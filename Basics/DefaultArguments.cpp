#include<iostream>
using namespace std;

//inline functions - replaces call with function body 
//ceratin functions may not be inlined when eg:large function, recursive, fucntion pointer
//excessive inlining increases binary size.
inline int Square(int x)
{
	return x * x;
}

//Macros if value passed (val + 1)// the result is 11 but we expected 36.
//macro expanded at pre processing
//avoid use of maccros fro small functions.
//#define Square(x) x*x

void CreateWindow1(int a, int b=10, int c=34)
{
	cout << "" << endl;
}

int defaultArguments()
//int main()
{
	CreateWindow1(10);
	cout<<Square(5+1);
}