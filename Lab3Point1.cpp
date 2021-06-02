/*
 Praveen Manimaran
 Summer 2019
 Lab 3
 Problem 3.1
 Description of problem: This program is similar to Lab 2, however it changes
 the function setUpCar to setUp,makes output function a member of class Car,
 changes the parameters of input function to 5 reference parameters, and in the
 main function it creates a Car object statically rather than dynamically in Lab
 2. It then prints out the content of the Car object.

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

   //prototypes
   void output(Car car1);
   Car setUp(Car car1, string &, int &, string &, bool &, string &);

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
void input(Car car1, string &, string &, string &, int &, bool &);


/*****************************************************************************/

int main()
{

   string reportingMark;  // string variable to store car member reportingMark
   string kind;           // string variable to store car member kind
   string destination;    // string variable to store car member destination
   int carNumber;      // int variable to store car member carNumber
   bool loaded;         // boolean variable to store car member loaded

   Car car1;
   input(car1, reportingMark, kind, destination, carNumber, loaded);
   car1 = car1.setUp(car1, reportingMark, carNumber, kind, loaded, destination);
   //cout<<"num "<<car1.getCarNumber()<<endl;
   car1.output(car1);

   return 0;
}

void Car::output(Car car1)
{
   cout<<endl<<"Reporting Mark: " << getReportingMark()<<endl;
   cout<<"Car Number: " << getCarNumber()<<endl;
   cout<<"Car Type: " << getKind()<<endl;
   if(getLoaded()==true)
   {
      cout<<"Is car loaded: true "<<endl;
   }
   else
   {
      cout<<"Is car loaded: false "<<endl;
   }

   cout<<"Destination: " << getDestination()<<endl;
}

// Class specific function
/* ******************** setUp ********************
 creates an object using a constructor that takes the reference parameters
 pointer to the object c1 returned.
 */
Car Car::setUp(Car car1, string &mark, int &num, string &make, bool &state, string &dest)
{
   car1 = Car(mark, num, make, state, dest);
   //cout<<"num "<<car1.getCarNumber()<<endl;
   return car1;

   //carOne(mark, num, make, state, dest);
   //Car *c1 = new Car(mark, num, make, state, dest);
  // return c1;
}; // end setUp




void input(Car car1, string &reportingMark, string &kind, string &destination,
           int &carNumber, bool &loaded)
{
   //setUpCar(string mark, int num, string make, bool state, string dest)
   string checkLoaded;

   cout<< "Enter Reporting Mark: ";
   cin >> reportingMark;
   cout<< "Enter Car Number: ";
   cin >> carNumber;
   cout<< "Enter what kind of car: ";
   cin >> kind;
   cout<< "Is the car loaded? (Enter true or false): ";
   cin >> checkLoaded;

   if(checkLoaded == "true")
   {
      loaded = true;
   }
   else if(checkLoaded == "false")
   {
      loaded = false;
   }
   if(loaded == true)
   {
      destination = "NONE";
      while(destination == "NONE")
      {
         cout<<"Enter destination: ";
         cin>> destination;
      }
   }
   else
   {
      cout<<"Enter destination: ";
      cin >> destination;
   }

}








