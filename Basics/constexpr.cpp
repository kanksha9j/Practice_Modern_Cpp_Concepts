//constexpr to evaluate value at compile time.
//better than #define or const int. 
//#define is not type safe, cannot be scoped,
//constexpr better for array size,templates.

#include<iostream>

#define PI 3.14;

constexpr double pi = 3.14;
