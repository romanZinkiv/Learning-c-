#include <iostream>
using namespace std;

// Функтор - це клас у якого перегружений оператор ()
//функтор - функціональний об"єкт

class MyFunctor
{
public:
	void operator()()
	{
		cout << "i'm functor " << count << endl;
		count++;
	}
	int operator()(int a, int b)
	{
		cout << "i'm functor2" << endl;
		return a + b;
	}
private:
	int count = 0;
};

class EvenFunctor
{
public:

	void operator()(int value)
	{
		if (value % 2 == 0)
		{
			evenSum += value;
			evenCount++;
		}
	}

	void ShowEvenSum()
	{
		cout << "sum of even numbers = " << evenSum << endl;
	}

	void ShowEvenCount()
	{
		cout << "quantity of even numbers = " << evenCount << endl;
	}

private:
	int evenSum = 0;
	int evenCount = 0;
};

int main()
{

	MyFunctor f;
	f();
	f();
	f();

	int result = f(5, 2);
	cout << "result = " << result << endl;

	cout << endl << endl;

	int arr[] = { 1,2,55,99,44,3,6 };
	EvenFunctor ef;

	for (auto element : arr)
	{
		ef(element);
	}
	ef.ShowEvenSum();
	ef.ShowEvenCount();

	return 0;
}