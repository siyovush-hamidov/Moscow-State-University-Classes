/*CREATE TRIGGER trg_TimeTable_DayOfWeek_WeekNumber
ON TimeTable
AFTER INSERT
AS
BEGIN
    UPDATE TimeTable
    SET DayOfWeek = DATENAME(dw, i.Date),
        NumberOfWeek = (DATEDIFF(wk, DATEFROMPARTS(YEAR(i.Date), 9, 1), i.Date)) + 1
    FROM TimeTable t
    INNER JOIN inserted i ON t.LessonId = i.LessonId;
END;
*/
CREATE TRIGGER trg_TimeTable_DayOfWeek_WeekNumber_ON_UPDATE
ON TimeTable
AFTER UPDATE
AS
BEGIN
    UPDATE TimeTable
    SET DayOfWeek = DATENAME(dw, i.Date),
        NumberOfWeek = (DATEDIFF(wk, DATEFROMPARTS(YEAR(i.Date), 9, 1), i.Date)) + 1
    FROM TimeTable t
    INNER JOIN inserted i ON t.LessonId = i.LessonId;
END;
