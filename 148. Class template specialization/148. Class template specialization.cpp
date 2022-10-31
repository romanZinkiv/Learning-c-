#include <iostream>
#include <string>

using namespace std;


template<typename T>
class Printer
{
public:
	void Print(T value)
	{
		cout << value << endl;
	}
};

template<>
class Printer<string>
{
public:
	void Print(string value)
	{
		cout << "___" << value << "___" << endl;
	}
};


int main()
{
	Printer<char> c;
	c.Print('#');
	Printer<int> i;
	i.Print(231);
	Printer<string> s;
	s.Print("Hello World!");

	return 0;
}