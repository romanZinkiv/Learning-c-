// 68 Условная компиляция. ifdef else endif if elif endif ifndef.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

#define DEBUG
#define CONSTANT 5

int main()
{
	setlocale(LC_ALL, "ru");

#ifdef DEBUG
	cout << "початок циклу" << endl;
#endif
	for (int i = 0; i < 4; i++)
	{
		cout << i << endl;
	}

#ifdef DEBUG
	cout << "кінець циклу" << endl;
#endif


#ifdef DEBUG
	cout << "debug defined" << endl;
#else
	cout << "debug not defined" << endl;
#endif

#ifndef DEBUG
	cout << "debug not defined 2" << endl;
#else
	cout << "debug defined 2" << endl;
#endif

#if CONSTANT > 4
	cout << "cout 1" << endl;
#elif CONSTANT == 5
	cout << "cout 2" << endl;
#endif

}
