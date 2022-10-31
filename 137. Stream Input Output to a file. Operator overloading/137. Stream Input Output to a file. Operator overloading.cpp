#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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

private:
	int x;
	int y;
	int z;

	//1.дружніми ці функції робимо для того, щоб ці функції отримали
	//доступ до приватних полів класу
	//2.іншим способом вирішити цю проблему є реалізувати геттери і сеттери
	friend ostream& operator<<(ostream& os, const Point& point);
	friend istream& operator>>(istream& is, Point& point);
};

ostream& operator<<(ostream& os, const Point& point)
{
	os << point.x << " " << point.y << " " << point.z;
	return os;
}

istream& operator>>(istream& is, Point& point)
{
	//return is >> point.x >> point.y >> point.z;
	is >> point.x >> point.y >> point.z;
	return is;
}


int main()
{
	string path = "myFile.txt";

	//Point point(123, 5, 24);

	//cout << point;

	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);

	if (!fs.is_open())
	{
		cout << "error opening file" << endl;
	}
	else
	{
		cout << "file is open" << endl;
		//fs << point << '\n';

		//для економії ресурсів, бо всередині циклу вже виконується
		// перевірка на кінець файлу
		//while (!fs.eof())
		while (true)
		{
			Point p;
			fs >> p;
			//це робиться для того шоб не виводити лишній об"єкт p(0,0,0),
			//бо хоч всі об"єкти будуть зчитані, але це ще не буде кінець
			//файлу, бо залишиться перевод на наступний рядок, тобто '\n'
			if (fs.eof())
			{
				break;
			}

			cout << p << endl;
		}

	}
	fs.close();

	return 0;
}
