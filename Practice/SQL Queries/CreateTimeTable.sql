use MSUDB

/*GO

CREATE TABLE TimeTable
(
	LessonId int identity(1,1) primary key,
    Date date,
    DayOfWeek VARCHAR(20),
	FacultyId int,
    DirectionId int,
    Course int,
    Pair int,
    ClassroomId int,
    TeacherId int,
	SubjectId int,
    TypeOfLessonId int,
    NumberOfWeek INT
);


ALTER TABLE TimeTable
ADD GroupId int;

ALTER TABLE TimeTable
ADD FOREIGN KEY (FacultyId) REFERENCES Faculties(FacultyId)

ALTER TABLE TimeTable
ADD FOREIGN KEY (DirectionId) REFERENCES Directions(DirectionId)

ALTER TABLE TimeTable
ADD FOREIGN KEY (GroupId) REFERENCES Groups(GroupId)

ALTER TABLE TimeTable
ADD FOREIGN KEY (ClassroomId) REFERENCES Classrooms(ClassroomId)

ALTER TABLE TimeTable
ADD FOREIGN KEY (TeacherId) REFERENCES Teachers(TeacherId)

ALTER TABLE TimeTable
ADD FOREIGN KEY (SubjectId) REFERENCES Subjects(SubjectId)
*/


