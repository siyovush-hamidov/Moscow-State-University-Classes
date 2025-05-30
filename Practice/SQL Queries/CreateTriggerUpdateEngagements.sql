USE [MSUDB]
GO
/****** Object:  Trigger [dbo].[update_engagements]    Script Date: 8/19/2023 5:09:07 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER TRIGGER [dbo].[update_engagements]
ON [dbo].[TimeTable]
AFTER UPDATE
AS
BEGIN
    IF UPDATE(Date) OR UPDATE(Pair) OR UPDATE(TeacherId) OR UPDATE(GroupId) OR UPDATE(ClassroomId)
    BEGIN
        UPDATE GroupIsEngaged
        SET Date = i.Date, Pair = i.Pair, GroupId = i.GroupId
        FROM GroupIsEngaged g
        INNER JOIN inserted i ON g.LessonId = i.LessonId

        UPDATE TeacherIsEngaged
        SET Date = i.Date, Pair = i.Pair, TeacherId = i.TeacherId
        FROM TeacherIsEngaged t
        INNER JOIN inserted i ON t.LessonId = i.LessonId

        UPDATE ClassroomIsEngaged
        SET Date = i.Date, Pair = i.Pair, ClassroomId = i.ClassroomId
        FROM ClassroomIsEngaged c
        INNER JOIN inserted i ON c.LessonId = i.LessonId
    END
END;
