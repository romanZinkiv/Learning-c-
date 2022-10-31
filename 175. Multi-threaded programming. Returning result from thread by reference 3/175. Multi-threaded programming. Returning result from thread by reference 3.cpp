#include <iostream>
#include <thread>
using namespace std;

void DoWork(int& a)
{
	this_thread::sleep_for(chrono::milliseconds(400));
	cout << "thread ID = " << this_thread::get_id() << " =========\tDoWork STARTED\t=========" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	a = a * 2;
	cout << "thread ID = " << this_thread::get_id() << " =========\tDoWork STOPPED\t=========" << endl;
}


int main()
{
	int q = 5;
	//потік за замовчуванням передає параметри(аргументи) за значенням (програма не скопмілюється)
	//для того, щоб передати параметр по силці (для роботи з нею) і повернути значення по силці
	//для цього потрібно використати допоміжну функцію із простору імен std: std::ref - і в неї 
	//завернути значення (змінну), яке ми хочемо передати по силці
	//задача фунції ref - створити клас reference_wrapper, який дозволяє працювати з потоком 
	//таким чином, щоб получити з потоку результат його роботи через силку
	thread t(DoWork, /*std::*/ref(q));


	for (size_t i = 0; i < 10; i++)
	{
		cout << "thread ID = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}


	t.join();
	cout << q << endl;

	return 0;
}

//отак теж працює
//void DoWork(int* a)
//{
//	this_thread::sleep_for(chrono::milliseconds(400));
//	cout << "thread ID = " << this_thread::get_id() << " =========\tDoWork STARTED\t=========" << endl;
//	this_thread::sleep_for(chrono::milliseconds(1000));
//	*a = *a * 2;
//	cout << "thread ID = " << this_thread::get_id() << " =========\tDoWork STOPPED\t=========" << endl;
//}
////main
//int q = 5;
//DoWork(&q);
//cout << q << endl;