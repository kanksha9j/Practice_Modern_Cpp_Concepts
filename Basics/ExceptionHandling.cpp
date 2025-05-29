//Exception cannot be ignored.
#include<iostream>
using namespace std;

/* 1. Stack unwinding: When a function throws exception ,the destructor is called for objects on stack .
 but what about objects on heap eg: A* ptr = new A(), the delete will not be called if function throws exception before it. 
So there willl be memory leak, so that is why always use smart pointers

2. if constructor throws exception then destructor of that class does not execute. because the constructor fails to execute completely.

3. Destructors should not throw any exception. Because destructor might be called 
 while stack unwinding and program crashes.
even if you must write exception in destructor it should be handled within destructor and not thrown outside.

4. Always use smart pointer class members, if using exception.

5.noexcept: used for functions that gurantees to not throw exceptions, this helps compiler to not generate 
stack unwinding code. Can have big impact on optimization and code performance.
if noexcept function throws exception then program terminates/crashes and does not go though catch blocks in main function.

6. Destructors are implicitly noexcept if all its member destructors are noexcept.
but to make it clear mark main class destructor as noexcept.

Move constructor and assignment should also be marked noexcept, because 
The STL (like std::vector) provides strong exception safety.
To maintain this guarantee, STL containers will only use move operations if they are marked noexcept.
If the move operation is not noexcept, STL will fall back to using copy operations, provided the copy constructor is available.
This is because if an exception is thrown during a move (e.g., during reallocation or resizing), it could result in loss of data or leave the container in an inconsistent state.
By using copy operations, which are assumed to be safe, the STL can ensure that the original state is preserved even if something fails.

STL uses std::is_nothrow_move_constructible<T> to check if a type’s move constructor is safe.
If it’s not marked noexcept, STL won’t risk using it during critical operations like reallocation.
*/

void Test(int x)
{
	throw x;
}

int Sum(int x, int y) noexcept(true)   //same as noexcept.  noexcept(false): same as not writing noexcept
{
	//Test(x); //with this statement program will crash  
	return x + y;
}

int Add(int x, int y) noexcept(noexcept(Test(x)))   //depending on whether Test throws exception- this will be true or false
{
	//Test(x); //with this statement program will crash  
	return x + y;
}

int exceptionHandling()
//int main()
{
	int errors{4};
	try {
		try {
			throw std::runtime_error("Fail");
		}
		catch (std::runtime_error& e) {
			cout << " runtime_error:" << e.what() << endl;
			if (errors >= 4)
			{
				std::runtime_error err("Too many errors. abandoning operation ");
				e = err;
				throw; //rethrowing error
			}
		}
		catch (std::bad_alloc& e) {
			cout << "bad_alloc:" << e.what() << endl;
		}
		catch (std::out_of_range &e) {
			cout << "out_of_range:" << e.what() << endl;
		}
	}
	catch (std::exception &e) {
			cout << "exception:" << e.what() << endl; //covers all above exceptions. no need of above
	}
	catch (...) {
		cout << "Error:catches undocumented exception also" << endl;
	}

	return 0;
}