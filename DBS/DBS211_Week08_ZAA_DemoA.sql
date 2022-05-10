/* *************************
Author: Clint MacDonald
StudentID: #########
Date: March 7, 2022
Title: DBS211 - Week 8 - Class Demo A
**************************** */

-- SQL - Structured Query Language

-- There are 3 sub-languages of SQL
-- DDL, DML, TCL
---------------------------
-- DDL - Data Definition Language - defining and changing the STRUCTURE of the database
-- DML - Data Manipulation Language - adding and modifying the data itself. (CRUD statements)
-- TCL - Transaction Control Language - multiple statement processes (all or nothing)
---------------------------

-- DML 
-- made up of 4 main statements - CRUD
-- CREATE   - refers to INSERT statements (add new rows of data)
-- READ     - refers to SELECT statements (Q & A statements)
-- UPDATE   - refers to UPDATE statements (changing existing data)
-- DELETE   - refers to DELETE statements (deleting existing data)

-- SELECT STATEMENTS
-- basic syntax - 
/*
SELECT <fieldlist comma separated>
FROM <data source or sources may contain JOINs>
WHERE <filter condition>
ORDER BY <fieldlist comma separated>
*/

-- The easiest statement
SELECT * FROM employees;
-- this gets all rows and columns from the employees table
-- the * does NOT mean all rows, only all columns
-- we get all ROWS because there is no WHERE (filter condition)

-- IN SQL Statements there are 2 MANDATORY parts - SELECT and FROM
-- the semi colon is ONLY required if you have multiple statements.
-- the FROM statement is ONLY required in Oracle.

SELECT 
    employeeNumber AS empNum,  -- empNum is an ALIAS for employeenumber
    firstName,
    lastName,
    email,
    jobTitle
FROM employees;

-- calculated fields
SELECT
    firstname,
    lastname,
    firstname || ' ' || lastname  -- this gives bad column name
FROM employees;
-- we need to add an alias to the full name
SELECT
    firstname,
    lastname,
    firstname || ' ' || lastname AS fullName
FROM employees;
-- ALL Calculated fields MUST HAVE an alias.

-- Q: What would the credit limits look like if we added 10% to all customers
SELECT
    customerNumber AS custNum,
    customerName,
    city,
    creditLimit AS origCL,
    creditLimit * 1.1 AS newCL
FROM customers;

-- SORTING
-- Q. List all employees sorted by lastname
SELECT *
FROM employees
ORDER BY lastname;
-- Q. Same with full name
SELECT
    firstname || ' ' || lastname AS fullName
FROM employees
ORDER BY lastname, firstname;

-- you can sort by aliases
SELECT
    firstname || ' ' || lastname AS fullName
FROM employees
ORDER BY fullName;

-- What is we want to sort backwards
-- Q. List all customers sorted by those with the highest credit limit first
SELECT 
    customerNumber,
    customerName,
    city,
    creditLimit,
    creditLimit * 1.1 AS newLimit
FROM customers
ORDER BY newLimit DESC;  -- ASC is the default sort order






