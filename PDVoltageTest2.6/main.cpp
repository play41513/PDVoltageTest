﻿//---------------------------------------------------------------------------
#include <windows.h>    // 安全移除USB裝置用 *要比 vcl.h 早編譯
#include <SetupAPI.h> // 安全移除USB裝置用 *要比 vcl.h 早編譯
#include <cfgmgr32.h> // 安全移除USB裝置用 *要比 vcl.h 早編譯
#include <vcl.h>
#pragma hdrstop


#include "main.h"
#include "MSGBOX.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmMain *FrmMain;
//UI調整參數
DWORD MouseY,memo_heigh=0;//,VOLTAGE_TOLERANCE_RANGE=20;
bool xCapture;
float voltage;
float MAX_VOLTAGE_TOLERANCE_RANGE[5],MIN_VOLTAGE_TOLERANCE_RANGE[5];

int TimeStart = 0,DelayTimeBack5V = 0,DelayTime20V = 0;
bool bTesting = false;
AnsiString DUT_MAC= "";
DWORD dwStep,dwTestCount = 0;
//---------------------------------------------------------------------------
__fastcall TFrmMain::TFrmMain(TComponent* Owner)
	: TForm(Owner)
{
	EnumHID();

	bTEST_END_SWITCH_5V = false;

	zVoltageSetting[0] = plSet5V;
	zVoltageSetting[1] = plSet9V;
	zVoltageSetting[2] = plSet12V;
	zVoltageSetting[3] = plSet15V;
	zVoltageSetting[4] = plSet20V;

	zRead_AD_Voltage[0] = pl_read_5v_voltage;
	zRead_AD_Voltage[1] = pl_read_9v_voltage;
	zRead_AD_Voltage[2] = pl_read_12v_voltage;
	zRead_AD_Voltage[3] = pl_read_15v_voltage;
	zRead_AD_Voltage[4] = pl_read_20v_voltage;

	zRead_FULL_LOAD_Voltage[0] = pl_full_load_voltage5;
	zRead_FULL_LOAD_Voltage[1] = pl_full_load_voltage9;
	zRead_FULL_LOAD_Voltage[2] = pl_full_load_voltage12;
	zRead_FULL_LOAD_Voltage[3] = pl_full_load_voltage15;
	zRead_FULL_LOAD_Voltage[4] = pl_full_load_voltage20;

	zAuto_Test[0] = pl_Auto5V;
	zAuto_Test[1] = pl_Auto9V;
	zAuto_Test[2] = pl_Auto12V;
	zAuto_Test[3] = pl_Auto15V;
	zAuto_Test[4] = pl_Auto20V;
	//
	//ReadRegSet();
	if(FindIniFile()) ReadInISet();
	CL_DEV_CONTROL = new cCOM();


	FrmMain->Caption = APP_TITLE;

	/*
	if(frmMsg==NULL)  frmMsg = new TfrmMsg(Application);
	frmMsg->edtSetWorkOrderNumber->Text = edtWorkOrderNumber->Text ;
	frmMsg->edtSetModel->Text = edtModel->Text ;
	frmMsg->edtWorkStation->Text = edtWorkStation->Text;
	if(frmMsg->ShowModal()== mrOk)
	{
		edtWorkOrderNumber->Text 	= frmMsg->edtSetWorkOrderNumber->Text.Trim();
		edtEmployeeID->Text	 		= frmMsg->edtSetEmployeeID->Text.Trim();
		edtModel->Text 				= frmMsg->edtSetModel->Text.Trim();
		edtWorkStation->Text 		= frmMsg->edtWorkStation->Text.Trim();
		delete frmMsg;
		frmMsg = NULL;
	}
	else
	{
		delete frmMsg;
		frmMsg = NULL;
		PostQuitMessage(WM_QUIT);
	}
	/*/
	LOG_FILE_PATH = "C:\\ASMP\\log\\PDVotageTool\\"+AnsiString(plIniName->Caption)+"\\";
	AddLocalFilePath(LOG_FILE_PATH);
	LOG_FILE_PATH += AnsiString(FormatDateTime("\\yyyy-mm-dd_hh-nn-ss", Now()))+".csv";
	FormResize(NULL);
	dwStep = CHECK_DEV_ONLINE;
	//que_log.c.clear();
	//new TWNetFileThread(false);
}
void __fastcall TFrmMain::EnumHID(){
	HDEVINFO hDevInfo;
	SP_DEVINFO_DATA DeviceInfoData;
	DWORD i,j;
	AnsiString SS,USBPath;
	PSP_DEVICE_INTERFACE_DETAIL_DATA   pDetail   =NULL;
	GUID GUID_USB_HID =StringToGUID(GUID_HID);
	DEBUG("[ HID裝置列舉 ]");
	//--------------------------------------------------------------------------
	//   獲取設備資訊
	hDevInfo = SetupDiGetClassDevs((LPGUID)&GUID_USB_HID,
	0,   //   Enumerator
	0,
	DIGCF_PRESENT | DIGCF_DEVICEINTERFACE );
	if   (hDevInfo   ==   INVALID_HANDLE_VALUE){
		DEBUG("ERROR - SetupDiGetClassDevs()"); //   查詢資訊失敗
	}
	else{
	//--------------------------------------------------------------------------
		SP_DEVICE_INTERFACE_DATA   ifdata;
		DeviceInfoData.cbSize   =   sizeof(SP_DEVINFO_DATA);
		for (i=0;SetupDiEnumDeviceInfo(hDevInfo, i, &DeviceInfoData);i++)	//   枚舉每個USB設備
		{
			ULONG   len;
			CONFIGRET cr;
			PNP_VETO_TYPE   pnpvietotype;
			CHAR   vetoname[MAX_PATH];
			ULONG   ulStatus;
			ULONG   ulProblemNumber;
			ifdata.cbSize   =   sizeof(ifdata);
			if (SetupDiEnumDeviceInterfaces(								//   枚舉符合該GUID的設備介面
			hDevInfo,           //   設備資訊集控制碼
			NULL,                         //   不需額外的設備描述
			(LPGUID)&GUID_USB_HID,//GUID_CLASS_USB_DEVICE,                     //   GUID
			(ULONG)i,       //   設備資訊集裏的設備序號
			&ifdata))                 //   設備介面資訊
			{
				ULONG predictedLength   =   0;
				ULONG requiredLength   =   0;
				//   取得該設備介面的細節(設備路徑)
				SetupDiGetInterfaceDeviceDetail(hDevInfo,         //   設備資訊集控制碼
					&ifdata,          //   設備介面資訊
					NULL,             //   設備介面細節(設備路徑)
					0,         	      //   輸出緩衝區大小
					&requiredLength,  //   不需計算輸出緩衝區大小(直接用設定值)
					NULL);            //   不需額外的設備描述
				//   取得該設備介面的細節(設備路徑)
				predictedLength=requiredLength;
				pDetail = (PSP_INTERFACE_DEVICE_DETAIL_DATA)::GlobalAlloc(LMEM_ZEROINIT,   predictedLength);
				pDetail->cbSize   =   sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

				if(SetupDiGetInterfaceDeviceDetail(hDevInfo,         //   設備資訊集控制碼
					&ifdata,             //   設備介面資訊
					pDetail,             //   設備介面細節(設備路徑)
					predictedLength,     //   輸出緩衝區大小
					&requiredLength,     //   不需計算輸出緩衝區大小(直接用設定值)
					NULL))               //   不需額外的設備描述
				{
					try
					{
						char ch[512];
						for(j=0;j<predictedLength;j++)
						{
						ch[j]=*(pDetail->DevicePath+8+j);
						}
						SS=ch;
						DEBUG(SS);
					}
					catch(...)
					{
						DEBUG(SS+"列舉失敗");
					}

				}
				else
				{
					DEBUG("SetupDiGetInterfaceDeviceDetail F");
				}
			}
			else
			{
				DEBUG("SetupDiEnumDeviceInterfaces F");
			}
		}
	}
}
//---------------------------------------------------------------------------
bool TFrmMain::HID_TurnOn(){
	//配置HID物件
	wchar_t HID_PID[5];
	wchar_t HID_VID[5];
	wcsncpy(HID_PID,PD_BOARD_PVID+8,4);
	wcsncpy(HID_VID,PD_BOARD_PVID+17,4);
	HID_PID[4]='\0';
	HID_VID[4]='\0';

	if(m_hid.Configure(HID_PID,HID_VID,L"",L"")){
		if(!m_hid.Open()){
			MessageBox(this->Handle, _T("開啟 PD 板失敗!"), Application->Title.t_str(), MB_ICONWARNING);
			return false;
        }
	}else{
		MessageBox(this->Handle, _T("配置 PD 板失敗!"), Application->Title.t_str(), MB_ICONWARNING);
		return false;
	}
	HID_PID[4] = 0;
	HID_PID[4] = 0;

	return true;
}
void TFrmMain::HID_TurnOff(){
	m_hid.Close();
}
//---------------------------------------------------------------------------
void TFrmMain::Tx(AnsiString Value){
	int szTx, szCmd;
	unsigned char * cmd;
	TStringList * list;

	szTx = m_hid.GetTxBytes();
	m_or.AllocBuf(szTx);
	cmd = (unsigned char *)m_or.GetBufAddr();

	list = new TStringList();
	list->DelimitedText = Value;

	if(list->Count > szTx){
		szCmd = szTx;
	}else{
        szCmd = list->Count;
	}

	for(int i=0; i<szCmd; i++){
		list->Strings[i] = L"0x" + list->Strings[i];
		cmd[i] = list->Strings[i].ToInt();
	}

	HidD_SetOutputReport(m_hid.m_hWrite, cmd, szTx);
	UI_DisplayCmd(cmd, szTx);

	delete list;
}
void __fastcall TFrmMain::UI_DisplayCmd(unsigned char *pBuf, int size){
	String str, str2;
	str = _T("寫入 : ");

	for(int i=0; i<size; i++){
		if(i == 0){
			str2.printf(_T("%02X"), pBuf[i]);
		}else{
			str2.printf(_T(" %02X"), pBuf[i]);
		}

		str += str2;
	}

	DEBUG(str);
}
//---------------------------------------------------------------------------
bool TFrmMain::Rx(AnsiString Value)
{
	DWORD nBytes;
	bool bl=false;

	if(!m_ir.AllocBuf(m_hid.GetRxBytes())){
		MessageBox(NULL, _T("FAIL!"), _T("Allocate read buffer"), MB_ICONSTOP);
		return false;
	}

	if(m_ir.Read(m_hid.m_hRead)){
		if(HID_ReadReport(Value)) bl = true;
	}else{
		if(GetLastError() == ERROR_IO_PENDING){
			WaitForSingleObject(m_hid.m_hRead, 1000);
			if(GetOverlappedResult(m_hid.m_hRead, &m_ir, &nBytes, false)){
				if(HID_ReadReport(Value)) bl = true;
			}
			CancelIo(m_hid.m_hRead);
		}
	}
	return bl;
}
bool __fastcall TFrmMain::HID_ReadReport(AnsiString Value){
	String buf, buf2;
	const unsigned char *report = (const unsigned char *)m_ir.GetBufAddr();

	buf = _T("讀取 : ");

	for(int i=0; i!=m_ir.GetBufSize(); i++){
		if(i==0){
			buf2.printf(_T("%02X"), report[i]);
		}else{
			buf2.printf(_T(" %02X"), report[i]);
		}

		buf += buf2;
	}
	DEBUG(buf);

	AnsiString buf3 = AnsiString(buf.c_str());
	if(Value!="")
	{
		if(!strcmp(buf3.SubString(8,Value.Length()).c_str(),Value.c_str()))
			return true;
		else return false;
	}
	else
	{
		Rx_ValueAnalyze(buf3.SubString(8,23));
		return true;
	}
}
void TFrmMain::Rx_ValueAnalyze(AnsiString Value){
	AnsiString HexValue = Value.SubString(19,2)+Value.SubString(22,2);
	m_ADValue.printf("%.3f",float(HexToInt(HexValue))*UNIT);
	DEBUG("Voltage Value : "+m_ADValue+" V");
}
//---------------------------------------------------------------------------
void TFrmMain::Voltage_Test(AnsiString CMD)
{
	//初始化
	int step = 0;
	bool bl = true;

	int numBtn = CMD.SubString(CMD.Length()-1,CMD.Length()).ToInt();
	bool bTimeInterval = atof(AnsiString(zVoltageSetting[numBtn-1]->Tag).c_str()) < voltage ? true : false;
	bool b20VDelay = false;
	if(bTimeInterval&&(voltage==20)&&(zVoltageSetting[numBtn-1]->Tag!=5))
		b20VDelay = true;
	else if(bTimeInterval&&(voltage==15)&&(zVoltageSetting[numBtn-1]->Tag==9))
		b20VDelay = true;
	voltage = zVoltageSetting[numBtn-1]->Tag;

	TPanel * pl_no_load = (TPanel *)FindComponent("pl_read_"+AnsiString(voltage)+"v_voltage");
	TPanel * pl_full_load = (TPanel *)FindComponent("pl_full_load_voltage"+AnsiString(voltage));
	if(!bTEST_END_SWITCH_5V)
	{
		pl_no_load->Color = clWhite;
		pl_no_load->Caption = "Testing...";
		pl_full_load->Color = clWhite;
		pl_full_load->Caption = "";
	}

	FrmMain->Refresh();

	while(bl)
	{
		DEBUG_TIME;
		switch(step)
		{
			case HID_IS_ONLINE:
				if(m_hid.m_online) step = SET_VOLTAGE;
				else step = HID_TURN_ON;
				break;
			case HID_TURN_ON:
				if(HID_TurnOn()) step = SET_VOLTAGE;
				else step = HID_NOT_FIND;
				break;
			case SET_VOLTAGE:
				Tx(CMD);
				if(Rx(CMD)) step = EXECUTE_SETTING;
				break;
			case EXECUTE_SETTING:
				Tx(ExecuteVoltageSetting);
				if(Rx(ExecuteVoltageSetting))
				{
					/*
					20V to 9V、12V、15V 					  => Delay 3000 ms
					15V to 9V           					  => Delay 3000 ms
					previous test-voltage > now test-voltage  => Delay 800  ms
					other                                     => Delay 200  ms
					*/
					DWORD dwDelay = GetTickCount();
					if(b20VDelay)
						dwDelay += 1000;
					else if(bTimeInterval)
						dwDelay += (TIME_INTERVAL*4);
					else
						dwDelay += 200;

					while(true)
						if(GetTickCount()> dwDelay) break;
					if(bTEST_END_SWITCH_5V)
						Delay(DelayTimeBack5V);
					Delay(DelayTime20V);
					step = READ_NO_LOAD_VOLTAGE_VALUE;
				}
				break;
			case READ_NO_LOAD_VOLTAGE_VALUE:
				step = DL_CMD("load off;meas:curr?;meas:volt?\n",AnsiString(voltage));
				if(step == TEST_PASS)
				{
					if(bTEST_END_SWITCH_5V)
					{
						bTEST_END_SWITCH_5V = false;
						step = TEST_VOLTAGE_END;
					}
					else
					{
						pl_no_load->Font->Color = clGreen;
						if(((TPanel *)FindComponent("plFullLoad_"+AnsiString(numBtn)))->Caption!="")
							step = READ_FULL_LOAD_VOLTAGE_VALUE;
						else  step = TEST_VOLTAGE_END;
					}
				}
				else if(step == TEST_FAIL)
				{
					pl_no_load->Font->Color = clRed;
					g_bError = true;
					if(bTEST_END_SWITCH_5V)
					{
						bTEST_END_SWITCH_5V = false;
						step = TEST_VOLTAGE_END;
					}
					else
					{
						if(((TPanel *)FindComponent("plFullLoad_"+AnsiString(numBtn)))->Caption!="")
							step = READ_FULL_LOAD_VOLTAGE_VALUE;
						else  step = TEST_VOLTAGE_END;
					}
				}
				else if(step == DL_NOT_FIND)
				{
					pl_no_load->Font->Color = clRed;
					pl_no_load->Caption = "FAIL";
					g_bError = true;
				}
				break;
			case READ_FULL_LOAD_VOLTAGE_VALUE:
				pl_full_load->Caption = "Testing...";
				FrmMain->Refresh();
				step = DL_CMD("LOAD ON\n",AnsiString(voltage));
				if(step == TEST_PASS)
				{
					pl_full_load->Font->Color = clGreen;
					step = TEST_VOLTAGE_END;
				}
				else if(step == TEST_FAIL)
				{
					pl_full_load->Font->Color = clRed;
					step = TEST_VOLTAGE_END;
					g_bError = true;
				}
				else if(step == DL_NOT_FIND)
				{
					pl_no_load->Font->Color = clRed;
					pl_no_load->Caption = "FAIL";
					g_bError = true;
				}
				break;
			case TEST_VOLTAGE_END:
				(DL_CMD("LOAD OFF\n",AnsiString(voltage)));
				bl =false;
				break;
			case HID_NOT_FIND:
				pl_no_load->Font->Color = clRed;
				pl_no_load->Caption = "FAIL";
				g_bError = true;
				bl =false;
				break;
			case DL_NOT_FIND:
				g_bError = true;
				bl =false;
				break;
		}
	}
}

//---------------------------------------------------------------------------
int  TFrmMain::HexToInt(AnsiString HexStr) {//16進位轉10進位
	int iIndex, iHex, totalChar;
	TCHAR HexChar[8];

	HexStr.UpperCase(); // 把字串轉成全大寫
	_tcscpy_s(HexChar, 8, WideString(HexStr).c_bstr());
//	strcpy(HexChar, HexStr.c_str()); // 把字串轉成字元陣列
	iHex = 0;
	totalChar = HexStr.Length(); // 取得字串的長度
	for (iIndex = 0; iIndex < totalChar; iIndex++) {
		iHex <<= 4;
		if ((HexChar[iIndex] >= 0x30) && (HexChar[iIndex] <= 0x39)) {
			iHex += (HexChar[iIndex] - 0x30); // 把 0 - 9 字元轉成數字
		}
		else if ((HexChar[iIndex] >= 0x41) && (HexChar[iIndex] <= 0x46)) {
			iHex += (HexChar[iIndex] - 0x37); // ­把 A - F 字元轉成數字
		}
		else {
			iHex = 0;
			break;
		}
	}
	return iHex + HARDWARE_VOLTAGE_COMPENSATION;
}
//---------------------------------------------------------------------------
void TFrmMain::Main_Test(bool CheckMAC)
{
	AnsiString SS = "",Temp;
	if(btnStart->Enabled)
	{
		plResult->Caption = "Testing...";
		plResult->Color = clWhite;
		btnStart->Enabled = false;
		g_bError = false;
		bool bHaveDev = false;
		//bool bl = CheckMAC ? getLanMAC():true;
		TimeStart = GetTickCount();
		for(int i=0;i < 5 ;i++)
		{
			zRead_AD_Voltage[i]->Font->Color = clBlue;
			zRead_AD_Voltage[i]->Caption = "";
			zRead_FULL_LOAD_Voltage[i]->Font->Color = clBlue;
			zRead_FULL_LOAD_Voltage[i]->Caption = "";
		}
		//
		//plMAC->Width   = 360;
		//if(bl)
		//{
			//plMAC->Caption = DUT_MAC;
			//plMAC->Font->Color   = clBlue;
			for(int i = 0;i < 5;i++)
			{
				if(zAuto_Test[i]->Caption == "V")
				{
					plSet5VClick(zVoltageSetting[i]);
					bHaveDev = true;
				}
				if(zRead_AD_Voltage[i]->Caption == "FAIL" || zRead_FULL_LOAD_Voltage[i]->Caption == "FAIL")
				{
					if(zRead_AD_Voltage[i]->Caption == "FAIL")
					{
						zRead_FULL_LOAD_Voltage[i]->Font->Color = clRed;
						zRead_FULL_LOAD_Voltage[i]->Caption = "FAIL";
					}
					for(int j =i+1;j < 5;j++)
					{
						if(zAuto_Test[j]->Caption == "V")
						{
							zRead_AD_Voltage[j]->Font->Color = clRed;
							zRead_AD_Voltage[j]->Caption = "FAIL";
							zRead_FULL_LOAD_Voltage[j]->Font->Color = clRed;
							zRead_FULL_LOAD_Voltage[j]->Caption = "FAIL";
						}
					}
					break;
				}
				else if(i==4)
				{
					Temp = ",["+AnsiString(zVoltageSetting[i]->Tag)+"V],"
						+zRead_AD_Voltage[i]->Caption+","+zRead_FULL_LOAD_Voltage[i]->Caption;
					SS += Temp;
					Delay(100);
					bTesting = true;
					bTEST_END_SWITCH_5V = true;
					Voltage_Test(SetVoltage[0]); //切回5V
					bTesting = false;

					Temp = ",[Back5V]"+pl_read_5v_voltage->Caption+"V";
					SS += Temp;
				}
				else
				{
					Temp = ",["+AnsiString(zVoltageSetting[i]->Tag)+"V],"
						+zRead_AD_Voltage[i]->Caption+","+zRead_FULL_LOAD_Voltage[i]->Caption;
					SS += Temp;
                }
			}
		//}
		//else
		//{
			//plMAC->Caption 		= "Unable to get MAC";
			//plMAC->Font->Color  = clRed;
			//g_bError = true;
		//}
		DEBUG((GetTickCount()-TimeStart)/1000);

		if(!bHaveDev) g_bError = true;
		plResult->Color = g_bError ? clRed:clLime;
		plResult->Caption = g_bError ? "FAIL":"PASS";
		if(SS!="")
		{
			SS += g_bError ? ",[Result],FAIL":",[Result],PASS";
			//if(CheckMAC)
			//{
			//que_log.push(SS);
			//
			dwTestCount++;
			AnsiString strTemp;
			strTemp.sprintf("%04d",dwTestCount);
			SS = strTemp + (FormatDateTime(",hh:nn:ss,", Now()))+SS+"\n";
			//
			LocalWriteLOG(LOG_FILE_PATH,SS);
			//}
		}

		btnStart->Enabled = true;
	}
}

void __fastcall TFrmMain::btnStartClick(TObject *Sender)
{
	Main_Test(false);
}
//---------------------------------------------------------------------------
void __fastcall TFrmMain::pl_Auto5VClick(TObject *Sender)
{
	TPanel* pl=(TPanel*)Sender;
	pl->Caption = pl->Caption == "V" ? "":"V";
}
//---------------------------------------------------------------------------
void TFrmMain::ReadRegSet()
{
	/*AnsiString value;
	TRegistry *reg = new TRegistry();

	try
	{
		reg->RootKey = HKEY_CURRENT_USER;
		reg->OpenKey("SOFTWARE", false);
		bool bl = reg->OpenKey("PD Voltage Test", true);
		bl = reg->OpenKey("PD Voltage Test 2.0.2", true);

		if(bl)
		{
			if(reg->ValueExists("AutoTestItem")){
				value = reg->ReadString("AutoTestItem");
				for(int i=1;i <=value.Length();i++)
					zAuto_Test[value.SubString(i,1).ToInt()-1]->Caption = "V";
			}
			else
				for(int i=0;i <5;i++)
					zAuto_Test[i]->Caption = "V";
			if(reg->ValueExists("DutPluginAutoTest")){
				value = reg->ReadString("DutPluginAutoTest");
				ckbAuto->Checked = value == 1 ? true:false;
			}
			if(reg->ValueExists("DutPidVid")){
				value = reg->ReadString("DutPidVid");
				edtVID->Text = value.SubString(5,4);
				edtPID->Text = value.SubString(14,4);
			}
			if(reg->ValueExists("SetCurrent")){
				edtSetCurrent->Text = reg->ReadString("SetCurrent");
			}
			for(int i=1 ;i<=5 ;i++)
			{
				if(reg->ValueExists("VoltageToleranceRange_"+IntToStr(i))){
					value = reg->ReadString("VoltageToleranceRange_"+IntToStr(i));
					((TEdit *)FindComponent("edt_min"+IntToStr(i)))->Text	  = value.SubString(1,value.Pos("、")-1);
					((TEdit *)FindComponent("edt_max"+IntToStr(i)))->Text	  = value.SubString(value.Pos("、")+2,value.Pos("&")-value.Pos("、")-2);
					value = value.Delete(1,value.Pos("&"));
					((TEdit *)FindComponent("edt_load_min"+IntToStr(i)))->Text	  = value.SubString(1,value.Pos("、")-1);
					((TEdit *)FindComponent("edt_load_max"+IntToStr(i)))->Text	  = value.SubString(value.Pos("、")+2,value.Length()-value.Pos("、")+2);
				}
			}
			if(reg->ValueExists("OverLoadTestItem")){
				value = reg->ReadString("OverLoadTestItem");
				TPanel* zCkbOverLoad[5];
				for(int i=0;i<5;i++)
				   zCkbOverLoad[i] = (TPanel*)FindComponent("plFullLoad_"+IntToStr(i+1));
				for(int i=1;i <=value.Length();i++)
					zCkbOverLoad[value.SubString(i,1).ToInt()-1]->Caption = "V";
			}
			SaveVoltageRangeSetting();
		}
		else
		{
			for(int i=0;i <5;i++)
				zAuto_Test[i]->Caption = "V";
		}
	}__finally {
		delete reg;
	}
	FrmMain->Refresh();
	FormResize(NULL);*/
}
void TFrmMain::SetRegVal(AnsiString numTestItem,bool AutoTest,AnsiString DutVPID){
	/*TRegistry *reg = new TRegistry;

	try {
		reg->RootKey = HKEY_CURRENT_USER;
		reg->OpenKey("SOFTWARE", false);
		bool bl = reg->OpenKey("PD Voltage Test", true);
		bl = reg->OpenKey("PD Voltage Test 2.0.2", true);
		AnsiString VoltageRange[5];
		for(int i =1 ;i <=5 ;i++)
			VoltageRange[i-1] =
				AnsiString(((TEdit *)FindComponent("edt_min"+IntToStr(i)))->Text)
				+ "、"
				+ AnsiString(((TEdit *)FindComponent("edt_max"+IntToStr(i)))->Text)
				+ "&"
				+ AnsiString(((TEdit *)FindComponent("edt_load_min"+IntToStr(i)))->Text)
				+ "、"
				+ AnsiString(((TEdit *)FindComponent("edt_load_max"+IntToStr(i)))->Text);

		if(bl){
			reg->WriteString("AutoTestItem", numTestItem);
			if(edtVID->Font->Color==clBlue&&edtPID->Font->Color==clBlue)
				reg->WriteString("DutPidVid", DutVPID);
			reg->WriteString("DutPluginAutoTest", AutoTest ? "1":"0");
			reg->WriteString("SetCurrent",edtSetCurrent->Text);
			reg->WriteString("VoltageToleranceRange_1",  VoltageRange[0]);
			reg->WriteString("VoltageToleranceRange_2",  VoltageRange[1]);
			reg->WriteString("VoltageToleranceRange_3", VoltageRange[2]);
			reg->WriteString("VoltageToleranceRange_4", VoltageRange[3]);
			reg->WriteString("VoltageToleranceRange_5", VoltageRange[4]);

			AnsiString numOverLoad="";
			for(int i=0;i<5;i++)
			   if(((TPanel*)FindComponent("plFullLoad_"+IntToStr(i+1)))->Caption!="")
					numOverLoad+=AnsiString(i+1);
			reg->WriteString("OverLoadTestItem", numOverLoad);
		}
	} __finally {
		delete reg;
	}*/
}

void __fastcall TFrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	AnsiString AutoTestItem = "";
	for(int i=0;i<5;i++)
		if(zAuto_Test[i]->Caption == "V") AutoTestItem += i+1;
	if(btnStart->Enabled)
		SetInIVal(AutoTestItem,ckbAuto->Checked,"vid_"+edtVID->Text+"&pid_"+edtPID->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFrmMain::ckbAutoClick(TObject *Sender)
{
	pl_DutVPID->Visible = ckbAuto->Checked ? true:false;
	btnStart->Caption = ckbAuto->Checked ? "Auto Test":"Start";
}
//---------------------------------------------------------------------------
bool TFrmMain::CheckVPIDSET(TEdit * edt){
	TCHAR HexChar[8];
	if(edt->Text.Length() == 0){}
	else if(edt->Text.Length() <= 4 ){
		edt->Text = edt->Text.UpperCase();// 把字串轉成全大寫
		AnsiString pvid = edt->Text;
		_tcscpy_s(HexChar, 8, WideString(pvid).c_bstr());
		for(int j=0;j<pvid.Length();j++)
		{
			if(HexChar[j] < 0x30 || HexChar[j] > 0x39){
				if(HexChar[j] < 0x41 || HexChar[j] > 0x5A){
					edt->Font->Color = clRed;
					return false;
				}
			}
		}
	}
	else
	{
		int bb = edt->Text.Length();
		edt->Font->Color = clRed;
		return false;
	}
	if(edt->Text.Length() == 4) edt->Font->Color = clBlue;
	else edt->Font->Color = clWindowText;

	edt-> SelStart=edt-> Text.Length();
	return true;
}


void __fastcall TFrmMain::edtVIDChange(TObject *Sender)
{
	CheckVPIDSET((TEdit*)Sender);
}
//---------------------------------------------------------------------------
void __fastcall TFrmMain::FormResize(TObject *Sender)
{
	for (int i = 2; i <= 6; ++i)
		((TPanel *)FindComponent("Panel" + IntToStr(i)))->Width =(Panel7->Width-118) / 5;
}
//---------------------------------------------------------------------------
void __fastcall TFrmMain::plSet5VClick(TObject *Sender)
{
	TPanel* pl=(TPanel*)Sender;
	if(!bTesting)
	{
		bTesting = true;
		if(btnStart->Enabled)
		{
			g_bError = false;
			plResult->Caption = "Testing...";
			plResult->Color = clWhite;
			zRead_AD_Voltage[pl->Hint.ToInt()]->Font->Color = clBlue;
			zRead_AD_Voltage[pl->Hint.ToInt()]->Caption = "";
			zRead_FULL_LOAD_Voltage[pl->Hint.ToInt()]->Font->Color = clBlue;
			zRead_FULL_LOAD_Voltage[pl->Hint.ToInt()]->Caption = "";
		}
		Voltage_Test(SetVoltage[pl->Hint.ToInt()]);
		if(btnStart->Enabled)
		{
			plResult->Color = g_bError ? clRed:clLime;
			plResult->Caption = g_bError ? "FAIL":"PASS";
		}
		bTesting = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::moDebugChange(TObject *Sender)
{
	if(moDebug->Lines->Count >500) moDebug->Clear();
}
//---------------------------------------------------------------------------



void __fastcall TFrmMain::edtPassWordEnter(TObject *Sender)
{
	if(edtPassWord->Font->Color == clRed)
	{
		edtPassWord->Font->Color = clBlue;
		edtPassWord->Text 	= "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::btnSetClick(TObject *Sender)
{
	if(btnSet->Caption == "ENTER")
	{
		if(edtPassWord->Text.UpperCase() == PASSWORD)
		{
			btnSet->Caption		 = "END";
			SetValueEnabled(true);
		}
		else edtPassWord->Font->Color = clRed;
	}
	else
	{
		if(SaveVoltageRangeSetting())
		{
			btnSet->Caption	  	= "ENTER";
			edtPassWord->Text 	= "";
			SetValueEnabled(false);
//---------------------------------
			AnsiString AutoTestItem = "";
			for(int i=0;i<5;i++)
				if(zAuto_Test[i]->Caption == "V") AutoTestItem += i+1;
			if(btnStart->Enabled)
				SetInIVal(AutoTestItem,ckbAuto->Checked,"vid_"+edtVID->Text+"&pid_"+edtPID->Text);
		}
		dwStep = CHECK_DEV_ONLINE;
	}
}
//---------------------------------------------------------------------------
void  TFrmMain::SetValueEnabled(bool Enabled)
{
	edtPassWord->Enabled = !Enabled;
	edtVID->Enabled = Enabled;
	edtPID->Enabled = Enabled;
	ckbAuto->Enabled = Enabled;
	for(int i=1 ; i<=5 ;i++)
	{
		TPanel  * pl   = ((TPanel *)FindComponent("pl_set_" + IntToStr(i)));
		pl->Enabled	  = Enabled;
		zVoltageSetting[i-1]->Enabled = !Enabled;

		((TEdit *)FindComponent("edt_min"+IntToStr(i)))->Enabled = Enabled;
		((TEdit *)FindComponent("edt_max"+IntToStr(i)))->Enabled = Enabled;
		((TEdit *)FindComponent("edt_load_min"+IntToStr(i)))->Enabled = Enabled;
		((TEdit *)FindComponent("edt_load_max"+IntToStr(i)))->Enabled = Enabled;
	}
	pl_Auto5V->Enabled  = Enabled;
	pl_Auto9V->Enabled  = Enabled;
	pl_Auto12V->Enabled = Enabled;
	pl_Auto15V->Enabled = Enabled;
	pl_Auto20V->Enabled = Enabled;

	edtLossVol->Enabled = Enabled;

	edtSetCurrent5->Enabled = Enabled;
	edtSetCurrent9->Enabled = Enabled;
	edtSetCurrent12->Enabled = Enabled;
	edtSetCurrent15->Enabled = Enabled;
	edtSetCurrent20->Enabled = Enabled;

	btnStart->Enabled = !Enabled;
	pl_Set_Switch->Enabled = !Enabled;
}


void __fastcall TFrmMain::pl_ckb1_1Click(TObject *Sender)
{
	TPanel* pl=(TPanel*)Sender;
	pl->Caption = pl->Caption == "+" ? "-":"+";
	pl->Tag = pl->Caption=="+" ? 1:0;
}
//---------------------------------------------------------------------------


void __fastcall TFrmMain::edt_min1Change(TObject *Sender)
{
	TEdit* edt=(TEdit*)Sender;
	if(edt->Text.Length()>5)
		edt->Text = edt->Text.SubString(1,5);
	TCHAR HexChar[8];
	bool bPASS = true;
	bool bPoint = false;
	if(edt->Text.Length() == 0){
		bPASS =false;
	}
	else
	{
		edt->Text = edt->Text.UpperCase();// 把字串轉成全大寫
		_tcscpy_s(HexChar, 8, edt->Text.c_str());
		for(int j=0;j<edt->Text.Length();j++)
		{
			if(HexChar[j] < 0x30 || HexChar[j] > 0x39){
				if(HexChar[j] == 0x2E)
				{
					if(j == edt->Text.Length()-1 ||bPoint)
					{
						edt->Font->Color = clRed;
						edt-> SelStart=edt-> Text.Length();
						bPASS = false;
					}
					if(!bPoint) bPoint = true;
				}
				else
				{
					edt->Font->Color = clRed;
					edt-> SelStart=edt-> Text.Length();
					bPASS = false;
				}
			}
		}
	}
	if(bPASS)
	{
		edt->Font->Color = edt->Text.ToDouble() <= 99 ? clBlue : clRed;
		FormResize(NULL);
	}

	edt-> SelStart=edt-> Text.Length();
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::edt_min1Exit(TObject *Sender)
{
	TEdit* edt=(TEdit*)Sender;
	if(edt->Text.Length() == 0 || edt->Font->Color == clRed){
		edt->Text = AnsiString(edt->Tag)+".00";
		edt->Font->Color = clBlue;
	}
	else
	{
		AnsiString edtnum = AnsiString(edt->Text.ToDouble());
		edtnum.printf("%.2f",atof(edtnum.c_str()));
		edt->Text =  edtnum;
	}

}
//---------------------------------------------------------------------------
bool TFrmMain::SaveVoltageRangeSetting()
{
	for(int i =1;i <= 5;i++)
	{
		MAX_VOLTAGE_TOLERANCE_RANGE[i-1] = ((TEdit *)FindComponent("edt_max"+IntToStr(i))) ->Text.ToDouble();
		MIN_VOLTAGE_TOLERANCE_RANGE[i-1] = ((TEdit *)FindComponent("edt_min"+IntToStr(i))) ->Text.ToDouble();
		if(MIN_VOLTAGE_TOLERANCE_RANGE[i-1]>MAX_VOLTAGE_TOLERANCE_RANGE[i-1])
		{
			AnsiString ERROR_MSG = "["+AnsiString(zVoltageSetting[i-1]->Caption)+"量測電壓]最小電壓不應大於最大電壓";
			MessageBoxA(NULL,ERROR_MSG.c_str(),"ERROR", MB_ICONEXCLAMATION);
			return false;
		}
	}
	FormResize(NULL);
	return true;
}

void __fastcall TFrmMain::pl_Set_SwitchClick(TObject *Sender)
{
	if(pl_Set->Height)
	{
	   pl_Set->Height = 0;
	   pl_Set_Switch ->Caption ="v";
	   FrmMain->Height -=245;
	}
	else
	{
	   pl_Set->Height = 245;
	   FrmMain->Height +=245;
	   pl_Set_Switch ->Caption ="^";
	}
	FormResize(NULL);
}
//---------------------------------------------------------------------------
void TFrmMain::Delay(ULONG iMilliSeconds) // 原版delay time 用在thread裡面
{
	ULONG iStart;
	iStart = GetTickCount();
	while (GetTickCount() - iStart <= iMilliSeconds)
		Application->ProcessMessages();
}
//---------------------------------------------------------------------------
// PSU Test
int TFrmMain::DL_CMD(AnsiString CMD,AnsiString PDVol)
{
	int Result;
	if(CL_DEV_CONTROL->open_dev_com())
	{
		que_cmd.c.clear();
		char buff[200];
		TEdit* edtSetCurrent = (TEdit *)FrmMain->FindComponent("edtSetCurrent"+PDVol);
		AnsiString strCurrent = edtSetCurrent->Text;
		if(CMD.Pos("LOAD ON"))
		{
			if(strCurrent.ToDouble() > 1)
			{
				//strCurrent = AnsiString(strCurrent.ToDouble()-1);
				//que_cmd.push("*remote;chan 1;mode cc;pres on;curr:high "+strCurrent+"\n");
				que_cmd.push("*remote;chan 1;mode cc;pres on;curr:high 0.7\n");
				que_cmd.push(CMD);
				que_cmd.push("*remote;chan 1;mode cc;pres on;curr:high "+edtSetCurrent->Text+"\n");
			}
			else
			{
				que_cmd.push("*remote;chan 1;mode cc;pres on;curr:high "+strCurrent+"\n");
				que_cmd.push(CMD);
            }
		}
		else
		{
			que_cmd.push("*remote;chan 1;mode cc;pres on;curr:high "+edtSetCurrent->Text+"\n");
			que_cmd.push(CMD);
		}
		//測試
		Result = CL_DEV_CONTROL->Dev_CMD_Test(PDVol) ? TEST_PASS:TEST_FAIL;
		if(CL_DEV_CONTROL->bNoResponse)
		{
			CL_DEV_CONTROL->bCOM_PORT_OPEN = false;
			MessageBox(this->Handle, _T("動態負載機通訊失敗!請檢查線路!"), Application->Title.t_str(), MB_ICONWARNING);
			Result = DL_NOT_FIND;
		}
	}
	else
	{
		MessageBox(this->Handle, _T("動態負載機通訊失敗!請檢查線路!(Not Find COM-PORT)"), Application->Title.t_str(), MB_ICONWARNING);
		DEBUG("ERROR : Not Find Device COM-PORT");
		CL_DEV_CONTROL->bCOM_PORT_OPEN = false;
		Result = DL_NOT_FIND;
	}
	return Result;
}



void __fastcall TFrmMain::plResultDblClick(TObject *Sender)
{
	if(moDebug->Width)
	{
		moDebug->Width = 0;
		FrmMain->Width = 978;
	}
	else
	{
		moDebug->Width = 270;
		FrmMain->Width = FrmMain->Width+270;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::edtPassWordKeyPress(TObject *Sender, wchar_t &Key)
{
	if(Key == 13)
		btnSet->Click();
	else
		edtPassWord->Font->Color = clBlue;
}
//---------------------------------------------------------------------------
bool TFrmMain::FindIniFile()
{
	TSearchRec Sr;
	TStringList*FileList=new TStringList();
	if(FindFirst("*.ini",faAnyFile,Sr)==0)
	{
		do
		{
			FileList->Add(Sr.Name);
		}
		while(FindNext(Sr)==0);
		FindClose(Sr);
	}
	if(FileList->Count>1||FileList->Count==0)
	{
		delete FileList;
		plIniName->Font->Color = clRed;
		return false;
	}
	else
	{
		FILE_DUT_SET_INI = FileList->Strings[0];
		if(FILE_DUT_SET_INI.Length()>12)
			plIniName->Caption = FILE_DUT_SET_INI.SubString(8,FILE_DUT_SET_INI.Length()-11);
		delete FileList;
		return true;
	}
}
bool TFrmMain::ReadInISet()
{
	AnsiString value;
	value = Findfilemsg(FILE_DUT_SET_INI,"[AutoTestItem]",1);
	for(int i=1;i <=value.Length();i++)
		zAuto_Test[value.SubString(i,1).ToInt()-1]->Caption = "V";
	//
	value = Findfilemsg(FILE_DUT_SET_INI,"[DutPluginAutoTest]",1);
	ckbAuto->Checked = value == 1 ? true:false;
	//
	value = Findfilemsg(FILE_DUT_SET_INI,"[DelayTime20V]",1);
	if(value != "")
		DelayTime20V = value.ToInt();
	//
	value = Findfilemsg(FILE_DUT_SET_INI,"[DelayTimeBack5V]",1);
	if(value != "")
		DelayTimeBack5V = value.ToInt();
	//
	value = Findfilemsg(FILE_DUT_SET_INI,"[DutPidVid]",1);
	edtVID->Text = value.SubString(5,4);
	edtPID->Text = value.SubString(14,4);
	//
	edtSetCurrent5->Text = Findfilemsg(FILE_DUT_SET_INI,"[SetCurrent]",1);
	edtSetCurrent9->Text = Findfilemsg(FILE_DUT_SET_INI,"[SetCurrent]",2);
	edtSetCurrent12->Text = Findfilemsg(FILE_DUT_SET_INI,"[SetCurrent]",3);
	edtSetCurrent15->Text = Findfilemsg(FILE_DUT_SET_INI,"[SetCurrent]",4);
	edtSetCurrent20->Text = Findfilemsg(FILE_DUT_SET_INI,"[SetCurrent]",5);
	//
	edtLossVol->Text = Findfilemsg(FILE_DUT_SET_INI,"[LossVoltage]",1);
	//
	for(int i=1 ;i<=5 ;i++)
	{
		value = Findfilemsg(FILE_DUT_SET_INI,"[VoltageToleranceRange_"+IntToStr(i)+"]",1);
		((TEdit *)FindComponent("edt_min"+IntToStr(i)))->Text	  = value.SubString(1,value.Pos("、")-1);
		((TEdit *)FindComponent("edt_max"+IntToStr(i)))->Text	  = value.SubString(value.Pos("、")+2,value.Pos("&")-value.Pos("、")-2);
		value = value.Delete(1,value.Pos("&"));
		((TEdit *)FindComponent("edt_load_min"+IntToStr(i)))->Text	  = value.SubString(1,value.Pos("、")-1);
		((TEdit *)FindComponent("edt_load_max"+IntToStr(i)))->Text	  = value.SubString(value.Pos("、")+2,value.Length()-value.Pos("、")+2);

	}
	value = Findfilemsg(FILE_DUT_SET_INI,"[OverLoadTestItem]",1);
	TPanel* zCkbOverLoad[5];
	for(int i=0;i<5;i++)
	   zCkbOverLoad[i] = (TPanel*)FindComponent("plFullLoad_"+IntToStr(i+1));
	for(int i=1;i <=value.Length();i++)
		zCkbOverLoad[value.SubString(i,1).ToInt()-1]->Caption = "V";
	//
	return true;
}
void TFrmMain::SetInIVal(AnsiString numTestItem,bool AutoTest,AnsiString DutVPID){

	AnsiString VoltageRange[5];
	for(int i =1 ;i <=5 ;i++)
		VoltageRange[i-1] =
			AnsiString(((TEdit *)FindComponent("edt_min"+IntToStr(i)))->Text)
			+ "、"
			+ AnsiString(((TEdit *)FindComponent("edt_max"+IntToStr(i)))->Text)
			+ "&"
			+ AnsiString(((TEdit *)FindComponent("edt_load_min"+IntToStr(i)))->Text)
			+ "、"
			+ AnsiString(((TEdit *)FindComponent("edt_load_max"+IntToStr(i)))->Text);


	fstream fp;
	fp.open(FILE_DUT_SET_INI.c_str(), ios::out); // 開啟檔案
	fp << "[AutoTestItem]" << endl;
	fp << numTestItem.c_str() << endl;
	fp << "[DutPluginAutoTest]" << endl;
	if(AutoTest) fp << "1" << endl;
	else fp << "0" << endl;
	//
	fp << "[DelayTime20V]" << endl;
	fp << AnsiString(DelayTime20V).c_str() << endl;
	//
	fp << "[DelayTimeBack5V]" << endl;
	fp << AnsiString(DelayTimeBack5V).c_str() << endl;
	//
	fp << "[OverLoadTestItem]" << endl;
	AnsiString numOverLoad="";
	for(int i=0;i<5;i++)
	   if(((TPanel*)FindComponent("plFullLoad_"+IntToStr(i+1)))->Caption!="")
			numOverLoad+=AnsiString(i+1);
	fp << numOverLoad.c_str() << endl;
	fp << "[DutPidVid]" << endl;
	if(edtVID->Font->Color==clBlue&&edtPID->Font->Color==clBlue)
		fp << DutVPID.c_str() << endl;
	fp << "[SetCurrent]" << endl;
	fp << AnsiString(edtSetCurrent5->Text).c_str() << endl;
	fp << AnsiString(edtSetCurrent9->Text).c_str() << endl;
	fp << AnsiString(edtSetCurrent12->Text).c_str() << endl;
	fp << AnsiString(edtSetCurrent15->Text).c_str() << endl;
	fp << AnsiString(edtSetCurrent20->Text).c_str() << endl;

	fp << "[LossVoltage]" << endl;
	fp << AnsiString(edtLossVol->Text).c_str() << endl;

	fp << "[VoltageToleranceRange_1]" << endl;
	fp << VoltageRange[0].c_str() << endl;
	fp << "[VoltageToleranceRange_2]" << endl;
	fp << VoltageRange[1].c_str() << endl;
	fp << "[VoltageToleranceRange_3]" << endl;
	fp << VoltageRange[2].c_str() << endl;
	fp << "[VoltageToleranceRange_4]" << endl;
	fp << VoltageRange[3].c_str() << endl;
	fp << "[VoltageToleranceRange_5]" << endl;
	fp << VoltageRange[4].c_str() << endl;

	fp.close(); // 關閉檔案
}
AnsiString TFrmMain::Findfilemsg(AnsiString filename, AnsiString findmsg,
	int rownum) { // 找檔案找到字串行回傳幾行後的字串
	ifstream lanfile(filename.c_str());
	std::string filemsg;
	if (lanfile.is_open()) {
		while (!lanfile.eof()) {
			getline(lanfile, filemsg);
			if (strstr(filemsg.c_str(), findmsg.c_str())) {
				for (int i = 0; i < rownum; i++)
					getline(lanfile, filemsg);
				lanfile.close();
				return(AnsiString)filemsg.c_str();
			}
		}
		lanfile.close();
		return "";
	}
	else
		return "";
}



void __fastcall TFrmMain::pl_SetResize(TObject *Sender)
{
	for (int i = 0; i <= 5; ++i)
	{
		((TPanel *)FindComponent("plSetVolTitle_" + IntToStr(i)))->Width =(pl_Set->Width-96) / 4;
		if(i)
		{
			((TPanel *)FindComponent("edt_min" + IntToStr(i)))->Width =(plSetVolTitle_0->Width-32) / 2;
			((TPanel *)FindComponent("edt_max" + IntToStr(i)))->Width =(plSetVolTitle_0->Width-32) / 2;
			((TPanel *)FindComponent("edt_load_min" + IntToStr(i)))->Width =(plSetVolTitle_0->Width-32) / 2;
			((TPanel *)FindComponent("edt_load_max" + IntToStr(i)))->Width =(plSetVolTitle_0->Width-32) / 2;
		}
	}
	plSetNoLoadVolTitle->Width = plSetVolTitle_0->Width;
	plSetFullLoadVolTitle->Width = plSetVolTitle_0->Width;
	plLoadCurr->Width = plSetVolTitle_0->Width;
	plLossVolTitle->Width = plSetVolTitle_0->Width;

	edtSetCurrent5->Width = plSetVolTitle_0->Width;
	edtSetCurrent9->Width = plSetVolTitle_0->Width;
	edtSetCurrent12->Width = plSetVolTitle_0->Width;
	edtSetCurrent15->Width = plSetVolTitle_0->Width;
	edtSetCurrent20->Width = plSetVolTitle_0->Width;

	plVidTitle->Width = pl_DutVPID->Width/6;
	plPidTitle->Width = pl_DutVPID->Width/6;
	edtVID->Width	  = pl_DutVPID->Width/3;
	edtPID->Width	  = pl_DutVPID->Width/3;
}
//---------------------------------------------------------------------------
bool TFrmMain::getLanMAC() { // 得到網卡名稱IP
	int IpCount = 0;
	ULONG ulLen1 = 8192;
	BYTE *pbBuf1 = new BYTE[ulLen1];
	IP_ADAPTER_INFO *pipai = NULL;
	IP_ADDR_STRING *pipas = NULL;
	if (ERROR_SUCCESS == GetAdaptersInfo((IP_ADAPTER_INFO*)pbBuf1, &ulLen1)) {
		pipai = (IP_ADAPTER_INFO*)pbBuf1;
		do {
			AnsiString LanName = (AnsiString)pipai->Description;
			// 取得網卡名稱並儲存
			pipas = &(pipai->IpAddressList); // 取得網卡IP並儲存
			while (pipas != NULL) {
				if(LanName.LowerCase().Pos("targus")||LanName.LowerCase().Pos("displaylink"))
				{
					// Mac ID
					DUT_MAC.sprintf("%02X:%02X:%02X:%02X:%02X:%02X", pipai->Address[0],
					pipai->Address[1], pipai->Address[2], pipai->Address[3],
					pipai->Address[4], pipai->Address[5]);
					delete pbBuf1;
					return true;
				}
				pipas = pipas->Next;
			}
			pipai = pipai->Next;
			IpCount++;
		}
		while (pipai != NULL);
	}
	delete pbBuf1;
	return false;
}
void __fastcall TFrmMain::lbLOGStatusClick(TObject *Sender)
{
	//DEBUG(CL_WNETLOG->WNetFileERROR_MSG());
}
//---------------------------------------------------------------------------
bool TFrmMain::LocalWriteLOG(AnsiString PATH,AnsiString Line)
{
	FILE * fp;
	fp = fopen(LOG_FILE_PATH.c_str(),"a+");
	fseek( fp, 0, SEEK_END);
	fwrite(Line.c_str(),Line.Length(),1,fp); //寫入一筆資料
	fclose(fp);
	//
}
bool TFrmMain::AddLocalFilePath(AnsiString PATH)
{
	if(!DirectoryExists(PATH.c_str()))
	{
		AnsiString SS,Temp = "";
		while(true)
		{
			SS = PATH.SubString(1,PATH.Pos("\\"));
			PATH.Delete(1,PATH.Pos("\\"));
			Temp+=SS;
			_mkdir( Temp.c_str());
			if(PATH == "")
				break;
		}
	}

	return true;
}


void __fastcall TFrmMain::plVidTitleClick(TObject *Sender)
{
	LocalWriteLOG(LOG_FILE_PATH,"Test");
}
//---------------------------------------------------------------------------


void __fastcall TFrmMain::plPidTitleClick(TObject *Sender)
{
	AddLocalFilePath(LOG_FILE_PATH);
}
//---------------------------------------------------------------------------
void __fastcall TFrmMain::Timer1Timer(TObject *Sender)
{
	Timer1->Enabled = false;
	if(ckbAuto->Checked)
	{
		switch(dwStep)
		{
			case CHECK_DEV_ONLINE:
				if(CL_USB->VPIDCheckUSBDev(edtVID->Text,edtPID->Text)
					||CL_USB->VPIDCheckHUBDev(edtVID->Text,edtPID->Text))
				{
					if(btnSet->Caption!= "END")
					{
						btnSet->Enabled = false;
						dwStep = START_TEST;
					}
				}
				break;
			case START_TEST:
				Main_Test(true);
				btnSet->Enabled = true;
				dwStep = CHECK_DEV_OFFLINE;
				break;
			case CHECK_DEV_OFFLINE:
				if(m_hid.m_online) HID_TurnOff();
				if(!CL_USB->VPIDCheckUSBDev(edtVID->Text,edtPID->Text)
					&&!CL_USB->VPIDCheckHUBDev(edtVID->Text,edtPID->Text))
				{
					for(int i=0;i < 5 ;i++)
					{
						zRead_AD_Voltage[i]->Font->Color = clWhite;
						zRead_AD_Voltage[i]->Caption = "";
						zRead_FULL_LOAD_Voltage[i]->Font->Color = clWhite;
						zRead_FULL_LOAD_Voltage[i]->Caption = "";
						plResult->Caption = "Wait...";
						plResult->Color = clWhite;
					}
					dwStep = CHECK_DEV_ONLINE;
				}
		}
	}
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
