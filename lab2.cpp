/*****************************************************************************/
//
// Filename:      lab2_sln.cpp
//
// Author:        Victor Lau
//
// Date:          2018.01.15
//
// Modifications: 2018.05.22
//
// Copyright:
//
// Description:
// This program generate a monthly sales tax report listing the sales for the
// month and the amount of sales tax collected.
// In the beginning, it asks for the month, the year, and the total receipt,
// amount collected at the cash register (that is, sales plus sales tax).
// Assume the state sales tax is 5.3% and the county sales tax is 3.1%.
//
/*****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// use macro to define a constant for the STATE_TAX_RATE
#define STATE_TAX_RATE 0.053

/*****************************************************************************/
//                                  main()
/*****************************************************************************/
int main( )
{
   // define all the variables first
   const double COUNTY_TAX_RATE = 0.031;
   double sales, state_tax, county_tax, total_receipts, total_tax;
   int year;
   string month;

   // Gets the month and year in question and store them in memory.
   cout << "Please enter month: ";
   cin >> month;
   // alternative way:
   // getline( cin, month );

   cout << "Please enter year: ";
   cin >> year;

   // Takes how much money was collected in the said month and stores it for
   // later in "total_receipts"
   cout << "How much money was collected in " << month << "?: $";
   cin >> total_receipts;
   cout << endl << endl;

   // All the arithmetic is done here, namely caculating the sales, and taxes amounts.
   // (Assigns proper values to sales, state_tax, county_tax, and total_tax)
   sales = total_receipts / (1 + STATE_TAX_RATE + COUNTY_TAX_RATE);
   state_tax = sales * STATE_TAX_RATE;
   county_tax = sales * COUNTY_TAX_RATE;
   total_tax = state_tax + county_tax;

   /**********************************************************/
   //
   //   Output the result tabulated with adequate formatting
   //
   /**********************************************************/
   // this only have to be done once, for all output numeric data are
   // dollar amounts
   cout << setprecision(2) << fixed;

   // write the first line with date info - month and year
   cout << endl << "Date: " << month << ", " << year << endl
   << "--------------------" << endl;

   // write the first line with the Total collected amount
   cout << left << setw(20) << "Total collected:" << right << setw(3) << "$"
   << setw(10) << total_receipts << endl;

   // write the second line with the Total Sales amount
   cout << left << setw(20) << "Total Sales:" << right << setw(3) << "$"
   << setw(10) << sales << endl;

   // write the third line with County Sales Tax amount
   cout << left << setw(20) << "County Sales Tax:" << right << setw(3) << "$"
   << setw(10) << county_tax << endl;

   // write the forth line with State Sales Tax amount
   cout << left << setw(20) << "State Sales Tax:"  << right << setw(3) << "$"
   << setw(10) << state_tax << endl;

   // write the fifth line with Total Sales Tax amount
   cout << left << setw(20) << "Total Sales Tax:"  << right << setw(3) << "$"
   << setw(10) << total_tax << endl << endl;

   return 0;
}
/*****************************************************************************/
//                              End of main()
/*****************************************************************************/














/*
// lab2.cpp
// Praveen Manimaran
// 7/11/18
// This program asks for the month, the year, and the total amount collected at
// the cash register (that is, sales plus sales tax)

#include <iostream>
#include <iomanip>
#include <string>
#define STATE_TAX 0.053

using namespace std;


int main()
{
   const double COUNTY_TAX = 0.031;
   const double COMBINED_TAX_RATE = 1.084;
   string month;
   int year;
   double total, sales, countySalesTax, stateSalesTax, totalSalesTax;


   cout << "Praveen Manimaran" << endl << endl; //prints out my name

   //Prompts user to enter month
   cout << "Month: ";
   getline(cin, month);

   //Prompts user to enter year
   cout << "Year: ";
   cin >> year;
   cout << endl << "--------------------" << endl;

   // Prompts user to enter the total collected
   cout << setw(20) << left << "Total Collected: " << setw(5) << "$" << right
        << "";
   cin >> total;

   //Calculates and prints out the sales
   sales = total/COMBINED_TAX_RATE;
   cout << setw(20) << left << "Sales: " << setw(5) << "$" << right
        << setprecision(7) << showpoint << sales << endl;

   //Calculates and prints out the County Sales Tax
   countySalesTax = COUNTY_TAX * sales;
   cout << setw(20) << left << "County Sales Tax: " << setw(6) << "$" << right
        << setprecision(6) << showpoint << countySalesTax <<endl;

   //Calculates and prints out the State Sales Tax
   stateSalesTax = STATE_TAX * sales;
   cout << setw(20) << left << "State Sales Tax: "<< setw(6) << "$" << right
        << setprecision(6) << showpoint << stateSalesTax <<endl;

   //Calculates and prints out the Total Sales Tax
   totalSalesTax = stateSalesTax + countySalesTax;
   cout << setw(20)<<left<<"Total Sales Tax: "<< setw(6)<< "$" << right
        << setprecision(6)<<showpoint<< totalSalesTax << endl << endl;

   return 0;
}

 */

/*------------------------paste of run-------------------------------
Praveen Manimaran

Month: December
Year: 2015

--------------------
Total Collected:    $    81673.67
Sales:              $    75344.71
County Sales Tax:   $     2335.69
State Sales Tax:    $     3993.27
Total Sales Tax:    $     6328.96

Program ended with exit code: 0
 --------------------------------------------------------------------*/
