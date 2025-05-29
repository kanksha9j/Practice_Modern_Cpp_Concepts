#include<iostream>
#include <iomanip>
using namespace std;

int Add1(int a,int b)
{
	cout << "Add1 ::int called" << endl;
	return a + b;
}

int Add1(double a, double b)
{
	cout << "Add1 ::double called" << endl;
	return a + b;
}

void Print(int x)
{
	cout << "what? int" << endl;
}

extern "C"  //or can use extern "C" void Print()
{
	void Print()   //due to extern C does not do name mangling. allows C++ functions to be called from C
	{
		cout << "what?" << endl;
	}
}

/*void Print(int* x)   //will not overload because of Print(int x)
{
	cout << "what? int*" << endl;
}*/

void Print(const int* x) //pointer or reference it will overload
{
	cout << "what? const int*" << endl;
}

//name mangling generates unique names for each function call
//correct function is resolved at compile time. Also called static polyphormism. Achieved by name mangling
int functionOverload()
//int main()
{
	cout << Add1(5, 10) << endl;
	cout << Add1(5.2, 10.3) << endl;
	Print();
	Print(10);
	const int x = 5;
	Print(&x);// calls const int*
	
	return 0;
}
/* Operator overload
* cannot be overloaded:
* 
Scope resolution operator (::)

Member access operators(., ->)

Conditional(ternary) operator ( ? : )

Typeid operator (typeid)

Sizeof operator (sizeof)

Alignof operator (alignof)

Noexcept operator (noexcept)
*/