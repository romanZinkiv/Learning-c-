#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

//рекурсивний м"ютекс recursive_mutex можна захоплювати(lock) безліч разів (стільки раз, скільки нам потрібно)
//але звільняти цей м"ютекс (метод unlock) нам буде необхідно стільки ж разів, скільки ми його захопили

recursive_mutex rm;


void Foo(int a)
{
	rm.lock();
	cout << a << " ";

	this_thread::sleep_for(chrono::milliseconds(300));

	if (a <= 1)
	{
		cout << endl;
		rm.unlock();
		return;
	}

	a--;
	Foo(a);
	rm.unlock();
}


int main()
{
	//з recursive_mutex так можна, тільки к-ть викликів lock(), має співпадати p к-тю викликів unlock()
	//rm.lock();
	//rm.lock();
	//rm.lock();
	//rm.unlock();
	//rm.unlock();
	//rm.unlock();

	thread t1(Foo, 10);
	thread t2(Foo, 10);

	t1.join();
	t2.join();

	return 0;
}