#include <iostream>
#include <string>

using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); }}_;


/*
Задание 1

Цифровой счетчик, это переменная с ограниченным диапазоном.
Значение которой сбрасывается, когда ее целочисленное значение
достигает определенного максимума (например, k принимает значения
в диапазоне от 0 до 100).
В качестве примера такого счетчика можно привести цифровые часы,
счетчик километража. Опишите класс такого счетчика.
Обеспечьте возможность установления максимального и минимального
значений, увеличения счетчика на 1, возвращения текущего значения.
*/


class Counter
{
private:
	int temp;
	int hour;
	int MAX = 12;
	int MIN = 1;
	int k;
public:
	Counter();
	int Increment()
	{
		hour = 0;
		for (int  i = 0; i < k; i++)
		{
			hour++;
			if (k > MAX)
			{
				hour++;
				hour = temp % MAX;
			}

		}
		return hour;
	}
	
	void Input()
	{
		cout << "Введите значение: ";
		cin >> temp;
		setHour(temp);
	}
	void Print()
	{
		cout << "Стрелка до: " << "12" << endl;
		cout << "Стрелка после: " << Increment() << endl;
	}

	int InputHour()
	{
		return hour;
	}
	
	void setHour(int newhour)
	{
		k = newhour;
		Increment();
	}
	void ChangeMAX(int newMAX)
	{
		MAX = newMAX;
	}
	void ChangeMIN(int newMIN)
	{
		MIN = newMIN;
	}
};
int main()

{
	Counter A;
	A.Input();
	A.Print();

}

Counter::Counter()
{
}
