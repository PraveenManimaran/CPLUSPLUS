/*
 Praveen Manimaran
 Summer 2019
 Lab 2
 Problem 2.2
 Description of problem:
 This program will ask the user to input the reporting mark, type of car, the
 destination, if the the car is loaded, and the car number. However, this program
 uses a class called Car which uses an input function to only read the data from
 the user, and then it will call an additional function named setUpCar which
 will put the data into the object. The program then uses the output function
 to print out the reporting mark, type of car, the destination, if the the car
 is loaded, and the car number.
 -----------------------------------------------------------------------------*/

//preprocessor directives
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class Car
{
private:
   string reportingMark;  // string variable to store car member reportingMark
   string kind;           // string variable to store car member kind
   string destination;    // string variable to store car member destination
   int carNumber;      // int variable to store car member carNumber
   bool loaded;         // boolean variable to store car member loaded
public:
   // Constructors
   Car()
   {
      reportingMark = "None";
      carNumber = 0;
      kind = "None";
      loaded = false;
      destination = "None";
   }

   Car(string mark, int num, string make, bool state, string dest)
   {
      reportingMark = mark;
      carNumber = num;
      kind = make;
      loaded = state;
      destination = dest;
   }

   // Destructor
   ~Car()
   {
      //delete car
   };
   // Mutator member function prototypes
   void setReportingMark(string mark);
   void setCarNumber(int num);
   void setKind(string make);
   void setLoaded(bool state);
   void setDestination(string dest);

   // Accessor member function prototypes
   string getReportingMark() const;
   int getCarNumber() const;
   string getKind() const;
   bool getLoaded() const;
   string getDestination() const;


   // Class specific function
   /* ******************** setUpCar ********************
    creates an object using a constructor that takes the reference parameters
    pointer to the object c1 returned.
    */
   Car* setUpCar(string mark, int num, string make, bool state, string dest)
   {
      Car *c1 = new Car(mark, num, make, state, dest);
      return c1;
   }; // end setUpCar
};   // end class Car
void Car::setReportingMark(string mark)
{
   reportingMark = mark;
}

void Car::setCarNumber(int num)
{
   carNumber = num;
}
void Car::setKind(string make)
{
   kind = make;
}
void Car::setLoaded(bool state)
{
   loaded = state;
}
void Car::setDestination(string dest)
{
   destination = dest;
}

//Accessor functions
string Car::getReportingMark() const
{
   return reportingMark;
}
int Car::getCarNumber() const
{
   return carNumber;
}
string Car::getKind() const
{
   return kind;
}
bool Car::getLoaded() const
{
   return loaded;
}
string Car::getDestination() const
{
   return destination;
}
//prototypes
Car* input(Car *car1);
void output(Car *car1);
/*****************************************************************************/

int main()
{

   Car *car1 = new Car;
   car1 = input(car1);
   output(car1);

   return 0;
}

Car* input(Car *car1)
{
   //setUpCar(string mark, int num, string make, bool state, string dest)
   string checkLoaded;
   string mark;
   int num;
   string make;
   bool state = false;
   string dest;

   cout<< "Enter Reporting Mark: ";
   cin >> mark;
   cout<< "Enter Car Number: ";
   cin >> num;
   cout<< "Enter what kind of car: ";
   cin >> make;
   cout<< "Is the car loaded? (Enter true or false): ";
   cin >> checkLoaded;

   if(checkLoaded == "true")
   {
      state = true;
   }
   else if(checkLoaded == "false")
   {
      state = false;
   }
   if(state == true)
   {
      dest = "NONE";
      while(dest == "NONE")
      {
         cout<<"Enter destination: ";
         cin>> dest;
      }
   }
   else
   {
      cout<<"Enter destination: ";
      cin >> dest;
   }

   car1 = car1->setUpCar(mark, num, make, state, dest);
   return car1;

}

 void output(Car *car1)
 {
    cout<<endl<<"Reporting Mark: " << car1->getReportingMark()<<endl;
    cout<<"Car Number: " << car1->getCarNumber()<<endl;
    cout<<"Car Type: " << car1->getKind()<<endl;
    if(car1->getLoaded()==true)
    {
       cout<<"Is car loaded: true "<<endl;
    }
    else
    {
       cout<<"Is car loaded: false "<<endl;
    }

    cout<<"Destination: " << car1->getDestination()<<endl;
 }





