/* ***********************
AUTHOR: Clint MacDonald 100######
DATE: March 14, 2022
TITLE: Week 09 - Demo 1 - SELECT with multiple Table sources
*/

-- Two types of JOINS
-- ANSI89 Join, which jois tables together using a comma and a WHERE statement
-- ANSI92 Join, which uses the JOIN statement with an ON clause.

-- LET ME BE VERY CLEAR
-- ANSI 89 Joins and NOT ACCEPTABLE and will receive a mark of 0.

-- Q. List all the orders sorted by customer
SELECT 
    orderNumber, 
    orderDate,
    customerNumber
FROM orders
ORDER BY customerNumber;
-- but in reality, this is not very useful as we need the customer name
-- therefore we need data from more than one table, in this case the orders and the customers table.
SELECT 
    orderNumber, 
    orderDate,
    orders.customerNumber,
    customerName
FROM orders 
    INNER JOIN customers ON orders.customernumber = customers.customernumber
ORDER BY customerName;
-- This is ANSI92 standard..   all good with 326 rows
SELECT 
    orderNumber, 
    orderDate,
    orders.customerNumber AS oCust,
    customers.customerNumber AS cCust,
    customerName
FROM orders, customers  
ORDER BY customerName;
-- = 326*122 rows = 39,772 rows

-- NEVER DO THIS
SELECT 
    orderNumber, 
    orderDate,
    orders.customerNumber AS oCust,
    customers.customerNumber AS cCust,
    customerName
FROM orders, customers  
WHERE orders.customernumber = customers.customernumber
ORDER BY customerName;
-- this gives the right answer - BUT NEVER DO THIS ANSI89 JOIN unless asked to

-- remember order of execution
-- FROM happens before WHERE


-- Q. List all the customers, and the orders that they have placed.
SELECT
    c.customernumber,
    customername,
    city,
    creditlimit,
    ordernumber,
    orderdate
FROM customers c
    JOIN orders o ON c.customernumber = o.customernumber
ORDER BY 
    customerName, 
    orderDate;
-- JOIN by itself by default is an INNER JOIN    

-- but what if I ask, list all the customers whom have never placed an order
SELECT
    c.customernumber,
    customername,
    city,
    creditlimit,
    ordernumber,
    orderdate
FROM customers c
    LEFT OUTER JOIN orders o ON c.customernumber = o.customernumber
ORDER BY 
    customerName, 
    orderDate;

-- List ALL orders and the customer name that placed the order
SELECT
    c.customernumber,
    customername,
    city,
    creditlimit,
    ordernumber,
    orderdate
FROM customers c
    RIGHT OUTER JOIN orders o ON c.customernumber = o.customernumber
ORDER BY 
    customerName, 
    orderDate;

-- INNER JOIN - will return only those rows from each table where the ON statement exactly matches
-- OUTER JOIN - will return the inner join plus records that do NOT have matching records in the other table.

-- The LEFT and RIGHT parts specify from which table do you want to ensure ALL rows 
--            are returned regardless of the equality

-- REPEATING QUESTION, list all the customers whom have never placed an order
SELECT
    c.customernumber,
    customername,
    city,
    creditlimit,
    ordernumber,
    orderdate
FROM customers c 
    LEFT OUTER JOIN orders o ON c.customernumber = o.customernumber
ORDER BY 
    customerName, 
    orderDate;
-- IS the EXACT same as:
SELECT
    c.customernumber,
    customername,
    city,
    creditlimit,
    ordernumber,
    orderdate
FROM orders o 
    RIGHT OUTER JOIN customer c ON c.customernumber = o.customernumber
    WHERE orderNumber IS NULL
ORDER BY 
    customerName, 
    orderDate;
-- but this still gives us customers WITH orders....

-- no let us finally answer the original question
 -- list all the customers whom have never placed an order
SELECT
    c.customernumber,
    customername,
    city,
    creditlimit,
    ordernumber,
    orderdate
FROM customers c 
    LEFT OUTER JOIN orders o ON c.customernumber = o.customernumber
ORDER BY 
    customerName, 
    orderDate;
    
-- Question:  List ALL orders that do NOT have a customer associated with them.
SELECT 
    orderNumber, orderDate
FROM orders o LEFT JOIN customers c ON o.customernumber = c.customernumber
WHERE c.customernumber IS NULL
ORDER BY orderNumber;

-- no data found, which is a real and good result...  
--     means referential integrity is doing its job

-- Queries with MORE than 2 tables
-- List all products that a customer has ordered.

-- first look at the ERD
-- then right SELECT
SELECT DISTINCT
    c.customernumber,
    customername,
    p.productCode,
    productname
FROM customers c
    JOIN orders o ON c.customernumber = o.customernumber
    JOIN orderdetails od ON o.ordernumber = od.ordernumber
    JOIN products p ON p.productCode = od.productCode
ORDER BY 
    customerNumber, 
    productname;
