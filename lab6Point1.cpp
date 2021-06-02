/*
 Praveen Manimaran
 Summer 2019
 Lab 6
 Problem 6.1
 Description of Problem: This implementation will use a linked list, rather than
 an array or vector to hold the cars. A new class called Node is created and a
 linked list using Node objects, linked together to make a list is built.
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
   void output();
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


class StringOfCars; //StringOfCars class declaration

/***********************NODE CLASS DECLARATION***************************/
class Node
{
private:
   Node* next;
   Car* data;
   Node()
   {
      next = nullptr;
      data = nullptr;
   }
public:
   friend class StringOfCars;

};
/********************END OF NODE CLASS DECLARATION***********************/


/**************STRING OF CARS CLASS DECLARATION*********************/
class StringOfCars
{
private:
   Node* head;
   Node* tail;
public:
   StringOfCars();
   StringOfCars(const StringOfCars &obj);
   ~StringOfCars()
   {
      //delete []carPtr;
   };
   //prototypes
   void push(const Car &car);
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
   head = nullptr;
   tail = nullptr;
}


//COPY CONSTRUCTOR which gets space for the array in heap and copies all
//car objects
StringOfCars::StringOfCars(const StringOfCars &obj)
{
   Node * currentNodePtr = obj.head;

   tail = nullptr;
   head = nullptr;


   if (obj.head != nullptr)
   {
      while (currentNodePtr != nullptr)
      {
         push(*currentNodePtr->data);
         currentNodePtr = (*currentNodePtr).next;
      }
   }
}


//A Push function which adds a car to the string of cars. It takes a Car by
//constant reference,  allocates space in the heap, makes a copy of the Car,
//and puts the pointer to the Car in the array.
void StringOfCars::push(const Car &car1)
{

   Car* currentCarPtr;
   currentCarPtr= new Car(car1);
   Node* currentNodePtr;
   currentNodePtr = new Node;

   (*currentNodePtr).data = currentCarPtr;

   if (head == nullptr)
   {
      head = currentNodePtr;
      tail = currentNodePtr;
   }
   else
   {
      (*tail).next = currentNodePtr;
      tail = currentNodePtr;
   }
   /*
    carPtr[size] = car1;
    size++;
    */
}


//Class Name: Car, function output(Car car1)
void Car::output()
{
   cout<<endl<<"Reporting Mark: " << reportingMark<<endl;
   cout<<"Car Number: " << carNumber <<endl;
   cout<<"Car Type: " << KIND_ARRAY[kind] <<endl; //CHANGE TO KIND_ARRAY[ ]
   if(loaded==true)
   {
      cout<<"Is car loaded: true "<<endl;
   }
   else
   {
      cout<<"Is car loaded: false "<<endl;
   }

   cout<<"Destination: " << destination <<endl;
}

//Class:StringOfCars
//Function which prints a heading for each car
void StringOfCars::output()
{
   Node* currentNodePtr;
   if(head == nullptr)
   {
      cout<<"NO cars "<<endl;
   }
   else
   {
      int count = 1;
      currentNodePtr = head;

      while(currentNodePtr!=nullptr)
      {
         cout << endl<< "Car Number: " << count << endl;
         count++;

         (*currentNodePtr->data).output();
         currentNodePtr = (*currentNodePtr).next;
      }
   }
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
   fileName = "/Users/praveenmanimaran/Desktop/cardata61.txt";
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



