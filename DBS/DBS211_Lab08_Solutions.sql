/*
Name: Clint MacDonald
Purpose: DBS211 Lab 8 
*/
SET AUTOCOMMIT ON;
-- -----------------------------------------------------------------------------------------------------------------------
-- Q1 Create table as shown on lab handout
DROP TABLE L5_movies;
CREATE TABLE L5_movies (
	mID 	    int 			Primary Key,
    title 		varchar(35)		not null,
    releaseYear	int				not null,
    director	int				not null,
    score		decimal(3,2) 	check(score between 0 AND 5)
	);

DROP TABLE L5_actors;
CREATE TABLE L5_actors (
	aID		    int				Primary Key,
    firstName	varchar(20)		not null,
    lastName	varchar(30)		not null
    );

DROP TABLE L5_castings;
CREATE TABLE L5_castings (
	movieID		int, 
	actorID		int,
    Primary Key (movieID, actorID)
    );
    
DROP TABLE L5_directors;
CREATE TABLE L5_directors (
	directorID	int,
    firstName	varchar(20)		not null,
    lastName	varchar(30)		not null,
    Primary Key (directorID)
    );
-- -----------------------------------------------------------------------------------------------------------------------
-- Q2
ALTER TABLE L5_movies
	ADD CONSTRAINT movie_directors_fk FOREIGN KEY (director) REFERENCES L5_directors(directorID);
-- -----------------------------------------------------------------------------------------------------------------------
-- Q3
ALTER TABLE L5_movies
	ADD CONSTRAINT moviename_unq UNIQUE (title);
-- -----------------------------------------------------------------------------------------------------------------------
-- Q4
INSERT ALL 
INTO L5_directors VALUES (1010, 'Rob', 'Minkoff')
INTO L5_directors VALUES (1020, 'Bill', 'Condon')
INTO L5_directors VALUES (1050, 'Josh', 'Cooley')
INTO L5_directors VALUES (2010, 'Brad', 'Bird')
INTO L5_directors VALUES (3020, 'Lake', 'Bell')
SELECT * FROM dual;

INSERT ALL
INTO L5_movies VALUES (100, 'The Lion King', 2019, 3020, 3.50)
INTO L5_movies VALUES (200, 'Beauty and the Beast', 2017, 1050, 4.20)
INTO L5_movies VALUES (300, 'Toy Story 4', 2019, 1020, 4.50)
INTO L5_movies VALUES (400, 'Mission Impossible', 2018, 2010, 5.00)
INTO L5_movies VALUES (500, 'The Secret Life of Pets', 2016, 1010, 3.90)
SELECT * FROM dual;
-- -----------------------------------------------------------------------------------------------------------------------
-- Q5
DROP TABLE L5_castings;
DROP TABLE L5_movies;
DROP TABLE L5_actors;
DROP TABLE L5_directors;
-- Yes, referential integrity
-- -----------------------------------------------------------------------------------------------------------------------
-- Q6 
CREATE TABLE employee2 AS SELECT * FROM employees;

-- -----------------------------------------------------------------------------------------------------------------------
-- Q7
ALTER TABLE employee2 
	ADD username varchar(16);

-- -----------------------------------------------------------------------------------------------------------------------
-- Q8
DELETE FROM employee2;
-- -----------------------------------------------------------------------------------------------------------------------
-- Q9
INSERT INTO employee2 
    SELECT employeenumber, 
        lastname, 
        firstname, 
        extension, 
        email, 
        officecode, 
        reportsto, 
        jobtitle, 
        NULL 
    FROM employees;

-- -----------------------------------------------------------------------------------------------------------------------
-- Q10
UPDATE employee2 SET firstname = 'Clint', lastname='MacDonald' 
	WHERE employeeNumber = 1002;

-- -----------------------------------------------------------------------------------------------------------------------
-- Q11
UPDATE employee2 SET username = lower(concat(substr(firstname, 1, 1), lastname));
SELECT * FROM employee2;
 -- -----------------------------------------------------------------------------------------------------------------------
-- Q12
DELETE FROM employee2
	WHERE OfficeCode = 4;
    
 -- -----------------------------------------------------------------------------------------------------------------------
-- Q13
DROP TABLE employee2;
