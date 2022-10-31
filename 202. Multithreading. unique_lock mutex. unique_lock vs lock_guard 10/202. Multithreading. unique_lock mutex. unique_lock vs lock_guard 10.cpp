#include <iostream>
#include <mutex>
#include <thread>
#include "SimpleTimer.h"
using namespace std;


mutex mtx;

void Print(char ch) 
{
	//unique_lock може не захоплювати/заблоковувати м"ютекс в момент створення об"єкта класу, для цього
	//при створенні об"єкта класу потрібно в конструктор передати другим параметром std::defer_lock
	//в такому випадку для того щоб заблокувати м"ютекс потрібно викликати lock() у unique_lock
	unique_lock<mutex> ul(mtx, std::defer_lock);

	this_thread::sleep_for(chrono::milliseconds(2000));

	//подібний до lock_guard, але більш гнучкий
	//у unique_lock ми самі можемо викликати метод unlock(), щоб розблокувати м"ютекс, якщо ми цього 
	//не зробимо, то unique_lock сам розблокує м"ютекс в момент виходу об"єкта з області видимості
	//unique_lock<mutex> ul(mtx);

	ul.lock();

	for (size_t i = 0; i < 5; ++i)
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;

	//його викликати не обов"язково, бо якщо ми самі не розблокуємо м"ютекс, unique_lock зробить це за нас
	ul.unlock();

	this_thread::sleep_for(chrono::milliseconds(2000));
}


int main()
{
	//setlocale(LC_ALL, "uk");
	//setlocale(LC_ALL, "ru");

	SimpleTimer timer;

	thread t1(Print, '*');
	thread t2(Print, '#');



	t1.join();
	t2.join();

	return 0;
}