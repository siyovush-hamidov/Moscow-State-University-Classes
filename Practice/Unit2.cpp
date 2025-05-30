//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "Unit2.h"

#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPasswordWindow *PasswordWindow;
//---------------------------------------------------------------------------
__fastcall TPasswordWindow::TPasswordWindow(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TPasswordWindow::CheckBox1Click(TObject *Sender)
{
	if(CheckBox1->Checked) Edit1->PasswordChar = 0;
    else Edit1->PasswordChar = '*';
}
//---------------------------------------------------------------------------

void __fastcall TPasswordWindow::Button2Click(TObject *Sender)
{
	PasswordWindow->Visible = False; LoginWindow->Visible = True;
}
//---------------------------------------------------------------------------

void __fastcall TPasswordWindow::Button1Click(TObject *Sender)
{
    if(Edit1->Text != "")
	{
		LoginWindow->ADOQuery1->SQL->Clear();
		LoginWindow->ADOQuery1->SQL->Add("SELECT * FROM Register WHERE Password = '"+THashMD5::GetHashString(Edit1->Text)+"' AND Login = '"+LoginWindow->Edit1->Text+"'");
		LoginWindow->ADOQuery1->Open();

		if(LoginWindow->ADOQuery1->RecordCount == 1)
		{
			PasswordWindow->Visible = false;
			MainWindow->Enabled = true;
            MainWindow->AlphaBlendValue = 255;
		}
		if(LoginWindow->ADOQuery1->RecordCount == 0)
		{
			MessageDlg("������������ ������!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
		}
	}
	else
	{
		MessageDlg("������������ ������!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
	}
}
//---------------------------------------------------------------------------

void __fastcall TPasswordWindow::VirtualImage3Click(TObject *Sender)
{
	PasswordWindow->Visible = False; LoginWindow->Visible = True;
    LoginWindow->Edit1->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall TPasswordWindow::Label3Click(TObject *Sender)
{
	if(CheckBox1->Checked) CheckBox1->Checked = False;
    else CheckBox1->Checked = True;
}
//---------------------------------------------------------------------------


void __fastcall TPasswordWindow::Edit1KeyPress(TObject *Sender, System::WideChar &Key)

{
	if(Key == 13)
	{
        Key = 0;
		PasswordWindow->Button1Click(Button1);
	}
}
//---------------------------------------------------------------------------


