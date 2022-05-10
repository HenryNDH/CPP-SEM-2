var x =10;
console.log (" x = ", x);
console.log (" x = " + x);
//mark =89
// if mark is 90 or above, you display "Grade A+"
// if mark is 80 or above, you display "A"
// if mark is 79 or lower, you display "Fail"
var mark = 99;

if (mark >= 90) 
{
console.log("Grade A+");
} 

else if(mark >= 80) 
{
console.log("A");
} 

else 
{
console.log("Fail.");
}
//calculate avg
var marks = [89,97,56]; //array
var i = 0, total =0;
for (i=0; i<3; i++)
{
    total = total + marks[i];
}
console.log("Avg is: ", total/3);

var x ="6" //string
//if (x == 6) //6 is number , true
// 1. function declaration
function square(num)
{
    return num * num;
}
var  s = square(9);
console.log (s);
console.log (square(9));
// 2. function expression
var sq = function(num)
{
    return num*num;
}
console.log(sq(10));
// 3. function no return, no para
function hello()
{
    console.log("hello world");
}
hello();

function sum()
{
    var i=0, total=0;
    for (i=0; i<arguments.length; i++)
    {
        total += arguments[i];
    }
    return total;
}