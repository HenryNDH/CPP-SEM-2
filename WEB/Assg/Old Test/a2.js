/****************************************************************************
* Assignment 2
* I declare that this assignment is my own work in accordance with Seneca AcademicPolicy.
* No part of this assignment has been copied manually or electronically from any othersource
* (including web sites) or distributed to otherstudents.
* Name: Hoang Duy Nguyen Student ID: 108397217 Date: Feb 02 2022
****************************************************************************/

/***************************** Task1 *************************/
console.log("***************************** Task1 *************************");
var course = function (code, name, hours, url)
{
    this.code = code;
    this.name = name;
    this. hours = hours;
    this.url = url;
}
var course1 = new course ("APC100", "Applied professional communication", 3, "http:/www.senecacollege.ca");
var course2 = new course ("IPC144", "Introduction to C programming", null, "http:/www.senecacollege.ca/ipc");
var course3 = new course ("ULI101", "Linux and the Internet", 4, "http:/www.senecacollege.ca/lin");
var course4 = new course ("IOS110", "Windows Operating System", 4, "http:/www.senecacollege.ca/ios");
var course5 = new course ("EAC150", "College English", 3, null);

var courses = [];
courses.push(course1, course2, course3, course4, course5);

/* c. Create another course object WEB222, which has the same properties as
the objects (in the course array). Its values are as follows: */
var WEB222 = new course ("WEB222", "Web Programming Principles", 4, "http:/www.senecacollege.ca/web");

/*a. Using appropriate array method, Remove the last course object from the given array
courses and store the removed object to a variable. */
var bin = courses.pop(); //<--------------------- Store last course object from the given array to bin

//b. On the console, show the course which was removed from the array in step a. 
console.log();
console.log("The last course in the array is:");
console.log("              code: " + bin.code + ',');
console.log("              name: " + bin.name + ',');
console.log();

//d. Add the course object WEB222 to the end of the courses array
courses.push(WEB222);

//This part is not require but I make this to check if WEB222 added
console.log("The last course in the array is:");
console.log("              code: " + courses[courses.length - 1].code + ',');
console.log("              name: " + courses[courses.length - 1].name + ',');
console.log();

/* e. Use for loop to loop through the course array in order to add the hours of the courses
and log the total hours in the console. Refer to the following sample output. */
var total = 0;
for (var i = 0; i < courses.length; i++)
{
    total += courses[i].hours;
}
console.log("Total hours for all courses: " + total + " hours.");
console.log();

/***************************** Task2 *************************/

console.log("***************************** Task2 *************************");
console.log();
/* a. Create a constructor function (named: Student) which will be used to create objects
with the following: */
function Student(name, dob, sid, program, gpa)
{
    this.name = name;
    this.dob = dob;
    this.sid = sid;
    this.program = program;
    this.gpa = gpa;
}
let date0 = new Date(2002, 2, 3, 24, 0, 0);
date0 = date0.toLocaleString('en-US');
var student0 = new Student('name0', date0, 1001, "BSD", 3.4);
Student.prototype.toString = function studentToString() {
    return `Student info for ${this.name}: 
                Date of Birth: ${this.dob}, 
                Student ID: ${this.sid},
                Program: ${this.program}, 
                GPA: ${this.gpa}`;
};

console.log(student0.toString());
console.log();
// b. Create an empty array named students
var students = [];
let date1 = new Date(2003, 4, 8, 7, 0, 0);
date1 = date1.toLocaleString('en-US');
var student1 = new Student ('Mia', date1, 122397201, "CPP", 3.8);

let date2 = new Date(2001, 1, 6, 2, 0, 0);
date2 = date2.toLocaleString('en-US');
var student2 = new Student ('Alice', date2, 105387201, "CPA", 4.0);

let date3 = new Date(2002, 2, 5, 14, 0, 0);
date3 = date3.toLocaleString('en-US');
var student3 = new Student ('Alie', date3, 103297211, "CPP", 3.2);

let date4 = new Date(2003, 9, 20, 5, 24, 0);
date4 = date4.toLocaleString('en-US');
var student4 = new Student ('Hoang', date4, 108397217, "CPP", 4.0);

students.push(student1, student2, student3, student4);

/* c. Use the forEach method to iterate the array students and output the information of
the student objects to the console.*/
students.forEach(element => console.log(element));
console.log();

/* d. Create a separate function (name it highGPA()), which doesn’t belong to the object
Student. This function*/
function highGPA(arrayName)
{
    var highestGPAflag = -1;
    var highestGPA = 0;
    for (var i = 0; i < arrayName.length; i++)
    {
        if (highestGPA < arrayName[i].gpa)
        {
            highestGPA = arrayName[i].gpa;
            highestGPAflag ++;
        }
    }
    return arrayName[highestGPAflag];
}
console.log();

/* e. Display the student’s information who has the highest GPA by calling the function
highGPA(), passing the array students as argument, and apply student object
member function (toString()).*/
console.log("The student with the highest GPA is: ")
console.log(highGPA(students).toString());