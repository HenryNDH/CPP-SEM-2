// (1) closure
// function program (prog)
// {
//     var school = "ICT";
//     function student(name)
//     {
//         var str = "Student name: " + name + ", Program: " + prog + ", School of " + school;
//         return str;
//     }
//     return student;
// }
// var bsd_student = program("BSD"); //return inner function 
// //console log
// var john = bsd_student("John Smith1");
// var john2 = program ("BSD")  ("John Smith2");
// console.log (john);
// console.log (john2);

// // (2) closure - function  expression in closure
// function program(prog)
// {
//     var student = function (name) 
//     {
//         return "Student name: " + name + ", \nProgram: " + prog;
//     };
//     return student;
// }
// var bsd_student = program("BSD"); //return inner function 
// //console log
// var john3 = bsd_student("John Smith3");
// var john4 = program ("BSD")  ("John Smith4");
// console.log (john3);
// console.log (john4);

// //(3) Using anonymous function in closure
// function program(prog)
// {
//     return function(name)
//     {
//         return "Student name: " + name + ", \nProgram: " + prog;
//     };
// }
// var bsd_student = program("BSD"); //return inner function 
// //console log
// var john5 = bsd_student("John Smith5");
// var john6 = program ("BSD")  ("John Smith6");
// console.log (john5);
// console.log (john6);

// (4) function factory
function makeAdder(x){
    return function (y){
        return x+y;
    };
}
var add5 = makeAdder(5);
var add10 = makeAdder (10);

console.log(add5(2));
console.log(add10(2));