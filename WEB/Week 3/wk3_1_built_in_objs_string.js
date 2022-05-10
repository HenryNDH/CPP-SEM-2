// String object functions
var s = "Hello world   ";

//var newStr="";
var newS=[];// create an empty array
newS[0]=s.length;  //14 , length is the property for string, tells how many characters in string s  
// s[0]= 'H'
newS[1]=s.charAt(1); // e
newS[2] = s[1]; // e
newS[3]=s.charCodeAt(1);  //101
newS[4]=s.concat(" !wow"); //Hello world    !wow
newS[5] =s.trim().concat("!wow");
newS[6] = s.trim() + "!wow";  // better, //Hello world!wow
//recommend to use the operators (+, +=) instead of the concat method for performance reason. 
//Functions are slower than operators.
newS[7]=s.toLowerCase(); //hello world 
newS[8]=s.toUpperCase(); //HELLO WORLD  

//console.log(s);  //original string unchanged with concat(), toLowerCase(), etc.

 //newStr = 10.2232;
 //console.log(newStr.toFixed(2));
 
newS[9]=s.substr(1,3); //ell, substring from index 1, return 3 chars
newS[10]=s.substring(1,3); //el,  substring from index 1, ending index 3, not inclusive
newS[11]=s.slice(1,3); //el, same as substring
newS[12]= s.split(' '); //[ 'Hello', 'world', '', '', '' ] // split string into array based on the separator

s = "Good, morning, everyone."
newS[13] = s.split(', '); //["Good", "morning", "everyone."]
newS[14]=s.includes("oo"); //true   --boolean --case sensitive
newS[15]=s.startsWith('G');//true   --boolean
newS[16]=s.startsWith('g');//false   --case sensitive
newS[17]=s.trim().endsWith(".");  // false, with white space ending

console.log(newS); 
console.log(s);  //original string unchanged after substr(), split(), etc.

 
///// indexOf(), lastIndexOf()
 var  myString    =  "BTI225";

console.log( myString.indexOf("B") );     // 0
console.log( myString.indexOf("TI") );    // 1
console.log( myString.indexOf('2') );     // 3, position of the first occurrence
console.log( myString.indexOf('b2') );     // -1
console.log( myString.indexOf('3') );     // -1 

console.log( myString.lastIndexOf("B") );    // returns  0
console.log( myString.lastIndexOf("BTI") );  // returns  0
console.log( myString.lastIndexOf('2') );     // returns  4, last occurrence of '2'
console.log( myString.lastIndexOf('22') );   // returns  3
console.log( myString.lastIndexOf('3') );    // returns  -1


//JS String obj property: prototype
//Allows you to add properties and methods to an object

String.prototype.reverse = function () {
    var rev = '';
    for (var i = this.length - 1; i >= 0; i--)
       rev += this[i]; // the string
    return rev;
 };
console.log(s.reverse()); //   .enoyreve ,gninrom ,dooG
console.log(s);  //Good, morning, everyone.

// compare characters based on ASCII number
var c ='D';
if (c >= 'a' && c<='z')   // test lower case alpha
// if (c>='0' && c<='9')  // test digit
 console.log("lower");
else
console.log("not lower"); 