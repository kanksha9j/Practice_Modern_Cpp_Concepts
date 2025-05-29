#include<iostream>

using namespace std;

/*
lvalue-
has name, can be assigned other values
some return lvalue beyond expression
++x = 6;
return by ref

rvalue -
no name : temporary
cannot assign anything
res=(x+y)*z
return by value

r value refe
always bind to temp
cannot point to lvalue


int &&r1=10 //r-value
int &&r2 =Add(1,2) //return by value

*/

/*
* Move semantics: copies the object from source to target using shallow copy and then 
deletes the dynamic resources of source object.
copy constructor: if there is temporary values. assigns new memory , copies and then destroys temporary. it is costly.
so use move.
Detect the temporary using rvalue reference.
obj1 = v, ptr   copied to obj2= v, ptr points to same memory location and then obj1 is deleted.
Copying rvalue is costly than lvalue because:
you need to first create object for rvalue then you need to create another object and then you need to copy to it.
unlike lvalue: where the object is already created so only copying is left.
*/

/*rule of 5:
If class has ownership semantics : or for proper resource management:
you must create user-defined:
1.Destructor
2.Copy constructor
3.Copy assignment operator
4.Move constructor
5.Move assignment operator.
*/
/*Rule of 0:
if no resource acquired , dont implement any.*/

/*
Copy elison :
technique used by compiler to elimante temporary objects.
cannot turn it off in VS
you can use linux. g++ -fno-elide-constructors main.cpp Integer.cpp 
Integer a=3; //this statemnt is taken as Integera =Integer(a) this calls the move constructor. 
Integer Add(int v){
Integer temp(v)            // para constructor call
return temp;              //move constructor call //ommited if copy elision on //also called return value optimisation
}              
integer a=Add(2)          //move called   //ommited if copy elision on
 */

void Print(int& x)   //non-const references can only bind to lvalues
{
	cout << "int&" << endl;
}

//C++'s lifetime extension rule: A temporary object bound to a const reference will persist for the lifetime of that reference (until it goes out of scope).
void Print(const int& x) //const references can bind to both lvalues and rvalues
{
	cout << "const int&" << endl;
}

void Print(int&& x)  //rvalue references can only bind to rvalues
{
	cout << "int&&" << endl;
}

class Integer
{
	int* m_Value;

public:
	Integer() { cout<<"Default constructor" << endl; m_Value = new int(0); };
	Integer(int value) { cout << "Parameterized constructor" << endl; m_Value = new int(value); };
	Integer(const Integer& obj) {
		cout << "Copy constructor" << endl;
		m_Value = new int(*obj.m_Value);
	};

	Integer(Integer&& obj) noexcept
	{
		cout << "Move constructor" << endl;
		//1.Do shallow copy
		m_Value = obj.m_Value;

		//2.make source ptr null
		obj.m_Value = nullptr;
	}

	Integer& operator=(const Integer& obj) {
		cout << "Assignment operator" << endl;
		//1. Self check
		if (this == &obj)
		{
			return *this;
		}
		//2. delete previous
		delete m_Value;

		m_Value = new int(*obj.m_Value);

		return *this;
	}

	Integer& operator=(Integer&& obj) noexcept
	{
		//1.self-check
		if (this == &obj)
		{
			return *this;
		}
		//2.delete
		delete m_Value;

		//3. shallow copy
		m_Value = obj.m_Value;
		
		//4.delete source ptr.
		obj.m_Value = nullptr;

		return *this;
	}

	/*
	    Operator	Return Type	            Why ?
		operator+	By value(Integer)	    Creates a new object(e.g.a = b + c)
		operator=	By reference(Integer&)	Modifies existing object and allows chaining(a = b = c)
    
	    returning *this needs a reference (you are sending same object) . temp object needs to be sent by value(you are sending a new object).
	*/

	Integer operator+(const Integer& obj) const
	{
		cout << "operator+ called" << endl;
		Integer temp;
		*temp.m_Value = *m_Value + *obj.m_Value;
		return temp;
	}

	//doing const int& is bit overhead , so no need for int.
	//but you must for string,vector Set(const string& var) as copying the string,vector is expensive
	void setValue(int value)  
	{
		*m_Value = value;
	}

	//Similarly following for int is sufficient. 
	//but for strings and objects use const string& getValue() const. as copying string is expensive. 
	int getValue() const   //dont forget it is standard practice
	{
		return *m_Value;
	}

	static Integer Add(const Integer& a, const Integer& b) //returning object by value;
	{
		Integer temp;
		temp.setValue(a.getValue() + b.getValue());
		Integer result = std::move(temp); //written this statement to force copy constructor call because RVO is enabled.
		return result;
	}

	~Integer() { cout << "Destructor" << endl; delete m_Value; }
};

class Number {
	Integer num;           //as integer class is member of Number. 
	                       //when compiler generates copy and move constructors , it will internally invoke constructors of Integer class.
public:
	Number(int value): num(value) {};  
	//Implement to check rule of 0
	
	//Number(const Number& obj) = default;

	//Number& operator=(const Number& obj) = default;

	//Number(Number&& obj) = default;
};

Number change(int val)
{
	Number temp(val);
	return temp;
}

int MoveSemantics()
//int main()
{
	/*int&& r1 = 10; //r-value
	int&& r2 = Add(1, 2); 
	int x = 0;
	int&& r3 = x;*/
	//
	//int x = 10;
	//Print(x);
	//Print(10);
	//
	////allows to detect temporary and expresion
	//const int& ref2 = 3;
	//
	////Integer: understanding move semantics
	//Integer a(1), b(2);
	//
	//a.setValue(Integer::Add(a, b).getValue()); 
	////Add(a,b) returns temporaries i.e unnamed object. 
	////You can only call const methods on temporaries.
	////so if getValue was not const method, then above will not be allowed for safety.
	//
	///* Copy Elison:
	//When you return a local object by value, the compiler can choose to directly construct the return value in 
	//the memory location where the return value is going to be stored (i.e., the location of the receiving variable). 
	//This means that the copy constructor doesn't need to be called at all. 
	//This optimization is known as RVO (Return Value Optimization).*/


	//Number p(1), q(p);  //para and copy constructor called
	//p = q;
	//
	//Number r{ std::move(change(3)) };   //compiler automatically synthesizes copy and move constructors and destructor for number class.
	////doing move due to elison
	////r = std::move(change(3));  //without rvo , this could invoke move operator.

	////Rule of 0:
	////if you write custom copy or copy assignment for Number class, move operations are deleted.
	////if you write custom move , copy operations are deleted and as well as the other move assignment is deleted.
	////if you write custom move assignment, copy operations are deleted and as well as the other move constructor is deleted.
	//// if you write custom destructor, then move operations are deleted.
	////if you dont write any custom function, default functions for all are synthesized by compiler
	////To allow implementation forced you can make the functions default. this will treat it as custom implementation.
	////eg: unique pointer allows only move opearations. and does not allow copy.

	////std::move usually used on lvalue
	//Integer z(20);
	//Integer x{ z }; //this will always call copy constructor
	//std::cout << "lvalue:" << endl;
	//Integer c{ std::move(z) }; //this will call move constructor. std::move forces to use move on lvalue
	////std::move casts an lvalue into an rvalue reference, allowing the move constructor or move assignment operator to be called.
 //   //Resources are moved(if move semantics are implemented), which is faster than copying.
	////std::move on an rvalue: It has no practical effect since an rvalue is already an rvalue reference.
	//std::cout << "rvalue:" << endl;
	//Integer v{ Integer::Add(2,3)}; //it calls move constructor, but i think its disabled by rvo
	
	//operator overload
	Integer i(1),b(2);
	Integer a = i + b;
	cout << a.getValue() << endl;
	return 0;
}