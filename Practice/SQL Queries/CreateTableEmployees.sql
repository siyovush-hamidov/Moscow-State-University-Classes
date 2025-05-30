CREATE TABLE [dbo].[Employees]
(
	[EmployeeId] int identity(1,1) not null,
	[RegId] int NULL,
	[Surname] [nvarchar](100) NULL,
	[Name] [nvarchar](100) NULL,
	[Middle Name] [nvarchar](100) NULL,
	[Nationality] [nvarchar](100) NULL,
	[Gender] [bit] NULL,
	[Birthday] [date] NULL,
	[Military Status] [nvarchar](100) NULL,
	[Family Status] varchar(30) not null,
	[Home Address] varchar(70) not null,
	[Actual Adress] varchar(70) not null,
	[Phone Number] varchar(30) not null,
	Email varchar(50) not null,
	Image image,
	[Passport Serial Number] varchar(50) not null,
	[Date Of Issue Of Passport] date not null,
	[Place Of Issue Of Passport] varchar(50) not null,
	[High School] varchar(60) not null,
	[Country Of High School] varchar(40) not null,
	[High School Diploma] varchar(50) not null,
	[High School Diploma Date Of Issue] date not null,
	[High School Diploma Serial Number] varchar(50) not null,
	[Phone] [varchar](50) NULL,
	[Latest Degree Earned]	nvarchar(100) NULL,
	[Latest Degree Country]	nvarchar(100) NULL,	
	[Latest Degree Date Of Issue] date NULL,	
	[Latest Degree Serial Number] nvarchar(100) NULL,	
	[Latest University]	nvarchar(100) NULL,
	[Departament] [nvarchar](100) NULL,
	[Position] [nvarchar](100) NULL
)