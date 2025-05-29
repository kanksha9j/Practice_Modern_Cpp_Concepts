#include<iostream>
#include<functional>
using namespace std;

/*
* C++11:
std::function: It is a general purpose function wrapper.
it stores any entity that can be invoked as function
We can store function pointer or function object in it.
stored object is called target.
Invocation without target thows std::bad_function_call exception
std::function<function signature>object={callable}

std::function is a template class in C++ that is used to wrap a particular function 
or any other callable object such as a lambda, or function object. 
It is generally used to write generic code where we need to pass functions as 
arguments in another function (callbacks).

std::bind:
binds arguments to a given function
arguments are bound using placeholders or bound directly to specific value.
std::bind(callable,arg1,arg2..argN)
Useful: 
1. if you pass rvalue , it will forward rvalue correctly to internal function. same for const
when you want to use a function with similar use but that function takes less arguments.
but better to use lambda functions for this use.
*/

int Square(int x) { return x * x; }
int* Alloc(size_t) { return new int(5); };
struct Max {
	int operator()(int x, int y)
	{
		return x > y ? x : y;
	}
};

//Implementing callback
int Add(int x, int y)
{
	return x + y;
}

int Subtract(int x, int y)
{
	return x - y;
}

/*template<typename Callback>
int Operation(int x, int y, Callback callback) 
{
	return callback(x, y);
}*/

int Operation(int x, int y, std::function<int(int,int)> callback) //alternative to tempate
{
	return callback(x, y);
}

//bind functions
void Print(const char* str,int x)
{
	cout << str << x << endl;
}

int Adder(int x, int y, int z)
{
	return x + y + z;
}

int functionwrapper()
//int main()
{
	try
	{

		std::function<int(int)> f1 = Square;  //f1 stores address of Square function
		cout << f1(3) << endl;

		std::function<int* (size_t)> f2 = Alloc;
		cout << *f2(1024) << endl;

		//invoking Lambda function
		std::function<bool(int)> f3 = [](int x) {
			return x % 2 == 0;
			};
		f3(3);

		//invoking function object
		Max m;
		std::function<int(int, int)>f4 = m;
		cout<< f4(3, 4) << endl;

		//implementing callback
		std::function<int(int, int )> f6 = Add;   //Create a wrapper of lambda/fobj/fptr
		cout << Operation(3, 4, f6) << endl;      //then pass to template function
		f6 = Subtract;
		cout << Operation(3, 4, f6) << endl;


	/*	std::function<int(int)> f5; //bad function call due to no target
		f5(2); */

		auto f7 = std::bind(Square, 3);
		f7();

		auto f8 = std::bind(Print, std::placeholders::_1, std::placeholders::_2); //using placeholder, order does not matter
		f8("Hello",10);
		using namespace std::placeholders;

		std::function<void(const char*)> f9 = std::bind(Print, _1, 20); //here int 2nd argument is not taken
		f9("Hello");

		auto f10 = std::bind(Max{}, _2, _1); //creates temp max obj
		cout << f10(2,3) << endl;

		//Advantage of using binder is the operation takes 2 arguments only, 
		//with binder you can use 3rd argument and call adder function in the callback operation
		auto f11 = std::bind(Adder, _1, _2, 0);
		cout << Operation(10, 20, f11) << endl;

		//but better to use lambda for this puprose:
		auto f12 = [](int x, int y) ->int {
			return Adder(x, y, 0);
			};
		cout << Operation(10, 20, f12) << endl;

		//lambda function you need to handle  r-value.
		auto f13 = [](auto&& x, auto&& y)
			{
				return Adder(std::forward<decltype(x)>(x), std::forward<decltype(x)>(y), 0);
			};
		cout << Operation(10, 20, f13) << endl;

		//C++20 template type parameters in lambda
		auto f14 = []<typename T>(T && x, T && y) {
			return Max{}(std::forward<T>(x), std::forward<T>(y));
		};
		cout << Operation(30, 20, f14) << endl;

	}
	catch(const std::exception &e){
		std::cout << e.what() << endl;
	}

	return 0;
}