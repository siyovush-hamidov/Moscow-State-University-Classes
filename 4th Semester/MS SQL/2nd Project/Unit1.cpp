//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
	if(RadioButton1->Checked == True)
	{
		Panel1->Visible = True;
		Panel2->Visible = False;
	}
	else
	{
        ListBox1->Clear();
		Panel2->Visible = True;
		Panel1->Visible = False;

		ADOQuery1->Open();
		ADOQuery1->First();

		for(int i = 0; i < ADOQuery1->RecordCount; i++)
		{
			ListBox1->Items->Add(ADOQuery1->FieldByName("name")->AsString);
            ComboBox1->Items->Add(ADOQuery1->FieldByName("name")->AsString);
            ADOQuery1->Next();
		}

    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
	double StockWidth = 765; double StockHeight = 462;
	double WCoef = double(double(Form1->Width) / double(StockWidth));
	double HCoef = double(double(Form1->Height)/ double(StockHeight));

	RadioButton1->Width = 100 * WCoef;
	RadioButton1->Height = 35 * HCoef;
    RadioButton1->Font->Size = Panel1->Font->Size;
	RadioButton2->Width = RadioButton1->Width;
	RadioButton2->Height = RadioButton1->Height;
	RadioButton2->Left = RadioButton1->Width + 16;
	RadioButton2->Font->Size = Panel1->Font->Size;


	Panel1->Width = WCoef * 224;
	Panel1->Height = HCoef * 365;
	Panel1->Top = RadioButton1->Height + 16;
    Panel1->Font->Size = 10 + (10 * ((WCoef - 1) / 2 + (HCoef - 1) / 2));
	Panel2->Width = Panel1->Width;
	Panel2->Height = Panel1->Height;
	Panel2->Top = Panel1->Top;
    Panel2->Font->Size = Panel1->Font->Size;
	Panel3->Width = WCoef * 505;
	Panel3->Height = Panel1->Height;
	Panel3->Left = Panel1->Width + 16;
    Panel3->Font->Size = Panel1->Font->Size;
	Panel3->Top = Panel1->Top;
	Panel4->Width = Panel3->Width;
	Panel4->Height = HCoef * 35;
    Panel4->Left = Panel3->Left;

    DriveComboBox1->Height = HCoef * 21;
	DirectoryListBox1->Width = WCoef * 125;
	DirectoryListBox1->Height = HCoef * 318;
    DirectoryListBox1->Top = DriveComboBox1->Height + 16;
	FileListBox1->Width = WCoef * 75;
	FileListBox1->Height = DirectoryListBox1->Height;
	FileListBox1->Left = DirectoryListBox1->Width + 16;
	FileListBox1->Top = DirectoryListBox1->Top;
    DriveComboBox1->Width = DirectoryListBox1->Width + FileListBox1->Width + 8;

	Memo1->Width = 490 * WCoef;
	Memo1->Height = 170 * HCoef;
	Memo2->Width = Memo1->Width;
	Memo2->Height = Memo1->Height;
    Memo2->Top = Memo1->Height + 16;
	DBGrid1->Width = Memo1->Width;
	DBGrid1->Height = Memo1->Height;
	DBGrid1->Top = Memo2->Top;

	ListBox1->Width = WCoef * 100;
	ListBox1->Height = Memo1->Height + Memo2->Height + 8;
	ListBox1->Top = Memo1->Top;
	ListBox2->Width = ListBox1->Width;
	ListBox2->Height = ListBox1->Height;
	ListBox2->Left = 16 + ListBox1->Width;
	ListBox2->Top = ListBox1->Top;
}
//---------------------------------------------------------------------------





