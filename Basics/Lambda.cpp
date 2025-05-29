#include<iostream>
using namespace std;

/*
Callback:
callbacks are implemented using:
1.function pointers   - invoked through ptr,slow,cannot store state
2.functors/ function object - invoked through object,fast,can store state
3.lambda expressions
Callback is that when some condition is true , a particular function is called.
eg: button click event- on that a event a particular task is done.
using if else , we will need to continously poll, but using callback no need to contniously poll.
a callback can be called within a thread or in another thread.

*/

int lambda()
//int main()
{
	//Zero argument lambda
	[] {
		cout << "C++" << endl;
		}();

	//f is a lambda function object. This objects overloads operator ()
	auto f = []() {
		cout << "Program" << endl;
		};
	f();



	return 0;
}