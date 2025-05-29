#include<iostream>
using namespace std;
//composition: has-a relation
//Car class has object engine. accelerate will use behaviour of engine.
//Inheritance : inherits features of another class. is-a relation. parent-child classes
//promotoes reuse

class A
{
	int priv=1;
protected:
	int prot = 2;
public:
	A() { cout << "A()" << endl; }
	virtual ~A() { cout << "A destructor" << endl; }
	A(int x,int y):priv(x),prot(y) { cout << "A param" << endl; }
	virtual void Print() { cout << "A"; }
	int pub = 3;
};

class B : public A
{
	int z = 4;
public:
	B() { cout << "B()" << endl; }
	~B() { cout << "B destructor" << endl; }
	B(int x, int y, int z) :A(x, y), z(z) { cout << "B param" << endl; };
	void Print() override { cout << "B:" << z << prot << endl; }
};

class C : private A
{
public:
	using A::A;  //Inheriting constructor as class C does not have its own members
	C() { cout << "C()" << endl; }
	void Print() override { cout << "D:"; cout << prot; cout << pub; }
};

class D :protected A
{
public:
	D() { cout << "D()" << endl; }
	void Print() override final { cout << "D:"; cout << prot; cout << pub; }
};

class E final:public D
{
public:
	E() {}
	//void Print() { cout << prot << pub << endl; }  //not allowed to override due to final
};

//class F : public E {    //cannot inherit from class E as marked final
//
//};

/*Object slicing: part of derived class is slicedto to match the base class */

int Inheritance()
//int main()
{
	//A a;
	//B b(10,20,30);
	//b.Print();
	//C c; //cant access any variable
	//D d;
	A* ptr = new B;
	ptr->Print();
	delete ptr;
	return 0;
}

