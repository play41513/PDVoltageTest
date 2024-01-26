//---------------------------------------------------------------------------

#ifndef COM_controlH
#define COM_controlH


#define TEST_END			0
#define RS232_WRITE			1
#define RS232_READ			2
#define LOAD_TEST_PASS			3
#define LOAD_TEST_FAIL			4
#define TEST_OCP			5
#define Dev_NO_RESPOND		6

#define GetVoltageCount		3

#include <Registry.hpp>
#include <queue>
#include "ConstantString.h"

//---------------------------------------------------------------------------
struct tag_cmd_desc {
	char *cmd;
	int (*pfn)(char *s);
	};
	typedef struct tag_cmd_desc CMD_DESC;
class cCOM{
	private:
		void	Delay(ULONG iMilliSeconds);
		DWORD 	cmd_get_system_consumptoin(char *s,int index);
		DWORD 	dwGetErrorVolCount,dwGetDataTimeOut;
		INI_DESCRIPOR INI_Desc;
		AnsiString astrVoltage;
		std::queue<AnsiString> que_cmd;
		std::queue<AnsiString> que_Msg;
	public:
		cCOM::cCOM(void);
		AnsiString ReadLoaderVoltage();
		void    SetINI_Desc(INI_DESCRIPOR info);
		double  GetNumOfString(AnsiString String);
		void    SetQueueCMD(std::queue<AnsiString> que);
		bool 	open_dev_com();
		bool 	CheckLoaderNameIs3315F();
		int 	Dev_CMD_Test(int index);
		void 	search_Reg_ComNum();
		void 	SearchDevCOM();

		void 	QueueClear();
		void 	Dev_Stop();

		bool 	bCOM_PORT_OPEN;
		bool 	bNoResponse;

};
#endif