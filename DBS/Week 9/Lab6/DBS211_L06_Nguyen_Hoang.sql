--Name:    Hoang Duy Nguyen
--ID:      108397217
--Date:    12 Mar 2022
--Purpose: DBS211 Lab 06
SET AUTOCOMMIT ON;
--1.Display the data for all offices
SELECT * FROM offices;

--2.Display the employee number for all employees whose office code is 1.
SELECT employeeNumber
FROM employees
WHERE officeCode = 1;
--3.Display customer number, customer name, contact first name and contact last name, and phone for all customers in Paris. (hint: be wary of case sensitivity)
SELECT 
    customerNumber, 
    customerName, 
    contactFirstname, 
    contactLastname, 
    phone,
    city
FROM customers
WHERE city= 'Paris'
ORDER BY contactFirstname;
--4.Repeat the previous Query with a couple small changes:
--  a.The contact�s first and last name should be in a single column in the format �lastname, firstname�.
SELECT 
    customerNumber, customerName, 'LastName,FirstName',
    phone,
    country
FROM customers
--  b.Show customers who are in Canada
WHERE upper (country) IN ('CANADA')
ORDER BY contactFirstName;
--5.Display customer number for customers who have payments.  Do not included any repeated 
--  values. (hints: how do you know a customer has made a payment? You will need to access only one table for this query)
SELECT DISTINCT 
    customerNumber
FROM payments
ORDER BY customerNumber ASC;
--6.List customer numbers, check number, and amount for customers whose payment amount is not in the range of $30,000 to $65,000. Sort the output by top payments amount first.
SELECT
    customerNumber,
    checkNumber,
    amount
FROM payments
WHERE amount<30000 or amount>65000
ORDER BY amount DESC;
--7.Display the order information for all orders that are cancelled
SELECT *
FROM orders
WHERE status IN('Cancelled');
--8.The company needs to know the percentage markup for each product sold.  Produce a query that outputs the ProductCode, ProductName, BuyPrice, MSRP in addition to
SELECT 
    productcode,
    productname,
    buyprice,
    msrp,
    msrp - buyprice AS markup,
    ROUND((((msrp - buyprice) / buyprice) * 100), 1) AS percmarkup
FROM products;
--9.Display the information of all products with string �co� in their product name. (c and o can be lower or upper case).
SELECT *
FROM products
WHERE upper(productname) LIKE '%CO%'
ORDER BY productName;
--10.Display all customers whose contact first name starts with letter s (both lowercase and uppercase) and includes letter e (both lowercase and uppercase).
SELECT *
FROM customers
WHERE upper(customerName) LIKE 'S%E%';
--11.Create a statement that will insert yourself as an employee of the company.  
INSERT INTO employees(employeeNumber,lastName,firstName,extension,email,officeCode,reportSto,jobtitle)
VALUES(1799,'Nguyen','Hoang','v86993','hdnguyen12@myseneca.ca',4,1088,'CASHIER');

--12.Create a query that displays your, and only your, employee data
SELECT *
FROM employees
WHERE firstName = 'Hoang';
--13.Create a statement to update your job title to �Head Cashier�
UPDATE employees
SET jobtitle = 'Head Cashier'
WHERE employeeNumber = 1799;
--14.Create a statement to insert another fictional employee into the database.  This employee will be a �Cashier� and will report to you.  Make up fake data for the other fields.
INSERT INTO employees(employeeNumber,lastName,firstName,extension,email,officeCode,reportSto,jobtitle)
VALUES(1800,'Nguyen','Lisa','x8699','lisa12@gmail.com',4,1799,'CASHIER');
--15.Create a statement to Delete yourself from the database.  Did it work?  If not, why?
DELETE FROM employees
WHERE employeeNumber = 1799;
--No it doesn't because my employee still exist
--16.Create a statement to delete the fake employee from the database and then rerun the statement to delete yourself.  Did it work?
DELETE FROM employees
WHERE employeenumber = 1800;
DELETE FROM employees
WHERE employeenumber = 1799;
--Yes it work
--17.Create a single statement that will insert both yourself and the fake employee at the same time.  This time the fake employee will report to 1088 as well.
INSERT ALL
INTO employees(employeenumber, lastname, firstname, extension, email, officecode, reportsto, jobtitle) 
VALUES(1799,'Nguyen','Hoang','v86993','hdnguyen12@myseneca.ca',4,1088,'CASHIER')
INTO employees(employeenumber, lastname, firstname, extension, email, officecode, reportsto, jobtitle) 
VALUES(1800,'Nguyen','Lisa','x8699','lisa12@gmail.com',4,1799,'CASHIER')
SELECT * FROM dual;
--18.Create a single statement to delete both yourself and the fake employee.
DELETE FROM employees
WHERE employeenumber = 1799 OR employeenumber = 1800;