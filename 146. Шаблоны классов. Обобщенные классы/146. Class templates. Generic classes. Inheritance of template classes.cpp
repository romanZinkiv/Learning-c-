#include <iostream>
#include <string>
//#include <typeinfo>

using namespace std;

//если есть ошибка то нужно написать так.
//1) typeid(this->value).name()
//2) TypeInfo(T1 value) :TypeSize<T1>(value)

//У кого выводятся ошибки типа(недопустимая инициализация члена : MyClass 
//не является базовым классом) или типо нету базового подходящего 
//класса(что - то в этом духе) делаете такую штуку :
//MyClass2(T value) : MyClass<T>(value)
//{
//
//}
//В конструкторе наследника указываете MyClass2(T value) : MyClass<T>(value) и все

class Point
{
public:
	Point()
	{
		x = y = z = 0;
	}
	Point(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	int x;
	int y;
	int z;
};

//typename і class - можна використовувати обидва ці ключові слова
//template<class T>
template<typename T>
class MyClass
{
public:
	MyClass(T value)
	{
		this->value = value;
	}

	void DataTypeSize()
	{
		cout << sizeof(value) << endl;
	}

	T Foo() { return value; }

private:
	T value;
};

//typename і class - можна використовувати обидва ці ключові слова
//template<class T1, class T2>
template<typename T1, typename T2>
class MyClass2
{
public:
	MyClass2(T1 value1, T2 value2)
	{
		this->value1 = value1;
		this->value2 = value2;
	}

	void DataTypeSize()
	{
		cout << sizeof(value1) << endl << sizeof(value2) << endl;
		//чому таке не працює
		//cout << value1 << sizeof(value1) << endl;
		//cout << value2 << sizeof(value2) << endl;
	}

private:
	T1 value1;
	T2 value2;
};

template<class T1>
class TypeSize
{
public:
	TypeSize(T1 value)
	{
		this->value = value;
	}

	void DataTypeSize()
	{
		cout << "value: " << sizeof(value) << endl;
	}


protected:
	T1 value;
};

//так теж можна
//class TypeInfo : public TypeSize<int>
//typename\class - мусить співпадати з ключовими словами
//класу від якого наслідуємось
//T в TypeSize<T> - не зобов"язане співпадати з буквою (ідентифікатором типу)
//батьківського\базового класу (від якого наслідуємось)
template<class T>
class TypeInfo : public TypeSize<T>
{
public:
//У кого выводятся ошибки типа(недопустимая инициализация члена : MyClass 
//не является базовым классом) или типо нету базового подходящего 
//класса(что - то в этом духе) делаете такую штуку :
//MyClass2(T value) : MyClass<T>(value) {}
//В конструкторе наследника указываете MyClass2(T value) : MyClass<T>(value) и все
	TypeInfo(T value) : TypeSize<T>(value)
	{

	}

	void ShowTypeName()
	{
		//typeid - щось типу об"єктної обгортки, яка працює з типами даних
		//поверне тип (якщо не працює, то треба #include <typeinfo>)
		cout << "Type name: " << typeid(this->value).name() << endl;
		//так теж можна
		// Да, лучше именно так писать, зависит от компилятора и ОС, 
		// но ваш вариант должен компилироваться на всех системах.
		//cout << "Type name: " << typeid(TypeSize<T>::value).name() << endl;
	}
};


int main()
{
	//int a = 5;
	////double a = 5.231;
	////Point a;
	//MyClass<int> c(a);
	//c.DataTypeSize();
	////int b = c.Foo();

	//int a = 2;
	//Point p;
	//MyClass2<int, Point> c(a, p);
	////MyClass2<int, int> c(a, a);
	//c.DataTypeSize();

	//double a = 2;
	Point a;
	TypeInfo<Point> c(a);
	c.DataTypeSize();
	c.ShowTypeName();



	return 0;
}