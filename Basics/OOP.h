#pragma once  //prevents re declaration errors
#include<iostream>

class Car
{
	static int totalCount;
	float fuel{0};
	float speed{0};
	int passengers{0};
	int arr[5] = { 1,2,3,4 };
	char* carCode = new char[5] {"car"};
	char* q{};
	//auto i = 5; //auto is not allowed
public:
	Car();
	Car(float amount);
	Car(float amount, int pass);
	Car(const Car& obj);
	Car& operator=(const Car& obj);
	~Car();

	struct Point{
		//frequently used for function objects
		int x;
		int y;
	};
	void Draw(Point start, Point end);

	void Fillfuel(float amount);
	void Accelerate();
	void Brake();
	void AddPassengers(int count);
	void AssignCode(char *code);
	void Foo(const Car& obj);
	void Dashboard() const;
	static int TotalPassengers(const Car&obj);

	static int totalCountTest;
};


/*Constructor
* invoked during instantiation,
* used for initialization
* doesnt have return type
* can be overloaded.
* types:
* Default: with no arguments, created by compiler if no constructor specified
,parameterized: has arguments
,copy,delegating,inheriting

destructor: invoked when object destroyed.
used for releasing resources that have been allocated in constructor
cannot be overloaded
no arguments
synthesize by compiler if required.
*/
