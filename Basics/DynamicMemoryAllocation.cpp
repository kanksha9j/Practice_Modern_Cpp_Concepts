#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


//stack: local variables
//heap: allocated at runtime
//data section: allocated for global and static variables


int dynamemalloc()
//int main()
{

	//malloc - allocates memory
	//calloc - initializes to 0(fixed) and allocates memory
	//realloc - allocate larger chunk for current allocation
	//free - deallocate memory

	//write in C file
	int* p = (int*)malloc(sizeof(int)); //c++ file needs (int*)conversion
	// int*p = (int*)malloca(5*sizeof(int)) //for 5 array elements.
	*p = 5;
	cout << *p<<endl;
	free(p);
	p = NULL;
	int* q = (int*)calloc(1, sizeof(int));  //number of elements to allocate
	if (q == NULL)
	{
		return -1;
	}
	*q = 12;
	cout << *q<<endl;
	free(q);
	q = NULL;

	//new operator
	//new allocates on heap, delete - deallocates on heap
	int* r = new int(0);  //initialize to 0 //new throws exception when failed to allocate
	*r = 4;
	cout << *r << endl;
	delete r;
	r = nullptr;

	//malloc vs new
	//new can call constructors
	//returns void pointer that needs to be type casted.
	//malloc returns NULL on failure, new throws exception
    
	//new for arrays.
	int* s = new int[5];  
	for (int i = 0;i < 5;i++)
	{
		s[i] = i;
	}
	cout << *s << endl;
	delete[] s;
	s = NULL;

	int* t = new int[5] {1,2,3,4,5}; //uniform initialization
	delete[] t;
	t = NULL;

	char* u = new char[4];//allocate one extra byte for null terminator
	strcpy_s(u,4, "C++");   //dprecated: strcpy(u, "C++");
	cout << u << endl;    //***prints all characters till null terminator unlike int
	delete[] u;

	//new with 2D arrays
	int v[2][3]{//represted as continous array
		1,2,3,
		4,5,6
	};  //1,2,3,4,5,6

	v[0][1];

	/*int* p1 = new int[3];
	int* p2 = new int[3];

	int** pData = new int* [2];
	pData[0] = p1;
	pData[1] = p2;

	pData[0][1]=2;

	delete[]p1; // or delete [] pData[0]
	delete[] p2;  // or delete [] pData[1]
	delete[] pData;*/

	//this way is more efficient, as above takes 3 allocations. 
	//contigous 2d array
	int rows = 2, cols = 3;
	int* data = new int[rows * cols];

	// Access like 2D: data[row * cols + col]
	data[0 * cols + 1] = 2; // same as pData[0][1]

	//best practice would be to use vector of vector.

}