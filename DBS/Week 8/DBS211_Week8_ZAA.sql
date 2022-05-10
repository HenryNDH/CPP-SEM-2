/* **********************************
Author: Hoang Duy Nguyen
StudentID: 108397217
Date: March 07 2022
Titile: DBS211 - Week 8 - Class Demo A
********************************** */

-- SQL - Structured Query Language

-- There are three sub languages of SQL:
-- DDL, DML, TCL
-----------------------------------------
-- DDL - Data Deffinition Language - defining and changing the STRUCTURE of database
-- DML - Data Manipulation Language - adding modifying the data itself. (CRUD statements)
-- TCL - Transaction Control Language - multiple statement process (all or nothing)
-----------------------------------------

-- DML 
-- made up 4 main statement - CRUD
-- CREATE   - refers to INSERT statements (add new rows of data)
-- READ     - refers to SELECT statements (Q&A statements)
-- UPDATE   - refers to UPDATE statements (changing existing data)
-- DELET    - refers to DELETE statements (deleting existing data)

-- SELECT STATEMENTS
-- Basic Syntax -
/*
SELECT <fieldlist comma separated)>
FROM <data source or sources>
WHERE <filter condition>
ORDER BY <fieldlist comma sperated>
*/

-- The easiest
SELECT * FROM employees;
-- this get all rows and columns from the emloyees table 
-- the * does not mean all rows, only all columns
-- we get all ROWS because there is no WHERE STATEMENTS (filter condition)

-- In SQL Statements there are 2 MANDATORY parts - SELECT and FROM
-- the semi colon in ONLY required if you have multiple statements.
-- the FROM statement is ONLY require in Oracle.

SELECT * FROM offices;
