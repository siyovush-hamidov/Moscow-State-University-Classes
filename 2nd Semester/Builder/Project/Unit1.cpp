//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
String DeviceName1,Price1,DGPU1,Quantity1;

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   Q1->Close();
   Q1->SQL->Clear();
   Q1->SQL->Add("INSERT INTO t_Prod(DeviceName,Price,DGPU,Quantity) VALUES('"+Edit1->Text+"',"+Edit2->Text+",'"+Edit3->Text+"',"+Edit4->Text+")");
   Q1->ExecSQL();
   Edit1->Clear();
   Edit2->Clear();
   Edit3->Clear();
   Edit4->Clear();
   	  DBGrid1->DataSource = DataSource1;
	  DataSource1->DataSet = Q1;
	  DBNavigator1->DataSource=DataSource1;
      DataSource1->Enabled=True;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   DeviceName1=Edit1->Text;
   Price1=Edit2->Text;
   DGPU1=Edit3->Text;
   Quantity1=Edit4->Text;
   Q1->Close();
   Q1->SQL->Clear();
   Q1->SQL->Add("UPDATE t_Prod SET DeviceName='"+Edit1->Text+"', Price="+Edit2->Text+", DGPU='"+Edit3->Text+"', Quantity="+Edit4->Text+" WHERE (DeviceName='"+DeviceName1+"') OR (Price="+Price1+") OR (DGPU='"+DGPU1+"') OR (Quantity="+Quantity1+")");
   Q1->ExecSQL();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
   DeviceName1=Edit1->Text;
   Price1=Edit2->Text;
   DGPU1=Edit3->Text;
   Quantity1=Edit4->Text;
	  Q1->Close();
	  Q1->SQL->Clear();
	  Q1->SQL->Add("DELETE FROM t_Prod WHERE (DeviceName='"+DeviceName1+"') OR (Price="+Price1+") OR (DGPU='"+DGPU1+"') OR (Quantity="+Quantity1+")");
	  Q1->ExecSQL();
	  Q1->SQL->Add("SELECT * FROM t_Prod");



}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientsPageActionExecute(TObject *Sender)
{
	Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SalesPageActionExecute(TObject *Sender)
{
	 Form3->Show();
}
//---------------------------------------------------------------------------
