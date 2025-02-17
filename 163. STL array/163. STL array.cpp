﻿#include <iostream>
#include <array>
using namespace std;

//vector - обгортка для динамічного масиву
//array - обгортка для статичного масиву
//для того щоб створити об"єкт array чи статичний масив нам наперед(заздалегідь) 
//треба вказати із скількох елементів такий об"єкт/масив складатиметься

int main()
{
	//оскільки це статичний масив, то ні додати елементи, ні видалити елементи ми не можемо
	// 
	//array<arg1,arg2> - arg1 - тип колекції, arg2 - кількість елементів в колекції
	array<int, 4> arr = { 1,94,77,9 };
	//різниця між методом at() і [] у тому що [] - ніяк не перевіряються (вихід за межі масиву),
	//at() - контролює вихід за межі контейнеру (у випадку виходу за межі масиву -> throw exception)
	//можна використовувати блок try catch для того щоб обробити виключення, що кидає метод at()
	//у [] - при виході за межі масиву може відбутись все, що завгодно (буде непередбачуваний результат)
	cout << arr[0] << endl;
	cout << arr.at(0) << endl;
	//метод size() - повертає кількість елементів в масиві
	cout << arr.size() << endl << endl;
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}
	cout << endl;

	//метод front() - отримує доступ до першого елементу масиву
	cout << "front(): " << arr.front() << endl<<endl;

	//метод back() - отримує доступ до останнього елементу масиву
	cout << "back(): " << arr.back() << endl << endl;

	//метод fill(arg) заповнює масив значеннями arg, але в рамках розміру масиву(у стат.масиві - не зміниш розмір)
	arr.fill(-1);
	for(auto i:arr)
	{
		cout << i << endl;
	}



	try
	{
		arr.at(10);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}


	return 0;
}