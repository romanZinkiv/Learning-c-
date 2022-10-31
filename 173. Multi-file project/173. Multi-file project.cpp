#include <iostream>
#include "Sum.h"
#include "MyClass.h"
#include <string>

using namespace std;
//using namespace myNamespace;

int main()
{

	cout << Sum(2, 3) << endl;

	myNamespace::MyClass m;
	char str[] = "Hello World!";
	m.PrintMessage(str);
	int a = 5;
	double b = 6.7;
	//bool m = true;
	cout << a + str;


	return 0;
}