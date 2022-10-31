#include <iostream>


using namespace std;


class PC
{
public:
	//enum class PCState
	enum PCState
	{
		//це константи
		OFF,
		ON,
		SLEEP
	};

	PCState GetState() { return State; }
	void SetState(PCState State) { this->State = State; }
private:
	PCState State;
};

enum Speed
{
	//це константи
	MIN = 150,
	RECOMMEND = 600,
	MAX = 800,
	AUTO_INCREMENT1,
	AUTO_INCREMENT2
};

int main()
{

	PC pc;
	//PCState s = PCState::OFF;
	pc.SetState(PC::PCState::SLEEP);

	switch (pc.GetState())
	{
	case PC::PCState::OFF:
		cout << "PC is off" << endl;
		break;
	case PC::PCState::ON:
		cout << "PC is working" << endl;
		break;
	case PC::PCState::SLEEP:
		cout << "PC is sleeping" << endl;
		break;
	default:
		break;
	}

	Speed sp = Speed::AUTO_INCREMENT1;
	cout << sp << endl;

	return 0;
}