#include <iostream>
#include <string>
using namespace std;


template<typename T>
class List
{
public:
	List();
	~List();

	void pop_front();
	void clear();
	void push_back(T data);
	int getSize();
	T& operator[](const int index);

	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();

private:

	template<typename T>
	class Node
	{
	public:
		Node* ptrNext;
		T data;

		//T() - якщо клас\структ, то викликає конструктор за замовчування
		//якщо примітивний тип даних, то значення за замовчуванням того типу даних
		Node(T data = T(), Node* ptrNext = nullptr)
		{
			this->data = data;
			this->ptrNext = ptrNext;
		}
	};

	Node<T>* head;
	int size;

};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->ptrNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = head;
		while (current->ptrNext != nullptr)
		{
			current = current->ptrNext;
		}
		current->ptrNext = new Node<T>(data);
	}

	size++;
}

template<typename T>
int List<T>::getSize()
{
	return size;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->ptrNext;
		counter++;
	}


	//if (head != nullptr)
	//{
	//	int counter = 0;
	//	Node<T>* current = head;
	//	while (counter < index && current->ptrNext != nullptr)
	//	{
	//		current = current->ptrNext;
	//		counter++;
	//	}
	//	if (counter == index)
	//	{
	//		return current->data;
	//	}
	//}
	//Node<T> ret;
	//return ret.data;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->ptrNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->ptrNext);
		previous->ptrNext = newNode;
		//previous->ptrNext = new Node<T>(data, previous->ptrNext);

		size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		//цей код можна винести в окремий метод
		Node<T>* previous = head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->ptrNext;
		}
		//
		Node<T>* toDelete = previous->ptrNext;
		previous->ptrNext = toDelete->ptrNext;
		delete toDelete;
		//буде витік пам"ятті, бо ми тільки переназначаємо адреса, а сам елемент не видаляємо
		//previous->ptrNext = previous->ptrNext->ptrNext;

		size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(size - 1);

	//довга фігня
	//if (head != nullptr)
	//{
	//	if (head->ptrNext != nullptr)
	//	{
	//		Node<T>* previous = head;
	//		while (previous->ptrNext->ptrNext != nullptr)
	//		{
	//			previous = previous->ptrNext;
	//		}

	//		delete previous->ptrNext;
	//		//previous->ptrNext = nullptr;

	//		size--;
	//	}
	//	else
	//	{
	//		pop_front();
	//	}
	//}
}





int main()
{

	List<int> lst;

	int numbersCount;
	cout << "Input count of elements of singly linked list: ";
	cin >> numbersCount;

	for (int i = 0; i < numbersCount; i++)
	{
		lst.push_back(rand() % 100);
	}

	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "do push_front(505)" << endl;
	lst.push_front(555);
	cout << "do push_front(735)" << endl;
	lst.push_front(735);
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "do pop_front()" << endl;
	lst.pop_front();
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "insert" << endl;
	lst.insert(999, 0);
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "removeAt " << endl;
	lst.removeAt(1);
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "push_back" << endl;
	lst.push_back(-10);
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "pop_back" << endl;
	lst.pop_back();
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "do clear()" << endl;
	lst.clear();
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}


	return 0;
}