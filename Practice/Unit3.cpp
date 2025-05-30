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
	ADOQuery1->SQL->Add("SELECT StudId FROM Students WHERE Surname COLLATE Cyrillic_General_CI_AI = '"+Edit1->Text+"' AND Name COLLATE Cyrillic_General_CI_AI = '"+Edit2->Text+"' AND [Middle Name] COLLATE Cyrillic_General_CI_AI = '"+Edit3->Text+"' UNION ALL SELECT TeacherId FROM Teachers WHERE Surname COLLATE Cyrillic_General_CI_AI = '"+Edit1->Text+"' AND Name COLLATE Cyrillic_General_CI_AI = '"+Edit2->Text+"' AND [Middle Name] COLLATE Cyrillic_General_CI_AI = '"+Edit3->Text+"' UNION ALL SELECT EmployeeId FROM Employees WHERE Surname COLLATE Cyrillic_General_CI_AI = '"+Edit1->Text+"' AND Name COLLATE Cyrillic_General_CI_AI = '"+Edit2->Text+"' AND [Middle Name] COLLATE Cyrillic_General_CI_AI = '"+Edit3->Text+"'");
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
			ADOQuery1->SQL->Add("SELECT RegId FROM Students WHERE Surname = '"+Edit1->Text+"' AND Name = '"+Edit2->Text+"' AND [Middle Name] = '"+Edit3->Text+"' AND (RegId IS NOT NULL OR RegId < 2147483647) UNION ALL SELECT RegId FROM Teachers WHERE Surname = '"+Edit1->Text+"' AND Name = '"+Edit2->Text+"' AND [Middle Name] = '"+Edit3->Text+"' AND (RegId IS NOT NULL OR RegId < 2147483647) UNION ALL SELECT RegId FROM Employees WHERE Surname = '"+Edit1->Text+"' AND Name = '"+Edit2->Text+"' AND [Middle Name] = '"+Edit3->Text+"' AND (RegId IS NOT NULL OR RegId < 2147483647)");
			ADOQuery1->Open();
			if(ADOQuery1->RecordCount != 0)
			{
				MessageDlg("����� �� ���� ��� ��� ����������!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
			}
			else
			{
				ADOQuery1->SQL->Clear();
				ADOQuery1->SQL->Add("SELECT RegId from Register WHERE Login COLLATE SQL_Latin1_General_CP1_CS_AS = '"+Edit4->Text+"'");
				ADOQuery1->Open();
				if(ADOQuery1->RecordCount == 1)
				{
					MessageDlg("����� � ����� ������ ��� ����������!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
				}
				else
				{

                    AnsiString role;
					ADOQuery1->SQL->Clear();
					ADOQuery1->SQL->Add("SELECT COUNT(*) FROM Students WHERE Surname = :surname AND Name = :name AND [Middle Name] = :middleName");
					ADOQuery1->Parameters->ParamByName("surname")->Value = Edit1->Text;
					ADOQuery1->Parameters->ParamByName("name")->Value = Edit2->Text;
					ADOQuery1->Parameters->ParamByName("middleName")->Value = Edit3->Text;
					ADOQuery1->Open();
					if (ADOQuery1->Fields->Fields[0]->AsInteger > 0)
					{
						role = "1";
					}

                    ADOQuery1->SQL->Clear();
					ADOQuery1->SQL->Add("SELECT COUNT(*) FROM Teachers WHERE Surname = :surname AND Name = :name AND [Middle Name] = :middleName");
					ADOQuery1->Parameters->ParamByName("surname")->Value = Edit1->Text;
					ADOQuery1->Parameters->ParamByName("name")->Value = Edit2->Text;
					ADOQuery1->Parameters->ParamByName("middleName")->Value = Edit3->Text;
					ADOQuery1->Open();
					if (ADOQuery1->Fields->Fields[0]->AsInteger > 0) role = "2";

                    ADOQuery1->SQL->Clear();
					ADOQuery1->SQL->Add("SELECT COUNT(*) FROM Employees WHERE Surname = :surname AND Name = :name AND [Middle Name] = :middleName");
					ADOQuery1->Parameters->ParamByName("surname")->Value = Edit1->Text;
					ADOQuery1->Parameters->ParamByName("name")->Value = Edit2->Text;
					ADOQuery1->Parameters->ParamByName("middleName")->Value = Edit3->Text;
                    ADOQuery1->Open();
					if (ADOQuery1->Fields->Fields[0]->AsInteger > 0) role = "3";

					ADOQuery1->SQL->Clear();
					ADOQuery1->SQL->Add("INSERT INTO Register(Login, Password, Role) VALUES('"+Edit4->Text+"', '"+THashMD5::GetHashString(Edit5->Text)+"', '"+role+"')");
					ADOQuery1->ExecSQL();

//					ADOQuery1->SQL->Clear();
//					ADOQuery1->SQL->Add("UPDATE R SET R.RegId = T.RegId FROM Register AS R JOIN (SELECT RegId FROM Students WHERE Surname = :surname AND Name = :name AND [Middle Name] = :middleName UNION ALL SELECT RegId FROM Teachers WHERE Surname = :surname AND Name = :name AND [Middle Name] = :middleName UNION ALL SELECT RegId FROM Employees WHERE Surname = :surname AND Name = :name AND [Middle Name] = :middleName) AS T ON R.Login = :login");
//                    ADOQuery1->Prepared = true;
//					ADOQuery1->Parameters->ParamByName("surname")->Value = Edit1->Text;
//					ADOQuery1->Parameters->ParamByName("name")->Value = Edit2->Text;
//					ADOQuery1->Parameters->ParamByName("middleName")->Value = Edit3->Text;
//					ADOQuery1->Parameters->ParamByName("login")->Value = Edit4->Text;
//					ADOQuery1->ExecSQL();


					MessageDlg("�� ������� ������������������!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
					StudentRegistration->Visible = False;
					LoginWindow->Visible = True;
				}
			}
		}
		else
		{
			MessageDlg("������ �� ���������!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
			Edit5->Clear(); Edit6->Clear();
		}
	}
	else
	{
        MessageDlg("����� �������� ������������ �������! ����������� ���������� �����, ����� � ����� ����������.", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
    }

}
//---------------------------------------------------------------------------

