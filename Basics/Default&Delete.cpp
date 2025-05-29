#include<iostream>
using namespace std;

/*default can only be used onf function that can be synthesized by compiler;
It cannot be used on parameterized constructor.*/
class Integer {
	int m_Value{0};
public:
	//Force to generate default. with functions:destructor,copy constructor ,assignment operator.
	Integer() = default;
	
	//Commenting the default constructor. and initializing m_Value above. But gives erro because
	//you have defined constructor with parameter below.
	/*Integer() {
		m_Value = 0;
	}*/

	Integer(int value)       //explicit Integer(int value)
	{
		m_Value = value;
	}
	Integer(const Integer&) = default; //gernerated
	//delete can be used on any kind of function
    //Do not generate or use a copy constructor at all—even the default one.
	Integer& operator=(const Integer&) = delete;
	void SetValue(int value )
	{
		m_Value = value;
	}
	void SetValue(float value) = delete; //restrict from using float values

	int GetValue() const
	{
		return m_Value;
	}
	
	operator int()
	{
		cout << "operator int" << endl;
		return m_Value;
	}

	Integer operator+(const Integer& obj) const
	{
		cout << "operator+ called" << endl;
		Integer temp;
		temp.m_Value = m_Value + obj.m_Value;
		return temp.m_Value;
	}
};

class Product
{
	int m_Value=1;
public:
	
	operator Integer()
	{
		cout << "operator Integer" << endl;
		return m_Value;
	}
};

int IntegerFunction()
//int main()
{
	Integer i1;
	Integer i2(3);
	//Integer i3(i);  Gives error because have not allowed copy .
	i1.SetValue(23);
	//i1.SetValue(23.4f); gives error

	//explicit : does not allow implicit conversions like following:
	//if we write explicit for parameterized constructor.
	//Integer i5 = 5;         //will give error


	//type conversion operator
	Integer i4;
	int a = i4;
	cout << i4.GetValue() << endl;

	Product p1;
	Integer i6 = p1;
	return 0;
}