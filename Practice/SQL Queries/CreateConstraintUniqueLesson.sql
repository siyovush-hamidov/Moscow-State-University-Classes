ALTER TABLE TimeTable
ADD CONSTRAINT UniqueLesson UNIQUE (Date, FacultyId, DirectionId, Course, Pair);
