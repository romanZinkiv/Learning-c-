#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Person
{
public:
	Person(string name, double score)
	{
		this->Name = name;
		this->Score = score;
	}

	bool operator()(const Person& p)
	{
		return p.Score > 180;
	}

	string Name;
	double Score;
};


int main()
{

	vector<int> v = { 6,4,4,12,1,2,7 };
	vector<int> v2 = { 6,4,4,12,2,1 };

	//find(arg) - дозволяє вияснити чи є в колекції якийсь конкретний елемент (arg)
	//повертає ітератор, що вказує на елемент, якщо такий елемент присутній і на 
	//кінець колекції (після останнього елементу (end())), якщо такого елементу немає 
	//auto result1 = find(v.begin(), v.end(), 12);
	//cout << *result1 << endl;
	auto result2 = find(v.begin(), v.end(), 12);
	if (result2 == v.end())
	{
		cout << "-" << endl;
	}
	else
	{
		cout << "+" << endl;
	}

	//функція  find_if  повертає ітератор, що вказує на елемент, якщо такий елемент присутній і на 
	//кінець колекції (після останнього елементу (end())), якщо такого елементу немає 
	// (у нашому випадку, коли хоч одне число буде парним)
	auto result3 = find_if(v2.begin(), v2.end(), [](int a)
		{
			return a % 2 == 0;
			//return a < 0;
		});
	if (result3 == v2.end())
		cout << "-" << endl;
	else
		cout << "+" << endl;
	//реалізація функції find за допомогою find_if : замість цифри 6 потрібно вставляти елемент, що шукається
	//auto result3 = find_if(v.begin(), v.end(), [](int a)
	//	{
	//		return a == 6;
	//	});

	//find_if_not - якщо предикат хоч раз верне false - то вертає ітератор на цей елемент, інакше на end()
	auto result4 = find_if_not(v2.begin(), v2.end(), [](int a)
		{
			return a % 2 == 0;
			//return a < 0;
		});
	if (result4 == v2.end())
		cout << "-" << endl;
	else
		cout << "+" << endl;
	cout << endl << endl;



	vector<Person> people
	{
		Person("Vasya",181),
		Person("Petya",30),
		Person("Masha",179),
		Person("Dasha",200),
		Person("Katya",198),
		Person("Andriy",181),
		Person("Sergiy",50),
		Person("Ivan",150), //можна з ',' , а можна без 
	};
	auto result5 = find_if_not(people.begin(), people.end(), [](Person p)
		{
			//return p.Name == "Kataya";
			//return p.Score > 100 && p.Name == "Dasha";
			return p.Score = 100 || p.Name == "Dasha";
		});
	if (result5 == people.end())
		cout << "-" << endl;
	else
		cout << "+" << endl;

	return 0;
}