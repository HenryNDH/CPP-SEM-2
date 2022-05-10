--Name:    Hoang Duy Nguyen
--ID:      108397217
--Date:    05 Apr 2022
--Purpose: DBS211 Lab 09

--PART A - Transactions
--1.	List the 4 ways that we know that a transaction can be started
--  1) Execute a COMMIT statementt
--  2) Connecting to the database server within each session
--  3) Executing ANY DDL statement
--  4) SET TRANSACTION

--2.	Using SQL, create an empty table, that is the same as the employees table, and name it newEmployees.
--
CREATE TABLE newEmployees AS
SELECT *
FROM employees;

TRUNCATE TABLE newEmployees;
--3.	Execute the following commands.
SET AUTOCOMMIT OFF;
SET TRANSACTION READ WRITE;
--
--4.	Write an INSERT statement to populate the newEmployees table with the rows of the sample data. Insert the NULL value for the reportsTo column. (Write a single INSERT statement to insert all the rows)
--
INSERT ALL
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) 
VALUES (100, 'Patel', 'Ralph', 22333, 'rpatel@mail.com', 1, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) 
VALUES (101, 'Denis', 'Betty', 33444, 'bdenis@mail.com', 4, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) 
VALUES (102, 'Biri', 'Ben', 44555, 'bbirir@mail.com', 2, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) 
VALUES (103, 'Newman', 'Chad', 66777, 'cnewman@mail.com', 3, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) 
VALUES (104, 'Ropeburn', 'Audrey', 77888, 'aropebur@mail.com', 1, NULL, 'Sales Rep')
SELECT * FROM dual;
--5.	Create a query that shows all the inserted rows from the newEmployees table. How many rows are selected?
--
SELECT * FROM newEmployees;
--
--  5 rows are selected
--6.	Execute the rollback command. Display all rows and columns from the newEmployees table. How many rows are selected?
--
ROLLBACK;
--
--  0 rows are selected

--7.	Repeat Task 4. Make the insertion permanent to the table newEmployees. Display all rows and columns from the newEmployee table. How many rows are selected?
--
INSERT ALL
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) 
VALUES (100, 'Patel', 'Ralph', 22333, 'rpatel@mail.com', 1, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) 
VALUES (101, 'Denis', 'Betty', 33444, 'bdenis@mail.com', 4, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) 
VALUES (102, 'Biri', 'Ben', 44555, 'bbirir@mail.com', 2, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) 
VALUES (103, 'Newman', 'Chad', 66777, 'cnewman@mail.com', 3, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) 
VALUES (104, 'Ropeburn', 'Audrey', 77888, 'aropebur@mail.com', 1, NULL, 'Sales Rep')
SELECT * FROM dual;

COMMIT;

SELECT * FROM newemployees;
--  5 rows are selected

--8.	Write an update statement to update the value of column jobTitle to ‘unknown’ for all the employees in the newEmployees table.
--
UPDATE newEmployees SET jobtitle = 'unknown';
SELECT * FROM newEmployees;

--9.	Make your changes permanent.
--
COMMIT;
--10.	Execute the rollback command. 
--a.	Display all employees from the newEmployees table whose job title is ‘unknown’. How many rows are still updated?
SELECT * 
FROM newEmployees
WHERE jobtitle = 'unknown';

-- 5 Rows
--b.	Was the rollback command effective?
ROLLBACK;

-- No
--c.	What was the difference between the result of the rollback execution from Task 6 and the result of the rollback execution of this task?
-- task 10 ROLLBACK was not effective due to COMMIT

--11.	Begin a new transaction and then create a statement to delete to employees from the newEmployees table
--
COMMIT;
TRUNCATE TABLE newEmployees;

--12.	Create a VIEW, called vwNewEmps, that queries all the records in the newEmployees table sorted by last name and then by first name.
--
CREATE VIEW vwNewEmps AS
SELECT * FROM newEmployees
ORDER BY lastname, firstname;

--13.	Perform a rollback to undo the deletion of the employees
ROLLBACK;
--a.	How many employees are now in the newEmployees table?
SELECT * FROM newEmployees;
--  0 Employees
--b.	Was the rollback effective and why?
--  Rollback was not effective due to commit at line 93
--14.	Begin a new transaction and rerun the data insertion from Task 4 (copy the code down to Task 14 and run it)
COMMIT;
INSERT ALL
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) 
VALUES (100, 'Patel', 'Ralph', 22333, 'rpatel@mail.com', 1, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) 
VALUES (101, 'Denis', 'Betty', 33444, 'bdenis@mail.com', 4, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) 
VALUES (102, 'Biri', 'Ben', 44555, 'bbirir@mail.com', 2, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) 
VALUES (103, 'Newman', 'Chad', 66777, 'cnewman@mail.com', 3, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) 
VALUES (104, 'Ropeburn', 'Audrey', 77888, 'aropebur@mail.com', 1, NULL, 'Sales Rep')
SELECT * FROM dual;

--15.	Set a Savepoint, called insertion, after inserting the data
SAVEPOINT insertion;

--16.	Rerun the update statement from Task 8 and run a query to view the data (copy the code down and run it again)
UPDATE newEmployees SET jobtitle = 'unknown';
SELECT * FROM newEmployees;

--17.	Rollback the transaction to the Savepoint created in task 15 above and run a query to view the data.
ROLLBACK TO insertion;
SELECT * FROM newEmployees;

--What does the data look like (i.e. describe what happened?
-- jobtitle data return to what it save at savepoint

--18.	Use the basic for of the rollback statement and again view the data.  Describe what the results look like and what happened.
ROLLBACK;
SELECT * FROM newEmployees;

--Part B - Permissions
--19.	Write a statement that denies all access to the newemployees table for all public users
REVOKE ALL
ON newEmployees
FROM public;
--20.	Write a statement that allows a classmate (use their database login) read only access to the newemployees table.
GRANT SELECT ON newEmployees TO dbs211_221za25;
--21.	Write a statement that allows the same classmate to modify (insert, update and delete) the data of the newemployees table.
GRANT INSERT, UPDATE, DELETE ON newEmployees TO dbs211_221za25;
--22.	Write a statement the denies all access to the newemployees table for the same classmate.

REVOKE ALL 
ON newEmployees 
FROM dbs211_221za03;

--Part C – Clean up
--23.	Write statements to permanently remove the view and table created for this lab
DROP TABLE newEmployees;
DROP VIEW vwNewEmps;

