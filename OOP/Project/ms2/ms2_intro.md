# Milestone 2
# The User interface
Now that the Status and Date classes are developed we can create the user interface of the system. 
To accomplish this we need to create two classes; `Menu` and `AidMan` (Aid Management)

## The Menu Module.
Create a class called Menu. 
This class has two attributes.
- A dynamically allocated text that contains the list of options the user can select from.
- An unsigned integer that holds the number of available options.

>For example, if a menu offers three types of drink:
>```text
>1- Orange Juice
>2- Water
>3- Apple Juice
>```
>The text the menu holds will be:
>`"1- Orange Juice\n2- Water\n3- Apple Juice\n"`. <br/>
>In this project we will call this text, **the menu content**.<br />
>Also, the number of options will be `3`.

### Construction
A Menu is created using an unsigned integer and a CString.
The unsigned integer is used to initialize the number of options and a dynamic copy of the CString is held in **the menu content**.
The maximum number of options is 15, if the number of options is more than 15 or if the CString is null, then the menu is rendered invalid.

### Rule of three.
A Menu cannot be copied or assigned to another Menu.
When going out of scope **the menu content** is deallocated to prevent a memory leak.

### Methods
The menu has only one public method called run().
#### run()
This method receives nothing and returns an unsigned integer and will not change the state of the Menu object.

The run method will first display **the menu content** and then prints `"0- Exit"` and goes to newline.
Then it will display `"> "` as a prompt and waits for the user to enter an integer between 0 and the number of options.
This integer entry is foolproof. The user can not exit this stage unless a valid integer number with a valid value is entered. 
- If the user enters a non-integer value the error message should be: `"Invalid Integer, retry: "`. 
- If the user enters an invalid integer then the error message should be: `"Value out of range [0<=val<=X]: "`. Where `X` is the number of options.

In the end, the selected number will be returned.

#### Execution sample
Using the previous example's data an execution sample of the run method will be as follows:
```text
1- Orange Juice
2- Water
3- Apple Juice
0- Exit
> abc<ENTER>
Invalid Integer, retry: 10
Value out of range [0<=val<=3]: 3
```
3 will be returned by the run function.

#### Additional methods
The Menu class with the above capabilities supports what we need from a Menu up to this part of the application. There is no "need" for any additional methods or attributes. However, you are free to add any other functionality needed to make the work easier for you.  

## The AidMan Module

The AidMan Module is the controller of the whole system. We will design it as if the application is complete but with respect to functionality, it will be completely hollow. Essentially at this stage of the development AidMan is only a prototype for the system. 

When all the pieces of the system are developed, we will put them together by adding their role into the AidMan Class.

### Development
Create a class called AidMan that offers a Menu with the list of tasks needed to be done to manage the preparation of products to be shipped to places in need. 

#### Attributes

##### file name
Dynamically holding the name of a data file holding the aid and product information.
##### main menu 
A Menu object.  

#### Private Methods
For now, there is only one private method, but as we advance in the development of the system new methods may be added.

##### menu()
This function receives nothing and returns an unsigned integer that is the user's selection of an option in the main menu of the system. The menu function will not change the state of the AidMan class.

The Menu will first print the title of the application, current date and the data file name.
```text
Aid Management System Version 0.1
Date: YYYY/MM/DD
Data file:  filename.csv
---------------------------------
```
If the **filename** attribute is null, it will print `"No file"` instead of the file name.

Then it will run the main menu and return the selection made by the user.

#### Construction
The AidMan has only one default constructor that initializes the main menu with `7` for the number of options and the following text as **the menu content**:
```text
"1- List Items\n"
"2- Add Item\n"
"3- Remove Item\n"
"4- Update Quantity\n"
"5- Sort\n"
"6- Ship Items\n"
"7- New/Open Aid Database\n"
"---------------------------------\n"
```
The **file name** attribute is also initialized to nullptr.

#### Rule Of Three
- An AidMan object can neither be copied nor assigned to another AinMan object.
- When going out of scope the destructor makes sure there is no memory leak.

### the public method run()
run() receives and returns nothing and runs the whole application.

In a loop, the run function will keep displaying the menu by calling the **menu()** function and awaits the user's entry. Then after each selection, based on the user's entry, it will execute the task chosen from the menu. 

The run function exits when the user selects `0`, at which point it will print `"Exiting Program!"<NEWLINE>` and terminates.

For now, when a task is selected just print the task name as follows:<br />
`<NEWLINE>****Task Name****<2 NEWLINES>`<br />
for example print the following if option 4 is selected:
`<NEWLINE>****Update Quantity****<2 NEWLINES>`<br />