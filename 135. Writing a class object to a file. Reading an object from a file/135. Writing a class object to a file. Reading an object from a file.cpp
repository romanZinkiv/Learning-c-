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

	void Print()
	{
		cout << "X: " << x << "\tY: " << y << "\tZ: " << z << endl;
	}

	int x;
	int y;
	int z;
};



int main()
{

	string path = "myFile.txt";

	//Point point(9, 14, 12);
	//ofstream fout;
	//fout.open(path, ofstream::app);
	//if (!fout.is_open())
	//{
	//	cout << "error opening file" << endl;
	//}
	//else
	//{
	//	cout << "file is open" << endl;
	//	fout.write((char*)&point, sizeof(Point));
	//}
	//fout.close();

	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "error opening file" << endl;
	}
	else
	{
		cout << "file is open" << endl;
		Point pnt;
		//метод read() повертає true, якщо вдалось 
		//зчитати дані, якщо не вдалось - поверне false
		//і вписує зчитані дані в перший аргумент (тут це pnt)
		while (fin.read((char*)&pnt, sizeof(Point)))
		{
			pnt.Print();
		}

	}
	fin.close();


	return 0;
}
