#include<iostream>
#include<vector>
using namespace std;

//class Templates: following template creates stack for different data types.
//You must define one primary template and define specializations based on that version. cannot create multiple different primary templates.

template<typename T, int size>

class Stack
{
	int mTop{-1};  //this needs to stay int as it is subscript to navigate through array.
	T arr[size];
public:
	Stack() = default;
	Stack(const Stack& obj)
	{
		mTop = obj.mTop;
		for (int i=0;i<=mTop;i++)
		{
			arr[i] = obj.arr[i];
		}
	}

	void push(const T& elem)
	{
		arr[++mTop] = elem;
	}

	void pop();                   //defining pop outside class

	const T& top()
	{
		return arr[mTop];
	}

	bool isEmpty()
	{
		return mTop == -1;
	}

	static Stack Create()                //Factory method
	{
		return Stack<T, size>();
	}
};

template<typename T,int size>
void Stack<T,size>::pop()
{
	--mTop;
}

/* Writing static method outside class
template<typename T, int size>
static Stack<T, size> Stack<T, size>::Create()
{
	return Stack<T, size>();
}
*/

//Class template Explicit specialization 1
template<typename T>
class pPrinter
{
	T* mData;

public:
	pPrinter(T* data):mData(data){}

	void Print()
	{
		cout <<"{" << *mData <<"}" << endl;
    }

	T* getData()
	{
		return mData;
	}
};

//template explicit specialization 2
template<>
class pPrinter<const char*>
{
	const char * mData;

public:
	pPrinter(const char* data) :mData(data) {}

	void Print()
	{
		cout << "{" << mData << "}" << endl;
	}

	const char* getData()
	{
		return mData;
	}
};

//write explicit sp for vector<int>. no need to write complate class template for this.
//we can just do for a particular function.

template<>
void pPrinter<std::vector<int>>::Print()
{
	std::cout << "{";
	for (const auto &x:*mData)
	{
		std::cout << x;
	}
	std::cout << "}" << std::endl;
}

//Partial specialization of class templates
//in explicit, all parameters are specialized, in partial only few are.
//partial specialization is an efficient way to use i.e if there is a condition in which one of the primary template parameter should behave in different way.
//you can use if else condition at run time instead of partial specialization, but partial specialization is more efficient.
template<typename T,int col>
class partialPrinter
{
	T* mData;
	int col;

public:
	partialPrinter(T* data,int columns) :mData(data), col(columns) {}

	void Print()
	{
		cout << "{" << *mData << col << "}" << endl;
	}

	T* getData()
	{
		return mData;
	}
};

template<typename T>
class partialPrinter<T, 80>
{
	T* mdata;

public:
	partialPrinter(T* data) :mdata(data){}
	void Print() 
	{ 
	  cout << "using 80 columns" << endl;
	  cout << "{" << *mdata << "}" << endl;
	}

	T* getData()
	{
		return mdata;
	}
};

int classTemplate()
//int main()
{
	Stack<double,10> s = Stack<double,10>::Create(); //factory method
	s.push(10.5);
	s.push(5.3);

	auto s2(s);
	while (!s2.isEmpty())
	{
		cout << s2.top() << endl;
		s2.pop();
	}

	//Class template Explicit specialization 1
	int idata = 5;
	pPrinter<int> p1(&idata);
	p1.Print();

    const char* str{"Hello"};
	pPrinter<const char*>p2(str);
	p2.Print();

	std::vector<int> v{ 1,2,3,4,5 };
	pPrinter<vector<int>> vec(&v);
	vec.Print();

	int pdata = 5;
	//partial specialization
	partialPrinter<int, 80> p3(&pdata);
	p3.Print();
	return 0;
}