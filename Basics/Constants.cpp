#include<iostream>

/*nullptr:
What is nullptr?
nullptr:
nullptr is a keyword introduced in C++11 to represent a null pointer constant. 
It is used to indicate that a pointer does not point to any object or function.
It is of type std::nullptr_t and can be implicitly converted to any raw pointer type.
This makes it safer and more explicit than using NULL or 0 to represent null pointers.

NULL:
NULL is a macro typically defined as 0 or ((void*)0) in C and C++.
It has been traditionally used to represent null pointers.
However, since NULL is essentially an integer constant, it can lead to ambiguity in function overload resolution,
especially when there are overloaded functions that accept both pointer types and integer types.
Example demonstrating the difference between nullptr and NULL in function overloading:
* 

constexpr:
constexpr is a keyword introduced in C++11 that indicates that the value of a variable or function can be evaluated at compile time.
It can be applied to variables, functions, and constructors.
When a variable is declared as constexpr, it must be initialized with a constant expression.
When a function is declared as constexpr, it can be evaluated at compile time if its arguments are constant expressions.
When constructing objects, a constexpr constructor allows the creation of objects that can be used in constant expressions.
constexpr is useful for optimization, as it enables the compiler to perform computations at compile time rather than at runtime.

How to check performance of constexpr?
Checking the performance of constexpr can be done by comparing the 
execution time of code that uses constexpr with code that does not use it.

*/

constexpr int var = 10;
constexpr int getFive() {
	return 5;
}

class A
{
	int value;
public:
	constexpr A(int x) : value(x) {}
	constexpr int getValue() const { return value; };
};

void foo(char*) {
	std::cout << "foo(char*) called" << std::endl;
}

void foo(int) {
	std::cout << "foo(int) called" << std::endl;
}

void myFunc(int x) {
	std::cout << "Overload A called" << std::endl;
}
void myFunc(void* ptr) {
	std::cout << "Overload B called" << std::endl;
}

int main() 
//  int constant()
  {
	foo(0);      // Calls foo(int)
	foo(NULL);   // Calls foo(int) since NULL is typically defined as 0
	foo(nullptr); // Calls foo(char*) since nullptr is of type std::nullptr_t

	myFunc(NULL);                    // Calls Overload A (int), NULL is treated as 0
	myFunc(static_cast<void*>(NULL)); // Calls Overload B (void*), explicit cast to void*

	constexpr A a(10);
	static_assert(a.getValue() == 10, "Value should be 10");

	return 0;
}