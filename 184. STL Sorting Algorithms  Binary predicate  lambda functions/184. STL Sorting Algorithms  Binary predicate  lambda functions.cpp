#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool GreaterThanZero(int a)
{
	return a > 0;
}

bool LessThanZero(int a)
{
	return a < 0;
}

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

bool MyPred(int a, int b)
{
	return a > b;
}


int main()
{

	vector<int> v = { 9,4,94,6,1,3,7 };

	//sort(v.begin(), v.end(), [](int a, int b)
	//	{
	//		return a > b;
	//		//return a < b;
	//	});
	for (auto element : v)
	{
		cout << element << endl;
	}
	cout << endl;

	sort(v.begin(), v.end(), MyPred);

	for (auto element : v)
	{
		cout << element << endl;
	}
	cout << endl << endl;

	const int SIZE = 7;
	int arr[SIZE] = { 12,4,9,66,14,32,17 };
	sort(arr, arr + SIZE, [](int a, int b)
		{
			return a > b;
		});
	for (auto element : arr)
	{
		cout << element << endl;
	}


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
	for (auto element : people)
	{
		cout << "Name:\t" << element.Name << "\tScore:\t" << element.Score << endl;
	}
	cout << endl;
	sort(people.begin(), people.end(), [](const Person p1, const Person p2)
		{
			//return p1.Name < p2.Name;
			return p1.Score > p2.Score;
		});
	for (auto element : people)
	{
		cout << "Name:\t" << element.Name << "\tScore:\t" << element.Score << endl;
	}

	return 0;
}