#include <iostream>
#include <thread>
using namespace std;

class MyClass
{
public:

	void DoWork()
	{
		cout << "DoWork2 &m = " << (void*)this << endl;
		this_thread::sleep_for(chrono::milliseconds(400));
		cout << "thread ID = " << this_thread::get_id() << " =========\tDoWork STARTED\t=========" << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "thread ID = " << this_thread::get_id() << " =========\tDoWork STOPPED\t=========" << endl;
	}

	void DoWork2(int a)
	{
		this_thread::sleep_for(chrono::milliseconds(400));
		cout << "thread ID = " << this_thread::get_id() << " =========\tDoWork STARTED\t=========" << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "DoWork2 value of parameter\t" << a << endl;
		cout << "thread ID = " << this_thread::get_id() << " =========\tDoWork STOPPED\t=========" << endl;
	}

	int Sum(int a, int b)
	{
		this_thread::sleep_for(chrono::milliseconds(400));
		cout << "thread ID = " << this_thread::get_id() << " =========\tDoWork STARTED\t=========" << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "thread ID = " << this_thread::get_id() << " =========\tDoWork STOPPED\t=========" << endl;
		return a + b;
	}

private:

};


int main()
{

	int result;
	MyClass m;

	// [&] - захоплюємо всі змінні контексту по силці (&) (що знаходяться вище лямбда функції)
	//thread t([&]()
	//	{
	//		result = m.Sum(2, 5);
	//	});
	//thread t2([&]()
	//	{
	//		m.DoWork();
	//	});
	//так може бути, але для методів класу, що не повертають значення є ще один варіант:
	//cout << "main &m = " << (void*)&m << endl;
	//другим параметром краще передавати об"єкт по силці &arg, але можна і просто копію об"єкта arg
	//thread t2(&MyClass::DoWork, &m);

	
	thread t3(&MyClass::DoWork2, &m, 7);
	//так теж можна
		//thread t3([&m]()
		//{
		//	m.DoWork2(7);
		//});


	for (size_t i = 1; i <= 10; i++)
	{
		cout << "thread ID = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}

	//t.join();
	//t2.join();
	t3.join();
	//cout << "RESULT\t" << result << endl;

	return 0;
}