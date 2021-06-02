/*
 Praveen Manimaran
 Summer 2019
 Lab 1
 Problem 0.0.0
 Description of problem:
 This program will ask the user if they want to encode/decode a message and will
 take the input from the user(if they dont enter no) and store it in dynamic
 memory. Using the rot13 function, the program will encode/decode and will then
 output the encoded/decoded message using the output function. The program will
 continue to run as long as the user does not enter no to terminate the program.
 -----------------------------------------------------------------------------*/

//preprocessor directives
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//prototypes
string inputData(string *userInput);
string rot13(string *input);
void outputResults(string rotatedString);
/*****************************************************************************/
int main()
{
   string entered;
   //repeats until user wants to terminate with no
   while(entered!="no")
   {
      //dynamic variable
      string *userInput = nullptr;
      userInput = new string;

      string rotatedString;
      cout<<"Would u like to encode or decode, enter no if you want to terminate"
      <<endl;
      getline(cin,entered);
      //checks if user typed in no to terminate
      if(entered == "no")
      {
         cout<<"Program Terminated"<<endl;
         exit(0);
      }
      *userInput = inputData(userInput);

      rotatedString = rot13(userInput);
      outputResults(rotatedString);
      //deletes the input string from dyanmic memory
      delete userInput;
      userInput  = nullptr;
   }

}

string inputData(string *userInput)
{
   string inputtedData;
   //prompt user to enter the string they want to encode/decode and store in
   //variable
   cout<<"Enter string you want to decode or encode: ";
   getline(cin, inputtedData);
   *userInput = inputtedData;
   return *userInput;

}

string rot13(string *userInput)
{
   string input = *userInput;

   //gets size of string
   int inputSize = input.size();
   int index = 0;

   //performs substituion by rotating each character by 13 ascii characters
   while(index != inputSize)
   {
      if(input[index] >= 97 && input[index] <= 109)
      {
         input[index] = input[index] + 13;
      }
      else if(input[index] >= 110 && input[index] <= 122)
      {
         input[index] = input[index] - 13;
      }
      else if(input[index] >= 65 && input[index] <= 77)
      {
         input[index] = input[index] + 13;
      }
      else if(input[index] >= 78 && input[index] <= 90)
      {
         input[index] = input[index] - 13;
      }
      index++;
   }

   return input;
}


void outputResults(string rotatedString)
{
   //outputs encrypted message
   cout<<"Encrypted Message: "<<rotatedString<<endl;
}















