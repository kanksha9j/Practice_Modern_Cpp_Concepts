
//rvalue are temporary objects .
//rvalue references allow these temporary objects to be moved instead of copied
// copying can be expensive for large arrays or containers.
//int&&x =5; here 5 is rvalue and x is rvalue reference.


#include <iostream>

//this is universal reference , it can take both lvalue and rvalue.
template <typename T>
void process(T&& arg) {
    // T&& is a "universal reference" here
    std::cout << "Processing: " << arg << std::endl;
}

void processValue(int&& x) {  // rvalue reference to an int
    std::cout << "Processing rvalue: " << x << std::endl;
}

void processValue(int& x) {  // lvalue reference to an int
    std::cout << "Processing lvalue: " << x << std::endl;
}

int rvalueref()
//int main() 
{
    int a = 10;
    processValue(a);          // Calls lvalue version
    processValue(20);         // Calls rvalue version
    return 0;
}