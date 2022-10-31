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

	vector<int> v = { 5,9,1,46,4,9,4 };

	//функція remove не видаляє вказаний елемент (елементи), а поміщає їх у кінець колекції, і повертає 
	//ітератор на позицію за останнім невиключеним елементом (вказує на перший виключений елемент)
	//по суті кажучи ми потрібні елементи збираємо в одну сторону, непотрібні в другу сторону і між ними
	//є відмітка де потрібні, де непотрібні (мається на увазі ітератор, що функція повертає)
	auto result = remove(v.begin(), v.end(), 9);
	//для того щоб видалити елементи потрібно викликати метод erase
	//метод erase(arg1,arg2) видаляє всі елементи з arg1 по arg2, включно з arg1 - [arg1,arg2]
	v.erase(result, v.end());

	for (auto i : v)
	{
		cout << i << endl;
	}
	cout << endl << endl;



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

	//auto result2 = remove_if(people.begin(), people.end(), [](const Person& p)
	//	{
	//		return p.Score < 180;
	//	});
	//people.erase(result2, people.end());
	people.erase(remove_if(people.begin(), people.end(), [](const Person& p)
		{
			//return p.Score < 180;
			//return p.Score < 150 && p.Age > 25;
			return p.Score < 150 || p.Age > 25;
		}), people.end());

	cout << "Total number of elements:\t" << people.size() << endl;
	for (auto element : people)
	{
		cout << "Name\t" << element.Name << "\tScore:\t" << element.Score << "\tAge:\t" << element.Age << endl;
	}
	cout << endl << endl;


	string str = "Text with few   spaces";
	cout << str << endl;

	str.erase(remove(str.begin(),str.end(), ' '), str.end());
	cout << str << endl;




	return 0;
}