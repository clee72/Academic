Assignment 1
Group #1
Subject: DBS501


--Question 1)------------------------------------------------------------------------------------------

SET SERVEROUTPUT ON
SET VERIFY OFF
ACCEPT v_country_id PROMPT 'Enter valid for country: ';

DECLARE
    v_city locations.city%TYPE;
    v_state_province locations.state_province%TYPE;
    v_street_address locations.street_address%TYPE;
    v_length NUMBER;
BEGIN
    SELECT state_province, city, street_address 
    INTO v_state_province, v_city, v_street_address
    FROM locations
    WHERE country_id = '&v_country_id' AND state_province IS NULL;
    
    v_length := LENGTH(v_street_address);
    
    IF SUBSTR(v_city, 1, 1) IN ('A', 'B', 'E', 'F') THEN
        v_state_province := RPAD('*', v_length, '*');
    ELSIF SUBSTR(v_city, 1, 1) IN ('C', 'D', 'G', 'H') THEN
        v_state_province := RPAD('&', v_length, '&');
    ELSE
        v_state_province := RPAD('#', v_length, '#');
    END IF;    
     
    UPDATE locations
    SET state_province = v_state_province
    WHERE city = v_city;
    
    DBMS_OUTPUT.PUT_LINE('City '||v_city||' has modified its province to '|| v_state_province);  
 
    EXCEPTION
        WHEN TOO_MANY_ROWS THEN
            DBMS_OUTPUT.PUT_LINE('This country has MORE THAN ONE City without province listed.');
        WHEN NO_DATA_FOUND THEN
            DBMS_OUTPUT.PUT_LINE('This country has NO cities listed.');
END;
/
SELECT * FROM locations WHERE country_id = '&v_country_id' AND city = 'Hiroshima';
SELECT * FROM locations WHERE country_id ='&v_country_id' AND city ='London';
rollback;
/

OUTPUT:
1.Enter valid for country  JP
City Hiroshima has modified its province to &&&&&&&&&&&&&&&

LOCATION_ID STREET_ADDRESS  POSTAL_CODE CITY          STATE_PROVINCE    CO

1300	    9450 Kamiya-cho	6823	Hiroshima     &&&&&&&&&&&&&&&	JP
Rollback complete.

2.Enter valid for country UK
City London has modified its province to ##############

LOCATION_ID STREET_ADDRESS  POSTAL_CODE CITY          STATE_PROVINCE    CO
2400	    8204 Arthur St          London	      ##############	UK
Rollback complete.

3.Enter valid for country IT
This country has MORE THAN ONE City without province listed.

4.Enter valid for country  RS
This country has NO cities listed.
   
--Question 2)------------------------------------------------------------------------------------------

SET SERVEROUTPUT ON
ALTER TABLE COUNTRIES ADD FLAG VARCHAR2(7);
ACCEPT v_region_id PROMPT 'Enter value for region: ';

DECLARE
  v_region_id regions.region_id%type := &v_region_id;
  v_country_name countries.country_name%TYPE;
  v_counter NUMBER := 0;
  
BEGIN
    SELECT country_name INTO v_country_name
    FROM countries
    WHERE country_id NOT IN(SELECT DISTINCT country_id FROM locations)
    AND region_id = v_region_id;

    SELECT count(countries.country_name) INTO v_counter
    FROM countries
    WHERE country_id NOT IN(SELECT DISTINCT country_id FROM locations);

    UPDATE countries
    SET flag ='EMPTY_'||region_id
    WHERE country_id NOT IN(SELECT DISTINCT country_id FROM locations);
    
    DBMS_OUTPUT.PUT_LINE('In the region '||v_region_id||' there is ONE country '||v_country_name||' with NO city.');
    DBMS_OUTPUT.PUT_LINE('Number of countries with NO cities listed is: '||v_counter);
    
    EXCEPTION
      WHEN NO_DATA_FOUND THEN
          DBMS_OUTPUT.PUT_LINE('This region ID does NOT exist: ' || v_region_id);  
      WHEN TOO_MANY_ROWS THEN
          DBMS_OUTPUT.PUT_LINE('This region ID has MORE THAN ONE country without cities listed: ' || v_region_id);
END;

/
SELECT *
FROM countries 
WHERE flag IS NOT NULL
ORDER BY region_id, flag;
Rollback;

/

OUTPUT:
1.Enter value for region: 5
This region ID does NOT exist: 5


2.Enter value for region: 1
This region ID has MORE THAN ONE country without cities listed: 1



3.Enter value for region: 2
In the region 2 there is ONE country Argentina with NO city.
Number of countries with NO cities listed is: 11

CO   COUNTRY_NAME    REGION_ID   FLAG
--   ------------   ----------  ------ 

BE	Belgium		1	EMPTY_1
DK	Denmark		1	EMPTY_1
FR	France		1	EMPTY_1
AR	Argentina	2	EMPTY_2
HK	HongKong	3	EMPTY_3
ZW	Zimbabwe	4	EMPTY_4
IL	Israel		4	EMPTY_4
KW	Kuwait		4	EMPTY_4
NG	Nigeria		4	EMPTY_4
ZM	Zambia		4	EMPTY_4
EG	Egypt		4	EMPTY_4



--Question 3)------------------------------------------------------------------------------------------

SET  SERVEROUTPUT ON;
SET  VERIFY OFF;
SET LINESIZE 70;

ALTER TABLE countries
ADD flag VARCHAR (7);

ACCEPT v_region  PROMPT  'Enter value for region:  '       

DECLARE
    v_key INTEGER := 0;
    v_count NUMBER := 0;
    v_countregion NUMBER := 0;
    v_max NUMBER := 0;
    v_countryname countries.country_name%TYPE;
    v_finish NUMBER;
    
    CURSOR c_country IS
        SELECT * FROM countries
        WHERE country_id NOT IN(SELECT DISTINCT country_id FROM locations)
        ORDER BY country_name;
    
     CURSOR c_countrysort IS
        SELECT * FROM countries
        WHERE country_id NOT IN(SELECT DISTINCT country_id FROM locations)
        ORDER BY region_id, country_name;
    
     CURSOR c_countryregion IS
        SELECT country_name FROM countries
        WHERE country_id NOT IN(SELECT DISTINCT country_id FROM locations)
        AND region_id = &v_region
        ORDER BY country_name;
        
    TYPE c_list IS TABLE of countries.country_name%TYPE INDEX BY binary_integer;
    
    v_countries_list c_list;   
    v_record c_country%ROWTYPE;
    v_sort_record c_countrysort%ROWTYPE;
    
BEGIN
    DBMS_OUTPUT.PUT_LINE('Enter value for region: ' || &v_region);
    
    SELECT COUNT(*) INTO v_finish FROM regions WHERE region_id = &v_region;
    
    IF v_finish = 0 THEN
        DBMS_OUTPUT.PUT_LINE('This region ID does NOT exist: ' || &v_region);
        DBMS_OUTPUT.PUT_LINE( ' ');
        DBMS_OUTPUT.PUT_LINE('no rows selected');
    ELSE
    
        FOR country_record IN c_country
            LOOP
                v_key := v_key + 10;
                v_count := v_count +1;
                v_countries_list(v_key) := country_record.country_name;
                UPDATE COUNTRIES SET FLAG = ('Empty_' || TO_CHAR(country_record.region_id)) WHERE country_id = country_record.country_id;
                DBMS_OUTPUT.PUT_LINE('Index Table Key: ' || v_key || ' has a value of ' || v_countries_list(v_key));
        END LOOP;
        
        DBMS_OUTPUT.PUT_LINE('======================================================================');
        
        DBMS_OUTPUT.PUT_LINE('Total number of elements in the Index Table or Number of countries with NO cities listed is: ' || v_count );
        

        DBMS_OUTPUT.PUT_LINE('Second element (Country) in the Index Table is ' || v_countries_list(20) );
            

        DBMS_OUTPUT.PUT_LINE('Before the las element (Country) in the Index Table is ' || v_countries_list((v_count-1)*10) );
            
        
        DBMS_OUTPUT.PUT_LINE('======================================================================');
        
        FOR countryregion_record IN c_countryregion
            LOOP
                v_countregion := v_countregion +1;
                DBMS_OUTPUT.PUT_LINE('In the region ' || &v_region || ' there is country ' || countryregion_record.country_name || ' with NO city.');
        END LOOP;
        
        DBMS_OUTPUT.PUT_LINE('======================================================================');
        
        DBMS_OUTPUT.PUT_LINE('Total Number of countries with No cities listed in the Region ' || &v_region || ' is: ' || v_countregion );
        
        DBMS_OUTPUT.PUT_LINE('CO COUNTRY_NAME                              REGION_ID FLAG   ' );
        DBMS_OUTPUT.PUT_LINE('-- ---------------------------------------- ---------- -------' );
        
        OPEN c_countrysort;
        LOOP
            FETCH c_countrysort INTO v_sort_record;
            EXIT WHEN c_countrysort%NOTFOUND;
                DBMS_OUTPUT.PUT_LINE( v_sort_record.country_id|| ' ' || RPAD(v_sort_record.country_name,40,' ') || ' ' || LPAD(v_sort_record.region_id,10,' ') || ' ' || v_sort_record.flag);
            
        END LOOP;
        CLOSE c_countrysort;
        
        DBMS_OUTPUT.PUT_LINE( ' ');
        DBMS_OUTPUT.PUT_LINE( v_count ||' rows selected');
    END IF;
    
END;

/
ROLLBACK;


OUTPUT:

1.Enter value for region: 5
This region ID does NOT exist: 5
Rollback complete.

2.Enter value for region: 1
Index Table Key: 10 has a value of Argentina
Index Table Key: 20 has a value of Belgium
Index Table Key: 30 has a value of Denmark
Index Table Key: 40 has a value of Egypt
Index Table Key: 50 has a value of France
Index Table Key: 60 has a value of HongKong
Index Table Key: 70 has a value of Israel
Index Table Key: 80 has a value of Kuwait
Index Table Key: 90 has a value of Nigeria
Index Table Key: 100 has a value of Zambia
Index Table Key: 110 has a value of Zimbabwe
======================================================================
Total number of elements in the Index Table or Number of countries
with NO cities listed is: 11
Second element (Country) in the Index Table is Belgium
Before the las element (Country) in the Index Table is Zambia
======================================================================
In the region 1 there is country Belgium with NO city.
In the region 1 there is country Denmark with NO city.
In the region 1 there is country France with NO city.
======================================================================
Total Number of countries with No cities listed in the Region 1 is: 3
CO COUNTRY_NAME                              REGION_ID FLAG   
-- ---------------------------------------- ---------- -------
BE Belgium                                           1 Empty_1
DK Denmark                                           1 Empty_1
FR France                                            1 Empty_1
AR Argentina                                         2 Empty_2
HK HongKong                                          3 Empty_3
EG Egypt                                             4 Empty_4
IL Israel                                            4 Empty_4
KW Kuwait                                            4 Empty_4
NG Nigeria                                           4 Empty_4
ZM Zambia                                            4 Empty_4
ZW Zimbabwe                                          4 Empty_4
 
11 rows selected
Rollback complete.


3.Enter value for region: 2
Index Table Key: 10 has a value of Argentina
Index Table Key: 20 has a value of Belgium
Index Table Key: 30 has a value of Denmark
Index Table Key: 40 has a value of Egypt
Index Table Key: 50 has a value of France
Index Table Key: 60 has a value of HongKong
Index Table Key: 70 has a value of Israel
Index Table Key: 80 has a value of Kuwait
Index Table Key: 90 has a value of Nigeria
Index Table Key: 100 has a value of Zambia
Index Table Key: 110 has a value of Zimbabwe
======================================================================
Total number of elements in the Index Table or Number of countries
with NO cities listed is: 11
Second element (Country) in the Index Table is Belgium
Before the las element (Country) in the Index Table is Zambia
======================================================================
In the region 2 there is country Argentina with NO city.
======================================================================
Total Number of countries with No cities listed in the Region 2 is: 1
CO COUNTRY_NAME                              REGION_ID FLAG   
-- ---------------------------------------- ---------- -------
BE Belgium                                           1 Empty_1
DK Denmark                                           1 Empty_1
FR France                                            1 Empty_1
AR Argentina                                         2 Empty_2
HK HongKong                                          3 Empty_3
EG Egypt                                             4 Empty_4
IL Israel                                            4 Empty_4
KW Kuwait                                            4 Empty_4
NG Nigeria                                           4 Empty_4
ZM Zambia                                            4 Empty_4
ZW Zimbabwe                                          4 Empty_4
 
11 rows selected
Rollback complete.

--Question 4)------------------------------------------------------------------------------------------

SET LINESIZE 69;
SET SERVEROUTPUT ON;
SET VERIFY OFF;

ACCEPT v_course_desc PROMPT 'Enter the piece of the course description in UPPER case:';
ACCEPT v_ins_lname PROMPT 'Enter the beginning of Instructor last name in UPPER CASE:';

DECLARE
    v_total_enrollment NUMBER := 0;

    CURSOR cur_cour IS 
        SELECT c.course_no, s.section_id, c.description, i.last_name, s.section_no
        FROM course c, section s, instructor i
        WHERE UPPER(i.last_name) LIKE '&v_ins_lname'||'%' 
        AND UPPER(c.description) LIKE '%'||'&v_course_desc'||'%'
        AND s.course_no = c.course_no
        AND s.instructor_id = i.instructor_id
        ORDER BY c.description;
    rec_cour cur_cour%ROWTYPE;
  
    CURSOR cur_sec(secid NUMBER) IS 
        SELECT count(student_id) AS stu_cnt
        FROM enrollment
        WHERE section_id = secid;
    
BEGIN
    OPEN  cur_cour;
    FETCH cur_cour INTO rec_cour;
    IF cur_cour%ROWCOUNT = 0 THEN
        DBMS_OUTPUT.PUT_LINE('There is NO data for this input match between the course description '||
        'piece and the surname start of Instructor. Try again!');
        CLOSE cur_cour;
    ELSE
        CLOSE cur_cour;
        FOR i IN cur_cour 
            LOOP
                DBMS_OUTPUT.PUT_LINE('Course no: '||i.course_no||' '||i.description||' with Section Id: '||i.section_id||
                ' is taught by '||i.last_name||' in the Course Section: '||i.section_no);
                DBMS_OUTPUT.NEW_LINE;
                FOR j IN cur_sec(i.section_id)
                    LOOP
                       DBMS_OUTPUT.PUT_LINE(LPAD('This Section Id has an enrollment of: '||j.stu_cnt, 55));
                       DBMS_OUTPUT.NEW_LINE;
                        v_total_enrollment := v_total_enrollment + j.stu_cnt;
                    END LOOP;
                    DBMS_OUTPUT.PUT_LINE('*********************************************************************');
                    DBMS_OUTPUT.NEW_LINE;
            END LOOP;
            DBMS_OUTPUT.PUT_LINE('This input match has a total enrollment of: '||v_total_enrollment||' students.');
    END IF;
END;


OUTPUT:
1.
Enter the piece of the course description in UPPER case:DATA
Enter the beginning of Instructor last name in UPPER CASE:W

There is NO data for this input match between the course description
piece and the surname start of Instructor. Try again!

2.
Enter the piece of the course description in UPPER case:INTRO
Enter the beginning of Instructor last name in UPPER CASE:W


Course no: 120 Intro to Java Programming with Section Id: 149 is
taught by Wojick in the Course Section: 4

                This Section Id has an enrollment of: 1

*********************************************************************

Course no: 25 Intro to Programming with Section Id: 88 is taught by
Wojick in the Course Section: 4

                This Section Id has an enrollment of: 5

*********************************************************************

Course no: 240 Intro to the Basic Language with Section Id: 102 is
taught by Wojick in the Course Section: 2

                This Section Id has an enrollment of: 1

*********************************************************************

This input match has a total enrollment of: 7 students.

3.
Enter the piece of the course description in UPPER case:JAVA
Enter the beginning of Instructor last name in UPPER CASE:S

Course no: 124 Advanced Java Programming with Section Id: 127 is
taught by Schorin in the Course Section: 2

                This Section Id has an enrollment of: 1

*********************************************************************

Course no: 122 Intermediate Java Programming with Section Id: 153 is
taught by Smythe in the Course Section: 2

                This Section Id has an enrollment of: 3

*********************************************************************

Course no: 120 Intro to Java Programming with Section Id: 150 is
taught by Schorin in the Course Section: 5

                This Section Id has an enrollment of: 3

*********************************************************************

This input match has a total enrollment of: 7 students.
























