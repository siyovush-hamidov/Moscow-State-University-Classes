//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStudentRegistration *StudentRegistration;
//---------------------------------------------------------------------------
__fastcall TStudentRegistration::TStudentRegistration(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TStudentRegistration::VirtualImage3Click(TObject *Sender)
{
    StudentRegistration->Visible = False; LoginWindow->Visible = true;
}
//---------------------------------------------------------------------------

bool ContainsInvalidChars(AnsiString S)
{
  for (int i = 1; i <= S.Length(); i++)
  {
	  if( ((S[i] <= ' ' && S[i] >= 'z')) || ((S[i] >= '"' && S[i] <= '+')) || ((S[i] >= '<' && S[i] <= '@')) )
	  {
		  return false;
	  }
  }
  return true;
}

void __fastcall TStudentRegistration::Edit1Change(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT * FROM Students WHERE Surname COLLATE Cyrillic_General_CI_AI = '"+Edit1->Text+"' AND Name COLLATE Cyrillic_General_CI_AI = '"+Edit2->Text+"' AND MiddleName COLLATE Cyrillic_General_CI_AI = '"+Edit3->Text+"' UNION ALL SELECT * FROM Teachers WHERE Surname COLLATE Cyrillic_General_CI_AI = '"+Edit1->Text+"' AND Name COLLATE Cyrillic_General_CI_AI = '"+Edit2->Text+"' AND MiddleName COLLATE Cyrillic_General_CI_AI = '"+Edit3->Text+"' UNION ALL SELECT * FROM Employees WHERE Surname COLLATE Cyrillic_General_CI_AI = '"+Edit1->Text+"' AND Name COLLATE Cyrillic_General_CI_AI = '"+Edit2->Text+"' AND MiddleName COLLATE Cyrillic_General_CI_AI = '"+Edit3->Text+"'");
	ADOQuery1->Open();

	if(ADOQuery1->RecordCount == 1)
	{
		VirtualImage4->Visible = True;
		Button1->Enabled = true;
		Edit4->Enabled = true;
		Edit5->Enabled = true;
		Edit6->Enabled = true;
	}
	else
	{
		VirtualImage4->Visible = False;
		Button1->Enabled = false;
		Edit4->Enabled = false;
		Edit5->Enabled = false;
		Edit6->Enabled = false;
	}
}
//---------------------------------------------------------------------------



void __fastcall TStudentRegistration::Button1Click(TObject *Sender)
{
	if(ContainsInvalidChars(Edit4->Text))
	{
        if(Edit5->Text == Edit6->Text && Edit5->Text != "" && Edit6->Text != "")
		{

			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("SELECT * FROM Students WHERE Surname = '"+Edit1->Text+"' AND Name = '"+Edit2->Text+"' AND MiddleName = '"+Edit3->Text+"' AND (RegId IS NOT NULL OR RegId < 2147483647) UNION ALL SELECT * FROM Teachers WHERE Surname = '"+Edit1->Text+"' AND Name = '"+Edit2->Text+"' AND MiddleName = '"+Edit3->Text+"' AND (RegId IS NOT NULL OR RegId < 2147483647) UNION ALL SELECT * FROM Employees WHERE Surname = '"+Edit1->Text+"' AND Name = '"+Edit2->Text+"' AND MiddleName = '"+Edit3->Text+"' AND (RegId IS NOT NULL OR RegId < 2147483647)");
			ADOQuery1->Open();
			if(ADOQuery1->RecordCount != 0)
			{
				MessageDlg("Логин на ваше имя уже существует!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
			}
			else
			{
				ADOQuery1->SQL->Clear();
				ADOQuery1->SQL->Add("SELECT * from Register WHERE Login COLLATE SQL_Latin1_General_CP1_CS_AS = '"+Edit4->Text+"'");
				ADOQuery1->Open();
				if(ADOQuery1->RecordCount == 1)
				{
					MessageDlg("Логин с таким именем уже существует!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
				}
				else
				{
					ADOQuery1->SQL->Clear();
					ADOQuery1->SQL->Add("INSERT INTO Register(Login, Password, Role) VALUES('"+Edit4->Text+"', '"+THashMD5::GetHashString(Edit5->Text)+"', (SELECT MAX(Role) FROM (SELECT Role FROM Students WHERE Surname = '"+Edit1->Text+"' AND Name = '"+Edit2->Text+"' AND MiddleName = '"+Edit3->Text+"' UNION SELECT Role FROM Teachers WHERE Surname = '"+Edit1->Text+"' AND Name = '"+Edit2->Text+"' AND MiddleName = '"+Edit3->Text+"' UNION SELECT Role FROM Employees WHERE Surname = '"+Edit1->Text+"' AND Name = '"+Edit2->Text+"' AND MiddleName = '"+Edit3->Text+"') AS T))");
					ADOQuery1->ExecSQL();

					ADOQuery1->SQL->Clear();
					ADOQuery1->SQL->Add("UPDATE T SET RegId = R.RegId FROM (SELECT * FROM Students WHERE Surname = '"+Edit1->Text+"' AND Name = '"+Edit2->Text+"' AND MiddleName = '"+Edit3->Text+"' UNION ALL SELECT * FROM Teachers WHERE Surname = '"+Edit1->Text+"' AND Name = '"+Edit2->Text+"' AND MiddleName = '"+Edit3->Text+"' UNION ALL SELECT * FROM Employees WHERE Surname = '"+Edit1->Text+"' AND Name = '"+Edit2->Text+"' AND MiddleName = '"+Edit3->Text+"') AS T JOIN Register AS R ON R.Login = '"+Edit4->Text+"'");
					ADOQuery1->ExecSQL();

					MessageDlg("Вы успешно зарегистрировались!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
					StudentRegistration->Visible = False;
					LoginWindow->Visible = True;
				}
			}
		}
		else
		{
			MessageDlg("Пароли не совпадают!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
			Edit5->Clear(); Edit6->Clear();
		}
	}
	else
	{
        MessageDlg("Логин содержит недопустимые символы! Допускаются английские буквы, цифры и знаки препинания.", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
    }

}
//---------------------------------------------------------------------------

