#include "OOP.h"
//Object oriented programming

/*basic principles :
* Abstraction: method of hiding unwanted implemetnation details and shows only relevant interface
* achieved using abstract classes, interfaces (pure virtual functions) 
* hides complexity
* Encapsultion: is about binding data and methods into single unit and restricting direct access to inner workings.
* Achieved using classes,access specifiers: private , protected and public
* hides data
* Inheritance: create relationship between classes, can create hierarchy. Behaviour and implementation is inherited 
* by child classes from parent classes.
* usability and extendibility.
* has-a and part -of relationship.
* promotes re-use of oject.
* polymorphism: meanss different forms, common behaviour with differenct implementations.
* function overload,templates &virtual functions.
*/

/*
* class:
can have multiple instances.
this pointer: hidden pointer passed to member function. 
This pointer contains address of object on which member function is called, allowing access to all the objects members.
compiler internally uses this pointer.
this->speed++;
this->Accelerate();
Static member invoked directly through class name or object name. buut better use class name.
*/

/* Static class members:
* not part of object but part of class. this copy shared by all objects of class.
* declared inside but initialized outside. 
* if not initialized the compiler will initialize it with 0.
* does not have this pointer so cant access object members by this
* static methods have no access to this, But they can access non-static members through an 
object passed as a parameter or created inside the function
*/

/*Const member functions
const keyword,
declarion and defination
used fro creating read only member functions.
cannot change value of any member variables.
constant objects can invoke only constant member function.
const is applied to this pointer. * this in the const function
make read only functions const

*/

/*
Copy constructor
copy values of member var in other object
default copy constructor by compiler simply copy values
*/

/*Rule of 3
If you are implementing any of these 3 , then you should implement all of these:
1.Destructor
2.Copy constructor
3.Copy Assignment operator
Otherwise there will be memory leak or shallow copy.
*/

/* Delegating constructors should be used for default and parameterized constructor to avoid duplication code
* dont use for copy and assignment constructor.It may lead to shallow copy bugs, it requires deep copy management.
*/
#include "OOP.h"
using namespace std;

int Car::totalCount = 0;
int Car::totalCountTest = 1;


//:Car(0) is part of definition only
Car::Car():Car(0) {
	cout << "Default Constructor called" << endl;
	//Used Delegating constructor to avoid repeat code in multiple constructors. Calls Car(float amount) before executing this
	/*++totalCount;
	fuel = 0;
	speed = 0;
	passengers = 0;*/
}

Car::Car(float amount):Car(amount,0) {
	cout << "Parameterized Constructor called" << endl;
	//Calls Car(float amount, int pass) before executing this.
	/*++totalCount;
	fuel = amount;
	speed = 0;
	passengers = 0;*/
}

Car::Car(float amount, int pass)
{
	cout << "Parameterized Constructor 2 called" << endl;
	++totalCount;
	fuel = amount;
	speed = 0;
	passengers = pass;
}

Car::Car(const Car& obj)
{
	cout << "Copy Constructor called" << endl;
	fuel = obj.fuel;
	speed = obj.speed;
	passengers = obj.passengers;
	this->carCode = new char[5];
    strcpy_s(this->carCode,4,obj.carCode);
}

Car& Car::operator=(const Car& obj)
{
	cout << "Copy Assignment called" << endl;
	//1.self assignment check
	if (this == &obj)
	{
		return *this;
	}

	//2.delete exisiting allocation
	delete[] carCode;

	fuel = obj.fuel;
	speed = obj.speed;
	passengers = obj.passengers;
	this->carCode = new char[5];
	strcpy_s(this->carCode, 4, obj.carCode);
	
	return *this;
}

Car::~Car() {
	--totalCount;
	cout << "Destructor called" << endl;
	delete[] carCode;
}

void Car::Draw(Point start, Point end)
{
	cout << start.x << start.y;
	cout << end.x << end.y;
	Foo(*this);
}

void Car::Fillfuel(float amount)
{
	fuel = amount;
}

void Car::Accelerate()
{
	this->speed++;
	this->fuel -= 0.5f;
}

void Car::Brake()
{
	speed = 0;
}

void Car::AddPassengers(int passengers)
{
	this->passengers = passengers; //assign local variable to local variable if this is not used.
}

void Car::AssignCode(char* code)
{
	strcpy_s(this->carCode,4,code);
	cout << "Code assigned:" << this->carCode<<endl;
}

void Car::Foo(const Car &obj)
{
	cout<<"Foo::"<<obj.speed << endl;
	cout << "Car::" << this->speed << endl;
}

void Car::Dashboard() const
{
	cout << "Fuel" << fuel << endl;
	cout << "Speed" << speed << endl;
	cout << "Pasasengers" << passengers << endl;
	cout << "totalCount" << totalCount << endl;
	cout << "Code" << carCode << endl;
	cout << endl;
}

int Car::TotalPassengers(const Car & obj)
{
	cout << "Static::Total Passengers:" << totalCount << endl;
//	cout << "non-static member access prohibited:" << Car::speed << endl; //gives error
	Car c;
	cout<<"static::fuel:"<<obj.fuel << endl;   //thats valid as this is explicit call.
	//cout << fuel << endl;                      //thats invalid, no implicit object
	//cout << this->fuel << endl;                //thats invalid, no this pointer as its not associated with object
	return 0;
}

int OOP()
//int main()
{
	Car car(5); //initialized with 5, the default member initializer values are overriden. 
	car.Fillfuel(10);
	car.Accelerate();
	car.AddPassengers(2);
	car.Dashboard();
	Car::Point str;
	str.x = 10;
	str.y = 20;
	car.Draw(str, str);

	Car c1, c2;
	c1.Dashboard();
	c2.Fillfuel(4.5);
	Car::TotalPassengers(c2);
	//cout<<Car::totalCount; not possible because you have made static member private.
	cout << Car::totalCountTest; //now this is public

	//const
	const Car constCar(5);
	//constCar.Fillfuel(23); //cannot be accessed 
	//constCar.Dashboard(); //cannot be accesssed without const
	constCar.Dashboard(); //with const can be accessed. 

	//shallow copy
	int* p = new int(10);
	int* q(p);
	cout << "Values p and q:" << *p << " " << *q << endl;
	cout << "Address pointing to p and q:" << p << " " << q << endl;
	cout << "Pointer's Address p and q:" << &p << " " << &q << endl;

	//deep copy
	int* r = new int(*p);
	cout << "Values p and r:" << *p << " " << *r << endl;
	cout << "Address pointing to p and r:" << p << " " << r << endl;
	cout << "Pointer's Address p and r:" << &p << " " << &r << endl;

	//shallow copy in terms of object
	cout << "BMW:" << endl;
	Car bmw(5);
	//shallow copy causes error
	char code[5] = "abc";
	bmw.AssignCode(code);
	cout << "Merc:" << endl;
	Car merc(bmw);
	merc.Dashboard();
	cout << "Toyota:" << endl;
	Car Toyota(10);   //Copy constructor invoked
	Toyota=merc;      //Copy assignment constructor invoked
	Toyota.Dashboard();
	return 0;
}
