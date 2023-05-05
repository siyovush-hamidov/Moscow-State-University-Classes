//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
#include <fstream.h>
#include <cstring>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

String n, DeviceName1;
int k, m;
void __fastcall TForm3::FormCreate(TObject *Sender)
{

	Q2->SQL->Clear();
	Q2->SQL->Add("SELECT * FROM t_Clnt");
    Q2->Open();
    ComboBox1->Clear();
	for(Q2->First(); !Q2->Eof; Q2->Next()){
	   ComboBox1->Items->Add(Q2->FieldByName("ClientName")->AsString);
	}

	Q3->SQL->Clear();
	Q3->SQL->Add("SELECT * FROM t_Prod");
	Q3->Open();
	ComboBox2->Clear();
	for(Q3->First(); !Q3->Eof; Q3->Next())
	   ComboBox2->Items->Add(Q3->FieldByName("DeviceName")->AsString);

	ComboBox4->Items->LoadFromFile("goroda.txt");
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
    Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
    Form1->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ComboBox2Select(TObject *Sender)
{
    Q4->Close();
	Q4->SQL->Clear();
	Q4->SQL->Add("SELECT * From t_Prod WHERE DeviceName='"+ComboBox2->Text+"'");
	Q4->Open();
	Q4->First();
	ComboBox3->Clear();
	ComboBox3->Items->Clear();
	int i,n=StrToInt(Q4->FieldByName("Quantity")->Text);
	for (int i=1;i<=n;i++)
		ComboBox3->Items->Add(i);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ComboBox3Select(TObject *Sender)
{
	Q4->Close();
	Q4->SQL->Clear();
	Q4->SQL->Add("SELECT * From t_Prod WHERE DeviceName='"+ComboBox2->Text+"'");
    Q4->Open();
	Q4->First();
	Edit1->Clear();
	int i,n=StrToInt(Q4->FieldByName("Price")->Text);
    i = StrToInt(ComboBox3->Text);
	Edit1->Text = IntToStr(n * i);
    Edit2->Text = IntToStr(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm3::CheckBox1Click(TObject *Sender)
{
	if(CheckBox1->Checked){
	Edit2->Text = IntToStr(StrToInt(Edit1->Text) + 20);
	RadioButton1->Enabled = True;
    RadioButton1->Checked = True;
	RadioButton2->Enabled = True;
	}
	else{
	Edit2->Text = IntToStr(StrToInt(Edit1->Text));
	RadioButton1->Enabled = False;
	RadioButton2->Enabled = False;
	RadioButton1->Checked = False;
    RadioButton2->Checked = False;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::RadioButton2Click(TObject *Sender)
{
   if(RadioButton2->Checked){
	   Edit2->Text = IntToStr(StrToInt(Edit1->Text) + 50);
	}
	else{
		Edit2->Text = IntToStr(StrToInt(Edit1->Text) + 20);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::RadioButton1Click(TObject *Sender)
{
     if(RadioButton1->Checked){
	   Edit2->Text = IntToStr(StrToInt(Edit1->Text) + 20);
	}
	else{
		Edit2->Text = IntToStr(StrToInt(Edit1->Text) + 50);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button4Click(TObject *Sender)
{
   String date, clientname, devicename, city;
   double quantity, overall, totalsum, delivery;

  date = DateToStr(DateTimePicker1->Date);
  clientname = ComboBox1->Text;
  devicename = ComboBox2->Text;
  city = ComboBox4->Text;

  quantity = StrToFloat(ComboBox3->Text);
  overall = StrToFloat(Edit1->Text);
  totalsum = StrToFloat(Edit2->Text);

  if(CheckBox1->Checked){
  delivery = 1;
  }
  else{
	  delivery = 0;
  }

   Q5->Close();
   Q5->SQL->Clear();
   Q5->SQL->Add("INSERT INTO t_Sell(SaleDate,ClientName,DeviceName,Quantity,Overall,Delivery,TotalSum,City) VALUES('"+date+"','"+clientname+"','"+devicename+"',"+quantity+","+overall+","+delivery+","+totalsum+",'"+city+"')");
   Q5->ExecSQL();
}
//---------------------------------------------------------------------------

