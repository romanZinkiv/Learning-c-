#include <iostream>
#include <vector>
//using namespace std;

int main()
{

	std::vector<int> myVector = { 11,46,9 };

	std::vector<int>::iterator it = myVector.begin(); // =/еквівалентно  auto it2 = myVector.begin();


	//тип даних який буде в змінній it2 визначається на основі того, який тип даних повертає
	//вираз після оператора =  (метод begin())
	auto it2 = myVector.begin();

	//for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++)
	for (auto it = myVector.begin(); it != myVector.end(); it++)
	{
		std::cout << *it << std::endl;
	}


	return 0;
}