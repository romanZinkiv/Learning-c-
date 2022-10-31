#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<typename T>
void PrintList(const list<T>& lst)
{
	for (auto i = lst.cbegin(); i != lst.cend(); ++i)
	{
		cout << *i << endl;
	}
}

int main()
{

	//int arr[] = { 5,11,94,99,44 };
	//for each (int var in arr)
	//{
	//	cout << var << endl;
	//}
	//у змінну var поміщаються не по силці, а за значенням елементи колекції arr
	//тобто ми можемо отримати значення, але не можемо ті значення в колекції змінювати,
	//бо отримуємо доступ не до елемента колекції (по силці), а до його копії (присвоєну у змінну (var))
	//for (auto var : arr)
	//{
	//	var = -1;
	//	cout << var << endl;
	//}	
	//cout << endl << endl;
	//for (auto var : arr)
	//{
	//	cout << var << endl;
	//}
	//cout << endl << endl;
	////ось у такий спосіб ми зможемо редагувати дані нашої колекції, бо елементи передаються по силці
	//for (auto& var : arr)
	//{
	//	var = -1;
	//	cout << var << endl;
	//}
	//cout << endl << endl;
	//for (auto var : arr)
	//{
	//	cout << var << endl;
	//}
	//якщо потрібно передавати елементи по силці, але їх не можна міняти, то допоможе ключове слово const
	//for (const auto& var : arr)
	//{
	//	//var = -1;
	//	cout << var << endl;
	//}

	list<int> myList = { 1,99,4,94,799,44,6 };
	for (const auto& var : myList)
	{
		cout << var << endl;
	}

	return 0;
}