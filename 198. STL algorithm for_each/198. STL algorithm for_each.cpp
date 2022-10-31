#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;


void Foo(int a)
{
	cout << a << endl;
}

int main()
{

	int arr[] = { 1,2,10,55 };

	//for_each(begin(arr), end(arr), Foo);
	// //передаємо за значенням, а якщо (auto &a : arr) - то по силці
	//for (auto a : arr)
	//{
	//	Foo(a);
	//}
	//передаємо за значенням, а якщо (int& a) - то по силці
	for_each(begin(arr), end(arr), [](int a)
		{
			cout << a << endl;
		});


	return 0;
}