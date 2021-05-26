BEGIN TRANSACTION;
CREATE TABLE Seller(
    Seller_Id CHAR(3) PRIMARY KEY,
    Seller_Name CHAR(10), 
    Rating FLOAT,
    CHECK(RATING BETWEEN 0 AND 5)
);

CREATE TABLE Category (
    Category_Id CHAR(3) PRIMARY KEY, 
    Category CHAR(10)
);

CREATE TABLE Product (
    Product_Id CHAR(4) PRIMARY KEY,
    Product VARCHAR(25), 
    amount INT, 
    Quantity_remaining INT, 
    Category_Id CHAR(3), 
    seller_id CHAR(3), 
    Rating INT DEFAULT 0,
    FOREIGN KEY(CATEGORY_ID) REFERENCES CATEGORY(CATEGORY_ID), 
    FOREIGN KEY(SELLER_ID) REFERENCES SELLER(SELLER_ID)
);

CREATE TABLE Customer ( 
    Customer_Id CHAR(5) PRIMARY KEY,
    name CHAR(10), 
    password VARCHAR(15)
);

CREATE TABLE Orders (
    Order_id CHAR(5) PRIMARY KEY,
    customer_id CHAR(10), 
    amount INT, 
    TIME_STAMP_OF_ORDER DATE,
    FOREIGN KEY(CUSTOMER_ID) REFERENCES CUSTOMER(CUSTOMER_ID)
);

CREATE TABLE Order_Products(
    Order_id CHAR(5) PRIMARY KEY,
    Product_id CHAR(4), 
    quantity INT , 
    seller_id CHAR(3), 
    Original_amount INT, 
    discount INT, 
    product_Rating INT ,
    FOREIGN KEY(ORDER_ID) REFERENCES ORDERS(ORDER_ID),
    FOREIGN KEY(PRODUCT_ID,PRODUCT_RATING) REFERENCES PRODUCT(PRODUCT_ID,RATING),
    FOREIGN KEY(SELLER_ID) REFERENCES SELLER(SELLER_ID)
);

INSERT INTO SELLER (Seller_Id, Seller_Name, Rating) VALUES ('1S', 'Abhay', 3.3);
INSERT INTO SELLER (Seller_Id, Seller_Name, Rating) VALUES ('2S', 'Priya', 1);
INSERT INTO SELLER (Seller_Id, Seller_Name, Rating) VALUES ('3S', 'Kishan', 4.8);
INSERT INTO SELLER (Seller_Id, Seller_Name, Rating) VALUES ('4S', 'Vicky', 4.3);
INSERT INTO SELLER (Seller_Id, Seller_Name, Rating) VALUES ('5S', 'Sneha', 3.6);
INSERT INTO SELLER (Seller_Id, Seller_Name, Rating) VALUES ('6S', 'Pushpa', 2.8);

INSERT INTO CATEGORY (Category_Id, Category) VALUES ('1C', 'Books');
INSERT INTO CATEGORY (Category_Id, Category) VALUES ('2C', 'Footwear');
INSERT INTO CATEGORY (Category_Id, Category) VALUES ('3C', 'Home Decor');
INSERT INTO CATEGORY (Category_Id, Category) VALUES ('4C', 'Accessories');

INSERT INTO PRODUCT (Product_Id, Product, Amount, Quantity_Remaining, Category_Id, Seller_Id) VALUES 
('1P', 'The Programming language of ORACLE', 350, 4, '1C', '1S'),
('2P', 'Nike White shoes', 7000, 2, '2C', '3S'),
('3P', 'White Lamp', 800, 3, '3C', '5S'),
('4P', 'Antique Silver Earrings', 400, 7, '4C', '2S'),
('5P', 'Antique Silver Bracelet', 700, 5, '4C', '6S'),
('6P', 'Catwalk leather flats', 1599, 3, '2C', '4S'),
('7P', 'Introduction to Java', 650, 8, '1C', '5S'),
('8P', 'Portico King size bedsheet', 1999, 1, '3C', '1S'),
('9P', 'Book rack', 999, 7, '3C', '4S'),
('10P', 'Artificial Intelligence 3rd Edition', 570, 9, '1C', '2S'),
('11P', 'Introduction to python', 630, 10, '1C', '5S');

INSERT INTO CUSTOMER (CUSTOMER_ID, NAME, PASSWORD) VALUES
('CST01','ABRAHM LINCON','AB@LI'),
('CST02','GRAHAM BELL','#BELL'),
('CST03','NICHOLA TESLA','@TESLA'), 
('CST04','SWAMI VIVEKANAND','@SWAMI'), 
('CST05','VIRAT KOHLI','@RUN MACHINE'),
('CST06','LIONELL MESSI','FOOTBALL'),
('CST07','DUCKWARD LEWIS','drs'),
('CST08','PIED PIPPER','SILICONVALLEY'),
('CST09','STUART LITTLE','@MOUSE'),
('CST10','AXAR PATEL','MOTERA');

INSERT INTO ORDERS(Order_id, customer_id, amount, TIME_STAMP_OF_ORDER) VALUES 
('O0001', 'CST01', 6500, '2021-03-09 10:00'),
('O0002', 'CST03', 760, '2021-03-07 12:00'),
('O0003', 'CST04', 350, '2021-03-08 18:00'),
('O0004', 'CST06', 6900, '2021-03-09 12:00'),
('O0005', 'CST08', 400, '2021-03-08 16:00'),
('O0006', 'CST09', 700, '2021-03-09 17:00'),
('O0007', 'CST01', 350, '2021-03-05 09:00'),
('O0008', 'CST03', 1900, '2021-03-09 11:00'),
('O0009', 'CST08', 350, '2021-03-06 10:00'),
('O0010', 'CST01', 970, '2021-03-08 14:00');

INSERT INTO Order_Products
( Order_id, Product_id, quantity, seller_id, Original_amount, discount, product_Rating) VALUES
('O0001', '2P', 1, '3S', 7000, 500, 4),
('O0002', '3P', 1, '5S', 800, 40, 3.5),
('O0003', '1P', 1, '1S', 350, 0, 3.8),
('O0004', '2P', 1, '3S', 7000, 100, 4.5),
('O0005', '4P', 1, '2S', 400, 0, 2.9),
('O0006', '5P', 1, '6S', 700, 0, 4),
('O0007', '1P', 1, '1S', 350, 0, 3.6),
('O0008', '8P', 1, '1S', 1999, 99, 4.8),
('O0009', '1P', 1, '1S', 350, 0, 4.7),
('O0010', '9P', 1, '4S', 999, 29, 4.3);

-- Saving the Work
COMMIT;

-------------------------------------------------------------------
-- For Output Formatting [Human Understandable Form] in SQLite
.mode column
.headers on
.separator ROW "\n"
.nullvalue NULL
-------------------------------------------------------------------

-- SELECT * FROM SELLER;
-- SELECT * FROM CATEGORY;
-- SELECT * FROM PRODUCT;
-- SELECT * FROM CUSTOMER;
-- SELECT * FROM ORDERS;
-- SELECT * FROM Order_Products;

-- 1. Display the highest sold product details.  

-- SELECT *
-- FROM PRODUCT, ( SELECT P,MAX(COUNTS)
--                 FROM (  SELECT PRODUCT_ID P, COUNT(PRODUCT_ID) AS COUNTS 
--                         FROM ORDER_PRODUCTS O
--                         GROUP BY PRODUCT_ID
--                      ))
--                 WHERE PRODUCT.PRODUCT_ID = P;

-- 2. Update product rating column in product table as per the entries in order_product table (calculate average) 

-- DO NOT COMMENT THE BELOW LINE
UPDATE PRODUCT
SET RATING=(	SELECT AVG(PRODUCT_RATING)
                FROM ORDER_PRODUCTS OLD 
                GROUP BY PRODUCT_ID
                HAVING OLD.PRODUCT_ID=PRODUCT.PRODUCT_ID 
);

-- select * from PRODUCT;

-- 3. Add a new seller with all details. [Gada Electronics!]

-- DO NOT COMMENT THE BELOW LINE
INSERT INTO SELLER VALUES('7S','JETHALAL','4.5'); 
-- SELECT * FROM SELLER;

-- 4. Add a new product with all details.

-- DO NOT COMMENT THE BELOW LINE
INSERT INTO PRODUCT VALUES('12P','THE ATOMIC HABIT',350,3,'1C','7S',4.6);
-- SELECT * FROM PRODUCT;

-- 5. Display the details of the products which have never sold. 

-- SELECT *
-- FROM PRODUCT P
-- WHERE P.PRODUCT_ID NOT IN ( SELECT PRODUCT_ID
--                             FROM ORDER_PRODUCTS);

-- 6. Display the details of the seller who has not sold any product today.

-- SELECT *
-- FROM SELLER
-- WHERE SELLER_ID NOT IN ( SELECT SELLER_ID
--                          FROM ORDER_PRODUCTS
--                          WHERE ORDER_ID IN (SELECT ORDER_ID
--                                             FROM ORDERS
--                                             WHERE STRFTIME("%Y-%m-%d",ORDERS.TIME_STAMP_OF_ORDER) IS '2021-03-09')
-- );
-- NOTE: Observe that the New Seller “JETHALAL” who was added recently, has not sold any Product and therefore is also there in the List.

-- 7. Display the details of the seller who has sold the highest amount of products today.

-- SELECT *
-- FROM SELLER S, (SELECT SI ,MAX(SUMATION)
--                 FROM (SELECT SELLER_ID AS SI, SUM(ORIGINAL_AMOUNT- DISCOUNT) AS SUMATION
--                 FROM ORDER_PRODUCTS 
--                 GROUP BY SELLER_ID))
--                 WHERE S.SELLER_ID=SI;

-- 8. Display the product details with the highest rating. 

-- SELECT *
-- FROM PRODUCT
-- WHERE RATING IS ( SELECT MAX(RATING)
--                   FROM PRODUCT);

-- 9. Display the customer details who has repeated the same product purchase in the last three months. 

-- Added the Order Purchase Repeated by 'CST01' Customer
-- DO NOT COMMENT THESE TWO LINES
INSERT INTO ORDERS( Order_id, customer_id, amount, TIME_STAMP_OF_ORDER ) VALUES 
('O0011','CST01',350,'2021-03-09 16:00');

INSERT INTO Order_Products
( Order_id, Product_id, quantity, seller_id, Original_amount, discount, product_Rating )
VALUES ('O0011', '1P',1,'1S',350,0,4);

-- SELECT *
-- FROM CUSTOMER
-- WHERE CUSTOMER_ID IN (  SELECT O1.CUSTOMER_ID
--                         FROM (ORDERS NATURAL JOIN ORDER_PRODUCTS) O1 ,(ORDERS NATURAL JOIN ORDER_PRODUCTS) O2
--                         WHERE O1.CUSTOMER_ID=O2.CUSTOMER_ID AND O1.ORDER_ID IS NOT O2.ORDER_ID AND O1.PRODUCT_ID=O2.PRODUCT_ID
--                         AND JULIANDAY('now')-JULIANDAY(O1.TIME_STAMP_OF_ORDER)<=90
-- );

-- 10. Display the seller details who is second highest in selling products in the last three months.

-- Note : HERE IN THIS QUESTION IT IS CONSIDERED THAT "HIGHEST IN SELLING PRODUCTS" = "HIGHEST QUANTITY SOLD"
-- IF ABOVE ONE IS NOT TRUE RATHER IF IT IS "HIGHEST IN SELLING PRODUCTS" = "HIGHEST AMOUNT"
-- THEN REPLACING QUANTITY TO AMOUNT WILL WORK AS PER REQUIREMENTS  

-- CREATE TABLE TEMPORARY(
--     SELLER_ID CHAR(3), 
--     TOTAL_QUANTITY INT
-- );

-- INSERT INTO TEMPORARY
-- SELECT SELLER_ID ,SUM(QUANTITY)
-- FROM (  SELECT *
--         FROM ORDER_PRODUCTS NATURAL JOIN ORDERS
--         WHERE JULIANDAY('now')-JULIANDAY(TIME_STAMP_OF_ORDER)<=90)
-- GROUP BY SELLER_ID;

-- SELECT *
-- FROM SELLER
-- WHERE SELLER_ID IN (    SELECT SELLER_ID 
--                         FROM (  SELECT SELLER_ID , MAX(TOTAL_QUANTITY) AS salary 
--                                 FROM TEMPORARY 
--                                 WHERE TOTAL_QUANTITY < (SELECT MAX(TOTAL_QUANTITY) FROM TEMPORARY))
-- ); 

-- DROP TABLE TEMPORARY;

-- 11. Display products in the descending order of product amount sold by the seller who is having the highest rating.

-- SELECT DISTINCT PRODUCT_ID, PRODUCT , AMOUNT , QUANTITY_REMAINING , CATEGORY_ID , SELLER_ID
-- FROM (ORDER_PRODUCTS NATURAL JOIN PRODUCT) 
-- WHERE SELLER_ID IN (SELECT SID
--                     FROM (SELECT SELLER_ID SID, MAX(RATING) FROM SELLER))
--                     ORDER BY ORIGINAL_AMOUNT-DISCOUNT DESC;

--12. Update the seller ratings as per the new entries in Order_Products table. 

-- SELECT * FROM SELLER;

-- UPDATE SELLER
-- SET RATING=(	
--     SELECT AVG(PRODUCT_RATING)
--     FROM ORDER_PRODUCTS OP 
--     GROUP BY SELLER_ID
--     HAVING OP.SELLER_ID=SELLER.SELLER_ID 
-- );

-- SELECT * FROM SELLER;

-- 13. Display the list of products having quantity remaining <= 4. 

-- select product_id , product from product
-- where quantity_remaining <= 4;



