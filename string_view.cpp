#include<iostream>
#include <string_view>
using namespace std;

/*
string_view: std::string_view is a lightweight, non-owning reference to a string introduced in C++17.
It provides a read-only view of a character sequence without copying or allocating memory.
Internally, it simply stores:
1. a pointer to the first character
2. the length of the string

Because it does not own the data, it is very efficient for passing substrings or string parameters, 
but it becomes invalid if the underlying string it refers to is destroyed.
if str1 is out of scope or deleted, and str2 is used , it is actually a dangling reference.
So it must not be point to a local variable
Therefore, a std::string_view must not refer to data stored in a local variable that will be destroyed, such as a std::string inside a function returning the view.
*/

int main()
{
std::string str1 {"Hello!"};
std::string_view str2 = str1.substr(0,5);
cout<<str2<<" "<<&str2<<" "<<&str1<<endl;
return 0;   
}
