#include<iostream>
using namespace std;


void constbyref(const int& ref)
{
	//ref = 20; //not allowed due to const
	cout << ref << endl;
}

int constQualifiers()
//int main()
{
	/* creates a variable that is constant.
	always needs an initializer
	attempt to modify causes compilation error.
	replaces C macros used for creating constants: not type safe, do not have scope, lead to bugs
	const commonly used with references.

	const<type><variable> {initializer}
	*/

	float radius = 0;
	float area = 3.14f * radius * radius;
	float pi = 3.14f;
	float area1 = pi * radius * radius;
	const float PI1 = 3.14f;
	float area2 = PI1 * radius * radius; //pi cannot be modified by anyone
	//use capital for const variable.
	//PI1 = 2; //gives error

	const int CHUNK_SIZE = 512;
	/*int* ptr = &CHUNK_SIZE;  //constant pointer needed.
	*ptr = 1;*/

	int y = 10;
	//for creating pointer to constant, pointer should also be constant;
	const int* ptr1 = &CHUNK_SIZE;
	ptr1 = &y;   //allowed
	/*ptr1 = 1;  //cannot modify */ 

	//const int * suggests the ptr containing int data should remain constant.
	//const int * const ptr suggests that the ptr cannot point to another location.
	const int* const ptr2 = &CHUNK_SIZE;
	/*ptr2 = &y; //not allowed
	*ptr2 = 1; //not allowed*/


	//ref is inherently const, so doing const int &const ref =x is invalid.
	int p = 10;
	constbyref(p);

	const int& ref1 = 10; // is allowed
	//int& ref1 = 10; // is not allowed
	
	//Try to modify x1 & x2 and see the compilation output
	int x = 5;
	const int MAX = 12;
	int& ref_x1 = x;
	const int& ref_x2 = x;
	ref_x1 = y;
	//ref_x2 = y; //not allowed  

	const int z = 20;
	//Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
	const int* ptr6 = &x;
	int* const ptr4 = &x;
	const int* const ptr5 = &x;
	ptr6 = &z;
	*ptr4 = z; //allowed
	//ptr5 = &z;

	//Find which declarations are valid. If invalid, correct the declaration
	const int* ptr3 = &MAX;
	//int* ptr7 = &MAX;  //error

	const int& r1 = ref_x1;
	//int& r2 = ref_x2; //not allowed

	//int*& p_ref1 = ptr1; //ref to ptr
	//const int*& p_ref2 = ptr2;

	return 0;
}