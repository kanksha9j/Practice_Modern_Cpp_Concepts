#include<iostream>
using namespace std;

//compiler automatically infers type from initializer.
//in pre-C++11, auto was used as storage specifier
//after C++11 , it is used for type deduction . and it is done from its initializer.

int Sum(int x, int y)
{
	return x + y;
}

int autokey()
//int main()
{
	auto i = 10;
	auto j = 5;
	auto sum = i + 4.3f; //type of sum will be largenst type i.e float

	auto result = Sum(i, j);
	static auto y = 2;

	const int x = 10;
	const auto var = x; //for making var const use const auto
	auto& var1 = x;
	auto ptr = &x; //avoid auto when using ref and const.
	
	auto list = {1,2,3,4};
	//auto list1{ 1,2,3,4 }; //error
	auto list2{1};



	return 0;
}
