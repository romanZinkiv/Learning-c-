#include <iostream>
#include <string>
#include <map>

using namespace std;

//map, multimap - контейнери схожі на set, multiset
//теж впорядковані, теж мають структуру бінарного дерева,
//але на відміну від set, multiset, які просто зберігають одне значення і строяться
//у вигляді бінарного дерева логічно, контейнери map, multimap зберігають не просто якесь одне значення,
//а пару значень (ключ і значення)
//map - може зберігати лише унікальні значення
//multimap - може зберігаи дублюючі значення
//побудова дерева (і впорядкування, і побудова бінарного дерева) відбувається на основі ключа, 
//а значення до нього просто підв"язується. як результат маємо певний словник

int main()
{
	////pair<ключ, значення>
	////pair<int, string> p(1, "telephone");
	////перший елемент пари (ключ)
	//cout << p.first << endl;
	////другий елемент пари (значення)
	//cout << p.second << endl;

	map<int, string> myMap;

	//метод insert(arg) вставляє пару в колекцію і приймає готову пару arg
	//метод insert або копіює готовий об"єкт, або переміщує його
	//пару можна створити так:
	myMap.insert(make_pair(3, "tel"));
	myMap.insert(pair<int, string>(2, "laptop"));
	//метод emplace(arg1,arg2) : arg1 - ключ, arg2 - значення. за допомогою цього методу можна просто додати
	//потрібні елементи через кому (,) не вказуючи, що це якась пара і не використовуючи метод make_pair
	//метод emplace, просто, створює об"єкт в момент виконання, тобто, по суті, він має працювати
	//трохи швидше (, ніж insert i make_pair)
	//метод emplace повертає пару: (arg1,arg2), де arg1 - ітератор на пару з таким ключом,
	//arg2 - true, якщо пару додано, false - якщо пара не була доданою ,бо в контейнері вже є пара з таким ключом
	myMap.emplace(1, "monitor");

	myMap.emplace(22, "keyboard");
	//цей елемент не буде додано, бо вже є пара з ключом 22
	myMap.emplace(22, "adasd");

	for (auto item : myMap)
	{
		cout << item.first << " : " << item.second << endl;
	}

	//метод find(arg) шукає в контейнері пару з ключом arg, якщо така пара знаходиться в контейнері,
	//то метод повертає ітератор, що вказує на цю пару, якщо такої пари немає, 
	//то повертає end() - повертає результатом своєї роботи вказівник на якусь область в пам"яті,
	//яка знаходиться за контейнером (після нього), тобто в нікуди, тобто шуканий елемент не знайдено
	auto it = myMap.find(22);
	if (it != myMap.end())
	{
		cout << "it->second : " << it->second << endl;
	}
	else
	{
		cout << "element not found" << endl;
	}


	//для контейнера map перегружений оператор [], параметром оператор [] приймає такий же тип даних
	//який йому вказали для ключа
	//як результат вернеться пара цього ключа, якщо він там був знайдений
	//якщо в контейнері нема буде пари з таким ключом, який буде вказано в [], то
	//буде створено нова пара елемент контейнера з ключом всередині [] і значенням за замовчування
	//типу значення у парі
	//за допомогою оператора [] зручно додавати нові значення
	cout << myMap[10] << endl;
	for (auto item : myMap)
	{
		cout << item.first << " : " << item.second << endl;
	}

	map<string, int> map2;

	map2.emplace("Peter", 400);
	map2.emplace("Louis", 2600);
	map2.emplace("Joe", 4100);
	cout << "map2[\"Peter\"] : " << map2["Peter"] << endl;
	//за допомогою оператора [] зручно додавати нові значення чи міняти вже наявні
	map2["Peter"] = -300;
	cout << "map2[\"Peter\"] : " << map2["Peter"] << endl << endl;
	map2["Stewie"] = 9797;
	for (auto item : map2)
	{
		cout << item.first << " : " << item.second << endl;
	}

	//метод at(arg) arg-ключ працює схожим чином до оператора [], за його допомогою можна змінити 
	// елемент (значення), якщо пари з таким ключом в контейнері немає, то 
	//викличення виключення (throw std::out_of_range (exception))
	try
	{
		map2.at("Mag") = 3;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
		cout << "key is missing at container map" << endl;
	}

	//метод erase(arg) видаляє пару за ключем arg
	//видалення відбувається по ключу
	//повертає true - якщо такий елемент був в контейнері, повертає false - якщо такого елементу не було
	auto a = map2.erase("Peter");



	multimap<string, int> myMultimap;
	myMultimap.emplace("Homer", 1121);
	myMultimap.emplace("Homer", 565);
	myMultimap.emplace("Marge", 2312);
	myMultimap.emplace("Skiner", 3400);
	cout << endl << "myMultimap: " << endl;
	for (auto item : myMultimap)
	{
		cout << item.first << " : " << item.second << endl;
	}

	//в multimap не перегружений оператор [] і відсутній метод at()
	//cout << "myMultimap[\"Homer\"] : " << myMultimap["Homer"] << endl;    // - error


	return 0;
}