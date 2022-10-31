#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout << "allocated dynamic memory, class object A" << endl;
	}
	virtual ~A()
	{
		cout << "released dynamic memory, class object A" << endl;
	}

	//замість 2 кроків можна зробити так
	//virtual ~A() = 0 {};

	//чисто віртуальний деструктор (за 2 кроки)
	//virtual ~() = 0;	- 1 крок
};
//A::~A() {};	- 2 крок

class B : public A
{
public:
	B()
	{
		cout << "allocated dynamic memory, class object B" << endl;
	}
	~B() override
	{
		cout << "released dynamic memory, class object B" << endl;
	}
};

int main()
{
	B* bptr = new B;
	delete bptr;

	//A a;

	return 0;
}
