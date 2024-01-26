//---------------------------------------------------------------------------

#ifndef mainH
#define mainH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
#include <dbt.h> //DBT_�`�� ���U�n���o���˸m����
#include "DeviceNotify.h"
#include <Buttons.hpp>
#include <Registry.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <Graphics.hpp>

#include "FileControl.h"
#include "ConstantString.h"
#include "MainThread.h"
#include "LogMsg.h"

const AnsiString PASSWORD  = "SET";

//GUID
const char GUID_USB_HUB[] = "{F18A0E88-C30C-11D0-8815-00A0C906BED8}";
const char GUID_USB_DEVICE[] = "{A5DCBF10-6530-11D2-901F-00C04FB951ED}";
const char GUID_HID[] = "{4d1e55b2-f16f-11cf-88cb-001111000030}";

//---------------------------------------------------------------------------

class TFrmMain : public TForm
{
__published:	// IDE-managed Components
	TPanel *pl_Set_Switch;
	TPanel *Panel1;
	TPanel *pl_Set;
	TPanel *pl_set_5;
	TPanel *plSetVolTitle_5;
	TEdit *edt_min5;
	TPanel *pl_set_4;
	TPanel *plSetVolTitle_4;
	TEdit *edt_min4;
	TPanel *pl_set_3;
	TPanel *plSetVolTitle_3;
	TEdit *edt_min3;
	TPanel *pl_set_2;
	TPanel *plSetVolTitle_2;
	TEdit *edt_min2;
	TPanel *pl_set_1;
	TPanel *plSetVolTitle_1;
	TEdit *edt_min1;
	TPanel *pl_ckb1_2;
	TPanel *pl_ckb2_2;
	TPanel *pl_ckb3_2;
	TPanel *pl_ckb4_2;
	TPanel *pl_ckb5_2;
	TEdit *edt_max1;
	TEdit *edt_max2;
	TEdit *edt_max3;
	TEdit *edt_max4;
	TEdit *edt_max5;
	TPanel *Panel16;
	TPanel *Panel21;
	TPanel *Panel26;
	TPanel *Panel31;
	TPanel *Panel37;
	TPanel *Panel63;
	TPanel *plSetVolTitle_0;
	TPanel *plSetNoLoadVolTitle;
	TPanel *plSetFullLoadVolTitle;
	TPanel *Panel15;
	TPanel *Panel17;
	TPanel *plFullLoad_1;
	TPanel *plFullLoad_2;
	TPanel *plFullLoad_3;
	TPanel *plFullLoad_4;
	TPanel *plFullLoad_5;
	TEdit *edt_load_min1;
	TEdit *edt_load_min2;
	TEdit *edt_load_min3;
	TEdit *edt_load_min4;
	TEdit *edt_load_min5;
	TPanel *Panel50;
	TPanel *Panel51;
	TPanel *Panel52;
	TPanel *Panel53;
	TPanel *Panel54;
	TEdit *edt_load_max1;
	TEdit *edt_load_max2;
	TEdit *edt_load_max3;
	TEdit *edt_load_max4;
	TEdit *edt_load_max5;
	TPanel *plLoadCurr;
	TPanel *Panel13;
	TPanel *Panel14;
	TPanel *Panel18;
	TPanel *Panel23;
	TPanel *Panel28;
	TPanel *Panel40;
	TEdit *edtSetCurrent1;
	TEdit *edtSetCurrent2;
	TEdit *edtSetCurrent3;
	TEdit *edtSetCurrent4;
	TEdit *edtSetCurrent5;
	TPanel *Panel22;
	TPanel *Panel71;
	TPanel *pl_Auto;
	TPanel *Panel27;
	TPanel *Panel7;
	TBitBtn *btnStart;
	TPanel *plIniName;
	TPanel *Panel19;
	TPanel *Panel41;
	TPanel *Panel42;
	TPanel *Panel43;
	TLabel *Label1;
	TPanel *Panel45;
	TPanel *Panel2;
	TPanel *pl_read_5v_voltage;
	TPanel *ckbAuto1;
	TPanel *plSetVoltage1;
	TPanel *pl_full_load_voltage5;
	TPanel *Panel3;
	TPanel *pl_read_9v_voltage;
	TPanel *ckbAuto2;
	TPanel *plSetVoltage2;
	TPanel *pl_full_load_voltage9;
	TPanel *Panel4;
	TPanel *pl_read_12v_voltage;
	TPanel *ckbAuto3;
	TPanel *plSetVoltage3;
	TPanel *pl_full_load_voltage12;
	TPanel *Panel5;
	TPanel *pl_read_15v_voltage;
	TPanel *ckbAuto4;
	TPanel *plSetVoltage4;
	TPanel *pl_full_load_voltage15;
	TPanel *Panel6;
	TPanel *pl_read_20v_voltage;
	TPanel *ckbAuto5;
	TPanel *plSetVoltage5;
	TPanel *pl_full_load_voltage20;
	TPanel *plResult;
	TPanel *Panel20;
	TMemo *moDebug;
	TEdit *edtPassWord;
	TBitBtn *btnSet;
	TPanel *Panel25;
	TCheckBox *ckbVPIDAuto;
	TPanel *plVidTitle;
	TEdit *edtVID;
	TPanel *plPidTitle;
	TEdit *edtPID;
	TPanel *Panel9;
	TPanel *pl_DutVPID;
	TPanel *plMAC;
	TLabel *lbLOGStatus;
	TEdit *edtVoltageAutoValue;
	TCheckBox *ckbVoltageAuto;
	TLabel *lbVoltageAuto;
	TPanel *Panel8;
	TPanel *Panel10;
	TTimer *TimerMsg;
	TPanel *plE_Mark;
	TPanel *plE_MarkResult;
	TPanel *plE_MarkTitle;
	void __fastcall ckbAuto1Click(TObject *Sender);
	void __fastcall ckbVPIDAutoClick(TObject *Sender);
	void __fastcall edtVIDChange(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall plSetVoltage1Click(TObject *Sender);

	void __fastcall moDebugChange(TObject *Sender);
	void __fastcall edtPassWordEnter(TObject *Sender);
	void __fastcall btnSetClick(TObject *Sender);
	void __fastcall pl_ckb1_1Click(TObject *Sender);
	void __fastcall edt_min1Change(TObject *Sender);
	void __fastcall edt_min1Exit(TObject *Sender);
	void __fastcall pl_Set_SwitchClick(TObject *Sender);
	void __fastcall plResultDblClick(TObject *Sender);
	void __fastcall edtPassWordKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall pl_SetResize(TObject *Sender);
	void __fastcall btnStartClick(TObject *Sender);
	void __fastcall TimerMsgTimer(TObject *Sender);
private:	// User declarations
	INI_DESCRIPOR INI_Desc;
	cFileControl *CL_FileControl;
	cLogMsg		 *mLogMsg;
	TMainThread *mainThread;

	void SetValueEnabled(bool Enabled);
	bool CheckVPIDSET(TEdit * edt);
	bool SaveSetting();
	void UI_Update();

	void FindIniFile();
	bool ReadINIParm();

public:		// User declarations
	__fastcall TFrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmMain *FrmMain;
//---------------------------------------------------------------------------
#endif