//---------------------------------------------------------------------------

#ifndef Unit9H
#define Unit9H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.VirtualImage.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.WinXPickers.hpp>
//---------------------------------------------------------------------------
class TAdminWindow : public TForm
{
__published:	// IDE-managed Components
	TVirtualImage *VirtualImage1;
	TADOQuery *ADOQuery1;
	TVirtualImage *VirtualImage12;
	TLabel *Label2;
	TVirtualImage *VirtualImage4;
	TVirtualImage *VirtualImage2;
	TLabel *Label1;
	TVirtualImage *VirtualImage3;
	TVirtualImage *VirtualImage6;
	TVirtualImage *VirtualImage7;
	TLabel *Label3;
	TVirtualImage *VirtualImage8;
	TScrollBox *ScrollBoxAddStudent;
	TLabel *Label4;
	TOpenPictureDialog *OpenPictureDialog1;
	TVirtualImage *VirtualImage9;
	TLabel *Label5;
	TLabeledEdit *LabeledEdit1;
	TLabeledEdit *LabeledEdit2;
	TLabeledEdit *LabeledEdit3;
	TLabeledEdit *LabeledEdit4;
	TComboBox *ComboBox1;
	TLabel *Label6;
	TDateTimePicker *DateTimePicker1;
	TLabel *Label7;
	TLabeledEdit *LabeledEdit5;
	TLabeledEdit *LabeledEdit6;
	TLabeledEdit *LabeledEdit7;
	TLabeledEdit *LabeledEdit8;
	TLabeledEdit *LabeledEdit9;
	TLabeledEdit *LabeledEdit10;
	TLabeledEdit *LabeledEdit11;
	TLabeledEdit *LabeledEdit12;
	TVirtualImage *VirtualImage10;
	TComboBox *ComboBox2;
	TLabel *Label8;
	TLabeledEdit *LabeledEdit13;
	TLabeledEdit *LabeledEdit14;
	TDateTimePicker *DateTimePicker2;
	TLabel *Label9;
	TImage *Image1;
	TLabel *Label10;
	TDateTimePicker *DateTimePicker3;
	TLabeledEdit *LabeledEdit15;
	TLabeledEdit *LabeledEdit16;
	TComboBox *ComboBox3;
	TLabel *Label11;
	TComboBox *ComboBox4;
	TLabel *Label12;
	TLabeledEdit *LabeledEdit19;
	TComboBox *ComboBox5;
	TLabel *Label13;
	TLabeledEdit *LabeledEdit20;
	TComboBox *ComboBox6;
	TLabel *Label14;
	TButton *Button1;
	TLabel *Label15;
	TComboBox *ComboBox7;
	TLabel *Label16;
	TComboBox *ComboBox8;
	TLabel *Label17;
	TMaskEdit *MaskEdit1;
	TMaskEdit *MaskEdit2;
	TMaskEdit *MaskEdit3;
	TMaskEdit *MaskEdit4;
	TMaskEdit *MaskEdit5;
	TMaskEdit *MaskEdit6;
	TMaskEdit *MaskEdit7;
	TMaskEdit *MaskEdit8;
	TButton *Button2;
	void __fastcall VirtualImage5Click(TObject *Sender);
	void __fastcall ScrollBoxAddStudentMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
	void __fastcall ComboBox8DropDown(TObject *Sender);
	void __fastcall ComboBox1DropDown(TObject *Sender);
	void __fastcall ComboBox2DropDown(TObject *Sender);
	void __fastcall ComboBox7DropDown(TObject *Sender);
	void __fastcall ComboBox4DropDown(TObject *Sender);
	void __fastcall ComboBox3DropDown(TObject *Sender);
	void __fastcall ComboBox5DropDown(TObject *Sender);
	void __fastcall ComboBox6DropDown(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAdminWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAdminWindow *AdminWindow;
//---------------------------------------------------------------------------
#endif
