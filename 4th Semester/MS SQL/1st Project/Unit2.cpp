//---------------------------------------------------------------------------

#include <vcl.h>
#include "Unit1.h"
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
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
	if(Key == 13)
	{
		Form1->ADOQuery1->Active = False;
		if(ComboBox1->ItemIndex == 0)
		{
			Form1->ADOQuery1->SQL->Add(" and Country LIKE '"+Edit1->Text+"'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 1)
		{
			Form1->ADOQuery1->SQL->Add(" and Country NOT LIKE '"+Edit1->Text+"'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 2)
		{
			Form1->ADOQuery1->SQL->Add(" and Country LIKE '"+Edit1->Text+"%'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 3)
		{
			Form1->ADOQuery1->SQL->Add(" and Country LIKE '%"+Edit1->Text+"'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 4)
		{
			Form1->ADOQuery1->SQL->Add(" and Country LIKE '%"+Edit1->Text+"%'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 5)
		{
			Form1->ADOQuery1->SQL->Add(" and Country NOT LIKE '%"+Edit1->Text+"%'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 6)
		{
			Form1->ADOQuery1->SQL->Add(" order by Country desc");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 7)
		{
			Form1->ADOQuery1->SQL->Add(" order by Country asc");
			Form1->ADOQuery1->ExecSQL();
		}
		Form1->ADOQuery1->Active = True;
		Form2->Visible = false;
	}
}
//---------------------------------------------------------------------------

