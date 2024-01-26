//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainThread.h"
#pragma package(smart_init)
DWORD dwTestCount = 0;
DWORD dwStep,dwIndex;
AnsiString strLocalLog = "";
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TMainThread::TMainThread(bool CreateSuspended,INI_DESCRIPOR info
	,HWND hWnd,cLogMsg* LogMsg)
	: TThread(CreateSuspended)
{
	INI_Desc = info;
	mHwnd = hWnd;
	mLogMsg = LogMsg;
	mLoaderThread = new TLoaderThread(false,INI_Desc,LogMsg);
	dwStep = STEP_CHECK_DEV_ONLINE;
	m_hid.SetAutoVoltageValue(INI_Desc.Auto_VoltageValue.ToDouble());
}
INI_DESCRIPOR TMainThread::ReadINIDesc()
{
	return INI_Desc;
}
void TMainThread::SetINIDesc(INI_DESCRIPOR info)
{
	INI_Desc = info;
}
void TMainThread::SetManualTestingStep(DWORD Index,bool bSingleVoltageTest)
{
	dwIndex = Index;
	dwStep  = bSingleVoltageTest ? STEP_VOLTAGE_TEST : STEP_MANUAL_TESTING;
}
//---------------------------------------------------------------------------
void __fastcall TMainThread::Execute()
{
	//---- Place thread code here ----
	while( !Terminated )
	{
		switch(dwStep)
		{
			case STEP_CHECK_DEV_ONLINE:
				if(INI_Desc.VPID_AutoTest)
				{
					if(CL_USB->VPIDCheckUSBDev(INI_Desc.Auto_VID,INI_Desc.Auto_PID)
						||CL_USB->VPIDCheckHUBDev(INI_Desc.Auto_VID,INI_Desc.Auto_PID))
					{
						mLogMsg->AddLineToLogQueue(DEBUG_TEST_START_VPID_AUTO);
						if(!INI_Desc.bSetting)
						{
							Sleep(INI_Desc.dwDelayTime_Auto_VPID);
							dwStep = STEP_AUTO_TEST;
						}
					}
				}
				if(INI_Desc.Voltage_AutoTest)
				{
					if(m_hid.HID_READ_VALUE())
					{
						mLogMsg->AddLineToLogQueue(DEBUG_TEST_START_VOLTAGE_AUTO);
						Sleep(INI_Desc.dwDelayTime_Auto_Voltage);
						dwStep = STEP_AUTO_TEST;
					}
					else
					{
						if(!m_hid.m_online)
						{
							mLogMsg->AddLineToLogQueue(DEBUG_CAN_NOT_FIND_PDBOARD);
							if(MessageBoxExA(mHwnd, "(!)Can Not Find PD-Board! Press 'Cancel' to close the program!", "Error", MB_RETRYCANCEL,MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US))
								== IDCANCEL)
							{
								TMainThread::Terminate();
								AddToUIUpdateQueue(WM_QUIT,0,0);
							}
						}
                    }
                }
				break;
			case STEP_AUTO_TEST:
				MainTestFun();
				dwStep = STEP_CHECK_DEV_OFFLINE;
				break;
			case STEP_MANUAL_TESTING:
				MainTestFun();
				dwStep = STEP_CHECK_DEV_ONLINE;
				if(INI_Desc.VPID_AutoTest)
				{
					if(CL_USB->VPIDCheckUSBDev(INI_Desc.Auto_VID,INI_Desc.Auto_PID)
						||CL_USB->VPIDCheckHUBDev(INI_Desc.Auto_VID,INI_Desc.Auto_PID))
						dwStep = STEP_CHECK_DEV_OFFLINE;
				}
				if(INI_Desc.Voltage_AutoTest)
				{
					if(m_hid.HID_READ_VALUE())
					 	dwStep = STEP_CHECK_DEV_OFFLINE;
                }
				break;
			case STEP_VOLTAGE_TEST:
				AddToUIUpdateQueue(WM_UI_PANEL_RESULT,UI_PANEL_RESULT_TESTING,NULL);
				Voltage_Test(dwIndex);
				dwStep = STEP_CHECK_DEV_ONLINE;
				AddToUIUpdateQueue(WM_UI_PANEL_RESULT,UI_PANEL_RESULT_WAIT,NULL);
				if(INI_Desc.VPID_AutoTest)
				{
					if(CL_USB->VPIDCheckUSBDev(INI_Desc.Auto_VID,INI_Desc.Auto_PID)
						||CL_USB->VPIDCheckHUBDev(INI_Desc.Auto_VID,INI_Desc.Auto_PID))
						dwStep = STEP_CHECK_DEV_OFFLINE;
				}
				if(INI_Desc.Voltage_AutoTest)
				{
					if(m_hid.HID_READ_VALUE())
					 	dwStep = STEP_CHECK_DEV_OFFLINE;
                }
				break;
			case STEP_CHECK_DEV_OFFLINE:
				if(m_hid.m_online) m_hid.Close();
				if(INI_Desc.VPID_AutoTest)
				{
					if(!CL_USB->VPIDCheckUSBDev(INI_Desc.Auto_VID,INI_Desc.Auto_PID)
						&&!CL_USB->VPIDCheckHUBDev(INI_Desc.Auto_VID,INI_Desc.Auto_PID))
					{
						INI_Desc.strReadValueNow = "";
						for(int i=0;i < 5 ;i++)
						{
							INI_Desc.PITEM_PD_DESCRIPOR[i].NoLoadVoltageNow = "";
							INI_Desc.PITEM_PD_DESCRIPOR[i].FullLoadVoltageNow = "";
							AddToUIUpdateQueue(WM_UI_PANEL_NOLOAD,UI_PANEL_FONT_BLUE,i);
							AddToUIUpdateQueue(WM_UI_PANEL_FULLLOAD,UI_PANEL_FONT_BLUE,i);
						}
						AddToUIUpdateQueue(WM_UI_PANEL_E_MARK,UI_PANEL_FONT_BLUE,NULL);
						AddToUIUpdateQueue(WM_UI_PANEL_RESULT,UI_PANEL_RESULT_WAIT,NULL);
						dwStep = STEP_CHECK_DEV_ONLINE;
					}
				}
				if(INI_Desc.Voltage_AutoTest)
				{
					if(!m_hid.HID_READ_VALUE())
					{
						INI_Desc.strReadValueNow = "";
						for(int i=0;i < 5 ;i++)
						{
							INI_Desc.PITEM_PD_DESCRIPOR[i].NoLoadVoltageNow = "";
							INI_Desc.PITEM_PD_DESCRIPOR[i].FullLoadVoltageNow = "";
							AddToUIUpdateQueue(WM_UI_PANEL_NOLOAD,UI_PANEL_FONT_BLUE,i);
							AddToUIUpdateQueue(WM_UI_PANEL_FULLLOAD,UI_PANEL_FONT_BLUE,i);
						}
						AddToUIUpdateQueue(WM_UI_PANEL_E_MARK,UI_PANEL_FONT_BLUE,NULL);
						AddToUIUpdateQueue(WM_UI_PANEL_RESULT,UI_PANEL_RESULT_WAIT,NULL);
						dwStep = STEP_CHECK_DEV_ONLINE;
					}
				}
		}
		Sleep(1);
	}
}
//---------------------------------------------------------------------------
void TMainThread::MainTestFun()
{
	mLogMsg->SetStartTimeMsg();
	strLocalLog = "";
	INI_Desc.bError   = false;
	mLogMsg->AddLineToLogQueue(DEBUG_AUTO_TEST_START);
	AddToUIUpdateQueue(WM_UI_PANEL_RESULT,UI_PANEL_RESULT_TESTING,NULL);

	//�M��
	mLoaderThread->SetLoaderVoltage("");
	for(int i = 0 ; i < 5 ;i++)
	{
		INI_Desc.PITEM_PD_DESCRIPOR[i].FullLoadVoltageNow = "";
		INI_Desc.PITEM_PD_DESCRIPOR[i].NoLoadVoltageNow = "";
	}
	for(int i=0;i < 5 ;i++)
	{
		AddToUIUpdateQueue(WM_UI_PANEL_NOLOAD,UI_PANEL_FONT_BLUE,i);
		AddToUIUpdateQueue(WM_UI_PANEL_FULLLOAD,UI_PANEL_FONT_BLUE,i);
	}
	AddToUIUpdateQueue(WM_UI_PANEL_E_MARK,UI_PANEL_FONT_BLUE,NULL);
	//
	for(int i = 0; i < 5; i++)
	{
		if(INI_Desc.PITEM_PD_DESCRIPOR[i].bTest)
			Voltage_Test(i);
		mLogMsg->AddLineToLogQueue(DEBUG_SLEEP+AnsiString(INI_Desc.PITEM_PD_DESCRIPOR[i].dwAfterTestDelay));
		Sleep(INI_Desc.PITEM_PD_DESCRIPOR[i].dwAfterTestDelay);
		if(INI_Desc.bHIDError)
			break;
		else if(i==4)
		{
			INI_Desc.bSwitchBack5V = true;
			Voltage_Test(0); //���^��l�q��
			INI_Desc.bSwitchBack5V = false;
		}
	}
	//E-Mark v3.2
	if(INI_Desc.bE_MarkEnable)
	{
		INI_Desc.bE_MarkPass = ReadEMarkValue();
		if(INI_Desc.bE_MarkPass)
		{
			AddToUIUpdateQueue(WM_UI_PANEL_E_MARK,UI_PANEL_FONT_GREEN,NULL);
			strLocalLog = strLocalLog+",E_Mark,PASS";
		}
		else
		{
			INI_Desc.bError = true;
			AddToUIUpdateQueue(WM_UI_PANEL_E_MARK,UI_PANEL_FONT_RED,NULL);
			strLocalLog = strLocalLog+",E_Mark,FAIL";
		}
	}
	//

	if(INI_Desc.WNetLOG.bRecordMAC)
		strLocalLog = "MAC,"+getLanMAC(INI_Desc.WNetLOG.NetworkCardName)+","+strLocalLog;

	mLogMsg->WriteLocalLOG(strLocalLog,!INI_Desc.bError,INI_Desc.WNetLOG);
	if(INI_Desc.bError)
		AddToUIUpdateQueue(WM_UI_PANEL_RESULT,UI_PANEL_RESULT_FAIL,NULL);
	else
	{
		AddToUIUpdateQueue(WM_UI_PANEL_RESULT,UI_PANEL_RESULT_PASS,NULL);
		if(INI_Desc.bExitWhenPASS)
		{
			INI_Desc.dwExitWhenPASSCount--;
			if(INI_Desc.dwExitWhenPASSCount <= 0)
			{
				mLogMsg->Local_MC12X_LOG("PASSED");
				TMainThread::Terminate();
				PostMessage(mHwnd,WM_QUIT,0,0);

			}
		}
	}
}
void TMainThread::Voltage_Test(int index)
{
	//��l��
	int step = HID_CONTROL;
	bool bl = true;
	INI_Desc.bHIDError = false;
	mLogMsg->AddLineToLogQueue(INI_Desc.PITEM_PD_DESCRIPOR[index].PD_Voltage+" V Test");
	strLocalLog += "PD-Voltage,"+INI_Desc.PITEM_PD_DESCRIPOR[index].PD_Voltage + "V";
	if(!INI_Desc.bSwitchBack5V)
	{
		AddToUIUpdateQueue(WM_UI_PANEL_NOLOAD,UI_PANEL_FONT_BLUE,index);
		AddToUIUpdateQueue(WM_UI_PANEL_FULLLOAD,UI_PANEL_FONT_BLUE,index);
	}
	mLogMsg->AddLineToLogQueue(DEBUG_READY_TO_CHANGE_VOLTALE);
	while(bl)
	{
		switch(step)
		{
			case HID_CONTROL:
				mLogMsg->AddLineToLogQueue(DEBUG_SLEEP+AnsiString(INI_Desc.PITEM_PD_DESCRIPOR[index].dwBeforeChangeVoltageDelay));
				Sleep(INI_Desc.PITEM_PD_DESCRIPOR[index].dwBeforeChangeVoltageDelay);
				if(m_hid.HID_Control(INI_Desc.PITEM_PD_DESCRIPOR[index].SetVoltageCMD))
					step = HID_CHANGE_VOLTAGE_DELAYTIME;
				else
					step = HID_NOT_FIND;
				break;
			case HID_CHANGE_VOLTAGE_DELAYTIME:
				mLogMsg->AddLineToLogQueue(DEBUG_AFTER_CHANGE_VOLTALE);
				mLogMsg->AddLineToLogQueue(DEBUG_SLEEP+AnsiString(INI_Desc.PITEM_PD_DESCRIPOR[index].dwAfterChangeVoltageDelay));
				Sleep(INI_Desc.PITEM_PD_DESCRIPOR[index].dwAfterChangeVoltageDelay);
				mLoaderThread->SetLoaderVoltage("");
				step = HID_CMD_NO_LOAD;
				break;
			case HID_CMD_NO_LOAD:
				mLogMsg->AddLineToLogQueue(DEBUG_NO_LOAD_TEST);
				AddToUIUpdateQueue(WM_UI_PANEL_NOLOAD,UI_PANEL_FONT_BLUE,index);
				DL_CMD("SYNC:LOAD OFF\n",index);
				step = READ_NO_LOAD_VOLTAGE_VALUE;
				break;
			case READ_NO_LOAD_VOLTAGE_VALUE:
				INI_Desc.strReadValueNow = mLoaderThread->ReadLoaderVoltage();
				INI_Desc.PITEM_PD_DESCRIPOR[index].NoLoadVoltageNow = INI_Desc.strReadValueNow;
				switch(mLoaderThread->CheckTestStatus())
				{
					case STEP_LOAD_TEST_PASS:
						strLocalLog += ",NoLoad-Voltage," + mLoaderThread->ReadLoaderVoltage()
										+",NoLoad-Current," + mLoaderThread->ReadLoaderCurrent();
						mLogMsg->AddLineToLogQueue(DEBUG_VOLTAGE_TEST_PASS);
						AddToUIUpdateQueue(WM_UI_PANEL_NOLOAD,UI_PANEL_FONT_GREEN,index);
						step = HID_CMD_FULL_LOAD;
						if(INI_Desc.bSwitchBack5V)
							step = TEST_VOLTAGE_END;
						break;
					case STEP_LOAD_TEST_FAIL:
						strLocalLog += ",NoLoad-Voltage," + mLoaderThread->ReadLoaderVoltage()
										+",NoLoad-Current," + mLoaderThread->ReadLoaderCurrent();
						mLogMsg->AddLineToLogQueue(DEBUG_VOLTAGE_TEST_FAIL);
						mLogMsg->WriteErrorMsg(INI_Desc.PITEM_PD_DESCRIPOR[index].PD_Voltage+"V-NoLoad-FAILED");
						AddToUIUpdateQueue(WM_UI_PANEL_NOLOAD,UI_PANEL_FONT_RED,index);
						INI_Desc.bError = true;
						step = TEST_VOLTAGE_END;
						break;
					case STEP_COMPORT_NO_RESPOND:
						INI_Desc.strReadValueNow = "FAIL";
						INI_Desc.PITEM_PD_DESCRIPOR[index].NoLoadVoltageNow = "FAIL";
						AddToUIUpdateQueue(WM_UI_PANEL_NOLOAD,UI_PANEL_FONT_RED,index);
						step = DL_NOT_FIND;
						break;
					default:
						AddToUIUpdateQueue(WM_UI_PANEL_NOLOAD,UI_PANEL_FONT_BLUE,index);
                }
				break;
			case HID_CMD_FULL_LOAD:
				mLogMsg->AddLineToLogQueue(DEBUG_FULL_LOAD_TEST);
				AddToUIUpdateQueue(WM_UI_PANEL_FULLLOAD,UI_PANEL_FONT_BLUE,index);
				mLogMsg->AddLineToLogQueue("Sleep.."+AnsiString(INI_Desc.PITEM_PD_DESCRIPOR[index].dwBeforeFullLoadDelay));
				Sleep(INI_Desc.PITEM_PD_DESCRIPOR[index].dwBeforeFullLoadDelay);
				DL_CMD("SYNC:LOAD ON\n",index);
				step = READ_FULL_LOAD_VOLTAGE_VALUE;
				break;
			case READ_FULL_LOAD_VOLTAGE_VALUE:
				INI_Desc.strReadValueNow = mLoaderThread->ReadLoaderVoltage();
				INI_Desc.PITEM_PD_DESCRIPOR[index].FullLoadVoltageNow = INI_Desc.strReadValueNow;
				switch(mLoaderThread->CheckTestStatus())
				{
					case STEP_LOAD_TEST_PASS:
						strLocalLog += ",FullLoad-Voltage," + mLoaderThread->ReadLoaderVoltage()
										+",FullLoad-Current," + mLoaderThread->ReadLoaderCurrent();
						mLogMsg->AddLineToLogQueue(DEBUG_VOLTAGE_TEST_PASS);
						AddToUIUpdateQueue(WM_UI_PANEL_FULLLOAD,UI_PANEL_FONT_GREEN,index);
						step = TEST_VOLTAGE_END;
						break;
					case STEP_LOAD_TEST_FAIL:
						strLocalLog += ",FullLoad-Voltage," + mLoaderThread->ReadLoaderVoltage()
										+",FullLoad-Current," + mLoaderThread->ReadLoaderCurrent();
						mLogMsg->AddLineToLogQueue(DEBUG_VOLTAGE_TEST_FAIL);
						mLogMsg->WriteErrorMsg(INI_Desc.PITEM_PD_DESCRIPOR[index].PD_Voltage+"V-FullLoad-FAILED");
						AddToUIUpdateQueue(WM_UI_PANEL_FULLLOAD,UI_PANEL_FONT_RED,index);
						step = TEST_VOLTAGE_END;
						INI_Desc.bError = true;
						break;
					case STEP_COMPORT_NO_RESPOND:
						INI_Desc.strReadValueNow = "FAIL";
						INI_Desc.PITEM_PD_DESCRIPOR[index].FullLoadVoltageNow = "FAIL";
						AddToUIUpdateQueue(WM_UI_PANEL_FULLLOAD,UI_PANEL_FONT_RED,index);
						step = DL_NOT_FIND;
						break;
					default:
						AddToUIUpdateQueue(WM_UI_PANEL_FULLLOAD,UI_PANEL_FONT_BLUE,index);
				}
				break;
			case TEST_VOLTAGE_END:
				//DL_CMD("SYNC:LOAD OFF\n",index);
				bl =false;
				break;
			case HID_NOT_FIND:
				strLocalLog += ",NoLoad-Voltage,FAIL,NoLoad-Current,FAIL";
				mLogMsg->WriteErrorMsg(DEBUG_CAN_NOT_FIND_PDBOARD);
				INI_Desc.strReadValueNow = "FAIL";
				INI_Desc.PITEM_PD_DESCRIPOR[index].NoLoadVoltageNow = "FAIL";
				mLogMsg->AddLineToLogQueue(DEBUG_CAN_NOT_FIND_PDBOARD);
				AddToUIUpdateQueue(WM_UI_PANEL_NOLOAD,UI_PANEL_FONT_RED,index);
				INI_Desc.bError = true;
				INI_Desc.bHIDError = true;
				bl =false;
				break;
			case DL_NOT_FIND:
				strLocalLog += ",NoLoad-Voltage,FAIL,NoLoad-Current,FAIL";
				mLogMsg->WriteErrorMsg(DEBUG_CAN_NOT_FIND_LOADER);
				INI_Desc.bError = true;
				INI_Desc.bHIDError = true;
				mLogMsg->AddLineToLogQueue(DEBUG_CAN_NOT_FIND_LOADER);
				MessageBox(mHwnd, _T("(!)Can Not Find Loader"), Application->Title.t_str(), MB_ICONWARNING);
				if(INI_Desc.bExitWhenPASS)
				{
					TMainThread::Terminate();
					PostMessage(mHwnd,WM_QUIT,0,0);
				}
				bl =false;
				break;
		}
		Sleep(10);
	}
}
int TMainThread::DL_CMD(AnsiString CMD,int index)
{
	int Result;
	INI_Desc.PITEM_PD_DESCRIPOR[index].bWattIsOver = false;

	que_cmd.c.clear();
	if(CMD.Pos("LOAD ON"))
	{
		double dbCurrent =  INI_Desc.PITEM_PD_DESCRIPOR[index].FullLoadCurrent.ToDouble();
		double dbInitCurrent =  INI_Desc.PITEM_PD_DESCRIPOR[index].FullInitLoadCurrent.ToDouble();
		double dbVoltage =  INI_Desc.PITEM_PD_DESCRIPOR[index].PD_Voltage.ToDouble();
		if(mLoaderThread->CheckLoaderNameIs3315F())
			INI_Desc.PITEM_PD_DESCRIPOR[index].bWattIsOver = (dbCurrent * dbVoltage) > 75 ? true : false;
		if(INI_Desc.PITEM_PD_DESCRIPOR[index].bWattIsOver)
		{
			que_cmd.push("*remote;chan 1;mode cc;pres on;curr:high "+AnsiString(dbInitCurrent/2)+"\n");
			que_cmd.push("*remote;chan 2;mode cc;pres on;curr:high "+AnsiString(dbInitCurrent/2)+"\n");
			que_cmd.push("SYNC:LOAD ON\n");
			que_cmd.push("*remote;chan 1;mode cc;pres on;curr:high "+AnsiString(dbCurrent/2)+"\n");
			que_cmd.push("*remote;chan 2;mode cc;pres on;curr:high "+AnsiString(dbCurrent/2)+"\n");
			que_cmd.push("chan 2;meas:vc?\n");
		}
		else
		{
			if(INI_Desc.PITEM_PD_DESCRIPOR[index].FullLoadCurrent.ToDouble() > 1)
			{
				que_cmd.push("*remote;chan 1;mode cc;pres on;curr:high "+AnsiString(dbInitCurrent)+"\n");
				que_cmd.push("LOAD ON\n");
				que_cmd.push("*remote;chan 1;mode cc;pres on;curr:high "+AnsiString(dbCurrent)+"\n");
			}
			else
			{
				que_cmd.push("*remote;chan 1;mode cc;pres on;curr:high "+INI_Desc.PITEM_PD_DESCRIPOR[index].FullLoadCurrent+"\n");
				que_cmd.push(CMD);
			}
		}
		que_cmd.push("chan 1;meas:vc?\n");
		que_cmd.push("SYNC:LOAD OFF\n");
	}
	else
	{
		que_cmd.push("*remote;chan 1;mode cc;pres on;curr:high "+INI_Desc.PITEM_PD_DESCRIPOR[index].FullLoadCurrent+"\n");
		que_cmd.push("chan 1;meas:vc?\n");
		que_cmd.push(CMD);
	}
	//����
	INI_Desc.dwTestStatus = 0;
	mLoaderThread->SetQueueCMD(que_cmd);
	mLoaderThread->SetINI_Desc(INI_Desc,index);
	mLoaderThread->SetTestStep(true);
	return Result;
}
AnsiString TMainThread::getLanMAC(AnsiString LANname) { // �o����d�W��IP
	int IpCount = 0;
	ULONG ulLen1 = 8192;
	BYTE *pbBuf1 = new BYTE[ulLen1];
	IP_ADAPTER_INFO *pipai = NULL;
	IP_ADDR_STRING *pipas = NULL;
	if (ERROR_SUCCESS == GetAdaptersInfo((IP_ADAPTER_INFO*)pbBuf1, &ulLen1)) {
		pipai = (IP_ADAPTER_INFO*)pbBuf1;
		do {
			AnsiString LanName = (AnsiString)pipai->Description;
			// ���o���d�W�٨��x�s
			pipas = &(pipai->IpAddressList); // ���o���dIP���x�s
			while (pipas != NULL) {
				if(LanName.Pos(LANname))
				{
					// Mac ID
					AnsiString szTemp;
					szTemp.sprintf("%02X:%02X:%02X:%02X:%02X:%02X", pipai->Address[0],
					pipai->Address[1], pipai->Address[2], pipai->Address[3],
					pipai->Address[4], pipai->Address[5]);
					delete pbBuf1;
					return szTemp;
				}
				pipas = pipas->Next;
			}
			pipai = pipai->Next;
			IpCount++;
		}
		while (pipai != NULL);
	}
	delete pbBuf1;
    return "NULL";
}
void TMainThread::AddToUIUpdateQueue(DWORD msg, DWORD wParam, DWORD lParam)
{
    UI_UPDATE_DESCRIPOR updateDescriptor;
    updateDescriptor.UI_Msg = msg;
    updateDescriptor.UI_WParam = wParam;
    updateDescriptor.UI_LParam = lParam;

    queUIUpdate.push(updateDescriptor);
}
bool TMainThread::ReadEMarkValue()
{
	if(m_hid.HID_READ_EMARK())
		calculateEMarkValue();
	bool bHave;
	for(int i = 0 ; i < 5 ; i++)
	{
		if(INI_Desc.PE_MARK_DESCRIPOR[i].bEnable)
		{
			bHave = false;
			for(int j = 0;j <5;j++)
			{
				if(PE_MARK_DESCRIPOR[j].strEMark_Voltage
					== INI_Desc.PE_MARK_DESCRIPOR[i].strINI_Voltage)
				{
					if(PE_MARK_DESCRIPOR[j].strEMark_Current
						!= INI_Desc.PE_MARK_DESCRIPOR[i].strINI_Current)
					{
						mLogMsg->WriteErrorMsg("E-MARK_Error:"+PE_MARK_DESCRIPOR[j].strEMark_Current+"(A)");
						return false;
                    }
					else
					{
						bHave = true;
						break;
					}
                }
			}
			if(bHave == false)
				return false;
        }
	}
	return true;
}
void TMainThread::calculateEMarkValue()
{
	AnsiString strValue = m_hid.HID_READ_E_MARK_VALUE;
	strValue.Delete(1,25);
	for(int i =0;i<5;i++)
	{
		AnsiString binaryValue = hexToBinary(strValue.SubString(1,11));
		strValue.Delete(1,12);
		AnsiString EMarkVoltage = binaryValue.SubString(29,4)+binaryValue.SubString(17,6);
		EMarkVoltage =	strtoul(EMarkVoltage.c_str(),NULL,2)*0.05;
		AnsiString EMarkCurrent = binaryValue.SubString(23,2)+binaryValue.SubString(9,8);
		EMarkCurrent =	strtoul(EMarkCurrent.c_str(),NULL,2)*0.01;
		mLogMsg->AddLineToLogQueue(AnsiString(i+1)+". E-MARK : "+EMarkVoltage+" V "+EMarkCurrent+" A");

		PE_MARK_DESCRIPOR[i].strEMark_Voltage = EMarkVoltage;
		PE_MARK_DESCRIPOR[i].strEMark_Current = EMarkCurrent;
	}
}
AnsiString TMainThread::hexToBinary(AnsiString hexString)
{
	string binaryResult;
	const char* ptr = hexString.c_str();

    while (*ptr != '\0') {
        char hexValue[3];
        std::strncpy(hexValue, ptr, 2);
        hexValue[2] = '\0';

        unsigned int decimalValue;
        sscanf(hexValue, "%x", &decimalValue);

        std::bitset<8> binary(decimalValue);
        binaryResult += binary.to_string();

        ptr += 2;
        while (*ptr == ' ') {
            ptr++; // Skip any space characters
        }
    }

	return AnsiString(binaryResult.c_str());
}
