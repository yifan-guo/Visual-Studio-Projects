CREATE TABLE [dbo].[PlayerDetails]
(
	[UserID] INT NOT NULL PRIMARY KEY Identity(1,1),
	[FirstName] VARCHAR(50) NULL,
	[LastName] VARCHAR(50) NULL,
	[PhoneNumber] VARCHAR(20) NULL,
	[SchoolName] VARCHAR (200) NULL,
	[Tournament] VARCHAR(100) NULL,
	[FirstTime] BIT NULL,
	[CreatedDate] DATETIME NOT NULL DEFAULT getdate()
)