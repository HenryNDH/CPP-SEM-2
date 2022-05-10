//////////////////////// Array Objects
// Create an array
// 1. Using an array literal (recommended)
var arrayName1 = [11, 15, 13, "blue", 24, 35.05] ; //different data types, OK
var arrayName2 = [];  // an empty array
// 2. Using the new keyword (for simplicity, do not use this method)
var arrayName1 = new Array (11, 15, 13, "blue", 24, 35.05);
var arrayName2 = new Array();
// int a[3];
// a[3]=5; // error in C  
/* arrayName2[2] = 100;  // OK i JavaScript

console.log(arrayName1);
console.log(arrayName2.length); // 3
console.log(arrayName2);

// pop(), shift(), push(), unshift()
var colors = ["Red", "Green", "Blue", "White", "Black"];
console.log("original: " + colors);  // you can display array this way
var last   = colors.pop();   // remove and return the last element , Black, original array is changed
var first  = colors.shift();  // remove and return the first element , Red, original array is changed
  // [ "Green", "Blue", "White" ]
console.log(last);     // Black
console.log(first);    // Red 
console.log(colors); // original string changed

 // var colors = ["Red", "Green", "Blue"];
colors.push("Pink");  //adds an new entry to the end of the array
colors.unshift("white"); //adds an new entry to the front of the array
console.log(colors);   // [ “white”, "Red", "Green", "Blue", "Pink" ]
 

/// concat(): Concatenates two or more arrays and returns a new array
// original array unchanged.
var array1 = ["Red", "Green", "Blue"];
var array2 = [1, 2, 3, "Yellow"];
var newArray = array1.concat(array2); // return the contactination of array1 and array2, however array1 not changed
console.log(newArray); // [ "Red", "Green", "Blue", 1, 2, 3, "Yellow" ] 
console.log(array1);   // original array unchanged

// join(): join all the elements of an array into a single string separated by a specified string separator, default is a comma.
// the opposite operation: split(), is a method of a String
var myArray = ["Red", "Green", "Blue", "Yellow"];
//newStr = myArray.join(); // default is separated by ,
newStr = myArray.join( ' * ' ) ; //"Red * Green * Blue * Yellow"
console.log(newStr);
var newArr = newStr.split(" * "); //[ 'Red', 'Green', 'Blue', 'Yellow' ]
console.log(newArr);
console.log( myArray );  // ["Red", "Green", "Blue", "Yellow"]
console.log( myArray.join()    ); // "Red,Green,Blue,Yellow"
console.log( myArray.join(' ') ); // "Green Blue Yellow"
console.log( myArray.join("&") );   // "Red&Green&Blue&Yellow"
 */
/////////////// reverse()
/* var myArray = ["Red", "Green", "Blue", "Yellow"];
console.log( myArray );  // [ "Red", "Green", "Blue", "Yellow" ]          

var myArray2 = myArray.reverse();
console.log( myArray2 );  // [ "Yellow", "Blue", "Green", "Red" ]
console.log( myArray );   // original array is changed
 */
//// sort(): 
//array elements are converted to strings, then sorted according to each character's Unicode code point value.
/* var array1 = ["Red", 2, "Green", "15", "Blue", 101, "Yellow"];
var array2 = [99, 2, 38, 15, 66, 101, 200];
console.log(array1);
console.log( array1.sort() );  // [101, "15", 2, "Blue", "Green", "Red", "Yellow"]
console.log( array2.sort() );  // [101, 15, 2, 200, 38, 66, 99]

console.log( array2.sort((a,b)=>a-b) );   //2, 15, 38, 66, 99, 101, 200 ]


// sort in descending order

var array1 = array1.sort().reverse();
console.log(array1);  // sort by unicode, //[ 'Yellow', 'Red', 'Green', 'Blue', 2, '15', 101 ]
console.log(array2.sort((a,b)=>b-a));   // sort by numeric values
 */
/// slice(startIndex, endIndex): return part of the array, endIndex not included
/* var colors = ["Red", "Green", "Blue", "Yellow", "White"];
var subclrs   = colors.slice(1, 3)  // get part of array from index 1 & 3, 3 is not included

console.log( colors );   // [ "Red", "Green", "Blue", "Yellow", "White" ] // origianl array not changed
console.log( subclrs );  */  // [ "Green", "Blue" ]

// loop through array
// (1) simple for loop
/* var i, len;
var colors = ["Red", "Green", "Blue", "Yellow", "White"];
//for (i = 0, len = colors.length; i < len; i++) {
for (i=0; i< colors.length; i++) {
    console.log(i + ": " + colors[i]);
}  */ 
/*  output
0: Red
1: Green
2: Blue
3: Yellow
4: White
*/

//// (2) for...of, loops through the values of an iterable object, e.g. array, string, 
/* var colors = ["Red", "Green", "Blue", "Yellow", "White"];
for (let item of colors)
{
    console.log(item);
}
// for ... of , over a string
var str = "Hello";
for (let item of str)
{
    console.log(item);
}  */
 
/// (3) js forEach() function
var colors = ["Red", "Green", "Blue", "Yellow", "White"];
 /* function myFunction(item, index) {
    console.log(index + ": " + item);
}
var colors = ["Red", "Green", "Blue", "Yellow", "White"];
colors.forEach(myFunction);  */

// (4) Callback function, function as parameter 
/* colors.forEach(function(item, index){
    console.log(index + ": " + item);
}); */

// (5) function arrow notation 
colors.forEach((item, index)=>{
    console.log(index + ": " + item);
});
