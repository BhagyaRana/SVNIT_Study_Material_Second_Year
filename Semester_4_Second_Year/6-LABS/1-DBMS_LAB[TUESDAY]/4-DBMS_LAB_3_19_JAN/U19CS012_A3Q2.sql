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
    'Garfield',
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
    '2020-04-03',
    35000
);

INSERT INTO EMPLOYEE VALUES(
    4428,
    'Kiteretsu',
    'Accounting',
    1002,
    '2019-04-04',
    75000
);

INSERT INTO EMPLOYEE VALUES(
    4073,
    'Shizuka',
    'HR',
    1027,
    '2020-04-05',
    60000
);

INSERT INTO EMPLOYEE VALUES(
    4983,
    'Mr.Bean',
    'HR',
    1002,
    '2017-04-06',
    100000
);

INSERT INTO EMPLOYEE VALUES(
    4009,
    'Nobita',
    'Research',
    1022,
    '2015-04-07',
    50000
);

INSERT INTO EMPLOYEE VALUES(
    4773,
    'Doraemon',
    'Marketing',
    1042,
    '2020-04-08',
    25000
);

INSERT INTO EMPLOYEE VALUES(
    4833,
    'Gian',
    'Accounting',
    1102,
    '2018-04-09',
    95000
);

INSERT INTO EMPLOYEE VALUES(
    4337,
    'Donald',
    'HR',
    1082,
    '2020-04-10',
    55000
);

-- Saving the Work
COMMIT;

-- 1. Employee table with all columns and rows. 
SELECT * FROM EMPLOYEE;
-- 2. Employee details with columns Name and Department only.
SELECT emp_name, department FROM EMPLOYEE;
-- 3. Employee details of all the Employees who are in HR department. 
SELECT * FROM EMPLOYEE where department=='HR';
-- 4. Employee details of all the Employees whose salary is between 50000 to 100000. 
SELECT * FROM EMPLOYEE WHERE salary>=50000 and salary<=100000;
-- 5. Employee details of all the Employees whose JoiningDate is greater than 1st jan 2020.
SELECT * FROM EMPLOYEE WHERE joining_date > '2020-01-01';
