//---------------------------------------------------------------------------

#include <vcl.h>
#include "Unit1.h"
#pragma hdrstop

#include "Unit3.h"
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

//---------------------------------------------------------------------------
void __fastcall TForm3::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
    if(Key == 13)
	{
		Form1->ADOQuery1->Active = False;
		if(ComboBox1->ItemIndex == 0)
		{
			Form1->ADOQuery1->SQL->Add(" and Capital LIKE '"+Edit1->Text+"'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 1)
		{
			Form1->ADOQuery1->SQL->Add(" and Capital NOT LIKE '"+Edit1->Text+"'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 2)
		{
			Form1->ADOQuery1->SQL->Add(" and Capital LIKE '"+Edit1->Text+"%'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 3)
		{
			Form1->ADOQuery1->SQL->Add(" and Capital LIKE '%"+Edit1->Text+"'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 4)
		{
			Form1->ADOQuery1->SQL->Add(" and Capital LIKE '%"+Edit1->Text+"%'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 5)
		{
			Form1->ADOQuery1->SQL->Add(" and Capital NOT LIKE '%"+Edit1->Text+"%'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 6)
		{
			Form1->ADOQuery1->SQL->Add(" order by Capital desc");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 7)
		{
			Form1->ADOQuery1->SQL->Add(" order by Capital asc");
			Form1->ADOQuery1->ExecSQL();
		}
		Form1->ADOQuery1->Active = True;
		Form3->Visible = false;
	}
}
//---------------------------------------------------------------------------
