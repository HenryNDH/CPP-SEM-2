/*  Declaration:
I declare that this test is my own work in accordance with Seneca College’s Academic Policies.  No part of this work has been copied manually or electronically from any other source
  (including 3rd party web sites) or distributed to other students.
I acknowledge that by beginning this test, I will abide by the above.
Name: Hoang Duy Nguyen
Student Number: 108397217
*/
const customer = [
    customer1 = {
        first: "Alice",
        last: "Nguyen",
        product1: 1080.89,
        product2: 783.23,
        product3: 68.09    
    },
    customer2 = {
        first: "Anh",
        last: "Van",
        product1: 80.89,
        product2: 73.23,
        product3: 1368.09    
    },
    customer3 = {
        first: "Henry",
        last: "Nguyen",
        product1: 580.89,
        product2: 7083.23,
        product3: 608.09    
    },
    customer4 = {
        first: "Mia",
        last: "Nguyen",
        product1: 100.89,
        product2: 1783.23,
        product3: 6.09    
    }
];
var total = 0;
function getTotal(i)
{
    total = customer[i].product1 + customer[i].product2 + customer[i].product3;
    return total;
}
function p1_level(i)
{
    var level = " ";
    if (customer[i].product1 >= 1000)
    {
        level = "super";
    }   
    else if (customer[i].product1 >= 500)
    {
        level = "good";
    }
    else
    {
        level = "potential";
    }
    return level;
}
function p2_level(i)
{
    var level = " ";
    if (customer[i].product2 >= 1000)
    {
        level = "super";
    }   
    else if (customer[i].product2 >= 500)
    {
        level = "good";
    }
    else
    {
        level = "potential";
    }
    return level;
}
function p3_level(i)
{
    var level = " ";
    if (customer[i].product3 >= 1000)
    {
        level = "super";
    }   
    else if (customer[i].product3 >= 500)
    {
        level = "good";
    }
    else
    {
        level = "potential";
    }
    return level;
}
console.log("================ Task 1 ================")
for (var i = 0; i < customer.length; i++)
{
    console.log(customer[i].first + " " + customer[i].last + " spent total "+  getTotal(i));
}
console.log("================ Task 2 ================")
for (var i = 0; i < customer.length; i++)
{
    console.log(customer[i].first + " " + customer[i].last + " is a");
    console.log(p1_level(i) + " customer for product1,")
    console.log(p2_level(i) + " customer for product2,")
    console.log(p3_level(i) + " customer for product3,")
    console.log("In total, he spent $ " + getTotal(i) + " for all products.")
    console.log("===============================================");
}

