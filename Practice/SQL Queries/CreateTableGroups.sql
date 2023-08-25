USE MSUDB

CREATE TABLE Groups
(
	GropuId int identity(1,1) primary key,
	FacultyId int,
	FOREIGN KEY (FacultyId) REFERENCES Faculties(FacultyId),
	DirectionId int,
	FOREIGN KEY (DirectionId) REFERENCES Directions(DirectionId),
	Course int,
	CONSTRAINT UniqueColumnsForGroups UNIQUE(FacultyId, DirectionId, Course)
);