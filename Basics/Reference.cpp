#include<iostream>
using namespace std;


void swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

void swapbyptr(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swapbyref(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void Print(int* val)
{
	if (val != nullptr)
	{
		cout << *val << endl;
	}
}

void PrintbyRef(int& val)
{
	cout << val << endl;
}

int references()
//int main()
{
	//alternative name for a variable
	int x = 10;
	int& ref = x;
	cout << x << endl;
	cout << ref << endl;
	x = 20;
	cout << ref << endl;
	//ref and x point to same location.
	int y = 20;
	ref = 20;
	cout << ref << " "<< x << endl;
	//reference needs to be always initialized.
	//Initializer should be l-value.
	//reference cannot be nullptr.
	//reference bounded to referent for full lifetime , cannot be changed.
	
	int a = 5, b = 10;
	swap(a, b);
	cout << a << " " <<b<< endl;
    
	swapbyptr(&a,&b);

	cout << a << " " << b << endl;

	swapbyref(a,b);

	cout << a << " " <<b<< endl;

	int s = 10;
	Print(&s);

	Print(nullptr);

	PrintbyRef(s);

	//PrintbyRef(nullptr);  //reference cannot be null
	return 0;
}