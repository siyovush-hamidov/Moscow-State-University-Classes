//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include <Vcl.Themes.hpp>
#include <System.SysUtils.hpp>
#include <System.DateUtils.hpp>
#include <System.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLoginWindow *LoginWindow;
//---------------------------------------------------------------------------
__fastcall TLoginWindow::TLoginWindow(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TLoginWindow::Button1Click(TObject *Sender)
{
	if(Edit1->Text != "")
	{
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("SELECT * FROM Register WHERE Login COLLATE SQL_Latin1_General_CP1_CS_AS  = '"+Edit1->Text+"' ");
		ADOQuery1->Open();

		if(ADOQuery1->RecordCount == 1)
		{
			LoginWindow->Visible = False;
			PasswordWindow->Visible = True;
		}
		if(ADOQuery1->RecordCount == 0)
		{
			MessageDlg("������������ �� ������!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
		}
	}
	else
	{
		MessageDlg("������������ �����!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
	}
}
//---------------------------------------------------------------------------


void __fastcall TLoginWindow::FormCreate(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT * FROM Register");
	ADOQuery1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TLoginWindow::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
	if(Key == 13)
	{
        Key = 0;
		LoginWindow->Button1Click(Button1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TLoginWindow::Label3Click(TObject *Sender)
{
	LoginWindow->Visible = False; StudentRegistration->Visible = True;
}
//---------------------------------------------------------------------------


void __fastcall TLoginWindow::FormClose(TObject *Sender, TCloseAction &Action)
{
//    MainWindow->Close();
}
//---------------------------------------------------------------------------

