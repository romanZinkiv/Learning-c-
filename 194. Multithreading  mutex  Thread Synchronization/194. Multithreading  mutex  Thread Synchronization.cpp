#include <iostream>
#include <mutex>
#include <thread>
#include "SimpleTimer.h"

using namespace std;

//об"єкт класу mutex
mutex mtx;

void Print(char ch) {
	//this_thread::sleep_for(chrono::milliseconds(2000));

	//доступ до ділянки коду закритий для інших потоків на час його виконання якимось одним потоком
	mtx.lock();

	//мютексом ми кажемо, що ця ділянка коду
	for (size_t i = 0; i < 5; ++i)
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}
	cout << endl;
	//у нас одночасно може використовуватись лише одним потоком

	//ділянка коду виконалась і тепер розблокована, і інший потік може отримувати доступ до цієї ділянки коду
	mtx.unlock();

	//this_thread::sleep_for(chrono::milliseconds(2000));
}

int main()
{
	SimpleTimer timer;

	thread t1(Print, '*');
	thread t2(Print, '#');
	thread t3(Print, '@');

	t1.join();
	t2.join();
	t3.join();

	return 0;
}