#include <iostream>

using namespace std;

class Msg
{
public:
	Msg(string msg)
	{
		this->msg = msg;
	}
	virtual string GetMsg()
	{
		return msg;
	}

private:
	string msg;
};
class BracketsMsg : public Msg
{
public:
	BracketsMsg(string msg) : Msg(msg)
	{

	}
	string GetMsg() override
	{
		//спосіб викликати віртуальний метод
		//базового класу або метод якогось з класів предків
		return "[" + ::Msg::GetMsg() + "]";
		// Msg::GetMsg() - так теж працює (є помилки при компіляції, але програма нормально працює)
	}
};
class Printer
{
public:
	void Print(Msg* msg)
	{
		cout << msg->GetMsg() << endl;
	}
};

int main()
{
	BracketsMsg m("Hi!");

	Printer p;
	p.Print(&m);


}
