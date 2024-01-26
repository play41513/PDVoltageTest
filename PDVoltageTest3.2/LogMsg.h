//---------------------------------------------------------------------------

#ifndef LogMsgH
#define LogMsgH
#include <queue>
#include <direct.h>
#include <fstream.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "ConstantString.h"
//---------------------------------------------------------------------------
typedef struct _LOG_DESCRIPOR
{
  AnsiString datetime;
  AnsiString workorder;
  AnsiString userid;
  AnsiString mac;
  AnsiString sn;
  AnsiString workordersn;
  AnsiString result;
  AnsiString testtime;
  AnsiString errorcode;

}LOG_DESCRIPOR;

class cLogMsg
{
	private:
		std::queue<AnsiString> queMsg;
		AnsiString strLogName;
		AnsiString strLocalLog;
		AnsiString strErrorMsg;
		AnsiString strStartTime;
		AnsiString WNetERROR_MSG;
		DWORD dwWriteLogCount;
		bool WNetFileConnection(WNet_LOG_DESCRIPOR WNet);
		bool AddWNetFilePath(WNet_LOG_DESCRIPOR WNet);
		WNet_LOG_DESCRIPOR WNetLOG;

		LOG_DESCRIPOR LOG_DESC;
		DWORD dwStartTime;
		void SetEndTimeMsg();
	public:
		cLogMsg::cLogMsg(void);
		void AddLineToLogQueue(AnsiString Line);
		void AddLocalFilePath(AnsiString ToolName);
		void Local_MC12X_LOG(AnsiString Line);
		void WriteLocalLOG(AnsiString Line,bool bPass,WNet_LOG_DESCRIPOR WNet);
		void WriteErrorMsg(AnsiString Line);
		void SetStartTimeMsg();
		bool WNetWriteLOG(AnsiString Line,WNet_LOG_DESCRIPOR WNet);
        AnsiString ReadQueMsg();
};
#endif