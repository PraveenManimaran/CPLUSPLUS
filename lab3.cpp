/*****************************************************************************/
//  Filename:      lab3.cpp
//
//  Author:        Praveen Manimaran
//
//  Date:          7/18/2018
//
//  Modifications: Praveen Manimaran - 7/18/2018
//
//
//  Description:   This program creates a customer bill by prompting the user
//                 for the quantity of each product sold.
//
/*****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// use macro to define a constant for the TAX_RATE
#define TAX_RATE 0.0875

int main()
{
   // define all the variables first
   const double TV = 500.00;
   const double DVD_PLAYER = 380.00;
   const double REMOTE_CONTROLLER = 35.20;
   const double CD_PLAYER = 74.50;
   const double AUDIO_VISUAL_PROCESSOR = 1500.0;

   int numTVs, numDVDs, numRemoteControllers, numCDPlayers, numAVPs;
   string month;
   double totalTVs, totalDVDs,totalRemoteControllers,totalCDPlayers, totalAVPs;
   double subtotal ,tax, total;


   //Prompts user to get number of items sold for each product
   cout<<"How many TVs were sold? ";
   cin>>numTVs;

   cout<<"How many DVD players were sold? ";
   cin>>numDVDs;

   cout<<"How many Remote Controller units were sold? ";
   cin>>numRemoteControllers;

   cout<<"How many CD players were sold? ";
   cin>>numCDPlayers;

   cout<<"How many AV Processors were sold? ";
   cin>>numAVPs;
   cout<<"\n\n\n";

   cout<<left<<setw(10)<<"QTY";
   cout<<left<<setw(20)<<"Description";
   cout<<right<<setw(10)<<"Unit Price";
   cout<<right<<setw(15)<<"Total Price"<<endl;

   //if-statements check if the sale is 0 unit for a product so that it doesn't
   //print any sales data for that product.
   if(numTVs>0)
   {
      //prints out quantity, item name, price of item, and total price of item
      cout<<left<<setw(10)<<numTVs;
      cout<<left<<setw(20)<<"TV";
      cout<<right<<setw(10)<<setprecision(2) << fixed << TV;
      totalTVs = numTVs*TV;
      cout<<right<<setw(15)<<setprecision(2)<<fixed<<totalTVs<<endl;
   }

   if(numDVDs>0)
   {
      //prints out quantity, item name, price of item, and total price of item
      cout<<left<<setw(10)<<numDVDs;
      cout<<left<<setw(20)<<"DVD_PLAYER";
      cout<<right<<setw(10)<<setprecision(2) << fixed << DVD_PLAYER;
      totalDVDs = numDVDs*DVD_PLAYER;
      cout<<right<<setw(15)<<setprecision(2)<<fixed<<totalDVDs<<endl;
   }

   if(numRemoteControllers>0)
   {
       //prints out quantity, item name, price of item, and total price of item
      cout<<left<<setw(10)<<numRemoteControllers;
      cout<<left<<setw(20)<<"Remote Controller";
      cout<<right<<setw(10)<<setprecision(2) << fixed<<REMOTE_CONTROLLER;
      totalRemoteControllers = numRemoteControllers*REMOTE_CONTROLLER;
      cout<<right<<setw(15)<<setprecision(2)<<fixed<<totalRemoteControllers
          <<endl;
   }

   if(numCDPlayers>0)
   {
      //prints out quantity, item name, price of item, and total price of item
      cout<<left<<setw(10)<<numCDPlayers;
      cout<<left<<setw(20)<<"CD Player";
      cout<<right<<setw(10)<<setprecision(2) << fixed<<CD_PLAYER;
      totalCDPlayers = numCDPlayers*CD_PLAYER;
      cout<<right<<setw(15)<<setprecision(2)<<fixed<<totalCDPlayers<<endl;
   }
   if(numAVPs>0)
   {
      //prints out quantity, item name, price of item, and total price of item
      cout<<left<<setw(10)<<numAVPs;
      cout<<left<<setw(20)<<"AV Processor";
      cout<<right<<setw(10)<<setprecision(2) << fixed<<AUDIO_VISUAL_PROCESSOR;
      totalAVPs = numAVPs*AUDIO_VISUAL_PROCESSOR;
      cout<<right<<setw(15)<<setprecision(2)<<fixed<<totalAVPs<<endl;
   }

   cout<<"\n\n";

   //calculate the subtotal, tax, and the total price
   subtotal=totalDVDs+totalCDPlayers+totalRemoteControllers+totalDVDs+totalAVPs;
   tax = TAX_RATE*subtotal;
   total = subtotal+tax;

   //prints out subtotal
   cout<<right<<setw(30)<<"";
   cout<<left<<setw(10)<<"Subtotal";
   cout<<right<<setw(10)<<setprecision(2)<<fixed<<subtotal<<endl;

   //prints out tax
   cout<<right<<setw(30)<<"";
   cout<<left<<setw(10)<<"Tax";
   cout<<right<<setw(10)<<setprecision(2)<<fixed<<tax<<endl;

   //prints out total
   cout<<right<<setw(30)<<"";
   cout<<left<<setw(10)<<"Total";
   cout<<right<<setw(10)<<setprecision(2)<<fixed<<total<<endl<<endl;

}

/*------------------------paste of run-------------------------------
Test Data set: 13, 2, 3, 1, 21
How many TVs were sold? 13
How many DVD players were sold? 2
How many Remote Controller units were sold? 3
How many CD players were sold? 1
How many AV Processors were sold? 21


QTY       Description         Unit Price    Total Price
13        TV                      500.00        6500.00
2         DVD_PLAYER              380.00         760.00
3         Remote Controller        35.20         105.60
1         CD Player                74.50          74.50
21        AV Processor           1500.00       31500.00


                              Subtotal    33200.10
                              Tax          2905.01
                              Total       36105.11

Program ended with exit code: 0
--------------------------------------------------------------------
Test Data set: 0, 2, 0, 1, 0
 How many TVs were sold? 0
 How many DVD players were sold? 2
 How many Remote Controller units were sold? 0
 How many CD players were sold? 1
 How many AV Processors were sold? 0


 QTY       Description         Unit Price    Total Price
 2         DVD_PLAYER              380.00         760.00
 1         CD Player                74.50          74.50


                               Subtotal    1594.50
                               Tax          139.52
                               Total       1734.02

 Program ended with exit code: 0

 --------------------------------------------------------------------*/
