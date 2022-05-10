/* *************************
Author: Clint MacDonald
StudentID: #########
Date: March 9, 2022
Title: DBS211 ZAA - Week 8 - Class Demo B 
Subject:  Intro to SQL - DML 1 continued
**************************** */

-- Filtering and Limiting the rows returned

-- Q: List all customers whom have a 0 credit limit!  Show the cust #, name, phone, credit limit
SELECT
    customerNumber,
    customerName,
    phone,
    creditLimit
FROM customers
WHERE creditLimit = 0
ORDER BY customerName;

-- opposite give those with a credit limit
SELECT
    customerNumber,
    customerName,
    phone,
    creditLimit
FROM customers
WHERE NOT(creditLimit = 0)
ORDER BY customerName;
-- or
SELECT
    customerNumber,
    customerName,
    phone,
    creditLimit
FROM customers
WHERE creditLimit > 0
ORDER BY customerName;

-- Q List all customers with a 0 credit limit from the city of Madrid
SELECT
    customerNumber,
    customerName,
    phone,
    city,
    creditLimit
FROM customers
WHERE creditLimit = 0 AND city = 'Madrid'
ORDER BY customerName;

-- Filter RANGES 
-- Q List all customers with a credit limit between 60,000 and 120,000
SELECT
    customerNumber,
    customerName,
    phone,
    city,
    creditLimit
FROM customers
WHERE creditLimit >= 60000 AND creditLimit <= 120000
ORDER BY customerName;
-- easier way using the BETWEEN function
SELECT
    customerNumber,
    customerName,
    phone,
    city,
    creditLimit
FROM customers
WHERE creditLimit BETWEEN 60000 AND 120000 -- BETWEEN is inclusive
ORDER BY customerName;

-- opposite, credit limit < 60000 OR credit limit > 120000
SELECT
    customerNumber,
    customerName,
    phone,
    city,
    creditLimit
FROM customers
WHERE creditLimit < 60000 OR creditLimit > 120000
ORDER BY customerName;
-- easier way using the BETWEEN function
SELECT
    customerNumber,
    customerName,
    phone,
    city,
    creditLimit
FROM customers
WHERE creditLimit NOT BETWEEN 60000 AND 120000 -- BETWEEN is inclusive
ORDER BY customerName;

-- WHERE with aliases
SELECT 
    customerNumber,
    customerName,
    city,
    creditLimit,
    creditLimit * 1.1 AS newCreditLimit
FROM customers
WHERE newCreditLimit > 0
ORDER BY newCreditLimit;
-- this fails
-- you cannot use an alias in the WHERE clause, period.

-- ORDER OF EXECUTION
-- an SQL statement does not run left to right sequentially.
-- it runs in a specific order to optimize the process and make the statement execute
-- as quickly as possible.
-- the order is:
-- 1) FROM 
    -- 1a) JOIN
-- 2) WHERE 
-- 3) SELECT - iterates as a LOOP one row at a time.
-- 4) ORDER BY

-- therefore the above statement must be:
SELECT 
    customerNumber,
    customerName,
    city,
    creditLimit,
    creditLimit * 1.1 AS newCreditLimit
FROM customers
WHERE creditLimit * 1.1 > 0
ORDER BY newCreditLimit;

-- *************************************************
-- Strings, Wildcards and the LIKE operator

-- Q: List all customer contacts whose last name starts with S
SELECT 
    customerName,
    contactFirstName,
    contactLastName
FROM customers
WHERE contactLastName LIKE 'S%';
-- Strings are CASE SENSITIVE
SELECT 
    customerName,
    contactFirstName,
    contactLastName
FROM customers
WHERE contactLastName LIKE 's%';
-- Therefore to solve this use UPPER() or LOWER()
SELECT 
    customerName,
    contactFirstName,
    contactLastName
FROM customers
WHERE UPPER(contactLastName) LIKE 'S%';
-- OR
SELECT 
    customerName,
    contactFirstName,
    contactLastName
FROM customers
WHERE LOWER(contactLastName) LIKE 's%';

SELECT 
    customerName,
    contactFirstName,
    contactLastName
FROM customers
WHERE contactLastName LIKE 's%' OR contactLastName LIKE 'S%' ;

-- uniqueness in results
-- Q - list all the cities where our customers are located
SELECT DISTINCT city
FROM customers
ORDER BY city;
-- but we got Auckland twice because some have spaces after the name
SELECT DISTINCT TRIM(city) AS City
FROM customers
ORDER BY City;
-- this eliminated those extra spaces and gave us a better answer

-- ORDER OF PRECEDENCE

-- let us look at Order of Operations
SELECT 4 + 3 * 5 AS aNumber FROM dual;
-- we get 19 as the * is before the +

-- the dual table is a minimalistic build-in table for use when you do not require a data source
SELECT * FROM dual;

-- getting the current date
SELECT sysdate FROM dual;

-- List all contacts whose FIRST name starts with R, 
--          and their LAST names starts with S or M.
SELECT
    contactFirstName, 
    contactLastName
FROM customers
WHERE 
    UPPER(contactLastName) LIKE 'S%'
    OR UPPER(contactLastName) LIKE 'M%'
    AND UPPER(contactFirstName) LIKE 'R%'
ORDER BY 
    contactLastName, 
    contactFirstName;
-- problem, gives incorrect results

-- ORDER OF OPERATIONS is extended.... to ORDER OF PRECENDENCE
-- common addition is that AND always occurs before OR

-- to solve the above problem
SELECT
    contactFirstName, 
    contactLastName
FROM customers
WHERE 
    (UPPER(contactLastName) LIKE 'S%'   -- ADD BRACKETS
    OR UPPER(contactLastName) LIKE 'M%')
    AND UPPER(contactFirstName) LIKE 'R%'
ORDER BY 
    contactLastName, 
    contactFirstName;



-- USER INPUT

-- Q- List all customers from a city of the users choice
SELECT 
    customerNumber,
    customerName,
    City
FROM customers
WHERE TRIM(LOWER(city)) = 'auckland'; 
-- but the user caan enter
SELECT 
    customerNumber,
    customerName,
    City
FROM customers
WHERE TRIM(LOWER(city)) = TRIM(LOWER('&EnterCountry'));

-- What if we don't know how to spell it.....
-- we can only enter the first few letters
SELECT 
    customerNumber,
    customerName,
    City
FROM customers
WHERE TRIM(LOWER(city)) LIKE TRIM(LOWER('&EnterCountry%'));

-- ******************************
-- TO_CHAR() and TO_DATE()

-- TO_CHAR()
SELECT 
    customerNumber,
    customerName,
    creditLimit,
    '$' || TO_CHAR(ROUND(creditLimit,2),'999999.99') AS newCredit
FROM customers
ORDER BY newCredit;

-- be careful sorting after converting a number to a string, as sorting would then 
-- be alphabetical rather than numeric.

SELECT * FROM orders
ORDER BY orderDate;
-- 
SELECT
    orderNumber,
    orderDate,
    TO_CHAR(orderDate, 'Day, Mon DD, YYYY') AS newOrderDate
FROM orders
ORDER BY newOrderDate;
-- WRONG SORTING ORDER - have to use original OrderDate

-- TO_DATE()
-- list all orders on Dec 9, 2003
SELECT 
    orderNumber, 
    orderDate, 
    shippedDate
FROM orders
WHERE orderdate = TO_DATE('03-12-09', 'YY-MM-DD');

-- do not need to do this with sysdate or fields that are already date types

-- some more examples to look at on your own
-- let us use DUAL for examples
SELECT TO_CHAR(sysdate, 'Day, Mon DD, YYYY') FROM dual;

SELECT TO_CHAR(      NEXT_DAY(sysdate+28, 'Friday')              , 'Day, Mon DD, YYYY') FROM dual;

-- Outputting Dates
SELECT * FROM orders;
-- format
SELECT sysdate FROM dual;
SELECT TO_CHAR(sysdate, 'Mon DD, YYYY') AS dt FROM dual;

-- give me all orders in March
SELECT orderNumber, orderDate
    FROM orders
    WHERE EXTRACT(MONTH from orderDate) = 3
        AND EXTRACT(YEAR from orderDate) = 2004;
