//---------------------------------------------------------------------------

#include <vcl.h>
#include "Unit1.h"
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
    if(Key == 13)
	{
		Form1->ADOQuery1->Active = False;

		if(ComboBox1->ItemIndex == 0)
		{
			Form1->ADOQuery1->SQL->Add(" and Population = '"+Edit1->Text+"'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 1)
		{
			Form1->ADOQuery1->SQL->Add(" and Population != '"+Edit1->Text+"'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 2)
		{
			Form1->ADOQuery1->SQL->Add(" and Population > '"+Edit1->Text+"'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 3)
		{
			Form1->ADOQuery1->SQL->Add(" and Population >= '"+Edit1->Text+"'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 4)
		{
			Form1->ADOQuery1->SQL->Add(" and Population < '"+Edit1->Text+"'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 5)
		{
			Form1->ADOQuery1->SQL->Add(" and Population <= '"+Edit1->Text+"'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 6)
		{
			Form1->ADOQuery1->SQL->Add(" and Population BETWEEN '"+Edit1->Text+"' AND '"+Edit2->Text+"'");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 7)
		{
			Form1->ADOQuery1->SQL->Add(" and Population > (select AVG(Population) from First_Project) order by Population desc");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 8)
		{
			Form1->ADOQuery1->SQL->Add(" and Population < (select AVG(Population) from First_Project) order by Population desc");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 9)
		{
            Form1->ADOQuery1->SQL->Clear();
			Form1->ADOQuery1->SQL->Add("SELECT TOP 10 ID, Country, Capital, Population from First_Project order by Population desc");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 10)
		{
			Form1->ADOQuery1->SQL->Add(" order by Population desc");
			Form1->ADOQuery1->ExecSQL();
		}
		if(ComboBox1->ItemIndex == 11)
		{
			Form1->ADOQuery1->SQL->Add(" order by Population asc");
			Form1->ADOQuery1->ExecSQL();
		}

		Form1->ADOQuery1->Active = True;

		Form4->Visible = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ComboBox1Select(TObject *Sender)
{
	if(ComboBox1->ItemIndex == 6)
	{
        Edit2->Visible = True;
    }
}
//---------------------------------------------------------------------------

