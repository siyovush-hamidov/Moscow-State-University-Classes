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
	void __fastcall TForm1::SaveExecute(TObject *Sender)
	{
	   if(SaveDialog1->Execute())
        Memo1 -> Lines -> SaveToFile(SaveDialog1->FileName);
    }

//---------------------------------------------------------------------------
void __fastcall TForm1::CloseExecute(TObject *Sender)
{
    Memo1->Clear();
}
//---------------------------------------------------------------------------




void __fastcall TForm1::OpenExecute(TObject *Sender)
{
    if(OpenDialog1->Execute())
		 Memo1 -> Lines -> LoadFromFile(OpenDialog1->FileName);
}

void __fastcall TForm1::FontExecute(TObject *Sender)
{
	if(FontDialog1->Execute())
		 Memo1 -> Font = FontDialog1->Font;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NewExecute(TObject *Sender)
{
//	SaveDialog1->Execute();
//	  Memo1 -> Lines -> SaveToFile(SaveDialog1->FileName);
      Memo1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ApplicationEvents1Idle(TObject *Sender, bool &Done)
{
     String s = Memo1->Text;
   int n = s.Length(), sen = 0;
   for (int i = 1; i <= n; i++)
   {
   if(s[i] == '.' || s[i] == '?' || s[i] == '!' || s[i] == ';') sen++;
   }
   StatusBar1 -> Panels -> Items[0] -> Text = "Предложений: " + IntToStr(sen);

   ////
   int words = 0;
   bool t = (n != 0);
   for (int i = 1; i < n; i++)
   {
   if(s[i] == ' ' && s[i - 1] != ' ' && s[i + 1] != ' ') words ++;
   }
   StatusBar1 -> Panels -> Items[1] -> Text = "Слов: " + IntToStr(words + t);
   int symb = 0;
   for(int i = 1; i <= n; i++)
   {
	 if(s[i] != ' ' && s[i]!= '\r\n') symb++;
   }
   StatusBar1 -> Panels -> Items[2] -> Text = "Символов: " + IntToStr(symb);

}
//---------------------------------------------------------------------------

