/*****************************************************************************/
//  Filename:      lab4.cpp
//
//  Author:        Praveen Manimaran
//
//  Date:          7/23/2018
//
//  Modifications: Praveen Manimaran - 7/23/2018
//
//
//  Description:This program aids the DeAnza Bookstore in estimating
//  its business for next quarter. Experience has shown that sales depend on
//  whether a book is required or suggested, and on whether or not it has been
//  used before. A new, required book will sell to 90% (.90) of expected
//  enrollment, but if it has been used before (and required) only 65% of the
//  expected enrollment will buy it. Similarly, 40% of the expected enrollment
//  will buy a newly suggested book, but only 20% will purchase a previously
//  (used)suggested book.
//
/*****************************************************************************/

//Pre-processor directives
#include <iostream>
#include <iomanip>
#include <string>

//namespace
using namespace std;

//constants
const double PROFIT_RATE = 0.80;
const double REQUIRED_NEW = 0.90;
const double REQUIRED_OLD = 0.65;
const double SUGGESTED_NEW = 0.40;
const double SUGGESTED_OLD = 0.20;

//prototypes
int calcBooks(int enrollment, char char1, char char2);
double calcProfit(int numOfBooks, double unitPrice);

/*****************************************************************************/
//
// Function:   main()
// Parameters:  none
//
// Outputs: The prompts given to the user and number of books ordered, profit,
//          ISBN number
//
// Returns:    0
//
// Author:     Praveen Manimaran
//
// Date:       7/23/2018
//
// Modifications: 7/23/2018
//
// Description:
// This function prints all of the output and calls other methods to perform
// specific functions.
//
/*****************************************************************************/
int main()
{
   //declarations of local variables
   string bookNum;
   char userInput, userInput2;
   double pricePerCopy, profit;
   int enrollment, numOfBooks;

   //Prompts user to enter the book number
   cout<<"Enter book number: ";
   getline(cin, bookNum);

   //Prompts user to enter the price of each book
   cout<<endl<< "Enter price per copy: ";
   cin>> pricePerCopy;

   //Prompts user to enter the number of students in the class
   cout<<endl<< "Enter expected class enrollment: ";
   cin>>enrollment;

   //Prompts user to enter if the book is required or suggested
   cout<<endl<< "Enter 'R' if required or 'S' if suggested:";
   cin>>userInput;

   //if statements determine whether or not the user entered required(R)
   //or suggested(S)
   if(userInput == 'r' ||userInput == 'R')
   {
      userInput = 'R';
   }
   else if(userInput == 's' ||userInput == 'S')
   {
      userInput = 'S';
   }
   else
   {
      //if user does not input the correct option
      cout<<"ERROR"<<endl;
      exit(0);
   }

   //Prompts user to enter if the book is new or old
   cout<<endl<<"Enter 'N' if new or 'O' if not a new text:";
   cin>>userInput2;

   //if statements determine whether or not the user entered new(N)
   //or old(O)
   if(userInput2 == 'n' ||userInput2 == 'N')
   {
      userInput2 = 'N';
   }
   else if(userInput2 == 'o' ||userInput2 == 'O')
   {
      userInput2 = 'O';
   }
   else
   {
      //if user does not input the correct option
      cout<<"ERROR"<<endl;
      exit(0);
   }
   //calls a method to calculate the number of books to order
   numOfBooks = calcBooks(enrollment, userInput, userInput2);

   //calls a method to calculate the profit that the bookstore makes
   profit = calcProfit(numOfBooks, pricePerCopy);

   //prints the book number
   cout<<endl<<"ISBN: "<< bookNum <<endl;

   //prints out the number of books to order
   cout<<endl<<"Copies Needed: "<<numOfBooks<<endl;

   //prints out the profit that the bookstore makes
   cout<<endl<<"Profit: $ "<<setprecision(2)<<fixed<<profit<<endl;


}
/*****************************************************************************/
//
// Function:   double calcProfit(int numOfBooks, double unitPrice)
//
// Parameters: int numOfBooks - number of books to order
//             double unitPrice - the list price of each book
//
// Outputs:    None
//
// Returns:    profit – the profit of the bookstore
//
// Author:     Praveen Manimaran
//
// Date:       7/23/2018
//
// Modifications: 7/23/2018
//
// Description: This method calculates the profit of the book store based on the
//              the list price and the number of books ordered.
//
//
/*****************************************************************************/

double calcProfit(int numOfBooks, double unitPrice)
{

   double profit;
   profit = (numOfBooks * unitPrice) - (numOfBooks*(PROFIT_RATE*unitPrice));
   return profit;
}
/*****************************************************************************/
//
// Function:   int calcBooks(int enrollment, char char1, char char2)
//
// Parameters: int enrollment - the number of students in the class
//             char char1 - the character if book is required or suggested
//             char char2 - the character if book is new or old
//
// Outputs:    None
//
// Returns:    the number of books sold
//
// Author:     Praveen Manimaran
//
// Date:       7/23/2018
//
// Modifications: 7/23/2018
//
// Description: This method calculates the number of books depending on whether
//              a book is required or suggested, and on whether or not it has
//              been used before.
//
//
/*****************************************************************************/

int calcBooks(int enrollment, char char1, char char2)
{
   int numBooks;
   //if statements determine which conditions the book falls into and performs
   //operations depending on the conditions.
   if(char1 == 'R' && char2 == 'N')
   {
      numBooks = static_cast<int>(enrollment * REQUIRED_NEW +0.5);
   }
   else if(char1 == 'R' && char2 == 'O')
   {
      numBooks = static_cast<int>(enrollment * REQUIRED_OLD + 0.5);
   }
   else if(char1 == 'S' && char2 == 'N')
   {
      numBooks = static_cast<int>(enrollment * SUGGESTED_NEW + 0.5);
   }
   else if(char1 == 'S' && char2 == 'O')
   {
      numBooks = static_cast<int>(enrollment * SUGGESTED_OLD + 0.5);
   }

   return numBooks;
}

/*------------------------paste of run-------------------------------
Set 1 – 0755798652, 34.98, 31, R, O

Enter expected class enrollment: 31

Enter 'R' if required or 'S' if suggested:R

Enter 'N' if new or 'O' if not a new text:O

ISBN: 0755798652

Copies Needed: 20

Profit: $ 139.92
Program ended with exit code: 0
--------------------------------------------------------------------
Set 2 – 3453456784, 23.95, 100, r, N

Enter book number: 3453456784

Enter price per copy: 23.95

Enter expected class enrollment: 100

Enter 'R' if required or 'S' if suggested:r

Enter 'N' if new or 'O' if not a new text:n

ISBN: 3453456784

Copies Needed: 90

Profit: $ 431.10
Program ended with exit code: 0
--------------------------------------------------------------------
Set 3 – 5677655673, 54.50, 40, R, O

Enter book number: 5677655673

Enter price per copy: 54.50

Enter expected class enrollment: 40

Enter 'R' if required or 'S' if suggested:R

Enter 'N' if new or 'O' if not a new text:O

ISBN: 5677655673

Copies Needed: 26

Profit: $ 283.40
Program ended with exit code: 0

--------------------------------------------------------------------
Set 4 – 2462462464, 5.95, 40, s, O

Enter book number: 2462462464

Enter price per copy: 5.95

Enter expected class enrollment: 40

Enter 'R' if required or 'S' if suggested:s

Enter 'N' if new or 'O' if not a new text:O

ISBN: 2462462464

Copies Needed: 8

Profit: $ 9.52
Program ended with exit code: 0

--------------------------------------------------------------------
Set 5 – 8953647888, 65.99, 35, N, Y   ; this is not a(my) typo

Enter book number: 8953647888

Enter price per copy: 65.99

Enter expected class enrollment: 35

Enter 'R' if required or 'S' if suggested:N
ERROR
Program ended with exit code: 0

--------------------------------------------------------------------*/

