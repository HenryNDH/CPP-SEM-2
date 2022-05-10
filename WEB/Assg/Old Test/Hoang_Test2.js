/*  
Declaration:
I declare that this test is my own work in accordance with Seneca College’s Academic Policies.  No part of this work has been copied manually or electronically from any other source
  (including 3rd party web sites) or distributed to other students.
I acknowledge that by beginning this test, I will abide by the above.
Name: Nguyen Duy Hoang
Student Number: 108397217
*/
var name;
var newname;
function capitalizeName(name){
   if(isNaN(parseInt(name))){
    newname = name.toLowerCase()
    newname = name.split(' ');
    var i = 0;
    for (i = 0; i < newname.length; i++){
        newname[i] = newname[i].charAt(0).toUpperCase() + newname[i].substring(1);
    }
    newname = newname.join(' ');
    return newname;
    }
    else{
    return name;
    }
}
console.log(capitalizeName("Bryan stevenson"));
console.log(capitalizeName("jayce a. tapia"));
console.log(capitalizeName("math"));
console.log(capitalizeName("I love programming"));
console.log(capitalizeName("1+2+3"));
console.log(capitalizeName("Good Morning"));