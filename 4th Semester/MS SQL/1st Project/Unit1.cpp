//---------------------------------------------------------------------------

#include <vcl.h>

#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"

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

void ClearEdits()
{
	Form1->Edit1->Text = "";
	Form1->Edit2->Text = "";
	Form1->Edit3->Text = "";
	Form1->Edit4->Text = "";
	Form1->Edit5->Text = "";
	Form1->Edit6->Text = "";
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	//ADD

	ADOQuery1->Active = False;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("insert into First_Project(Country, Capital, Population) values('"+Edit1->Text+"', '"+Edit2->Text+"', '"+Edit3->Text+"')");
	ADOQuery1->ExecSQL();

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from First_Project where ID = ID");
	ADOQuery1->ExecSQL();
	ADOQuery1->Active = True;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	//DELETE

	ADOQuery1->Active = False;
	ADOQuery1->SQL->Clear();
    ADOQuery1->SQL->Add("delete from First_Project where Country = '"+Edit1->Text+"' or Capital = '"+Edit2->Text+"' or Population = '"+Edit3->Text+"' ");
	ADOQuery1->ExecSQL();

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from First_Project where ID = ID");
	ADOQuery1->ExecSQL();
	ADOQuery1->Active = True;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	//CHANGE

    ADOQuery1->Active = False;

	if(Edit6->Text.Length() != 0)
	{
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("update First_Project set Population = '"+Edit6->Text+"' where Country = '"+Edit1->Text+"' or Capital = '"+Edit2->Text+"' or Population = '"+Edit3->Text+"'");
		ADOQuery1->ExecSQL();
	}

	if(Edit5->Text.Length() != 0)
	{
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("update First_Project set Capital = '"+Edit5->Text+"' where Country = '"+Edit1->Text+"' or Capital = '"+Edit2->Text+"' or Population = '"+Edit3->Text+"'");
		ADOQuery1->ExecSQL();
	}

	if(Edit4->Text.Length() != 0)
	{
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("update First_Project set Country = '"+Edit4->Text+"' where Country = '"+Edit1->Text+"' or Capital = '"+Edit2->Text+"' or Population = '"+Edit3->Text+"'");
		ADOQuery1->ExecSQL();
	}

	ADOQuery1->SQL->Add("select * from First_Project where ID = ID");
	ADOQuery1->Active = True;

	ClearEdits();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	//SEARCH

	ADOQuery1->Active = False;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from First_Project where Country = '"+Edit1->Text+"' or Capital = '"+Edit2->Text+"' or Population = '"+Edit3->Text+"'");
	ADOQuery1->ExecSQL();
	ADOQuery1->Active = True;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	//REFRESH

	ADOQuery1->Active = False;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from First_Project where ID = ID");
	ADOQuery1->ExecSQL();
	ADOQuery1->Active = True;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Form2->Visible = True;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
    Form3->Visible = True;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	Form4->Visible = True;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormResize(TObject *Sender)
{
	double FWidth = 885;
	double FHeight = 567;

	double WCoef = double(double(Form1->Width) / double(FWidth));
	double HCoef = double(double(Form1->Height)/ double(FHeight));

	Button1->Width = 175 * WCoef;
	Button3->Width = 175 * WCoef;
	Button4->Width = 175 * WCoef;
	Button5->Width = 175 * WCoef;
	Button6->Width = 175 * WCoef;

    Button1->Height = 30 * HCoef;
	Button3->Height = 30 * HCoef;
	Button4->Height = 30 * HCoef;
	Button5->Height = 30 * HCoef;
	Button6->Height = 30 * HCoef;

	Edit1->Width = 175 * WCoef;
	Edit2->Width = 175 * WCoef;
	Edit3->Width = 175 * WCoef;
	Edit4->Width = 175 * WCoef;
	Edit5->Width = 175 * WCoef;
	Edit6->Width = 175 * WCoef;

	Edit1->Height = 30 * HCoef;
	Edit2->Height = 30 * HCoef;
	Edit3->Height = 30 * HCoef;
	Edit4->Height = 30 * HCoef;
	Edit5->Height = 30 * HCoef;
	Edit6->Height = 30 * HCoef;

//	Label1->Width = 150 * WCoef;
//	Label2->Width = 150 * WCoef;
//	Label3->Width = 150 * WCoef;
	Label1->Height = 30 * WCoef;
	Label2->Height = 30 * WCoef;
	Label3->Height = 30 * WCoef;

	DBGrid1->Width = 856 * WCoef;
	DBGrid1->Height = 386 * HCoef;
	DBGrid1->Columns->Items[0]->Width = 50 * WCoef;
	DBGrid1->Columns->Items[1]->Width = 300 * WCoef;
	DBGrid1->Columns->Items[2]->Width = 300 * WCoef;
	DBGrid1->Columns->Items[3]->Width = 160 * WCoef;

	DBGrid1->Font->Size = 9 + int(WCoef * 10 - 10);

//	Button9->Width = 18 * WCoef;
//	Button10->Width = 18 * WCoef;
//	Button11->Width = 18 * WCoef;

//	Button9->Height = 34 * (HCoef);
//	Button10->Height = 34 * (HCoef);
//	Button11->Height = 34 * (HCoef);

	Edit2->Top = Edit1->Top + (30 * HCoef) + 6;
	Edit3->Top = Edit2->Top + (30 * HCoef) + 6;
	Edit5->Top = Edit4->Top + (30 * HCoef) + 6;
	Edit6->Top = Edit5->Top + (30 * HCoef) + 6;
	Label2->Top = Label1->Top + (30 * HCoef) + 6;
	Label3->Top = Label2->Top + (30 * HCoef) + 6;
	Button4->Top = Button3->Top + (30 * HCoef) + 6;
	Button5->Top = Button1->Top + (30 * HCoef) + 6;
	Button6->Top = Button5->Top + (30 * HCoef) + 6;

	DBGrid1->Top = Label3->Top + (30 * HCoef) + 25;

	Button9->Top = DBGrid1->Top;
	Button10->Top = DBGrid1->Top;
	Button11->Top = DBGrid1->Top;

	Label1->Font->Size = 15 + (10 * ((WCoef - 1) / 2 + (HCoef - 1) / 2));
	Label2->Font->Size = Label1->Font->Size;
	Label3->Font->Size = Label1->Font->Size;
	Edit1->Font->Size = Label1->Font->Size;
	Edit2->Font->Size = Label1->Font->Size;
	Edit3->Font->Size = Label1->Font->Size;
	Edit4->Font->Size = Label1->Font->Size;
	Edit5->Font->Size = Label1->Font->Size;
	Edit6->Font->Size = Label1->Font->Size;
	Button1->Font->Size = Label1->Font->Size;
	Button3->Font->Size = Label1->Font->Size;
	Button4->Font->Size = Label1->Font->Size;
	Button5->Font->Size = Label1->Font->Size;
	Button6->Font->Size = Label1->Font->Size;
//	DBGrid1->TitleFont->Size = Label1->Font->Size;
	DBGrid1->Font->Size = 9 + (10 * ((WCoef - 1) / 2 + (HCoef - 1) / 2));

	Edit1->Left = Label1->Left + 156;
	Edit2->Left = Label1->Left + 156;
	Edit3->Left = Label1->Left + 156;

	Edit4->Left = Edit1->Left + (175 * (WCoef)) + 6;
	Edit5->Left = Edit2->Left + (175 * (WCoef)) + 6;
	Edit6->Left = Edit3->Left + (175 * (WCoef)) + 6;

	Button1->Left = Edit4->Left + (175 * (WCoef)) + 4;
	Button5->Left = Edit5->Left + (175 * (WCoef)) + 4;
	Button6->Left = Edit6->Left + (175 * (WCoef)) + 4;
	Button3->Left = Button1->Left + (175 * (WCoef)) + 4;
	Button4->Left = Button5->Left + (175 * (WCoef)) + 4;

	Button9->Left = DBGrid1->Columns->Items[0]->Width + 16 - 20;
	Button10->Left = Button9->Left + DBGrid1->Columns->Items[1]->Width;
	Button11->Left = DBGrid1->Columns->Items[2]->Width + Button10->Left;

//	Button9->Left = WCoef * 45;
//	Button9->Top = HCoef * 132;
//	Button10->Left = WCoef * 342;
//	Button10->Top = HCoef * 132;
//	Button11->Left = WCoef * 640;
//	Button11->Top = HCoef * 132;


}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
//    Button2->BringToFront();
}
//---------------------------------------------------------------------------



