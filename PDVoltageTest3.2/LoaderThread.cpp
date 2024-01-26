//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LoaderThread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
struct ComNum_Info comNum_Info[10]; // COM資訊

DWORD WINAPI SearchLoaderCOMTExecute(LPVOID Param);
AnsiString strLoaderName,INILoaderName;
AnsiString DeviceCOM;
DWORD dwStep;
//---------------------------------------------------------------------------

__fastcall TLoaderThread::TLoaderThread(bool CreateSuspended,INI_DESCRIPOR info
	,cLogMsg* LogMsg)
	: TThread(CreateSuspended)
{
	bCOM_PORT_OPEN = false;
	INI_Desc       = info;
	INILoaderName  = info.strLoaderName;
	mLogMsg        = LogMsg;
	dwStep         = STEP_TEST_END;
}
void TLoaderThread::SetTestStep(bool bTest)
{
	dwStep = bTest ? STEP_CHECK_COMPORT : STEP_TEST_END;
}
DWORD TLoaderThread::CheckTestStatus()
{
	return INI_Desc.dwTestStatus;
}
//---------------------------------------------------------------------------
void __fastcall TLoaderThread::Execute()
{
	DWORD dwCMDTimeOut;
	unsigned long Written;
	bool bError = false;
	dbCurrentChanel1 = 0;
	dbCurrentChanel2 = 0;
	//---- Place thread code here ----
	while( !Terminated )
	{
		switch(dwStep)
		{
			case STEP_CHECK_COMPORT:
				dwStep = open_dev_com() ? STEP_COMPORT_WRITE : STEP_COMPORT_NO_RESPOND;
				bError = false;
				dwGetErrorVolCount = 0;
				break;
			case STEP_COMPORT_WRITE:
				mLogMsg->AddLineToLogQueue("CMD :"+que_cmd.front());
				WriteFile(DEV_hCom,que_cmd.front().c_str(),
					que_cmd.front().Length(), &Written, NULL);
				dwCMDTimeOut = GetTickCount() + 1000;
				dwStep = STEP_COMPORT_READ;
				break;
			case STEP_COMPORT_READ:
				if(strstr(que_cmd.front().c_str(),"meas:vc?"))
				{
					dwLoaderChanel = que_cmd.front().Pos("chan 2") ? 2 : 1;
					DWORD ByteRead;
					char RXBuff[100];
					char buff[100];
					memset(buff, 0, sizeof(buff));
					memset(RXBuff, 0, sizeof(RXBuff));
					while (1) {
						ReadFile(DEV_hCom, RXBuff, 100, &ByteRead, NULL); // 接收
						if (ByteRead > 0) // 接收到數據
						{
							strncpy(buff, RXBuff, ByteRead);
							dwStep = cmd_get_system_consumptoin(buff, dwDevIndex);
							if(dwStep == STEP_LOAD_TEST_PASS || dwStep == STEP_LOAD_TEST_FAIL)
								que_cmd.pop();
							memset(buff, 0, sizeof(buff));
							memset(RXBuff, 0, sizeof(RXBuff));
							break;
						}
						else if (GetTickCount() > dwCMDTimeOut)
						{
							dwStep = STEP_COMPORT_NO_RESPOND;
							break;
						}
					}
				}
				else
				{
					if (strstr(que_cmd.front().c_str(),"LOAD ON"))
					{
						Sleep(INI_Desc.PITEM_PD_DESCRIPOR[dwDevIndex].dwAfterFullLoadDelay);
						bLoad = true;
						dwStep = STEP_COMPORT_WRITE;
						dwGetDataTimeOut
							= GetTickCount()+INI_Desc.PITEM_PD_DESCRIPOR[dwDevIndex].dwLoadTime;
					}
					else if (strstr(que_cmd.front().c_str(),"LOAD OFF")) {
						bLoad = false;
						dwStep = STEP_COMPORT_WRITE;
					}
					que_cmd.pop();
					if(!que_cmd.empty())
						dwStep = STEP_COMPORT_WRITE;
					else dwStep = STEP_TEST_END;
				}
				break;
			case STEP_LOAD_TEST_PASS:
				if(!que_cmd.empty())
					dwStep = STEP_COMPORT_WRITE;
				else
					dwStep = STEP_TEST_END;
				break;
			case STEP_LOAD_TEST_FAIL:
				bError	= true;
				if(bLoad)
				{
					dwStep = STEP_COMPORT_WRITE;
				}
				else
					dwStep = STEP_TEST_END;
				break;
			case STEP_TEST_END:
				INI_Desc.dwTestStatus
					= bError ? STEP_LOAD_TEST_FAIL:STEP_LOAD_TEST_PASS;
				break;
			case STEP_COMPORT_NO_RESPOND:
				INI_Desc.dwTestStatus = STEP_COMPORT_NO_RESPOND;
				break;
		}
		Sleep(100);
    }
}
DWORD TLoaderThread::cmd_get_system_consumptoin(char *s, int index) {
	TStringList *sList = new TStringList();
	sList->Delimiter = ',';
	sList->DelimitedText = AnsiString(s);
	double dCurrent = GetNumOfString(sList->Strings[1]);
	double dVoltage = GetNumOfString(sList->Strings[0]);
	mLogMsg->AddLineToLogQueue("Voltage :"+AnsiString(dVoltage));
	mLogMsg->AddLineToLogQueue("Current :"+AnsiString(dCurrent));
	delete sList;
	if (bLoad) {
		double MaxVoltage = INI_Desc.PITEM_PD_DESCRIPOR[index]
		.FullLoadMaxVoltage.ToDouble();
		double MinVoltage = INI_Desc.PITEM_PD_DESCRIPOR[index]
		.FullLoadMinVoltage.ToDouble();
		double dbLoadCurrent = INI_Desc.PITEM_PD_DESCRIPOR[index]
		.FullLoadCurrent.ToDouble();
		//
		if(dwLoaderChanel == 2)
			dbCurrentChanel2 = dCurrent;
		else
			dbCurrentChanel1 = dCurrent;
		//
		if(INI_Desc.PITEM_PD_DESCRIPOR[index].bWattIsOver)
        	dbLoadCurrent = dbLoadCurrent/2;
		if (dCurrent < (dbLoadCurrent - 0.2) || dCurrent > (dbLoadCurrent + 0.2))
		{
			dwGetErrorVolCount++;
			astrVoltage = AnsiString(dCurrent) + "A";
			//if (dwGetErrorVolCount > 5) {
				// que_Msg.push("(!)Load-Voltage Failed");
				return STEP_LOAD_TEST_FAIL;
			//}
		}
		dVoltage = dVoltage + INI_Desc.PITEM_PD_DESCRIPOR[index].LossVol.ToDouble();
		astrVoltage = AnsiString(dVoltage);
		if (dVoltage <= MaxVoltage && dVoltage >= MinVoltage) {
			if (GetTickCount() >= dwGetDataTimeOut) {
				return STEP_LOAD_TEST_PASS;
			}
			else {
				return STEP_COMPORT_WRITE;
			}
		}
		else {
			dwGetErrorVolCount++;
			if (dwGetErrorVolCount > 5) {
				return STEP_LOAD_TEST_FAIL;
			}
			return STEP_COMPORT_WRITE;
		}
	}
	else {
		double MaxVoltage = INI_Desc.PITEM_PD_DESCRIPOR[index]
		.NoLoadMaxVoltage.ToDouble();
		double MinVoltage = INI_Desc.PITEM_PD_DESCRIPOR[index]
		.NoLoadMinVoltage.ToDouble();
		astrVoltage = AnsiString(dVoltage);
		if (dVoltage <= MaxVoltage && dVoltage >= MinVoltage) {
			return STEP_LOAD_TEST_PASS;
		}
		else {
			if (GetTickCount() > dwGetDataTimeOut) {
				return STEP_LOAD_TEST_FAIL;
			}
		}
	}
	return STEP_LOAD_TEST_FAIL;
}
//---------------------------------------------------------------------------
AnsiString TLoaderThread::ReadLoaderVoltage() {
	return astrVoltage;
}
AnsiString TLoaderThread::ReadLoaderCurrent() {
	return AnsiString(dbCurrentChanel1+dbCurrentChanel2);
}
void TLoaderThread::SetLoaderVoltage(AnsiString strValue)
{
	astrVoltage = strValue;
}
bool TLoaderThread::CheckLoaderNameIs3315F()
{
	return strLoaderName.Pos("3315") ? true:false;
}
void TLoaderThread::SetINI_Desc(INI_DESCRIPOR info,DWORD Index) {
	dwDevIndex = Index;
	INI_Desc = info;
}
void TLoaderThread::SetQueueCMD(std::queue<AnsiString> que) {
	que_cmd = que;
}
//======================================================================
bool TLoaderThread::open_dev_com() {
	if (bCOM_PORT_OPEN)
		return true;

	DWORD WaitTime = GetTickCount() + 5000;
	if (!strstr(DeviceCOM.c_str(), "COM"))
		SearchDevCOM(); // 偵測是否有裝置名稱
	while (1) {
		if (DeviceCOM.Pos("COM")) {
			DEV_hCom = CreateFile(WideString(DeviceCOM).c_bstr(),
				GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
			if (DEV_hCom == INVALID_HANDLE_VALUE) {
				Sleep(100);//加了比較不會CreateFile FAIL
				Dev_Stop();
				DEV_hCom = CreateFile(WideString(DeviceCOM).c_bstr(),
					GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0,
					NULL);
				if (DEV_hCom == INVALID_HANDLE_VALUE) {
					CloseHandle(DEV_hCom);
					bCOM_PORT_OPEN = false;
					return false;
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
			return true;
		}
		else if (GetTickCount() > WaitTime) {
			bCOM_PORT_OPEN = false;
			return false;
		}
		else
			Sleep(100);
	}
}
void TLoaderThread::Dev_Stop() {
	bCOM_PORT_OPEN = false;
	CloseHandle(DEV_hCom);
}
//======================================================================
void TLoaderThread::SearchDevCOM() // Create多執行緒 找裝置
{
	search_Reg_ComNum();
	int Count = 0;
	while (strstr(comNum_Info[Count].ComName.c_str(), "COM")) {
		comNum_Info[Count].Threadhandle = ::CreateThread(0, 0, SearchLoaderCOMTExecute,
			(void*)Count, 0, NULL);
		CloseHandle(comNum_Info[Count].Threadhandle);
		Count++;
	}
}
void TLoaderThread::search_Reg_ComNum() // 取得 regedt COM
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
DWORD WINAPI SearchLoaderCOMTExecute(LPVOID Param) // 執行續
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
					DeviceCOM = comNum_Info[(int)Param].ComName;
					strLoaderName = buff;
			}
			else if(strstr(buff, INILoaderName.c_str()))
			{
				DeviceCOM = comNum_Info[(int)Param].ComName;
				strLoaderName = buff;
            }
		}
		CloseHandle(comNum_Info[(int)Param].handle);
		memset(RXBuff, 0, sizeof(RXBuff));
	}
	return 0;
}

double TLoaderThread::GetNumOfString(AnsiString String)
{
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