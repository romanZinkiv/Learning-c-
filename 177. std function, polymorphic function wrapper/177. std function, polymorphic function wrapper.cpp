#include <iostream>
//для ви користання треба підключити #include <functional>
#include <functional>
#include <vector>
using namespace std;

//	std::function

//Немного не понимаю, зачем это нужно, если вместо класса function можно 
// использовать typedef и указатель на функцию
//typedef void(*FUNC)(int)
//Результат будет таким же, просто реализация без сторонних инклудов
//или я ошибаюсь ?

void Foo()
{
	cout << "Foo()" << endl;
}

void Bar()
{
	cout << "=====Bar()=====" << endl;
}

int Sum(int a, int b)
{
	return a + b;
}


void Foo2(int a)
{
	if (a > 10 && a < 40)
	{
		cout << a << endl;
	}
}

void Bar2(int a)
{
	if (a % 2 == 0)
	{
		cout << a << endl;
	}
}

void DoWork(vector<int>& vc, function<void(int)> f)
{
	for (auto el : vc)
	{
		f(el);
	}
}

void Baz(int a)
{
	cout << "BAZ" << endl;
}

void DoWork2(vector<int>& vc, vector<function<void(int)>> funcVector)
{
	for (auto el : vc)
	{
		for (auto fel : funcVector)
		{
			fel(el);
		}
	}
}


int main()
{

	//function<void()> f;
	//f = Foo;
	//f();
	//f = Bar;
	//f();

	//function<int(int, int)> f2;
	//f2 = Sum;
	//cout << f2(17, 19) << endl;

	vector<int> vc = { 1,51,4,10,44,98,8,12,22,29,49 };
	DoWork(vc, Foo2);
	cout << endl;
	DoWork(vc, Bar2);
	cout << endl << endl;

	cout << "DoWork2 :" << endl;
	vector<function<void(int)>> fVector;
	fVector.emplace_back(Foo);
	//fVector.emplace_back(Bar);
	//DoWork2(vc, fVector);

	return 0;
}