CREATE TABLE staff (
    empid INT GENERATED BY DEFAULT ON NULL AS IDENTITY PRIMARY KEY,
    firstname VARCHAR(25) NOT NULL,
    lastname VARCHAR(25) NOT NULL,
    city VARCHAR(20),
    phone NUMBER(10) NOT NULL,
    maxcust DECIMAL(0,2) DEFAULT 0 NOT NULL CHECK(maxcust BETWEEN 0 and 20),
    startdate DATE NOT NULL,
    active BOOLEAN DEFAULT 1,
    FOREIGN KEY (city) REFERENCES cities(city)
);
INSERT INTO staff(firstname, lastname, city, phone, maxcust, startdate, active)
VALUES('Clint', 'MacDonald', 'Toronto', 64722221111, 18, 1);

INSERT INTO customer(empid, custname, membernumber, email, address, balance)
VALUES(1011, 'Hoang Nguyen', '21za25', 'hdnguyen12@myseneca.ca', '1700 Keele St', 300);

UPDATE customers
SET lastname = 'Brown'
WHERE empid = 1007;

DELETE customer
WHERE custid = 3;

SELECT c.balance, s.country || '(' || cit.countrycode || ')' ||
FROM staff s, customer c, cities cit 
WHERE s.empid = c.empid AND s.country = c.country