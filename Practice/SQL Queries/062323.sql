use MSUDB

 create table Register
(
	RegId int identity(1,1) not null primary key,
	Login varchar(50) not null,
	Password varchar(50) not null,
	Role int not null,
	Surname varchar(40) not null,
	Name varchar(40) not null,
	MiddleName varchar(40) not null
)
