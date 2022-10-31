#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

int main()
{
    
    string path = "myFile.txt";

    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);
    if (!fs.is_open())
    {
        cout << "error opening file" << endl;
    }
    else
    {
        cout << "file is open" << endl;
        cout << "input 1 to write message in file:" << endl;
        cout << "input 2 to read all messages from file:" << endl;
        string msg;
        int value;
        cin >> value;
        if (value==1)
        {
            cout << "input your message:  ";
         
            ////для вводу кирилиці:
            ////необхідно #include <windows.h>
            ////SetConsoleCP() - в параметрах приймає кодування
            //// і змінює на неї кодування
            ////щоб бачити кирилицю потрібно змінити на кодування 1251
            //SetConsoleCP(1251);
            //cin >> msg;
            //fs << msg << '\n';
            ////потрібно змінити кодування назад на кодування
            ////за замовчуванням, що було до зміни кодування
            ////бо те кодування для нашої проги буде неправильним
            ////і вона не зможе коректно виводити дані на консоль
            //SetConsoleCP(866);

            cin >> msg;
            fs << msg << '\n';
        }
        if (value==2)
        {
            cout << "reading data from file:" << endl;

            //eof - end of file
            while (!fs.eof())
            {
                msg = "";
                fs >> msg;
                cout << msg << endl;
            }
        }
    }
    fs.close();

    return 0;
}