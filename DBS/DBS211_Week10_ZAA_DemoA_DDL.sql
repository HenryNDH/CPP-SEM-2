-- -----------------------------------
-- DBS211 ZAA - Winter 2022
-- March 21, 2022
-- Clint MacDonald
-- Introduction to DDL (Create, Drop, Alter, Constraints)
-- -----------------------------------
-- Data Definition Language

-- CREATE TABLE syntax
/*
CREATE TABLE <tablename> (
    <fieldname> <data type/size> <constraint(s)>,
    <fieldname> <data type/size> <constraint(s)>,
    .....,
    <fieldname> <data type/size> <constraint(s)>,
    CONSTRAINT <constraint name> <constraint type> <constraint details>,
    CONSTRAINT <constraint name> <constraint type> <constraint details>,
    .....,
    CONSTRAINT <constraint name> <constraint type> <constraint details>
);
*/

-- CONSTRAINTS
-- There are 7 different constraint in database
-- it is important to note that different DBMSs implement constraint slightly different.
-- 1) Primary Key - unique identifier
-- 2) Foreign Key - child reference - implementation of referential integrity
-- 3) Required - NOT NULL - can not insert a null value into this cell
-- 4) Unique - no repeating values
-- 5) Default - allows you to insert a value if a null was inserted
-- 6) Range - sets a range of permissable values
-- 7) Index - field on which the data is duplicated and pre-sorted to optimize searching

-- AUTONUMBER fields
  -- GENERATED BY DEFAULT ON NULL AS IDENTITY
  -- in MS SQL -    IDENTITY(1,1)

-- Dropping Tables
-- ***********************************
-- The easy way
-- DROP TABLE <tablename> CASCADE CONSTRAINTS

-- The RIGHT way
BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE offices CASCADE CONSTRAINTS';
EXCEPTION
    WHEN OTHERS THEN NULL;
END;

-- Let us use BOB's CAR LOT as an example database to create some tables.

-- Let us start with the People Table
BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE bclPeople CASCADE CONSTRAINTS';
EXCEPTION
    WHEN OTHERS THEN NULL;
END;
-- Create table
CREATE TABLE bclPeople (
    peopleID INT GENERATED BY DEFAULT ON NULL AS IDENTITY PRIMARY KEY,
    firstName VARCHAR(25) NOT NULL,
    lastName VARCHAR(30) NOT NULL, 
    street VARCHAR(25),
    city VARCHAR(25) NOT NULL,
    prov CHAR(2) DEFAULT 'ON',
    pc CHAR(6),
    phone NUMBER(11) NOT NULL,
    phoneType CHAR(1) CHECK(phoneType IN ('W','H','M','F','P')),
    dob DATE,
    email VARCHAR(100) NOT NULL
);

-- EMPLOYEES TABLE
BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE bclEmployees CASCADE CONSTRAINTS';
EXCEPTION
    WHEN OTHERS THEN NULL;
END;
-- create table
CREATE TABLE bclEmployees (
    employeeNumber INT PRIMARY KEY,
    department CHAR(2) NOT NULL,
    hireDate DATE NOT NULL,
    leaveDate DATE,
    jobTitle VARCHAR(20) NOT NULL,
    sin INT,
    CONSTRAINT emp_sin_chk CHECK(sin BETWEEN 100000000 AND 999999999),
    CONSTRAINT emp_people_fk FOREIGN KEY (employeeNumber) 
                            REFERENCES bclPeople(peopleID) 
);

-- Wednesday Class

-- Customer TABLE
BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE bclCustomers CASCADE CONSTRAINTS';
EXCEPTION
    WHEN OTHERS THEN NULL;
END;
-- create table
CREATE TABLE bclCustomers (
    customerNumber INT PRIMARY KEY,
    creditLimit NUMBER(9,2) DEFAULT 0 NOT NULL,
    CONSTRAINT cust_cl_chk CHECK (creditLimit BETWEEN 0 AND 250000),
    CONSTRAINT peo_cust_fk FOREIGN KEY (customerNumber)
                REFERENCES bclPeople(peopleID)
);

-- ORDERS TABLE
BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE bclOrders CASCADE CONSTRAINTS';
EXCEPTION
    WHEN OTHERS THEN NULL;
END;
-- create table
CREATE TABLE bclOrders (
    orderNumber INT GENERATED BY DEFAULT ON NULL AS IDENTITY PRIMARY KEY,
    customer INT NOT NULL, 
    salesPerson INT,
    notes LONG,
    status CHAR(2) DEFAULT 'PE' NOT NULL
);

ALTER TABLE bclOrders
    ADD orderDate DATE;
-- CARS TABLE
BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE bclCars CASCADE CONSTRAINTS';
EXCEPTION
    WHEN OTHERS THEN NULL;
END;
-- create table
CREATE TABLE bclCars (
    VIN CHAR(16) PRIMARY KEY,
    yr NUMBER(4) CHECK (yr BETWEEN 1900 AND 2072) NOT NULL,
    carModel VARCHAR(20) NOT NULL,
    transmission VARCHAR(20),
    mileage INT,
    colour VARCHAR(25),
    sellingPrice DECIMAL(9,2),
    purchaseCost DECIMAL(9,2),
    isCertified NUMBER(1) DEFAULT 0 NOT NULL
)

-- ORDER_CARS table (Junction/Bridge Table with a composite key)
BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE bclOrder_Cars CASCADE CONSTRAINTS';
EXCEPTION
    WHEN OTHERS THEN NULL;
END;
-- create table
CREATE TABLE bclOrder_Cars (
    vin CHAR(16),
    orderNumber INT,
    soldPrice DECIMAL(9,2) NOT NULL,
    CONSTRAINT ord_ordCars_fk FOREIGN KEY (orderNumber)
                REFERENCES bclOrders(orderNumber),
    CONSTRAINT cars_ordCars_fk FOREIGN KEY (vin)
                REFERENCES bclCars(vin),
    CONSTRAINT ordCars_pk PRIMARY KEY (vin, orderNumber)
);

-- Changing Tables AFTER they have already been created

ALTER TABLE bclOrders
    ADD CONSTRAINT ord_cust_fk FOREIGN KEY (customer)
        REFERENCES bclCustomers(customerNumber);

ALTER TABLE bclOrders
    ADD CONSTRAINT ord_emps_fk FOREIGN KEY (salesPerson)
        REFERENCES bclEmployees(employeeNumber);

-- add a new column to a table afterwards
ALTER TABLE bclCars
    ADD numDoors NUMBER(3) DEFAULT 4;

INSERT INTO bclCars VALUES ('1234567891234567',2022,'Civic',
    '4 speed auto', 19254, 'Gun Grey', 25000, 22000, 1, 4);

ALTER TABLE bclCars
    ADD engineSize NUMBER(5) CHECK (engineSize BETWEEN 50 and 2000);

UPDATE bclCars SET engineSize = 180 WHERE vin = '1234567891234567';

ALTER TABLE bclCars
    ADD CONSTRAINT cars_engine_nn NOT NULL; -- DOES NOT WORK

ALTER TABLE bclCars
    ADD CONSTRAINT cars_engine_nn CHECK (engineSize IS NOT NULL);

-- Creating TEMP tables based on existing tables

CREATE TABLE bclTEMPcars AS 
    SELECT * FROM bclCars;
ALTER TABLE bclTEMPcars ADD CONSTRAINT temp_cars_pk PRIMARY KEY(vin);

CREATE TABLE bclOrders2021 AS
    SELECT * FROM bclOrders WHERE EXTRACT(YEAR FROM orderDate) = 2021;

DELETE FROM bclOrders WHERE EXTRACT(YEAR FROM orderDate) = 2021;

CREATE TABLE bclTEMPOrdersTEST AS
    SELECT orderNumber, customer, orderDate FROM bclOrders;


CREATE VIEW vwbclCars AS (SELECT * FROM bclCars);

SELECT * FROM vwbclCars;

UPDATE bclCars SET sellingPrice = 10000 WHERE vin = '1234567891234567'; 

SELECT * FROM (SELECT * FROM bclCars);
