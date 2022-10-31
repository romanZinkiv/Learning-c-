#include <iostream>
#include <vector>
#include <list>
//для роботи з list треба #include <list>
using namespace std;


template<typename T>
void PrintList(const list<T>& lst)
{
	for (auto i = lst.cbegin(); i != lst.cend(); ++i)
	{
		cout << *i << endl;
	}
}


int main()
{
	list<int> myList2 = { 99,15,99,64,979,99,99,99 };

	list<int> myList = { 15,64,979 };
	cout << "list(3 el) + push_back() + push_front()  : " << endl;
	myList.push_back(5);
	myList.push_front(151);
	list<int>::iterator it = myList.begin();
	//auto it = myList.begin();
	PrintList(myList);
	cout << endl;

	cout << "sort() : " << endl;
	myList.sort();
	PrintList(myList);
	cout << endl;

	cout << "pop_back() + pop_front() : " << endl;
	myList.pop_back();
	myList.pop_front();
	PrintList(myList);
	cout << endl;

	cout << "size() : " << myList.size() << endl << endl;

	//метод reverse() міняє положення елементів в контейнері в зворотньому порядку
	//приклад: list(el1,el2,el3) -> list.reverse() -> list(el3,el2,el1)
	myList.reverse();
	cout << "reverse() : " << endl;
	PrintList(myList);
	cout<<endl;

	it = myList.begin();
	//++it;
	//так не вийде зробити, бо ітератор у list не підтримує доступ до довільного індексу
	//it += 3;
	advance(it, 2);
	myList.insert(it, 232);
	cout << "insert() (index:2): " << endl;
	PrintList(myList);
	cout << endl;

	it = myList.begin();
	++it;
	myList.erase(it);
	cout << "erase() (index:1): " << endl;
	PrintList(myList);
	cout << endl;

	//метод remove(arg) - видаляє всі елементи arg в контейнері, якщо такі є. 
	//якщо нема, то нічого не відбудеться (метод нічого не зробить).  arg - дані (int,bool,double,class etc.)
	//myList.remove(99);

	//метод assign(arg1, arg2) заповнює контейнер елементами
	//arg1 - кількість елементів,  arg2 - дані (елемент) яким заповнюватиметься контейнер
	//перед тим як заповнити контейнер елементами, попередні елементи він видаляє (тобто очищує контейнер)
	myList.assign(3, 131312312);
	cout << "assign(args) : " << endl;
	PrintList(myList);
	cout << endl;

	//методом assign(arg1, arg2) можна скопіювати елементи одного ліста в інший ліст
	//list1, list2 -> list1.assign(list2.begin(), list2.end()) -> вміст 
	//list2 копіюється в list1 (від list1 не залишиться ні одного елементу)
	myList.assign(myList2.begin(), myList2.end());
	cout << "myList.assign(myList2.begin(), myList2.end()) : " << endl;
	PrintList(myList);
	cout << endl;

	//метод clear() очищає контейнер (видаляє всі елементив контейнері)
	myList.clear();
	cout << "clear()" << endl;
	PrintList(myList);


	cout << endl << endl << endl;
	//метод unique() - видаляє всі !послідовні! дублікати (ті що йдуть послідовно, один за одним)
	//list<int> myList2 = { 99,15,99,64,979,99,99,99 };
	myList2.unique();
	cout << "myList2.unique() : " << endl;
	PrintList(myList2);
	cout << endl;

	//метод remove(arg) - видаляє всі елементи arg в контейнері, якщо такі є. 
	//якщо нема, то нічого не відбудеться (метод нічого не зробить).  arg - дані (int,bool,double,class etc.)
	myList2.remove(99);
	cout << "remove(99) : " << endl;
	PrintList(myList2);
	cout << endl;

	return 0;
}