#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void DoWork(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "=========\tDoWork STARTED\t=========" << endl;
	this_thread::sleep_for(chrono::milliseconds(400));
	cout << "a + b = " << a + b << endl;
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "=========\tDoWork STOPPED\t=========" << endl;
}


int main()
{

	//передача потоку функції з параметрами (насправді вказівник/адрес цієї функції), і далі підряд параметри
	thread th(DoWork, 2, 3);
	//виклик в окремому потоці функції, яка в основному потоці би мала такий вигляд: DoWork(2, 3);


	//DoWork(2, 3);
	for (size_t i = 0; true; i++)
	{
		cout << "thread ID = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(200));
	}


	th.join();

	return 0;
}