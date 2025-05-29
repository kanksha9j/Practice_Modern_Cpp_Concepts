#include<iostream>
#include<vector>

using namespace std;

//Scalar types required initialization with = or ()
//Array types to be initialized with {}
//But in C++11 uniform initialization same for all types.
//now use {} for all types
//Forces initialization
//Prevents bugs when incompatible types used.

static int uInit()
{
	int a1 = 0; //Unitializaed
	int a3(5);  //Direct initialization
	std::string s1("C++"); //Direct initialization
	char d2[8] = { '\0' }; //Copy initialization
	char d3[8] = { 'a','b','c' }; //aggregate initialization


	//Uniform initialization
	int b1{}; //value initializion, initialized to default values
	int b2{ 5 }; //Direct initialization

	int b4 = 0;
	char e1[8]{}; //
	char e2[8]{ "Hello" };

	int* p1 = new int{};
	char* p2 = new char[8] {};
	char* p3 = new char[8] {"Hello"};

	//Primitive type stick to assignment
	//user defined = use uniform initialization
	//1. Value initializatio
	//2. Direct initialization
	//3. Copy initialization = avoid with user defined objects.
	//Advantage : Forces initialization
	//use direct initialization for array types.
	//prevents narrowing conversion: floating point assignment to integer.
    //uniform syntaxx.
	float f{};
	//int i{ f };

	vector<vector<double>>vs = {
		vector<double>(10),  //vector constructed with 10 elements
		vector<double>{10}  //vector with 1 element of value 10
	};
}


