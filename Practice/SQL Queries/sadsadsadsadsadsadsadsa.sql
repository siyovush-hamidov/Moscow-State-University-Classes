USE [MSUDB]
GO
/****** Object:  Trigger [dbo].[trg_UpdateCourse]    Script Date: 8/25/2023 5:38:12 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER TRIGGER [dbo].[trg_UpdateCourse]
ON [dbo].[Students]
AFTER INSERT, UPDATE
AS
BEGIN
    DECLARE @today DATE = GETDATE();
    DECLARE @enrollmentYear INT;
    DECLARE @course INT;
    DECLARE @id INT;

    -- Получаем данные из вставленной/обновленной строки
    SELECT @id = inserted.StudId, @enrollmentYear = inserted.[Enrollment Year], @course = inserted.Course
    FROM inserted;

    -- Вычисляем текущий курс студента
    SET @course = DATEDIFF(YEAR, DATEFROMPARTS(@enrollmentYear, 9, 1), @today) + 1;

   /* -- Если сегодняшняя дата позже 1 сентября, увеличиваем курс на 1
    IF MONTH(@today) > 9 OR (MONTH(@today) = 9 AND DAY(@today) >= 1)
        SET @course = @course + 1;
		*/
    -- Обновляем строку в таблице Students
    UPDATE Students
    SET Course = @course
    WHERE StudId = @id;
END;
