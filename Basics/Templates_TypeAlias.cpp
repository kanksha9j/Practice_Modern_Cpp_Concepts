#include<iostream>
#include<vector>
#include<list>
#include<type_traits>

#define NUM 10;  

//template metaprogramming- Programming using templates at compile time
//type traits- Compile-time tools to query or modify types. 
//defined in header <type_traits>


//typedef - name for an existing type
//useful to construct shorter or more meaningful name for existing type
typedef long long LLONG;

//type alias - creates name for existing type , same as typedef
//more natural similar to initializing variables.
using UINT = unsigned int;
using LLONG = long long;

typedef std::vector<std::list<std::string>> names;
//or:
template<typename T>
using Teams = std::vector<std::list<T>>;

using namespace std;

//typedef as function pointer
typedef const char* (*PFN)(int);
//or type alias:
using PFN = const char* (*)(int);
 
void ShowError(PFN pfn)
{

}

//type trait
template<typename T>
T Calculate(T a, T b)
{
	static_assert(is_floating_point<T>::value, "only floating point value allowed");
	if (is_floating_point<T>::value == false)         //type_trait is deduced at compile time. so at runtime , just checks false==false??
	{
		cout << "Use floating type values only" << endl;
		return 0;
	}
	return a / b;
}

//the above condition can be evaluated at compile time and not allow the code to run. by using static_assert.
//static_assert: evaluate expressions at compile time. if expression fails, compiler gives message and compilation fails.

//When the template argument is declared as T&& and you pass an lvalue, the compiler deduces T as an lvalue reference(T = int&),
//due to reference collapsing . This special rule only applies to template parameters declared as T&& (also called universal or forwarding references).
template<typename T>
void Check(T&&)
{
	cout << "Template type trait:" << endl;

	cout << std::boolalpha << is_reference<T>::value << endl; 
    
	cout << std::boolalpha << is_reference<typename std::remove_reference<T>::type>::value << endl;

}

int type()
//int main() 
{
	names Names;

	Teams<string> testingTeams;
	Teams<Teams<string>> test2;
	//typealias supports templates, typedef does not.

	//type traits: following tells if int is integer
	cout << std::boolalpha << "Is integer?" << is_integral<int>::value << endl;

	//cout << Calculate(6, 3) << endl;

	//type trait in template
	int val{20};
	Check(10);
	Check(val);
	return 0;
}


