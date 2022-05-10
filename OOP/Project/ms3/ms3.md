# Milestone 3
## Core classes overview
Overall there are going to be 3 core classes in this application:
### iProduct
An interface for an Item in the application
### Item
An Item is a concrete iProduct to keep track of the quantity and on-hand-quantity items to be prepared for shipping
### Perishable
A Pereishabe is a concrete Item that has an expiry date

### Class diagram
![Class diagram](images/classes.png)

## MS3 development
Your task for MS3 is to develop the iProduct and the Item modules.

## The iProduct interface

Create an inteface module with the following Pure functions:
```C++
// to read the Stock-Keeping Unit from console before
// main data entry
int readSku(std::istream& istr);
// to reduce the quantity on hand
int operator-=(int qty);
// to increase the quantity on hand
int operator+=(int qty);
// returns the price of the produce
operator double()const;
// returns if the iProduct is in a good state
operator bool()const;
// returns the number of products needed
int qtyNeeded()const;
// retuns the quantity on hand
int qty()const;
// determines if the iProduct is displayed in a linear format or 
// descriptive format
void Linear(bool isLinear);
// saves the iProduct into a file
std::ofstream& save(std::ofstream& ofstr)const;
// loads an iProduct from a file
std::ifstream& load(std::ifstream& ifstr);
// displays the iProduct on the screen
std::ostream& display(std::ostream& ostr)const;
// reads the iProduct from the console
std::istream& read(std::istream& istr);
// return true if the sku is a match to the iProduct's sku
bool operator==(int sku)const;
// rtrns true if the description is found in the iPorduct's description
bool operator==(const char* description)const;

```
Also, set up the destructor of the iProduct to make sure the dynamic descendants of the iProduct interface will not have a memory leak if when going out of scope.

### Insertion and extraction operator overloads.
Overload the Insertion and extraction operators for istream and ostream to call the display and the read methods of the iProduct.

## iProductTester
This tester program should generate the following output with no memory leak:
### iProductTester output
```text
load
save
operator bool
operator double
qtyNeeded
qty
operator==(cosnt char*)
operator==
operator+=
operator-=
readSku
Linear
```
### The Tester
```C++
/* ------------------------------------------------------
Final project Milestone 3
Module: iProductTester.cpp
Filename: main.cpp
Version 1.0
Author: Fardad Soleimanloo   2022-03-03
Revision History
-----------------------------------------------------------
Date          Reason
-----------------------------------------------------------*/
#include <iostream>
#include <fstream>
using namespace std;
#include "iProduct.h"
using namespace sdds;
class Product : public iProduct {
   char* dyntest{};
public:
   int readSku(std::istream& istr) {
      cout << "readSku" << endl;
      return 0;
   }
   int operator-=(int qty) {
      cout << "operator-=" << endl;
      return 0;
   }
   int operator+=(int qty) {
      cout << "operator+=" << endl;
      return 0;
   }
   operator double()const {
      cout << "operator double" << endl;
      return 0.;
   }
   operator bool()const {
      cout << "operator bool" << endl;
      return false;
   }
   int qtyNeeded()const {
      cout << "qtyNeeded" << endl;
      return 0;
   }
   int qty()const {
      cout << "qty" << endl;
      return 0;
   }
   void Linear(bool isLinear) {
      cout << "Linear" << endl;
   }
   std::ofstream& save(std::ofstream& ofstr)const {
      cout << "save" << endl;
      return ofstr;
   }
   std::ifstream& load(std::ifstream& ifstr) {
      cout << "load" << endl;
      return ifstr;
   }
   std::ostream& display(std::ostream& ostr)const {
      operator bool();
      operator double();
      qtyNeeded();
      qty();
      operator==("");
      operator== (2);
      return ostr;
   }
   std::istream& read(std::istream& istr) {
      operator+=(1);
      operator-=(1);
      readSku(istr); 
      Linear(true);
      dyntest = new char[2345];
      return istr;
   }
   bool operator==(int sku)const {
      cout << "operator==" << endl;
      return false;
   }
   bool operator==(const char* desc)const {
      cout << "operator==(cosnt char*)" << endl;
      return false;
   }
   ~Product() {
      delete[] dyntest;
   }
};

int main() {
   iProduct* P = new Product;
   ifstream in("tst.txt");
   ofstream out("tst.txt");
   P->load(in);
   P->save(out);
   cout << *P;
   cin >> *P;
   delete[] P;
   return 0;
}
```
## The Item Module

Derive a concrete class called Item class from the iProduct class.

### Private Attributes
Add the following private attributes to the Item:
- a double for the price
- an integer for quantity on hand
- an integer for needed quantity. This integer is the target amount for the item to be acquired.
- a dynamic Cstring for (not a C++ string) for the description of the item.
- a boolean flag to dictate to the display function if the next output is going to be linear to descriptive.

### Protected Attributs
Add the following attributes to be accessible to the descendants of the **Item**.
- a Status object to hold the state of the Item object
- an integer value to hold the Stock-Keeping Unit number.

### Protected Method

- create a query called **linear** that returns the linear flag of the **Item**

### Construction
The Item is has a default constructor that sets all the attributes to zero, nullptr and false.

#### Rule of three
Rule of three is implemented to make sure there is no memory leak in case of copying, assignment or destruction.

### virtual public query iProduct overrides 
  - the **qtyNeeded** method returns the needed-quantity attribute
  - the **qty** method returns the on-hand quantity attribute
  - the **double conversion operator** overload returns the price
  - the **boolean conversion operator** overload returns the state of the object being good.
  
### virtual public modifier iProduct overrides
  - the operator-= reduces the on-hand quantity by the received value
  - the operator+= increases the on-hand quantity by the received value
  - the linear modifier sets the linear flag attribute to true or false.

### public modifier
  - create a modifier called clear that does not accept any argument and sets the state of the Item object back to good, by resetting the state attribute.

### virtual operator== iProduct overrides
  - the integer comparison returns true if the SKU attribute matches the received value
  - the constant character pointer comparison searches in the description of the Item for the appearance of the received Cstring. If a match was found it returns true. If any of the descriptions (The Items or the received value) are null or the match is not found, it will return false.

### virtual Input/Output method iProduct overrides

#### save
If the state of the Item is good, it will write SKU, description, on-hand quantity, needed quantity and price in tab-separated format. 

> note that the price should be written with 2 digits after the decimal point.

No newline is added.

If the state is not good, it will do nothing. 

In the end, the reference of the ofstream is returned.

#### load
After deallocating the description:

The tab-separated SKU, description, on-hand quantity, needed quantity and price are read into their corresponding attributes and then a single character is discarded from the file.  

If ifstream is in a bad state after the read the state of the item will be set to `"Input file stream read failed!"`

> Note that the description is dynamically allocated

In the end, the reference of ifstream is returned.

#### display
If the state is bad, the state is printed instead.

If the state is good the following will be done.

##### If in linear format  
SKU, description, on-hand quantity, needed quantity and price are printed in the following format:

```text
##### | AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA | #### | #### | ####.## |
Example:
45678 | Sleeping Bags                       |  100 |  200 |   65.66 |
45678 | Sleeping Bags and blankets with pil |  100 |  200 |   65.66 |
```
> Note that if the description is too long only the first 35 characters will be printed

No newline is inserted after.

##### If in descriptive format 

The information is printed in the following format with a newline after.

```text
AMA Item:
SKU: The description is printed fully
Quantity Needed: ###
Quantity Available: ###
Unit Price: $####.##
Needed Purchase Fund: $##.##

Example:  
AMA Item:
45678: Sleeping Bags
Quantity Needed: 200
Quantity Available: 100
Unit Price: $65.66
Needed Purchase Fund: $6566.00
```
> Needed Purchase Fund is the amount of money needed to buy the rest of the needed amount to fulfill the needed quantity

#### readSku and read
Entering the information through the console is done in two stages; readSku and read.

##### readSku
Reads the SKU from the screen with the prompt `"SKU: "`. It makes sure the SKU number begins with digits 4 to 9 and it is 5 digits long.

The entry is full-proof, example:

```text
SKU: ten<ENTER>
Invalid Integer, retry: 12345<ENTER>
Value out of range [40000<=val<=99999]: 45678<ENTER>
```

##### read
After deleting the description and clearing the state.

**read** will first prompt the user with the title "AMA Item" and then displays the SKU and reads the rest of the information in a full-proof way (the same as SKU).

Example:

```text
AMA Item:
SKU: 44444
Description: Sleeping Bag<ENTER>
Quantity Needed: 200<ENTER>
Quantity On Hand: 100<ENTER>
Unit Price: $65.66<ENTER>
```

Valid values are as follows:
- Description: Unknown length of characters
- Quantity Needed: integers between 1 and 9999
- Quantity On Hand: integers between 0 and the needed quantity.
- Price: double values between 0.0 and 9999.0 Dollars.

If the istream fails during reading, the state is set to `"Console entry failed!"`

The istream reference is returned in the end.

### Tester program
```C++
/* ------------------------------------------------------
Final project Milestone 3
Module: iProduct and Item
Filename: main.cpp
Version 1.0
Author: Fardad Soleimanloo   2022-03-19
Revision History
-----------------------------------------------------------
Date          Reason
-----------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include "iProduct.h"
#include "Item.h"
using namespace std;
using namespace sdds;
void resetToOriginal();
void entryAndSave();
void descriptive();
void linear();
int main() {
   resetToOriginal();
   entryAndSave();
   cout << "------------------------" << endl;
   descriptive();
   cout << "------------------------" << endl;
   linear();
   cout << "------------------------" << endl;
   return 0;
}
void resetToOriginal() {
   ifstream in("dataOriginal.dat");
   ofstream out("data.dat");
   char ch;
   while (in.get(ch)) out.put(ch);
}
void entryAndSave() {
   ofstream file("data.dat", ios::app);
   iProduct* p = new Item;
   cout << "Enter the following values: " << endl
      << 
      "abc\n"
      "1111\n"
      "44444\n"
      "Blanket\n"
      "abc\n"
      "222222\n"
      "22\n"
      "abc\n"
      "222\n"
      "2\n"
      "abc\n"
      "22222222\n"
      "22.22\n" << "------------------------" << endl;
   p->readSku(cin);
   cin >> *p;
   cout << "------------------------" << endl;
   cout << *p;
   cout << "------------------------" << endl;
   p->linear(true);
   cout << *p << endl;
   p->save(file) << endl;
   file.flush();
   file.close();
   delete p;
}
void descriptive() {
   ifstream file("data.dat");
   iProduct* p;
   p = new Item;
   while (p->load(file)) {
      cout << *p << endl;
   }
   delete p;
}
void linear() {
   ifstream file("data.dat");
   iProduct* p;
   p = new Item;
   while (p->load(file)) {
      if (*p == 44444) {
         p->linear(true);
         (*p) += 10;
         cout << "------------------------" << endl;
         cout << *p << endl;
         cout << "Need: " << p->qtyNeeded() << endl;
         cout << "Have: " << p->qty() << endl;
         cout.setf(ios::fixed);
         cout.precision(2);
         cout << "Price: " << double(*p) << endl;
      }
      if (*p == "kets") {
         p->linear(true);
         (*p) -= 5;
         cout << "------------------------" << endl;
         cout << *p << endl;
         cout << "Need: " << p->qtyNeeded() << endl;
         cout << "Have: " << p->qty() << endl;
         cout << "This object is in a " << (bool(*p)?"good":"bad") << " state!" << endl;
      }
   }
   delete p;
}


```

### Tester program output
```text
Enter the following values:
abc
1111
44444
Blanket
abc
222222
22
abc
222
2
abc
22222222
22.22
------------------------
SKU: abc
Invalid Integer, retry: 1111
Value out of range [40000<=val<=99999]: 44444
AMA Item:
SKU: 44444
Description: Blanket
Quantity Needed: abc
Invalid Integer, retry: 222222
Value out of range [1<=val<=9999]: 22
Quantity On Hand: abc
Invalid Integer, retry: 222
Value out of range [0<=val<=22]: 2
Unit Price: $abc
Invalid number, retry: 22222222
Value out of range [0.00<=val<=9999.00]: 22.22
------------------------
AMA Item:
44444: Blanket
Quantity Needed: 22
Quantity Available: 2
Unit Price: $22.22
Needed Purchase Fund: $444.40
------------------------
44444 | Blanket                             |    2 |   22 |   22.22 |
------------------------
AMA Item:
45678: Sleeping Bags
Quantity Needed: 200
Quantity Available: 100
Unit Price: $65.66
Needed Purchase Fund: $6566.00

AMA Item:
56789: Tents and Blankets and pillows Tents and Blankets and pillows Tents and Blankets and pillows Tents and Blankets and pillows Tents and Blankets and pillows Tents and Blankets and pillows Tents and Blankets and pillows Tents and Blankets and pillows Tents and Blankets and pillows Tents and Blankets and pillows Tents and Blankets and pillows
Quantity Needed: 2000
Quantity Available: 134
Unit Price: $165.99
Needed Purchase Fund: $309737.34

AMA Item:
44444: Flash lights
Quantity Needed: 400
Quantity Available: 0
Unit Price: $5.99
Needed Purchase Fund: $2396.00

AMA Item:
44444: Blanket
Quantity Needed: 22
Quantity Available: 2
Unit Price: $22.22
Needed Purchase Fund: $444.40

------------------------
------------------------
56789 | Tents and Blankets and pillows Tent |  129 | 2000 |  165.99 |
Need: 2000
Have: 129
This object is in a good state!
------------------------
44444 | Flash lights                        |   10 |  400 |    5.99 |
Need: 400
Have: 10
Price: 5.99
------------------------
44444 | Blanket                             |   12 |   22 |   22.22 |
Need: 22
Have: 12
Price: 22.22
------------------------

```

### Files to submit
```text
Utils.cpp
Utils.h
Status.cpp
Status.h
iProduct.h
iProduct.cpp
Item.h
Item.cpp
main.cpp
```

Upload your source codes and the tester program to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/mX
```
and follow the instructions.

- *2??* is replaced with your subject code
- *X* is replaced with milestone number

### The submitter program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to milestones](#milestones)