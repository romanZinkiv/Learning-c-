#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{
	string path = "myFile.txt";
	ifstream fin;
	//для того, щоб ввімкнути обробку виключних ситуацій
	fin.exceptions(ifstream::badbit | ifstream::failbit);

	try
	{
		fin.open(path);
	}
	//catch (const std::exception& ex)
	catch (const ifstream::failure& ex)
	{
		cout << ex.what() << endl;
		cout << ex.code() << endl; //метод класу ifstream::failure
		cout << "error opening file" << endl;
	}


	return 0;
}
