#include <iostream>
#include <string>
using namespace std;



namespace firstNS
{
	void Foo()
	{
		cout << "Foo firstNS" << endl;
	}

	int a;

	class Point {};
}

namespace secondNS
{
	void Foo()
	{
		cout << "Foo secondNS" << endl;
	}

	int b;

	class Point {};
}
//та саме що namespace secondNS { Foo(); Foo2(); }
namespace secondNS
{
	void Foo2()
	{
		cout << "Foo secondNS" << endl;
	}
}

namespace thirdNS
{
	namespace secondNS
	{
		void Foo()
		{
			cout << "Foo thirdNS" << endl;
		}
	}
}

//using namespace треба обержно використовувати, щоб не виникало 
//ніяких конфліктів (імен)
//using namespace firstNS;
//using namespace secondNS;
//int main() { Foo(); } - буде конфлікт


int main()
{

	thirdNS::secondNS::Foo();
	secondNS::Foo();

	//firstNS::a;
	//secondNS::b;
	//firstNS::Point;
	//secondNS::Point;

	return 0;
}