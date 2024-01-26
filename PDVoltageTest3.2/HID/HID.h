
//---------------------------------------------------------------------------
#ifndef HIDH
#define HIDH

#define DEVICE_PATH_LENGTH 95
#define DEVICE_SYMBOL_LENGTH 38

#include <windows.h>
#include "IO_Request.h"
#include <vcl.h>
//#include <guiddef.h>
extern "C"
{
#include "setupapi.h"
#include "hidsdi.h"  //HidD_GetHidGuid(&HidGuid);
}

#include <vector>
using namespace std;
typedef std::basic_string<TCHAR> tstring;
//#ifndef UNICODE
//  typedef std::string  tstring;
//#else
//  typedef std::wstring tstring;
//#endif


#define HID_IS_ONLINE		0
#define HID_TURN_ON			1
#define SET_VOLTAGE			2
#define EXECUTE_SETTING 	3
#define HID_READ_VOLTAGE 	4
#define HID_CHECK_VOLTAGE 	5
#define HID_ERROR			99

#define HARDWARE_VOLTAGE_COMPENSATION 13

const wchar_t PD_BOARD_PVID[] = L"hid#vid_0835&pid_fe00";
const AnsiString ExecuteVoltageSetting = "03 14 07 70 08 04 41 4E 65 67";
const AnsiString ReadADValue = "03 13 E8 FF 90";
const float UNIT = 0.0195; //單位元電壓值

const AnsiString ReadEMarkValue = "03 14 05 71 30";
//---------------------------------------------------------------------------
class HID {
private:
	bool m_configured;
	GUID m_classGuid; //HID 的 類別 GUID
	TCHAR m_vid[5], m_pid[5], m_mi[3], m_col[3];
	TCHAR m_symbol[DEVICE_SYMBOL_LENGTH];
	TCHAR m_path[DEVICE_PATH_LENGTH];
	unsigned short m_RxBytes, m_TxBytes;
	//
	IO_Request m_ir, m_or;
	//
	bool HID_TurnOn();
	void Tx(AnsiString Value);
	bool Rx(AnsiString Value);
	bool HID_ReadReport(AnsiString Value);
	void Rx_ValueAnalyze(AnsiString Value);
	int  HexToInt(AnsiString HexStr) ;

	double dbAutoVoltage;
	AnsiString AD_VALUE;
protected:
	bool IsConfigured();
	bool Find(vector<tstring> *pPaths = NULL);
	bool GetPath(HDEVINFO hDevinfo, SP_DEVICE_INTERFACE_DATA *pData, vector<tstring> *pPaths);
	bool CreateHandle();
	void ReleaseHandle();
public:
	bool m_online;
	HANDLE m_hWrite; // = INVALID_HANDLE_VALUE;
	HANDLE m_hRead; // = INVALID_HANDLE_VALUE;

	HID();
	~HID();

	bool Configure(TCHAR vid[5], TCHAR pid[5], TCHAR mi[3], TCHAR col[3]);
	bool Open();
	bool IsOnline();
	bool Write(const unsigned char *cmd);
	bool Read(unsigned char *cmd);
	unsigned char ExecuteTask(const unsigned char writeBuffer[1], unsigned char readBuffer[1]);
	TCHAR* GetSymbol();
	TCHAR* GetPath();
	unsigned short GetRxBytes();
	unsigned short GetTxBytes();
	void GetRxTxBytes();
	void Close();
	void EnumPresentHidPaths(vector<tstring> *pPaths);
	//
	bool HID_Control(AnsiString CMD);
	bool HID_READ_VALUE();
	bool HID_READ_EMARK();
	void SetAutoVoltageValue(double value);

	AnsiString HID_READ_E_MARK_VALUE;
};
// ---------------------------------------------------------------------------
#endif
