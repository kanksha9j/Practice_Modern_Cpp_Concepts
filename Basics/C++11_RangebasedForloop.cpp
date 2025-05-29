#include<iostream>
using namespace std;

int rangebased()
//int main()
{
	int arr[] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i];
	}

	//does not need index var. used with any object that behaves like range
	cout << endl;
	for (int& n : arr)  //in each iteration copy of element is created in x. To avoid that use reference.
	{
		n = 3;          //moodifying array
		cout << n;
	}

	//range-based for loop
	//end condition not required
	//no need of index to iterate.
	//less chance of error due to iteration through correct bounds

	auto range = arr;             //can use rvalue reference for lvalues auto&&range =arr  //here its not necessary to use aut&& , auto& is enough
	auto begin = std::begin(arr); // so : auto begin = std::begin(range)
	auto end = std::end(arr);     // so : auto end = std::end(range)
	for (;begin != end;++begin)   //the rest will work as same.
	{
		auto v = *begin;
	}

	//auto&& is universal reference or forwarding reference that binds to both lvalues and rvalues.
	//auto&& is mostly used when you want to forward the type of reference or you want to konw the type

	for (auto&& v : {1,2,3,4})   //using rvalue reference here for rvalues.
	{
		cout << v << endl;
	}

	int* beg1 = &arr[0]; //or std::begin(arr)
	int* end1 = &arr[5]; //or std::end(arr)
	while (beg1 != end1)
	{
		cout << "beg" << *beg1<< endl;
		++beg1;
	}
	
	//C++17: begin and end should be same type. 
	// like char arrays null terrminotr 
	// is end and not same as begin. so range based cant be used
	return 0;
}