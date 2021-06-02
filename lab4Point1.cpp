/*
 Praveen Manimaran
 Summer 2019
 Lab 4
 Problem 4.1
 Description of problem: In this problem, we will read cars from a file, rather
 than typing them in from the keyboard. It consists of an input function that
 reads from cardata.txt and inputs the data according to the listed 3 different
 cars in the file.
 -----------------------------------------------------------------------------*/

//preprocessor directives
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;


//prototypes
void input();
//friend void checkEquals();

/*****************************************************************************/

//main function to call input
int main()
{
   input();

   return 0;
}


//Class Name: Car
class Car
{

private:
   string reportingMark;  // string variable to store car member reportingMark
   string kind;           // string variable to store car member kind
   string destination;    // string variable to store car member destination
   int carNumber;      // int variable to store car member carNumber
   bool loaded;         // boolean variable to store car member loaded
public:
   //prototypes
   void output(Car car1);
   void setUp(string &, int &, string &, bool &, string &);

   // Constructors
   Car()
   {
      reportingMark = "";
      carNumber = 0;
      kind = "other";
      loaded = false;
      destination = "NONE";
   }
   //Copy Constructor
   Car(Car &obj)
   {
      reportingMark = obj.reportingMark;
      carNumber = obj.carNumber;
      kind = obj.kind;
      loaded = obj.loaded;
      destination = obj.destination;
   }

   Car(string &mark, int &num, string &make, bool &state, string &dest)
   {
      setUp(mark, num, make, state, dest);
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


   friend bool operator==(Car& , Car& );

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
/*****************************************************************************/


//Class Name: Car, function output(Car car1)
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
void Car::setUp(string &mark, int &num, string &make, bool &state, string &dest)
{
   setReportingMark(mark);
   setCarNumber(num);
   setKind(make);
   setLoaded(state);
   setDestination(dest);
   //car1 = Car(mark, num, make, state, dest);
   //cout<<"num "<<car1.getCarNumber()<<endl;
   //return car1;

   //carOne(mark, num, make, state, dest);
   //Car *c1 = new Car(mark, num, make, state, dest);
   // return c1;
}; // end setUp

bool operator==(Car &car1, Car &car2)
{
   //bool isEqual = false;
   if((car1.getCarNumber()==car2.getCarNumber()) &&
      (car1.getReportingMark()==car2.getReportingMark()))
   {
      return true;
   }
   else
   {
      return false;
   }
}

//input function to read into file and calls output to print out the data
void input()
{

   ifstream inputFile;
   string fileName, line;
   string type;
   string reportingMark;
   string kind;
   string destination;
   int carNumber;
   int count = 1;
   bool loaded;
   //setUpCar(string mark, int num, string make, bool state, string dest)
   string checkLoaded;
   fileName = "/Users/praveenmanimaran/Desktop/cardata.txt";
   inputFile.open(fileName);
   if (!inputFile.fail())
   {
      while(inputFile.peek()!= EOF) //
      {

         inputFile>>type;
         inputFile>>reportingMark;
         inputFile>>carNumber;
         inputFile>>kind;
         inputFile>>checkLoaded;

         if(checkLoaded == "true")
         {
            loaded = true;
         }
         else if(checkLoaded == "false")
         {
            loaded = false;
         }

         while(inputFile.peek() == ' ')
         {
            inputFile.get();

         }
         getline(inputFile, destination);

         Car temp;
         temp = Car(reportingMark, carNumber, kind, loaded, destination);
         temp.output(temp);
         count++;

      }

   }
   else
   {
      cerr << "File open failed. Program abort." << endl;
      exit(0);
   }
   inputFile.close(); // close file

}
















