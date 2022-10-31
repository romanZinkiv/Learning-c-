#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;


int main()
{

	int arr[] = { 1,2,2,2,5,4,4 };
	vector<int> v = { 1,2,2,2,5,4,4 };
	vector<int> v2;
	list<int> l;

	//метод unique всі елементи, що повторяються переміщає в кінець колекції і повертає ітератор на межу між
	//потрібними і не потрібними елементами, тобто повертає ітератор на перший елемент, що повторяється
	auto result = unique(begin(arr), end(arr));
	//виводимо лише унікальні елементи
	for_each(begin(arr), result, [](int a)
		{
			cout << a << endl;
		});
	cout  << endl;

	//видаляємо неунікальні елементи з вектору
	//auto resultVector = unique(begin(v), end(v));
	//v.erase(resultVector, end(v));
	//for (auto i : v)
	//{
	//	cout << i << endl;
	//}
	//cout << endl;

	//метод unique_copy(arg1,arg2,arg3) копіює унікальні елементи з arg1 в інший (новий) контейнер arg2
	//третім параметром arg3 передаємо той контейнер в яким хочемо поміщати елементи, але не просто контейнер,
	//а контейнер завернутий в функцію, яка поміщатиме в наш контейнер елементи (back_inserter) 
	unique_copy(begin(v), end(v), back_inserter(l));

	for (auto a : v)
	{
		cout << a << '\t';
	}
	cout << endl;
	for (auto a : /*v2*/l)
	{
		cout << a << '\t';
	}
	cout << endl;

	return 0;
}