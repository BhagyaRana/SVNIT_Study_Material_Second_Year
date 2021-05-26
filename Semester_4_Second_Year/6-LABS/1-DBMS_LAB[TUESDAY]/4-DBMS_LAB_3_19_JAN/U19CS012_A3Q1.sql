BEGIN TRANSACTION;

CREATE TABLE STUDENT(
    roll_no integer PRIMARY KEY,
    name text,
    semester integer,
    -- YEAR MONTH DAY [Important Mistake!]
    date_of_birth DATE,
    admission_date DATE,
    hostel_room integer
    -- Null Values also Allowed in Hostel Room
);

-- Insert 10 Rows in the above created table. 

INSERT INTO STUDENT VALUES(
    101,
    'Bhagya',
    4,
    '2001-01-02',
    '2001-02-03',
    104
);

INSERT INTO STUDENT VALUES(
    201,
    'Nobita',
    3,
    '2001-03-04',
    '2001-04-05',
    745
);

INSERT INTO STUDENT VALUES(
    103,
    'Doraemon',
    5,
    '2001-05-06',
    '2001-06-07',
    450
);

INSERT INTO STUDENT VALUES(
    204,
    'Shizuka',
    4,
    '2001-07-08',
    '2001-08-09',
    789
);

INSERT INTO STUDENT VALUES(
    150,
    'Sunio',
    4,
    '2001-09-02',
    '2001-10-03',
    912
);

INSERT INTO STUDENT VALUES(
    612,
    'Gian',
    3,
    '2000-11-04',
    '2001-12-05',
    312
);

INSERT INTO STUDENT VALUES(
    107,
    'Kiteretsu',
    4,
    '2001-01-06',
    '2001-02-07',
    390
);

INSERT INTO STUDENT VALUES(
    118,
    'Shinchan',
    2,
    '2001-03-08',
    '2001-04-09',
    881
);

INSERT INTO STUDENT VALUES(
    190,
    'Harry',
    6,
    '2000-05-02',
    '2001-06-03',
    654
);

INSERT INTO STUDENT VALUES(
    210,
    'Salman',
    4,
    '2000-07-04',
    '2001-08-07',
    981
);

-- Saving the Work
COMMIT;

-- 1. Student table with all columns and rows. 
SELECT * FROM STUDENT;

-- 2. Student details with columns Roll number and Name only. 
SELECT roll_no, name FROM STUDENT;

-- 3. Student details of all the students who are in 4th semester. 
SELECT * FROM STUDENT WHERE semester==4;

-- 4. Student details of all the students whose roll number is between 100 to 200. 
SELECT * FROM STUDENT WHERE roll_no>=100 and roll_no<=200;

-- 5. Student details of all the students whose DOB is greater than 1st jan 2001. 
SELECT * FROM STUDENT WHERE date_of_birth > '2001-01-01';

