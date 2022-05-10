-- DBS211 - ZAA Review Questions
-- APril 4, 2022

-- Q1. List all the orders between May 1 and June 30, 2003. Include the 
-- customer name with the order date and the shipped date.
-- format the order date to be human readable

-- Q2. List all customers whom have placed an order, but never paid anything

-- Q3. List all employees who work in Boston

-- Q4. List all employees who work in Boston but allow the user to enter ANY PART of the city name

-- Q5. List all products with product name, that when ordered, 10 or more were ordered
      -- do not include duplicates

-- Q6. Write a series of SQL statements to ARCHIVE all 2013 orders and order details into temp tables
     -- Delete the data from the original tables after you are sure the data is safely stored in the archive
     
-- Q7. Create all the statements required to have customer 146 place a new order in which they order
--      3 x product 'S700_2047' and  2 x product 'S12_2823'
--      - place savepoints where appropriate
--      - Complete the transaction 

-- Q8. Write an SQL statement to change employee Loui Bondour's phone ext to x999

-- Q9. Write a query to show all the cars currently in inventory at Bob's Car Lot (Use the ERD created during week 3)

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