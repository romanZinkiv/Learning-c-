#include <iostream>

using namespace std;

class Component
{
public:
	Component(string companyName)
	{
		cout << "constructor Component  " << endl;
		this->companyName = companyName;
	}

	string companyName;
};

class GPU : public Component
{
public:
	GPU(string companyName) : Component(companyName)
	{
		cout << "constructor GPU  " << endl;
	}

};
class Memory : public Component
{
public:
	Memory(string companyName) : Component(companyName)
	{
		cout << "constructor Memory	" << endl;
	}
};

class GraphicCard : public GPU, public Memory
{
public:
	GraphicCard(string GPUCompanyName, string MemoryCompanyName) : GPU(GPUCompanyName), Memory(MemoryCompanyName)
	{
		cout << "constructor GraphicCard  " << endl;
	}
};



class Character
{
public:
	Character()
	{
		cout << "constructor Character  " << endl;
	}

	int HP;
};

class Orc : public virtual Character
{
public:
	Orc()
	{
		cout << "constructor Orc  " << endl;
	}
};
class Warrior : public virtual Character
{
public:
	Warrior()
	{
		cout << "constructor Warrior  " << endl;
	}
};

class OrcWarrior : public Orc, public Warrior
{
public:
	OrcWarrior()
	{
		cout << "constructor OrcWarrior  " << endl;
	}
};


int main()
{
	//GraphicCard gc("AMD", "Samsung");

	OrcWarrior orcW;
	
	return 0;
}
