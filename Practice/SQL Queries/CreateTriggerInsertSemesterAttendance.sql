/*CREATE TRIGGER trg_InsertSemester
ON Attendance
AFTER INSERT
AS
BEGIN
    UPDATE Attendance
    SET Attendance.Semester = CASE 
        WHEN MONTH(Attendance.Date) BETWEEN 9 AND 12 OR MONTH(Attendance.Date) = 1 THEN 1
        WHEN MONTH(Attendance.Date) BETWEEN 2 AND 7 THEN 2
        ELSE Attendance.Semester
    END
    FROM Attendance
    INNER JOIN inserted i ON Attendance.AttendanceId = i.AttendanceId;
END;*/


CREATE TRIGGER trg_UpdateSemester
ON Attendance
AFTER UPDATE
AS
BEGIN
    IF UPDATE(Date)
    BEGIN
        UPDATE Attendance
        SET Attendance.Semester = CASE 
            WHEN MONTH(Attendance.Date) BETWEEN 9 AND 12 OR MONTH(Attendance.Date) = 1 THEN 1
            WHEN MONTH(Attendance.Date) BETWEEN 2 AND 7 THEN 2
            ELSE Attendance.Semester
        END
        FROM Attendance
        INNER JOIN inserted i ON Attendance.AttendanceId = i.AttendanceId;
    END;
END;
