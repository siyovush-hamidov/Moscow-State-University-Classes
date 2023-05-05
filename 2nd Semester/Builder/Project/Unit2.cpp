//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}

String ClientName1,PhoneNumber1,HomeAddress1;

void __fastcall TForm2::Button1Click(TObject *Sender)
{
	Q1->Close();
   Q1->SQL->Clear();
   Q1->SQL->Add("INSERT INTO t_Clnt(ClientName,HomeAddress,PhoneNumber) VALUES('"+Edit1->Text+"','"+Edit2->Text+"',"+Edit3->Text+")");
   Q1->ExecSQL();
   Edit1->Clear();
   Edit2->Clear();
   Edit3->Clear();

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	ClientName1 = Edit1->Text;
	PhoneNumber1 = Edit2->Text;
	HomeAddress1 = Edit3->Text;
    Q1->Close();
   Q1->SQL->Clear();
   Q1->SQL->Add("UPDATE t_Clnt SET ClientName='"+Edit1->Text+"', HomeAddress='"+Edit3->Text+"', PhoneNumber="+Edit2->Text+" WHERE (ClientName='"+ClientName1+"') OR (PhoneNumber="+PhoneNumber1+") OR (HomeAddress='"+HomeAddress1+"')");
   Q1->ExecSQL();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
    ClientName1 = Edit1->Text;
	PhoneNumber1 = Edit2->Text;
	HomeAddress1 = Edit3->Text;

	  Q1->Close();
	  Q1->SQL->Clear();
	  Q1->SQL->Add("DELETE FROM t_Clnt WHERE (ClientName='"+ClientName1+"') OR (PhoneNumber="+PhoneNumber1+") OR (HomeAddress='"+HomeAddress1+"')");
      Q1->ExecSQL();
}
//---------------------------------------------------------------------------
