// (1) global and local variables
/* var ident_A = 5;           // Global variable - bad practice
function someFunction() {   // Start of function
        var ident_B = 15;      // Local  variable
        ident_C     = 34;        // without var, Global variable - bad practice
        var ident_A = 0;     // Local variable, redefine global variable in line 2
        ident_C++;          // global variable increment ident_C by 1 
        ident_A     = ident_B + ident_C;  // 50
        console.log("ident_A in function: " + ident_A);  // show the value of global variable ident_A inside the function      

} // End of function

 // call the function, making line 8, indent_C global. 
 // If remove this line, indent_C will be not defined in line 20 
someFunction();    
console.log("ident_A outside function: " + ident_A);   // show the value of ident_A outside the function
console.log("ident_C = " + ident_C);   // show the value of ident_C
console.log("ident_B = " + ident_B);   // ident_B is not defined
 */


// (2) Block level scope - let new in ECMAScript 2015
// let vs var

/* var x = 2;
//for ( var i = 0; i < 3; i++)  // var cannot define block level scop
for ( let i = 0; i < 3; i++)
{
    console.log("inside loop block, i= " + i);

    //var x = 10; // redeclare x, outside the block
    let x = 10;   // will not change the outside variable x
}
//console.log("outside loop block, i= " + i); 
   // i=3, if defined with var in line 26, 
   // i is not defined, if defined using let in line 27 
console.log("x = " + x); // 10 */



