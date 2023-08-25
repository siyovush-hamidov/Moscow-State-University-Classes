use MSUDB

CREATE TABLE TeacherSubjects (
    TeacherId INT,
    SubjectId INT,
    FOREIGN KEY (TeacherId) REFERENCES Teachers(TeacherId),
    FOREIGN KEY (SubjectId) REFERENCES Subjects(SubjectId),
	CONSTRAINT UC_TeacherSubjects UNIQUE(TeacherId, SubjectId)
);