//////// User defined objs
///// ---=== (1.1) create obj- literal notation
var person1 = { name: "John", age: 30 };
var person2 = {
    name: "Steven",
    age: 25,
    talk: function () {
        console.log('I am ' + this.name + ", and I'm " + this.age + " years old.");
    }
};
console.log( person1.name );// John
console.log(person1.age); //30
person2.talk(); // My name is Steven, and I'm 25 years old.

//(1.2) obj property - bracket notation
/* person2.name = "Bob";
person2['age'] = 20;
person2.talk(); */

// (1.3) create obj, dynamically add/delete members
// need to initialize to empty obj using {}, if set to null, cannot add property later

//var person4;  //when set obj property person4.name = "James"; TypeError: Cannot set property 'name' of undefined
//var person4 = null; //when set obj property person4.name = "James"; TypeError: Cannot set property 'name' of null

/* var person4 = {};
// equivalent to: var person4 = new Object();

person4.name = "James";
person4.age = 30;
person4.show = function () {
    console.log('My name is ' + this.name + ", and I'm "
        + this.age + " years old.");
};

console.log(person4.name);  //James
person4.show();

delete person4.age; 
person4.show();  //My name is James, and I'm undefined years old.

person4.phone = "231-223-4211";
console.log(person4); */

////////// (1.4) for- in loop for js objs, iterates over the enumerable properties of an object, in arbitrary order
// iterates over the enumerable properties of an object, in arbitrary order. 
/* var student = {name:"John", program:"CPD", semester:2};
var str = "Student info:\n\t";

for (var x in student) { // x stands for …?
    str += x + ": " + student[x] + "\n\t"; 
}
console.log(str); */

/////--=== (2.1) create objs - using function constructor
/* function Person(name1, age1) {
    this.name = name1;
    this.age = age1;
    this.show = function () {
        console.log('My name is ' + this.name + ", and I'm " + this.age + " years old.");
    };
} */

///// using prototype to avoid duplicate functions.
/* Person.prototype.show = function () {
        console.log('My name is ' + this.name + ", and I'm " + this.age + " years old.");
} */
 /* var person1 = new Person("Person1", 30);
console.log(`Person1's name is ${person1.name}`);
//console.log( person1.age);
person1.show(); // My name is Steven, and I'm 30 years old.

// (2.2) obj and array are assigned by reference
var person2 = person1; //assigned by reference
person2.name = "Person2";  // person1 is changed to also
person2.age = 26;
console.log("=====");
person1.show(); // person1 is same as person2. // My name is Person2, and I'm 26 years old.
person2.show();  //My name is Person2, and I'm 26 years old.

// (2.3) create an instance to keep two copies of the objs
var person3 = new Person("Person3", 33);
console.log("=====");
person1.show();
person2.show();
person3.show(); */  //My name is Person3, and I'm 33 years old.

///// (2.4) Advanced - JS Obj with closure, hiding data
//Usually,JavaScript object properties are "public". 
// This does not conform the basic principle of OOP – Encapsulation.
/* function Person(name, age) {
    return {setName:   function(newName) {name = newName;},
            getName:   function() { return name; },
            
            setAge:       function(newAge) { age = newAge;},
            getAge:       function() { return age; }
             };
  }
  
  var person1 = new Person("John", 25); 
  console.log(`Name: ${person1.getName()}, Age: ${person1.getAge()}`); // Name: John, Age: 25
  console.log(`person1.name is ${person1.name}`); // undefined
  person1.setAge(20);
  console.log(`Name: ${person1.getName()}, Age: ${person1.getAge()}`); // Name: John, Age: 20
 */


