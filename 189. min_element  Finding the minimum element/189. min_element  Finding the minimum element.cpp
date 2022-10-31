#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
using namespace std;

int main()
{

	vector<int> v = { 10,1,-55,11,13,58 };
	list<int> lst = { 4,7,77,-3,44,73 };
	const int SIZE = 6;
	int arr[SIZE] = { 10,1,-55,-111,13,58 };

	//метод min_element повертає ітератор, що вказує на найменший елемент колекції
	auto result1 = min_element(v.begin(), v.end());
	cout << *result1 << endl;
	auto result2 = min_element(lst.begin(), lst.end());
	cout << *result2 << endl;
	auto result3 = min_element(arr, arr + SIZE);
	cout << *result3 << endl;

	auto result4 = minmax_element(lst.begin(), lst.end());
	cout << "min: " << *result4.first << "\tmax: " << *result4.second << endl;



	return 0;
}