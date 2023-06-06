#include <iostream>
#include <string>

using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))

/*
Домашнее задание
Тема. Повторение - указатели

1) **Создать массив из N целых чисел, N вводит пользователь.
Заполнить массив случайным образом в диапазоне от 1 до 12.
Каждое число это оценка по 12 бальной системе.
Пользуясь указателем на массив целых чисел, посчитать процент двоек, троек, четверок и пятерок.
Двойка от 1 до 3 включительно, тройка от 4 до 6, четверка от 7 до 9, пятерка от 10 до 12.

2) **Используя указатели, перенести в хвост одномерного массива первый отрицательный элемент.

3) *Написать программу, которая вычисляет сумму ЧЕТНЫХ элементов массива, используя ДВА указателя на массив целых чисел.
Первый указатель двигается с начала массива, второй - с конца.

4) **Напишите функцию, которая принимает целое число и возвращает количество цифр в числе и процент четных цифр.
Рекомендации: Воспользуйтесь передачей параметров по ссылке.

5) ***Напишите шаблон функции, которая осуществляет поиск максимального элемента в массиве.
Функция возвращает позицию элемента и его значение.
Рекомендации: Воспользуйтесь передачей параметров по ссылке.
*/


int* CreateArr(int& size)
{
	cout << "Enter size of array: ";
	cin >> size;
	int* arr = new int[size];
	return arr;

}

void FillArr(int * arr, int size) 
{

	for (int i = 0; i < size; i++)
	{
		arr[i] = RAND(1, 12);
	}
}

void PrintArr(int * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int* PercentBal(int* arr, int size)
{
	int result2 = 0, result3 = 0, result4 = 0, result5 = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] <= 3)
		{
			result2 += arr[i];
	
		}
		if (arr[i] >= 4 && arr[i] <= 6)
		{
			result3 += arr[i];
			
		}
		if (arr[i] >= 7 && arr[i] <= 9)
		{
			result4 += arr[i];

		}
		if (arr[i] >= 10 && arr[i] <= 12)
		{
			result5 += arr[i];

		}
	}
	cout << "Percent of 2: " << result2 << "%" << endl;
	cout << "Percent of 3: " << result3 << "%" << endl;
	cout << "Percent of 4: " << result4 << "%" << endl;
	cout << "Percent of 5: " << result5 << "%" << endl;
	return arr;
}


// функции к 2 задаче

int* NegativeFillArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = RAND(-5, 5);
	}
	return arr;
}

int* SwapI(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			arr[size - 1] = arr[i];
			break;
		}

	}
	return arr;
}

int main()
{
	int size;
	int* arr = CreateArr(size);
	FillArr(arr, size);
	PrintArr(arr, size);
	PercentBal(arr, size);
	NegativeFillArr(arr, size);
	PrintArr(arr, size);
	SwapI(arr, size);
	PrintArr(arr, size);


}