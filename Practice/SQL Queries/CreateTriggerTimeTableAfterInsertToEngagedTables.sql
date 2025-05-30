USE [MSUDB]
GO
/****** Object:  Trigger [dbo].[trg_TimeTable_Insert_To_Engaged_Tables]    Script Date: 8/19/2023 5:09:29 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER TRIGGER [dbo].[trg_TimeTable_Insert_To_Engaged_Tables]
ON [dbo].[TimeTable]
AFTER INSERT
AS
BEGIN
    -- Вставка данных в таблицу ClassroomIsEngaged
    INSERT INTO ClassroomIsEngaged (ClassroomId, Date, Pair, IsEngaged, LessonId)
    SELECT i.ClassroomId, i.Date, i.Pair, 1, i.LessonId
    FROM inserted i;

    -- Вставка данных в таблицу GroupIsEngaged
    INSERT INTO GroupIsEngaged(GroupId, FacultyId, DirectionId, Date, Pair, IsEngaged, Course, LessonId)
    SELECT i.GroupId, i.FacultyId, i.DirectionId, i.Date, i.Pair, 1, i.Course, i.LessonId
    FROM inserted i;

    -- Вставка данных в таблицу TeacherIsEngaged
    INSERT INTO TeacherIsEngaged(TeacherId, Date, Pair, IsEngaged, LessonId)
    SELECT i.TeacherId, i.Date, i.Pair, 1, i.LessonId
    FROM inserted i;
END;
