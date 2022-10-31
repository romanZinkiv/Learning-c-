#include <iostream>
#include <algorithm>
#include <vector>
#include<list>
using namespace std;

int main()
{

	//int arr[] = { 10,3,4,5,7,11 };
	//list<int> arr = { 10,3,4,5,7,11 };

	//алгоритм просто перевіряє перебування під тим ж самими індексами тих самих елементів (перевірка на ==)
	//при цьому колекції можуть містити ті самі ж елементи, але якщо вони знаходитимуться на різних місцях
	//то метод equal вважатиме що це різні колекції
	vector<int> arr = { 11,3,4,5,7,10 };	//для методу equal
	vector<int> arr2 = { 10,3,4,5,7,11 };	//це дві різні колекції

	bool result = equal(begin(arr), end(arr), begin(arr2), end(arr2));
	cout << result << endl;

	sort(begin(arr), end(arr));
	sort(begin(arr2), end(arr2));

	result = equal(begin(arr), end(arr), begin(arr2), end(arr2));
	cout << result << endl;

	//у такий спосіб метод equal може повернути невірну інформацію, якщо перший контейнер менший за другий
	//bool result = equal(begin(arr), end(arr), begin(arr2));


	vector<int> v1 = { 11,3,4,5,7,10 };
	vector<int> v2 = { 1,3,4,5,7,10 };

	//метод mismatch перевіряє на рівність послідовності (колекції), але крім того що він перевіряє послідовності 
	//на рівність, якщо він знайшов елементи які не рівні, то він повертає пару ітераторів, які вказують
	//на ці елементи
	auto result2 = mismatch(begin(v1), end(v1), begin(v2), end(v2));

	if (result2.first == end(v1) && result2.second == end(v2))
	{
		cout << "+" << endl;
	}
	else
	{
		cout << "-" << endl;
	}


	return 0;
}