//////// User defined objs
///// ---=== (3) create obj- prototypeal inheritance
// (3.1) Object.create()
/*  var rectangle1 = {
    width: 10,
    height: 15,
    show: function () {
       console.log('dimensions: ' + this.width + " x " + this.height);
    },
    getArea: function(){
        console.log("Area = " + this.width * this.height);
    }
};
rectangle1.show();
rectangle1.getArea();

// creates a new rectangle using rectangle1 as prototype
var rectangle2 = Object.create(rectangle1); // clone
console.log("rectangle2's width = " + rectangle2.width);  // 10, exact same as rectangle1.width
rectangle2.show();    // same as rectangle 1, // dimensions: 10 x 15
rectangle2.getArea();  // inherited functions of prototype obj, rectangle1

//////// prototype inheritance is another solution to assignment by reference issue 
/////// in file wk4_3_obj_custom1.js (2.2)
rectangle2.width = 20; 
rectangle2.height = 25;

rectangle1.show();  // dimensions: 10 x 15
rectangle2.show();  // dimensions: 20 x 25
rectangle2.getArea();  *///500

//====
// (3.2) array of objs
//Model of subjects for School of ICT, obj subject as prototype
/* var subject = {
    code: "",
    desc: "",
    prog: [], //  the prog property is an array
    info: {}  //  the info property is an object
};

//Create subject instances using the Object.create method.
var web222   = Object.create(subject);
web222.code = 'WEB222';
web222.desc = 'Internet I - Internet Fundamentals ';
web222.prog = ['CPD', 'CPA'];
web222.info  = { hours: 4, url:'http://scs.senecac.on.ca/course/web222' };

// display the code of web222
console.log("web222 code is "  + web222.code);

//display web222's course description
console.log(web222.desc);

// dislay the first program of web222
console.log("web222 prog 1: " + web222.prog[0]);  // CPD
console.log("web222 prog 1: " + web222.prog);  // print whole array ['CPD', 'CPA']
console.log("how many programs in web222 ?" + web222.prog.length);  // 2

// how many hours for web222
console.log("hours for web222 " + web222.info.hours); // 4 // pay attention to the notation

var bti220 = Object.create(subject);
bti220.code = 'BTI220';
bti220.desc = 'Internet Architecture and Development';
bti220.prog = ['BSD'];
bti220.info = { hours: 4, url:'http://scs.senecac.on.ca/course/bti220' }

var ipc144 = Object.create(subject);
ipc144.code = 'IPC144';
ipc144.desc = 'Introduction to Programming Using C';
ipc144.prog = ['CPD', 'CPA', 'CTY'];
ipc144.info = { hours: 5, url:'http://scs.senecac.on.ca/course/ipc144' }
 
var btc140 = Object.create(subject);
btc140.code = 'BTC140';
btc140.desc = 'Critical Thinking and Writing';
btc140.prog = ['BSD', 'IFS'];
btc140.info = { hours: 3, url:'http://scs.senecac.on.ca/course/btc140' }

//All subjects
// Create a collection of all subject objects
var all = [ web222, bti220, ipc144 ];
all.push(btc140);
// using all to access btc140's desc
// console.log("btc140's desc: " + all.btc140.desc); // wrong
console.log("btc140's desc: " + all[3].desc);
// how to get btc140's prog "BSD"
console.log("BTC140's 1st prog :" + all[3].prog[0]);
// get btc140's hours (3)
console.log("btc140's hours (3): " + all[3].info.hours);
 
// Declare and initialize an accumulator
var totalHours = 0; 

// Go through the collection, accumulate hours, dump to the Web Console
for (var i = 0; i < all.length; i++) {
    totalHours += all[i].info.hours; // add up hours
    console.log(all[i]); // display all objs
};

// Report the total hours
console.log('Total hours is ' + totalHours);  
*/
