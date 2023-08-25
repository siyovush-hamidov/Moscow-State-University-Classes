use MSUDB

CREATE TABLE GroupIsEngaged
(
	GroupId INT,
	FOREIGN KEY(GroupId) REFERENCES Groups(GroupId),
	FacultyId INT,
	FOREIGN KEY(FacultyId) REFERENCES Faculties(FacultyId),
	DirectionId INT,
	FOREIGN KEY(DirectionId) REFERENCES Directions(DirectionId),
	Date DATE,
	Pair INT,
	IsEngaged BIT,
);