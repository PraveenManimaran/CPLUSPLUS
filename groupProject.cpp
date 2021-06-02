/*
Step 1: Write a program to ask the user for the number of entries, each is a number.
Step 2: Then input the numbers.
Step 3: Add code for summing the values.
Step 4: Add code for computing the average.
Step 5: Add code for outputting data to a file.
 */





#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
   int entries, sum, num;
   double average;

   cout<<"Enter the number of entries: ";
   cin>>entries;
   cout<<"Enter numbers";

   for(int i = 0; i<=entries; i++)
   {
      cin>>num;
      sum+=num;
   }
   average = static_cast<double>(sum)/entries;


   ofstream file_out;
   string fullname = "out_data.txt";
   file_out.open(fullname.c_str());

   if (!file_out.fail())
   {
      file_out << average;
      file_out.close();
      cout << "Writing to file completed!" << endl;
   }
   else
      cout << "File open failed. Program abort." << endl;

   return 0;
}




