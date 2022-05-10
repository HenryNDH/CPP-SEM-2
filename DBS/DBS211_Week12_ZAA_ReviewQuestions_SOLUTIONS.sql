-- DBS211 - ZAA Review Questions
-- April 4, 2022
-- SOLUTIONS

-- Q1 	List all the orders between May 1 and June 30, 2003. Include the 
-- 		customer name with the order date and the shipped date.
-- 		format the order date to be human readable
SELECT
    ordernumber,
    to_char(orderdate, 'Mon dd, yyyy') AS order_date,          -- need to format
    shippeddate,
    c.customernumber,
    customername
FROM orders o
    INNER JOIN customers c ON o.customernumber = c.customernumber
WHERE orderdate BETWEEN 
    to_date('05/01/03','mm/dd/yy') AND to_date('06/27/03', 'mm/dd/yy')  -- make sure to use to_date() 
ORDER BY orderdate, orderNumber;

-- Q2	List all customers whom have placed an order, but never paid anything
SELECT DISTINCT
    c.customernumber,
    customername,
    amount
FROM customers c 
    INNER JOIN orders o ON c.customernumber = o.customernumber
    LEFT OUTER JOIN payments p ON p.customernumber = c.customernumber
WHERE p.customernumber IS NULL
ORDER BY customername;

-- Q3	List all employees who work in Boston
SELECT
    firstname,
    lastname,
    jobtitle,
    city
FROM employees e
    JOIN offices o ON e.officeCode = o.officeCode
WHERE upper(city) = 'BOSTON'
ORDER BY lastname, firstname;

-- Q4	List all employees who work in Boston but allow the user to 
--		enter ANY PART of the city name
SELECT
    firstname,
    lastname,
    jobtitle,
    city
FROM employees e
    JOIN offices o ON e.officeCode = o.officeCode
WHERE upper(city) LIKE '%' || trim(upper('&input')) || '%'
ORDER BY lastname, firstname;

-- Q5	List all products with product name, that when ordered, 10 or more were ordered
-- 		do not include duplicates
SELECT DISTINCT
    p.productCode,
    productName
FROM products p 
    JOIN orderdetails od ON p.productCode = od.productCode
WHERE od.quantityordered >= 10
ORDER BY p.productName;

-- Q6	Write a series of SQL statements to ARCHIVE all 2013 orders and order 
-- 		details into temp tables
-- 			- Delete the data from the original tables after you are sure the 
-- 			  data is safely stored in the archive
CREATE TABLE archiveOrders2013 AS
	SELECT * FROM orders
	WHERE EXTRACT(Year from orderdate) = 2013;
	
CREATE TABLE archiveOrderDetails2013 AS
	SELECT od.orderNumber, productCode, quantityordered, priceeach, orderlinenumber
	FROM orderdetails od JOIN orders o ON o.ordernumber = od.ordernumber
	WHERE EXTRACT(Year from orderdate) = 2013;
	
DELETE FROM orderdetails 
	WHERE ordernumber IN (
		SELECT orderNumber 
		FROM orders
		WHERE EXTRACT(Year from orderdate) = 2013;

DELETE FROM orders
	WHERE EXTRACT(Year from orderdate) = 2013;

-- Q7. Create all the statements required to have customer 146 place a new order in which they order
--      3 x product 'S700_2047' and  2 x product 'S12_2823'
--      - place savepoints where appropriate
INSERT INTO orders VALUES (10422, sysdate, sysdate + 14, null, 'In Progress', null, 146);
SAVEPOINT orderplaced
INSERT INTO orderdetails VALUES (10422, 'S700_2047', 3, 90.52, 1);
INSERT INTO orderdetails VALUES (10422, 'S12_2823', 2, 150.62, 2);
COMMIT;

-- Q8. Write an SQL statement to change employee Loui Bondour's phone ext to x999
UPDATE employees SET extension = 'x999'
WHERE employeenumber = 1337;   -- make sure you use a unique field (name not good enough)

-- Q9. Write a query to show all the cars currently in inventory at Bob's Car Lot
SELECT 
	vin, 
	year, 
	make, 
	model
FROM cars c LEFT OUTER JOIN order_cars oc ON c.vin = oc.vin
WHERE oc.vin IS NULL;

-- Q10. Given the following code: without running it, tell me how many rows will there be
--    in each table after executing the following code:
SELECT COUNT(*) FROM orders;        -- results in 326 rows
SELECT COUNT(*) FROM orderdetails;  -- results in 2996 rows
COMMIT;
INSERT INTO orders VALUES (10426, sysdate, TO_DATE('04-15-22', 'mm-dd-yy'), null, 'In Process', null, 129);
INSERT INTO orders VALUES (10427, sysdate, TO_DATE('04-22-22', 'mm-dd-yy'), null, 'In Process', null, 130);
SAVEPOINT ordersCreated;
INSERT INTO orderdetails VALUES (10426, 'S18_1097',3,58.33,1);
INSERT INTO orderdetails VALUES (10426, 'S18_2325',3,58.48,2);
SAVEPOINT orderProductsInserted;
ROLLBACK TO ordersCreated;
CREATE VIEW vqAllOrders AS SELECT * FROM orders;
INSERT INTO orderdetails VALUES (10428, 'S18_1065',1,64.50,2);
INSERT INTO orderdetails VALUES (10427, 'S18_2876',2,23.12,5);
ROLLBACK;
COMMIT;
-- how many rows will there be in each table after these lines have completed?
-- ANSWER
-- Table orders will have 327 rows 
	-- the second order insert fails because the customer number does not exist (ref. int).
-- Table order details will have 2996
	-- the first two inserts are rolled back with the ROLLBACK TO ordersCreated line
	-- the second two inserts are rolled back on the last ROLLBACK statement
-- remember the CREATE VIEW statement auto-commits all lines before it.

	