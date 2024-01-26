//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmMain *FrmMain;
//UI調整參數
DWORD MouseY,memo_heigh=0;
bool xCapture;
//---------------------------------------------------------------------------
__fastcall TFrmMain::TFrmMain(TComponent* Owner)
	: TForm(Owner)
{
	FrmMain->Caption = APP_TITLE;
	CL_FileControl = new cFileControl();
	mLogMsg = new cLogMsg();
	FindIniFile();
	mainThread = new TMainThread(false,INI_Desc,Handle,mLogMsg);

	mLogMsg->AddLocalFilePath("C:\\ASMP\\log\\PDVotageTool\\"+INI_Desc.ININame+"\\");
	//消息
	OldFormWndProc = this->WindowProc;
	this->WindowProc = FormWndProc;
}
//---------------------------------------------------------------------------
void __fastcall TFrmMain::FormWndProc(TMessage& Message)
{
	switch(Message.Msg)
	{
		case WM_UI_PANEL_RESULT:
			switch(Message.WParam)
			{
				case UI_PANEL_RESULT_WAIT:
					btnStart->Enabled = true;
					btnSet->Enabled = true;
					plResult->Caption = "Wait...";
					plResult->Color = clWhite;
					break;
				case UI_PANEL_RESULT_TESTING:
					btnStart->Enabled = false;
					btnSet->Enabled = false;
					plResult->Caption = "Testing...";
					plResult->Color = clWhite;
					break;
				case UI_PANEL_RESULT_PASS:
					btnStart->Enabled = true;
					btnSet->Enabled = true;
					plResult->Color = clLime;
					plResult->Caption = "PASS";
					break;
				case UI_PANEL_RESULT_FAIL:
					btnStart->Enabled = true;
					btnSet->Enabled = false;
					plResult->Color = clRed;
					plResult->Caption = "FAIL";
					break;
			}
			FrmMain->Refresh();
			break;
		case WM_UI_PANEL_NOLOAD:
			INI_Desc = mainThread->ReadINIDesc();
			INI_Desc.PITEM_PD_DESCRIPOR[Message.LParam].plNoLoadValue->Caption
				 = INI_Desc.strReadValueNow;
			switch(Message.WParam)
			{
				case UI_PANEL_FONT_GREEN:
					INI_Desc.PITEM_PD_DESCRIPOR[Message.LParam].plNoLoadValue
						->Font->Color = clGreen;
					break;
				case UI_PANEL_FONT_RED:
					INI_Desc.PITEM_PD_DESCRIPOR[Message.LParam].plNoLoadValue
						->Font->Color = clRed;
					break;
				case UI_PANEL_FONT_BLUE:
					INI_Desc.PITEM_PD_DESCRIPOR[Message.LParam].plNoLoadValue
						->Font->Color = clBlue;
					break;
			}
			break;
		case WM_UI_PANEL_FULLLOAD:
			INI_Desc = mainThread->ReadINIDesc();
			INI_Desc.PITEM_PD_DESCRIPOR[Message.LParam].plFullLoadValue->Caption
				 = INI_Desc.strReadValueNow;
			switch(Message.WParam)
			{
				case UI_PANEL_FONT_GREEN:
					INI_Desc.PITEM_PD_DESCRIPOR[Message.LParam].plFullLoadValue
						->Font->Color = clGreen;
					break;
				case UI_PANEL_FONT_RED:
					INI_Desc.PITEM_PD_DESCRIPOR[Message.LParam].plFullLoadValue
						->Font->Color = clRed;
					break;
				case UI_PANEL_FONT_BLUE:
					INI_Desc.PITEM_PD_DESCRIPOR[Message.LParam].plFullLoadValue
						->Font->Color = clBlue;
					break;
			}
			break;
	}
	TForm :: WndProc(Message);
}
void __fastcall TFrmMain::ckbAuto1Click(TObject *Sender)
{
	TPanel* pl=(TPanel*)Sender;
	pl->Caption = pl->Caption == "V" ? "":"V";
}
void __fastcall TFrmMain::ckbVPIDAutoClick(TObject *Sender)
{
	TCheckBox *ckb = (TCheckBox*) Sender;
	if(	ckb->Name.Pos("VPID") && ckb->Checked)
		ckbVoltageAuto->Checked = false;
	else if(!ckb->Name.Pos("VPID") && ckb->Checked)
		ckbVPIDAuto->Checked = false;
	INI_Desc.VPID_AutoTest = ckbVPIDAuto->Checked;
	INI_Desc.Voltage_AutoTest = ckbVoltageAuto->Checked;

	btnStart->Caption = ckb->Checked ? "Auto Test":"Start";
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
void __fastcall TFrmMain::plSetVoltage1Click(TObject *Sender)
{
	TPanel* pl=(TPanel*)Sender;

	if(btnStart->Enabled)
	{
		INI_Desc.bError = false;
		mainThread->SetManualTestingStep(pl->Hint.ToInt(),true);
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
		if(SaveSetting())
		{
			btnSet->Caption	  	= "ENTER";
			edtPassWord->Text 	= "";
			SetValueEnabled(false);
//---------------------------------
			if(btnStart->Enabled)
				CL_FileControl->WriteINIFile(INI_Desc);
			mainThread->SetINIDesc(INI_Desc);
		}
	}
}
//---------------------------------------------------------------------------
void  TFrmMain::SetValueEnabled(bool Enabled)
{
	edtPassWord->Enabled = !Enabled;
	edtVID->Enabled = Enabled;
	edtPID->Enabled = Enabled;
	ckbVPIDAuto->Enabled = Enabled;
	ckbVoltageAuto->Enabled = Enabled;
	edtVoltageAutoValue->Enabled = Enabled;
	for(int i=1 ; i<=5 ;i++)
	{
		TPanel  * pl   = ((TPanel *)FindComponent("pl_set_" + IntToStr(i)));
		pl->Enabled	  = Enabled;

		((TEdit *)FindComponent("edt_min"+IntToStr(i)))->Enabled = Enabled;
		((TEdit *)FindComponent("edt_max"+IntToStr(i)))->Enabled = Enabled;
		((TEdit *)FindComponent("edt_load_min"+IntToStr(i)))->Enabled = Enabled;
		((TEdit *)FindComponent("edt_load_max"+IntToStr(i)))->Enabled = Enabled;
	}
	ckbAuto1->Enabled  = Enabled;
	ckbAuto2->Enabled  = Enabled;
	ckbAuto3->Enabled = Enabled;
	ckbAuto4->Enabled = Enabled;
	ckbAuto5->Enabled = Enabled;

	edtSetCurrent1->Enabled = Enabled;
	edtSetCurrent2->Enabled = Enabled;
	edtSetCurrent3->Enabled = Enabled;
	edtSetCurrent4->Enabled = Enabled;
	edtSetCurrent5->Enabled = Enabled;

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
bool TFrmMain::SaveSetting()
{
	AnsiString SS;
	for(int i = 1; i <= 5; i++)
	{
		INI_Desc.PITEM_PD_DESCRIPOR[i-1].bTest =
		((TPanel *)FindComponent("ckbAuto"+AnsiString(i)))->Caption == "V" ? true:false;
		INI_Desc.PITEM_PD_DESCRIPOR[i-1].FullLoadCurrent =
		((TPanel *)FindComponent("edtSetCurrent"+AnsiString(i)))->Caption;
		//
		INI_Desc.PITEM_PD_DESCRIPOR[i-1].NoLoadMinVoltage =
		((TEdit *)FindComponent("edt_min"+IntToStr(i)))->Text;

		INI_Desc.PITEM_PD_DESCRIPOR[i-1].NoLoadMaxVoltage =
		((TEdit *)FindComponent("edt_max"+IntToStr(i)))->Text;

		INI_Desc.PITEM_PD_DESCRIPOR[i-1].FullLoadMinVoltage =
		((TEdit *)FindComponent("edt_load_min"+IntToStr(i)))->Text;

		INI_Desc.PITEM_PD_DESCRIPOR[i-1].FullLoadMaxVoltage =
		((TEdit *)FindComponent("edt_load_max"+IntToStr(i)))->Text;

		INI_Desc.PITEM_PD_DESCRIPOR[i-1].FullLoadCurrent =
        ((TEdit *)FindComponent("edtSetCurrent"+IntToStr(i)))->Text;
	}
	//VID&PID AutoTest
	INI_Desc.VPID_AutoTest = ckbVPIDAuto->Checked;
	INI_Desc.Auto_VID  = edtVID->Text;
	INI_Desc.Auto_PID  = edtPID->Text;
	INI_Desc.Voltage_AutoTest = ckbVoltageAuto->Checked;
	INI_Desc.Auto_VoltageValue = edtVoltageAutoValue->Text;
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
void TFrmMain::FindIniFile()
{
	if(CL_FileControl->FindINIFile())
		ReadINIParm();
}
bool TFrmMain::ReadINIParm()
{
	INI_Desc =  CL_FileControl->ReadINIFile();
	plIniName->Caption = INI_Desc.ININame;
	for(int i = 1; i <= 5; i++)
	{
		((TPanel *)FindComponent("plSetVoltage"+AnsiString(i)))->Caption
			= INI_Desc.PITEM_PD_DESCRIPOR[i-1].PD_Voltage + "V";
		((TPanel *)FindComponent("plSetVolTitle_"+AnsiString(i)))->Caption
			= INI_Desc.PITEM_PD_DESCRIPOR[i-1].PD_Voltage + "V";
		((TPanel *)FindComponent("ckbAuto"+AnsiString(i)))->Caption
			= INI_Desc.PITEM_PD_DESCRIPOR[i-1].bTest ? "V":"";
		((TPanel *)FindComponent("edtSetCurrent"+AnsiString(i)))->Caption
			= INI_Desc.PITEM_PD_DESCRIPOR[i-1].FullLoadCurrent;
		//
		((TEdit *)FindComponent("edt_min"+IntToStr(i)))->Text
			= INI_Desc.PITEM_PD_DESCRIPOR[i-1].NoLoadMinVoltage;
		((TEdit *)FindComponent("edt_max"+IntToStr(i)))->Text
			= INI_Desc.PITEM_PD_DESCRIPOR[i-1].NoLoadMaxVoltage;

		((TEdit *)FindComponent("edt_load_min"+IntToStr(i)))->Text
			= INI_Desc.PITEM_PD_DESCRIPOR[i-1].FullLoadMinVoltage;
		((TEdit *)FindComponent("edt_load_max"+IntToStr(i)))->Text
			= INI_Desc.PITEM_PD_DESCRIPOR[i-1].FullLoadMaxVoltage;
		int iChange[5]= {5,9,12,15,20};
		for(int j=0;j<5;j++)
		{
			if(iChange[j] == INI_Desc.PITEM_PD_DESCRIPOR[i-1].PD_Voltage.ToInt())
			{
				INI_Desc.PITEM_PD_DESCRIPOR[i-1].SetVoltageCMD =  "03 14 04 70 33 01 0"+AnsiString(j+1);
				break;
			}
		}
	}
	INI_Desc.PITEM_PD_DESCRIPOR[0].plNoLoadValue  = pl_read_5v_voltage;
	INI_Desc.PITEM_PD_DESCRIPOR[1].plNoLoadValue  = pl_read_9v_voltage;
	INI_Desc.PITEM_PD_DESCRIPOR[2].plNoLoadValue  = pl_read_12v_voltage;
	INI_Desc.PITEM_PD_DESCRIPOR[3].plNoLoadValue  = pl_read_15v_voltage;
	INI_Desc.PITEM_PD_DESCRIPOR[4].plNoLoadValue  = pl_read_20v_voltage;

	INI_Desc.PITEM_PD_DESCRIPOR[0].plFullLoadValue = pl_full_load_voltage5;
	INI_Desc.PITEM_PD_DESCRIPOR[1].plFullLoadValue = pl_full_load_voltage9;
	INI_Desc.PITEM_PD_DESCRIPOR[2].plFullLoadValue = pl_full_load_voltage12;
	INI_Desc.PITEM_PD_DESCRIPOR[3].plFullLoadValue = pl_full_load_voltage15;
	INI_Desc.PITEM_PD_DESCRIPOR[4].plFullLoadValue = pl_full_load_voltage20;
	//VID&PID AutoTest
	ckbVPIDAuto->Checked = INI_Desc.VPID_AutoTest;
	edtVID->Text = INI_Desc.Auto_VID;
	edtPID->Text = INI_Desc.Auto_PID;
	ckbVoltageAuto->Checked = INI_Desc.Voltage_AutoTest;
	edtVoltageAutoValue->Text = INI_Desc.Auto_VoltageValue;
	//
	return true;
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

	edtSetCurrent1->Width = plSetVolTitle_0->Width;
	edtSetCurrent2->Width = plSetVolTitle_0->Width;
	edtSetCurrent3->Width = plSetVolTitle_0->Width;
	edtSetCurrent4->Width = plSetVolTitle_0->Width;
	edtSetCurrent5->Width = plSetVolTitle_0->Width;

	plVidTitle->Width = pl_DutVPID->Width/6;
	plPidTitle->Width = pl_DutVPID->Width/6;
	edtVID->Width	  = pl_DutVPID->Width/3;
	edtPID->Width	  = pl_DutVPID->Width/3;
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::btnStartClick(TObject *Sender)
{
	mainThread->SetManualTestingStep(0,false);
}
//---------------------------------------------------------------------------


void __fastcall TFrmMain::TimerMsgTimer(TObject *Sender)
{
	TimerMsg->Enabled = false;
	AnsiString SS = mLogMsg->ReadQueMsg();
	if(SS.Length())
		moDebug->Lines->Add(SS);
	TimerMsg->Enabled = true;
}
//---------------------------------------------------------------------------

