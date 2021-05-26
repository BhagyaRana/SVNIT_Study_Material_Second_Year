BEGIN TRANSACTION;

CREATE TABLE EMPLOYEE(
    emp_no INTEGER PRIMARY KEY,
    emp_name TEXT NOT NULL,
    -- YEAR MONTH DAY [Important Mistake]
    emp_join_date DATE DEFAULT CURRENT_DATE,
    emp_status VARCHAR(1)
    -- No Semicolon at End of Last Attribute
);

CREATE TABLE PROJECT(
    proj_code TEXT PRIMARY KEY,
    proj_name TEXT NOT NULL UNIQUE,
    -- YEAR MONTH DAY [Important Mistake]
    proj_start_date DATE NOT NULL,
    proj_end_date DATE
    -- No Semicolon at End of Last Attribute
);

CREATE TABLE PROJ_ALLOC(
    rproj_code TEXT,
    remp_no  INTEGER,
    -- YEAR MONTH DAY [Important Mistake]
    emp_proj_alloc_date DATE,
    emp_proj_release_date DATE
    -- No Semicolon at End of Last Attribute
);

INSERT INTO EMPLOYEE VALUES(101, 'Jhonny', '2005-07-01', 'C');
INSERT INTO EMPLOYEE VALUES(116, 'Nayak', '2005-08-16', 'C');
INSERT INTO EMPLOYEE VALUES(202, 'Meera', '2006-01-30', 'C');
INSERT INTO EMPLOYEE VALUES(205, 'Ravi', '2006-02-11', 'C');
INSERT INTO EMPLOYEE VALUES(304, 'Hari', '2006-11-25', 'P');
INSERT INTO EMPLOYEE VALUES(307, 'Nancy', '2007-01-15', 'P');
INSERT INTO EMPLOYEE VALUES(403, 'Nick', '2007-01-21', 'P');

INSERT INTO PROJECT VALUES('P001', 'Environment Pollution', '2005-08-02', '2006-12-11');
INSERT INTO PROJECT VALUES('P002', 'Learning Curve', '2006-02-01', '2006-03-15');
INSERT INTO PROJECT VALUES('P003', 'Effects of IT', '2007-01-03', NULL);

INSERT INTO PROJ_ALLOC VALUES('P001', 101, '2005-08-01', '2006-12-11');
INSERT INTO PROJ_ALLOC VALUES('P001', 116, '2005-08-16', '2006-12-11');
INSERT INTO PROJ_ALLOC VALUES('P002', 202, '2006-02-01', '2007-01-14');
INSERT INTO PROJ_ALLOC VALUES('P002', 307, '2007-01-15', NULL);
INSERT INTO PROJ_ALLOC VALUES('P002', 205, '2006-02-11', NULL);
INSERT INTO PROJ_ALLOC VALUES('P003', 403, '2005-01-21', NULL);
INSERT INTO PROJ_ALLOC VALUES('P003', 304, '2006-01-03', NULL);
INSERT INTO PROJ_ALLOC VALUES('P003', 101, '2007-01-03', NULL);
INSERT INTO PROJ_ALLOC VALUES('P003', 116, '2006-01-03', NULL);
INSERT INTO PROJ_ALLOC VALUES('P003', 202, '2007-01-15', NULL);

-- Saving the Work
COMMIT;

-------------------------------------------------------------------

-- For Output Formatting [Human Understandable Form] in SQLite

.mode column
.headers on
.separator ROW "\n"
.nullvalue NULL

-------------------------------------------------------------------

-- SELECT * FROM EMPLOYEE;
-- SELECT * FROM PROJECT;
-- SELECT * FROM PROJ_ALLOC;

-- 1. List all the project names along with the employee names to whom the project is assigned. 
SELECT DISTINCT P.proj_name AS PROJECT_NAME,E.emp_name AS EMPLOYEE_NAME
FROM EMPLOYEE E, PROJECT P, PROJ_ALLOC R
WHERE (E.emp_no = R.remp_no) AND (P.proj_code = R.rproj_code) 
ORDER BY P.proj_code; 

-- 2. Display the name of employees whose status is confirmed. 
SELECT emp_name AS EMPLOYEE_NAME 
FROM EMPLOYEE
WHERE emp_status='C';

-- For Checking
SELECT emp_name AS EMPLOYEE_NAME,emp_status AS EMPLOYEE_STATUS 
FROM EMPLOYEE
WHERE emp_status='C';

-- 3. List the employees who have joined in the month of November. 
SELECT *
FROM EMPLOYEE
WHERE strftime('%m',emp_join_date) = '11';

-- 4. List the projects which have started after 1st Jan 2006. 
SELECT * 
FROM PROJECT
WHERE proj_start_date>'2006-01-01';

-- 5. List all the employees who are working for the project entitled ‘Effects of IT’. 
SELECT E.emp_no AS EMPLOYEE_NO, E.emp_name AS EMPLOYEE_NAME
FROM EMPLOYEE E, PROJECT P,PROJ_ALLOC R
WHERE (P.proj_name = 'Effects of IT') AND (P.proj_code = R.rproj_code) AND (R.remp_no = E.emp_no);  

-- 6. List all the projects that are not yet completed. 
SELECT * 
FROM PROJECT
WHERE proj_end_date IS NULL;

-- 7. Display the Employees who are released from project having code P002. 
SELECT E.emp_no AS EMPLOYEE_NO, E.emp_name AS EMPLOYEE_NAME
FROM EMPLOYEE E, PROJECT P, PROJ_ALLOC R
WHERE (P.proj_code = 'P002') AND (R.emp_proj_release_date IS NOT NULL) AND (P.proj_code = R.rproj_code) AND (R.remp_no = E.emp_no);  

-- 8. Count and display the number of days it took for the completion of project P002.
SELECT (julianday(proj_end_date)-julianday(proj_start_date)) AS DAYS_TAKEN_P002
FROM PROJECT
WHERE proj_code='P002';

-- 9. List the name of employees along with the number of days they have worked for projects allocated to them. 
SELECT E.emp_no,E.emp_name,P.proj_name,(CASE 
    WHEN  R.emp_proj_release_date IS NOT NULL
        THEN (julianday(R.emp_proj_release_date)-julianday(R.emp_proj_alloc_date))
    -- Any Reference Date can be Chosen, Here 1st Jan, 2009 
    ELSE (julianday('2009-01-01')-julianday(R.emp_proj_alloc_date)) 
        END) AS DAYS_TAKEN 
FROM EMPLOYEE E, PROJECT P, PROJ_ALLOC R
WHERE (P.proj_code = R.rproj_code) AND (R.remp_no = E.emp_no);

-- 10. Add a column Manager_id in the Projects table.
-- <NOT TO BE COMMENTED>
ALTER TABLE PROJECT ADD manager_id;
-- SELECT * FROM PROJECT;

-- 11. Update the Projects table with the following data:
-- Don't Forget to Uncomment the Query 10 to add manager_id to Table [Online Editor]
-- <NOT TO BE COMMENTED>
UPDATE PROJECT SET manager_id = 101 WHERE proj_code = 'P001';
UPDATE PROJECT SET manager_id = 202 WHERE proj_code = 'P002';
UPDATE PROJECT SET manager_id = 116 WHERE proj_code = 'P003';
-- SELECT * FROM PROJECT;

-- 12. A new project entitled “Election Rage” which will be starting on 1st March 2007 has been received.
--  Add these details in Projects table. 
-- <NOT TO BE COMMENTED>
INSERT INTO PROJECT (proj_code, proj_name, proj_start_date) VALUES('P004','Election Rage','2007-03-01');
-- SELECT * FROM PROJECT;

-- 13. Project named “Effects of IT” is cancelled. Remove its details from the Projects table. 
-- DELETE FROM PROJECT WHERE proj_name='Effects of IT';
-- SELECT * FROM PROJECT;

-- 14. List the projects with a time duration of more than 13 months [1yr + 1 month = 365 + 30 days = 395 days]. 
SELECT P.proj_code, P.proj_name, Q.DAYS_TAKEN/30 AS 'AVERAGE MONTHS' 
FROM PROJECT AS P, (
    SELECT P1.proj_code,( CASE 
    WHEN P1.proj_end_date IS NOT NULL
        THEN (julianday(P1.proj_end_date)-julianday(P1.proj_start_date))
    ELSE
        (julianday('2009-01-01')-julianday(P1.proj_start_date)) 
    END) AS DAYS_TAKEN 
    FROM PROJECT AS P1
) AS Q
WHERE (DAYS_TAKEN>(394)) AND (Q.proj_code = P.proj_code);

-- 15. List the number of employees, project wise who have worked on the project in Feb – 2007.
SELECT P.proj_code, P.proj_name, COUNT(FEB_WORK.remp_no) AS NUMBER_OF_EMPLOYEES
FROM (
    SELECT remp_no, rproj_code 
    FROM PROJ_ALLOC
    WHERE (emp_proj_alloc_date <= '2007-02-01') AND ((emp_proj_release_date IS NULL) OR (emp_proj_release_date>='2007-02-28'))   
) AS FEB_WORK, PROJECT AS P
WHERE (FEB_WORK.rproj_code = P.proj_code) GROUP BY FEB_WORK.rproj_code;
