#include<iostream>
using namespace std;

class A {
	int val;
	int val2;
	weak_ptr<int> m_Value;

public:
	A():val(1) { cout << "Constructor" << endl; };
	A(int value) : val(value) { cout << "Para Constructor called" << endl; };
	A(int x, int y) : val(x), val2(y) { cout << "Para Constructor 2 called" << endl; };
	~A() { cout << "Destructor" << endl; };
	void Print(std::unique_ptr<A> obj)
	{
		std::cout << "Print" << endl;
		std::cout << obj->val << endl;
	}

	void Print(std::shared_ptr<A> obj)
	{
		std::cout << "Print" << endl;
		std::cout << obj->val << endl;
		std::cout << "Ref count:" <<obj.use_count()<< endl;
	}

	int getvalue() const
	{
		return val;
	}

	void SetValue(std::shared_ptr<int> ptr)
	{
		m_Value = ptr;
	}

	void Print()
	{
			
			if (m_Value.expired())
			{
				cout << "resource is not available" << endl;
				return;
			}
			auto sp = m_Value.lock();
			std::cout << "Print:" << *sp << endl;
			cout << "Address of m_Value" << sp << endl;
	}
};

A* GetPointer(int value)
{
	A* p = new A(value);
	return p;
}

void Display(A* ptr)
{
	if (ptr != nullptr)
	{
		cout << "Unique Value" << ptr->getvalue() << endl;
	}
}

void Store(std::unique_ptr<A> ptr)
{
	cout << "Unique_value:" << ptr->getvalue() << endl;
}

void Store1(std::unique_ptr<A> &ptr)
{
	cout << "Unique_value:" << ptr->getvalue() << endl;
}

int smartPointers()
//int main()
{
	A a;
	A* p = new A;  
	delete p; //if you dont write delete , destructor is not called.
	
	/******* Unique pointer *******/

	std::unique_ptr<A> q(new A); //Unique pointer has explicit constructor, hence assignment not possible here
	a.Print(std::move(q));    //move allowed   , q destructor called when print is out of scope
	//q->getvalue();          //q cannot be used as it is moved. 
	cout << a.getvalue() << endl;;
	//std::unique_ptr<A> r(q);// copy is not allowed
	q.reset(new A()); //


	std::unique_ptr<A> m(GetPointer(10));
	if (m == nullptr)
	{
		//m = new A(10); cannot do assignment for smart pointer, but can do with initialization or reset.
		m.reset(new A(20));   //so use reset
	}

	Display(m.get());  // Display function accepts A* ptr, and we have unique ptr, so can use .get() to get the ptr.
	//delete m;   // not required
	m = nullptr; // this assignment is overloaded so allowed.

	m.reset(new A()); //reset deletes the underlying ppointer and assigns new resource. so above statement not required.

	*m = __LINE__; //value assignment can be done
	*m = 20;       //value assignment can be done

	//delete m; // not required

	Store1(m);   //pass by reference if you want to use it after the function.
	*m = 200;
	Store(std::move(m));
	//*m = 133;   //not allowed

	/******* Shared pointer *******/

	std::shared_ptr<A> s(new A);
	a.Print(s); //copy allowed , ref increases by 1; ref decreases after print scope end
	cout<<s->getvalue()<<endl;
	std::cout << "Ref count:" << s.use_count() << endl;  //shows refernce count, use only while debuugging
	//destructor for sharedptr called when ref count becomes 0;
	std::shared_ptr<A> t = s;
	std::cout << "Ref count after t :" << s.use_count() << endl;
	Display(s.get());
	s.reset(new A(2));
	cout << s->getvalue() << endl;

	/******* Weak pointer *******/
	A* u = new A();
	std::shared_ptr<int> pt(new int(100));
	cout << "Address of pt" << pt << endl;
	u->SetValue(pt);
	if (*pt > 10)
	{
		//delete pt;        //while m_Value still points to the address where the memory no longer exists, if pointer is simple pointer
		pt = nullptr;       // assign to null , decrease ref count. or you can use reset. 
		                    //the underlying memory is not deleted, it can be released much later.
	}
	u->Print();

	delete u;
	//delete pt;            //we do if simple ptr

	/******* Circular reference *******/

	/******* Deleter: For unique ptr, shared ptr *******/

	//When resource is not allocated using new, then in such case you can create a deleter.
	//Delter can be function object or function. but function object is preferred

	/******* Dynamic arrays *******/
	std::unique_ptr<int[]> array{ new int[5]{1,2,3,4,5 }};
	//for shared ptr dynamic arrray list support added in C++17
	array[0] = 5;

	/******* Using make *******/
	{
		auto p = make_unique<int>(5);
		auto q = make_unique<A>(10,20); //in bracket include value passed to constructor of class A.

		auto r = make_unique<int[]>(5); //creates dynamic array list of 5 elements, cannot initialize in make_unique
		r[0] = 5;// can initialize like this
	}
	
	//Advantage of using make_shared: single allocation(single new call) done for object and control block(reference count) 
	//otherwise it takes 2 new calls.
	{
		auto p = make_shared<int>(5);
		auto q = make_shared<A>(10, 20); //in bracket include value passed to constructor of class A.

		auto r = make_shared<int[]>(5);  //creates dynamic array list of 5 elements, cannot initialize in make_unique
		r[0] = 5;// can initialize like this
	}

	return 0;

} //at end of scope destructor is called only objects that are on stack like A a; and not on heap.
 //for dynamically allocated obj/objects on heap delete is required.

