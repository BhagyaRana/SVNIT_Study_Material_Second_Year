BEGIN TRANSACTION;

CREATE TABLE STUDENT(
    roll_no integer,
    stud_name text,
    semester integer,
    dept_name text,
    -- YEAR MONTH DAY [Important Mistake!]
    date_of_birth DATE,
    admission_date DATE,
    hostel_room integer
    -- Null Values also Allowed in Hostel Room
);

-- Insert 15 Rows in the above created table. 

INSERT INTO STUDENT VALUES(1,'Alfred',1,'C.S.E.','2002-02-14','2021-01-15',93);
INSERT INTO STUDENT VALUES(5,'Bunty',6,'CHEMICAL','2000-03-18','2018-03-18',120);
INSERT INTO STUDENT VALUES(7,'Sunio',8,'E.C.E.','1999-01-04','2017-05-24',178);
INSERT INTO STUDENT VALUES(22,'Gian',3,'CIVIL','2001-08-07','2019-07-13',NULL);
INSERT INTO STUDENT VALUES(1,'Kitretsu',2,'E.C.E.','2002-07-19','2020-09-22',198);

INSERT INTO STUDENT VALUES(8,'Larry',5,'C.S.E.','2000-08-21','2018-02-19',NULL);
INSERT INTO STUDENT VALUES(1,'Newton',2,'CHEMICAL','2002-09-27','2020-04-10',207);
INSERT INTO STUDENT VALUES(43,'Moore',4,'E.C.E.','2001-08-17','2019-06-11',NULL);
INSERT INTO STUDENT VALUES(1,'Sachin',1,'MECHANICAL','2000-10-09','2020-08-17',234);
INSERT INTO STUDENT VALUES(10,'Abdul',3,'CIVIL','2001-11-16','2019-10-03',217);

INSERT INTO STUDENT VALUES(21,'Arham',4,'C.S.E.','2001-03-15','2019-12-06',314);
INSERT INTO STUDENT VALUES(59,'John',1,'MECHANICAL','2002-08-25','2020-11-09',NULL);
INSERT INTO STUDENT VALUES(72,'Anand',7,'MECHANICAL','1999-12-30','2017-03-27',404);
INSERT INTO STUDENT VALUES(1,'Jethalal',6,'CIVIL','2000-10-11','2018-06-30',102);
INSERT INTO STUDENT VALUES(17,'Shizuka',3,'C.S.E.','2001-12-06','2019-07-12',NULL);

-- Saving the Work
COMMIT;

-- -----------------------------------------------------------------

-- For Output Formatting [Human Understandable Form] in SQLite
.mode column
.headers on
.separator ROW "\n"
.nullvalue NULL

-- For Checking the Inserted Values
-- SELECT * FROM STUDENT

-- 1. Display semester of students whose name has the letter ‘a’.
-- [GROP = Case Sensistive]  [LIKE = Case In-sensititive (A & a Both Tuples)]

-- SELECT semester FROM STUDENT WHERE stud_name LIKE "A%";
-- For Checking
-- SELECT stud_name,semester FROM STUDENT WHERE stud_name LIKE "A%";

-- 2. Display count of students semester wise.

-- SELECT semester AS "SEMESTER",COUNT(*) AS "NUMBER OF STUDENTS" FROM STUDENT GROUP BY semester;

-- 3. Display students' names from every department whose roll number is 1.

-- SELECT stud_name,roll_no,dept_name FROM STUDENT WHERE roll_no=1;

-- 4. Display student name and semester of students who are not staying in the hostel.

-- SELECT stud_name,semester FROM STUDENT WHERE hostel_room IS NULL;
-- For Checking
-- SELECT stud_name,semester,hostel_room FROM STUDENT WHERE hostel_room IS NULL;

-- 5. Display student count in each semester whose birth month is august.

-- SELECT semester, COUNT(*) AS "NUMBER OF STUDENTS" FROM STUDENT 
-- WHERE strftime('%m',date_of_birth) == '08'
-- GROUP BY semester ;
-- For Checking
-- SELECT stud_name,semester,date_of_birth FROM STUDENT WHERE strftime('%m',date_of_birth) == '08' ORDER BY semester;

-- 6. Display roll number and name of the student who was the first one to get admission in the college.

-- SELECT roll_no,stud_name,MIN(admission_date) FROM STUDENT ;

-- 7. Display the average count of students. ( In any semester)
-- SELECT AVG(cnt) FROM (SELECT COUNT(*) as cnt FROM STUDENT GROUP BY semester);

-- 8. For every month (Jan-Dec) display the count of students who are having birthdays in that month.
-- SELECT strftime("%m",date_of_birth) AS "MONTH [01-12]",COUNT(*) AS "NUMBER OF STUDENTS" 
-- FROM STUDENT
-- GROUP BY strftime("%m",date_of_birth);

-- 9. Display count of students who have taken admission in the last six months.

-- SELECT COUNT(*) AS "Last 6 Months Students Admitted" FROM STUDENT WHERE admission_date > (SELECT date('now','-6 month'));
-- For Checking
-- SELECT stud_name,admission_date FROM STUDENT WHERE admission_date > (SELECT date('now','-6 month'));

-- 10. Display semester with least number of students.

-- SELECT semester,COUNT(semester) FROM STUDENT 
-- GROUP BY semester 
-- HAVING COUNT(semester)==(SELECT MIN(semester) FROM (SELECT semester,COUNT(semester) FROM STUDENT GROUP BY semester));