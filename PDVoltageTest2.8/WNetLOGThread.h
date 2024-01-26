//---------------------------------------------------------------------------

#ifndef WNetLOGThreadH
#define WNetLOGThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TWNetFileThread : public TThread
{
private:

	bool AddWNetFilePath(AnsiString PATH);
protected:
	void __fastcall Execute();
public:
	AnsiString WNetFileERROR_MSG();
	bool WNetFileConnection();
	bool WNetWriteLOG(AnsiString PATH,AnsiString Line);
	__fastcall TWNetFileThread(bool CreateSuspended);

};
//---------------------------------------------------------------------------
#endif
