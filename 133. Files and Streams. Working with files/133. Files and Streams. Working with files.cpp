#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{


	//string path = "myFile.txt";
	//cin >> path;
	//ofstream fout;
	//за замовчуванням метод open() працює так що, якщо 
	//метод open() не знаходить такий файл, то він (метод) його створює (файл)
	//fout.open(path);
	//за замовчування метод open() при відкритті стирає всі дані з файлу (можливо видаляє файл)
	//у нижче наведений спосіб дані дописуватимуться в кінець файлу (нічого не стирається)
	//fout.open(path, ofstream::app);

	//метод is_open() перевіряє чи вдалось відкрити файл
	//повертає true - в разі успіху і false - в разі невдачі
	//if (!fout.is_open())
	//{
	//	cout << "error opening file" << endl;
	//}
	//else
	//{
	//	запис данних в файл
	//	fout << "It's our data!\n";
	//	for (int i = 0; i < 5; i++)
	//	{
	//		cout << "Input number" << endl;
	//		int a;
	//		cin >> a;
	//		fout << a << '\n';
	//	}
	//	
	//}

	//як тільки відпрацювали з файлом і він більше не потрібен
	// файл потрібно закривати
	//закриття файлу
	//fout.close();



	string path = "myFile2.txt";
	ifstream fin;
	//відкриваємо файл
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "error opening file" << endl;
	}
	else
	{
		cout << "File is open" << endl;
		//метод get() посимвольно зчитує файл
		//якщо у get() вдалось щось зчитати, то він повертає true
		//якщо не вдалось - false (і напевно при true - присвоює 
		//аргументу значення зчитаного символу)
		char ch;
		//while (fin.get(ch))
		//{
		//	cout << ch;
		//}

		//метод eof() зчитує рядки (текст до пробілу), до кінця файлу
		//поки не кінець файлу - вертає false
		//коли досягне кінець файлу - вертає true
		string str;
		//while (!fin.eof())
		//{
		//	str = ""; // -це робиться, щоб із-за символу '\n' в кінці
		//	//файлу не дублювався останній рядок
		//	//зчитуємо аналогічно як в cin>>
		//	fin >> str;
		//	cout << str << endl;
		//}
		//eof - end of file
		while (!fin.eof())
		{
			str = "";
			//метод getline() приймає в параметрах потік і
			//і рядок куди будуть записуватись дані
			// зчитує повністю рядок (1 горизонтальний рядок)
			// до переводу на наступний рядок
			//метод ігнорує пробіли і ділить на рядки по '\n'
			//потрібно #include <string> , інакше не запрацює
			/*std::*/getline(fin, str);
			cout << str << endl;

			//так собі спосіб
			//char str[50];
			//fin.getline(str, 50);
		}
	}
	fin.close();

	return 0;
}