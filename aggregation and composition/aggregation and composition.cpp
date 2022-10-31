#include <iostream>

using namespace std;

class Cap
{

public:
	string GetColor()
	{
		return color;
	}
private:
	string color = "red";
};
//манекен
class Model
{
public:
	void InspectModel()
	{
		cout << "My cap is " << cap.GetColor() << " color." << endl;
	}
private:
	Cap cap;
};

class Human
{
public:
	void Think()
	{
		brain.Think();
	}

	void InspectTheCap()
	{
		cout << "Cap is " << cap.GetColor() << " color." << endl;
	}

private:

	class Brain
	{
	public:
		void Think()
		{
			cout << "I think!" << endl;
		}
	};

	Brain brain;
	Cap cap;
};


int main()
{
	Human human;
	human.Think();
	human.InspectTheCap();

	Model m;
	m.InspectModel();

	return 0;
}
