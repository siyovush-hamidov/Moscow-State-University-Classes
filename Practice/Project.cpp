//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("Unit3.cpp", StudentRegistration);
USEFORM("Unit4.cpp", MainWindow);
USEFORM("Unit5.cpp", SplashScreen);
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit2.cpp", PasswordWindow);
//---------------------------------------------------------------------------
#include "Unit5.h"
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		SplashScreen = new TSplashScreen(Application);
		SplashScreen->Show(); SplashScreen->Update();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TMainWindow), &MainWindow);
		Application->CreateForm(__classid(TPasswordWindow), &PasswordWindow);
		Application->CreateForm(__classid(TStudentRegistration), &StudentRegistration);
		SplashScreen->Hide();
		SplashScreen->Free();
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
