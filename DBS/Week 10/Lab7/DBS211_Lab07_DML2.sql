--Name:    Hoang Duy Nguyen
--ID:      108397217
--Date:    23 Mar 2022
--Purpose: DBS211 Lab 07

--Q1
--a
SELECT 
    employeenumber, 
    firstname, 
    lastname, 
    city, 
    phone AS phoneNum, 
    postalcode
FROM employees, offices    
WHERE employees.officecode = offices.officecode AND lower(country) = 'france';

--b
SELECT 
    employeenumber, 
    firstname, 
    lastname, 
    city, 
    phone AS phoneNum, 
    postalcode 
FROM employees JOIN offices ON (employees.officecode = offices.officecode)     
WHERE UPPER(country) = 'FRANCE';

--Q2
SELECT 
    customers.customernumber,
    customername,
    TO_CHAR(paymentdate, 'Mon dd, yyyy') AS payDate,
    amount    
FROM customers JOIN payments ON (customers.customernumber = payments.customernumber)
WHERE UPPER(country) = 'CANADA'
ORDER BY customers.customernumber;

--Q3
SELECT 
    customernumber,
    customername,
    amount,
    country
FROM customers LEFT JOIN payments USING(customernumber)
WHERE UPPER(country) = 'USA' AND amount IS NULL
ORDER BY customernumber;

--Q4
CREATE VIEW vwCustomerOrder AS
SELECT 
    customernumber,
    orders.ordernumber,
    orderdate,
    productname,
    quantityordered,
    priceeach
FROM orders JOIN orderdetails ON (orders.ordernumber = orderdetails.ordernumber)
JOIN products USING (productcode)
JOIN customers USING (customernumber);
                
SELECT *
FROM vwCustomerOrder;

--Q5
SELECT DISTINCT 
    customernumber,
    orderlinenumber,
    vwCustomerOrder.ordernumber
FROM vwCustomerOrder INNER JOIN orderdetails ON (vwCustomerOrder.ordernumber = orderdetails.ordernumber) 
WHERE customernumber = 124
ORDER BY ordernumber, orderlinenumber;

--Q6
SELECT DISTINCT 
    customers.customernumber, 
    contactfirstname, 
    contactlastname, 
    phone, 
    creditlimit 
FROM customers
LEFT JOIN orders ON (customers.customernumber = orders.customernumber)
WHERE orders.customernumber IS NULL;
                
 --Q7
CREATE VIEW vwEmployeemanager AS
SELECT *
FROM employees
WHERE reportsto IS NULL OR reportsto IS NOT NULL;

 --Q8
 
 
 --Q9
 DROP VIEW vwCustomerOrder;
 DROP VIEW vwEmployeeManagers;