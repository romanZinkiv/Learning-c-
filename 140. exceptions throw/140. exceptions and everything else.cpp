#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//У меня объект ex не видит метод getDataState(). Хотя он находится модификаторе доступа public. 
//А также время от времени подчеркивает базовый класс exception как несуществующий
//Тоже столкнулся с такой ошибкой.У меня она пропала после того, как убрал const из catch, 
//т.е: catch (MyException& ex).Не совсем понял, с чем это связано
//P.S.Всё решается довольно просто(я фиг знаю почему так, но всё же.Не помню такой темы 
//с const и методами класса).Надо после метода GetDataState() написать const, то есть 
//вот так : int GetDataState() const { return this->dataState; }
//Кстати + у автора у самого нет const перед MyException & ex(я только сейчас заметил), тогда 
//всё решается первым способам(если вы просто написали случайно const, или не убирали его 
//после того, как переименовали exception в My...), но для себя можно и вторым способом))

//я сейчас посмотрел и был очень удивлён тому, почему так получается.
//Оказывается у константного объекта мы можем вызывать ТОЛЬКО константные методы, 
//иначе другие методы даже не будут проверяться на то, есть ли в нём способ 
//изменения константного объекта или нет.Проще говоря надо писать константный 
//метод(слово const после параметров), потому что у нас константный объект.
//На эту тему есть отличный урок на Ravesli.Называется "Классы и const в C++" 123 урок

class MyException : public exception
{
public:
	MyException(const char* msg, int dataState) : exception(msg)
	{
		this->dataState = dataState;
	}
	//look top comment
	int GetDataState() const
	{ 
		return dataState; 
	}
private:
	int dataState;
};

void Foo(int value)
{
	if (value < 0)
	{
		//throw value;
		throw "Number below zero!";
	}
	if (value == 0)
	{
		throw exception("Number is zero!");
	}
	if (value == 1)
	{
		throw 1;
	}

	cout << "Variable = " << value << endl;
}
void Foo2(int value)
{
	if (value < 0)
	{
		throw exception("Number below zero!");
	}
	if (value == 1)
	{
		throw MyException("the number is zero!", value);
	}
	cout << "Variable = " << value << endl;
}

int main()
{

	try
	{
		//Foo(1);
		Foo2(1);
	}
	catch (const MyException& ex)
	{
		cout << "Block 1 - We catch: " << ex.what() << endl;
		cout << "data status: " << ex.GetDataState() << endl;
	}	
	catch (const exception& ex)
	{
		cout << "We catch: " << ex.what() << endl;
	}
	catch (const char* ex)
	{
		cout << "We catch: " << ex << endl;
	}
	//такий блок catch ловить абсолютно все що завгодно,
	//що кинуло (викликало) виключну ситуацію, throw exception
	//P.S. ми знаємо, що виникла виключна ситуація, але не знаємо,
	//що там відбулося (бо ми нічого не приймаємо (в параметрах))
	catch (...)
	{
		cout << "something went wrong!" << endl;
	}
	//catch (const int ex)
	//{
	//	cout << "We catch: " << ex << endl;
	//}

	return 0;
}
