use MSUDB

create table TypesOfLesson
(
	TypeOfLessonId int identity(1,1) primary key,
	TypeOfLesson varchar(40)
);

/*ALTER TABLE TimeTable
ADD FOREIGN KEY(TypeOfLessonId) REFERENCES TypesOfLesson(TypeOfLessonId)