// // 1. parseFloat()
// var a = "15.25"
// //console.log (a+10)
// console.log (parseFloat("15.25") + 10);
// console.log (parseFloat("1 2 3 4"));

// // 2. parseInt()
// var a = "15.25"
// //console.log (a+10)
// console.log (parseInt("15.25"));
// console.log (parseInt('110011', 2)); // second parameter is a base ( base 2)
// console.log (parseInt('16', 16)); // second parameter is a base ( base 16)

// // 3. Number(), String(), toString(), typeof
// //Number() can convert both integer and float numbers.
// //Number() can convert the parameter as a whole - no partial conversion. e.g.
// var x = "12.78";
// var y = 10;
// var z = x+y; //NOT 22.78, it is 12.7810, concatenation because x was declare as a string so string + number = string
// // var z = parseFloat(x) + y ; //22.78
// var z = Number(x) + y;  //22.78
// console.log(z);
// console.log("sss = " + String(y));
// console.log("sss= " + y);

// console.log(Number("1+2+3"));
// console.log(parseInt("1234ABC"));
// console.log(parseFloat("12.34.23"));

var x = 123;
console.log(x.toString(/* inside will be base*/));
