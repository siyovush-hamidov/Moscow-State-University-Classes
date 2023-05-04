//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.FileCtrl.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.WinXCalendars.hpp>
#include <Vcl.WindowsStore.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TDriveComboBox *DriveComboBox1;
	TPanel *Panel1;
	TFileListBox *FileListBox1;
	TDirectoryListBox *DirectoryListBox1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TPanel *Panel2;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TDataSource *DataSource1;
	TListBox *ListBox1;
	TListBox *ListBox2;
	TMemo *Memo1;
	TPanel *Panel3;
	TMemo *Memo2;
	TDBGrid *DBGrid1;
	void __fastcall RadioButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
