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
		ADOConnection1->Open();
		ADOQuery1->Open();
		ADOQuery1->First();

		for(int i = 0; i < ADOQuery1->RecordCount; i++)
		{
			ListBox1->Items->Add(ADOQuery1->FieldByName("name")->AsString);
            ADOQuery1->Next();
		}

    }
}
//---------------------------------------------------------------------------
