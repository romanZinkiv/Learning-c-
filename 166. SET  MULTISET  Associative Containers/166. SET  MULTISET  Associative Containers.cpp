#include <iostream>
#include <set>
using namespace std;

//для того, щоб користуватись set i multiset , треба #include <set>
//set i multiset - дуже схожі між собою, різниця полягає в тому, що
//set - зберігає(додає) в колекцію лише унікальні елементи
//multiset - може зберігати декілька одинакових значень колекції


int main()
{
	//контейнер set не може змінити елемент, який в ньому знаходиться
	set<int> mySet;

	//значення мають бути унікальними, тобто не мають повторятись
	//set (завжди) зберігає лише унікальні значення
	//set не може зберігати два одинакових елемента
	mySet.insert(5);
	mySet.insert(1);
	mySet.insert(12);
	mySet.insert(12);
	mySet.insert(4);
	mySet.insert(-1);

	for (auto& item : mySet)
	{
		cout << item << endl;
	}
	cout << endl;

	set<int> mySet2 = { 1,44,6,-2,43 };
	for (auto& item : mySet2)
	{
		cout << item << endl;
	}
	cout << endl;

	set<int> mySet3;
	for (size_t i = 0; i < 20; i++)
	{
		mySet3.insert(rand() % 10);
	}
	for (auto& item : mySet3)
	{
		cout << item << endl;
	}
	cout << endl;

	set<int> mySet4 = { 5,45,35,11,86 };
	//метод find(arg) - повертає (як результат своєї роботи) ітератор на певний елемент arg в контейнері
	//якщо такого елемент нема, то верне ітератор end(), тобто верне ітератор на елемент, який знаходиться
	//після колекції (внікуда)
	//auto it = mySet.find(5); 
	//int value;
	//cout << "input value: ";
	//cin >> value;

	//if (mySet4.find(value) != mySet4.end())
	//{
	//	cout<<"value: "<<value<<" is found"<<endl;
	//}
	//else
	//{
	//	cout<<"value: "<<value<<" not found"<<endl;
	//}

	//метод erase(arg) - видаляє із сету елемент за значенням arg. якщо такий елемент був, то повертає 1 ,
	//якщо такого елементу в сеті немає то повертає 0

	//метод insert(arg) вставляє в сет елемент arg (якщо такого елементу в сеті немає)
	//повертає Tree<int, less<int>> - вертається два значення, в одному з цих значень зберігається
	//ітератор, що вказує на елемент в колекції після його додавання. в другому елементі пари зберігатиметься
	//булева змінна: якщо метод insert зміг додати елемент в колекцію, то поверне true ,
	//якщо метод insert не зміг додати елемент в колекцію, то поверне false


	//для того щоб змінити елемент сету треба видалити, елемент, який хочемо змінити і додати
	//в сет елемент на який хотіли змінити
	for (auto& item : mySet4)
	{
		cout << item << endl;
	}
	auto result = mySet4.erase(5);
	mySet4.insert(64);
	cout << "changed element 5 to 64 by using erase+insert : " << endl;
	for (auto& item : mySet4)
	{
		cout << item << endl;
	}
	cout << endl;



	//multiset дуже схожий на set, різниця в тому, що multiset може зберігати декілька одинакових
	//значень колекції
	multiset<int> myMultiset = { 1,1,66,16,48,99 };
	myMultiset.insert(1);

	cout << "multiset: " << endl;
	for (auto& item : myMultiset)
	{
		cout << item << endl;
	}
	cout << endl;

	//метод lower_bound(arg) приймає параметром arg елемент який ми шукаємо, 
	//і поверне ітератор на перший елемент який знайде (в multiset елементи можуть повторюватись)
	auto it1 = myMultiset.lower_bound(1);

	//метод upper_bound(arg) знайде і верне ітератор на наступний елемент 
	// після arg (а set/multiset - впорядковані колекції)
	auto it2 = myMultiset.upper_bound(1);

	//метод equal_range(arg) повертає діапазон чисел від lower_bound до upper_bound
	//повертає пару ітераторів, зо є результами роботи методів lower_bound і upper_bound з аргументом arg
	// (lower_bound(arg), upper_bound(arg))
	auto a = myMultiset.equal_range(1);


	return 0;
}