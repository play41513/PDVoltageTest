//---------------------------------------------------------------------------

#ifndef LoaderThreadH
#define LoaderThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Registry.hpp>
#include <queue>
#include "ConstantString.h"
#include "LogMsg.h"
//---------------------------------------------------------------------------
struct ComNum_Info {
	HANDLE handle;
	HANDLE Threadhandle;
	AnsiString ComName;
};

class TLoaderThread : public TThread
{
private:
	AnsiString astrVoltage;
	double  dbCurrentChanel1;
	double  dbCurrentChanel2;
	bool 	bCOM_PORT_OPEN;
	bool    bLoad;
	DWORD	dwLoaderChanel;
	DWORD   dwDevIndex;
	DWORD 	dwGetErrorVolCount,dwGetDataTimeOut;
	HANDLE DEV_hCom;
	cLogMsg *mLogMsg;

	INI_DESCRIPOR INI_Desc;
	std::queue<AnsiString> que_cmd;

	double GetNumOfString(AnsiString String);
	void search_Reg_ComNum();
	void SearchDevCOM();
	void Dev_Stop();
	DWORD cmd_get_system_consumptoin(char *s, int index);
protected:
	void __fastcall Execute();
public:
	__fastcall TLoaderThread(bool CreateSuspended,INI_DESCRIPOR info,cLogMsg* LogMsg);
	bool CheckLoaderNameIs3315F();
	AnsiString ReadLoaderVoltage();
	AnsiString ReadLoaderCurrent();
	void SetINI_Desc(INI_DESCRIPOR info,DWORD Index);
	DWORD CheckTestStatus();
	void SetQueueCMD(std::queue<AnsiString> que);
	void SetTestStep(bool bTest);
	void SetLoaderVoltage(AnsiString strValue);

	bool open_dev_com();
};
//---------------------------------------------------------------------------
#endif