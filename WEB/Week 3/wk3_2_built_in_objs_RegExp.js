///// Regular Expression
 /* declare Regular Expression
 var patt=/pattern/[modifiers];
 var patt=new RegExp(pattern[, modifiers]);
 */

//// 1. test(): return boolean, Regular Expression method
var str = "Welcome to Toronto";
var patt1 = /Me/;       
var result = patt1.test(str);  // testing whether patter Me is in the string str
console.log(result);   // false 

var patt2 = /Me/i;  // case insensitive 
var result2 = patt2.test(str);
console.log(result2);  // true 


// replace(), match(), search() are String methods/ functions
var s = "Hello world   ";
var newS = [];
newS[0]=s.replace("l","A"); //HeAlo world  
newS[1]=s.replace(/l/, "A"); // HeAlo world  
newS[2]=s.replace(/l/g, "A"); //HeAAo worAd  
newS[3]=s.match(/l/); // [ 'l']
newS[4]=s.match(/l/g); //[ 'l', 'l', 'l' ]
newS[5]= s.search("low"); //-1, returns the index of the match, or -1 if the search fails
newS[6]= s.search(/lo w/); //3
console.log(newS);

//To validate: at least 4 alphabetical character
var pattern1 = /^[a-zA-Z]{4,}$/;
var str= "Hello";
console.log(pattern1.test(str));  // true
console.log(str.match(pattern1)); //["Hello"]
console.log(str.search(pattern1)); //0

var str= "Hello world";
console.log(pattern1.test(str));  // false, space is not alpha
console.log(str.match(pattern1)); // null
console.log(str.search(pattern1));  // -1

// To validate: telephone format ###-###-####
// var s = "234-442-3888"
var pattern1 = /\d{3}-\d{3}-\d{4}$/;
var pattern2 =  /(\d{3}-){2}\d{4}$/;
var pattern3 = /^([0-9]{3}[-]){2}[0-9]{4}$/;
//var str = "415-444-3333";
var str = "123-333-2222";
var result1 = pattern1.test(str);
var result2 = pattern2.test(str);
var result3 = pattern3.test(str);
console.log(result1);
console.log(result2);
console.log(result3); 