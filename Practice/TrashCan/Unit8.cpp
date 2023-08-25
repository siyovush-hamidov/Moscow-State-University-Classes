//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit8.h"
#include "Unit1.h"
#include "Unit4.h"

#include <iostream>
#include <vcl.h>
#include <System.SysUtils.hpp>
#include <System.DateUtils.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStaffWindow *StaffWindow;
//---------------------------------------------------------------------------
__fastcall TStaffWindow::TStaffWindow(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TStaffWindow::ComboBox1DropDown(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select * from Faculties");
	ADOQuery1->Open(); ADOQuery1->First();

	ComboBox1->Items->Clear();

	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox1->Items->Add(ADOQuery1->FieldByName("Faculty")->AsString);
		ADOQuery1->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TStaffWindow::ComboBox2DropDown(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT FacultyId FROM Faculties WHERE Faculty = :Faculty");
	ADOQuery1->Parameters->ParamByName("Faculty")->Value = ComboBox1->Text;
	ADOQuery1->Open();
	int IntFacultyId = ADOQuery1->Fields->Fields[0]->AsInteger;

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT * FROM Directions WHERE FacultyId = :FacultyId");
	ADOQuery1->Parameters->ParamByName("FacultyId")->Value = IntToStr(IntFacultyId);
	ADOQuery1->Open();
	ComboBox2->Text = ADOQuery1->FieldByName("Direction")->AsString;
	ComboBox2->Items->Clear();

	while (!ADOQuery1->Eof) {
		ComboBox2->Items->Add(ADOQuery1->FieldByName("Direction")->AsString);
		ADOQuery1->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TStaffWindow::ComboBox3DropDown(TObject *Sender)
{
	ComboBox3->Items->Strings[0] = "1-й курс";
	ComboBox3->Items->Strings[1] = "2-й курс";
	ComboBox3->Items->Strings[2] = "3-й курс";
	ComboBox3->Items->Strings[3] = "4-й курс";

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT GroupIsEngaged.Course FROM GroupIsEngaged JOIN Directions ON GroupIsEngaged.DirectionId = Directions.DirectionId JOIN Faculties ON GroupIsEngaged.FacultyId = Faculties.FacultyId WHERE Faculties.Faculty = :Faculty AND Directions.Direction = :Direction AND GroupIsEngaged.Date = :Date AND GroupIsEngaged.Pair = :Pair AND GroupIsEngaged.IsEngaged = 1");
	ADOQuery1->Parameters->ParamByName("Faculty")->Value = ComboBox1->Text;
	ADOQuery1->Parameters->ParamByName("Direction")->Value = ComboBox2->Text;
	ADOQuery1->Parameters->ParamByName("Date")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker1->Date);
	ADOQuery1->Parameters->ParamByName("Pair")->Value = ComboBox4->ItemIndex + 1;
	ADOQuery1->Open();

	TStringList *EngagedCourseIds = new TStringList;
	while (!ADOQuery1->Eof) {
		EngagedCourseIds->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}

	for (int i = 0; i < EngagedCourseIds->Count; i++) {
		String temp = ComboBox3->Items->Strings[StrToInt(EngagedCourseIds->Strings[i]) - 1];
		ComboBox3->Items->Strings[StrToInt(EngagedCourseIds->Strings[i]) - 1] = temp + " (Группе уже назначена пара)";
	}
}

//---------------------------------------------------------------------------

void __fastcall TStaffWindow::ComboBox5DropDown(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT ClassroomId FROM ClassroomIsEngaged WHERE Date = :Date AND Pair = :Pair AND IsEngaged = 1");
	ADOQuery1->Parameters->ParamByName("Date")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker1->Date);
	ADOQuery1->Parameters->ParamByName("Pair")->Value = ComboBox4->ItemIndex + 1;
	ADOQuery1->Open();

	TStringList *EngagedClassroomIds = new TStringList;
	while (!ADOQuery1->Eof) {
		EngagedClassroomIds->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT * FROM Classrooms");
	ADOQuery1->Open();

	ComboBox5->Items->Clear();

	for (int i = 0; i < ADOQuery1->RecordCount; i++) {
		String ClassroomName = ADOQuery1->FieldByName("Classroom")->AsString;
		String ClassroomId = ADOQuery1->FieldByName("ClassroomId")->AsString;
		if (EngagedClassroomIds->IndexOf(ClassroomId) != -1) {
			ClassroomName += " (Аудитория занята)";
		}
		ComboBox5->Items->Add(ClassroomName);
		ADOQuery1->Next();
	}
}

//---------------------------------------------------------------------------

void __fastcall TStaffWindow::ComboBox6DropDown(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT TeacherId FROM TeacherIsEngaged WHERE Date = :Date AND Pair = :Pair AND IsEngaged = 1");
	ADOQuery1->Parameters->ParamByName("Date")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker1->Date);
	ADOQuery1->Parameters->ParamByName("Pair")->Value = ComboBox4->ItemIndex + 1;
	ADOQuery1->Open();

	TStringList *EngagedTeacherIds = new TStringList;
	while (!ADOQuery1->Eof) {
		EngagedTeacherIds->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT * FROM Teachers");
	ADOQuery1->Open();

	ComboBox6->Items->Clear();

	for (int i = 0; i < ADOQuery1->RecordCount; i++) {
		String TeacherName = ADOQuery1->FieldByName("Teacher")->AsString;
		String TeacherId = ADOQuery1->FieldByName("TeacherId")->AsString;
		if (EngagedTeacherIds->IndexOf(TeacherId) != -1) {
			TeacherName += " (Преподаватель занят)";
		}
		ComboBox6->Items->Add(TeacherName);
		ADOQuery1->Next();
	}
}

//---------------------------------------------------------------------------

void __fastcall TStaffWindow::ComboBox6Select(TObject *Sender)
{
    ComboBox7->Enabled = true;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select TeacherId from Teachers where Teacher = '"+ComboBox6->Text+"'");
	ADOQuery1->Open();
	int IntTeacherId = ADOQuery1->Fields->Fields[0]->AsInteger;

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select SubjectId from TeacherSubjects where TeacherId = '"+IntToStr(IntTeacherId)+"' ");
	ADOQuery1->Open();
	int FirstSubjectIdOfTheTeacher = ADOQuery1->Fields->Fields[0]->AsInteger;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select Subject from Subjects where SubjectId = '"+IntToStr(FirstSubjectIdOfTheTeacher)+"'");
	ADOQuery1->Open();
	ComboBox7->Text = ADOQuery1->Fields->Fields[0]->AsString;
}
//---------------------------------------------------------------------------


void __fastcall TStaffWindow::ComboBox7DropDown(TObject *Sender)
{
	String TeachersName = ComboBox6->Text;
	String SubString = L" (Преподаватель занят)";

	int pos = TeachersName.Pos(SubString);
	if(pos > 0)
	{
		TeachersName.Delete(pos, SubString.Length());
	}

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select TeacherId from Teachers where Teacher = '"+TeachersName+"'");
	ADOQuery1->Open();
	int IntTeacherId = ADOQuery1->Fields->Fields[0]->AsInteger;

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select Subject from Subjects where SubjectId in (select SubjectId from TeacherSubjects where TeacherId = '"+IntToStr(IntTeacherId)+"')");
	ADOQuery1->Open();

	ComboBox7->Items->Clear();
	while(!ADOQuery1->Eof)
	{
		ComboBox7->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}
}
//---------------------------------------------------------------------------


void __fastcall TStaffWindow::FormCreate(TObject *Sender)
{
	TDateTime date = DateTimePicker1->Date;
	int dayOfWeek = DayOfWeek(date);
	switch(dayOfWeek)
	{
		case 1: Label4->Caption = "Дата (день недели: воскресенье)"; break;
		case 2: Label4->Caption = "Дата (день недели: понедельник)"; break;
		case 3: Label4->Caption = "Дата (день недели: вторник)";     break;
		case 4: Label4->Caption = "Дата (день недели: среда)";       break;
		case 5: Label4->Caption = "Дата (день недели: четверг)";     break;
		case 6: Label4->Caption = "Дата (день недели: пятница)";     break;
		case 7: Label4->Caption = "Дата (день недели: суббота)";     break;
	}
	DateTimePicker1->Date = Date();
    DateTimePicker2->Date = Date();
}
//---------------------------------------------------------------------------


void __fastcall TStaffWindow::DateTimePicker1Change(TObject *Sender)
{
	TDateTime date = DateTimePicker1->Date;
	int dayOfWeek = DayOfWeek(date);

	switch(dayOfWeek)
	{
		case 1: Label4->Caption = "Дата (день недели: воскресенье)"; break;
		case 2: Label4->Caption = "Дата (день недели: понедельник)"; break;
		case 3: Label4->Caption = "Дата (день недели: вторник)";     break;
		case 4: Label4->Caption = "Дата (день недели: среда)";       break;
		case 5: Label4->Caption = "Дата (день недели: четверг)";     break;
		case 6: Label4->Caption = "Дата (день недели: пятница)";     break;
		case 7: Label4->Caption = "Дата (день недели: суббота)";     break;
	}
}
//---------------------------------------------------------------------------

//КНОПКА ДОБАВИТЬ
void __fastcall TStaffWindow::Button3Click(TObject *Sender)
{
	if(ComboBox1->Text == "" ||
	   ComboBox2->Text == "" ||
	   ComboBox3->Text == "" ||
	   ComboBox4->Text == "" ||
	   ComboBox5->Text == "" ||
	   ComboBox6->Text == "" ||
	   ComboBox7->Text == "" ||
	   ComboBox8->Text == "")
	   {
			MessageDlg("Заполните все поля!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);
	   }
	   else
	   {
		   //DirectionId
		   ADOQuery1->SQL->Clear();
		   ADOQuery1->SQL->Add("SELECT DirectionId FROM Directions WHERE Direction = '"+ComboBox2->Text+"'");
		   ADOQuery1->Open(); int DirectionId = ADOQuery1->Fields->Fields[0]->AsInteger;
		   //FacultyId
		   ADOQuery1->SQL->Clear();
		   ADOQuery1->SQL->Add("SELECT FacultyId FROM Faculties WHERE Faculty = '"+ComboBox1->Text+"'");
		   ADOQuery1->Open(); int FacultyId = ADOQuery1->Fields->Fields[0]->AsInteger;
		   //ClassRoomId
		   String ClassroomName = ComboBox5->Text;
		   String SubStringForClassroom = L" (Аудитория занята)";
			int posForClassroom = ClassroomName.Pos(SubStringForClassroom);
			if(posForClassroom > 0)
			{
				ClassroomName.Delete(posForClassroom, SubStringForClassroom.Length());
			}
		   ADOQuery1->SQL->Clear();
		   ADOQuery1->SQL->Add("SELECT ClassroomId FROM Classrooms WHERE Classroom = '"+ClassroomName+"'");
		   ADOQuery1->Open(); int ClassroomId = ADOQuery1->Fields->Fields[0]->AsInteger;
		   //TeacherId
		   String TeacherName = ComboBox6->Text;
		   String SubStringForTeacher = L" (Преподаватель занят)";
			int posForTeacher = TeacherName.Pos(SubStringForTeacher);
			if(posForTeacher > 0)
			{
				TeacherName.Delete(posForTeacher, SubStringForTeacher.Length());
			}
		   ADOQuery1->SQL->Clear();
		   ADOQuery1->SQL->Add("SELECT TeacherId FROM Teachers WHERE Teacher = '"+TeacherName+"'");
		   ADOQuery1->Open(); int TeacherId = ADOQuery1->Fields->Fields[0]->AsInteger;
		   //SubjectId
		   ADOQuery1->SQL->Clear();
		   ADOQuery1->SQL->Add("SELECT SubjectId FROM Subjects WHERE Subject = '"+ComboBox7->Text+"'");
		   ADOQuery1->Open(); int SubjectId = ADOQuery1->Fields->Fields[0]->AsInteger;
		   //GroupId
		   ADOQuery1->SQL->Clear();
		   ADOQuery1->SQL->Add("SELECT GroupId FROM Groups WHERE FacultyId = '"+IntToStr(FacultyId)+"' AND DirectionId = '"+IntToStr(DirectionId)+"' AND Course = '"+IntToStr(ComboBox3->ItemIndex + 1)+"'");
		   ADOQuery1->Open(); int GroupId = ADOQuery1->Fields->Fields[0]->AsInteger;
		   //INSERT INTO Расписание
		   String DateString = FormatDateTime("yyyy-mm-dd", DateTimePicker1->Date);
		   ADOQuery1->SQL->Clear();
		   ADOQuery1->SQL->Add("INSERT INTO TimeTable(Date, FacultyId, DirectionId, Course, Pair, ClassroomId, TeacherId, SubjectId, TypeOfLessonId, GroupId) VALUES(:Date, :FacultyId, :DirectionId, :Course, :Pair, :ClassroomId, :TeacherId, :SubjectId, :TypeOfLessonId, :GroupId)");
		   ADOQuery1->Parameters->ParamByName("Date")->Value = DateString;
		   ADOQuery1->Parameters->ParamByName("FacultyId")->Value = FacultyId;
		   ADOQuery1->Parameters->ParamByName("DirectionId")->Value = StrToInt(DirectionId);
		   ADOQuery1->Parameters->ParamByName("Course")->Value = ComboBox3->ItemIndex + 1;
		   ADOQuery1->Parameters->ParamByName("Pair")->Value = ComboBox4->ItemIndex + 1;
		   ADOQuery1->Parameters->ParamByName("ClassroomId")->Value = ClassroomId;
		   ADOQuery1->Parameters->ParamByName("TeacherId")->Value = TeacherId;
		   ADOQuery1->Parameters->ParamByName("SubjectId")->Value = SubjectId;
		   ADOQuery1->Parameters->ParamByName("TypeOfLessonId")->Value = ComboBox8->ItemIndex + 1;
		   ADOQuery1->Parameters->ParamByName("GroupId")->Value = GroupId;
		   ADOQuery1->ExecSQL();

		   this->Button1Click(Sender); // Вызов Button1Click
	   }
}
//---------------------------------------------------------------------------

void __fastcall TStaffWindow::Button1Click(TObject *Sender)
{
	ComboBox1->ItemIndex = -1;
	ComboBox2->ItemIndex = -1; ComboBox2->Enabled = false;
	ComboBox3->ItemIndex = -1;
	ComboBox4->ItemIndex = -1;
	ComboBox5->ItemIndex = -1;
	ComboBox6->ItemIndex = -1; ComboBox6->Enabled = false;
	ComboBox7->ItemIndex = -1;
	ComboBox8->ItemIndex = -1;
}
//---------------------------------------------------------------------------

void __fastcall TStaffWindow::Label13Click(TObject *Sender)
{
	LessonConstructor->Visible = true;
	LessonEditor->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TStaffWindow::Label13MouseEnter(TObject *Sender)
{
    VirtualImage4->ImageName = "WhiteBackground";
	Label13->Font->Color = clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TStaffWindow::Label13MouseLeave(TObject *Sender)
{
    VirtualImage4->ImageName = "BlueBackground";
	Label13->Font->Color = clWhite;
}
//---------------------------------------------------------------------------


//====================================================================
//====================================================================
//====================================================================
// ИЗМЕНЕНИЕ РАСПИСАНИЯ ИЗМЕНЕНИЕ РАСПИСАНИЯ

void __fastcall TStaffWindow::Label1Click(TObject *Sender)
{
	LessonEditor->Visible = true;
    LessonConstructor->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TStaffWindow::ComboBox10DropDown(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select Faculty from Faculties");
	ADOQuery1->Open(); ComboBox10->Items->Clear();
    ComboBox10->Text = ADOQuery1->Fields->Fields[0]->AsString;

	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox10->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TStaffWindow::Button2Click(TObject *Sender)
{
	ComboBox9->ClearSelection();
	ComboBox14->ClearSelection();
	ComboBox15->ClearSelection();
	ComboBox16->ClearSelection();
	ComboBox17->ClearSelection();
	ComboBox18->ClearSelection();
	ComboBox19->ClearSelection();
	ComboBox20->ClearSelection();
}
//---------------------------------------------------------------------------

void __fastcall TStaffWindow::ComboBox10Select(TObject *Sender)
{
	ComboBox11->Enabled = true;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT D.Direction FROM Directions D JOIN Faculties F ON F.FacultyId = D.FacultyId WHERE F.Faculty = '"+ComboBox10->Text+"'");
	ADOQuery1->Open();
	ComboBox11->Text = ADOQuery1->Fields->Fields[0]->AsString;
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox11->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}

	this->ComboBox13Select(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TStaffWindow::ComboBox13Select(TObject *Sender)
{
    ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT TT.TypeOfLessonId, TT.Course, TT.Date, TT.Pair, F.Faculty, D.Direction, CR.Classroom, T.Teacher, S.Subject, TL.TypeOfLesson FROM TimeTable TT JOIN Faculties F ON TT.FacultyId = (SELECT FacultyId FROM Faculties WHERE Faculty = '"+ComboBox10->Text+"') JOIN Directions D ON TT.DirectionId = (SELECT DirectionId FROM Directions WHERE Direction = '"+ComboBox11->Text+"') JOIN Classrooms CR ON CR.ClassroomId = TT.ClassroomId JOIN Teachers T ON TT.TeacherId = T.TeacherId JOIN TypesOfLesson TL ON TT.TypeOfLessonId = TL.TypeOfLessonId JOIN Subjects S ON TT.SubjectId = S.SubjectId WHERE TT.Pair = '"+IntToStr(ComboBox13->ItemIndex + 1)+"' AND TT.Date = '"+FormatDateTime("yyyy-mm-dd", DateTimePicker2->Date)+"' AND TT.Course = '"+IntToStr(ComboBox12->ItemIndex + 1)+"' ");
	ADOQuery1->Open();

	if(!ADOQuery1->IsEmpty())
	{
        bool Enabled = true;
		DateTimePicker3->Enabled = true;
		ComboBox9->Enabled = true;
		ComboBox14->Enabled = true;
		ComboBox15->Enabled = true;
		ComboBox16->Enabled = true;
		ComboBox17->Enabled = true;
		ComboBox18->Enabled = true;
		ComboBox19->Enabled = true;
		ComboBox20->Enabled = true;
		Label2->Enabled = true;
		Label18->Enabled = true;
		Label19->Enabled = true;
		Label20->Enabled = true;
		Label21->Enabled = true;
		Label22->Enabled = true;
		Label23->Enabled = true;
		Label24->Enabled = true;
		Label25->Enabled = true;
		Button2->Enabled = true;
		Button4->Enabled = true;

		Label2->Caption = "Дата ("+ADOQuery1->FieldByName("Date")->AsString+")";

		TDateTime DateValue = VarToDateTime(ADOQuery1->FieldByName("Date")->AsString);
		DateTimePicker3->Date = DateValue;

		Label22->Caption = "Пара ("+ADOQuery1->FieldByName("Pair")->AsString+"-я)";
		Label23->Caption = "Факультет ("+ADOQuery1->FieldByName("Faculty")->AsString+")";
		Label24->Caption = "Направление ("+ADOQuery1->FieldByName("Direction")->AsString+")";
		Label25->Caption = "Курс ("+ADOQuery1->FieldByName("Course")->AsString+"-й)";
		Label18->Caption = "Аудитория ("+ADOQuery1->FieldByName("ClassRoom")->AsString+")";
		Label19->Caption = "Преподаватель ("+ADOQuery1->FieldByName("Teacher")->AsString+")";
		Label20->Caption = "Дисциплина ("+ADOQuery1->FieldByName("Subject")->AsString+")";
		Label21->Caption = "Тип Занятия ("+ADOQuery1->FieldByName("TypeOfLesson")->AsString+")";
	}
	else
	{
		Label2->Caption = "Дата";
		Label22->Caption = "Пара";
		Label23->Caption = "Факультет";
		Label24->Caption = "Направление";
		Label25->Caption = "Курс";
		Label18->Caption = "Аудитория";
		Label19->Caption = "Преподаватель";
		Label20->Caption = "Дисциплина";
		Label21->Caption = "Тип Занятия";
		DateTimePicker3->Enabled = false;
		ComboBox9->Enabled = false;
		ComboBox14->Enabled = false;
		ComboBox15->Enabled = false;
		ComboBox16->Enabled = false;
		ComboBox17->Enabled = false;
		ComboBox18->Enabled = false;
		ComboBox19->Enabled = false;
		ComboBox20->Enabled = false;
		Label2->Enabled = false;
		Label18->Enabled = false;
		Label19->Enabled = false;
		Label20->Enabled = false;
		Label21->Enabled = false;
		Label22->Enabled = false;
		Label23->Enabled = false;
		Label24->Enabled = false;
		Label25->Enabled = false;
		Button2->Enabled = false;
		Button4->Enabled = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TStaffWindow::Button4Click(TObject *Sender)
{
	if(ComboBox9->Text == ""  ||
	   ComboBox14->Text == "" ||
	   ComboBox15->Text == "" ||
	   ComboBox16->Text == "" ||
	   ComboBox17->Text == "" ||
	   ComboBox18->Text == "" ||
	   ComboBox19->Text == "" ||
	   ComboBox20->Text == "") MessageDlg("Заполните все поля!", TMsgDlgType(mtInformation), TMsgDlgButtons() << mbOK, 0);

	else
	{
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("UPDATE TimeTable SET Date = :Date, Pair = :Pair, FacultyId = (SELECT FacultyId FROM Faculties WHERE Faculty = :Faculty), DirectionId = (SELECT DirectionId FROM Directions WHERE Direction = :Direction), Course = :Course, ClassroomId = (SELECT ClassroomId FROM Classrooms WHERE Classroom = :Classroom), TeacherId = (SELECT TeacherId FROM Teachers WHERE Teacher = :Teacher), SubjectId = (SELECT SubjectId FROM Subjects WHERE Subject = :Subject), TypeOfLessonId = (SELECT TypeOfLessonId FROM TypesOfLesson WHERE TypeOfLesson = :TypeOfLesson) WHERE LessonId = (SELECT LessonId FROM TimeTable WHERE Date = :InitialDate AND Pair = :InitialPair AND FacultyId = (SELECT FacultyId FROM Faculties WHERE Faculty = :InitialFaculty) AND DirectionId = (SELECT DirectionId FROM Directions WHERE Direction = :InitialDirection) AND Course = :InitialCourse)");

		ADOQuery1->Parameters->ParamByName("InitialDate")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker2->Date);
		ADOQuery1->Parameters->ParamByName("InitialPair")->Value = ComboBox13->ItemIndex + 1;
		ADOQuery1->Parameters->ParamByName("InitialFaculty")->Value = ComboBox10->Text;
		ADOQuery1->Parameters->ParamByName("InitialDirection")->Value = ComboBox11->Text;
		ADOQuery1->Parameters->ParamByName("InitialCourse")->Value = ComboBox12->ItemIndex + 1;

		//ИЗБАВЛЕНИЕ ОТ (ЗАНЯТ)
		String ClassroomsName = ComboBox14->Text; String ClassroomsSubString = L" (Аудитория занята)";
		String TeachersName = ComboBox15->Text; String TeachersSubString = L" (Преподаватель занят)";
		int Tpos = TeachersName.Pos(TeachersSubString); if(Tpos > 0) TeachersName.Delete(Tpos, TeachersSubString.Length());
		int Cpos = ClassroomsName.Pos(ClassroomsSubString); if(Cpos > 0) ClassroomsName.Delete(Cpos, ClassroomsSubString.Length());

		ADOQuery1->Parameters->ParamByName("Date")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker3->Date);
		ADOQuery1->Parameters->ParamByName("Pair")->Value = IntToStr(ComboBox9->ItemIndex + 1);
		ADOQuery1->Parameters->ParamByName("Faculty")->Value = ComboBox18->Text;
		ADOQuery1->Parameters->ParamByName("Direction")->Value = ComboBox19->Text;
		ADOQuery1->Parameters->ParamByName("Course")->Value = IntToStr(ComboBox20->ItemIndex + 1);
		ADOQuery1->Parameters->ParamByName("Classroom")->Value = ClassroomsName;
		ADOQuery1->Parameters->ParamByName("Teacher")->Value = TeachersName;
		ADOQuery1->Parameters->ParamByName("Subject")->Value = ComboBox17->Text;
		ADOQuery1->Parameters->ParamByName("TypeOfLesson")->Value = ComboBox16->Text;

		ADOQuery1->ExecSQL();

        this->Button2Click(Sender);
    }
}
//---------------------------------------------------------------------------

void __fastcall TStaffWindow::ComboBox18DropDown(TObject *Sender)
{
	ADOQuery1->SQL->Clear(); ComboBox18->Clear();
	ADOQuery1->SQL->Add("SELECT Faculty FROM Faculties"); ADOQuery1->Open();
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox18->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
        ADOQuery1->Next();
    }
}
//---------------------------------------------------------------------------

void __fastcall TStaffWindow::ComboBox18Select(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT D.Direction FROM Directions D JOIN Faculties F ON F.FacultyId = D.FacultyId WHERE F.Faculty = '"+ComboBox18->Text+"'");
	ADOQuery1->Open();
	ComboBox19->Text = ADOQuery1->Fields->Fields[0]->AsString;
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox19->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}

}
//---------------------------------------------------------------------------


void __fastcall TStaffWindow::ComboBox15DropDown(TObject *Sender)
{
    ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT T.TeacherId FROM TeacherIsEngaged T WHERE T.Date = :Date AND T.Pair = :Pair AND T.IsEngaged = 1");
	ADOQuery1->Parameters->ParamByName("Date")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker3->Date);
	ADOQuery1->Parameters->ParamByName("Pair")->Value = ComboBox9->ItemIndex + 1;
	ADOQuery1->Open();

	TStringList *EngagedTeacherIds = new TStringList;
	while (!ADOQuery1->Eof) {
		EngagedTeacherIds->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
    }

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT * FROM Teachers");
	ADOQuery1->Open();

	ComboBox15->Items->Clear();

	for (int i = 0; i < ADOQuery1->RecordCount; i++) {
		String TeacherName = ADOQuery1->FieldByName("Teacher")->AsString;
		String TeacherId = ADOQuery1->FieldByName("TeacherId")->AsString;
		if (EngagedTeacherIds->IndexOf(TeacherId) != -1) {
			TeacherName += " (Преподаватель занят)";
		}
		ComboBox15->Items->Add(TeacherName);
		ADOQuery1->Next();
	}

}
//---------------------------------------------------------------------------

void __fastcall TStaffWindow::ComboBox14DropDown(TObject *Sender)
{
    ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT ClassroomId FROM ClassroomIsEngaged WHERE Date = :Date AND Pair = :Pair AND IsEngaged = 1");
	ADOQuery1->Parameters->ParamByName("Date")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker3->Date);
	ADOQuery1->Parameters->ParamByName("Pair")->Value = ComboBox9->ItemIndex + 1;
	ADOQuery1->Open();

	TStringList *EngagedClassroomIds = new TStringList;
	while (!ADOQuery1->Eof) {
		EngagedClassroomIds->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT * FROM Classrooms");
	ADOQuery1->Open();

	ComboBox14->Items->Clear();

	for (int i = 0; i < ADOQuery1->RecordCount; i++) {
		String ClassroomName = ADOQuery1->FieldByName("Classroom")->AsString;
		String ClassroomId = ADOQuery1->FieldByName("ClassroomId")->AsString;
		if (EngagedClassroomIds->IndexOf(ClassroomId) != -1) {
			ClassroomName += " (Аудитория занята)";
		}
		ComboBox14->Items->Add(ClassroomName);
		ADOQuery1->Next();
	}

}
//---------------------------------------------------------------------------

void __fastcall TStaffWindow::ComboBox20DropDown(TObject *Sender)
{
	ComboBox20->Items->Strings[0] = "1-й курс";
	ComboBox20->Items->Strings[1] = "2-й курс";
	ComboBox20->Items->Strings[2] = "3-й курс";
	ComboBox20->Items->Strings[3] = "4-й курс";

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT GroupIsEngaged.Course FROM GroupIsEngaged JOIN Directions ON GroupIsEngaged.DirectionId = Directions.DirectionId JOIN Faculties ON GroupIsEngaged.FacultyId = Faculties.FacultyId WHERE Faculties.Faculty = :Faculty AND Directions.Direction = :Direction AND GroupIsEngaged.Date = :Date AND GroupIsEngaged.Pair = :Pair AND GroupIsEngaged.IsEngaged = 1");
	ADOQuery1->Parameters->ParamByName("Faculty")->Value = ComboBox18->Text;
	ADOQuery1->Parameters->ParamByName("Direction")->Value = ComboBox19->Text;
	ADOQuery1->Parameters->ParamByName("Date")->Value = FormatDateTime("yyyy-mm-dd", DateTimePicker3->Date);
	ADOQuery1->Parameters->ParamByName("Pair")->Value = ComboBox9->ItemIndex + 1;
	ADOQuery1->Open();

	TStringList *EngagedCourseIds = new TStringList;
	while (!ADOQuery1->Eof) {
		EngagedCourseIds->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}

	for (int i = 0; i < EngagedCourseIds->Count; i++) {
		String temp = ComboBox20->Items->Strings[StrToInt(EngagedCourseIds->Strings[i]) - 1];
		ComboBox20->Items->Strings[StrToInt(EngagedCourseIds->Strings[i]) - 1] = temp + " (Группе уже назначена пара)";
}

//---------------------------------------------------------------------------
}
void __fastcall TStaffWindow::ComboBox11DropDown(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT FacultyId FROM Faculties WHERE Faculty = :Faculty");
	ADOQuery1->Parameters->ParamByName("Faculty")->Value = ComboBox10->Text;
	ADOQuery1->Open();
	int IntFacultyId = ADOQuery1->Fields->Fields[0]->AsInteger;

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT * FROM Directions WHERE FacultyId = :FacultyId");
	ADOQuery1->Parameters->ParamByName("FacultyId")->Value = IntToStr(IntFacultyId);
	ADOQuery1->Open();
	ComboBox11->Items->Clear(); ComboBox11->Text = ADOQuery1->Fields->Fields[0]->AsString;

	while (!ADOQuery1->Eof) {
		ComboBox11->Items->Add(ADOQuery1->FieldByName("Direction")->AsString);
		ADOQuery1->Next();
	}


}
//---------------------------------------------------------------------------

void __fastcall TStaffWindow::ComboBox17DropDown(TObject *Sender)
{
	String TeachersName = ComboBox15->Text;
	String SubString = L" (Преподаватель занят)";

	int pos = TeachersName.Pos(SubString);
	if(pos > 0)
	{
		TeachersName.Delete(pos, SubString.Length());
	}

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select TeacherId from Teachers where Teacher = '"+TeachersName+"'");
	ADOQuery1->Open();
	int IntTeacherId = ADOQuery1->Fields->Fields[0]->AsInteger;

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("select Subject from Subjects where SubjectId in (select SubjectId from TeacherSubjects where TeacherId = '"+IntToStr(IntTeacherId)+"')");
	ADOQuery1->Open();

	ComboBox17->Items->Clear();
	while(!ADOQuery1->Eof)
	{
		ComboBox17->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}

}
//---------------------------------------------------------------------------



void __fastcall TStaffWindow::ComboBox19DropDown(TObject *Sender)
{
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT FacultyId FROM Faculties WHERE Faculty = :Faculty");
	ADOQuery1->Parameters->ParamByName("Faculty")->Value = ComboBox18->Text;
	ADOQuery1->Open();
	int IntFacultyId = ADOQuery1->Fields->Fields[0]->AsInteger;

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT * FROM Directions WHERE FacultyId = :FacultyId");
	ADOQuery1->Parameters->ParamByName("FacultyId")->Value = IntToStr(IntFacultyId);
	ADOQuery1->Open();
	ComboBox19->Text = ADOQuery1->FieldByName("Direction")->AsString;
	ComboBox19->Items->Clear();

	while (!ADOQuery1->Eof) {
		ComboBox19->Items->Add(ADOQuery1->FieldByName("Direction")->AsString);
		ADOQuery1->Next();
	}


}
//---------------------------------------------------------------------------



void __fastcall TStaffWindow::ComboBox1Select(TObject *Sender)
{
    ComboBox2->Enabled = true;
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add("SELECT D.Direction FROM Directions D JOIN Faculties F ON F.FacultyId = D.FacultyId WHERE F.Faculty = '"+ComboBox1->Text+"'");
	ADOQuery1->Open();
	ComboBox2->Text = ADOQuery1->Fields->Fields[0]->AsString;
	for(int i = 0; i < ADOQuery1->RecordCount; i++)
	{
		ComboBox2->Items->Add(ADOQuery1->Fields->Fields[0]->AsString);
		ADOQuery1->Next();
	}
}
//---------------------------------------------------------------------------

