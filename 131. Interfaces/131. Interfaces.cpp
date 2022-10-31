#include <iostream>

using namespace std;

class IBicycle
{
public:
	virtual void TwistTheWheel() = 0;
	void virtual Ride() = 0;
};

class SimpleBicycle : public IBicycle
{
public:
	void TwistTheWheel() override
	{
		cout << "method TwistTheWheel()	class SimpleBicycle" << endl;
	}
	void Ride() override
	{
		cout << "method Ride()	class SimpleBicycle" << endl;
	}
};

class SportBicycle : public IBicycle
{
public:
	void TwistTheWheel() override
	{
		cout << "method TwistTheWheel()	class SportBicycle" << endl;
	}
	void Ride() override
	{
		cout << "method Ride()	class SportBicycle" << endl;
	}
};

class Human
{
public:
	void RideOn(IBicycle& bicycle)
	{
		cout << "Twist the wheel" << endl;
		bicycle.TwistTheWheel();
		cout << "Ride" << endl;
		bicycle.Ride();
	}
};


int main()
{
	SimpleBicycle sb;
	SportBicycle sportB;

	Human h;
	//чому передаємо в метод з параметром IBicycle& bicycle
	//копію об"єкта - sb, а не адрес на об"єкт - &sb ???
	h.RideOn(sb);
	cout << endl << endl;
	h.RideOn(sportB);

	return 0;
}