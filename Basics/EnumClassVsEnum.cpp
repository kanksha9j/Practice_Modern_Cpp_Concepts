/*
This code demonstrates the differences between enum class (scoped enums) and traditional enums in C++.
The differences include scope, type safety, and implicit conversions.
Enum classes provide better type safety and avoid name clashes, while traditional enums allow implicit conversions to integers.
*/

#include <iostream>

using namespace std;

enum class Color { Red, Green = 2, Yellow = 2 };

enum class Car { Red, Green = 2, Yellow = 2 };

enum Colour { Red, Green, Yellow };

//enum Vehicle{Red,Green,Yellow}; //This will cause redefinition error because Red, Green, Yellow are already defined in Colour enum

enum Auto { Rot, Grun, Gelb };

//int main()
int EnumClassVsEnum()
{
    Color color = Color::Red;
    int col = Colour::Green;

	if (color == Color::Red) //Valid comparison between same enum class types
    {
        cout << "Red" << endl;
    }

	cout << Colour::Yellow << endl; //Valid usage of traditional enum, outputs 2

	//cout << Color::Yellow << endl; // Error: enum class cannot be output directly.
    // Use an explicit cast (e.g. static_cast<int>(Color::Yellow))
    // or overload operator<< for std::ostream if custom output is desired.
	
	if (Colour::Yellow == Auto::Gelb) //Gives only warning, comparison between different enum types
    {
        cout << "Yellow" << endl;
    }

    /*
	if (Color::Yellow == Car::Yellow) //error comparison between different enum class types
    {
        cout << "Yellow" << endl;
    }
    */

    return 0;
}
