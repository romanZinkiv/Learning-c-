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

void Baz(int a)
{
	cout << "BAZ" << endl;
}

void DoWork(vector<int>& vc, function<void(int)> f)
{
	for (auto el : vc)
	{
		f(el);
	}
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

	vector<int> vc = { 1,51,4,10,44,98,8,12,22,29,49 };

	//function<void(int)> f;
	//ЛЯМБДА/АНОНІМНА ФУНКЦІЯ - ЦЕ ФУНКЦІЯ, ПОКИ МИ ЇЇ НЕ ВИКЛИЧЕМО - ВОНА НЕ СПРАЦЮЄ (не працюватиме)
	//f = [](int a)
	//{
	//	cout << "called anonymous function with parameter - " << a << endl;
	//};
	//DoWork(vc, f);
	//можна і так
	//DoWork(vc, [](int a)
	//	{
	//		cout << "called anonymous function with parameter - " << a << endl;
	//	});

	DoWork(vc, [](int a)
		{
			if (a % 3 == 0)
			{
				cout << "lambda	" << a << endl;
			}
		});


	int p = 0;

	//якщо ми не передаємо по силці (&), то змінювати (зовнішній) контекст в анонімній ф-ї ми не можемо
	auto ff = [&p]()
	{
		p = 5;
	};
	ff();
	cout << "p = " << p;


	//тип лямбда/анонімної функції залежить від ключового слова return, що ним повернемо
	// того типу і буде функція
	//якщо лямбда/анонімна функція нічого не повертає, то її тип void (тип возвращаємого значєнія)
	auto func = []()
	{
		return true;
		//return a + b;
	};
	auto q = func();

	return 0;
}