#include <iostream>
#include <string>
#include <time.h>

using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))

/*
1. Создайте класс Array. Класс Array – это класс динамического массива. 
Размер массива может быть передан в качестве параметра или задан с помощью вызова функции-члена.
Реализовать в классе Array методы позволяющие:
* заполнять массив значениями,
* отображать содержимое массива,
* изменять размер массива,
* сортировать массив,
* определять минимальное и максимальное значение.
Класс должен содержать набор конструкторов (конструктор копирования обязателен), деструктор. 
Использовать делегирование конструкторов.

*/


class Array
{
private: 
	int Size;
	int* Data;
public:
	Array() : Size(0), Data(nullptr) {}
	Array(int* mas, int sz) :Array() {}
	Array(int sz) : Size(sz), Data(new int[sz]){}
	Array(const Array& other) 
	{
		Size = other.Size;
		Data = new int[Size];
		for (int i = 0; i < Size; ++i) {
			Data[i] = other.Data[i];
		}
	}
	~Array() { delete[] Data;}


	int SetSize()
	{
		delete[] Data;
		cout << "Enter size of Array: " << endl;
		cin >> Size;
		Data = new int[Size]();
		for (int i = 0; i < Size; i++)
		{
			Data[i] = RAND(1, 10);
			cout << Data[i] << " ";
		}
		cout << endl;
		return Size;
	}
	void PrintArr()
	{
		for (int i = 0; i < Size; i++)
		{
			cout << Data[i] << " ";
		}
		cout << endl;
	}
	void ChangeSize()
	{
		int CopyArray, NewSize;
		cout << "Enter new size of array: " << endl;
		cin >> NewSize;
		int* newData = new int[NewSize]();
		CopyArray = NewSize < Size ? NewSize : Size;
		for (int i = 0; i < CopyArray; i++)
			newData[i] = Data[i];
		delete[] Data;
		Data = newData;
		Size = NewSize;

	}
	void SortArray() 
	{
		cout << "Array sorted from min to max " << endl;
		for (int i = 0; i < Size - 1; ++i) {
			for (int j = 0; j < Size - i - 1; ++j) {
				if (Data[j] > Data[j + 1]) {
					int temp = Data[j];
					Data[j] = Data[j + 1];
					Data[j + 1] = temp;
				}
			}
		}
	}
	void MinMax()
	{
		int Min = Data[0];
		int Max = Data[0];
		for (int i = 0; i < Size; i++)
		{
			if (Data[i] < Min)
				Min = Data[i];
			if (Data[i] > Min)
				Max = Data[i];
		}
		cout << "Min of array: " << Min << endl;
		cout << "Max of array: " << Max << endl;
	}

};

int main()
{
	Array A;
	A.SetSize();
	A.ChangeSize();
	A.PrintArr();
	A.SortArray();
	A.PrintArr();
	A.MinMax();
}