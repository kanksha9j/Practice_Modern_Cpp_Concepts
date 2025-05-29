// Basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>    
#include"Math.h"

using namespace std;


//Functions: avoid repition of code. same code reused in diff parts of program.
//paramters and return type are optional.
//Definition of function with function body:
//int Add(int x, int y); //Declaration of function
void Print(char c)
{
    for (int i = 0;i < 10;++i)
    {
        std::cout << c;

    }
    std::cout << std::endl;
}

int Basics()
//entry point , always reutun int. is standard in C++.
//int main()
{
    /*Types
    bool,char, float, double, void = used with pointer and functions
    modifiers= signed, unsigned ,short, long
    qualifiers = const, volatile, static

    bool , char= 1 bytes
    wchar_t , short = 2
    int,long,float = 4
    long long, double = 8
    Range of fundamental types.
    <climits>
    <cfloat>
    */
    std::cout << "Hello World!\n";
    //scalar types
    int i = 0;
    int j{1}; //uniform initialization
    char ch = 'a';
    bool flag = false; //true or false
    bool val = 0; //false
    float f = 1.28f;
    double d = 5371.234;
    
    //Vector types
    int arr[5] = {1,2,3,4,5};
    int arr1[5]{1,2,3,4,5}; //uniform initialization
    
    //std::ostream& std::istream
    //cout & cin
    //<iostream> header
    cout << "Hello world\n"<<45<<0.2f<<endl;
    /* int age;
    cout << "tell your age" << endl;
    cin >> age;
    cout << "Your age:" << age << endl;
    */
    char buff[512];
    cout << "What is your name?";
   /* cin >> buff;
    cout << "your name : " << buff << endl; // This prints only firstname, lastname after space is omitted
    */

   //so use getline,* using cin before getline ,the getline starts reading from newline giving improper result.
   // to avoid this error a dummy getline is used. Still not an elegant situation.
   // getline syntax:  
    cin.getline(buff, 64,'\n'); //stops reading when we press enter. reads upto 64 characters
    cout << "getline name is:" << buff << endl;
    
    //Function
    int x, y;
    cout << "enter 2 numbers:" << endl;
    cin >> x >> y;
    int res= Add(x, y);
    cout << res;

    Print('a');
    
    return 0;
}

