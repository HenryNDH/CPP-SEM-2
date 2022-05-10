// (1) The map() method creates a new array populated with the results of 
// calling a provided function on every element in the calling array.
/* function double(item)
{
    return item * 2;
}
const array1 = [1, 4, 9, 16];

// pass a function to map
//const map1 = array1.map(x => x * 2);
const map1 = array1.map(double); // no () after double, map() takes a function as argument, not a function call
//const map1 = array1.map(double()); // wrong, this means: calling, executing double()

console.log(map1); */
// expected output: Array [2, 8, 18, 32]

// (2) filter(): creates a new array with all elements that pass the test implemented by the provided function.
/* function longWord(item)
{
    if (item.length>6)
       return item;
}
const words = ['spray', 'limit', 'elite', 'exuberant', 'destruction', 'present'];

// const result = words.filter(word => word.length > 6);
const result = words.filter(longWord); // no () after the function longWord
// const result = words.filter(longWord () ); // wrong, filter takes a function as argument, longWord() is calling a function

console.log(result); */
// expected output: Array ["exuberant", "destruction", "present"]

//(3) find(): returns the value of the first element in the provided array that satisfies the provided testing function.
function findElement(element)
{
    if (element > 10)
        return element; 
}
const array2 = [5, 12, 8, 130, 44];

//const found = array2.find(element => element > 10);
const found = array2.find(findElement);
//const found = array2.find(findElement()); wrong
console.log(found);
// expected output: 12
