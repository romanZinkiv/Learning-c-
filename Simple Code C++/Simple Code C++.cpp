#include <iostream>
#include <string>
using namespace std;

int main()
{
    int* pa = new int;
    *pa = 10;
    cout << *pa << endl;
    delete pa;

   // pa = NULL; //те саме що і pa = 0;
    pa = nullptr;

    //if (pa != NULL)
    if (pa != nullptr)
    {
        cout << pa << endl;
    }
    //cout << pa << endl;
    delete pa;
}

