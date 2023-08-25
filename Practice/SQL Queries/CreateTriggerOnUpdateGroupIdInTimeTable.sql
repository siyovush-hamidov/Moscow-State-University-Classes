CREATE TRIGGER UpdateGroupId
ON TimeTable
AFTER UPDATE
AS
BEGIN
    IF UPDATE(FacultyId) OR UPDATE(DirectionId) OR UPDATE(Course)
    BEGIN
        UPDATE TimeTable
        SET GroupId = Groups.GroupId
        FROM TimeTable
        INNER JOIN Groups
        ON TimeTable.FacultyId = Groups.FacultyId AND TimeTable.DirectionId = Groups.DirectionId AND TimeTable.Course = Groups.Course
        WHERE TimeTable.LessonId IN (SELECT LessonId FROM inserted)
    END
END;
