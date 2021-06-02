/*
 Praveen Manimaran
 Summer 2019
 Lab 5
 Problem 5.2
 Description of Problem: This program changes the StringOfCars class so it has
 an array of pointers to objects, rather than an array of objects themselves.
 This will allow us to have a string of cars that contains Car, FreightCar,
 and PassengerCar objects all in the same string of cars. This works because a
 pointer of type Car * can be made to point to Car objects as well as point to
 the child FreightCar and PassengerCar objects.

 -----------------------------------------------------------------------------*/

//preprocessor directives
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

enum Kind {business, maintenance, other, box, tank, flat, otherFreight, chair,
   sleeper, otherPassenger };
const int NUMCARKIND = 10;
//define an array of const string objects named KIND ARRAY
const string KIND_ARRAY[NUMCARKIND] = {"business", "maintenance", "other", "box",
   "tank", "flat", "otherFreight", "chair","sleeper", "otherPassenger"};

/*****************************************************************************/

//Class Name: Car
class Car
{

protected:
   string reportingMark;  // string variable to store car member reportingMark
   Kind kind;           // string variable to store car member kind
   string destination;    // string variable to store car member destination
   int carNumber;      // int variable to store car member carNumber
   bool loaded;         // boolean variable to store car member loaded
public:
   //prototypes
   virtual void output(Car car1);
   virtual void setUp(string &, int &, string &, bool &, string &);
   Car& operator==(const Car & carB);

   // Constructors
   Car()
   {
      reportingMark = "";
      carNumber = 0;
      // kind = "other";
      loaded = false;
      destination = "NONE";
   }
   //Copy Constructor
   Car(const Car &obj)
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

   void setLoaded(bool state);
   void setDestination(string dest);

   // Accessor member function prototypes
   string getReportingMark() const;
   int getCarNumber() const;
   string getKind() const;
   bool getLoaded() const;
   string getDestination() const;


   friend bool operator==(Car& , Car& );
   virtual Car& operator=(const Car & carB);

   virtual void setKind(const string &knd);


};   // end class Car

/**************FREIGHT CAR CLASS DECLARATION*********************/
class FreightCar: public Car
{
public:

   // Constructors
   FreightCar()
   {
      reportingMark = "";
      carNumber = 0;
      // kind = "other";
      loaded = false;
      destination = "NONE";
   }
   //Copy Constructor
   FreightCar(const FreightCar &obj)
   {
      reportingMark = obj.reportingMark;
      carNumber = obj.carNumber;
      kind = obj.kind;
      loaded = obj.loaded;
      destination = obj.destination;
   }

   FreightCar(string &mark, int &num, string &make, bool &state, string &dest)
   {
      setUp(mark, num, make, state, dest);
   }

   // Destructor
   ~FreightCar()
   {
      //delete car
   };

   //prototypes
   void setKind( const string &knd);

}; //END OF FREIGHT CAR CLASS


/**************PASSENGER CAR CLASS DECLARATION*********************/
class PassengerCar: public Car
{
public:
   // Constructors
   PassengerCar()
   {
      reportingMark = "";
      carNumber = 0;
      // kind = "other";
      loaded = false;
      destination = "NONE";
   }
   //Copy Constructor
   PassengerCar(const PassengerCar &obj)
   {
      reportingMark = obj.reportingMark;
      carNumber = obj.carNumber;
      kind = obj.kind;
      loaded = obj.loaded;
      destination = obj.destination;
   }
   //constructor with 5 paramaters
   PassengerCar(string &mark, int &num, string &make, bool &state, string &dest)
   {
      setUp(mark, num, make, state, dest);
   }

   // Destructor
   ~PassengerCar()
   {
      //delete car
   };

   //prototypes
   void setKind(const string &knd);

}; //END OF PASSENGER CAR CLASS


/**************STRING OF CARS CLASS DECLARATION*********************/
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
   void push(const Car &car);
   Car pop();
   void output();

};
/*------------------------END OF STRINGOFCARS CLASS DECLARATION---------*/




//prototypes
void input(StringOfCars &string1);
Car buildCar(string reportingMark, int carNumber, string knd, bool loaded,
             string dest);
FreightCar buildFreightCar(string reportingMark, int carNumber, string knd,
                           bool loaded,string dest);
PassengerCar buildPassengerCar(string reportingMark, int carNumber, string knd,
                               bool loaded,string dest);


//main function to call input
int main()
{
   StringOfCars string1;
   input(string1);

  //string1.output();
   StringOfCars string2 = StringOfCars(string1);
   string2.output();

   return 0;
}

/********************* GLOBAL AREA - BUILD CARS **************************/
Car buildCar(string reportingMark, int carNumber, string kind, bool loaded,
             string destination, StringOfCars &string1)
{
   Car car1(reportingMark, carNumber, kind, loaded, destination);
   //car1.setKind(kind);
   //cout<<string1.
   string1.push(car1);
   //car1.output(car1);

   return car1;
}

FreightCar buildFreightCar(string reportingMark, int carNumber, string kind, bool loaded,
                           string destination, StringOfCars &string1)
{
   FreightCar freightCar1;
   freightCar1 = FreightCar(reportingMark, carNumber, kind, loaded, destination);
   string1.push(freightCar1);
   return freightCar1;
}

PassengerCar buildPassengerCar(string reportingMark, int carNumber, string kind, bool loaded,
                               string destination, StringOfCars &string1)
{
   PassengerCar passengerCar1;
   passengerCar1 = PassengerCar(reportingMark, carNumber, kind, loaded, destination);
   string1.push(passengerCar1);
   return passengerCar1;
}

/************************ END OF GLOBAL AREA *****************************/


void Car::setReportingMark(string mark)
{
   reportingMark = mark;
}

void Car::setCarNumber(int num)
{
   carNumber = num;
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
/*
 string Car::getKind() const
 {
 return kind;
 }
 */
bool Car::getLoaded() const
{
   return loaded;
}
string Car::getDestination() const
{
   return destination;
}
/*****************************************************************************/


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
}; // end setUp

//Car class' setKind function
void Car::setKind(const string &knd)
{
  // cout<<knd<<endl;

   if(knd.compare(KIND_ARRAY[business])==0)
   {
      kind = business;
   }
   else if(knd.compare(KIND_ARRAY[maintenance])==0)
   {
      kind = maintenance;
   }
   else
   {
      kind = other;
   }
}

//FreightCar class' setKind function
void FreightCar::setKind(const string &knd)
{

   if(knd.compare(KIND_ARRAY[box])==0)
   {
      kind = box;
   }
   else if(knd.compare(KIND_ARRAY[tank])==0)
   {
      kind = tank;
   }
   else if(knd.compare(KIND_ARRAY[flat])==0)
   {
      kind = flat;
   }
   else
   {
      kind = otherFreight;
   }

}


//PassengerCar class' setKind function
void PassengerCar::setKind(const string &knd)
{

   if(knd.compare(KIND_ARRAY[chair])==0)
   {
      kind = chair;
   }
   else if(knd.compare(KIND_ARRAY[sleeper])==0)
   {
      kind = sleeper;
   }
   else
   {
      kind = otherPassenger;
   }
}

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
//Class Name: Car, function output(Car car1)
void Car::output(Car car1)
{
   cout<<endl<<"Reporting Mark: " << car1.getReportingMark()<<endl;
   cout<<"Car Number: " << car1.getCarNumber()<<endl;
   cout<<"Car Type: " << KIND_ARRAY[kind] <<endl; //CHANGE TO KIND_ARRAY[ ]
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

//Class:StringOfCars
//Function which prints a heading for each car
void StringOfCars::output()
{
   for(int i = 0; i < size; i++)
   {
      (carPtr[i]).output(carPtr[i]);
   }

}


//A Push function which adds a car to the string of cars. It takes a Car by
//constant reference,  allocates space in the heap, makes a copy of the Car,
//and puts the pointer to the Car in the array.
void StringOfCars::push(const Car &car1)
{

   carPtr[size] = car1;
   size++;
}

//an output function which prints a heading for each car:
//car number n where n is the position in the array starting from 1
//for the first car and then uses the Car output function to print the
//data for each car Or, if the array is empty prints: NO cars

//pop function that removes a car from the string of cars, Last in First Out
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
   string knd;
   string destination;

   // Kind kind;
   string numOfCar;
   int carNumber;

   int count = 1;
   bool loaded;
   //setUpCar(string mark, int num, string make, bool state, string dest)
   string checkLoaded;
   fileName = "/Users/praveenmanimaran/Desktop/cardata5.txt";
   inputFile.open(fileName);
   if (!inputFile.fail())
   {
      while(inputFile.peek()!= EOF) //
      {

         inputFile>>type;
         inputFile>>numOfCar;
         inputFile>>reportingMark;
         inputFile>>carNumber;
         inputFile>>knd;

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

         //cout<<endl<<"Car Number "<<count<<endl;

         if(type.compare("Car")==0)
         {
            Car car1;
            car1 = buildCar(reportingMark, carNumber, knd, loaded, destination,
                            string1);
         }
         else if(type.compare("FreightCar")==0)
         {
            FreightCar freight1;
            freight1 = buildFreightCar(reportingMark, carNumber, knd, loaded,
                                       destination, string1);
         }
         else if (type.compare("PassengerCar")==0)
         {
            PassengerCar passenger1;
            passenger1 = buildPassengerCar(reportingMark, carNumber, knd, loaded,
                                           destination, string1);
         }
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


