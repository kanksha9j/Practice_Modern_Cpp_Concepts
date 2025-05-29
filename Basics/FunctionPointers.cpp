#include<iostream>
using namespace std;


//Function pointer that holds the address of the function
//can be used to inderectly invoke the function when function name is not known.
//<ret> (*fncptr)(args)=&Function    
// int (*ptr)(int,int)=&Add // int Add(int,int)


void Print(int cnt, char ch)
{
	for (int i = 0;i <= cnt;i++)
	{
		cout << ch;
	}
	cout << endl;
}

namespace calc {
	float Add(float a, float b)
	{
		return a + b;
	}
	namespace comparison{
		void Print() {
			cout << "ok" << endl;
		}
	}
}

namespace {
	void check()
	{
		cout << "check" << endl;
	}
}

int funcPointers()
//int main()
{
	Print(5,'#');
	void (*ptr)(int, char) = &Print; //or just =Print
	(*ptr)(8, '@');
	ptr(5, '+');

	float (*ptrAdd)(float, float) = &calc::Add;
	float res= (*ptrAdd)(12.2f,23.45f);
	cout << res<<endl;
	res = ptrAdd(13.2f, 45.6f);
	cout << res<<endl;

	//namespace:
	//using calc::Add;
	using namespace calc;
	cout << calc::Add(4.5f, 5.6f) << endl; //another way to call
	calc::comparison::Print();
	check(); //calling an unnamed namespace funtion. this function can be called only in this source file.
	return 0;
}