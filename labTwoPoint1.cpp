/*
 Praveen Manimaran
 Summer 2019
 Lab 2
 Problem 2.1
 Description of problem:
 This program will ask the user to input the reporting mark, type of car, the
 destination, if the the car is loaded, and the car number. However, this program
 uses a struct called Car. The program then uses the output function
 to print out the reporting mark, type of car, the destination, if the the car
 is loaded, and the car number.
 -----------------------------------------------------------------------------*/

//preprocessor directives
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//structure declaration
struct Car
{
   string reportingMark;
   int carNumber;
   string kind;
   bool loaded;
   string destination;
};

//prototypes
void input(Car *cPtr);
void output(Car *cPtr);
/*****************************************************************************/

int main()
{
   Car *cPtr;
   cPtr = new Car;

   input(cPtr);
   output(cPtr);

   delete cPtr;
   cPtr = nullptr;

   return 0;
}

void input(Car *cPtr)
{
   string checkLoaded;

   cout<< "Enter Reporting Mark: ";
   cin >> (*cPtr).reportingMark;
   cout<< "Enter Car Number: ";
   cin >> (*cPtr).carNumber;
   cout<< "Enter what kind of car: ";
   cin >> (*cPtr).kind;
   cout<< "Is the car loaded? (Enter true or false): ";
   cin >> checkLoaded;

   if(checkLoaded == "true")
   {
      (*cPtr).loaded = true;
   }
   else if(checkLoaded == "false")
   {
      (*cPtr).loaded = false;
   }
   if((*cPtr).loaded == true)
   {
      (*cPtr).destination = "NONE";
      while((*cPtr).destination == "NONE")
      {
         cout<<"Enter destination: ";
         cin>> (*cPtr).destination;
      }
   }
   else
   {
      cout<<"Enter destination: ";
      cin>> (*cPtr).destination;
   }

}
void output(Car *cPtr)
{
   cout<<endl<<"Reporting Mark: " << (*cPtr).reportingMark<<endl;
   cout<<"Car Number: " << (*cPtr).carNumber<<endl;
   cout<<"Car Type: " << (*cPtr).kind<<endl;
   if((*cPtr).loaded==true)
   {
      cout<<"Is car loaded: true "<<endl;
   }
   else
   {
      cout<<"Is car loaded: false "<<endl;
   }
   cout<<"Destination: " << (*cPtr).destination<<endl;

}
