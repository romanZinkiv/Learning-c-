#include <iostream>
#include <vector>
using namespace std;

//vector - обгортка для динамічного масиву

int main()
{
	//методи, що працюють не через індекси, а через ітератори
	//insert(args) - додати елемент в вектор
	//erase(args) - видалити елемент з вектору

	//vector<int> myVector; // - пустий вектор/масив. size=0, capacity=0
	//так теж можна
	vector<int> myVector = { 2,44,77,9 };

	//створює вектор на arg1 (тут arg1=5) реально існуючих елементів. size() = arg1, capacity() = arg1, 
	//елементи масиву ініціалізовані другим параметром. значенняим за замовчуванняи, якщо 
	//другий параметр не вказано
	vector<int> myVector2(5, 55);
	cout << "vector2 capacity: " << myVector2.capacity() << endl;
	cout << "vector2 size: " << myVector2.size() << endl;
	//метод resize(arg1) - cтворює вектор на arg1 елементів і заповнює елементи вектору
	//значеннями arg2. значеннями за замовчуванням, якщо другий параметр не вказано
	//size() = arg1, capacity() = arg1
	myVector2.resize(8, -1);
	for (int i = 0; i < myVector2.size(); i++)
	{
		cout << myVector2[i] << endl;
	}
	cout << "vector2 capacity: " << myVector2.capacity() << endl;
	cout << "vector2 size: " << myVector2.size() << endl << endl;

	//push_back(arg) - додає елемент в кінець вектору 
	myVector.push_back(2);
	myVector.push_back(44);
	myVector.push_back(77);
	myVector.push_back(9);

	//буде помилка і це добре
	//myVector[10] = 55;
	//cout << myVector[10] << endl;
	//метод at() - практично те саме що і [], проте метод at() перевіряє вихід за межі вектора
	//і не дасть вийти за межі масиву, але він повільніший за []
	//cout << myVector.at(10) << endl;

	myVector[0] = 1000;
	cout << "vector capacity: " << myVector.capacity() << endl;
	cout << "vector size: " << myVector.size() << endl;
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << endl;
	}



	//pop_back() видаляє останній елемент із вектору
	myVector.pop_back();
	//capacity() - повертає вмістимість/ємність вектору, тобто реальний розмір внутрішнього масиву вектора
	cout << endl << "vector capacity: " << myVector.capacity() << endl;
	cout << "vector size: " << myVector.size() << endl;

	//метод reserve(arg) - вказує/змінює сapacity (запас), тобто реальний розмір внутрішнього масиву вектора
	myVector.reserve(100);
	cout << endl << "vector capacity: " << myVector.capacity() << endl;
	cout << "vector size: " << myVector.size() << endl;

	//метод shrink_to_fit() - змінює capacity значення size(), 
	//тобто на кількість реально зайнятих елементів внутрішнього масиву
	myVector.shrink_to_fit();
	cout << endl << "shrink_to_fit()" << endl;
	cout << "vector capacity: " << myVector.capacity() << endl;
	cout << "vector size: " << myVector.size() << endl;

	//метод empty() перевіряє чи є елементи в векторі/масиві
	//якщо вектор пустий, то повертає - true, якщо вектор не пустий, то повертає - false
	cout << endl << "vector empty: " << myVector.empty() << endl;


	//метод clear() очищує масив / видаляє всі елементи із масиву
	cout << endl << "clear()" << endl;
	myVector.clear();
	cout << endl << "vector capacity: " << myVector.capacity() << endl;
	cout << "vector size: " << myVector.size() << endl;
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << endl;
	}
	cout << endl << "vector empty: " << myVector.empty() << endl;

	return 0;
}