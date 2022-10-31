#include <iostream>
#include <vector>
using namespace std;

int main()
{

	vector<int> myVector = { 1,9,44,422,676,78 };

	//cout << myVector[1] << endl;

	//змінна it - ітератор, vector<int>::iterator - тип даних ітератора
	vector<int>::iterator it;

	//зв"язуємо ітератор з вектором
	//метод begin() - повертає (як результат роботи) ітератор.
	//ітератор саме такого типу який нам потрібен - vector<int>::iterator
	//it = myVector.begin();
	//*it = 1000;
	//it+=2;
	//it--;
	//cout << *it << endl;

	//метод end() - повертає ітератор, що вказує на наступний елемент, 
	//який йде після останнього елементу контейнера
	for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++)
	{
		cout << *it << endl;
	}
	cout << endl;
	//const_iterator - дає змогу зчитувати дані, але забороняє їх змінювати
	//for (vector<int>::const_iterator it = myVector.begin(); it != myVector.end(); it++)
	//{
	//	*it = 5;	// таке не спрацює
	//	cout << *it << endl;
	//}
	//метод begin() - повертає звичайний (не константний ітератор)
	//але завдяки наслідуванню і поліморфізму це працює
	//в ланцюгу наслідування звичайний ітератор знаходиться після константного ітератора,
	//тому він по суті являється теж і константним ітератором
	//метод cbegin() - повертає константний ітератор
	//метод cend() - повертає константний вказівник (може ітератор?), 
	//який йде після нашого контейнера
	//присвоїти в звичайний ітератор (::iterator) результат роботи cbegin() не вийде,
	//тому що ланцюг наслідування у нас іде не в тому порядку

	//reverse_iterator - дозволяє ітеруватись з кінця контейнера в початок (у зворотньому порядку)
	//rbegin() - повертає ітератор на кінець контейнера (останній елемент)
	//rend() - повертає ітератор на елемент перед початком (першим елементом) контейнера
	//for (vector<int>::reverse_iterator it = myVector.rbegin(); it != myVector.rend(); it++)
	//{
	//	cout << *it << endl;
	//}

	//функція advance(arg1, arg2) зсуває ітератор arg1 на вказану кількість елементів arg2
	vector<int>::iterator it2 = myVector.begin();
	cout << "it2: " << *it2 << endl;
	advance(it2, 3);
	cout << "advance(it2, 3): " << *it2 << endl << endl;

	//метод insert(arg1, arg2) - вставляє дані. arg1 - ітератор, куди буде поміщено нові дані, arg2 - дані
	//чомусь після виконання insert щось стається з ітератором, 
	//з ним більше неможливо працювати (повторно викликати insert не вдається)
	vector<int>::iterator it3 = myVector.begin();
	cout << endl << "insert -75 index advance(it=0, 5) = index 5 : " << endl;
	advance(it3, 5);
	myVector.insert(it3, -75);
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
	{
		cout << *i << endl;
	}

	//метод erase(arg) - видаляє дані, arg - ітератор, який вказує на позицію/індекс даних, що будуть видалені
	//метод erase(arg1, arg2) - видаляє дані в заданому діапазоні [arg1;arg2) - не включаючи arg2. 
	//arg1 - ітератор, який вказує на позицію з якої почнеться видалення даних включано з даними за цим ітер.
	//arg2 - ітератор, який вказує на позицію до якої видалятимуться дані не включаючи дані за цим ітер.
	//чомусь після виконання erase щось стається з ітератором, 
	//з ним більше неможливо працювати (повторно викликати erase не вдається)
	vector<int>::iterator itErase = myVector.begin();
	myVector.erase(itErase);
	cout << endl << "erase element 0: " << endl;
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
	{
		cout << *i << endl;
	}

	itErase = myVector.begin();
	cout << endl << "erase elements from [0 to 3) " << endl;
	myVector.erase(itErase, (itErase + 3));
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
	{
		cout << *i << endl;
	}


	return 0;
}