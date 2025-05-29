/*Type conversions :
* Done by casting
implicit: done by compiler
explicit : done by user
explicit conversions uses casting operators
*/

int typeConversions()
//int main()
{
	int a = 5,b=2;
	float f = a;//(implicit)
	f = a / b; //result is 2; loss of data ; int/int is int .decimal part is lost.
	float g = static_cast<float>(a / b);
	char* p = (char*) & a;  //c-style cast
	//char* q = static_cast<char>(&a);  //static cast does not allow this conversion between diff types. 
	//static cast checks whether the cast is valid or not.
	char* s = reinterpret_cast<char*>(&a); //forces the casting between different types same like c-style cast. 
	//*But one difference: c-style cast removes the qualifiers and re-interpret cast does. so c style cast can be prone to errors.

	const int x = 1;
	int* z = (int*) & x; //removes const qualifier
	//int* y = reinterpret_cast<int*>(&x); not allowed
	//instead you can use:
	z = const_cast<int*>(&x); //const_cast operator is specifically used to add or remove the const qualifier from a pointer or 
	//reference. It allows you to modify the constness of an object, but it does not change the underlying type or the actual
	//memory representation.

	//dynamic_cast

	//Type operator conversion 
	//written in Default&Delete

	return 0;
}