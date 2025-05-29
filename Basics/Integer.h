#pragma once
#include<iostream>
using namespace std;

namespace ClassInteger
{

class Integer
{
	int* m_Value;

public:
	Integer();
	Integer(int m_Val);
	Integer(const Integer& obj);
	Integer& operator=(const Integer& obj);

	Integer(Integer&& obj) noexcept;
	Integer& operator=(Integer&& obj) noexcept;

	int GetValue() const;
	~Integer();
};

}