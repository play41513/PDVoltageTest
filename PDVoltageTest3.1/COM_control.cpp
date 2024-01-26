// ---------------------------------------------------------------------------

#pragma hdrstop
#include "vcl.h"
#include "COM_control.h"

// ---------------------------------------------------------------------------

#pragma package(smart_init)
HANDLE DEV_hCom;
DWORD WINAPI WORKTESTExecute(LPVOID Param);
AnsiString DeviceCOM;
AnsiString strLoaderName;
int dwGetErrorVolCount = 0;
bool bLoad = false;
bool bError;

struct ComNum_Info {
	HANDLE handle;
	HANDLE Threadhandle;
	AnsiString ComName;
};

struct ComNum_Info comNum_Info[10]; // COM資訊
DWORD cmd_TimeOut, dwTimeOut;

cCOM::cCOM(void) {
	bCOM_PORT_OPEN = false;
}

AnsiString cCOM::ReadLoaderVoltage() {
	return astrVoltage;
}

void cCOM::SetINI_Desc(INI_DESCRIPOR info) {
	INI_Desc = info;
}
void cCOM::SetQueueCMD(std::queue<AnsiString> que) {
	que_cmd = que;
}
bool cCOM::CheckLoaderNameIs3315F()
{
	return strLoaderName.Pos("3315") ? true:false;
}

DWORD cCOM::cmd_get_system_consumptoin(char *s, int index) {
	TStringList *sList = new TStringList();
	sList->Delimiter = ',';
	sList->DelimitedText = AnsiString(s);
	AnsiString SS1 = GetNumOfString(sList->Strings[0]);
	SS1 = GetNumOfString(sList->Strings[1]);
	double dCurrent = GetNumOfString(sList->Strings[1]);
	double dVoltage = GetNumOfString(sList->Strings[0]);
	delete sList;
	if (bLoad) {
		double MaxVoltage = INI_Desc.PITEM_PD_DESCRIPOR[index]
		.FullLoadMaxVoltage.ToDouble();
		double MinVoltage = INI_Desc.PITEM_PD_DESCRIPOR[index]
		.FullLoadMinVoltage.ToDouble();
		double dbLoadCurrent = INI_Desc.PITEM_PD_DESCRIPOR[index]
		.FullLoadCurrent.ToDouble();
		if(INI_Desc.PITEM_PD_DESCRIPOR[index].bWattIsOver)
        	dbLoadCurrent = dbLoadCurrent/2;
		if (dCurrent < (dbLoadCurrent - 0.2) || dCurrent > (dbLoadCurrent + 0.2))
		{
			dwGetErrorVolCount++;
			astrVoltage = AnsiString(dCurrent) + "A";
			if (dwGetErrorVolCount > 5) {
				// que_Msg.push("(!)Load-Voltage Failed");
				return LOAD_TEST_FAIL;
			}
		}
		dVoltage = dVoltage + INI_Desc.LossVol.ToDouble();
		astrVoltage = AnsiString(dVoltage);
		if (dVoltage <= MaxVoltage && dVoltage >= MinVoltage) {
			if (GetTickCount() >= dwGetDataTimeOut) {
				return LOAD_TEST_PASS;
			}
			else {
				return RS232_WRITE;
			}
		}
		else {
			dwGetErrorVolCount++;
			if (dwGetErrorVolCount > 5) {
				// que_Msg.push("(!)Load-Voltage Failed");
				return LOAD_TEST_FAIL;
			}
			return RS232_WRITE;
		}
	}
	else {
		double MaxVoltage = INI_Desc.PITEM_PD_DESCRIPOR[index]
		.NoLoadMaxVoltage.ToDouble();
		double MinVoltage = INI_Desc.PITEM_PD_DESCRIPOR[index]
		.NoLoadMinVoltage.ToDouble();
		astrVoltage = AnsiString(dVoltage);
		if (dVoltage <= MaxVoltage && dVoltage >= MinVoltage) {
			return LOAD_TEST_PASS;
		}
		else {
			if (GetTickCount() > dwGetDataTimeOut) {
				// que_Msg.push(AnsiString(GetTickCount())+"-"+AnsiString(dwGetDataTimeOut));
				// que_Msg.push("(!)NoLoad-Voltage Failed");
				return LOAD_TEST_FAIL;
			}
		}
	}
	return LOAD_TEST_FAIL;
}

bool cCOM::open_dev_com() {
	if (bCOM_PORT_OPEN)
		return 1;

	DWORD WaitTime = GetTickCount() + 5000;
	if (!strstr(DeviceCOM.c_str(), "COM"))
		SearchDevCOM(); // 偵測是否有裝置名稱
	while (1) {
		if (strstr(DeviceCOM.c_str(), "COM")) {
			DEV_hCom = CreateFile(WideString(DeviceCOM).c_bstr(),
				GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
			if (DEV_hCom == INVALID_HANDLE_VALUE) {
				Delay(100);
				Dev_Stop();
				DEV_hCom = CreateFile(WideString(DeviceCOM).c_bstr(),
					GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0,
					NULL);
				if (DEV_hCom == INVALID_HANDLE_VALUE) {
					CloseHandle(DEV_hCom);
					bCOM_PORT_OPEN = false;
					return 0;
				}
			}
			DCB dcb; // 設定comport相關係數
			GetCommState(DEV_hCom, &dcb);
			BuildCommDCB(L"115200,n,8,1", &dcb);
			SetCommState(DEV_hCom, &dcb);
			// 設定TimeOut
			COMMTIMEOUTS TimeOut;
			TimeOut.ReadIntervalTimeout = MAXDWORD;
			TimeOut.ReadTotalTimeoutMultiplier = 0;
			TimeOut.ReadTotalTimeoutConstant = 100;
			TimeOut.WriteTotalTimeoutMultiplier = 0;
			TimeOut.WriteTotalTimeoutConstant = 0;
			SetCommTimeouts(DEV_hCom, &TimeOut);
			bCOM_PORT_OPEN = true;
			return 1;
		}
		else if (GetTickCount() > WaitTime) {
			bCOM_PORT_OPEN = false;
			return 0;
		}
		else
			Delay(100);
	}
}

int cCOM::Dev_CMD_Test(int index) {
	unsigned long Written;
	int  dwStep = RS232_WRITE;
	bool bError = false;
	dwGetErrorVolCount = 0;
	dwGetDataTimeOut = 0;
	dwTimeOut = 0;
	AnsiString SS;
	try {
		while (dwStep)
		{
			switch(dwStep)
			{
				case RS232_WRITE:
					// 寫
					bNoResponse = false;
					que_Msg.push(que_cmd.front());
					SS = que_cmd.front();
					WriteFile(DEV_hCom,que_cmd.front().c_str(),
						que_cmd.front().Length(), &Written, NULL);
					cmd_TimeOut = GetTickCount() + 1000;
					dwStep = RS232_READ;
					break;
				case RS232_READ:
					// 讀
					if(strstr(que_cmd.front().c_str(),"meas:vc?"))
					{
						DWORD ByteRead;
						char RXBuff[20];
						char buff[20];
						memset(buff, 0, sizeof(buff));
						memset(RXBuff, 0, sizeof(RXBuff));
						Delay(200);
						while (1) {
							ReadFile(DEV_hCom, RXBuff, 20, &ByteRead, NULL); // 接收
							if (ByteRead > 0) // 接收到數據
							{
								strncpy(buff, RXBuff, ByteRead);
								dwStep = cmd_get_system_consumptoin(buff, index);
								if(dwStep == LOAD_TEST_PASS || dwStep == LOAD_TEST_FAIL)
									que_cmd.pop();
								memset(buff, 0, sizeof(buff));
								memset(RXBuff, 0, sizeof(RXBuff));
								break;
							}
							else if (GetTickCount() > cmd_TimeOut)
							{
								bNoResponse = true;
								dwStep = Dev_NO_RESPOND;
								break;
							}
						}
					}
					else
					{
						if (strstr(que_cmd.front().c_str(),"LOAD ON"))
						{
							Delay(200); // LOAD ON Delay
							bLoad = true;
							dwStep = RS232_WRITE;
							dwGetDataTimeOut = GetTickCount()+3000;
						}
						else if (strstr(que_cmd.front().c_str(),"LOAD OFF")) {
							bLoad = false;
							dwStep = RS232_WRITE;
						}
						
						Delay(100); // 回應間隔
						que_cmd.pop();
						if(!que_cmd.empty())
							dwStep = RS232_WRITE;
						else dwStep = TEST_END;
					}
					break;
				case LOAD_TEST_PASS:
					if(!que_cmd.empty())
						dwStep = RS232_WRITE;
					else
						dwStep = TEST_END;
					break;
				case LOAD_TEST_FAIL:
					bError = true;
					que_Msg.push("(!)LOAD FAILED");
					if(bLoad)
					{
						dwStep = RS232_WRITE;
					}
					else
						dwStep = TEST_END;
					break;
				case Dev_NO_RESPOND:
					CloseHandle(DEV_hCom);
					bCOM_PORT_OPEN = false;
					bError = true;
					dwStep = TEST_END;
					break;
				case TEST_END:
					break;

			}
		}
	}
	catch(...) {
		bError = true;
	}
	return !bError;
}

// ---------------------------------------------------------------------------
void cCOM::search_Reg_ComNum() // 取得 regedt COM
{
	AnsiString temppath;
	TRegistry *reg = new TRegistry();
	TStringList* itemSet = new TStringList();
	reg->RootKey = HKEY_LOCAL_MACHINE;
	temppath = "HARDWARE\\DEVICEMAP\\SERIALCOMM";
	reg->OpenKey(temppath.c_str(), false);
	reg->GetValueNames(itemSet);
	for (int i = 0; i < itemSet->Count; i++) {
		AnsiString comName = (AnsiString)reg->ReadString(itemSet->Strings[i]);
		if (strlen(comName.c_str()) > 4)
			comName = "\\\\.\\" + comName;
		comNum_Info[i].ComName = (AnsiString)comName.c_str();
	}
	reg->CloseKey();
	delete itemSet;
	delete reg;
}

void cCOM::SearchDevCOM() // Create多執行緒 找裝置
{
	search_Reg_ComNum();
	int Count = 0;
	while (strstr(comNum_Info[Count].ComName.c_str(), "COM")) {
		comNum_Info[Count].Threadhandle = ::CreateThread(0, 0, WORKTESTExecute,
			(void*)Count, 0, NULL);
		CloseHandle(comNum_Info[Count].Threadhandle);
		Count++;
	}
}

DWORD WINAPI WORKTESTExecute(LPVOID Param) // 執行續
{

	// 開COM
	comNum_Info[(int)Param].handle = CreateFile
		(WideString(comNum_Info[(int)Param].ComName).c_bstr(),
		GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, 0);
	if (comNum_Info[(int)Param].handle != INVALID_HANDLE_VALUE) {
		DCB dcb; // 設定comport相關係數
		GetCommState(comNum_Info[(int)Param].handle, &dcb);
		BuildCommDCB(L"115200,n,8,1", &dcb);
		SetCommState(comNum_Info[(int)Param].handle, &dcb);
		// 設定TimeOut
		COMMTIMEOUTS TimeOut;
		GetCommTimeouts(comNum_Info[(int)Param].handle, &TimeOut);
		TimeOut.ReadIntervalTimeout = MAXDWORD;
		TimeOut.ReadTotalTimeoutMultiplier = 0;
		TimeOut.ReadTotalTimeoutConstant = 300; // (總讀取 time out 時間 = 0.1 秒)
		TimeOut.WriteTotalTimeoutMultiplier = 0;
		TimeOut.WriteTotalTimeoutConstant = 100; // (總寫入 time out 時間 = 0.1 秒)
		SetCommTimeouts(comNum_Info[(int)Param].handle, &TimeOut);
		// 寫
		unsigned long Written;
		char* data = "*remote;name?\n";
		WriteFile(comNum_Info[(int)Param].handle, data, strlen(data), &Written,
			NULL);
		// 讀
		DWORD ByteRead;
		char RXBuff[1024];
		char buff[1024];
		ReadFile(comNum_Info[(int)Param].handle, RXBuff, 1024, &ByteRead,
			NULL); // 接收
		if (ByteRead > 0) // 接收到數據
		{
			strncpy(buff, RXBuff, ByteRead);
			//DEBUG(buff);
			if (strstr(buff, "3315F") || strstr(buff, "3310F") || strstr(buff,
					"3311F") || strstr(buff, "3312F") || strstr(buff,
					"3313F") || strstr(buff, "3314F") || strstr(buff,
					"3316G")) {
				//DEBUG(AnsiString(buff) + "[" + comNum_Info[(int)Param]
				//	.ComName + "]");
				DeviceCOM = comNum_Info[(int)Param].ComName;
				strLoaderName = buff;
			}
		}
		CloseHandle(comNum_Info[(int)Param].handle);
		memset(RXBuff, 0, sizeof(RXBuff));
	}
	return 0;
}

void cCOM::Dev_Stop() {
	bCOM_PORT_OPEN = false;
	Delay(300);
	//FrmMain->que_cmd.c.clear();
	CloseHandle(DEV_hCom);
	//FrmMain->Refresh();
}

void cCOM::QueueClear() // Queue Clear
{
	/* while(!FrmMain->que_cmd.empty())
	{
	FrmMain->que_cmd.pop();
	} */
}

double cCOM::GetNumOfString(AnsiString String) {
	TCHAR HexChar[10];
	bool bPoint = false;
	AnsiString sResult = "";
	int DecimalPlace = 0;

	try {
		String = String.UpperCase(); // 把字串轉成全大寫
		_tcscpy_s(HexChar, 10, WideString(String).c_bstr());
		for (int j = 0; j < String.Length(); j++) {
			if (HexChar[j] < 0x30 || HexChar[j] > 0x39) {
				if (HexChar[j] == 0x2E) {
					if (!bPoint && j == 0) {
						sResult += "0";
					}
					sResult += HexChar[j];
					bPoint = true;
				}
			}
			else {
				if (bPoint)
					DecimalPlace++;
				sResult += HexChar[j];
			}
			if (DecimalPlace == 3)
				break;
		}

		return sResult.ToDouble();
	}
	catch(...) {
		return 0;
	}
}
void cCOM::Delay(ULONG iMilliSeconds) // 原版delay time 用在thread裡面
{
	ULONG iStart;
	iStart = GetTickCount();
	while (GetTickCount() - iStart <= iMilliSeconds)
		Application->ProcessMessages();
}
