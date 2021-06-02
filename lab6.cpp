/*****************************************************************************/
//  Filename:      lab6.cpp
//
//  Author:        Praveen Manimaran
//
//  Date:          8/2/2018
//
//  Modifications: Praveen Manimaran - 8/2/2018
//
//
//  Description:   This C++ program outputs the payment schedule for amount owed
//                 when each month nothing more is charged to the account but
//                 only the minimum payment is paid. The output stops when the
//                 balance is fully paid (i.e. no longer > 0).
//
/*****************************************************************************/

//preprocessor directives
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;
//prototypes
void inputData(double &creditCardBalance, double &cardInterestRate,
               double &minimumPaymentPercent);
void calcAmountOfInterest(double &monthInterest, double &totalInterest,
                          double &minimumPayment,double &creditCardBalance,
                          double &cardInterestRate,double &minimumPaymentPercent);

void writeHeader(ofstream &outFile, double originalBalance,
                 double cardInterestRate,double minimumPaymentPercent);
void writeOutput(ofstream &outFile,double creditCardBalance,
                 int count,double monthInterest,double minimumPayment,
                 double totalInterest);
/*****************************************************************************/
//
// Function:   main()
//
// Parameters: none
//
// Outputs:    none
//
// Returns:    0
//
// Author:     Praveen Manimaran
//
// Date:       8/3/2018
//
// Modifications: 8/3/2018
//
// Description: calls methods to read from a file and write to a file
//
/*****************************************************************************/
int main()
{
   double originalBalance, creditCardBalance, cardInterestRate, minimumPaymentPercent;
   double monthInterest, totalInterest, minimumPayment;
   int count = 1; //month number

   ofstream outFile;
   outFile.open("output.txt");//file name

   //method to input data
   inputData(originalBalance, cardInterestRate, minimumPaymentPercent);
   creditCardBalance = originalBalance;
   //method to output the header
   writeHeader(outFile, originalBalance,
               cardInterestRate,minimumPaymentPercent);

   //as long as there is money in credit card
   while(creditCardBalance>0)
   {
      //calculate the interest
      calcAmountOfInterest(monthInterest, totalInterest, minimumPayment,
                           creditCardBalance,cardInterestRate,
                           minimumPaymentPercent);
      //write the output to a file
      writeOutput(outFile,creditCardBalance,
                  count, monthInterest, minimumPayment,
                  totalInterest);
      //increment month number
      count++;

   }
   return 0;
}
/*****************************************************************************/
//
// Function:  inputData(double &creditCardBalance, double &cardInterestRate,
//                      double &minimumPaymentPercent)
//
// Parameters: double &creditCardBalance  - the credit card balance
// (Inputs)    double &cardInterestRate   - the rate of interest on credit card
//             double &minimumPaymentPercent -minimum payment percentage
//
// Outputs:    none
//
// Returns:    none
//
// Author:     Praveen Manimaran
//
// Date:       8/3/2018
//
// Modifications: 8/3/2018
//
// Description: This function reads data from a file.
//
/*****************************************************************************/

void inputData(double &creditCardBalance, double &cardInterestRate,
               double &minimumPaymentPercent)
{
   ifstream inFile;
   string fileName, line;
   fileName = "/Users/praveenmanimaran/Desktop/lab6.txt"; //pathname

   inFile.open(fileName);//open file
   inFile >> creditCardBalance >> cardInterestRate >> minimumPaymentPercent;
   inFile.close(); //close file

}

/*****************************************************************************/
//
// Function:calcAmountOfInterest(double &monthInterest, double &totalInterest,
//                               double &minimumPayment,
//                               double &creditCardBalance,double &cardInterestRate,
//                               double &minimumPaymentPercent )
//
// Parameters: double creditCardBalance  - the credit card balance
// (Inputs)    double cardInterestRate   - the rate of interest on credit card
//             double minimumPaymentPercent -minimum payment percentage
//             double monthInterest      - the interest to be paid for that month
//             double totalInterest      - the total interest paid
//             double minimumPayment     - the minimum payment
//
//
// Outputs:    none
//
// Returns:    none
//
// Author:     Praveen Manimaran
//
// Date:       8/3/2018
//
// Modifications: 8/3/2018
//
// Description: This function calculate the amount of interest to be paid that month
//(adding this into balance before calculating minimum payment), total of interest
//paid, amount of minimum payment due for the month, and updating new balance.
//
/*****************************************************************************/
void calcAmountOfInterest(double &monthInterest, double &totalInterest,
                          double &minimumPayment,
                          double &creditCardBalance, double &cardInterestRate,
                          double &minimumPaymentPercent )
{
   //calculates the monthly interest
   monthInterest = creditCardBalance*((cardInterestRate/100)/12);
   //adds monthly interest to credit card balance
   creditCardBalance += monthInterest;
   //calculates the minimum payment
   minimumPayment = creditCardBalance *(minimumPaymentPercent/100);

   if(minimumPayment<15.00)
   {
      minimumPayment = 15;
   }

   //calculate the credit card balance
   creditCardBalance -= minimumPayment;
   totalInterest+=monthInterest;// add monthly interest to the total

}

/*****************************************************************************/
//
// Function:writeHeader(ofstream &outFile, double originalBalance,
//                      double cardInterestRate,double minimumPaymentPercent)
//
// Parameters: double originalBalance    - the first balance on credit card
// (Inputs)    ofstream outFile          - the ofstream
//             double minimumPaymentPercent -minimum payment percentage
//             double cardInterestRate   - the interest rate on card
//
//
// Outputs:    none
//
// Returns:    none
//
// Author:     Praveen Manimaran
//
// Date:       8/3/2018
//
// Modifications: 8/3/2018
//
// Description: This function writes the header to a file
//
/*****************************************************************************/
void writeHeader(ofstream &outFile, double originalBalance,
                 double cardInterestRate,double minimumPaymentPercent)
{
   //prints out necessary information for the header formatted
      outFile<<right<<setw(20)<<"";
      outFile<<"Balance Owing: $ "<<setprecision(2)<<fixed<<originalBalance<<endl;
      outFile<<right<<setw(20)<<"";
      outFile<<"APR as % " <<cardInterestRate<<endl;
      outFile<<right<<setw(20)<<"";
      outFile<<"Percent for minimum payment as % "<< minimumPaymentPercent<<endl;
      outFile<<right<<setw(15)<<"";
      outFile<<"------------------------------------------------------"<<endl;
      outFile<<right<<setw(10)<<"Month";
      outFile<<right<<setw(15)<<"Balance";
      outFile<<right<<setw(20)<<"Interest this";
      outFile<<right<<setw(15)<<"Minimum";
      outFile<<right<<setw(20)<<"Sum of interest"<<endl;
      outFile<<right<<setw(40)<<"month";
      outFile<<right<<setw(35)<<"paid"<<endl;
}

/*****************************************************************************/
//
// Function:writeOutput(ofstream &outFile,double creditCardBalance,
//                      int count,double monthInterest,double minimumPayment,
//                      double totalInterest &cardInterestRate,
//                      double &minimumPaymentPercent )
//
// Parameters: ofstream outFile          - the ofstream
//             int count                 - month number
//             double creditCardBalance  - the credit card balance
// (Inputs)    double cardInterestRate   - the rate of interest on credit card
//             double minimumPaymentPercent -minimum payment percentage
//             double monthInterest      - the interest to be paid for that month
//             double totalInterest      - the total interest paid
//             double minimumPayment     - the minimum payment
//
//
// Outputs:    none
//
// Returns:    none
//
// Author:     Praveen Manimaran
//
// Date:       8/3/2018
//
// Modifications: 8/3/2018
//
// Description: This function writes the credit card balance, montly interest,
//              minimum payment, total interest to a file.
/*****************************************************************************/
void writeOutput(ofstream &outFile,double creditCardBalance,
                 int count,double monthInterest,double minimumPayment,
                 double totalInterest)
{
   outFile<<right<<setw(10)<<count;
   if(creditCardBalance>0) //if there is money
   {
      outFile<<right<<setw(15)<<creditCardBalance;
   }
   else
   {
      outFile<<right<<setw(15)<<"0.00"; //no money in card
   }
   //prints out month interest, minimum payment, and total interest
   outFile<<right<<setw(20)<<monthInterest;
   outFile<<right<<setw(15)<<minimumPayment;
   outFile<<right<<setw(20)<<totalInterest<<endl;

   if(creditCardBalance<=0)
   {
      outFile.close(); //closes the file
   }

}




