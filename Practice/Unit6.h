//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.VirtualImage.hpp>
#include <Vcl.WinXPickers.hpp>
#include <Vcl.Themes.hpp>
#include <Vcl.Styles.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TVirtualImage *VirtualImage1;
	TLabel *Label1;
	TEdit *Edit1;
	TDatePicker *DatePicker1;
	TDatePicker *DatePicker2;
	TVirtualImage *VirtualImage2;
	TEdit *Edit2;
	TEdit *Edit3;
	TButton *Button1;
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
