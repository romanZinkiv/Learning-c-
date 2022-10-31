#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;



int main()
{

	vector<int> v = { 2,3,4 };
	int v2[] = { 3,4,5 };
	int v3[] = { 2,3,4,5,6,7,8,9,10 };

	//метод accumulate поверне суму всіх елементів контейнера + початкова точка (точка відліку) arg3
	//від 3 параметру залежить, якого типу дані будуть акумулюватись в результаті (такого типу якого є arg3)
	int result = accumulate(v.begin(), v.end(), 10);
	//у просторі імен std є функції begin() i end(), які працюють аналогічно до object.begin() i object.end()
	//працює не лише з контейнерами STL
	int result2 = accumulate(begin(v2), end(v2), 0);  // = int result2 = accumulate(v.begin(), v.end(), 10);

	cout << "RESULT\t" << result << endl;
	cout << "RESULT\t" << result2 << endl << endl;


	auto result3 = accumulate(begin(v2), end(v2), 1, [](int a, int b)
		{
			return a * b;
		});
	//3 парам.ф-ї = 1;   a=1,b=3 -> a*b=3; a=3,b=4 -> a*b=12; a=12,b=5 -> a*b=60 (end of container). result: 60;
	cout << "RESULT\t" << result3 << endl << endl;


	//сума парних елементів
	auto result4 = accumulate(begin(v3), end(v3), 0, [](int a, int b)
		{
			if (b % 2 == 0)
				return a + b;
			else
				return a;
		});
	cout << "RESULT\t" << result4 << endl;

	//метод next() зсуває ітератор на крок вперед
	//від 3 параметру залежить, якого типу дані будуть акумулюватись в результаті (такого типу якого є arg3)
	string result5 = accumulate(next(begin(v3)), end(v3), to_string(v3[0]), [](string a, int b)
		{
			return a + "-" + to_string(b);
		});
	cout << "RESULT\t" << result5 << endl;



	return 0;
}