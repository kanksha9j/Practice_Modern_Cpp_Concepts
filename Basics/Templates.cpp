#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS          //need to be defined at the top
#endif

#include<iostream>
#include"Integer.h"
using namespace std;
using namespace ClassInteger;

/*
1.examines type argument,
2. no conversion done
3. template instatntiation - done at compile time. function and class templates
4.can override type deduction
5. Yes, perfect forwarding is fundamentally a template-only feature in C++

*/

//0. Template
template<typename T>
T Sum(T numA, T numB)
{
	cout << typeid(T).name() << endl;
	return numA + numB;
}

//0.Returns the sum of array elements 
//returns largest number in array
template<typename T>
T ArraySum(const T* pArr, size_t arrSize)
{
	T sum = 0;
	return T;
}

//0.Return the smallest and largest element in a pair
template<typename T>
std::pair<T, T> MinMax(const T* pArr, size_t arrSize)
{
	T minVal = 0;
	T maxVal = 0;

	return std::make_pair(minVal, maxVal);
}

//1A. Explicit instantiation  - used for correct semantic for a particular type, can be used more optimally
template char Sum(char x, char y);

//1B. Explicit specialization - requires empty template argument<>
template<> const char* Sum<const char*>(const char* x, const char* y)
{
	size_t len = std::strlen(x) + std::strlen(y) + 1;
	char* result = new char[len];  // Caller must delete this memory!
	std::strcpy(result, x);
	std::strcat(result, y);
	return result;
}

//2A. Non-type template argument
template<int size>  //Must be a constant expression
void Print()
{
	std::cout << size << endl;
	//size++; //size is a constant, cannot modify
	char buf[size]; //mostly used for arrays
}

//2B. Non-type template argument by passing reference as argument
template<typename T, int size>   //Such templates are used for std::begin and std::end STL functions
T Sum(T (&pArr)[size])
{
	T sum = 0;
	for (const auto &v : pArr)   //const =to not modify, takes element by ref and not copy
	{
		sum += v;
	}
	return sum;
}

//3. Perfect forwarding
class Employee
{
	std::string m_name;
	Integer m_id;
public:
	//Following constructor combinations need to be made , if template not used
	/*Employee(string& name, Integer& id) :
		m_name{ name },
		m_id{id} {
		cout << "Employee lvalue constructor called" << endl;
	}
	Employee(string&& name, Integer&& id):
		m_name{ name },
		m_id{std::move( id) } {
		cout << "Employee rvalue constructor called" << endl;
	}*/

	//forward ensures appropriate type argument to be forwarded, lvalue is forwarded as lvalue, 
	//rvalue as rvalue. Information of type is preserved and forwarded.
	template<typename T,typename U>
	Employee(T&& name, U&& id):
		m_name{ std::forward<T>(name) },
		m_id{std::forward<U>(id)} {
		cout << "Employee template constructor called" << endl;
	}

};

template<typename t1,typename t2>
std::unique_ptr<Employee> Create(t1&& name, t2&& id)
{
	std::cout << "Create Employee: factory method " << endl;
	return std::make_unique<Employee>(std::forward<t1>(name), std::forward<t2>(id));
}

//Variadic templates
/*
* They are used to write reusable, type safe code. 
* Allows to create templates that accept variable number of arguments with variable types.
* eg: printf accepts multiple arguments , it is not typesafe
* but it is used with macros internally, cannot accept ref as arguments.
* can use initializer list internally: disadv: but here args have to be of same type.
*/

void Print()
{
	std::cout << endl;
}

template<typename T, typename...Params>   //called template parameter pack. 
//Params is alias to list of typenames. Params is pack of typenames.
void Print(T&& a, Params&&...args) //... is ellipsis (like used in catch block)//Function parameter pack: it 
{
	//cout << sizeof...(args) << endl; //number of arguments in parameter pack
	//cout<< sizeof...(Params) << endl; //number of arguments in parameter pack
	//Aufcout<< a;
	if (sizeof...(args) != 0)
	{
		std::cout<<",";
	}
	Print(std::forward<Params>(args)...);  //this is base condition of recursion.
}
//in each recursive call one argument is reduced:
//cant access individual arguments directly, can be done with recursion.
//Print(1,2.5,3,"4")
//Print(2.5,3,"4"); 2.5 passed in a, rest in args
//Print(3,"4"); 3 passed in a, rest in args
//Print("4"); 4 passed in a, rest parameter pack is empty.
//Print(); //this is where stop condition is called.

int templates()
//int main()
{
	//cout << Sum(2, 3.4f) << endl;   //not allowed, you need to type cast or explicitly specify type
	cout << Sum(static_cast<float>(2), 3.4f) << endl;
	cout << Sum<double>(2, 3.4f);      //explicit
	cout << Sum(2, 3) << endl;
	cout << Sum(2.1f, 2.2f) << endl;
	cout << Sum(2.1, 2.2) << endl;

	//Access using address
	cout << "function pointer:" << endl;
	int (*pfn)(int, int) = Sum;
	cout<<pfn(2.3, 3.3)<<endl;
	cout << "Char:" << endl;
	cout<<static_cast<int>(Sum('a','b')) << endl; 

	const char* a{ "A" };
	const char* b{ "B" };
	cout << Sum(a, b) << endl;

	//Non type template argument
	Print<3>();

	//Passing reference to non type template argument

	int arr[4] = { 1,2,3,4 };
	cout<<Sum(arr)<<endl;

	//This is similar to : int (& ref)[4] = arr; //4 must be elements equal to elements in arr
	cout << "Perfect Forwarding:" << endl;
	Employee e1{ "Aka", Integer(1234) };
	std::string name{ "Aka" };
	Integer num{ 1234 };
	Employee e2{ name, num };

	//Factory method
	auto emp1 = Create("AG", Integer(9999));

	//variadic templates
	Print(1, 2.5, 3, "4");
	//variadic template with forward
	Print(1, 2.5, Integer{ 4 });


	return 0;
}