/*
Assignment 2
Group #1
Subject: DBS501
*/

--Q1

CREATE OR REPLACE PROCEDURE modify_sal(
    p_depno IN departments.department_id%TYPE)
IS
    CURSOR cur_sal IS
    SELECT salary, first_name, last_name, employee_id 
    FROM employees
    WHERE department_id = p_depno 
    AND salary < (SELECT AVG(salary)
                  FROM employees 
                  WHERE department_id = p_depno) FOR UPDATE NOWAIT;
               
    v_flag CHAR(1) := 'n';
    v_increase NUMBER := 0;
    v_emp# NUMBER := 0;
    v_cnt NUMBER := 0;
    v_avg employees.salary%TYPE;
    
    e_empty EXCEPTION;
    e_no_modified EXCEPTION;
    
BEGIN
    SELECT 'y' INTO v_flag
    FROM departments
    WHERE department_id = p_depno;
    
    SELECT AVG(salary) INTO v_avg
    FROM employees
    WHERE department_id = p_depno;
    
    SELECT COUNT(*) INTO v_cnt
    FROM employees
    WHERE department_id = p_depno;
    
    IF v_avg IS NULL THEN
        RAISE e_empty;
    END IF;
    
    IF v_cnt <= 1 THEN
        RAISE e_no_modified;
    END IF;

    FOR i IN cur_sal LOOP
        v_increase := v_avg - i.salary;
        DBMS_OUTPUT.PUT_LINE('Employee '||i.first_name||' '|| i.last_name||' just got an increase of $'||v_increase);
        
        UPDATE employees
        SET salary = v_avg
        WHERE employee_id = i.employee_id;
        
        v_emp# := cur_sal%ROWCOUNT;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Total # of employees who received salary increase is : '||v_emp#);

EXCEPTION
    WHEN NO_DATA_FOUND THEN
           DBMS_OUTPUT.PUT_LINE('This Department Id is invalid: '||p_depno);
    WHEN e_empty THEN
        DBMS_OUTPUT.PUT_LINE('This Department is EMPTY: '||p_depno);
    WHEN e_no_modified THEN
        DBMS_OUTPUT.PUT_LINE('No salary was modified in Department: '||p_depno);
END modify_sal;
/

SET SERVEROUTPUT ON
EXECUTE modify_sal(99);
EXECUTE modify_sal(190);
EXECUTE modify_sal(10);
EXECUTE modify_sal(110);
EXECUTE modify_sal(60);
ROLLBACK;


/* Q1 Output

Procedure MODIFY_SAL compiled
PL/SQL procedure successfully completed.

This Department Id is invalid: 99

PL/SQL procedure successfully completed.

This Department is EMPTY: 190

PL/SQL procedure successfully completed.

No salary was modified in Department: 10

PL/SQL procedure successfully completed.

Employee William Gietz just got an increase of $1850
Total # of employees who received salary increase is : 1


PL/SQL procedure successfully completed.
Employee David Austin just got an increase of $960
Employee Valli Pataballa just got an increase of $960
Employee Diana Lorentz just got an increase of $1560
Total # of employees who received salary increase is : 3


Rollback complete.

*/




--Q2
CREATE OR REPLACE FUNCTION Total_Cost 
    (p_studentID IN student.student_id%type)
RETURN NUMBER
IS
    v_flag CHAR(1) := 'n';
    v_cost NUMBER;
    v_sectionID NUMBER;
    v_sectionCnt NUMBER;
BEGIN
    SELECT 'y' INTO v_flag 
    FROM student 
    WHERE student_id = p_studentID;

    SELECT count(*) INTO v_sectionCnt 
    FROM enrollment 
    WHERE student_id = p_studentID;
    
    IF v_sectionCnt > 0 THEN
        SELECT section_id INTO v_sectionID 
        FROM enrollment 
        WHERE student_id = p_studentID;
        
        SELECT sum(cost) as cost INTO v_cost 
        FROM course 
        WHERE course_no = (SELECT course_no 
                            FROM section 
                            WHERE section_id = v_sectionID);
        RETURN v_cost;
    ELSE
        RETURN 0;
    END IF;
    
    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            RETURN -1;
END Total_Cost;
/
SET AUTOPRINT ON
VARIABLE COST NUMBER;
EXECUTE :COST := Total_Cost(194);
EXECUTE :COST := Total_Cost(294);
EXECUTE :COST := Total_Cost(494);
/

/*Q2 Output
Function TOTAL_COST compiled
PL/SQL procedure successfully completed.

COST
----
1195
PL/SQL procedure successfully completed.

COST
-
0
PL/SQL procedure successfully completed.

COST
--
-1
*/

--Q3

--3-a) Package Specification
CREATE OR REPLACE PACKAGE My_pack IS

FUNCTION Total_Cost(p_studentID IN student.student_id%TYPE)
RETURN NUMBER;

PROCEDURE modify_sal(p_depno IN departments.department_id%TYPE);

END My_pack;
/

--3-B) Package Body
CREATE OR REPLACE PACKAGE BODY  My_pack IS

    FUNCTION Total_Cost( p_studentID IN student.student_id%TYPE )
    RETURN NUMBER
    IS
        v_flag CHAR(1) := 'n';
        v_cost NUMBER;
        v_sectionID NUMBER;
        v_sectionCnt NUMBER;
    BEGIN
        SELECT 'y' INTO v_flag 
        FROM student 
        WHERE student_id = p_studentID;
        
        SELECT count(*) INTO v_sectionCnt 
        FROM enrollment 
        WHERE student_id = p_studentID;
    
        IF v_sectionCnt > 0 THEN
            SELECT section_id INTO v_sectionID 
            FROM enrollment 
            WHERE student_id = p_studentID;
        
            SELECT sum(cost) as cost INTO v_cost 
            FROM course 
            WHERE course_no = (SELECT course_no 
                                FROM section 
                                WHERE section_id = v_sectionID);
            RETURN v_cost;
        ELSE
            RETURN 0;
        END IF;
    
        EXCEPTION
            WHEN NO_DATA_FOUND THEN
                RETURN -1;
    END Total_Cost;
    
    PROCEDURE modify_sal(p_depno IN departments.department_id%TYPE)
    IS
        CURSOR cur_sal IS
        SELECT salary, first_name, last_name, employee_id 
        FROM employees
        WHERE department_id = p_depno 
        AND salary < (SELECT AVG(salary)
                      FROM employees 
                      WHERE department_id = p_depno) FOR UPDATE NOWAIT;                   
    
        v_flag CHAR(1) := 'n';
        v_increase NUMBER := 0;
        v_emp# NUMBER := 0;
        v_cnt NUMBER := 0;
        v_avg employees.salary%TYPE;
    
        e_empty EXCEPTION;
        e_no_modified EXCEPTION;
    
    BEGIN
        SELECT 'y' INTO v_flag
        FROM departments
        WHERE department_id = p_depno;
    
        SELECT AVG(salary) INTO v_avg
        FROM employees
        WHERE department_id = p_depno;
    
        SELECT COUNT(*) INTO v_cnt
        FROM employees
        WHERE department_id = p_depno;
    
        IF v_avg IS NULL THEN
            RAISE e_empty;
        END IF;
    
        IF v_cnt <= 1 THEN
            RAISE e_no_modified;
        END IF;

        FOR i IN cur_sal LOOP
            v_increase := v_avg - i.salary;
            DBMS_OUTPUT.PUT_LINE('Employee '||i.first_name||' '|| i.last_name||' just got an increase of $'||v_increase);
        
            UPDATE employees
            SET salary = v_avg
            WHERE employee_id = i.employee_id;
        
            v_emp# := cur_sal%ROWCOUNT;
        END LOOP;
        DBMS_OUTPUT.PUT_LINE('Total # of employees who received salary increase is : '||v_emp#);
    
    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            DBMS_OUTPUT.PUT_LINE('This Department Id is invalid: '||p_depno);
        WHEN e_empty THEN
            DBMS_OUTPUT.PUT_LINE('This Department is EMPTY: '||p_depno);
        WHEN e_no_modified THEN
            DBMS_OUTPUT.PUT_LINE('No salary was modified in Department: '||p_depno);
    END modify_sal;
    
END My_pack;
/


--3-C) Test Package using Q2 input.
SET AUTOPRINT ON
VARIABLE COST NUMBER;
EXECUTE :COST := My_pack.Total_Cost(194);
EXECUTE :COST := My_pack.Total_Cost(294);
EXECUTE :COST := My_pack.Total_Cost(494);
ROLLBACK;

/* Q3 Output
Package MY_PACK compiled

Package body MY_PACK compiled

PL/SQL procedure successfully completed.

COST
----
1195
PL/SQL procedure successfully completed.

COST
-
0

PL/SQL procedure successfully completed.

COST
--
-1
Rollback complete.

*/


--Q4

CREATE OR REPLACE PACKAGE My_pack IS

FUNCTION Total_Cost(p_studentID IN student.student_id%TYPE)
RETURN NUMBER;


--4-A) TWO Input parameters function (First Name, Last Name) Package Specification
FUNCTION Total_Cost
    (p_first_name IN student.first_name%TYPE,
        p_last_name IN student.last_name%TYPE)
RETURN NUMBER;


--4-B) ONE Input parameter function (Zipcode) Package Specification
FUNCTION Total_Cost
    (p_zip IN student.zip%TYPE)
RETURN NUMBER;

END My_pack;
/



CREATE OR REPLACE PACKAGE BODY  My_pack IS

    FUNCTION Total_Cost( p_studentID IN student.student_id%TYPE )
    RETURN NUMBER
    IS
        v_flag CHAR(1) := 'n';
        v_cost NUMBER;
        v_sectionID NUMBER;
        v_sectionCnt NUMBER;
    BEGIN
        SELECT 'y' INTO v_flag 
        FROM student 
        WHERE student_id = p_studentID;

        SELECT count(*) INTO v_sectionCnt 
        FROM enrollment 
        WHERE student_id = p_studentID;
    
        IF v_sectionCnt > 0 THEN
            SELECT section_id INTO v_sectionID 
            FROM enrollment 
            WHERE student_id = p_studentID;
        
            SELECT sum(cost) as cost INTO v_cost 
            FROM course 
            WHERE course_no = (SELECT course_no 
                                FROM section 
                                WHERE section_id = v_sectionID);
            RETURN v_cost;
        ELSE
            RETURN 0;
        END IF;
    
        EXCEPTION
            WHEN NO_DATA_FOUND THEN
                RETURN -1;
    END Total_Cost;
    

--4-A) TWO Input parameters function (First Name, Last Name) Package Body

    FUNCTION Total_Cost(
        p_first_name IN student.first_name%TYPE,
        p_last_name IN student.last_name%TYPE
    )
    RETURN NUMBER
    IS
        v_flag CHAR(1) := 'n';
        v_cost NUMBER;
        v_studentID NUMBER;
        v_sectionID NUMBER;
        v_sectionCnt NUMBER;
    BEGIN
        SELECT 'y' INTO v_flag 
        FROM student 
        WHERE UPPER(first_name) = UPPER(p_first_name) AND UPPER(last_name) = UPPER(p_last_name);
        
        SELECT student_id INTO v_studentID 
        FROM student
        WHERE UPPER(first_name) = UPPER(p_first_name) AND UPPER(last_name) = UPPER(p_last_name);
        SELECT count(*) INTO v_sectionCnt 
        FROM enrollment 
        WHERE student_id = v_studentID;
    
        IF v_sectionCnt > 0 THEN
            SELECT section_id INTO v_sectionID 
            FROM enrollment 
            WHERE student_id = v_studentID;
        
            SELECT sum(cost) as cost INTO v_cost 
            FROM course 
            WHERE course_no = (SELECT course_no 
                                FROM section 
                                WHERE section_id = v_sectionID);
            RETURN v_cost;
        ELSE
            RETURN 0;
        END IF;
    
        EXCEPTION
            WHEN NO_DATA_FOUND THEN
                RETURN -1;
    END Total_Cost;
    
    
--4-B) ONE Input parameter function (Zipcode) Package Body

    FUNCTION Total_Cost
    (p_zip IN student.zip%TYPE)
    RETURN NUMBER
    IS
        CURSOR cur_students IS
        SELECT enrollment.student_id, enrollment.section_id
        FROM student, enrollment
        WHERE student.student_id = enrollment.student_id AND student.zip = p_zip;
        
        v_cnt NUMBER := 0;
        v_cost NUMBER;
        v_sum NUMBER := 0;
        v_studentID NUMBER;
        v_sectionID NUMBER;
        v_sectionCnt NUMBER;
    BEGIN
        SELECT count(*) INTO v_cnt
        FROM student 
        WHERE zip = p_zip;
        IF v_cnt > 0 THEN
            FOR s IN cur_students LOOP
                SELECT cost INTO v_cost 
                FROM course 
                WHERE course_no = (SELECT course_no 
                                    FROM section 
                                    WHERE section_id = s.section_id);
                v_sum := v_sum + v_cost;
            END LOOP;
        ELSE
            RETURN -1;
        END IF;
        RETURN v_sum;
        
    END Total_Cost;
   
 
    
END My_pack;
/

--4-C) Test OVERLOADED Function
VARIABLE COST NUMBER;
EXECUTE :COST := My_pack.Total_Cost('VERONA', 'GRANT');
EXECUTE :COST := My_pack.Total_Cost('YVONNE', 'WINNICKI');
EXECUTE :COST := My_pack.Total_Cost('PETER', 'PAN');
EXECUTE :COST := My_pack.Total_Cost('07044');
EXECUTE :COST := My_pack.Total_Cost('11209');
EXECUTE :COST := My_pack.Total_Cost('11111');


/* Q4 Output 

Package MY_PACK compiled
Package body MY_PACK compiled

PL/SQL procedure successfully completed.

COST
----
1195
PL/SQL procedure successfully completed.

COST
-
0

PL/SQL procedure successfully completed.

COST
--
-1
PL/SQL procedure successfully completed.

COST
----
1195

PL/SQL procedure successfully completed.

COST
----
7070
PL/SQL procedure successfully completed.

COST
--
-1

*/
