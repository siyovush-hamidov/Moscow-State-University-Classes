use MSUDB

/*insert into Students(Photo)
select BulkColumn
from openrowset(BULK N'D:\Desktop\MSU\ForthSemester\Практика\Фотографии\UserPhotos\photo_2023-03-07_18-21-05.jpg', single_blob) image;
*/

UPDATE Register
SET Image = (SELECT BulkColumn FROM OPENROWSET(BULK 'D:\Desktop\MSU\ForthSemester\Практика\Фотографии\UserPhotos\photo_2023-03-07_18-21-05.jpg', SINGLE_BLOB) as ImageSource)
WHERE Name = 'Сиёвуш';


select * from Register