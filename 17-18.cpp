#include <iostream>
#include <string>

using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))


/*
Тема: 13-14. Перегрузка операторов

1. Создайте класс с именем Time для хранения времени (или используйте уже ранее созданный вами).
Напишите соответствующие конструкторы и функции-члены.
Используя перегрузку операторов реализуйте для него арифметические операции для работы с классом Time:
a) операция "+" для целого числа секунд: к времени Time прибавить целое число секунд (Time + int).
b) операция "-" для целого числа секунд: от времени Time отнять целое число секунд (Time - int). Результат типа Time.
c) операция "-" для определения разницы между двумя веременами (Time - Time). Результат типа Time.
Добавьте в класс метод для приращения времени (которое хранится в объкте Time) на 1 секунду.

Дополнительно
2. Создайте класс Дробь (или используйте уже ранее созданный вами).
Используя перегрузку операторов реализуйте для него арифметические операции для работы с дробями: операции +, -, *, /.

*/

class Time
{
public:
	Time() 
	{
		size = 3;
		time = new int[size];

	}
	~Time() { delete[] time; }

	void SetTime()
	{
		int hour, min, sec;
		cout << "Enter hour: ";
		cin >> hour;
		time[0] = hour;
		cout << "Enter minute: ";
		cin >> min;
		time[1] = min;
		cout << "Enter second: ";
		cin >> sec;
		time[2] = sec;
	}
	int* GetTime()
	{
		return time;
	}
	void Print()
	{
			cout << "Your time is: " << endl;
			cout << time[0] << ":" << time[1] << ":" << time[2];
	}
	
	int operator + (const Time& t2)
	{
		return int (time[2] + t2.time[2]);
	}



private:
	int *time;
	int size;


};

int main()
{
	Time A, C; 
	A.SetTime();
	A.Print();
	C.SetTime();
	A + C;
}