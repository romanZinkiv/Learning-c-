#include <iostream>

using namespace std;

class Human
{
public:
	Human(string Name)
	{
		this->Name = Name;
	}
	Human(string Name, int Age) : Human(Name)
	{
		this->Age = Age;
	}
	Human(string Name, int Age, int Weight) : Human(Name, Age)
	{
		this->Weight = Weight;
	}

private:
	string Name;
	int Age;
	int Weight;
};

int main()
{
	Human h("John Doe", 30, 80);

	return 0;
}