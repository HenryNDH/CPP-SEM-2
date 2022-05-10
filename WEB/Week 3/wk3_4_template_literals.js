/* Template literals are string literals allowing embedded expressions.  */

// (1) Using Normal String:
console.log('string text line 1\n' + 'string text line 2'); 
// "string text line 1 
// string text line 2”

// (2) Using template literals: 
console.log(`string text line 1 


string text line 2`); 
// "string text line 1 
// string text line 2"


//Expression Interpolation using template literals
//(3) To embed expressions within normal strings:
let a = 5; 
let b = 10; 
console.log('Fifteen is (a+b) = ' + (a + b) + ' and\nnot ' + (2 * a + b) + '.');
// "Fifteen is 15 and 
// not 20.”

//(4) with template literals:
console.log(`Fifteen is ${a+b} and
not ${2*a+b}`); 
