
#include <iostream>
#include <string>
using namespace std;

class CoffeeGrinder
{
private:
	bool CheckVoltage()
	{
		return true;
	}

public:
	void Start()
	{
		if (CheckVoltage())
		{
			cout << "VjuHHH!!" << endl;
		}
		else
		{
			cout << "Beep Beep" << endl;
		}
	}

};
class Human
{
public:

	int age;
	int weight;
	string name;

	void Print()
	{
		cout << "Name: " << name << "\nWeight: " << weight << "\tAge: " << age << endl;
	}

};

class Point
{

private:
	int x;
	int y;

public:

	Point()
	{
		cout << this << " constructor" << endl;
		this->y = 0;
		this->x = 0;
	}

	Point(int valueX, int valueY)
	{
		x = valueX;
		y = valueY;
	}

	//Point(int valueX, bool boolean)
	//{
	//	x = valueX;
	//	if (boolean)
	//		y = 1;
	//	else
	//		y = -1;
	//}

	bool operator==(const Point& other)
	{
		return this->x == other.x && this->y == other.y;
	}
	bool operator!=(const Point& other)
	{
		if (this->x != other.x || this->y != other.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//навіщо?
	// <, >=, <=  по аналогії
	bool operator>(const Point& other)
	{
		return this->x * this->y > other.x * other.y;
	}
	Point& operator+(const Point& other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;

		return temp;
	}
	Point& operator-(const Point& other)
	{
		Point temp;
		temp.x = this->x - other.x;
		temp.y = this->y - other.y;

		return temp;
	}
	Point& operator*(const Point& other)
	{
		Point temp;
		temp.x = this->x * other.x;
		temp.y = this->y * other.y;

		return temp;
	}
	Point& operator/(const Point& other)
	{
		if (other.x != 0 && other.y != 0)
		{
			Point temp;
			temp.x = this->x / other.x;
			temp.y = this->y / other.y;
			return temp;
		}
		else
		{
			cout << "ERROR: Division by zero!" << endl;
			return *this;
		}
	}
	Point& operator%(const Point& other)
	{
		Point temp;
		temp.x = this->x % other.x;
		temp.y = this->y % other.y;
		return temp;
	}

	Point& operator++()
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point& operator--()
	{
		this->x--;
		this->y--;
		return *this;
	}
	Point& operator++(int value)
	{
		Point temp = *this;

		this->x++;
		this->y++;

		return temp;
	}
	Point& operator--(int value)
	{
		Point temp = *this;

		this->x--;
		this->y--;

		return temp;
	}

	void setX(int valueX)
	{
		x = valueX;
	}

	void setY(int valueY)
	{
		y = valueY;
	}

	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}

	void Print()
	{
		cout << "X = " << x << "\t Y = " << y << endl;
	}

};

class MyClass
{
	int size;
	int* data;
public:
	MyClass(int size)
	{
		this->size = size;
		this->data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}
		cout << this << " Constructor called" << endl;
	}

	MyClass(const MyClass& other)
	{
		cout << "Copy constructor called " << this << endl;
		this->size = other.size;
		this->data = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->data[i] = other.data[i];
		}
	}

	MyClass& operator = (const MyClass& other)
	{
		cout << "Operator = called " << this << endl;

		this->size = other.size;

		if (this->data != nullptr)
		{
			delete[] this->data;
		}

		this->data = new int[size];
		for (int i = 0; i < this->size; i++)
		{
			this->data[i] = other.data[i];
		}

		return *this;
	}

	//ПРИПУСТИМО, ЩО У НАС У МАСИВІ data МОЖУТЬ БУТИ РІЗНІ ДАНІ
	bool operator ==(const MyClass& other)
	{
		if (this->size != other.size)
		{
			return this->size == other.size;
		}
		for (int i = 0; i < this->size; i++)
		{
			if (this->data[i] != other.data[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator !=(const MyClass& other)
	{
		if (this->size != other.size)
		{
			return this->size != other.size;
		}
		for (int i = 0; i < this->size; i++)
		{
			if (this->data[i] == other.data[i])
			{
				return false;
			}
		}
		return true;
	}
	// <, >=, <=  по аналогії
	bool operator >(const MyClass& other)
	{
		if (this->size != other.size)
		{
			return this->size > other.size;
		}
		int temp1 = 0, temp2 = 0;
		for (int i = 0; i < this->size; i++)
		{
			temp1 += this->data[i];
		}
		for (int i = 0; i < other.size; i++)
		{
			temp2 += other.data[i];
		}
		return temp1 > temp2;
	}

	~MyClass()
	{
		delete[] data;
		cout << this << " Destructor called" << endl;
	}
};
void Foo()
{
	cout << "Foo works begin" << endl;
	MyClass a(1);
	cout << "Foo works end" << endl;
}
MyClass Foo2()
{
	cout << "Called function FOO_2" << endl;
	MyClass temp(2);

	return temp;
}

class TestClass
{
	int arr[5]{ 3,44,32,5,65 };
public:
	//якщо так - int operator[](int index)
	//то ми не зможемо присвоювати присвоювати таким чином значення
	//наприклад: a[2] = 100, бо a[2] - це буде не посилання на
	//конкретне місце в пам"яті, а якесь конкретне значення
	//наприклад: 50 = 100 - що це не має ніякого смислу
	int& operator[](int index)
	{
		return arr[index];
	}
};

class Apple {

public:

	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		Count++;
		id = Count;
	}

	int GetId()
	{
		return id;
	}

	static int GetCount()
	{
		return Count;
	}

	static void ChangeColor(Apple& apple, string color)
	{
		apple.color = color;
	}

private:
	static int Count;
	int weight;
	string color;
	int id;
};
int Apple::Count = 0;

class Image
{

public:

	void GetImageInfo()
	{
		for (size_t i = 0; i < LENGTH; i++)
		{
			cout << "#" << i + 1 << " " << pixels[i].GetInfo() << endl;
		}
	}

private:

	class Pixel
	{
	public:

		Pixel(int r, int g, int b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		}

		string GetInfo()
		{
			return "Pixel: r = " + to_string(r) + "	g = " + to_string(g) + "	b = " + to_string(b);
		}

	private:

		int r;
		int g;
		int b;

	};

	static const int LENGTH = 5;

	Pixel pixels[5]
	{
		Pixel(0,4,64),
		Pixel(4,14,10),
		Pixel(111,4,24),
		Pixel(244,244,14),
		Pixel(111,179,64)
	};

};

class Pixel
{
public:

	Pixel()
	{
		r = g = b = 0;
	}

	Pixel(int r, int g, int b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}

	string GetInfo()
	{
		return "Pixel: r = " + to_string(r) + "	g = " + to_string(g) + "	b = " + to_string(b);
	}

private:

	int r;
	int g;
	int b;

};



int main()
{
	//Point a(5, 44);
	////Point a;
	//a.Print();

	//Point b(77, 9);
	//b.Print();

	//MyClass v(1);
	//MyClass b(2);
	//Foo();

	//Foo2();
	//MyClass a(10);
	//MyClass b(a);

	//MyClass a(10);
	//MyClass b(2);
	//MyClass c(5);
	//c = a = b;

	//Point a(3, 10);
	//Point b(5, 2);
	//cout << (a != b) << endl;
	//cout << (a == b) << endl;
	//cout << (a > b) << endl;
	//MyClass aa(10);
	//MyClass bb(5);
	//cout << (aa != bb) << endl;
	//cout << (aa == bb) << endl;
	//cout << (aa > bb) << endl;


	//TestClass a;
	//cout << a[0] << endl;
	//a[0] = 100;
	//cout << a[0] << endl;

	//Apple apple(150, "Red");
	//Apple apple2(100, "Green");
	//Apple apple3(200, "Yellow");
	//cout << apple.Count << endl;
	//cout << Apple::Count << endl;
	//cout << apple.GetId() << endl;
	//cout << apple2.GetId() << endl;
	//cout << apple3.GetId() << endl;
	//apple.ChangeColor(apple, "Green");

	//Image img;
	//img.GetImageInfo();
	//якщо клас Pixel знаходитиметься в секції public
	//Image::Pixel pixel(24, 44, 111);
	//pixel.GetInfo();

	//const int LENGTH = 5;
	////static array
	//Pixel arr1[LENGTH]
	//{
	//	Pixel(1, 3, 4),
	//	Pixel(32, 231, 211),
	//	Pixel(114, 141, 147),
	//	Pixel(99, 2, 115),
	//	Pixel(187, 32, 7)
	//};
	//cout << arr1[0].GetInfo() << endl;
	////dynamic array
	//Pixel* arr2 = new Pixel[LENGTH];
	//arr2[0] = Pixel(11, 151, 44);
	//cout << arr2[0].GetInfo() << endl;

	return 0;
}
