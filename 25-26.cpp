#include <iostream>
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;
/*
Домашнее задание
Шаблоны функций, классов


Задание 1
Написать перегруженные шаблоны функций для нахождения корней линейного (a * x + b = 0) и квадратного (a * x**2 + b * x + c = 0) уравнений.
Замечание: в функции передаются коэффициенты уравнений.


Задание 2
Напишите шаблон функции, которая возвращает максимум из двух переданных параметров.


Задание 3
Напишите шаблон функции, которая находит минимальное значение в массиве и возвращает одновременно найденное минимальное значение и его позицию в массиве.

*/

template <class T>
T MaxReturn(T a, T b)
{
	T Result = 0;
	if (a > b)
		cout << "MAX is: " << a << endl;
	else
		cout << "MAX is: " << b << endl;
	return Result;

}

template <class T2>
T2 MinInArr(T2 * arr, T2 size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = RAND(1, 20);
	}

	int min = arr[0];
	int Index = 0;

	for (int i = 1; i < size; i++)
	{

		if (arr[i] < min)
		{
			min = arr[i];
			Index = i;
		}

	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << "Min Value of this array is: " << min << "," << " in " << Index + 1 << " place " << endl;
	return min;
}


int main()
{
	MaxReturn <int> (15, 50);
	int arr[] = { 1,2,3,4,5};
	MinInArr(arr, 5);
}