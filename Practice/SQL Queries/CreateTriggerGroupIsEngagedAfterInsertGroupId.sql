CREATE TRIGGER update_GroupIsEngaged
ON GroupIsEngaged
AFTER INSERT
AS
BEGIN
    UPDATE GroupIsEngaged
    SET FacultyId = g.FacultyId, DirectionId = g.DirectionId, Course = g.Course
    FROM GroupIsEngaged ge
    INNER JOIN Groups g ON ge.GroupId = g.GroupId
    INNER JOIN inserted i ON ge.GroupId = i.GroupId
END;
