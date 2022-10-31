#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

class IAction
{
public:
	virtual void Action() = 0;
};

class CatAction : public IAction
{
	virtual void Action() override
	{
		cout << "stroking the cat" << endl;
	}
};

class TeaAction : public IAction
{
	virtual void Action() override
	{
		cout << "drinking a tea" << endl;
	}
};

class DogAction : public IAction
{
	virtual void Action() override
	{
		cout << "walking with a dog" << endl;
	}
};

class SleepAction : public IAction
{
	virtual void Action() override
	{
		cout << "sleep" << endl;
	}
};

int main()
{

	int arr[] = { 1,2,3,4,5 };

	for (auto el : arr)
	{
		cout << el << '\t';
	}
	cout << endl << endl;

	//з цією штукою random_shuffle - постійно генерувати випадкові послідовності в колекції
	srand(time(NULL));
	//метод random_shuffle розташовує елементи колекції у випадковому порядку
	random_shuffle(begin(arr), end(arr)); // спосіб роботи схожий на ф-ю rand()

	for (auto el : arr)
	{
		cout << el << '\t';
	}
	cout << endl << endl;


	IAction* actionArr[] =
	{
		//так не працює
		//&CatAction(),
		//&DogAction(),
		//&TeaAction(),
		//&SleepAction()
		new CatAction(),
		new DogAction(),
		new TeaAction(),
		new SleepAction()
		//так теж можна
		//new CatAction,
		//new DogAction,
		//new TeaAction,
		//new SleepAction
	};

	for (auto& element : actionArr)
	{
		element->Action();
	}
	cout << endl;
	random_shuffle(begin(actionArr), end(actionArr));
	for (auto& element : actionArr)
	{
		element->Action();
	}


	return 0;
}