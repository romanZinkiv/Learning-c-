#include <iostream>
#include <mutex>
#include <thread>
#include "SimpleTimer.h"
using namespace std;


//lock_guard - це клас, задачою якого є захопити м"ютекс в конструкторі при створенні об"єкту такого класу
//і звільнити цей м"ютекс в деструкторі в той момент, коли об"єкт цього класу буде покидати яку-небудь
//область видимості

//Для тех, кто не понял зачем это нужно
//std::mutex m;
//void bad()
//{
//	m.lock();                    // определяем мьютекс
//	f();                         // если f() кинет исключение, то поток так и останется закрытым
//	if (!everything_ok()) return; // если функция ретёрнится раньше unlock, то мьютекс тоже останется закрытым
//	m.unlock();                  // тут мьютекс разлочится
//}
//void good()
//{
//	std::lock_guard<std::mutex> lk(m); // RAII class, обычный казалось бы мьютекс
//	f();                               // если f() кинет исключение, то мьютекс разлочится
//	if (!everything_ok()) return;       // если программа внезапно ретёрнится, то мьютекс разлочится
//}                                                      // и тут соответственное мьютекс разлочится
//как видите это просто безопаснее и гарантирует нормальную работу потоков


//об"єкт класу mutex
mutex mtx;

void Print(char ch) {
	//задача lock_guard захопити м"ютекс в конструкторі і звільнити м"ютекс в деструкторі
	//так як захват відбувається в конструкторі, а конструктор викликається при створенні об"єкта
	//при створенні lock_guard можна рахувати, що написали mutex.lock()
	//lock_guard<mutex> guard(mtx);
	//деструктор класу lock_guard викличеться в момент виходу об"єкта із області видимості
	//mtx.lock();

	this_thread::sleep_for(chrono::milliseconds(2000));

	//обмежуємо область видимості нашого об"єкта класу lock_guard за допомогою фігурних дужок {}
	{
		lock_guard<mutex> guard(mtx);
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
	}
	//тут об"єкт guard класу lock_guard вже не видно
	//тому що було обмежено область видимості коду фігурнимим дужками {}

	this_thread::sleep_for(chrono::milliseconds(2000));

	//mtx.unlock();
	//після виходу із функції Print викличеться деструктор класу lock_guard 
	//і розблоковується/звільняється м"ютекс
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