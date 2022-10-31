// 69 Условный тернарный оператор.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
	int a;
	cout << "input a ";
	cin >> a;

	//if(a < 10)
	//{
	//	cout << "a < 10" << endl;
	//}
	//else 
	//{
	//	if (a > 10)
	//	{
	//		cout << "a > 10" << endl;
	//	}
	//	else
	//	{
	//		cout << "a == 10" << endl;
	//	}
	//}
	
	a < 10 ? cout << "a < 10" << endl : a>10 ? cout << "a > 10" << endl : cout << "a == 10" << endl;
}
