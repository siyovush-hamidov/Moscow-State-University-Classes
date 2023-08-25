//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.VirtualImage.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <System.hpp>
#include <Vcl.AppEvnts.hpp>
#include <Vcl.WinXPickers.hpp>
//---------------------------------------------------------------------------
class TStaffWindow : public TForm
{
__published:	// IDE-managed Components
	TVirtualImage *VirtualImage1;
	TPanel *LessonConstructor;
	TButton *Button1;
	TButton *Button3;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TComboBox *ComboBox3;
	TComboBox *ComboBox4;
	TComboBox *ComboBox5;
	TComboBox *ComboBox6;
	TComboBox *ComboBox7;
	TADOQuery *ADOQuery1;
	TComboBox *ComboBox8;
	TDateTimePicker *DateTimePicker1;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TVirtualImage *VirtualImage12;
	TVirtualImage *VirtualImage5;
	TLabel *Label13;
	TVirtualImage *VirtualImage4;
	TVirtualImage *VirtualImage3;
	TLabel *Label1;
	TVirtualImage *VirtualImage6;
	TPanel *LessonEditor;
	TLabel *Label3;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TButton *Button2;
	TComboBox *ComboBox17;
	TDateTimePicker *DateTimePicker2;
	TComboBox *ComboBox10;
	TComboBox *ComboBox11;
	TComboBox *ComboBox12;
	TComboBox *ComboBox13;
	TComboBox *ComboBox14;
	TComboBox *ComboBox15;
	TComboBox *ComboBox16;
	TButton *Button4;
	TVirtualImage *VirtualImage2;
	TLabel *Label2;
	TDateTimePicker *DateTimePicker3;
	TComboBox *ComboBox9;
	TLabel *Label22;
	TLabel *Label23;
	TComboBox *ComboBox18;
	TLabel *Label24;
	TComboBox *ComboBox19;
	TLabel *Label25;
	TComboBox *ComboBox20;
	void __fastcall ComboBox1DropDown(TObject *Sender);
	void __fastcall ComboBox2DropDown(TObject *Sender);
	void __fastcall ComboBox5DropDown(TObject *Sender);
	void __fastcall ComboBox6DropDown(TObject *Sender);
	void __fastcall ComboBox7DropDown(TObject *Sender);
	void __fastcall ComboBox6Select(TObject *Sender);
	void __fastcall ComboBox3DropDown(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DateTimePicker1Change(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Label13Click(TObject *Sender);
	void __fastcall Label13MouseEnter(TObject *Sender);
	void __fastcall Label13MouseLeave(TObject *Sender);
	void __fastcall Label1Click(TObject *Sender);
	void __fastcall ComboBox10DropDown(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ComboBox10Select(TObject *Sender);
	void __fastcall ComboBox13Select(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall ComboBox18DropDown(TObject *Sender);
	void __fastcall ComboBox18Select(TObject *Sender);
	void __fastcall ComboBox15DropDown(TObject *Sender);
	void __fastcall ComboBox14DropDown(TObject *Sender);
	void __fastcall ComboBox20DropDown(TObject *Sender);
	void __fastcall ComboBox11DropDown(TObject *Sender);
	void __fastcall ComboBox17DropDown(TObject *Sender);
	void __fastcall ComboBox19DropDown(TObject *Sender);
	void __fastcall ComboBox1Select(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TStaffWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStaffWindow *StaffWindow;
//---------------------------------------------------------------------------
#endif
