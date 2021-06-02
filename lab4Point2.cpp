/*
 Praveen Manimaran
 Summer 2019
 Lab 4
 Problem 4.2
 Description of problem: This program creates another class called StringOfCars
 which creates an array of pointers to car objects. It has a push and pop function
 that adds and removes a car from the string of cars. It has an output function
 that prints a heading for each car. This program will perform 3 tests.
 -----------------------------------------------------------------------------*/

//preprocessor directives
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;



/*****************************************************************************/

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
   Car& operator==(const Car & carB);

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
   Car& operator=(const Car & carB);



};   // end class Car

class StringOfCars
{
protected:
   Car* carPtr; //array of pointers to objects
   static const int ARRAY_MAX_SIZE = 10;
   int size;
public:
   StringOfCars();
   StringOfCars(const StringOfCars &obj);
   ~StringOfCars()
   {
      delete []carPtr;
   };
   //prototypes
   void push(Car &car);
   Car pop();
   void output2();

};
/*------------------------END OF STRINGOFCARS CLASS DECLARATION---------*/

//prototypes
void input(StringOfCars &car);
//main function to call input
int main()
{
   string reportingMark = "SP";  // string variable to store car member reportingMark
   string kind = "box";           // string variable to store car member kind
   string destination = "Salt Lake City";    // string variable to store car member destination
   int carNumber = 34567;      // int variable to store car member carNumber
   bool loaded = true;         // boolean variable to store car member loaded


   //TEST 1
   cout<<"TEST 1"<<endl;
   Car car1;
   car1 = Car(reportingMark, carNumber, kind, loaded, destination);
   Car car2;
   car2 = Car(car1);
   car2.output(car2);


   //TEST 2
   StringOfCars string1;
   cout<<"TEST 2"<<endl;
   input(string1);
   cout<<"STRING 1 "<<endl<<endl;
   string1.output2();

   //Test3
   cout <<endl<< "TEST 3 " << endl;
   Car car3;
   car3 = string1.pop();
   car3.output(car3);
   cout << "STRING 1" << endl;
   string1.output2();

   return 0;
}

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
   cout<<endl<<"Reporting Mark: " << car1.getReportingMark()<<endl;
   cout<<"Car Number: " << car1.getCarNumber()<<endl;
   cout<<"Car Type: " << car1.getKind()<<endl;
   if(car1.getLoaded()==true)
   {
      cout<<"Is car loaded: true "<<endl;
   }
   else
   {
      cout<<"Is car loaded: false "<<endl;
   }

   cout<<"Destination: " << car1.getDestination()<<endl;
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

// Car  operator=  **************************************************
Car & Car::operator=(const Car & carB)
{
   reportingMark = carB.reportingMark;
   carNumber     = carB.carNumber;
   kind          = carB.kind;
   loaded        = carB.loaded;
   destination   = carB.destination;

   return * this;
}


//DEFAULT CONSTRUCTOR which gets space for the array in heap,sets size to 0
StringOfCars::StringOfCars()
{
   size = 0;
   carPtr = new Car[ARRAY_MAX_SIZE];
}

//COPY CONSTRUCTOR which gets space for the array in heap and copies all
//car objects
StringOfCars::StringOfCars(const StringOfCars &obj)
{
   carPtr = new Car[ARRAY_MAX_SIZE];
   size = obj.size;
   for(int i = 0; i< ARRAY_MAX_SIZE; i++)
   {
      carPtr[i] = obj.carPtr[i];
   }
}
//Class:StringOfCars
//Function which prints a heading for each car:
//car number n where n is the position in the array starting from 1
//for the first car and then uses the Car output function to print the
//data for each car Or, if the array is empty prints: NO cars
void StringOfCars::output2()
{
   if(size==0)
   {
      cout<<"NO CARS "<<endl;
   }
   else
   {
      for(int n = 0; n<size;n++)
      {
         cout<<"CAR #"<<n+1<<endl;
         carPtr[n].output(carPtr[n]);
      }
   }

}


//push function which adds a car to the string of cars
void StringOfCars::push(Car &car1)
{
   carPtr[size] = car1;
   size++;
}

//an output function which prints a heading for each car:
//car number n where n is the position in the array starting from 1
//for the first car and then uses the Car output function to print the
//data for each car Or, if the array is empty prints: NO cars

//pop function thata removes a car from the string of cars, Last in First Out
Car StringOfCars::pop()
{
   return carPtr[--size];
}

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
void input(StringOfCars &string1)
{

   ifstream inputFile;
   string fileName, line;
   string type;
   string reportingMark;
   string kind;
   string destination;
   int carNumber;

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
         string1.push(temp);
      }

   }
   else
   {
      cerr << "File open failed. Program abort." << endl;
      exit(0);
   }
   inputFile.close(); // close file

}


