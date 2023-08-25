//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"

#include "Unit7.h"
#include <System.SysUtils.hpp>
#include <System.DateUtils.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStudentsWindow *StudentsWindow;
//---------------------------------------------------------------------------
__fastcall TStudentsWindow::TStudentsWindow(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TStudentsWindow::ScrollBoxTimeTableMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled)
{
	ScrollBoxTimeTable->VertScrollBar->Position -= WheelDelta;
}
//---------------------------------------------------------------------------
// ОПРЕДЕЛНИЕ ДАТЫ КАЖДОГО ДНЯ ТЕКУЩЕЙ НЕДЕЛИ

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
	UnicodeString months[12] = {"Января", "Февраля", "Марта", "Апреля", "Мая", "Июня", "Июля", "Августа", "Сентября", "Октября", "Ноября", "Декабря"};

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

void __fastcall TStudentsWindow::Label1Click(TObject *Sender)
{
	for(int i = 1; i < 8; i++) ((TPanel*)FindComponent("Panel" + IntToStr(i)))->Visible = false;

	TLabel *DayOfWeeksDates[7] = {Label8, Label25, Label42, Label59, Label76, Label93, Label110};
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

	//РАСПИСАНИЕ
	String StringDays[7] = {MondayString, TuesdayString, WednesdayString, ThursdayString, FridayString, SaturdayString, SundayString};

	int Pairs[5] = {1, 2, 3, 4, 5};
	int SelectedDay = ComboBox4->ItemIndex;
	int EndingDay;
	if(SelectedDay == 0)
	{
		for(int i = 1; i < 8; i++)
		{
			((TPanel*)FindComponent("Panel" + IntToStr(i)))->Visible = true;
			((TPanel*)FindComponent("Panel" + IntToStr(i)))->Top = Panel1->Top + ((i - 1) * Panel1->Height);
        }
		EndingDay = 7;
    }
	else
	{
		((TPanel*)FindComponent("Panel" + IntToStr(ComboBox4->ItemIndex)))->Visible = true;
        ((TPanel*)FindComponent("Panel" + IntToStr(ComboBox4->ItemIndex)))->Top = 320;
		EndingDay = SelectedDay + 1;
	}

	for(int i = SelectedDay; i < EndingDay; i++)
	{

		for(int j = 0; j < 5; j++)
		{
			ADOQuery1->SQL->Clear();
			ADOQuery1->SQL->Add("SELECT F.FacultyId, D.DirectionId, T.SubjectId, T.TeacherId, T.TypeOfLessonId, T.ClassroomId, S.Subject, Te.Teacher, Ty.TypeOfLesson, C.Classroom FROM TimeTable T JOIN Faculties F ON F.Faculty = '"+ComboBox1->Text+"' JOIN Directions D ON D.Direction = '"+ComboBox2->Text+"' JOIN Subjects S ON S.SubjectId = T.SubjectId JOIN Teachers Te ON Te.TeacherId = T.TeacherId JOIN TypesOfLesson Ty ON Ty.TypeOfLessonId = T.TypeOfLessonId JOIN Classrooms C ON C.ClassroomId = T.ClassroomId WHERE T.Date = '"+StringDays[i]+"' AND T.Pair = '"+Pairs[j]+"' AND T.FacultyId = F.FacultyId AND T.DirectionId = D.DirectionId AND T.Course = '"+IntToStr(ComboBox3->ItemIndex + 1)+"'");
			ADOQuery1->Open();
//          int FacultyId = ADOQuery1->FieldByName("FacultyId")->AsInteger;
//			int DirectionId = ADOQuery1->FieldByName("DirectionId")->AsInteger;
//			int SubjectId = ADOQuery1->FieldByName("SubjectId")->AsInteger;
//			int TeacherId = ADOQuery1->FieldByName("TeacherId")->AsInteger;
//			int TypeOfLessonId = ADOQuery1->FieldByName("TypeOfLessonId")->AsInteger;
//			int ClassroomId = ADOQuery1->FieldByName("ClassroomId")->AsInteger;
			((TLabel*)FindComponent("Label" + IntToStr(i * 20 + j * 4 + 126)))->Caption = ADOQuery1->FieldByName("Subject")->AsString;
			((TLabel*)FindComponent("Label" + IntToStr(i * 20 + j * 4 + 127)))->Caption = ADOQuery1->FieldByName("Teacher")->AsString;
			((TLabel*)FindComponent("Label" + IntToStr(i * 20 + j * 4 + 128)))->Caption = ADOQuery1->FieldByName("TypeOfLesson")->AsString;
	 		((TLabel*)FindComponent("Label" + IntToStr(i * 20 + j * 4 + 129)))->Caption = ADOQuery1->FieldByName("Classroom")->AsString;
		}
	}
    ScrollBoxTimeTable->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TStudentsWindow::ComboBox1DropDown(TObject *Sender)
{
	ComboBox1->Items->Clear();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT Faculty FROM Faculties");
	ADOQuery1->Open(); ADOQuery1->First();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox1->Items->Add(ADOQuery1->FieldByName("Faculty")->AsString); ADOQuery1->Next();
	}
}
//---------------------------------------------------------------------------
void __fastcall TStudentsWindow::ComboBox1Select(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT D.Direction FROM Directions D JOIN Faculties F ON D.FacultyId = F.FacultyId WHERE F.Faculty = '"+ComboBox1->Text+"'");
	ADOQuery1->Open(); ComboBox2->Text = ADOQuery1->Fields->Fields[0]->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TStudentsWindow::ComboBox2DropDown(TObject *Sender)
{
    ComboBox2->Items->Clear();
    ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT D.Direction FROM Directions D JOIN Faculties F ON D.FacultyId = F.FacultyId WHERE F.Faculty = '"+ComboBox1->Text+"'");
	ADOQuery1->Open();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
        ComboBox2->Items->Add(ADOQuery1->FieldByName("Direction")->AsString); ADOQuery1->Next();
    }
}
//---------------------------------------------------------------------------



