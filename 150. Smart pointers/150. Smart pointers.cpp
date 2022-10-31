#include <iostream>
#include <string>
#include <memory>

using namespace std;


//shared_ptr<> - найкорисніший і найпотрібніший з розумних вказівників

//А чтобы создать двумерный массив надо так :
//const int size = 5;
//shared_ptr<int[][size]> ptr(new int[size][size]);
//во всём инете не было ответа так что пригодится любому новичку,

template<typename T>
class SmartPointer
{
public:

	SmartPointer(T* ptr)
	{
		this->ptr = ptr;
		cout << "Constructor" << endl;
	}

	~SmartPointer()
	{
		delete ptr;
		cout << "Destructor" << endl;
	}

	T& operator*()
	{
		return *ptr;
	}

private:
	T* ptr;
};


int main()
{
	//int* ptr = new int(5);
	//cout << *ptr << endl;
	//delete ptr;

	//оператор new - повертає адрес в пам"яті
	//в даному випадку цей адрес вказуватиме на тип int
	//SmartPointer<int> pointer = new int(5);
	//cout << *pointer << endl;

	//виникне помилка, коли деструктор sp2 спробує звільнити дані
	//SmartPointer<int> sp1 = new int(5);
	//SmartPointer<int> sp2 = sp1;

	//при призначенні другого вказівника на область пам"ятті, перший вказівник стає пустим (empty)
	//auto_ptr<int> ap1(new int(5));
	//auto_ptr<int> ap2(ap1);

	//заборонено двом розумним вказівникам посилатись на одну і ту ж область в пам"ятті (не скомпілюється)
	//unique_ptr<int> up1(new int(5));
	//unique_ptr<int> up2(up1);
	//p1 стане пустим (empty), а p2 посилатиметься на вказану область пам"ятті
	//по суті ситуація та сама, що з auto_ptr<>
	//unique_ptr<int> p1(new int(5));
	//unique_ptr<int> p2;
	////move - ф-я із простору імен std
	//p2 = move(p1);
	////p1 - unique_ptr, p2 - empty -> swap -> p1 - empty, p2 - unique_ptr
	//p2.swap(p1);

	//для auto_ptr<> і unique_ptr<> метод get() повертає вказівник (в сирому, чистому виді - raw pointer)
	//auto_ptr<int> ap1(new int(5));	
	//unique_ptr<int> p1(new int(5));
	//int* ptr_ap1= ap1.get();
	//int* ptr_p1= p1.get();

	//int* p = new int(5);
	////метод reset() - затирає дані на які він вказує і вказівник стає пустим
	//unique_ptr<int> p1(p);
	//p1.reset();
	////метод release() - дані залишаються в пам"ятті(їх не чіпали), але вказівник стає пустим (ніби про дані забуває)
	//p1.release();

	//shared_ptr<> - найкорисніший і найпотрібніший з розумних вказівників
	//може бути багато shared_ptr<> і всі вони можуть ссилатись на одну і ту ж область в пам"ятті,
	//тобто на одні і ті ж дані.
	//коли дані будуть знищуватись при виході, помилки не виникне, тому що дані
	//будуть знищені лише в той момент, коли буде знищено останній shared_ptr<>, що посилається на ці дані
	//shared_ptr<int> p1(new int(5));
	//shared_ptr<int> p2(p1);

	//робота з динамічними масивами
	int SIZE;
	cout << "input size of array: ";
	cin >> SIZE;
	int* arr = new int[SIZE];
	//int* arr = new int[SIZE] {1, 6, 44, 9, 8};

	//якщо розумний вказівник вказує на масив, то треба це вказати додавши [],
	//щоб розумний вказівник знав, що він працює з масивом  
	//P.S. інакше нічого не вийде, shared_ptr<> контролює, що це за тип даних, просто значення чи саме масив
	shared_ptr<int[]> ptr(arr);
	//можна і так
	//shared_ptr<int[]> ptr(new int[SIZE] {1, 6, 44, 9, 8});
	for (int i = 0; i < SIZE; i++)
	{
		ptr[i] = rand() % 10;
		cout << ptr[i] << endl;
		//слід пам"ятати, що оператори (наприклад перегружені) - це теж функції,
		//і з ним можна ось так працювати
		//cout << ptr.operator[](i) << endl;
	}

	//А чтобы создать двумерный массив надо так :
	//const int size = 5;
	//shared_ptr<int[][size]> ptr(new int[size][size]);
	//во всём инете не было ответа так что пригодится любому новичку,

	return 0;
}