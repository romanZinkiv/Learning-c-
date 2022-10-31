#include <iostream>
#include <thread>

using namespace std;

int Sum(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(400));
	cout << "thread ID = " << this_thread::get_id() << " =========\tDoWork STARTED\t=========" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "thread ID = " << this_thread::get_id() << " =========\tDoWork STOPPED\t=========" << endl;
	return a + b;
}

int main()
{

	int result;

	thread t([&result]()
		{
			result = Sum(2, 5);
		});

	for (size_t i = 0; i < 10; i++)
	{
		cout << "thread ID = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}

	t.join();
	cout << "Sum result: " << result << endl;

	return 0;
}