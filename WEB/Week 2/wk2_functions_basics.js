// define function square (n) ===> n*n
// (1) function declaration 
// name rules: (1) alpha (2) digits (3) _;
function square (n)
{
    return n*n;
}
console.log ("square(n) = " + square(9));

// (2) function expression
var square = function (n)
{
    return n*n;
}
console.log ("square(n) = " + square(9));

// (3) function take no parameter, no return
function greeting ()
{
    console.log ("I love Mia");
}
greeting();

// (4) a function takes one parameter, no return
 function greeting_sb(name)
 {
     console.log("I Love " + name);
 }
 greeting_sb("Mia");

 // (5) a function with indefinite number of parameters, using arguments obj 
 function sum ()
 {
    var count = arguments.length
    var total = 0;
    for (var i =0; i < count; i ++)
    {
        total += arguments [i]
    } 
    return total;
 }
 console.log ("Sum a+b = " + sum (1,2,3,4,5,6,7));

// (6) rest parameter, it's an array
function sum_rest(...numbers)
{
    var total = 0;
     for (var i = 0; i < numbers.length; i ++)
     {
         total += numbers[i]; 
     }
     return total;
}
console.log("sum_rest(a,b) = " + sum_rest(2,8));
console.log("sum_rest(a,b) = " + sum_rest(2,8,9));

// (7) function with optional or missing arguments
function updateScore(currentScore, value, bonus)
{
    return bonus ? currentScore + value*bonus : currentScore +value;
}
console.log(updateScore(10, 3)); //10+3=13
console.log(updateScore(10,3,2)); // 10 + 3*2 = 16

// (8) function with parameter initialization
function updateScore(currentScore, value, bonus = 1)
{
    return currentScore + value * bonus;
}
console.log(updateScore(10, 3)); //10+3=13
console.log(updateScore(10,3,2)); // 10 + 3*2 = 16