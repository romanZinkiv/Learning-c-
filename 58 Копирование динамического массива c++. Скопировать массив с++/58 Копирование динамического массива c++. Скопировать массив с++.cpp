﻿// 58 Копирование динамического массива c++. Скопировать массив с++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>

using namespace std;

void FillArray(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void ShowArray(const int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int main()
{
	int size = 10;
	int* firstArray = new int[size];
	int* secondArray = new int[size];

	FillArray(firstArray, size);
	FillArray(secondArray, size);

	cout << "FirstArray =\t";
	ShowArray(firstArray, size);
	cout << "SecondArray =\t";
	ShowArray(firstArray, size);

	delete[] firstArray;

	firstArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		firstArray[i] = secondArray[i];
	}

	cout << "=========================" << endl;

	cout << "FirstArray =\t";
	ShowArray(firstArray, size);
	cout << "SecondArray =\t";
	ShowArray(firstArray, size);

	delete[] secondArray;
	delete[]firstArray;

}
