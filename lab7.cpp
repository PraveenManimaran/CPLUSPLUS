/*****************************************************************************/
//  Filename:      lab7.cpp
//
//  Author:        Praveen Manimaran
//
//  Date:          8/7/2018
//
//  Modifications: Praveen Manimaran - 8/7/2018
//
//
//  Description: This program will redirect the input from the file HR.txt and
//               put each value into arrays. It calculate the weekly average of
//               the average(daily) commuting heart rates for each person,
//               number of days that the person exercised on his/her own and the stimated
//               maximum heart rate,ratio of max HR to estimated max HR, ratio of
//               highest heartrate to max heart rate using a for-loop. The program
//               will output the data onto another file
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
void getData(ifstream &inFile, int id[],double measMaxHr[], int age[],
             double dayAvgComHR[], double maxComHR[],double excHR[],
             double weeklyAverageCommHr[],int numDaysExercised[],
             double estimatedMaxHr[],double ratioMaxHrEstMaxHr[],
             double ratioHighHrMaxHr[], int size, int personNum);
void writeHeader(ofstream &outFile);
void writeOutput(ofstream &outFile, int id[], double weeklyAverageCommHr[],
                 int numDaysExercised[],double estimatedMaxHr[],
                 double ratioMaxHrEstMaxHr[],double ratioHighHrMaxHr[], int SIZE);
void selectionSort(int id[], double weeklyAverageCommHr[],
                   int numDaysExercised[],double estimatedMaxHr[],
                   double ratioMaxHrEstMaxHr[],double ratioHighHrMaxHr[], int SIZE);

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
// Date:       8/7/2018
//
// Modifications: 8/7/2018
//
// Description: Reads from a file and calls a method put values into arrays
//              accordingly. Calls methods to print out the data from arrays and
//              sort the id numbers.
//
/*****************************************************************************/
int main()
{
   const int SIZE = 40;
   ifstream inFile;
   string fileName;
   int personNum =0;

   ofstream outFile;
   outFile.open("output.txt");//file name

   //the arrays to store data of each person
   int id[SIZE];
   double measMaxHr[SIZE];
   int age[SIZE];
   double dayAvgComHR[SIZE];
   double maxComHR[SIZE];
   double excHR[SIZE];
   double weeklyAverageCommHr[SIZE];
   int numDaysExercised[SIZE];
   double estimatedMaxHr[SIZE];
   double ratioMaxHrEstMaxHr[SIZE];
   double ratioHighHrMaxHr[SIZE];


   fileName = "/Users/praveenmanimaran/Desktop/HR.txt"; //pathname

   inFile.open(fileName);//open file

   getData(inFile, id, measMaxHr, age, dayAvgComHR, maxComHR,excHR,
           weeklyAverageCommHr,numDaysExercised,estimatedMaxHr,
           ratioMaxHrEstMaxHr,ratioHighHrMaxHr, SIZE, personNum);

   writeHeader(outFile); //writes header

   //sorts the id #s
   selectionSort(id, weeklyAverageCommHr, numDaysExercised, estimatedMaxHr,
                 ratioMaxHrEstMaxHr,ratioHighHrMaxHr, SIZE);

   //writes the output to a file

   writeOutput(outFile, id, weeklyAverageCommHr, numDaysExercised, estimatedMaxHr,
               ratioMaxHrEstMaxHr,ratioHighHrMaxHr, SIZE);
   inFile.close(); //close inFile stream
   outFile.close(); //close outFile stream

   return 0;
}
/*****************************************************************************/
//
// Function:  writeHeader(ofstream &outFile)
//
// Parameters: ofstream &outFile - the out file stream
//
// Outputs:    the header
//
// Returns:    none
//
// Author:     Praveen Manimaran
//
// Date:       8/7/2018
//
// Modifications: 8/7/2018
//
// Description: This function prints out the header.
//
/*****************************************************************************/

void writeHeader(ofstream &outFile)
{
   //prints out the header formatted
   outFile<<setw(20)<<" ";
   outFile<<"COMMUTING AND EXERCISE HEART RATE SUMMARY"<<endl<<endl;

   outFile<<right<<setw(15)<<"Subject";
   outFile<<right<<setw(15)<<"Average";
   outFile<<right<<setw(15)<<"Days";
   outFile<<right<<setw(15)<<"Estimated";
   outFile<<right<<setw(15)<<"%Measured";
   outFile<<right<<setw(15)<<"%Max"<<endl;

   outFile<<right<<setw(15)<<"Number";
   outFile<<right<<setw(15)<<"Commuting";
   outFile<<right<<setw(15)<<"Excercised";
   outFile<<right<<setw(15)<<"Max Hr";
   outFile<<right<<setw(15)<<"To";
   outFile<<right<<setw(15)<<"Commuting"<<endl;

   outFile<<right<<setw(30)<<"HR";
   outFile<<right<<setw(45)<<"Estimated";
   outFile<<right<<setw(15)<<"HR To"<<endl;

   outFile<<right<<setw(75)<<"Max HR";
   outFile<<right<<setw(15)<<"Measured"<<endl;

}
/*****************************************************************************/
//
// Function:  selectionSort(int id[], double weeklyAverageCommHr[],
//                          int numDaysExercised[],double estimatedMaxHr[],
//                          double ratioMaxHrEstMaxHr[],double ratioHighHrMaxHr[]
//                          , int SIZE)
//
// Parameters: int id[] - the id numbers
//             double weeklyAverageCommHr[] - weekly average commute heartrate
//             int numDaysExercised[] - # of days excercised
//             double estimatedMaxHr[] - estimated max heartrate
//             double ratioMaxHrEstMaxHr[]- ratio max-heartrate to estimate max hr
//             double ratioHighHrMaxHr[] - ratio highest-heartrate to max hr
//             int SIZE - the size of each array(constant)
//
// Outputs:    none
//
// Returns:    none
//
// Author:     Praveen Manimaran
//
// Date:       8/7/2018
//
// Modifications: 8/7/2018
//
// Description: This function sorts the id numbers in order by using selection
//              sort.
//
/*****************************************************************************/

void selectionSort(int id[], double weeklyAverageCommHr[],
                   int numDaysExercised[],double estimatedMaxHr[],
                   double ratioMaxHrEstMaxHr[],double ratioHighHrMaxHr[], int SIZE)
{
   int seek;      //array position currently being put in order
   int minCount;  //location of smallest value found
   int minValue;  //holds the smallest value found
   double minValueWeeklyAverageCommHr;
   double minValueNumDaysExercised;
   double minValueEstimatedMaxHr;
   double minValueRatioMaxHrEstMaxHr;
   double minValueRatioHighHrMaxHr;

   for (seek = 0; seek < SIZE;seek++)  // outer loop performs the swap
                                            // and then increments seek
   {
      if(id[seek]!=0)
      {
         minCount = seek;
         minValue = id[seek];
         minValueWeeklyAverageCommHr = weeklyAverageCommHr[seek];
         minValueNumDaysExercised = numDaysExercised[seek];
         minValueEstimatedMaxHr = estimatedMaxHr[seek];
         minValueRatioMaxHrEstMaxHr = ratioMaxHrEstMaxHr[seek];
         minValueRatioHighHrMaxHr = ratioHighHrMaxHr[seek];
         for(int index = seek + 1; index < SIZE; index++)
         {
            if(id[seek]!=0)
            {
               if(id[index] < minValue)
               {
                  minValue = id[index];
                  minValueWeeklyAverageCommHr = weeklyAverageCommHr[index];
                  minValueNumDaysExercised = numDaysExercised[index];
                  minValueEstimatedMaxHr = estimatedMaxHr[index];
                  minValueRatioMaxHrEstMaxHr = ratioMaxHrEstMaxHr[index];
                  minValueRatioHighHrMaxHr = ratioHighHrMaxHr[index];
                  minCount = index;
               }
            }
         }

         // the following two statements exchange the value of the
         // element currently needing the smallest value found in the
         // pass(indicated by seek) with the smallest value found
         // (located in minValue)

         id[minCount] = id[seek];
         weeklyAverageCommHr[minCount] = weeklyAverageCommHr[seek];
         numDaysExercised[minCount] = numDaysExercised[seek];
         estimatedMaxHr[minCount] = estimatedMaxHr[seek];
         ratioMaxHrEstMaxHr[minCount] = ratioMaxHrEstMaxHr[seek];
         ratioHighHrMaxHr[minCount] = ratioHighHrMaxHr[seek];

         id[seek] = minValue;
         weeklyAverageCommHr[seek] = minValueWeeklyAverageCommHr;
         numDaysExercised[seek] = minValueNumDaysExercised;
         estimatedMaxHr[seek] = minValueEstimatedMaxHr;
         ratioMaxHrEstMaxHr[seek] = minValueRatioMaxHrEstMaxHr;
         ratioHighHrMaxHr[seek] = minValueRatioHighHrMaxHr;

      }

   }
}

/*****************************************************************************/
//
// Function:  writeOutput(ofstream &outFile, int id[], double weeklyAverageCommHr[],
//                        int numDaysExercised[],double estimatedMaxHr[],
//                        double ratioMaxHrEstMaxHr[],double ratioHighHrMaxHr[],
//                        int SIZE)
//
// Parameters: ofstream &outFile - the outfile stream
//             int id[] - the id numbers
//             double weeklyAverageCommHr[] - weekly average commute heartrate
//             int numDaysExercised[] - # of days excercised
//             double estimatedMaxHr[] - estimated max heartrate
//             double ratioMaxHrEstMaxHr[]- ratio max-heartrate to estimate max hr
//             double ratioHighHrMaxHr[] - ratio highest-heartrate to max hr
//             int SIZE - the size of each array(constant)
//
// Outputs:    the id #, weekly average commute HR, days excercised,
//             estimated max HR, ratio of max HR to estimated max HR, ratio of
//             highest heartrate to max heart rate.
//
// Returns:    none
//
// Author:     Praveen Manimaran
//
// Date:       8/7/2018
//
// Modifications: 8/7/2018
//
// Description: This function prints out he id #, weekly average commute HR, days excercised,
//             estimated max HR, ratio of max HR to estimated max HR, ratio of
//             highest heartrate to max heart rate using a for-loop.
//
/*****************************************************************************/

void writeOutput(ofstream &outFile, int id[], double weeklyAverageCommHr[],
                 int numDaysExercised[],double estimatedMaxHr[],
                 double ratioMaxHrEstMaxHr[],double ratioHighHrMaxHr[], int SIZE)
{
   for(int i = 0; i<SIZE; i++)
   {
      if(id[i]!=0)
      {
         outFile<<right<<setw(15)<<id[i];
         outFile<<right<<setw(15)<<setprecision(2)<<fixed<<weeklyAverageCommHr[i];
         outFile<<right<<setw(15)<<numDaysExercised[i];
         outFile<<right<<setw(15)<<setprecision(2)<<fixed<<estimatedMaxHr[i];
         outFile<<right<<setw(15)<<setprecision(2)<<fixed<<ratioMaxHrEstMaxHr[i];
         outFile<<right<<setw(15)<<setprecision(2)<<fixed<<ratioHighHrMaxHr[i]<<endl;
      }
   }

}

/*****************************************************************************/
//
// Function:  getData(ifstream &inFile, int id[],double measMaxHr[], int age[],
//                    double dayAvgComHR[], double maxComHR[],double excHR[],
//                    double weeklyAverageCommHr[],int numDaysExercised[],
//                    double estimatedMaxHr[],double ratioMaxHrEstMaxHr[],
//                    double ratioHighHrMaxHr[], int size, int personNum)
//
// Parameters: ifstream &inFile - the infile stream
//             int id[] - the id numbers
//             double measMaxHr[] - the measured max heartrate
//             int age[] - the age
//             double dayAvgComHR[]- daily average commute heartrate
//             double maxComHR[]- max commute heartrate
//             double excHR[]- excercise heartrate
//             double weeklyAverageCommHr[] - weekly average commute heartrate
//             int numDaysExercised[] - # of days excercised
//             double estimatedMaxHr[] - estimated max heartrate
//             double ratioMaxHrEstMaxHr[]- ratio max-heartrate to estimate max hr
//             double ratioHighHrMaxHr[] - ratio highest-heartrate to max hr
//             int SIZE - the size of each array(constant)'
//             int personNum- the subject number
//
// Outputs:    none
//
// Returns:    none
//
// Author:     Praveen Manimaran
//
// Date:       8/7/2018
//
// Modifications: 8/7/2018
//
// Description: This function uses a while loop to read a file to put data into
//              specific arrays accordingly. This function also calculates the
//              number of days excercised, weekly average commute HR, and highest
//              commute HR, the ratio of max HR to estimated max HR, ratio of
//              highest heartrate to max heart rate.
//
/*****************************************************************************/

void getData(ifstream &inFile, int id[],double measMaxHr[], int age[],
             double dayAvgComHR[], double maxComHR[],double excHR[],
             double weeklyAverageCommHr[],int numDaysExercised[],
             double estimatedMaxHr[],double ratioMaxHrEstMaxHr[],
             double ratioHighHrMaxHr[], int SIZE, int personNum)
{
   while(!inFile.eof()) //until file is over
   {
      double totalComHr = 0;
      int daysExcercised = 0;
      int highestComHr = 0;
      int temp = 0;

      //reads first line
      inFile>>id[personNum];
      inFile>>measMaxHr[personNum];
      inFile>>age[personNum];
      estimatedMaxHr[personNum] = 220-age[personNum];

      //for loop to read data for each of five days
      for(int day = 0; day<5; day++)
      {
         inFile>>dayAvgComHR[day];
         inFile>>maxComHR[day];
         inFile>>excHR[day];
      }
      for(int i =0; i<5; i++)
      {
         if(dayAvgComHR[i]>=0)
         {
            totalComHr += dayAvgComHR[i];
         }

         if(excHR[i]!=0)
         {
            daysExcercised++;
         }
         if(maxComHR[i]>=0 && maxComHR[i]>temp)
         {
            temp=maxComHR[i];
         }
      }

      //calculates things to be outputted
      numDaysExercised[personNum] = daysExcercised;
      weeklyAverageCommHr[personNum] = totalComHr/5;
      highestComHr = temp;
      ratioMaxHrEstMaxHr[personNum] = (measMaxHr[personNum]/
                                       estimatedMaxHr[personNum])*100;
      ratioHighHrMaxHr[personNum] = (highestComHr/measMaxHr[personNum])*100;
      personNum++; //increase the subject count
   }
}

