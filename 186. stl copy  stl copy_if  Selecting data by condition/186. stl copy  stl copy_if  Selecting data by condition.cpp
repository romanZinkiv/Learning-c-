#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Person
{
public:
	Person(string name, double score, int age)
	{
		this->Name = name;
		this->Score = score;
		this->Age = age;
	}

	//bool operator()(const Person& p)
	//{
	//	return p.Score > 180;
	//}

	string Name;
	double Score;
	int Age;
};

int main()
{

	vector<Person> people
	{
		Person("Vasya",181,17),
		Person("Petya",30,22),
		Person("Masha",179,19),
		Person("Dasha",200,25),
		Person("Katya",198,24),
		Person("Andriy",181,23),
		Person("Sergiy",50,30),
		Person("Ivan",150,40),
		Person("Ivan",179,53), //можна з ',' , а можна без 
	};
	vector<Person> result;

	//копіює вектор people в вектор result
	//copy(people.begin(), people.end(), back_inserter(result));

	//copy_if(people.begin(), people.end(), back_inserter(result), [](const Person& p)
	//	{
	//		return p.Score < 100;
	//		//return p.Name == "Ivan";
	//	});

	//cout << "Total number of elements:\t" << result.size() << endl;

	//for (auto element : result)
	//{
	//	cout << "Name\t" << element.Name << "\tScore:\t" << element.Score << endl;
	//}


	copy_if(people.begin(), people.end(), back_inserter(result), [](const Person& p)
		{
			return p.Age > 20;
			//return p.Age > 20 && p.Score > 140 && p.Name == "Ivan";
		});

	sort(result.begin(), result.end(), [](const Person& p1, const Person p2)
		{
			//return p1.Score > p2.Score;
			return p1.Name < p2.Name;
		});

	cout << "Total number of elements:\t" << result.size() << endl;
	for (auto element : result)
	{
		cout << "Name\t" << element.Name << "\tScore:\t" << element.Score << "\tAge:\t" << element.Age << endl;
	}


	return 0;
}