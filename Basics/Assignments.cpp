#include<iostream>
using namespace std;


class InternalError
{
public:
	virtual const char* what() const throw()
	{
		return "internal";
	}
};

class DBError:public InternalError
{
public:
	virtual const char* what() const throw()
	{
		return "DB";
	}
};

class SQLError:public DBError
{
public:
	virtual const char* what() const throw()
	{
		return "SQL";
	}
};

int assignment()
//int main()
{
	char str[10] = "COMPUTER";
	cout << strlen(str);

	//Assignment 8
	/*
	const char* what() const throw()
	{
	}
	1.const char*: returns C style string
	const Indicates that this member function does not modify the object.
	throw() : indicates this function does not throw any exception. deprecated, use noexcept in C++11
	Even though SQLError is the most specific, InternalError is a base class, and it's checked first, so the exception is caught there.
	all three are matches for the SQL error
	2.catch(...) must be the last handler of catch statements otherwise compiler error
	3. You should specialize exactly for the type you intend to match. i.e <const char*> will not work for<char*> and vice versa
	*/

	try {
		throw SQLError();
	}
	catch (InternalError& e) {
		cout <<"i"<< e.what();
	}
	catch (DBError& e) {
		cout <<"d"<< e.what();
	}
	catch (SQLError& e) {
		cout <<"s"<< e.what();
	}
	return 0;
}