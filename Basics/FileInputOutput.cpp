#include<iostream>
#include<string>
#include<fstream>

using namespace std;

/*
1. 3 classes for file input output support
ofstream: write to output stream
ifstream: read from input stream
fstream: write/read stream
include <fstream> header

3 classes for stream input output support
ostream :write
istream :read
stringstream: read/write

little endian: a byte order in which the LSB of a multi-byte data value is stored at the lowest memory address, 
while the MSB is stored at the highest memory address
*/

void Write()
{
	std::ofstream out("data.txt"); //creates data file and associates with out fstream object, out cannot be used for reopening file
	out << "hello";  // No std::endl
	out.close();

	// Step 2: Reopen with ios::ate and write "world" immediately after
	//out| app = open file for writing and append at end
	std::ofstream appendFile("data.txt", std::ios::out | std::ios::app); //needs to use another object to reopen file. or else use oftsream out; and then open{}
	if (appendFile.is_open()) {
		appendFile << "world";  // Again, no std::endl
		appendFile.close();
	}
	else {
		std::cerr << "Failed to reopen file." << std::endl;
	}

	std::ofstream end;                                   //creates object without any file and can be reused for reopening file.
	end.open("data.txt", std::ios::out | std::ios::app); //open the file

	string msg{"This is Akanksha"};
	for (char ch : msg)
	{
		end.put(ch);
	}
	cout << "This is current position while writing:" << end.tellp() << endl;
	end.close();
}

void Read()
{
	std::ifstream in{ "data.txt" };
	if (!in)
	{
		cout << "file not found" << endl;
		return;
	}

	string message;
	getline(in, message);
	cout << message;

	cout << "The current position is " << in.tellg() << endl; //-1 means: You read past the end (EOF), or there was a read error
	
	//Clear EOF flag before seeking, as getline marks eof after reading all stream.
	in.clear();
	in.seekg(10,std::ios::beg);
	cout << "The current position is " << in.tellg() << endl;  //tellg gives get pointer position.

	char ch{};
	while (in.get(ch))
	{
		cout << ch;
	}

	in.close();
}

int FileInputOutput()
//int main()
{
	std::string filename{ "C:\temp\filename.txt" };
	cout << filename << endl;
	filename = "C:\\temp\\filename.txt";
	cout << filename << endl;
	filename = R"("C:\temp\filename.txt)" ;  //raw string ignores escape sequences like \n, \t, \\ 
	cout << filename << endl;
	filename = R"MSG("C:\\temp\filename.txt")MSG"; // MSG is custom delimeter, which takes )" and whatever that contains in MSG
	cout << filename << endl;
	Write();
	Read();
}