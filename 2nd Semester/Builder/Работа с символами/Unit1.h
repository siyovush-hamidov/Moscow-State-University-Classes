//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Menus.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.AppEvnts.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TMainMenu *MainMenu1;
	TButton *Button2;
	TButton *Button1;
	TButton *Button3;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TFontDialog *FontDialog1;
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	TMenuItem *Edit1;
	TMenuItem *Open1;
	TMenuItem *Save1;
	TMenuItem *Font1;
	TMenuItem *Clear1;
	TMenuItem *Font2;
	TMenuItem *Clear2;
	TActionList *ActionList1;
	TAction *OpenAction;
	TAction *SaveAction;
	TAction *FontAction;
	TAction *ClearAction;
	TButton *Button4;
	TAction *NewAction;
	TStatusBar *StatusBar1;
	TApplicationEvents *ApplicationEvents1;
	TAction *SearchAction;
	TButton *Button5;
	TButton *Button6;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TAction *Action1;
	TAction *Action2;
	TListBox *ListBox1;
	TListBox *ListBox2;
	TListBox *ListBox3;
	TListBox *ListBox4;
	TListBox *ListBox5;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
