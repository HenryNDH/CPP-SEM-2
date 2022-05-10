/****************************************************************************
* Assignment 1
* I declare that this assignment is my own work in accordance with Seneca AcademicPolicy.
* No part of this assignment has been copied manually or electronically from any othersource
* (including web sites) or distributed to otherstudents.
* Name: Hoang Duy Nguyen Student ID: 108397217 Date: Jan 25 2022
****************************************************************************/

/***************************** Task1 *************************/
// Using function declaration, define a JavaScript function (name it: playNumbers)
function playNumbers(/*indefinite number of parameters.*/)
{
    var number_check = true;
    var largest;
    var total = 0;
    var string;
    if(arguments.length == 0)
    {
        //(1) if the function call didn't pass any arguments, your function displays:
        console.log("There are no inputs.");
        number_check = false;
    }
    else
    {
        for(var i=0; i < arguments.length; i++)
        {
           //(2) if one or more arguments are not numbers, your function displays:
           if (isNaN(arguments[i]))
           {
                console.log(arguments[i] + " is not a number.");
                number_check = false;
           }
        }
    }
    //(3) Otherwise (if not (1) nor (2)),
    if (number_check == true)
    {
        largest = Number(arguments[0]);
        for(var i=1; i < arguments.length; i++)
        {
            if (Number(largest) < Number(arguments[i]))
            {
                largest = arguments[i]; //(3.1) it displays the largest value of all the parameters in the format
            }
        }
        total += arguments[0];
        for(var i=1; i < arguments.length; i++)
        {
            total += arguments[i];
        }
        string = arguments[0];
        for (var i=1; i < arguments.length; i++) 8,9,7
        {
            string = string + "," + arguments[i];
        }
        console.log("The largest number of ("  + string + ") is " + largest);
        console.log("The average of ("  + string + ") is " + total/arguments.length); //(3.2) it displays the average of all the values in the format:
    }
}
//(4) Test your program using the following statements.
console.log("/***************************** Task1 *************************/");
playNumbers();
playNumbers("abc", 3, "hello");
playNumbers(9,3,6);
playNumbers(3,5,1,3,5);
playNumbers("Good day!",3,4,32,"hi", "we");
// Sample result for the above function calls:
/***************************** Task1 *************************/
// There are no inputs.
// abc is not a number.
// hello is not a number.
// The largest number of (9, 3, 6) is 9
// The average of (9, 3, 6) is 6
// The largest number of (3, 5, 1, 3, 5) is 5
// The average of (3, 5, 1, 3, 5) is 3.4
// Good day! is not a number.
// hi is not a number.
// we is not a number.

/***************************** Task2 *************************/
function convertCF(val,cf)
{
    var converted = 0;
    var old_cf = "";
    if(isNaN(val))
    {
        console.log("I need a number"); //(1) if val is not a number, your function displays, "I need a number". 
    }
    else if (cf != 'C' && cf != 'F')
    {
        console.log("I am confused :(");//(2) if cf is not "C" or "F", your function displays "I am confused :("
    }
    else
    {
        if (cf == 'C') //if cf is "C", val is the value in Celcius, your function will convert it to Farenheit degree, and display:
        {
            converted = val * 1.8 + 32;
            cf = 'F'; 
            console.log (val + "C" + " is s equivalent to " + Math.round (converted) + cf);
        }
        else           //if cf is "F", val is the value in Farenheit, your function will convert it to Celcius degree, and display: 
        {
            converted = (val - 32) * .5556;
            cf = 'C';
            console.log (val + "F" + " is s equivalent to " + Math.round (converted) + cf);
        }
        
    }
}
//(5) test (call) your function with the example input(parameters): 
console.log("/***************************** Task2 *************************/");
convertCF("avc", "F");
convertCF("32", "M");
convertCF(32, 'F');
convertCF(0, "C");
convertCF(122, "F");

// Sample result for the above function calls:
// /***************************** Task2 *************************/
// I need a number.
// I am confused :(
// 32F is equivalent to 0C
// 0C is equivalent to 32F
// 122F is equivalent to 50C