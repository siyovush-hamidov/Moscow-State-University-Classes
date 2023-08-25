USE MSUDB

CREATE TABLE Attendance
(
	AttendanceId int identity(1,1) not null,
	Date date,
	Pair int,
	StudId int
);

ALTER TABLE Attendance ADD CONSTRAINT fk_attendanceToStudId FOREIGN KEY (StudId) REFERENCES Students (StudId);