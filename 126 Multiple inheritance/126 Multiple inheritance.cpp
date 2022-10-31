#include <iostream>

using namespace std;

class Car
{
public:
    //Car()
    //{
    //    cout << "Constructor Car called" << endl;
    //}
    //~Car()
    //{
    //    cout << "Destructor Car called" << endl;
    //}
    string str1 = "Car class field";
    void Drive()
    {
        cout << "I drive!" << endl;
    }
    void Use()
    {
        cout << "Car Use()" << endl;
    }
};

class Airplane
{
public:
    //Airplane()
    //{
    //    cout << "Constructor Airplane called" << endl;
    //}
    //~Airplane()
    //{
    //    cout << "Destructor Airplane called" << endl;
    //}
    string str2 = "Airplane class field";
    void Fly()
    {
        cout << "I fly!" << endl;
    }
    void Use()
    {
        cout << "Airplane Use()" << endl;
    }
};

class FlyingCar : public Car, public Airplane
{
public:
    //FlyingCar()
    //{
    //    cout << "Constructor FlyingCar called" << endl;
    //}
    //~FlyingCar()
    //{
    //    cout << "Destructor FlyingCar called" << endl;
    //}
};


int main()
{
    FlyingCar fc;

    //fc.Drive();
    //fc.Fly();
    //cout<<fc.str1<<endl;
    //cout<<fc.str2<<endl;

    //Car* ptrC = &fc;
    //Airplane* ptrA=&fc;

    ((Car)fc).Use();
    ((Airplane)fc).Use();

    return 0;
}