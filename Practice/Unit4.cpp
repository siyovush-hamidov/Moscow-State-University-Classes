//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit5.h"
//#include "Unit7.h"
//#include "Unit8.h"
//#include "Unit9.h"
//����������� ������ ����
#include <Vcl.Themes.hpp>
#include <memory>
#include <windows.h>
#include <System.hpp>
//������ � ������
#include <System.SysUtils.hpp>
#include <System.DateUtils.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainWindow *MainWindow;
//---------------------------------------------------------------------------
__fastcall TMainWindow::TMainWindow(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// ���������� ���������� ���������� ���������� ���������� ���������� ���������� ���������� ����������
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// ������� ���� ������� ���� ������� ���� ������� ���� ������� ���� ������� ���� ������� ���� ������� ����
///////////////////////////////////////////////////////////////////////////////////////////////////////////
int checker = 0;

void __fastcall TMainWindow::ToggleSwitch1Click(TObject *Sender)
{
	if (ToggleSwitch1->State == true)
	{
		TStyleManager::TrySetStyle("Tablet Dark");
		VirtualImageLightSwitcher->ImageName = "TO_LIGHT";
	}
	else
	{
		TStyleManager::TrySetStyle("Windows");
		VirtualImageLightSwitcher->ImageName = "TO_DARK";
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainWindow::FormCreate(TObject *Sender)
{
	while(checker < 1)
	{
		Application->CreateForm(__classid(TLoginWindow), &LoginWindow);
        checker++;
	}
//    LoginWindow->ADOQuery1
}
//---------------------------------------------------------------------------
void __fastcall TMainWindow::VirtualImageReturnToBackArrowClick(TObject *Sender)
{
	PanelMainMenu->BringToFront();
	PanelMainMenuSidebar->BringToFront();
	PanelForStudents->Visible = false;
	PanelForStaff->Visible = false;
	PanelForAdmins->Visible = false;
	VirtualImageReturnToBackArrow->Visible = false;
}
//BELOW SIDEBAR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! SIDEBAR BELOW

void __fastcall TMainWindow::VirtualImageStudentsMouseEnter(TObject *Sender)
{
	VirtualImageStudents->ImageName = "WhiteBackground";
	LabelStudents->Font->Color = clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImageStudentsMouseLeave(TObject *Sender)
{
	VirtualImageStudents->ImageName = "BlueBackground";
    LabelStudents->Font->Color = clWhite;
}

//---------------------------------------------------------------------------


void __fastcall TMainWindow::LabelStudentsClick(TObject *Sender)
{
    PanelForStudents->Visible = true;
	PanelForStudents->BringToFront();
	PanelForStudentsSidebar->BringToFront();

	VirtualImageReturnToBackArrow->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainWindow::Label623Click(TObject *Sender)
{
    PanelForStaff->Visible = true;
	PanelForStaff->BringToFront();
	PanelForStaffSidebar->BringToFront();

    VirtualImageReturnToBackArrow->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::Label624Click(TObject *Sender)
{
    PanelForAdmins->Visible = true;
	PanelForAdmins->BringToFront();
	PanelForAdminsSidebar->BringToFront();

    VirtualImageReturnToBackArrow->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImage5MouseEnter(TObject *Sender)
{
	Label623->Font->Color = clBlack;
	VirtualImage5->ImageName = "WhiteBackground";
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImage5MouseLeave(TObject *Sender)
{
	Label623->Font->Color = clWhite;
	VirtualImage5->ImageName = "BlueBackground";
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImage7MouseEnter(TObject *Sender)
{
	VirtualImage7->ImageName = "WhiteBackground";
    Label624->Font->Color = clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImage7MouseLeave(TObject *Sender)
{
	Label624->Font->Color = clWhite;
	VirtualImage7->ImageName = "BlueBackground";
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// ������� ���� ������� ���� ������� ���� ������� ���� ������� ���� ������� ���� ������� ���� ������� ����
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// �������� �������� �������� �������� �������� �������� �������� �������� �������� �������� �������� ��������
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void __fastcall TMainWindow::LabelStudentsTimeTableClick(TObject *Sender)
{
	ScrollBoxTimeTable->Visible = true;
	ScrollBoxTimeTable->BringToFront();
	this->ComboBox2Select(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::LabelStudentsFindClick(TObject *Sender)
{
	ScrollBoxTeachersLessons->Visible = true;
	ScrollBoxTeachersLessons->BringToFront();
	this->ComboBox5DropDown(Sender);
	ComboBox5->ItemIndex = 0;
	this->ComboBox5Select(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TMainWindow::ScrollBoxTimeTableMouseWheel(TObject *Sender, TShiftState Shift,
		  int WheelDelta, TPoint &MousePos, bool &Handled)
{
	ScrollBoxTimeTable->VertScrollBar->Position -= WheelDelta;
}
//---------------------------------------------------------------------------


void __fastcall TMainWindow::ComboBox1DropDown(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT Faculty FROM Faculties");
	ADOQuery1->Open(); ComboBox1->Items->Clear();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox1->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}
	ComboBox1->ItemIndex = 0;
}
//---------------------------------------------------------------------------


void __fastcall TMainWindow::ComboBox1Select(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT D.Direction FROM Directions D JOIN Faculties F ON F.FacultyId = D.FacultyId WHERE F.Faculty = :Faculty");
	ADOQuery1->Parameters->ParamByName("Faculty")->Value = ComboBox1->Text;
	ADOQuery1->Open(); ComboBox2->Items->Clear();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox2->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}
	ComboBox2->ItemIndex = 0;

    this->ComboBox2Select(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox2DropDown(TObject *Sender)
{
    ComboBox2->Items->Clear();
    ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT D.Direction FROM Directions D JOIN Faculties F ON D.FacultyId = F.FacultyId WHERE F.Faculty = '"+ComboBox1->Text+"'");
	ADOQuery1->Open();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox2->Items->Add(ADOQuery1->FieldByName("Direction")->AsString);
		ADOQuery1->Next();
    }
}
//---------------------------------------------------------------------------

void SetDatesToDayOfWeeks(TLabel *labels[7]) {
	// Get the current date from the system
	TDateTime today = Date();

	// Get the day of the week
	int dayOfWeek = DayOfWeek(today);

	// Calculate the date of the first day of the current week (Monday)
	TDateTime startOfWeek = today - (dayOfWeek - 2);

    // Create a custom format settings object with the Russian locale
	TFormatSettings fmt = TFormatSettings::Create("ru-RU");

    // Create an array of month names in the genitive case
	UnicodeString months[12] = {"������", "�������", "�����", "������", "���", "����", "����", "�������", "��������", "�������", "������", "�������"};

    // Loop through each label
    for (int i = 0; i < 7; i++) {
		TDateTime currentDay = startOfWeek + i;
		int currentMonth = MonthOf(currentDay);
		UnicodeString TheMonth = months[currentMonth - 1];
		UnicodeString dateString = FormatDateTime("d '"+TheMonth+"' yyyy", currentDay, fmt);
//		dateString = StringReplace(dateString, "mmmm", TheMonth, TReplaceFlags() << rfReplaceAll);
		labels[i]->Caption = dateString;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox2Select(TObject *Sender)
{
    String DaysOfWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
//	for(int i = 0; i < 7; i++) ((TPanel*)FindComponent("Panel" + DaysOfWeek[i]))->Visible = false;

	TLabel *DayOfWeeksDates[7] = {Label11, Label28, Label45, Label62, Label79, Label96, Label113};
	SetDatesToDayOfWeeks(DayOfWeeksDates);

	TDateTime today = Date();
	int dayOfWeek = DayOfWeek(today);
	TDateTime startOfWeek = today - (dayOfWeek - 2);

	TDateTime MondayDate = startOfWeek; String MondayString = FormatDateTime("yyyy-mm-dd", MondayDate);
	TDateTime TuesdayDate = startOfWeek + 1; String TuesdayString = FormatDateTime("yyyy-mm-dd", TuesdayDate);
	TDateTime WednesdayDate = startOfWeek + 2; String WednesdayString = FormatDateTime("yyyy-mm-dd", WednesdayDate);
	TDateTime ThursdayDate = startOfWeek + 3; String ThursdayString = FormatDateTime("yyyy-mm-dd", ThursdayDate);
	TDateTime FridayDate = startOfWeek + 4; String FridayString = FormatDateTime("yyyy-mm-dd", FridayDate);
	TDateTime SaturdayDate = startOfWeek + 5; String SaturdayString = FormatDateTime("yyyy-mm-dd", SaturdayDate);
	TDateTime SundayDate = startOfWeek + 6; String SundayString = FormatDateTime("yyyy-mm-dd", SundayDate);

	//����������
	String StringDays[7] = {MondayString, TuesdayString, WednesdayString, ThursdayString, FridayString, SaturdayString, SundayString};

	int Pairs[5] = {1, 2, 3, 4, 5};

	int SelectedDay = ComboBox4->ItemIndex;
	int EndingDay;
	if(SelectedDay == 0)
	{
		for(int i = 0; i < 7; i++)
		{
//			((TPanel*)FindComponent("Panel" + DaysOfWeek[i]))->Visible = true;
			((TPanel*)FindComponent("Panel" + DaysOfWeek[i]))->Top = PanelMonday->Top + (i * PanelMonday->Height);
		}
		EndingDay = 7;
    }
	else
	{
        for(int i = 0; i < 7; i++) ((TPanel*)FindComponent("Panel" + DaysOfWeek[i]))->Top = PanelMonday->Top;
		((TPanel*)FindComponent("Panel" + DaysOfWeek[ComboBox4->ItemIndex - 1]))->BringToFront();
		EndingDay = SelectedDay + 1;
	}

	for(int i = SelectedDay; i < EndingDay; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			ADOQuery1->SQL->Clear();
            ADOQuery1->SQL->Add("SELECT S.Subject, Te.Teacher, Ty.TypeOfLesson, C.Classroom FROM Subjects S JOIN Faculties F ON F.Faculty = '"+ComboBox1->Text+"' JOIN Directions D ON D.Direction = '"+ComboBox2->Text+"' JOIN TimeTable T ON S.SubjectId = T.SubjectId JOIN Teachers Te ON Te.TeacherId = T.TeacherId JOIN TypesOfLesson Ty ON Ty.TypeOfLessonId = T.TypeOfLessonId JOIN Classrooms C ON C.ClassroomId = T.ClassroomId WHERE T.Date = '"+StringDays[i - (SelectedDay != 0)]+"' AND T.Pair = '"+IntToStr(j + 1)+"' AND T.FacultyId = F.FacultyId AND T.DirectionId = D.DirectionId AND T.Course = '"+IntToStr(ComboBox3->ItemIndex + 1)+"'");
			ADOQuery1->Open();
			((TLabel*)FindComponent("Label" + IntToStr(i * 20 + j * 4 + 129)))->Caption = ADOQuery1->FieldByName("Subject")->AsString;
			((TLabel*)FindComponent("Label" + IntToStr(i * 20 + j * 4 + 130)))->Caption = ADOQuery1->FieldByName("Teacher")->AsString;
			((TLabel*)FindComponent("Label" + IntToStr(i * 20 + j * 4 + 131)))->Caption = ADOQuery1->FieldByName("TypeOfLesson")->AsString;
			((TLabel*)FindComponent("Label" + IntToStr(i * 20 + j * 4 + 132)))->Caption = ADOQuery1->FieldByName("Classroom")->AsString;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox3Select(TObject *Sender)
{
    this->ComboBox2Select(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImageHamburgerClick(TObject *Sender)
{
	if(VirtualImageHamburger->ImageName == "MenuButtonWhite")
	{
		PanelMainMenuSidebar->Visible = false;
		PanelForStudentsSidebar->Visible = false;
		PanelForStaffSidebar->Visible = false;
        PanelForAdminsSidebar->Visible = false;

        VirtualImageLogoMSU->Visible = false;
        VirtualImageBackground->Visible = false;
//		VirtualImageReturnToBackArrow->Visible = false;

		PanelForAdmins->Width = MainWindow->ClientWidth; PanelForAdmins->Left = VirtualImageHamburger->Width + 20;
		PanelForStudents->Width = MainWindow->ClientWidth; PanelForStudents->Left = VirtualImageHamburger->Width + 20;
		PanelForStaff->Width = MainWindow->ClientWidth; PanelForStaff->Left = VirtualImageHamburger->Width + 20;


		VirtualImageHamburger->ImageName = "MenuButtonBlue"; VirtualImageHamburger->BringToFront();
		VirtualImageReturnToBackArrow->ImageName = "BlueArrow";
	}
	else
	{
		VirtualImageBackground->Visible = true;
		VirtualImageLogoMSU->Visible = true;
//		VirtualImageReturnToBackArrow->Visible = true;

        PanelMainMenuSidebar->Visible = true;
		PanelForStudentsSidebar->Visible = true;
		PanelForStaffSidebar->Visible = true;
		PanelForAdminsSidebar->Visible = true;

		PanelForAdmins->Width = MainWindow->ClientWidth - VirtualImageBackground->Width; PanelForAdmins->Left = VirtualImageBackground->Width;
		PanelForStudents->Width = MainWindow->ClientWidth - VirtualImageBackground->Width; PanelForStudents->Left = VirtualImageBackground->Width;
		PanelForStaff->Width = MainWindow->ClientWidth - VirtualImageBackground->Width; PanelForStaff->Left = VirtualImageBackground->Width;

		VirtualImageHamburger->ImageName = "MenuButtonWhite"; VirtualImageHamburger->BringToFront();
        VirtualImageReturnToBackArrow->ImageName = "WhiteArrow";
	}

}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImage73Click(TObject *Sender)
{
//	if(VirtualImage73->ImageName == "MenuButtonWhite")
//	{
//		Label4->Visible = false;
//		Label269->Visible = false;
//
//		VirtualImage11->Visible = false;
//		VirtualImage61->Visible = false;
//		VirtualImage63->Visible = false;
//		VirtualImage65->Visible = false;
//		VirtualImage72->Visible = false;
//		VirtualImage75->Visible = false;
//		VirtualImage78->Visible = false;
//		VirtualImage128->Visible = false;
//		VirtualImage73->ImageName = "MenuButtonBlue";
//
//
//	}
//	else
//	{
//		Label4->Visible = true;
//        Label269->Visible = true;
//
//        VirtualImage11->Visible = true;
//		VirtualImage61->Visible = true;
//		VirtualImage63->Visible = true;
//		VirtualImage65->Visible = true;
//		VirtualImage72->Visible = true;
//		VirtualImage75->Visible = true;
//		VirtualImage78->Visible = true;
//		VirtualImage128->Visible = true;
//		VirtualImage73->ImageName = "MenuButtonWhite";
//	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox5DropDown(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT Teacher FROM Teachers");
	ADOQuery1->Open(); ComboBox5->Items->Clear();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox5->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
        ADOQuery1->Next();
	}
    ComboBox5->TextHint = ComboBox5->Items->Strings[0];
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox5Select(TObject *Sender)
{
	TLabel *DayOfWeeksDates[7] = {Label274, Label292, Label310, Label328, Label346, Label364, Label382};
	SetDatesToDayOfWeeks(DayOfWeeksDates);

	TDateTime today = Date();
	int dayOfWeek = DayOfWeek(today);
	TDateTime startOfWeek = today - (dayOfWeek - 2);

	TDateTime MondayDate = startOfWeek; String MondayString = FormatDateTime("yyyy-mm-dd", MondayDate);
	TDateTime TuesdayDate = startOfWeek + 1; String TuesdayString = FormatDateTime("yyyy-mm-dd", TuesdayDate);
	TDateTime WednesdayDate = startOfWeek + 2; String WednesdayString = FormatDateTime("yyyy-mm-dd", WednesdayDate);
	TDateTime ThursdayDate = startOfWeek + 3; String ThursdayString = FormatDateTime("yyyy-mm-dd", ThursdayDate);
	TDateTime FridayDate = startOfWeek + 4; String FridayString = FormatDateTime("yyyy-mm-dd", FridayDate);
	TDateTime SaturdayDate = startOfWeek + 5; String SaturdayString = FormatDateTime("yyyy-mm-dd", SaturdayDate);
	TDateTime SundayDate = startOfWeek + 6; String SundayString = FormatDateTime("yyyy-mm-dd", SundayDate);

	//����������
	String StringDays[7] = {MondayString, TuesdayString, WednesdayString, ThursdayString, FridayString, SaturdayString, SundayString};

	int Pairs[5] = {1, 2, 3, 4, 5};

	int SelectedDay = ComboBox6->ItemIndex;
	int EndingDay;
	if(SelectedDay == 0)
	{
		for(int i = 0; i < 7; i++)
		{
//			((TPanel*)FindComponent("Panel" + DaysOfWeek[i]))->Visible = true;
			((TPanel*)FindComponent("PanelTeachersLessons" + IntToStr(i + 1)))->Top = PanelTeachersLessons1->Top + (i * PanelTeachersLessons1->Height);
		}
		EndingDay = 7;
    }
	else
	{
		for(int i = 0; i < 7; i++) ((TPanel*)FindComponent("PanelTeachersLessons" + IntToStr(i + 1)))->Top = PanelTeachersLessons1->Top;
		((TPanel*)FindComponent("PanelTeachersLessons" + IntToStr(ComboBox6->ItemIndex)))->BringToFront();
		EndingDay = SelectedDay + 1;
	}

	for(int i = SelectedDay; i < EndingDay; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("SELECT Te.Teacher, S.Subject, Ty.TypeOfLesson, C.Classroom, (SELECT '' + SUBSTRING(value, 1, 1) FROM STRING_SPLIT(D.Direction, ' ') FOR XML PATH('')) AS Direction, TT.Course FROM TimeTable TT JOIN Directions D ON D.DirectionId = TT.DirectionId JOIN Subjects S ON S.SubjectId = TT.SubjectId JOIN Teachers Te ON Te.TeacherId = TT.TeacherId JOIN TypesOfLesson Ty ON Ty.TypeOfLessonId = TT.TypeOfLessonId JOIN Classrooms C ON C.ClassroomId = TT.ClassroomId WHERE TT.Date = '"+StringDays[i - (SelectedDay != 0)]+"' AND TT.Pair = '"+IntToStr(j + 1)+"' AND Te.Teacher = '"+ComboBox5->Text+"' ");
			ADOQuery1->Open();
			((TLabel*)FindComponent("Label" + IntToStr(i * 25 + j * 5 + 399)))->Caption = ADOQuery1->FieldByName("Direction")->AsString;
			((TLabel*)FindComponent("Label" + IntToStr(i * 25 + j * 5 + 400)))->Caption = ADOQuery1->FieldByName("Course")->AsString;
			((TLabel*)FindComponent("Label" + IntToStr(i * 25 + j * 5 + 401)))->Caption = ADOQuery1->FieldByName("Subject")->AsString;
			((TLabel*)FindComponent("Label" + IntToStr(i * 25 + j * 5 + 402)))->Caption = ADOQuery1->FieldByName("TypeOfLesson")->AsString;
            ((TLabel*)FindComponent("Label" + IntToStr(i * 25 + j * 5 + 403)))->Caption = ADOQuery1->FieldByName("Classroom")->AsString;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ScrollBoxTeachersLessonsMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled)
{
	ScrollBoxTeachersLessons->VertScrollBar->Position -= WheelDelta;
}
//---------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// �������� �������� �������� �������� �������� �������� �������� �������� �������� �������� �������� ��������
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// ���������� � ������� ���������� � ������� ���������� � ������� ���������� � ������� ���������� � �������
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void __fastcall TMainWindow::LabelStaffAddClick(TObject *Sender)
{
	LessonConstructor->Visible = true;
	LessonConstructor->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::LabelStaffEditClick(TObject *Sender)
{
	LessonEditor->Visible = true;
	LessonEditor->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox8DropDown(TObject *Sender)
{
	ComboBox8->Items->Clear();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT Faculty FROM Faculties");
	ADOQuery1->Open(); ADOQuery1->First();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox8->Items->Add(ADOQuery1->FieldByName("Faculty")->AsString); ADOQuery1->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox8Select(TObject *Sender)
{
	ComboBox9->Enabled = true;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT D.Direction FROM Directions D JOIN Faculties F ON F.FacultyId = D.FacultyId WHERE F.Faculty = '"+ComboBox8->Text+"'");
	ADOQuery1->Open(); ComboBox9->Items->Clear();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox9->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}
	ComboBox9->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox10DropDown(TObject *Sender)
{
	ComboBox10->Items->Clear();
	for (int i = 1; i < 5; i++) ComboBox10->Items->Add(""+IntToStr(i)+"-� ����");

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT G.Course, CASE WHEN E.Course IS NULL THEN 0 ELSE 1 END AS IsEngaged FROM (SELECT DISTINCT Course FROM GroupIsEngaged) G LEFT JOIN (SELECT Course FROM GroupIsEngaged JOIN Directions ON GroupIsEngaged.DirectionId = Directions.DirectionId JOIN Faculties ON GroupIsEngaged.FacultyId = Faculties.FacultyId WHERE Faculties.Faculty = :Faculty AND Directions.Direction = :Direction AND GroupIsEngaged.Date = :Date AND GroupIsEngaged.Pair = :Pair AND GroupIsEngaged.IsEngaged = 1) E ON G.Course = E.Course");
	ADOQuery1->Parameters->ParamByName("Faculty")->Value = ComboBox8->Text;
	ADOQuery1->Parameters->ParamByName("Direction")->Value = ComboBox9->Text;
	ADOQuery1->Parameters->ParamByName("Date")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker1->Date);
	ADOQuery1->Parameters->ParamByName("Pair")->Value = ComboBox11->ItemIndex + 1;
	ADOQuery1->Open();

	while (!ADOQuery1->Eof)
	{
		if (ADOQuery1->FieldByName("IsEngaged")->AsInteger == 1)
		{
			String temp = ComboBox10->Items->Strings[ADOQuery1->FieldByName("Course")->AsInteger - 1];
			ComboBox10->Items->Strings[ADOQuery1->FieldByName("Course")->AsInteger - 1] = temp + " (������ ��� ��������� ����)";
		}
		ADOQuery1->Next();
	}

}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox12DropDown(TObject *Sender)
{
    ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT C.Classroom, C.ClassroomId, CASE WHEN E.ClassroomId IS NULL THEN 0 ELSE 1 END AS IsEngaged FROM Classrooms C LEFT JOIN (SELECT ClassroomId FROM ClassroomIsEngaged WHERE Date = :Date AND Pair = :Pair AND IsEngaged = 1) E ON C.ClassroomId = E.ClassroomId");
	ADOQuery1->Parameters->ParamByName("Date")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker1->Date);
	ADOQuery1->Parameters->ParamByName("Pair")->Value = ComboBox11->ItemIndex + 1;
	ADOQuery1->Open();

	ComboBox12->Items->Clear();

	while (!ADOQuery1->Eof) {
		String ClassroomName = ADOQuery1->FieldByName("Classroom")->AsString;
		if (ADOQuery1->FieldByName("IsEngaged")->AsInteger == 1) {
			ClassroomName += " (��������� ������)";
		}
		ComboBox12->Items->Add(ClassroomName);
		ADOQuery1->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox13DropDown(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT T.Teacher, T.TeacherId, CASE WHEN E.TeacherId IS NULL THEN 0 ELSE 1 END AS IsEngaged FROM Teachers T LEFT JOIN (SELECT TeacherId FROM TeacherIsEngaged WHERE Date = :Date AND Pair = :Pair AND IsEngaged = 1) E ON T.TeacherId = E.TeacherId");
	ADOQuery1->Parameters->ParamByName("Date")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker1->Date);
	ADOQuery1->Parameters->ParamByName("Pair")->Value = ComboBox11->ItemIndex + 1;
	ADOQuery1->Open();

	ComboBox13->Items->Clear();

	while (!ADOQuery1->Eof) {
		String TeacherName = ADOQuery1->FieldByName("Teacher")->AsString;
		if (ADOQuery1->FieldByName("IsEngaged")->AsInteger == 1) {
			TeacherName += " (������������� �����)";
		}
		ComboBox13->Items->Add(TeacherName);
		ADOQuery1->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox13Select(TObject *Sender)
{
    ComboBox7->Enabled = true;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT S.Subject FROM Subjects S JOIN Teachers T ON T.Teacher = :Teacher JOIN TeacherSubjects TS ON S.SubjectId = TS.SubjectId WHERE T.TeacherId = TS.TeacherId");
	String TeachersName = ComboBox13->Text; String TeachersSubString = L" (������������� �����)";
	int Tpos = TeachersName.Pos(TeachersSubString); if(Tpos > 0) TeachersName.Delete(Tpos, TeachersSubString.Length());
	ADOQuery1->Parameters->ParamByName("Teacher")->Value = TeachersName; ADOQuery1->Open();
	ComboBox7->Items->Clear();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox7->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}
    ComboBox7->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::Button3Click(TObject *Sender)
{
	if(ComboBox7->Text == ""  ||
	   ComboBox8->Text == ""  ||
	   ComboBox9->Text == ""  ||
	   ComboBox10->Text == "" ||
	   ComboBox11->Text == "" ||
	   ComboBox12->Text == "" ||
	   ComboBox13->Text == "" ||
	   ComboBox14->Text == "") MessageDlg("��������� ��� ����!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
	else
	{
        String ClassroomName = ComboBox12->Text; String ClassroomSubString = L" (��������� ������)";
		String TeacherName = ComboBox13->Text; String TeacherSubString = L" (������������� �����)";
		int Tpos = TeacherName.Pos(TeacherSubString);     if(Tpos > 0) TeacherName.Delete(Tpos, TeacherSubString.Length());
		int Cpos = ClassroomName.Pos(ClassroomSubString); if(Cpos > 0) ClassroomName.Delete(Cpos, ClassroomSubString.Length());

		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("INSERT INTO TimeTable(Date, FacultyId, DirectionId, Course, Pair, ClassroomId, TeacherId, SubjectId, TypeOfLessonId, GroupId) SELECT :Date, F.FacultyId, D.DirectionId, :Course1, :Pair, C.ClassroomId, T.TeacherId, S.SubjectId, TL.TypeOfLessonId, G.GroupId FROM Directions D JOIN Faculties F ON F.Faculty = :Faculty JOIN Classrooms C ON C.Classroom = :Classroom JOIN Teachers T ON T.Teacher = :Teacher JOIN Subjects S ON S.Subject = :Subject JOIN Groups G ON (G.FacultyId = F.FacultyId AND G.DirectionId = D.DirectionId AND G.Course = :Course) JOIN TypesOfLesson TL ON TL.TypeOfLesson = :TypeOfLesson WHERE D.Direction = :Direction");
		ADOQuery1->Parameters->ParamByName("Faculty")->Value = ComboBox8->Text;
		ADOQuery1->Parameters->ParamByName("Direction")->Value = ComboBox9->Text;
		ADOQuery1->Parameters->ParamByName("Classroom")->Value = ClassroomName;
		ADOQuery1->Parameters->ParamByName("Teacher")->Value = TeacherName;
		ADOQuery1->Parameters->ParamByName("Subject")->Value = ComboBox7->Text;
		ADOQuery1->Parameters->ParamByName("Course")->Value = ComboBox10->ItemIndex + 1;
		ADOQuery1->Parameters->ParamByName("Course1")->Value = ComboBox10->ItemIndex + 1;
		ADOQuery1->Parameters->ParamByName("TypeOfLesson")->Value = ComboBox14->Text;
		ADOQuery1->Parameters->ParamByName("Date")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker1->Date);
		ADOQuery1->Parameters->ParamByName("Pair")->Value = ComboBox11->ItemIndex + 1;
		ADOQuery1->ExecSQL();
	}
	this->Button1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::Button1Click(TObject *Sender)
{
	ComboBox7->ClearSelection(); ComboBox7->Enabled = false;
	ComboBox8->ClearSelection(); ComboBox9->Enabled = false;
	ComboBox9->ClearSelection();
	ComboBox10->ClearSelection();
	ComboBox11->ClearSelection();
	ComboBox12->ClearSelection();
	ComboBox13->ClearSelection();
	ComboBox14->ClearSelection();
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::DateTimePicker1Change(TObject *Sender)
{
    TDateTime date = DateTimePicker1->Date;
	int dayOfWeek = DayOfWeek(date);

	switch(dayOfWeek)
	{
		case 1: Label576->Caption = "���� (���� ������: �����������)"; break;
		case 2: Label576->Caption = "���� (���� ������: �����������)"; break;
		case 3: Label576->Caption = "���� (���� ������: �������)";     break;
		case 4: Label576->Caption = "���� (���� ������: �����)";       break;
		case 5: Label576->Caption = "���� (���� ������: �������)";     break;
		case 6: Label576->Caption = "���� (���� ������: �������)";     break;
		case 7: Label576->Caption = "���� (���� ������: �������)";     break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::Label575Click(TObject *Sender)
{
    LessonConstructor->Visible = true;
	LessonConstructor->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::Label574Click(TObject *Sender)
{
	LessonEditor->Visible = true;
    LessonEditor->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox19Select(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT TT.TypeOfLessonId, TT.Course, TT.Date, TT.Pair, F.Faculty, D.Direction, CR.Classroom, T.Teacher, S.Subject, TL.TypeOfLesson FROM TimeTable TT JOIN Faculties F ON TT.FacultyId = (SELECT FacultyId FROM Faculties WHERE Faculty = '"+ComboBox15->Text+"') JOIN Directions D ON TT.DirectionId = (SELECT DirectionId FROM Directions WHERE Direction = '"+ComboBox16->Text+"') JOIN Classrooms CR ON CR.ClassroomId = TT.ClassroomId JOIN Teachers T ON TT.TeacherId = T.TeacherId JOIN TypesOfLesson TL ON TT.TypeOfLessonId = TL.TypeOfLessonId JOIN Subjects S ON TT.SubjectId = S.SubjectId WHERE TT.Pair = '"+IntToStr(ComboBox19->ItemIndex + 1)+"' AND TT.Date = '"+FormatDateTime("yyyy-mm-dd", DateTimePicker2->Date)+"' AND TT.Course = '"+IntToStr(ComboBox18->ItemIndex + 1)+"'");
//	String DateString = FormatDateTime("yyyy-mm-dd", DateTimePicker2->Date);
//	ADOQuery1->Parameters->ParamByName("Faculty")->Value = ComboBox15->Text;
//   	ADOQuery1->Parameters->ParamByName("Direction")->Value = ComboBox16->Text;
//	ADOQuery1->Parameters->ParamByName("Pair")->Value = ComboBox19->ItemIndex + 1;
//	ADOQuery1->Parameters->ParamByName("Date")->Value = DateString;
//	ADOQuery1->Parameters->ParamByName("Course")->Value = ComboBox18->ItemIndex + 1;

	ADOQuery1->Open();

	if(!ADOQuery1->IsEmpty())
	{
		DateTimePicker3->Enabled = true;
		ComboBox17->Enabled = true;
		ComboBox20->Enabled = true;
		ComboBox21->Enabled = true;
		ComboBox22->Enabled = true;
		ComboBox23->Enabled = true;
		ComboBox24->Enabled = true;
		ComboBox25->Enabled = true;
		ComboBox26->Enabled = true;
		Label590->Enabled = true;
		Label591->Enabled = true;
		Label592->Enabled = true;
		Label593->Enabled = true;
		Label594->Enabled = true;
		Label595->Enabled = true;
		Label596->Enabled = true;
		Label597->Enabled = true;
		Label598->Enabled = true;
		Button2->Enabled = true;
		Button4->Enabled = true;
		Label594->Caption = "���� ("+ADOQuery1->FieldByName("Date")->AsString+")";
		TDateTime DateValue = VarToDateTime(ADOQuery1->FieldByName("Date")->AsString);
		DateTimePicker3->Date = DateValue;
		Label590->Caption = "��������� ("+ADOQuery1->FieldByName("ClassRoom")->AsString+")";
		Label591->Caption = "������������� ("+ADOQuery1->FieldByName("Teacher")->AsString+")";
		Label592->Caption = "���������� ("+ADOQuery1->FieldByName("Subject")->AsString+")";
		Label593->Caption = "��� ������� ("+ADOQuery1->FieldByName("TypeOfLesson")->AsString+")";
		Label595->Caption = "���� ("+ADOQuery1->FieldByName("Pair")->AsString+"-�)";
		Label596->Caption = "��������� ("+ADOQuery1->FieldByName("Faculty")->AsString+")";
		Label597->Caption = "����������� ("+ADOQuery1->FieldByName("Direction")->AsString+")";
		Label598->Caption = "���� ("+ADOQuery1->FieldByName("Course")->AsString+"-�)";
	}
	else
	{
		Label590->Caption = "���������";
		Label591->Caption = "�������������";
		Label592->Caption = "����������";
		Label593->Caption = "��� �������";
		Label595->Caption = "����";
		Label596->Caption = "���������";
		Label597->Caption = "�����������";
		Label598->Caption = "����";
		DateTimePicker3->Enabled = false;
		ComboBox17->Enabled = false;
		ComboBox20->Enabled = false;
		ComboBox21->Enabled = false;
		ComboBox22->Enabled = false;
		ComboBox23->Enabled = false;
		ComboBox24->Enabled = false;
		ComboBox25->Enabled = false;
		ComboBox26->Enabled = false;
		Label590->Enabled = false;
		Label591->Enabled = false;
		Label592->Enabled = false;
		Label593->Enabled = false;
		Label594->Enabled = false;
		Label595->Enabled = false;
		Label596->Enabled = false;
		Label597->Enabled = false;
		Label598->Enabled = false;
		Button2->Enabled = false;
		Button4->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox15DropDown(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT Faculty FROM Faculties");
	ADOQuery1->Open(); ComboBox15->Items->Clear();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox15->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}
	ComboBox15->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox15Select(TObject *Sender)
{
	ComboBox16->Enabled = true;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT D.Direction FROM Directions D JOIN Faculties F ON F.FacultyId = D.FacultyId WHERE F.Faculty = :Faculty");
	ADOQuery1->Parameters->ParamByName("Faculty")->Value = ComboBox15->Text;
	ADOQuery1->Open(); ComboBox16->Items->Clear();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox16->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}
	ComboBox16->ItemIndex = 0;

    this->ComboBox19Select(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox24DropDown(TObject *Sender)
{
    ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT Faculty FROM Faculties");
	ADOQuery1->Open(); ComboBox24->Items->Clear();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox24->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}
	ComboBox24->ItemIndex = 0;
}
//---------------------------------------------------------------------------


void __fastcall TMainWindow::ComboBox24Select(TObject *Sender)
{
	ComboBox25->Enabled = true;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT D.Direction FROM Directions D JOIN Faculties F ON F.FacultyId = D.FacultyId WHERE F.Faculty = :Faculty");
	ADOQuery1->Parameters->ParamByName("Faculty")->Value = ComboBox24->Text;
	ADOQuery1->Open(); ComboBox25->Items->Clear();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox25->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}
	ComboBox25->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox26DropDown(TObject *Sender)
{
	ComboBox26->Items->Clear();
	for (int i = 1; i < 5; i++) ComboBox26->Items->Add(""+IntToStr(i)+"-� ����");

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT G.Course, CASE WHEN E.Course IS NULL THEN 0 ELSE 1 END AS IsEngaged FROM (SELECT DISTINCT Course FROM GroupIsEngaged) G LEFT JOIN (SELECT Course FROM GroupIsEngaged JOIN Directions ON GroupIsEngaged.DirectionId = Directions.DirectionId JOIN Faculties ON GroupIsEngaged.FacultyId = Faculties.FacultyId WHERE Faculties.Faculty = :Faculty AND Directions.Direction = :Direction AND GroupIsEngaged.Date = :Date AND GroupIsEngaged.Pair = :Pair AND GroupIsEngaged.IsEngaged = 1) E ON G.Course = E.Course");
	ADOQuery1->Parameters->ParamByName("Faculty")->Value = ComboBox24->Text;
	ADOQuery1->Parameters->ParamByName("Direction")->Value = ComboBox25->Text;
	ADOQuery1->Parameters->ParamByName("Date")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker3->Date);
	ADOQuery1->Parameters->ParamByName("Pair")->Value = ComboBox23->ItemIndex + 1;
	ADOQuery1->Open();

	while (!ADOQuery1->Eof)
	{
		if (ADOQuery1->FieldByName("IsEngaged")->AsInteger == 1)
		{
			String temp = ComboBox26->Items->Strings[ADOQuery1->FieldByName("Course")->AsInteger - 1];
			ComboBox26->Items->Strings[ADOQuery1->FieldByName("Course")->AsInteger - 1] = temp + " (������ ��� ��������� ����)";
		}
		ADOQuery1->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox20DropDown(TObject *Sender)
{
    ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT C.Classroom, C.ClassroomId, CASE WHEN E.ClassroomId IS NULL THEN 0 ELSE 1 END AS IsEngaged FROM Classrooms C LEFT JOIN (SELECT ClassroomId FROM ClassroomIsEngaged WHERE Date = :Date AND Pair = :Pair AND IsEngaged = 1) E ON C.ClassroomId = E.ClassroomId");
	ADOQuery1->Parameters->ParamByName("Date")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker3->Date);
	ADOQuery1->Parameters->ParamByName("Pair")->Value = ComboBox23->ItemIndex + 1;
	ADOQuery1->Open();

	ComboBox20->Items->Clear();

	while (!ADOQuery1->Eof) {
		String ClassroomName = ADOQuery1->FieldByName("Classroom")->AsString;
		if (ADOQuery1->FieldByName("IsEngaged")->AsInteger == 1) {
			ClassroomName += " (��������� ������)";
		}
		ComboBox20->Items->Add(ClassroomName);
		ADOQuery1->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox21DropDown(TObject *Sender)
{
    ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT T.Teacher, T.TeacherId, CASE WHEN E.TeacherId IS NULL THEN 0 ELSE 1 END AS IsEngaged FROM Teachers T LEFT JOIN (SELECT TeacherId FROM TeacherIsEngaged WHERE Date = :Date AND Pair = :Pair AND IsEngaged = 1) E ON T.TeacherId = E.TeacherId");
	ADOQuery1->Parameters->ParamByName("Date")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker3->Date);
	ADOQuery1->Parameters->ParamByName("Pair")->Value = ComboBox23->ItemIndex + 1;
	ADOQuery1->Open();

	ComboBox21->Items->Clear();

	while (!ADOQuery1->Eof) {
		String TeacherName = ADOQuery1->FieldByName("Teacher")->AsString;
		if (ADOQuery1->FieldByName("IsEngaged")->AsInteger == 1) {
			TeacherName += " (������������� �����)";
		}
		ComboBox21->Items->Add(TeacherName);
		ADOQuery1->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ComboBox21Select(TObject *Sender)
{
	ComboBox17->Enabled = true;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT S.Subject FROM Subjects S JOIN Teachers T ON T.Teacher = :Teacher JOIN TeacherSubjects TS ON S.SubjectId = TS.SubjectId WHERE T.TeacherId = TS.TeacherId");
	String TeachersName = ComboBox21->Text; String TeachersSubString = L" (������������� �����)";
	int Tpos = TeachersName.Pos(TeachersSubString); if(Tpos > 0) TeachersName.Delete(Tpos, TeachersSubString.Length());
	ADOQuery1->Parameters->ParamByName("Teacher")->Value = TeachersName; ADOQuery1->Open();
	ComboBox17->Items->Clear();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox17->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}
	ComboBox17->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::Button4Click(TObject *Sender)
{
	if(ComboBox17->Text == ""  ||
	   ComboBox20->Text == "" ||
	   ComboBox21->Text == "" ||
	   ComboBox22->Text == "" ||
	   ComboBox23->Text == "" ||
	   ComboBox24->Text == "" ||
	   ComboBox25->Text == "" ||
	   ComboBox26->Text == "") MessageDlg("��������� ��� ����!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);

	else
	{
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("UPDATE TimeTable SET Date = :Date, Pair = :Pair, FacultyId = (SELECT FacultyId FROM Faculties WHERE Faculty = :Faculty), DirectionId = (SELECT DirectionId FROM Directions WHERE Direction = :Direction), Course = :Course, ClassroomId = (SELECT ClassroomId FROM Classrooms WHERE Classroom = :Classroom), TeacherId = (SELECT TeacherId FROM Teachers WHERE Teacher = :Teacher), SubjectId = (SELECT SubjectId FROM Subjects WHERE Subject = :Subject), TypeOfLessonId = (SELECT TypeOfLessonId FROM TypesOfLesson WHERE TypeOfLesson = :TypeOfLesson) WHERE LessonId = (SELECT LessonId FROM TimeTable WHERE Date = :InitialDate AND Pair = :InitialPair AND FacultyId = (SELECT FacultyId FROM Faculties WHERE Faculty = :InitialFaculty) AND DirectionId = (SELECT DirectionId FROM Directions WHERE Direction = :InitialDirection) AND Course = :InitialCourse)");
		ADOQuery1->Parameters->ParamByName("InitialDate")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker2->Date);
		ADOQuery1->Parameters->ParamByName("InitialPair")->Value = ComboBox19->ItemIndex + 1;
		ADOQuery1->Parameters->ParamByName("InitialFaculty")->Value = ComboBox15->Text;
		ADOQuery1->Parameters->ParamByName("InitialDirection")->Value = ComboBox16->Text;
		ADOQuery1->Parameters->ParamByName("InitialCourse")->Value = ComboBox18->ItemIndex + 1;

		//���������� �� (�����)
		String ClassroomsName = ComboBox20->Text; String ClassroomsSubString = L" (��������� ������)";
		String TeachersName = ComboBox21->Text; String TeachersSubString = L" (������������� �����)";
		int Tpos = TeachersName.Pos(TeachersSubString); if(Tpos > 0) TeachersName.Delete(Tpos, TeachersSubString.Length());
		int Cpos = ClassroomsName.Pos(ClassroomsSubString); if(Cpos > 0) ClassroomsName.Delete(Cpos, ClassroomsSubString.Length());

		ADOQuery1->Parameters->ParamByName("Date")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker3->Date);
		ADOQuery1->Parameters->ParamByName("Pair")->Value = IntToStr(ComboBox23->ItemIndex + 1);
		ADOQuery1->Parameters->ParamByName("Faculty")->Value = ComboBox24->Text;
		ADOQuery1->Parameters->ParamByName("Direction")->Value = ComboBox25->Text;
		ADOQuery1->Parameters->ParamByName("Course")->Value = IntToStr(ComboBox26->ItemIndex + 1);
		ADOQuery1->Parameters->ParamByName("Classroom")->Value = ClassroomsName;
		ADOQuery1->Parameters->ParamByName("Teacher")->Value = TeachersName;
		ADOQuery1->Parameters->ParamByName("Subject")->Value = ComboBox17->Text;
		ADOQuery1->Parameters->ParamByName("TypeOfLesson")->Value = ComboBox22->Text;
		ADOQuery1->ExecSQL();

		this->Button2Click(Sender);
        this->ComboBox19Select(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::Button2Click(TObject *Sender)
{
	ComboBox17->ClearSelection();
	ComboBox20->ClearSelection();
	ComboBox21->ClearSelection();
	ComboBox22->ClearSelection();
	ComboBox23->ClearSelection();
	ComboBox24->ClearSelection();
	ComboBox25->ClearSelection();
	ComboBox26->ClearSelection();
}
//---------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// ���������� � ������� ���������� � ������� ���������� � ������� ���������� � ������� ���������� � �������
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// ������ ������ ������ ������ ������ ������ ������ ������ ������ ������ ������ ������ ������ ������ ������
///////////////////////////////////////////////////////////////////////////////////////////////////////////


void __fastcall TMainWindow::LabeledEdit1Change(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT * FROM Students WHERE Surname = :Surname AND Name = :Name AND [Middle Name] = :MiddleName");
	ADOQuery1->Parameters->ParamByName("Surname")->Value = LabeledEdit1->Text;
	ADOQuery1->Parameters->ParamByName("Name")->Value = LabeledEdit2->Text;
	ADOQuery1->Parameters->ParamByName("MiddleName")->Value = LabeledEdit3->Text;
	ADOQuery1->Open();
	if(ADOQuery1->RecordCount != 0)
	{
//		MessageDlg("����� ������� ��� ����� �������� ��������. ���� �� ������ �������� ������ � ��������, �� ��������� �� ������� '��������� ��������' -> 'C�������'", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
		Button5->Enabled = false;
		Button6->Enabled = false;

		ComboBox27->Enabled = false;
		ComboBox28->Enabled = false;
		ComboBox29->Enabled = false;
		ComboBox30->Enabled = false;
		ComboBox31->Enabled = false;
		ComboBox32->Enabled = false;
		ComboBox33->Enabled = false;
		ComboBox34->Enabled = false;

		DateTimePicker4->Enabled = false;
		DateTimePicker5->Enabled = false;
		DateTimePicker6->Enabled = false;

        Image1->Enabled = false;

		Label601->Enabled = false;
		Label602->Enabled = false;
		Label603->Enabled = false;
		Label604->Enabled = false;
		Label605->Enabled = false;
		Label606->Enabled = false;
		Label607->Enabled = false;
		Label608->Enabled = false;
		Label609->Enabled = false;
		Label610->Enabled = false;
		Label611->Enabled = false;
		Label612->Enabled = false;
		Label613->Enabled = false;
		Label614->Enabled = false;

		LabeledEdit4->Enabled = false;
		LabeledEdit5->Enabled = false;
		LabeledEdit6->Enabled = false;
		LabeledEdit7->Enabled = false;
		LabeledEdit8->Enabled = false;
		LabeledEdit9->Enabled = false;
		LabeledEdit10->Enabled = false;
		LabeledEdit11->Enabled = false;
		LabeledEdit12->Enabled = false;
		LabeledEdit13->Enabled = false;
		LabeledEdit14->Enabled = false;
		LabeledEdit15->Enabled = false;
		LabeledEdit16->Enabled = false;
		LabeledEdit17->Enabled = false;
		LabeledEdit18->Enabled = false;
		LabeledEdit19->Enabled = false;
		LabeledEdit20->Enabled = false;

		MaskEdit1->Enabled = false;
		MaskEdit2->Enabled = false;
		MaskEdit3->Enabled = false;
		MaskEdit4->Enabled = false;
		MaskEdit5->Enabled = false;
		MaskEdit6->Enabled = false;
		MaskEdit7->Enabled = false;
		MaskEdit8->Enabled = false;
	}
	else
	{
		Button5->Enabled = true;
		Button6->Enabled = true;

		ComboBox27->Enabled = true;
		ComboBox28->Enabled = true;
		ComboBox29->Enabled = true;
		ComboBox30->Enabled = true;
		ComboBox31->Enabled = true;
		ComboBox32->Enabled = true;
		ComboBox33->Enabled = true;
		ComboBox34->Enabled = true;

		DateTimePicker4->Enabled = true;
		DateTimePicker5->Enabled = true;
		DateTimePicker6->Enabled = true;

        Image1->Enabled = true;

		Label601->Enabled = true;
		Label602->Enabled = true;
		Label603->Enabled = true;
		Label604->Enabled = true;
		Label605->Enabled = true;
		Label606->Enabled = true;
		Label607->Enabled = true;
		Label608->Enabled = true;
		Label609->Enabled = true;
		Label610->Enabled = true;
		Label611->Enabled = true;
		Label612->Enabled = true;
		Label613->Enabled = true;
		Label614->Enabled = true;

		LabeledEdit4->Enabled = true;
		LabeledEdit5->Enabled = true;
		LabeledEdit6->Enabled = true;
		LabeledEdit7->Enabled = true;
		LabeledEdit8->Enabled = true;
		LabeledEdit9->Enabled = true;
		LabeledEdit10->Enabled = true;
		LabeledEdit11->Enabled = true;
		LabeledEdit12->Enabled = true;
		LabeledEdit13->Enabled = true;
		LabeledEdit14->Enabled = true;
		LabeledEdit15->Enabled = true;
		LabeledEdit16->Enabled = true;
		LabeledEdit17->Enabled = true;
		LabeledEdit18->Enabled = true;
		LabeledEdit19->Enabled = true;
		LabeledEdit20->Enabled = true;

		MaskEdit1->Enabled = true;
		MaskEdit2->Enabled = true;
		MaskEdit3->Enabled = true;
		MaskEdit4->Enabled = true;
		MaskEdit5->Enabled = true;
		MaskEdit6->Enabled = true;
		MaskEdit7->Enabled = true;
		MaskEdit8->Enabled = true;
    }
}
//---------------------------------------------------------------------------


void __fastcall TMainWindow::Button5Click(TObject *Sender)
{
	if
	(
	LabeledEdit1->Text == "" ||
	LabeledEdit2->Text == "" ||
	LabeledEdit3->Text == ""
	) MessageDlg("����: '���', '�������' � '��������' �������� ������������� ��� ����������. ����������, ��������� �� � ����������� �����.", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
	else
	{
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("INSERT INTO Students(Surname, Name, [Middle Name], Nationality, Gender, [Date Of Birth], [Country Of Birth], [Military Status], [Family Status], [Home Address], [Actual Adress], [Phone Number], Email, [Passport Serial Number], [Date Of Issue Of Passport], [Place Of Issue Of Passport], [High School], [Country Of High School], [High School Diploma], [High School Diploma Date Of Issue], [High School Diploma Serial Number], [Enrollment Year], Degree, Direction, Course, [Type Of Education], [Form Of Education], [Number Of Student's Ticket], [Boarding House]) VALUES('" + StringReplace(LabeledEdit1->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', '" + StringReplace(LabeledEdit2->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', '" + StringReplace(LabeledEdit3->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', '" + StringReplace(LabeledEdit4->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', " + IntToStr(ComboBox27->ItemIndex) + ", '" + FormatDateTime("yyyy-mm-dd", DateTimePicker4->Date) + "', '" + StringReplace(LabeledEdit5->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', '" + StringReplace(ComboBox28->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', '" + StringReplace(LabeledEdit6->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', '" + StringReplace(LabeledEdit7->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', '" + StringReplace(LabeledEdit8->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', '" + StringReplace(LabeledEdit9->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', '" + StringReplace(LabeledEdit10->Text, "'", "''", TReplaceFlags() << rfReplaceAll) +"', '" + StringReplace(LabeledEdit11->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', '" + FormatDateTime("yyyy-mm-dd", DateTimePicker5->Date) + "', '" + StringReplace(LabeledEdit12->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', '" + StringReplace(LabeledEdit13->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', '" + StringReplace(LabeledEdit14->Text, "'", "''", TReplaceFlags() << rfReplaceAll)+"','" + StringReplace(LabeledEdit19->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', '" + FormatDateTime("yyyy-mm-dd", DateTimePicker6->Date) + "', '" + StringReplace(LabeledEdit15->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', '" + StringReplace(LabeledEdit16->Text, "'", "''", TReplaceFlags() << rfReplaceAll) + "', '" + StringReplace(ComboBox33->Text, "'", "''", TReplaceFlags() << rfReplaceAll) +"', '"+ StringReplace(ComboBox34->Text, "'", "''", TReplaceFlags() << rfReplaceAll) +"', '"+ IntToStr(ComboBox29->ItemIndex + 1) +"', '"+ StringReplace(ComboBox30->Text, "'", "''", TReplaceFlags() << rfReplaceAll) +"', '"+ StringReplace(ComboBox31->Text, "'", "''", TReplaceFlags() << rfReplaceAll) +"', '"+ StringReplace(LabeledEdit20->Text, "'", "''", TReplaceFlags() << rfReplaceAll) +"', '"+ StringReplace(ComboBox32->Text, "'", "''", TReplaceFlags() << rfReplaceAll) +"' )");
        Clipboard()->AsText = ADOQuery1->SQL->Text;
		ShowMessage("SQL text: " + ADOQuery1->SQL->Text);
		ADOQuery1->ExecSQL(); this->Button6Click(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::Button6Click(TObject *Sender)
{
	ComboBox27->ClearSelection();
	ComboBox28->ClearSelection();
	ComboBox29->ClearSelection();
	ComboBox30->ClearSelection();
	ComboBox31->ClearSelection();
	ComboBox32->ClearSelection();
	ComboBox33->ClearSelection();
	ComboBox34->ClearSelection();

	LabeledEdit1->Text = ""; LabeledEdit2->Text = ""; LabeledEdit3->Text = ""; LabeledEdit4->Text = "";
	LabeledEdit5->Text = ""; LabeledEdit6->Text = ""; LabeledEdit7->Text = ""; LabeledEdit8->Text = "";
	LabeledEdit9->Text = ""; LabeledEdit10->Text = ""; LabeledEdit11->Text = ""; LabeledEdit12->Text = "";
	LabeledEdit13->Text = ""; LabeledEdit14->Text = ""; LabeledEdit15->Text = ""; LabeledEdit16->Text = "";
	LabeledEdit19->Text = ""; LabeledEdit20->Text = "";

	Image1->Picture = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ScrollBoxAddStudentMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled)
{
	ScrollBoxAddStudent->VertScrollBar->Position -= WheelDelta;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::LabelAdminsAddStudentClick(TObject *Sender)
{
	ScrollBoxAddStudent->Visible = true;
    ScrollBoxAddStudent->BringToFront();
}
//---------------------------------------------------------------------------


// �������� ������� /////////////////////////////////////////////////////////

void __fastcall TMainWindow::LabelAdminsAddTeacherClick(TObject *Sender)
{
	ScrollBoxAddTeacher->Visible = true;
    ScrollBoxAddTeacher->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImage1Click(TObject *Sender)
{
    if(OpenPictureDialog1->Execute()) Image2->Picture->LoadFromFile(OpenPictureDialog1->FileName);
}
//---------------------------------------------------------------------------


void __fastcall TMainWindow::Button7Click(TObject *Sender)
{
    if
	(
	LabeledEdit17->Text == "" ||
	LabeledEdit18->Text == "" ||
	LabeledEdit21->Text == ""
	) MessageDlg("����: '���', '�������' � '��������' �������� ������������� ��� ����������. ����������, ��������� �� � ����������� �����.", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
	else
	{
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("INSERT INTO Teachers(Teacher, Surname, Name, [Middle Name], Nationality, Gender, [Date Of Birth], [Country Of Birth], [Military Status], [Family Status], [Home Address], [Actual Adress], [Phone Number], Email, Image, [Passport Serial Number], [Date Of Issue Of Passport], [Place Of Issue Of Passport], [Latest Degree Speciality], [Latest Degree Earned], [Latest Degree Country], [Latest Degree Date Of Issue], [Latest Degree Serial Number], [Latest University], [Latest Degree Diploma]) VALUES(:Teacher, :Surname, :Name, :MiddleName, :Nationality, :Gender, :DateOfBirth, :CountryOfBirth, :MilitaryStatus, :FamilyStatus, :HomeAddress, :ActualAdress, :PhoneNumber, :Email, :Image, :PassportSerialNumber, :DateOfIssueOfPassport, :PlaceOfIssueOfPassport, :LatestDegreeSpeciality, :LatestDegreeEarned, :LatestDegreeCountry, :LatestDegreeDateOfIssue, :LatestDegreeSerialNumber, :LatestUniversity, :LatestDegreeDiploma)");
		ADOQuery1->Parameters->ParamByName("Teacher")->Value = LabeledEdit17->Text + " " + LabeledEdit18->Text.SubString(1,1) + ". " + LabeledEdit21->Text.SubString(1,1) + ".";
		ADOQuery1->Parameters->ParamByName("Surname")->Value = LabeledEdit17->Text;
		ADOQuery1->Parameters->ParamByName("Name")->Value = LabeledEdit18->Text;
		ADOQuery1->Parameters->ParamByName("MiddleName")->Value = LabeledEdit21->Text;
		ADOQuery1->Parameters->ParamByName("Nationality")->Value = LabeledEdit22->Text;
		ADOQuery1->Parameters->ParamByName("Gender")->Value = ComboBox35->ItemIndex;
		ADOQuery1->Parameters->ParamByName("DateOfBirth")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker7->Date);
		ADOQuery1->Parameters->ParamByName("CountryOfBirth")->Value = LabeledEdit23->Text;
		ADOQuery1->Parameters->ParamByName("MilitaryStatus")->Value = ComboBox36->Text;
		ADOQuery1->Parameters->ParamByName("FamilyStatus")->Value = LabeledEdit24->Text;
		ADOQuery1->Parameters->ParamByName("HomeAddress")->Value = LabeledEdit25->Text;
		ADOQuery1->Parameters->ParamByName("ActualAdress")->Value = LabeledEdit26->Text;
		ADOQuery1->Parameters->ParamByName("PhoneNumber")->Value = LabeledEdit27->Text;
		ADOQuery1->Parameters->ParamByName("Email")->Value = LabeledEdit28->Text;
		// IMAGE
		TMemoryStream *Stream = new TMemoryStream();
		Image2->Picture->SaveToStream(Stream);
		Stream->Position = 0;
		ADOQuery1->Parameters->ParamByName("Image")->LoadFromStream(Stream, ftGraphic);
		//IMAGE
		ADOQuery1->Parameters->ParamByName("PassportSerialNumber")->Value = LabeledEdit29->Text;
		ADOQuery1->Parameters->ParamByName("DateOfIssueOfPassport")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker8->Date);
		ADOQuery1->Parameters->ParamByName("PlaceOfIssueOfPassport")->Value = LabeledEdit30->Text;
		ADOQuery1->Parameters->ParamByName("LatestDegreeSpeciality")->Value = LabeledEdit35->Text;
		ADOQuery1->Parameters->ParamByName("LatestDegreeEarned")->Value = ComboBox37->Text;
		ADOQuery1->Parameters->ParamByName("LatestDegreeCountry")->Value = LabeledEdit33->Text;
		ADOQuery1->Parameters->ParamByName("LatestDegreeDateOfIssue")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker9->Date);
		ADOQuery1->Parameters->ParamByName("LatestDegreeSerialNumber")->Value = LabeledEdit34->Text;
		ADOQuery1->Parameters->ParamByName("LatestUniversity")->Value = LabeledEdit32->Text;
		ADOQuery1->Parameters->ParamByName("LatestDegreeDiploma")->Value = LabeledEdit31->Text;

		ADOQuery1->ExecSQL(); delete Stream; this->Button8Click(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::Button8Click(TObject *Sender)
{
	ComboBox35->ClearSelection();
	ComboBox36->ClearSelection();
	ComboBox37->ClearSelection();

	LabeledEdit17->Clear();
	LabeledEdit18->Clear();
	LabeledEdit21->Clear();
	LabeledEdit22->Clear();
	LabeledEdit23->Clear();
	LabeledEdit24->Clear();
	LabeledEdit25->Clear();
	LabeledEdit26->Clear();
	LabeledEdit27->Clear();
	LabeledEdit28->Clear();
	LabeledEdit29->Clear();
	LabeledEdit30->Clear();
	LabeledEdit31->Clear();
	LabeledEdit32->Clear();
	LabeledEdit33->Clear();
	LabeledEdit34->Clear();
	LabeledEdit35->Clear();

	Image2->Picture = NULL;
}


void __fastcall TMainWindow::LabeledEdit17Change(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT * FROM Teachers WHERE Surname = :Surname AND Name = :Name AND [Middle Name] = :MiddleName");
	ADOQuery1->Parameters->ParamByName("Surname")->Value = LabeledEdit17->Text;
	ADOQuery1->Parameters->ParamByName("Name")->Value = LabeledEdit18->Text;
	ADOQuery1->Parameters->ParamByName("MiddleName")->Value = LabeledEdit21->Text;
	ADOQuery1->Open();
	if(ADOQuery1->RecordCount != 0)
	{
//		MessageDlg("����� ������������� ��� ����� ��������. ���� �� ������ �������� ������ � ���, �� ��������� �� ������� '��������� ��������' -> '�������������'", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
		Button7->Enabled = false;
		Button8->Enabled = false;

		ComboBox35->Enabled = false;
		ComboBox36->Enabled = false;
		ComboBox37->Enabled = false;
		ComboBox30->Enabled = false;
		ComboBox31->Enabled = false;
		ComboBox32->Enabled = false;
		ComboBox33->Enabled = false;
		ComboBox34->Enabled = false;

		DateTimePicker7->Enabled = false;
		DateTimePicker8->Enabled = false;
		DateTimePicker9->Enabled = false;

		Image2->Enabled = false;

		Label1->Enabled = false;
		Label2->Enabled = false;
		Label3->Enabled = false;
		Label4->Enabled = false;
		Label269->Enabled = false;
		Label574->Enabled = false;
		Label575->Enabled = false;

		LabeledEdit22->Enabled = false;
		LabeledEdit23->Enabled = false;
		LabeledEdit24->Enabled = false;
		LabeledEdit25->Enabled = false;
		LabeledEdit26->Enabled = false;
		LabeledEdit27->Enabled = false;
		LabeledEdit28->Enabled = false;
		LabeledEdit29->Enabled = false;
		LabeledEdit30->Enabled = false;
		LabeledEdit31->Enabled = false;
		LabeledEdit32->Enabled = false;
		LabeledEdit33->Enabled = false;
		LabeledEdit34->Enabled = false;
		LabeledEdit35->Enabled = false;

		MaskEdit9->Enabled = false;
		MaskEdit10->Enabled = false;
		MaskEdit11->Enabled = false;
	}
	else
	{
		Button7->Enabled = true;
		Button8->Enabled = true;

		ComboBox35->Enabled = true;
		ComboBox36->Enabled = true;
		ComboBox37->Enabled = true;

		DateTimePicker7->Enabled = true;
		DateTimePicker8->Enabled = true;
		DateTimePicker9->Enabled = true;

		Image2->Enabled = true;

		Label1->Enabled = true;
		Label2->Enabled = true;
		Label3->Enabled = true;
		Label4->Enabled = true;
		Label269->Enabled = true;
		Label574->Enabled = true;
		Label575->Enabled = true;

		LabeledEdit22->Enabled = true;
		LabeledEdit23->Enabled = true;
		LabeledEdit24->Enabled = true;
		LabeledEdit25->Enabled = true;
		LabeledEdit26->Enabled = true;
		LabeledEdit27->Enabled = true;
		LabeledEdit28->Enabled = true;
		LabeledEdit29->Enabled = true;
		LabeledEdit30->Enabled = true;
		LabeledEdit31->Enabled = true;
		LabeledEdit32->Enabled = true;
		LabeledEdit33->Enabled = true;
		LabeledEdit34->Enabled = true;
		LabeledEdit35->Enabled = true;

		MaskEdit9->Enabled = true;
		MaskEdit10->Enabled = true;
		MaskEdit11->Enabled = true;
	}
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//�������� ����������
void __fastcall TMainWindow::LabelAdminsAddStaffClick(TObject *Sender)
{
	ScrollBoxAddStaff->Visible = true;
    ScrollBoxAddStaff->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::Button9Click(TObject *Sender)
{
    if
	(
	LabeledEdit36->Text == "" ||
	LabeledEdit37->Text == "" ||
	LabeledEdit38->Text == ""
	) MessageDlg("����: '���', '�������' � '��������' �������� ������������� ��� ����������. ����������, ��������� �� � ����������� �����.", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
	else
	{
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("INSERT INTO Employees(Surname, Name, [Middle Name], Nationality, Gender, [Date Of Birth], [Country Of Birth], [Military Status], [Family Status], [Home Address], [Actual Adress], [Phone Number], Email, Image, [Passport Serial Number], [Date Of Issue Of Passport], [Place Of Issue Of Passport], [Latest Degree Speciality], [Latest Degree Earned], [Latest Degree Country], [Latest Degree Date Of Issue], [Latest Degree Serial Number], [Latest University], [Latest Degree Diploma], [Department], [Position]) VALUES(:Surname, :Name, :MiddleName, :Nationality, :Gender, :DateOfBirth, :CountryOfBirth, :MilitaryStatus, :FamilyStatus, :HomeAddress, :ActualAdress, :PhoneNumber, :Email, :Image, :PassportSerialNumber, :DateOfIssueOfPassport, :PlaceOfIssueOfPassport, :LatestDegreeSpeciality, :LatestDegreeEarned, :LatestDegreeCountry, :LatestDegreeDateOfIssue, :LatestDegreeSerialNumber, :LatestUniversity, :LatestDegreeDiploma, :Department, :Position)");
		ADOQuery1->Parameters->ParamByName("Surname")->Value = LabeledEdit36->Text;
		ADOQuery1->Parameters->ParamByName("Name")->Value = LabeledEdit37->Text;
		ADOQuery1->Parameters->ParamByName("MiddleName")->Value = LabeledEdit38->Text;
		ADOQuery1->Parameters->ParamByName("Nationality")->Value = LabeledEdit39->Text;
		ADOQuery1->Parameters->ParamByName("Gender")->Value = ComboBox38->ItemIndex;
		ADOQuery1->Parameters->ParamByName("DateOfBirth")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker10->Date);
		ADOQuery1->Parameters->ParamByName("CountryOfBirth")->Value = LabeledEdit40->Text;
		ADOQuery1->Parameters->ParamByName("MilitaryStatus")->Value = ComboBox39->Text;
		ADOQuery1->Parameters->ParamByName("FamilyStatus")->Value = LabeledEdit41->Text;
		ADOQuery1->Parameters->ParamByName("HomeAddress")->Value = LabeledEdit42->Text;
		ADOQuery1->Parameters->ParamByName("ActualAdress")->Value = LabeledEdit43->Text;
		ADOQuery1->Parameters->ParamByName("PhoneNumber")->Value = LabeledEdit44->Text;
		ADOQuery1->Parameters->ParamByName("Email")->Value = LabeledEdit45->Text;
		// IMAGE
		TMemoryStream *Stream = new TMemoryStream();
		Image2->Picture->SaveToStream(Stream);
		Stream->Position = 0;
		ADOQuery1->Parameters->ParamByName("Image")->LoadFromStream(Stream, ftGraphic);
		//IMAGE
		ADOQuery1->Parameters->ParamByName("PassportSerialNumber")->Value = LabeledEdit46->Text;
		ADOQuery1->Parameters->ParamByName("DateOfIssueOfPassport")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker11->Date);
		ADOQuery1->Parameters->ParamByName("PlaceOfIssueOfPassport")->Value = LabeledEdit47->Text;
		ADOQuery1->Parameters->ParamByName("LatestDegreeDiploma")->Value = LabeledEdit48->Text;
		ADOQuery1->Parameters->ParamByName("LatestUniversity")->Value = LabeledEdit49->Text;
		ADOQuery1->Parameters->ParamByName("LatestDegreeCountry")->Value = LabeledEdit50->Text;
		ADOQuery1->Parameters->ParamByName("LatestDegreeEarned")->Value = ComboBox40->Text;
		ADOQuery1->Parameters->ParamByName("LatestDegreeSerialNumber")->Value = LabeledEdit51->Text;
		ADOQuery1->Parameters->ParamByName("LatestDegreeDateOfIssue")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker12->Date);
		ADOQuery1->Parameters->ParamByName("LatestDegreeSpeciality")->Value = LabeledEdit52->Text;
		ADOQuery1->Parameters->ParamByName("Department")->Value = ComboBox41->Text;
		ADOQuery1->Parameters->ParamByName("Position")->Value = LabeledEdit53->Text;


		Clipboard()->AsText = ADOQuery1->SQL->Text;
		ShowMessage("SQL text: " + ADOQuery1->SQL->Text);

		ADOQuery1->ExecSQL(); delete Stream; this->Button10Click(Sender);
	}
}
//---------------------------------------------------------------------------
//		ADOQuery1->SQL->Clear();
//		ADOQuery1->SQL->Add("INSERT INTO Employees(Surname, Name, [Middle Name], Nationality, Gender, [Date Of Birth], [Country Of Birth], [Military Status], [Family Status], [Home Address], [Actual Adress], [Phone Number], Email, Image, [Passport Serial Number], [Date Of Issue Of Passport], [Place Of Issue Of Passport], [Latest Degree Speciality], [Latest Degree Earned], [Latest Degree Country], [Latest Degree Date Of Issue], [Latest Degree Serial Number], [Latest University], [Latest Degree Diploma], Department, Position) VALUES('" + LabeledEdit36->Text + "', '" + LabeledEdit37->Text + "', '" + LabeledEdit38->Text + "', '" + LabeledEdit39->Text + "', " + IntToStr(ComboBox38->ItemIndex) + ", '" + FormatDateTime("yyyy-mm-dd", DateTimePicker10->Date) + "', '" + LabeledEdit40->Text + "', '" + ComboBox39->Text + "', '" + LabeledEdit41->Text + "', '" + LabeledEdit42->Text + "', '" + LabeledEdit43->Text + "', '" + LabeledEdit44->Text + "', '" + LabeledEdit45->Text + "', :Image, '" + LabeledEdit46->Text + "', '" + FormatDateTime("yyyy-mm-dd", DateTimePicker11->Date) + "', '" + LabeledEdit47->Text + "', '" + LabeledEdit52->Text + "', '" + ComboBox40->Text+ "', '" +LabeledEdit50->Text+ "', '" + FormatDateTime("yyyy-mm-dd", DateTimePicker12->Date) + "', '"+  LabeledEdit51->Text+ "', '"+  LabeledEdit49->Text+ "', :LatestDegreeDiploma, '"+ ComboBox41->Text+ "', '" + LabeledEdit53->Text+ "')");
//		// IMAGE
//		TMemoryStream *Stream = new TMemoryStream();
//		Image2->Picture->SaveToStream(Stream);
//		Stream->Position = 0;
//		ADOQuery1->Parameters->ParamByName("Image")->LoadFromStream(Stream, ftGraphic);
//		//IMAGE
//		ADOQuery1->Parameters->ParamByName("LatestDegreeDiploma")->Value = LabeledEdit48->Text;

void __fastcall TMainWindow::Button10Click(TObject *Sender)
{
	ComboBox38->ClearSelection();
	ComboBox39->ClearSelection();
	ComboBox40->ClearSelection();
	ComboBox41->ClearSelection();

	LabeledEdit36->Clear();
	LabeledEdit37->Clear();
	LabeledEdit38->Clear();
	LabeledEdit39->Clear();
	LabeledEdit40->Clear();
	LabeledEdit41->Clear();
	LabeledEdit42->Clear();
	LabeledEdit43->Clear();
	LabeledEdit44->Clear();
	LabeledEdit45->Clear();
	LabeledEdit46->Clear();
	LabeledEdit47->Clear();
	LabeledEdit48->Clear();
	LabeledEdit49->Clear();
	LabeledEdit50->Clear();
	LabeledEdit51->Clear();
	LabeledEdit52->Clear();
	LabeledEdit53->Clear();

	Image3->Picture = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::LabeledEdit36Change(TObject *Sender)
{
    ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT * FROM Employees WHERE Surname = :Surname AND Name = :Name AND [Middle Name] = :MiddleName");
	ADOQuery1->Parameters->ParamByName("Surname")->Value = LabeledEdit36->Text;
	ADOQuery1->Parameters->ParamByName("Name")->Value = LabeledEdit37->Text;
	ADOQuery1->Parameters->ParamByName("MiddleName")->Value = LabeledEdit38->Text;
	ADOQuery1->Open();

	if(ADOQuery1->RecordCount != 0)
	{
//        MessageDlg("����� ��������� ��� ����� ��������. ���� �� ������ �������� ������ � ���, �� ��������� �� ������� '��������� ��������' -> '����������'", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
		Button9->Enabled = false;
		Button10->Enabled = false;

		ComboBox38->Enabled = false;
		ComboBox39->Enabled = false;
		ComboBox40->Enabled = false;

		DateTimePicker10->Enabled = false;
		DateTimePicker11->Enabled = false;
		DateTimePicker12->Enabled = false;

		Image3->Enabled = false;

		Label615->Enabled = false;
		Label616->Enabled = false;
		Label617->Enabled = false;
		Label618->Enabled = false;
		Label619->Enabled = false;
		Label620->Enabled = false;
		Label621->Enabled = false;
        Label622->Enabled = false;

		LabeledEdit39->Enabled = false;
		LabeledEdit40->Enabled = false;
		LabeledEdit41->Enabled = false;
		LabeledEdit42->Enabled = false;
		LabeledEdit43->Enabled = false;
		LabeledEdit44->Enabled = false;
		LabeledEdit45->Enabled = false;
		LabeledEdit46->Enabled = false;
		LabeledEdit47->Enabled = false;
		LabeledEdit48->Enabled = false;
		LabeledEdit49->Enabled = false;
		LabeledEdit50->Enabled = false;
		LabeledEdit51->Enabled = false;
		LabeledEdit52->Enabled = false;
		LabeledEdit53->Enabled = false;

		MaskEdit12->Enabled = false;
		MaskEdit13->Enabled = false;
		MaskEdit14->Enabled = false;
		MaskEdit15->Enabled = false;

	}
	else
	{
		Button9->Enabled = true;
		Button10->Enabled = true;

		ComboBox38->Enabled = true;
		ComboBox39->Enabled = true;
		ComboBox40->Enabled = true;

		DateTimePicker10->Enabled = true;
		DateTimePicker11->Enabled = true;
		DateTimePicker12->Enabled = true;

		Image3->Enabled = true;

		Label615->Enabled = true;
		Label616->Enabled = true;
		Label617->Enabled = true;
		Label618->Enabled = true;
		Label619->Enabled = true;
		Label620->Enabled = true;
		Label621->Enabled = true;
		Label622->Enabled = true;

		LabeledEdit39->Enabled = true;
		LabeledEdit40->Enabled = true;
		LabeledEdit41->Enabled = true;
		LabeledEdit42->Enabled = true;
		LabeledEdit43->Enabled = true;
		LabeledEdit44->Enabled = true;
		LabeledEdit45->Enabled = true;
		LabeledEdit46->Enabled = true;
		LabeledEdit47->Enabled = true;
		LabeledEdit48->Enabled = true;
		LabeledEdit49->Enabled = true;
		LabeledEdit50->Enabled = true;
		LabeledEdit51->Enabled = true;
		LabeledEdit52->Enabled = true;
		LabeledEdit53->Enabled = true;

		MaskEdit12->Enabled = true;
		MaskEdit13->Enabled = true;
		MaskEdit14->Enabled = true;
		MaskEdit15->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImage3Click(TObject *Sender)
{
	if(OpenPictureDialog1->Execute()) Image3->Picture->LoadFromFile(OpenPictureDialog1->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImage9MouseEnter(TObject *Sender)
{
	VirtualImage9->ImageName = "WhiteBackground";
	Label625->Font->Color = clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImage9MouseLeave(TObject *Sender)
{
	VirtualImage9->ImageName = "BlueBackground";
	Label625->Font->Color = clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::Label625Click(TObject *Sender)
{
	ScrollBoxTimeTable->Visible = true;
	ScrollBoxTimeTable->BringToFront();
    this->ComboBox2Select(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::Label626Click(TObject *Sender)
{
	ScrollBoxTeachersLessons->Visible = true;
	ScrollBoxTeachersLessons->BringToFront();
    this->ComboBox5Select(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImage61MouseEnter(TObject *Sender)
{
	VirtualImage61->ImageName = "WhiteBackground";
	Label626->Font->Color = clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImage61MouseLeave(TObject *Sender)
{
	VirtualImage61->ImageName = "BlueBackground";
	Label626->Font->Color = clWhite;
}
//---------------------------------------------------------------------------


void __fastcall TMainWindow::Label627Click(TObject *Sender)
{
	LessonConstructor->Visible = true;
    LessonConstructor->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::Label628Click(TObject *Sender)
{
	LessonEditor->Visible = true;
    LessonEditor->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImage64MouseEnter(TObject *Sender)
{
	VirtualImage64->ImageName = "WhiteBackground";
	Label627->Font->Color = clBlack;
}
//---------------------------------------------------------------------------


void __fastcall TMainWindow::VirtualImage64MouseLeave(TObject *Sender)
{
	VirtualImage64->ImageName = "BlueBackground";
	Label627->Font->Color = clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImage73MouseEnter(TObject *Sender)
{
	VirtualImage73->ImageName = "WhiteBackground";
	Label628->Font->Color = clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::VirtualImage73MouseLeave(TObject *Sender)
{
	VirtualImage73->ImageName = "BlueBackground";
	Label628->Font->Color = clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::Label632Click(TObject *Sender)
{
	ScrollBoxAddStudent->Visible = true;
	ScrollBoxAddStudent->BringToFront();
}
//---------------------------------------------------------------------------


void __fastcall TMainWindow::Label633Click(TObject *Sender)
{
	ScrollBoxAddTeacher->Visible = true;
	ScrollBoxAddTeacher->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::Label634Click(TObject *Sender)
{
	ScrollBoxAddStaff->Visible = true;
	ScrollBoxAddStaff->BringToFront();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TMainWindow::Image1Click(TObject *Sender)
{
	if(OpenPictureDialog1->Execute()) Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
    Label602->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ScrollBoxAddStaffMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled)
{
	ScrollBoxAddStaff->VertScrollBar->Position -= WheelDelta;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::ScrollBoxAddTeacherMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled)
{
    ScrollBoxAddTeacher->VertScrollBar->Position -= WheelDelta;
}
//---------------------------------------------------------------------------

void __fastcall TMainWindow::FormResize(TObject *Sender)
{
	MainWindow->Constraints->MinWidth = 1120;
	MainWindow->Constraints->MinHeight = 740;

	// Calculate the new scale factor based on the current size of the form
	double newScaleX = double(MainWindow->Width) / double(MainWindow->Constraints->MinWidth);
	double newScaleY = (double)MainWindow->Height / double(MainWindow->Constraints->MinHeight);

    // Call the ScaleBy method to resize all components on the form
	MainWindow->ScaleBy(newScaleX, newScaleY);
	PanelMainMenu->ScaleBy(newScaleX, newScaleY);
	PanelMainMenuSidebar->ScaleBy(newScaleX, newScaleY);
	PanelForStudents->ScaleBy(newScaleX, newScaleY);
	PanelForStudentsSidebar->ScaleBy(newScaleX, newScaleY);
	ScrollBoxTimeTable->ScaleBy(newScaleX, newScaleY);
	ScrollBoxTeachersLessons->ScaleBy(newScaleX, newScaleY);
	PanelForStaff->ScaleBy(newScaleX, newScaleY);
    PanelForStaffSidebar->ScaleBy(newScaleX, newScaleY);
	LessonConstructor->ScaleBy(newScaleX, newScaleY);
    LessonEditor->ScaleBy(newScaleX, newScaleY);
	PanelForAdmins->ScaleBy(newScaleX, newScaleY);
    PanelForAdminsSidebar->ScaleBy(newScaleX, newScaleY);
	ScrollBoxAddStudent->ScaleBy(newScaleX, newScaleY);
	ScrollBoxAddTeacher->ScaleBy(newScaleX, newScaleY);
	ScrollBoxAddStaff->ScaleBy(newScaleX, newScaleY);
}
//---------------------------------------------------------------------------

