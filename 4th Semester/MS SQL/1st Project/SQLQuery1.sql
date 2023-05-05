use master
use MSUDB
create table First_Project(ID int not null identity(1,1) not for replication, Country varchar(40) not null, Capital varchar(40) not null,
Population int not null, primary key(ID), unique(ID asc));