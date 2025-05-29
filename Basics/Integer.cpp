#include"Integer.h"
#include<vector>
using namespace ClassInteger;

Integer::Integer() {
	cout << "ClassInteger Constructor called" << endl;
	m_Value = new int(0);
}

Integer::Integer(int m_Val)
{
	cout << "ClassInteger Parameterised Constructor called" << endl;
	m_Value = new int(m_Val);
}

Integer::Integer(const Integer& obj)
{
	cout << "ClassInteger Copy Constructor called" << endl;
	m_Value = new int(*obj.m_Value);
}

Integer& Integer::operator=(const Integer& obj)
{
	cout << "ClassInteger Assignment operator called" << endl;
	//Check if obj same
	if (this != &obj)
	{
		//2.delete previous
		delete m_Value;

		//3.assign new
		m_Value = new int(*obj.m_Value);
	}

	return *this;
}

Integer::Integer(Integer&& obj) noexcept
{
	cout << "ClassInteger Move Constructor called" << endl;
	//1.Shallow copy
	m_Value = obj.m_Value;

	//2.null previous
	obj.m_Value = nullptr;
}

Integer& Integer::operator=(Integer&& obj) noexcept
{
	cout << "ClassInteger Move Assignment operator called" << endl;
	//1.check if same
	if (this != &obj)
	{
		//2.delete previous 
		delete m_Value;

		//3.Do shallow copy
		m_Value = obj.m_Value;

		//2. previous null
		obj.m_Value = nullptr;
	}
	return *this;
}

int Integer::GetValue() const
{
	return *m_Value;
}

Integer::~Integer()
{
	cout << "ClassInteger Destructor called" << endl;
	delete m_Value;
}

//int Integers()
////int main()
//{
//	Integer number1;
//	Integer number2(10);
//	Integer number3(number2);
//	cout << number3.GetValue() << endl;
//	number1 = number2 ;
//	cout << number1.GetValue() << endl;
//
//	cout << "Method 1:" << endl;
//	Integer number4(std::move(number2));
//	std::vector<Integer> vec;
//
//	cout << "Method 2:" << endl;
//	vec.push_back(42); //calls parameterized ,then move constructor
//	cout << "Method 2.1:" << endl;
//	vec.push_back(Integer(42)); //calls parameterized ,then move constructor
//
//	cout << "Method 3:" << endl;
//	number4=number3.GetValue();
//
//	number4 = 20;  //number4=number(20), so calls parameterised constructor then move assignment
//	return 0;
//}
