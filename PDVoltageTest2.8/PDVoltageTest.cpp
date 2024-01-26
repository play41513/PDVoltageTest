//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "main.h"
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("main.cpp", FrmMain);
USEFORM("MSGBOX.cpp", frmMsg);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	HWND hwnd = NULL;
	hwnd = FindWindowA(NULL,APP_TITLE.c_str());
   //�� project/Options/Application/Title�]�w�Ө�
   //"TApplication" �u���u�������(������s�b)�~�|���
	if(hwnd)
	{ //�{���w����...
		MessageBoxA(NULL,"Application is already running","WARNING", MB_ICONEXCLAMATION);
	 return 0;
	}
	try
	{
		Application->Initialize();
		Application->Title = APP_TITLE; //�P�W
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFrmMain), &FrmMain);
		Application->CreateForm(__classid(TfrmMsg), &frmMsg);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------