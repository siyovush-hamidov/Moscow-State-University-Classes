//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAdminWindow *AdminWindow;
//---------------------------------------------------------------------------
__fastcall TAdminWindow::TAdminWindow(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAdminWindow::VirtualImage5Click(TObject *Sender)
{
	if(OpenPictureDialog1->Execute()) Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);

}
//---------------------------------------------------------------------------

void __fastcall TAdminWindow::ScrollBoxAddStudentMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled)
{
    ScrollBoxAddStudent->VertScrollBar->Position -= WheelDelta;
}
//---------------------------------------------------------------------------

void __fastcall TAdminWindow::ComboBox8DropDown(TObject *Sender)
{
    MaskEdit8->Visible = false;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT Direction FROM Directions");
	ADOQuery1->Open(); ComboBox8->Items->Clear();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox8->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
    }
}
//---------------------------------------------------------------------------

void __fastcall TAdminWindow::ComboBox1DropDown(TObject *Sender)
{
    MaskEdit1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TAdminWindow::ComboBox2DropDown(TObject *Sender)
{
    MaskEdit2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TAdminWindow::ComboBox7DropDown(TObject *Sender)
{
    MaskEdit7->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TAdminWindow::ComboBox4DropDown(TObject *Sender)
{
	MaskEdit4->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TAdminWindow::ComboBox3DropDown(TObject *Sender)
{
    MaskEdit3->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TAdminWindow::ComboBox5DropDown(TObject *Sender)
{
    MaskEdit5->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TAdminWindow::ComboBox6DropDown(TObject *Sender)
{
    MaskEdit6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TAdminWindow::Button1Click(TObject *Sender)
{
	if
	(
	LabeledEdit1->Text == "" ||
	LabeledEdit1->Text == "" ||
	LabeledEdit1->Text == ""
	) MessageDlg("Поля: 'Имя', 'Фамилия' и 'Отчество' являются обязательными для заполнения. Пожалуйста, заполните их и попытайтесь снова.", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
	else
	{
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("INSERT INTO Students(Surname, Name, [Middle Name], Nationality, Gender, [Date Of Birth], [Country Of Birth], [Military Status], [Family Status], [Home Address], [Actual Adress], [Phone Number], Email, Image, [Passport Serial Number], [Date Of Issue Of Passport], [Place Of Issue Of Passport], [High School], [Country Of High School], [High School Diploma], [High School Diploma Date Of Issue], [High School Diploma Serial Number], [Enrollment Year], Degree, Speciality, Course, [Type Of Education], [Form Of Education], [Number Of Student's Ticket], [Boarding House]) VALUES(:Surname, :Name, :MiddleName, :Nationality, :Gender, :DateOfBirth, :CountryOfBirth, :MilitaryStatus, :FamilyStatus, :HomeAddress, :ActualAdress, :PhoneNumber, :Email, :Image, :PassportSerialNumber, :DateOfIssueOfPassport, :PlaceOfIssueOfPassport, :HighSchool, :CountryOfHighSchool, :HighSchoolDiploma, :HighSchoolDiplomaDateOfIssue, :HighSchoolDiplomaSerialNumber, EnrollmentYear, Degree, Speciality, Course, TypeOfEducation, FormOfEducation, NumberOfStudentsTicket, BoardingHouse))");
		ADOQuery1->Parameters->ParamByName("Surname")->Value = LabeledEdit1->Text;
		ADOQuery1->Parameters->ParamByName("Name")->Value = LabeledEdit2->Text;
		ADOQuery1->Parameters->ParamByName("MiddleName")->Value = LabeledEdit3->Text;
		ADOQuery1->Parameters->ParamByName("Nationality")->Value = LabeledEdit4->Text;
		ADOQuery1->Parameters->ParamByName("Gender")->Value = ComboBox1->ItemIndex;
		ADOQuery1->Parameters->ParamByName("DateOfBirth")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker1->Date);
		ADOQuery1->Parameters->ParamByName("CountryOfBirth")->Value = LabeledEdit5->Text;
		ADOQuery1->Parameters->ParamByName("MilitaryStatus")->Value = ComboBox2->Text;
		ADOQuery1->Parameters->ParamByName("FamilyStatus")->Value = LabeledEdit6->Text;
		ADOQuery1->Parameters->ParamByName("HomeAddress")->Value = LabeledEdit7->Text;
		ADOQuery1->Parameters->ParamByName("ActualAdress")->Value = LabeledEdit8->Text;
		ADOQuery1->Parameters->ParamByName("PhoneNumber")->Value = LabeledEdit9->Text;
		ADOQuery1->Parameters->ParamByName("Email")->Value = LabeledEdit10->Text;
		// IMAGE
		TMemoryStream *Stream = new TMemoryStream();
		Image1->Picture->SaveToStream(Stream);
		Stream->Position = 0;
		ADOQuery1->Parameters->ParamByName("Image")->LoadFromStream(Stream, ftGraphic);
		//IMAGE
		ADOQuery1->Parameters->ParamByName("PassportSerialNumber")->Value = LabeledEdit11->Text;
		ADOQuery1->Parameters->ParamByName("DateOfIssueOfPassport")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker2->Date);
		ADOQuery1->Parameters->ParamByName("PlaceOfIssueOfPassport")->Value = LabeledEdit12->Text;
		ADOQuery1->Parameters->ParamByName("HighSchool")->Value = LabeledEdit13->Text;
		ADOQuery1->Parameters->ParamByName("CountryOfHighSchool")->Value = LabeledEdit14->Text;
		ADOQuery1->Parameters->ParamByName("HighSchoolDiploma")->Value = LabeledEdit19->Text;
		ADOQuery1->Parameters->ParamByName("HighSchoolDiplomaDateOfIssue")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker3->Date);
		ADOQuery1->Parameters->ParamByName("HighSchoolDiplomaSerialNumber")->Value = LabeledEdit15->Text;
		ADOQuery1->Parameters->ParamByName("EnrollmentYear")->Value = LabeledEdit16->Text;
		ADOQuery1->Parameters->ParamByName("Degree")->Value = ComboBox7->Text;
		ADOQuery1->Parameters->ParamByName("Speciality")->Value = ComboBox8->Text;
		ADOQuery1->Parameters->ParamByName("Course")->Value = ComboBox3->ItemIndex - 1;
		ADOQuery1->Parameters->ParamByName("TypeOfEducation")->Value = ComboBox4->Text;
		ADOQuery1->Parameters->ParamByName("FormOfEducation")->Value = ComboBox5->Text;
		ADOQuery1->Parameters->ParamByName("NumberOfStudentsTicket")->Value = LabeledEdit20->Text;
		ADOQuery1->Parameters->ParamByName("BoardingHouse")->Value = ComboBox6->Text;;
		ADOQuery1->ExecSQL(); delete Stream;
	}
}
//---------------------------------------------------------------------------

void __fastcall TAdminWindow::Button2Click(TObject *Sender)
{
	ComboBox1->ItemIndex = -1; ComboBox2->ItemIndex = -1; ComboBox3->ItemIndex = -1; ComboBox4->ItemIndex = -1;
	ComboBox5->ItemIndex = -1; ComboBox6->ItemIndex = -1; ComboBox7->ItemIndex = -1; ComboBox8->ItemIndex = -1;

	LabeledEdit1->Text = ""; LabeledEdit2->Text = ""; LabeledEdit3->Text = ""; LabeledEdit4->Text = "";
	LabeledEdit5->Text = ""; LabeledEdit6->Text = ""; LabeledEdit7->Text = ""; LabeledEdit8->Text = "";
	LabeledEdit9->Text = ""; LabeledEdit10->Text = ""; LabeledEdit11->Text = ""; LabeledEdit12->Text = "";
	LabeledEdit13->Text = ""; LabeledEdit14->Text = ""; LabeledEdit15->Text = ""; LabeledEdit16->Text = "";
	LabeledEdit19->Text = ""; LabeledEdit20->Text = "";

    Image1->Picture = NULL;
}
//---------------------------------------------------------------------------

