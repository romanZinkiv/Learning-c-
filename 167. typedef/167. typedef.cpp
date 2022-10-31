#include <iostream>
#include <vector>

//ключове слово typedef використовується для того щоб певним типам даних присвоювати псевдонім (alias)

typedef std::vector<int> int_vector;
typedef std::vector<float> float_vector;


int main()
{

	//std::vector<int> myVector;
	int_vector myVector2;

	//std::vector<float> fv;
	//float_vector fv2;

	std::cout << myVector2.size() << std::endl;

	return 0;
}