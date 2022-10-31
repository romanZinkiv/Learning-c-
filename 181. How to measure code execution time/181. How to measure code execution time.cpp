#include <iostream>
#include <thread>
//#include <chrono>
using namespace std;

int Sum(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "thread ID = " << this_thread::get_id() << "=========\tDoWork STARTED\t=========" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "thread ID = " << this_thread::get_id() << "=========\tDoWork STOPPED\t=========" << endl;
	return a + b;
}

class SimpleTimer
{
public:
	SimpleTimer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~SimpleTimer()
	{
		end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		cout << "DURATION " << duration.count() << " seconds" << endl;
	}


private:
	//std::chrono::steady_clock::time_point std::chrono::steady_clock
	std::chrono::time_point<std::chrono::steady_clock> start, end;
};

void Foo()
{
	SimpleTimer st;
	for (size_t i = 0; i < 5000; i++)
	{
		cout << i << endl;
	}
}

int main()
{
	//SimpleTimer timer;
	////auto start = chrono::high_resolution_clock::now();

	//int result;
	//thread t([&result]() {result = Sum(2, 5); });

	//for (size_t i = 1; i <= 10; i++)
	//{
	//	cout << "thread ID = " << this_thread::get_id() << "\tmain works\t" << i << endl;
	//	this_thread::sleep_for(chrono::milliseconds(500));
	//}

	//t.join();
	//cout << "Sum Result = " << result << endl;

	////auto end = chrono::high_resolution_clock::now();

	////chrono::duration<float> duration = end - start;
	////cout << "Duration: " << duration.count() << " seconds" << endl;

	Foo();

	return 0;
}