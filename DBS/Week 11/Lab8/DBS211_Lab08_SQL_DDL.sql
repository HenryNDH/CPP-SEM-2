--Name:    Hoang Duy Nguyen
--ID:      108397217
--Date:    29 Mar 2022
--Purpose: DBS211 Lab 08

SET AUTOCOMMIT ON; 

--Part A (DDL) :
--1.	Create table the following tables and their given constraints:
--L5_MOVIES (movieid:int, title:varchar(35), year:int, director:int,score:decimal(3,2))	
CREATE TABLE L5_MOVIES (
    mid int PRIMARY KEY,
    title varchar(35) NOT NULL,
    releaseYear int NOT NULL, 
    director int NOT NULL, 
    score decimal(3,2) CHECK (score <= 5 AND score >= 0)
);

--L5_ACTORS (actorid:int, name:varchar(20), lastname:varchar(30))
CREATE TABLE L5_ACTORS (
    aid int PRIMARY KEY,
    firstName varchar(20) NOT NULL,
    lastName varchar(30) NOT NULL
); 

--L5_CASTINGS (movieid:int, actorid:int)	
CREATE TABLE L5_CASTINGS (
    movieid int,
    actorid int,
    PRIMARY KEY(movieid, actorid),
    CONSTRAINT cast_mov_fk FOREIGN KEY(movieid) 
                        REFERENCES L5_MOVIES(mid),
    CONSTRAINT cast_actor_fk FOREIGN KEY(actorid) 
                        REFERENCES L5_ACTORS(aid)
);

--L5_DIRECTORS(id:int, name:varchar(20), lastname:varchar(30))
CREATE TABLE L5_DIRECTORS (
    directorid int PRIMARY KEY,
    firstname varchar(20) NOT NULL,
    lastname varchar(30) NOT NULL
);

--2.	Modify the movies table to create a foreign key constraint that refers to table directors. 
ALTER TABLE L5_MOVIES
    ADD CONSTRAINT mov_dir_fk FOREIGN KEY (director) REFERENCES L5_DIRECTORS (directorid);
    
--3.	Modify the movies table to create a new constraint so the uniqueness of the movie title is guaranteed.     
ALTER TABLE L5_MOVIES
    ADD UNIQUE (title);
    
--4.	Write insert statements to add the following data to table directors and movies.

--directors
INSERT INTO L5_DIRECTORS (directorid, firstname, lastname)
VALUES (1010, 'Rob', 'Minkoff');
INSERT INTO L5_DIRECTORS (directorid, firstname, lastname)
VALUES (1020, 'Bill', 'Condon');
INSERT INTO L5_DIRECTORS (directorid, firstname, lastname)
VALUES (1050, 'Josh', 'Cooley');
INSERT INTO L5_DIRECTORS (directorid, firstname, lastname)
VALUES (2010, 'Brad', 'Bird');
INSERT INTO L5_DIRECTORS (directorid, firstname, lastname)
VALUES (3020, 'Lake', 'Bell');

--movies
INSERT INTO L5_MOVIES (mid, title, releaseYear, director, score)
VALUES (100, 'The Lion King', 2019, 3020, 3.50);
INSERT INTO L5_MOVIES (mid, title, releaseYear, director, score)
VALUES (200, 'Beauty and the Beast', 2017, 1050, 4.20);
INSERT INTO L5_MOVIES (mid, title, releaseYear, director, score)
VALUES (300, 'Toy Story 4', 2019, 1020, 4.50);
INSERT INTO L5_MOVIES (mid, title, releaseYear, director, score)
VALUES (400, 'Mission Impossible', 2018, 2010, 5.00);
INSERT INTO L5_MOVIES (mid, title, releaseYear, director, score)
VALUES (500, 'The Secret Life of Pets', 2016, 1010, 3.90);

--5.	Write SQL statements to remove all above tables. 

DROP TABLE L5_CASTINGS;
DROP TABLE L5_ACTORS;
DROP TABLE L5_MOVIES;
DROP TABLE L5_DIRECTORS;

--Is the order of tables important when removing? Why?
--Yes the order of tables important when removing because we cannot drop a table 
-- if there is aprimary keys referenced by foreign keys in another table

--I dropped CASTINGS before ACTORS and MOVIES because in CASTING I have 
-- <cast_mov_fk> and <cast_actor_fk>

--I dropped MOVIES before DIRECTORS because I have <mov_dir_fk>

--Part B (More DML):

--6.	Create a new empty table employee2 the same as table employees.  
--  Use a single statement to create the table and insert the data at the
--  same time.

CREATE TABLE employee2 AS
SELECT *
FROM employees; 

--7.	Modify table employee2 and add a new column username to this table. 
--    The value of this column is not required and does not have to be unique.

ALTER TABLE employee2
    ADD username varchar(30);
    
--8.    Delete all the data in the employee2 table
TRUNCATE TABLE employee2;

--9.	Re-insert all data from the employees table into your new table 
--    employee2 using a single statement. 
INSERT INTO employee2 (employeenumber, lastname, firstname, 
                        extension, email, officecode, reportsto, jobtitle)
SELECT *
FROM employees;

--10.	In table employee2, write a SQL statement to change the first name and 
--    the last name of employee with ID 1002 to your name. 
UPDATE employee2
SET lastname = 'Nguyen', firstname = 'Hoang'
WHERE employeenumber = 1002;

--11.	In table employee2, generate the email address for column username 
--    for each student by concatenating the first character of employee’s  
--    first name and the employee’s last name. For instance, the username of  
--    employee Peter Stone will be pstone. NOTE: the username is in all 
--    lower case letters.  
UPDATE employee2
SET username = LOWER(SUBSTR(firstname,1,1)) || LOWER(lastname);

--12.	In table employee2, remove all employees with office code 4. 
DELETE employee2
WHERE officecode = 4;

--13.   Drop table employee2. 
DROP TABLE employee2;