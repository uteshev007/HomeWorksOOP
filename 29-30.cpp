#include <iostream>
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;
using namespace std;

/*
Домашнее задание
Тема: Шаблоны функций.Шаблоны классов

Задание 1.
Реализуйте шаблонные функции для:
a) сортировки массива (любым алгоритмом сортировки);
b) двоичного поиска в массиве;
c) замены элемента массива на переданное значение.
Приведите примеры работы с этими ф-циями в main()
*/



	template <class T>
	T* BSortArr(T* arr, T size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		return arr;
	}
	template <class T>
	T* FillArr(T size)
	{
		T *arr = new T [size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = RAND(1, 99);
		}
		return arr;
	}

	template <class T>
	void Print(T *arr, T size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	template <class T>
	T BSearch(T* arr, int size, int num)
	{
		int left = 0;
		int right = size - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (arr[mid] == num)
				return mid;
			else if (arr[mid] < num)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;

	}



int main()
{
	cout << "Unsorted array : " << endl;
	int *arr = FillArr<int>(30);
	Print(arr, 30);
	cout << "Buble sorted array: " << endl;
	BSortArr(arr, 30);
	Print(arr, 30);
	cout << "Enter searching number: ";
	int num;
	cin >> num;
	int res = BSearch(arr, 30, num);
	if (res != -1)
		cout << "Your serching number is in Index:" << res + 1 << endl;
	else
		cout << "Not found!" << endl;





}
