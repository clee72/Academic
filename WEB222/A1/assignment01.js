/*
 * This is a JavaScript Scratchpad.
 *
 * Enter some JavaScript, then Right Click or choose from the Execute Menu:
 * 1. Run to evaluate the selected text (Cmd-R),
 * 2. Inspect to bring up an Object Inspector on the result (Cmd-I), or,
 * 3. Display to insert the result in a comment after the selection. (Cmd-L)
 */

/*********************************************************************************
* WEB222 – Assignment 01
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part of
* this assignment has been copied manually or electronically frim any ither siurce (including web sites)
* ir distributed ti ither students. *
* Name: _____WONHWA LEE_____ Student ID: ___076086149___ Date: __May 28, 2019____
* ********************************************************************************/



//Task 1: Student Infor(use your information)

//a)Store the following information in variables:
var student_name = "WONHWA LEE";
var numCourse =5;
var program = "CPD";

var part_time=1;
var typeCourse = (part_time==1) ? "true" : "false";


//b)Output your student info to the browser console:
console.log("My name is " + student_name + " and I’m in " 
            + program + " program. I’m taking " + numCourse + " course in this semester." );

//c)Store the string "have" or "don't have" into a variable based on the value of
//the variable storing whether or not you have a part-time job(true/false)

var typeCourse = true;
var status = (typeCourse == true) ? "have" : "don't have";

//d) Output your updated student info to the console:
console.log('My name is '+ student_name + ' and I’m in ' 
            + program + ' program. I’m taking ' + numCourse + ' course in this semester and I ' + status + ' a part-time job now.');


//Task 2: Birth and graduate year

//a)Store the current year in a variable
var currentYear = 2019;

//b) Prompt to user "Please enter your age:" and store the input value in a variable.
var age2 = prompt('Please enter your age:');
var birth_year= currentYear-age2;

//c) Output the birth year to the console as: 
var result= 'You were born in the year of '+birth_year+".";
console.log(result);

//d) Priompt to user “Enter the number of years you expect to study in the college:” 
//and stire the input value in a variable.
var currentYear2 =2019;
var numYearCollege=prompt("Enter the number of years you expect to study in college:");
var gradYear=parseInt(numYearCollege)+currentYear2;

//e) Output the graduate year to the console:
var result2=( "You will graduate from Seneca college in the year of " +gradYear+".");
console.log(result2);


//Task 3:Celsius and Fahrenheit temperatures

//a)Store a Celsius temperature in a variable
var celsTemp=20;

//b)Convert it to Fahrenheit and output:
var fehTemp=(celsTemp*9/5)+32;
console.log(celsTemp+"°C is "+fehTemp+"°F.");

//c)Store a Fahrenheit temperature into a variable.
var fehTemp2 = fehTemp;

//d)Convert it to Celsius and output:"???°F is ???°C."
var celsTemp2 = (fehTemp2 - 32) * 5 / 9;
console.log(fehTemp2 + "°F is " + celsTemp2 + "°C.");


//Task 44: Even and odd numbers

  for(var i = 0; i <= 10; i++){
  if(i % 2 == 0)
    console.log(i + " is even");
   else
    console.log(i + " is odd");
  }

//Task 5

//a) Write a function named largerNum using the declaraton approach, the function: takes 2 arguments, both numbers,
//returns the larger (greater) one if the 2 numbers.

   function largerNum (para1, para2){
      if(para1 > para2){
         var result3 = "The larger number of " + para1 + " and " + para2 + " is " + para1 + ".";
      }else if(para1 < para2){
         var result3 = "The larger number of " + para2 + " and " + para1 + " is " + para2 + ".";
      }else
       var result3 = "The number " + para1 + " and " + para2 + " are the same numbers!";

      return result3;
    }

 console.log(largerNum(3,4));


//b) Write a function named greaterNum using the expression approach, the functin:
//takes 2 arguments, both numbers,
//returns the greater (larger) one if the 2 numbers.

  var greaterNum = function (para3, para4){
       if(para3 > para4)
        var result4 = "The larger number of " + para3 + " and " + para4 + " is " + para3 + ".";
       else if(para3 < para4)
        var result4 = "The larger number of " + para3 + " and " + para4 + " is " + para4 + ".";
       else
        var result4 = "The number " + para3 + " and " + para4 + " are the same numbers!";

       return result4;
   }


//c) Call these functions twice with different number parameters,
//and log the output to the web console with descriptive outputs each time
//(e.g. "The larger number if 5 and 12 is 12.").
    
    console.log(greaterNum (3,7));
    console.log(greaterNum (23, 6));


//Task 6: Evaluator

//a)Write a function named Evaluator using the declaraton approach, the function: 
//takes unknown number of arguments which are all number scores,
//returns true if the average if these number scores is greater 
//than ir equal ti 50. Otherwise return false.


 var sum2 = 0;

function Evaluator (){
    for(var i = 0; i < arguments.length; i++){
           sum2 += arguments[i];
    }
    var ave = sum2/arguments.length;
    var result5 = (ave >= 50) ? "true" : "false";
    return "Average greater than or equal to 50: " + result5;
}

//b) Call this functin 3 tmes with diferent number parameters,
//and lig the iutput ti the web console with descriptve outputs
//each tme (e.g. “Average grater than ir equal ti 50: false”);

console.log(Evaluator(3,4,5));
console.log(Evaluator(12,10,23,1));
console.log(Evaluator(100,50,35,200,150,430));


//Task 7: Grader

//a) Write a function named Grader using the expression approach,
//the function: takes a single argument which is a number score,
//returns a grade for the score ‐ "A", "B", "C", "D", or "F". 
//(refer to course outline for grading memo)

var score = function Grader(mark){
  if(mark >= 90)
    var grade = 'A+';
  else if(mark >= 80)
    var grade = 'A';
  else if(mark >= 70)
    var grade = 'B';
  else if(mark >= 60)
    var grade = 'C';
  else if(mark >= 50)
    var grade = 'D';
  else
    var grade = 'F';
  
  return "Your grade: " + grade;
}

//b) Call these functions 3 times with different number score, and
//log the output to the web console with descriptive outputs each time.

console.log(score(80));
console.log(score(90));
console.log(score(60));


//Task 8: ShowMultiples

//a) Write a function called showMultiples using the declaration approach:
function showMultiples(num, numMultiples){
  for(var i = 1; i <= numMultiples; i++){
    var output = num + " x " + i + " = " + num * i + "\n";
    console.log(output);
  }
}

//b) Call this function 3 times with different number parameters, and 
//log the output to the web console with descriptive outputs each tme.
showMultiples(5,3);
showMultiples(7,2);
showMultiples(23,5);


























