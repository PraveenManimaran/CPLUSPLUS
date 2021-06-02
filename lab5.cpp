/*****************************************************************************/
//  Filename:      lab5.cpp
//
//  Author:        Praveen Manimaran
//
//  Date:          7/28/2018
//
//  Modifications: Praveen Manimaran - 7/28/2018
//
//
//  Description:   Write a C++ program to calculate the monthly cost of a house
//                 given the selling price, annual rate of interest, and number
//                 of years for the loan.
//
/*****************************************************************************/

//preprocessor directives
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

//macro to define a constant for tax rate, insurance cost and cost of utilities
#define TAX_RATE 0.0125
#define INSURANCE_COST 550.00
#define UTILITIES_COST 300.00

//prototypes
void inputAllData(double &, double &, int &);
void calcMonthlyCost(double sellingPrice, double rateOfInterest,int loanYears,
                     double DOWN_PAYMENT_RATE);
double calcDownPayment(double sellingPrice, double DOWN_PAYMENT_RATE);
double calcLoanAmount(double downPayment, double sellingPrice);
double calcMonthlyMortgage(double loanAmount, double rateOfInterest,
                           double loanYears, double sellingPrice);
void outputInfo(double sellingPrice,double rateOfInterest,int loanYears,double
             downPayment,double loanAmount,double monthlyMortgage,double total);

/*****************************************************************************/
//
// Function:  main()
//
// Parameters: none
//
// Outputs:    None
//
// Returns:   0
//
// Author:     Praveen Manimaran
//
// Date:       7/28/2018
//
// Modifications: 7/28/2018
//
// Description: This method calls methods to ask the user for input and calculate
//              the monthly cost
//
//
/*****************************************************************************/

int main()
{
   // define all the variables first
   const double DOWN_PAYMENT_RATE = 0.20;
   double sellingPrice, rateOfInterest;
   int loanYears;

   inputAllData(sellingPrice, rateOfInterest, loanYears);
   calcMonthlyCost(sellingPrice,rateOfInterest,loanYears, DOWN_PAYMENT_RATE);
   return 0;

}
/*****************************************************************************/
//
// Function:   inputAllData(double &sellingPrice, double &rateOfInterest,
//                          int &loanYears)
//
// Parameters: double &sellingPrice     - the selling price of the house
// (Inputs)    double &rateOfInterest   - the rate of interest
//             int &loanYears           - the loan years
//
// Outputs:    Prompts user to enter info
//
// Returns:    none
//
// Author:     Praveen Manimaran
//
// Date:       7/28/2018
//
// Modifications: 7/28/2018
//
// Description: This function prompts the user to enter the selling price, rate
//              of interest, and the number of years for loan
//
//
/*****************************************************************************/

void inputAllData(double &sellingPrice, double &rateOfInterest, int &loanYears)
{
   //Prompts user to enter info
   cout<<left<<setw(10)<<"Selling price:";
   cin>>sellingPrice;
   cout<<left<<setw(10)<<"Rate Of Interest:";
   cin>>rateOfInterest;
   cout<<left<<setw(10)<<"Number of Years for Loan: ";
   cin>>loanYears;

}
/*****************************************************************************/
//
// Function:   calcMonthlyCost(double sellingPrice, double rateOfInterest,
//                             int loanYears,double DOWN_PAYMENT_RATE)
//
// Parameters: double sellingPrice     - the selling price of the house
// (Inputs)    double rateOfInterest   - the rate of interest
//             int loanYears           - the loan years
//             DOWN_PAYMENT_RATE       - the down payment rate
//
// Outputs:    none
//
// Returns:    none
//
// Author:     Praveen Manimaran
//
// Date:       7/28/2018
//
// Modifications: 7/28/2018
//
// Description: This function calls methods to get down payment, loan amount,
//              and monthly mortgage.It also calls a method to print the results
//
/*****************************************************************************/

void calcMonthlyCost(double sellingPrice, double rateOfInterest,int loanYears,
                     double DOWN_PAYMENT_RATE)
{
   //calls methods to get down payment, loan amount, and monthly mortgage
   double monthlyCost, downPayment, loanAmount, monthlyMortgage,total;
   downPayment = calcDownPayment(sellingPrice, DOWN_PAYMENT_RATE);
   loanAmount = calcLoanAmount(downPayment, sellingPrice);
   monthlyMortgage = calcMonthlyMortgage(loanAmount, rateOfInterest, loanYears,
                                         sellingPrice);
   //calculate the total month amount
   total = monthlyMortgage + UTILITIES_COST + (INSURANCE_COST/12) +
           (sellingPrice * TAX_RATE)/12;

   //calls method to output the results
   outputInfo(sellingPrice,rateOfInterest,loanYears, downPayment, loanAmount,
              monthlyMortgage,total);

}
/*****************************************************************************/
//
// Function:   outputInfo(double sellingPrice,double rateOfInterest,
//                        int loanYears,double downPayment,double loanAmount,
//                        double monthlyMortgage,double total)
//
// Parameters: double sellingPrice     - the selling price of the house
// (Inputs)    double rateOfInterest   - the rate of interest
//             int loanYears           - the loan years
//             double downPayment      - the down payment
//             double loanAmount       - the loan amount
//             double monthlyMortgage  - the monthly mortgage
//             double total            - the total cost per month
//
// Outputs:    PRINTS OUT THE RESULTS FORMATTED to another file
//
// Returns:    none
//
// Author:     Praveen Manimaran
//
// Date:       7/28/2018
//
// Modifications: 7/28/2018
//
// Description: This function PRINTS OUT THE RESULTS FORMATTED to another file.
//
/*****************************************************************************/

void outputInfo(double sellingPrice,double rateOfInterest,int loanYears,double
             downPayment,double loanAmount,double monthlyMortgage,double total)
{
   ofstream outFile;
   outFile.open("output.txt");//file name

   //PRINTS OUT THE RESULTS FORMATTED
   outFile<<"********************************************************************"
          <<endl;
   outFile<<right<<setw(45)<<"MONTHLY COST OF HOUSE"<<endl;
   outFile<<"********************************************************************"
          <<endl;
   outFile<<left<<setw(30)<<"SELLING PRICE";
   outFile<<right<<setw(20)<<"$ ";
   outFile<<right<<setw(10)<<setprecision(2)<<fixed<<sellingPrice<<endl;

   outFile<<left<<setw(30)<<"DOWN PAYMENT";
   outFile<<right<<setw(20)<<"$ ";
    outFile<<right<<setw(10)<<setprecision(2)<<fixed<<downPayment<<endl;

   outFile<<left<<setw(30)<<"AMOUNT OF LOAN";
   outFile<<right<<setw(20)<<"$ ";
   outFile<<right<<setw(10)<<setprecision(2)<<fixed<<loanAmount<<endl<<endl
          <<endl;

   outFile<<left<<setw(30)<<"INTEREST RATE";
   outFile<<right<<setw(15)<<setprecision(2)<<fixed<<rateOfInterest<<"%"<<endl;
   outFile<<left<<setw(30)<<"TAX RATE";
   outFile<<right<<setw(15)<<setprecision(2)<<fixed<<TAX_RATE*100<<"%"<<endl<<endl;
   outFile<<left<<setw(30)<<"DURATION OF LOAN (YEARS)";
   outFile<<right<<setw(12)<<loanYears<<" yrs"<<endl<<endl<<endl<<endl<<endl;

   outFile<<"**************************"
   <<endl;
   outFile<<"MONTHLY PAYMENT"<<endl;
   outFile<<"**************************"
   <<endl<<endl;

   outFile<<left<<setw(30)<<"MORTGAGE PAYMENT";
   outFile<<right<<setw(20)<<"$ ";
   outFile<<right<<setw(10)<<setprecision(2)<<fixed<<monthlyMortgage<<endl;

   outFile<<left<<setw(30)<<"UTILITIES";
   outFile<<right<<setw(20)<<"$ ";
   outFile<<right<<setw(10)<<setprecision(2)<<fixed<<UTILITIES_COST<<endl;

   outFile<<left<<setw(30)<<"PROPERTY TAXES";
   outFile<<right<<setw(20)<<"$ ";
   outFile<<right<<setw(10)<<setprecision(2)<<fixed<<(sellingPrice * TAX_RATE)/12
          <<endl;

   outFile<<left<<setw(30)<<"INSURANCE";
   outFile<<right<<setw(20)<<"$ ";
   outFile<<right<<setw(10)<<setprecision(2)<<fixed<<INSURANCE_COST/12<<endl;

   outFile<<right<<setw(60)<<"----------------"<<endl;
   outFile<<right<<setw(50)<<"$ ";
   outFile<<right<<setw(10)<<setprecision(2)<<fixed<<total<<endl;

   outFile.close(); //close the file
}
/*****************************************************************************/
//
// Function:   calcDownPayment(double sellingPrice, double DOWN_PAYMENT_RATE)
//
// Parameters: double sellingPrice      - the selling price of the house
//             double DOWN_PAYMENT_RATE - the down payment rate
//
//
// Outputs:    none
//
// Returns:    the down payment
//
// Author:     Praveen Manimaran
//
// Date:       7/28/2018
//
// Modifications: 7/28/2018
//
// Description: This function calculates the down payment and returns it.
//
/*****************************************************************************/

double calcDownPayment(double sellingPrice, double DOWN_PAYMENT_RATE)
{
   //calculates the down payment and returns
   double downPayment = sellingPrice*DOWN_PAYMENT_RATE;
   return downPayment;
}
/*****************************************************************************/
//
// Function:  calcLoanAmount(double downPayment, double sellingPrice)
//
// Parameters: double sellingPrice     - the selling price of the house
//             double downPayment      - the down payment
//
// Outputs:    none
//
// Returns:    the loan amount
//
// Author:     Praveen Manimaran
//
// Date:       7/28/2018
//
// Modifications: 7/28/2018
//
// Description: This function calculates the loan amount
//
/*****************************************************************************/

double calcLoanAmount(double downPayment, double sellingPrice)
{
    //calculates the loan amount and returns
   double loanAmount = sellingPrice - downPayment;
   return loanAmount;

}
/*****************************************************************************/
//
// Function:   calcMonthlyMortgage(double loanAmount, double rateOfInterest,
//                                 double loanYears, double sellingPrice)
//
// Parameters: double sellingPrice     - the selling price of the house
// (Inputs)    double rateOfInterest   - the rate of interest
//             int loanYears           - the loan years
//             double loanAmount       - the loan amount
//
// Outputs:    none
//
// Returns:    the monthly mortgage
//
// Author:     Praveen Manimaran
//
// Date:       7/28/2018
//
// Modifications: 7/28/2018
//
// Description: This function calculates the monthly mortgage with a formula
//              and returns it
//
/*****************************************************************************/
double calcMonthlyMortgage(double loanAmount, double rateOfInterest,
                           double loanYears, double sellingPrice)
{
   //calculates the monthly mortgage with a formula and returns
   double monthlyMortgage;
   rateOfInterest = (rateOfInterest/100) / 12;
   monthlyMortgage=(loanAmount*(rateOfInterest)*pow(1+rateOfInterest,
                    loanYears*12)) / (pow(1+rateOfInterest, loanYears*12)-1);

   return monthlyMortgage;
}

/*------------------------paste of run-------------------------------
Selling price:600000
Rate Of Interest:5
Number of Years for Loan: 20
Program ended with exit code: 0

-----------------------------------------------------
Selling price:400000
Rate Of Interest:4.2
Number of Years for Loan: 30
Program ended with exit code: 0

--------------------------------------------------------------------*/

