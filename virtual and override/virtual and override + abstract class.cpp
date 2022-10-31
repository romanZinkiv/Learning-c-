#include <iostream>

using namespace std;

//we can change/rename method Shoot() to Use() 
class Weapon
{
public:
	virtual void Shoot() = 0;

	void Foo()
	{
		cout << "Foo()" << endl;
	}
};

class Gun : public Weapon
{
public:
	//virtual void Shoot()
	void Shoot() override
	{
		cout << "BANG!" << endl;
	}
};
class SubmachineGun : public Gun
{
public:
	void Shoot() override
	{
		cout << "BANG! BANG! BANG!" << endl;
	}
};
class Bazooka : public Weapon
{
public:
	void Shoot() override
	{
		cout << "BOOM!!!" << endl;
	}
};
class Knife : public Weapon
{
public:
	void Shoot() override
	{
		cout << "VJUH!" << endl;
	}
};
class Player
{
public:
	void Shoot(Weapon* weapon)
	{
		weapon->Shoot();
	}
};

int main()
{
	//якщо не використовувати virtual + override
	// знизу закоментована реалізація необхідних класів
	//SubmachineGun s;
	//s.Gun::Shoot();

	//Gun gun;
	//SubmachineGun machinegun;
	//Gun* weapon1 = &gun;
	//Gun* weapon2 = &machinegun;
	//weapon1->Shoot();
	//weapon2->Shoot();

	//important
	Gun gun;
	SubmachineGun machinegun;
	Bazooka bazooka;
	Knife knife;
	Player player;
	player.Shoot(&gun);
	player.Shoot(&machinegun);
	player.Shoot(&bazooka);
	player.Shoot(&knife);
	knife.Foo();
	machinegun.Foo();


	return 0;
}



//class Gun
//{
//public:
//	void Shoot()
//	{
//		cout << "BANG!" << endl;
//	}
//};
//class SubmachineGun :public Gun
//{
//public:
//	void Shoot()
//	{
//		cout << "BANG! BANG! BANG!" << endl;
//	}
//};