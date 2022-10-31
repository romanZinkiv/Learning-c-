#include <iostream>
using namespace std;

union MyUnion
{
	short int a;
	int b;
	float c;
};

int main()
{

	MyUnion u;

	u.a = 5;
	u.b = 40000;
	u.c = 43.54;


	return 0;
}