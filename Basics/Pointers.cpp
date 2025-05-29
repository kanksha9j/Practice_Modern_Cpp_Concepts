#include <iostream>
#include<string>    

using namespace std;

//int main()
int pointers()
{
	int x = 10;
	cout << &x<<endl;
	int* p = &x;
	//pointer type should be same as pointee type
	cout << p <<endl;
	//create void pointercan point to any type of variable.
	float y;
	void* ptr = &y;
	cout << ptr << endl;
	//Wild pointer is uninitialized pointer. if we dont initialize of variable, it points to garbage value, leading to potential crash or unexpected behaviour.
	//NULL is macro in C and pre C++11
	//C++11 uses nullptr to initialize ptr.
	void* ptr1 = nullptr;
	//cout << *ptr1 << endl; Cannot read from nullptr.
	//Dangling pointer: pointer whose memory has been deallocated and that leads to undefined behaviour when accessed.
	//object that pointer points to is deleted or goes out of scope and pointer is not updated to point to valid memory location.

	int* ptr2 = new int(10); //allocate memory and initialize
	delete ptr2;
	//ptr is now dangling ptr.
	//To avoid this , reset to nullptr
	ptr2 = nullptr;

	return 0;
}