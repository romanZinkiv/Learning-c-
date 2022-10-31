#include <iostream>

using namespace std;

class Human
{
private:
	string name;
public:
	string GetName()
	{
		return name;
	}

	void SetName(string name)
	{
		this->name = name;
	}
};
class Student : public Human
{
public:
	string group;
	void Learn()
	{
		cout << "I am learn!" << endl;
	}
};
class ExtramuralStudent : public Student
{
public:
	void Learn()
	{
		cout << "I go to university less often than a regular student!" << endl;
	}
};
class Professor : public Human
{
public:
	string subject;
};

class A
{
public:
	A()
	{
		cout << "Constructor of class A is called" << endl;
	}
	~A()
	{
		cout << "Destructor of class A is called" << endl;
	}
};
class B : public A
{
public:
	B()
	{
		cout << "Constructor of class B is called" << endl;
	}
	~B()
	{
		cout << "Destructor of class B is called" << endl;
	}
};
class C : public B
{
public:
	C()
	{
		cout << "Constructor of class C is called" << endl;
	}
	~C()
	{
		cout << "Destructor of class C is called" << endl;
	}
};

class A2
{
public:
	A2()
	{
		msg = "null";
	}
	A2(string msg)
	{
		this->msg = msg;
	}
	void PrintMsg()
	{
		cout << msg << endl;
	}

protected:
	string msg;
};
class B2 : public A2
{
public:
	B2() :A2() //=B2()
	{

	}
	B2(string msg) :A2(msg)
	{

	}
};

int main()
{
	//Student st;
	//st.Learn();
	//st.SetName("Anonim");
	//cout << st.GetName() << endl;
	//ExtramuralStudent extraSt;
	//extraSt.Learn();
	//extraSt.SetName("John Doe");
	//cout << extraSt.GetName() << endl;

	//C c;

	//B2 value;
	//B2 value2("message");
	//value2.PrintMsg();


	return 0;
}
