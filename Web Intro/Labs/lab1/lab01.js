/*********************************************************************************
 *                     INT222 – Lab 01
 *  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  No part of this
 *  assignment has been copied manually or electronically from any other source (including web sites) or
 *  distributed to other students.
 *
 *  Name: Alejandro Mesa Suarez    Student ID: 038515151    Date: September 18
 *
 ********************************************************************************/

/*****************************
 *    Task 1 - Student Info
 *****************************/

var name = "Alejandro Mesa";
var courses = 5;
var program = "CPA";
var part_time = true;
var job;
if (part_time) {
    job = "have";
} else {
    job = "don't have";
}

console.log("My name is " + name + " and I'm in " + program +
    ". I'm taking " + courses + " course(s) in this semester.");

console.log("My name is " + name + " and I'm in " + program +
    ". I'm taking " + courses + " course(s) in this semester and I " + job +
    " a part-time job now");

/*****************************
 *    Task 2 - Birth and graduate year
 *****************************/

var year = 2016;
var age = parseInt(prompt("Please enter your age:"));
console.log("You were born in the year of " + (year - age));
var college_years = parseInt(prompt("Enter the number of years you expect to study in the college:"));
console.log("You will graduate from Seneca college in the year of " + (year + college_years));

/*****************************
 *    Task 3 - Celsius and Fahrenheit temperatures
 *****************************/

var celsius = 26;
var fahrenheit = 63;

function toFahrenheit(celsius) {
    return Math.round(celsius * (9 / 5) + 32);
}

function toCelsius(fahrenheit) {
    return Math.round((fahrenheit - 32) * (5 / 9));
}

console.log(celsius + "°C is " + toFahrenheit(celsius) + "°F");
console.log(fahrenheit + "°F is " + toCelsius(fahrenheit) + "°C");

/*****************************
 *    Task 4 - Even and odd numbers
 *****************************/

var number;

for (number = 0; number < 11; number++) {
    if (number == 0) {
        console.log(number + " is even but is debatable");
    } else if (number % 2 != 0) {
        console.log(number + " is odd");
    } else {
        console.log(number + " is even");
    }
}

/*****************************
 *    Task 5 - Larger or largest number
 *****************************/

function largerNum(num1, num2) {
    var large = 0;

    if (num1 >= num2) {
        large = num1;
    } else {
        large = num2;
    }
    console.log("The larger number of " + num1 + " and " + num2 + " is " + large);
    return large;
}

var greaterNum = function(num1, num2) {
    var greater = 0;

    if (num1 >= num2) {
        greater = num1;
    } else {
        greater = num2;
    }
    console.log("The greater number of " + num1 + " and " + num2 + " is " + greater);
    return greater;
}

/*****************************
 *    Task 6 - Evaluator
 *****************************/

function Evaluator() {
    var result;
    var total = 0;
    var average = 0;
    for (i = 0; i < arguments.length; i++) {

        total = total + arguments[i];

    }
    average = total / (arguments.length);
    average = Math.round(average);

    if (average > 50) {
        console.log("The average is " + average + " is greater or equal to 50");
        result = true;
    }
    else if (average == 50){
        console.log("The average is " + average + " , equal to 50");
        result = true;
    }
    else {
        console.log("The average is " + average + " is less than 50");
        result = false;
    }

    return result;
}



/*****************************
 *    Task 7 - Grader
 *****************************/

var Grader = function(score) {
    var result;

    if (score >= 80) {
        result = "A";
        console.log(score + " => " + result);
    } else if (score >= 70) {
        result = "B";
        console.log(score + " => " + result);
    } else if (score >= 60) {
        result = "C";
        console.log(score + " => " + result);
    } else if (score >= 50) {
        result = "D";
        console.log(score + " => " + result);
    } else {
        result = "F";
        console.log(score + " => " + result);
    }

    return result;

}

/*****************************
 *    Task 8 - Show Multiples
 *****************************/

function showMultiples(num, numMultiples) {

    var i;
    for (i = 1; i < numMultiples + 1; i++) {

        console.log(num + " x " + i + " = " + (num * i));

    }

}
