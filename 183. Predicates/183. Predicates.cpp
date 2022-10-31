#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Предикат
// це функція чи функтор, який повертає true або false
// (і відповідає на якесь поставлене завдання)

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


int main()
{

	//cout << GreaterThanZero(1) << endl;
	//cout << GreaterThanZero(-10) << endl;

	vector<int> v = { 1,-2,-55,9,8,2 };

	int result = count_if(v.begin(), v.end(), GreaterThanZero);

	//ptrdiff_t -> F12: typedef int		ptrdiff_t;
	cout << result << endl;

	int result2 = count_if(v.begin(), v.end(), LessThanZero);
	cout << result2 << endl;
	cout << endl;


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
	//за допомогою методу вектора front отримуємо перший елемент класу Person 
	// і передаємо його в якості предикату (функтор з перегруженою операцією () )
	result = count_if(people.begin(), people.end(), people.front());
	cout << result << endl;

	return 0;
}