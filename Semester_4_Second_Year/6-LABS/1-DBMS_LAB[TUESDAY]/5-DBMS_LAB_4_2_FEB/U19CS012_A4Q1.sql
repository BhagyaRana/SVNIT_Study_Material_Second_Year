BEGIN TRANSACTION;

CREATE TABLE EMPLOYEE(
    emp_id integer PRIMARY KEY,
    emp_name text,
    department text,
    manager_id integer,
    -- YEAR MONTH DAY [Important Mistake!]
    joining_date DATE,
    salary integer
);

-- Insert 10 Rows in the above created table. 

INSERT INTO EMPLOYEE VALUES(
    4123,
    'Ninja_Hatori',
    'Production',
    1002,
    '2020-04-01',
    65000
);

INSERT INTO EMPLOYEE VALUES(
    4129,
    'Ajay',
    'Research',
    1027,
    '2018-04-02',
    45000
);

INSERT INTO EMPLOYEE VALUES(
    4230,
    'Mickey',
    'Marketing',
    1022,
    '2016-04-03',
    35000
);

INSERT INTO EMPLOYEE VALUES(
    4428,
    'Kiteretsu',
    'Accounting',
    1012,
    '2019-04-04',
    75000
);

INSERT INTO EMPLOYEE VALUES(
    4073,
    'Shizuka',
    'HR',
    1035,
    '2020-04-05',
    60000
);

INSERT INTO EMPLOYEE VALUES(
    4983,
    'Aditya',
    'HR',
    1035,
    '2017-04-06',
    100000
);

INSERT INTO EMPLOYEE VALUES(
    4009,
    'Nobita',
    'Research',
    1027,
    '2015-04-07',
    50000
);

INSERT INTO EMPLOYEE VALUES(
    4773,
    'Doraemon',
    'Marketing',
    1022,
    '2020-04-08',
    25000
);

INSERT INTO EMPLOYEE VALUES(
    4833,
    'Gian',
    'Accounting',
    1012,
    '2018-04-09',
    95000
);

INSERT INTO EMPLOYEE VALUES(
    4337,
    'Donald',
    'HR',
    1035,
    '2012-04-10',
    55000
);

INSERT INTO EMPLOYEE VALUES(
    4113,
    'Akash',
    'HR',
    1035,
    '2017-04-06',
    110000
);

INSERT INTO EMPLOYEE VALUES(
    4010,
    'Naruto',
    'HR',
    1027,
    '2013-05-09',
    52000
);

INSERT INTO EMPLOYEE VALUES(
    4768,
    'Dishant',
    'Marketing',
    1022,
    '2019-08-02',
    35000
);

INSERT INTO EMPLOYEE VALUES(
    4830,
    'Gopal',
    'Marketing',
    1012,
    '2020-08-01',
    83000
);

INSERT INTO EMPLOYEE VALUES(
    4331,
    'Deepak',
    'Marketing',
    1022,
    '2014-02-14',
    57000
);

-- Saving the Work
COMMIT;

-- For Checking the Inserted Values
-- SELECT * FROM EMPLOYEE

-- 1. Display Manager Id of employees whose name starts with ‘A’.
SELECT manager_id FROM EMPLOYEE WHERE emp_name LIKE 'A%'
-- For Cross Checking
-- SELECT emp_name,manager_id FROM EMPLOYEE WHERE emp_name LIKE 'A%'

-- 2. Display employees Id and employee name, department wise.
SELECT emp_id,emp_name FROM EMPLOYEE ORDER BY department
-- For Cross Checking
-- SELECT department,emp_id,emp_name FROM EMPLOYEE ORDER BY department

-- 3. Display employee count department wise.
SELECT department,COUNT(*) FROM EMPLOYEE GROUP BY department

-- 4. Display all columns of employees whose experience is more than 3 years.
SELECT * FROM EMPLOYEE WHERE (joining_date)<(DATE('now','-3 year'))

-- 5. Display departments with more than 4 employees.
SELECT department FROM EMPLOYEE GROUP BY department HAVING COUNT(*)>4
-- For Cross Checking
-- SELECT department,COUNT(*) FROM EMPLOYEE GROUP BY department HAVING COUNT(*)>4

-- 6. Display employees Id and employee name whose salary is greater than 50000, department wise.
SELECT emp_id, emp_name FROM EMPLOYEE GROUP BY department HAVING salary>50000
-- For Checking
-- SELECT emp_id, emp_name, salary FROM EMPLOYEE GROUP BY department HAVING salary>50000

-- 7. Display department name and average salary of employees in department wise.
SELECT department,AVG(salary) FROM EMPLOYEE GROUP BY department

-- 8. Display Employee Id and Name of employee with highest salary.
SELECT emp_id, emp_name, MAX(salary) FROM EMPLOYEE 

-- 9. Display employees Id and employee name with least salary
SELECT emp_id, emp_name, MIN(salary) FROM EMPLOYEE 

-- 10. Display employees Id and employee name with second highest salary.
SELECT emp_id, emp_name, MAX(salary) FROM EMPLOYEE WHERE salary < (SELECT MAX(salary) FROM EMPLOYEE)
