-- ----------------------------------
-- DBS211 - Lab 01
-- Name: Henry Nguyen
-- StudentID: 108397217
-- Date: Jan 13 2022
-- ----------------------------------

-- Question 1
/* How many tables have been created? List the names of the created tables. */

/* 8 tables have been created. CUSTOMERS, EMPLOYEES, OFFICES ORDERDETAILS, ORDERS, PAYMENTS, PRODUCTLINES, PRODUCTS.*/


-- Question 2
/* Click on table customers. Click on the Data tab near the top of the worksheet. How many rows are there in the table customers?*/

/* 122 rows */


-- Question 3
/* What SQL statement would return the same results. Write the statement in the .sql file and execute it.*/

/* SELECT * FROM customers*/


-- Question 4
/* How many columns does the customers table have? List the column names.*/

/* 7 columns include: COLUMN_NAME, DATA_TYPE, NULLABLE, DATA_DEFAULT, COLUMN_ID, COMMENTS*/


-- Question 5
/* What is the value of each column in the first row in table customers? Write the column name and the column data type in addition to the value.*/

/* COLUMN_NAME: CUSTOMERNUMBER, DATA_TYPE: NUMBER(38,0), NULLABLE: No, DATA_DEFAULT: (null), COLUMN_ID: 1, COMMENTS: (null)*/


-- Question 6
/* Write the number of rows and columns for the rest of the tables in your schema.  Format it something like the following.*/

/* 3 rows and 3 columns*/

-- Question 7
/* Right Click on the orderdetails table and choose tables/count rows.  How many rows does the order details table include?*/

/*2996 Rows*/

-- Question 8
/*  Write the following SQL statement in the new tab.*/

/* It show OFFICES table's content*/

-- Question 9
/* Type the following statements in, execute them, then briefly describe what the statement is doing!*/

/*SELECT * FROM employees; this show employees table's data.
  SELECT * FROM customers ORDER BY ContactLastName; this show customers table's data but it reorder by their ContactLastName.
*/

-- Question 10
/* How many constraints does the products table have?*/

/* 12 constraints*/

-- Question 11
/* Find a way to turn on line numbers in the gutter.  Where is the gutter? Describe its location in your solutizon file.*/

/* Tools/Preferences/ Code Editor/ Line Gutter*/

-- Question 12
/* Set the font size in the worksheet editor to a size that is best for you.  (Hint: Tools/Preferences)*/

/* Tools/Preferences/ Code Editor/ Fonts*/

