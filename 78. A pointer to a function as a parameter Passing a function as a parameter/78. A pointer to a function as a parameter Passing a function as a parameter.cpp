// 78. A pointer to a function as a parameter Passing a function as a parameter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

//тип функції(*ім"я вказівника)(специфікація параметрів)

void Foo1()
{
	cout << "void Foo 1()" << endl;
}

void Foo2()
{
	cout << "void Foo 2()" << endl;
}

int Foo3(int a)
{
	return a - 1;
}
int Foo4(int a)
{
	return a * 2;
}


string GetDataFromDB()
{
	return "Data from Database";
}
string GetDataFromWebServer()
{
	return "Data from Webserver";
}

void ShowInfo(string(*foo)())
{
	cout << foo() << endl;;
}

int main()
{

	void(*fooPointer)();

	fooPointer = Foo1;
	fooPointer();

	fooPointer = Foo2;
	fooPointer();

	int(*fooPointer2)(int);

	fooPointer2 = Foo3;
	cout << fooPointer2(5) << endl;

	fooPointer2 = Foo4;
	cout << fooPointer2(5) << endl;


	ShowInfo(GetDataFromDB);
	ShowInfo(GetDataFromWebServer);

	return 0;
}