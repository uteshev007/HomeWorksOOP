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
private: 
	int InSec;
public:
	Time()
	{
		int InSec = 0;
	}
	Time(int InSec)
	{
		this->InSec += InSec;
	}
	~Time(){}

	int SetTime(int sec)
	{
		return InSec = sec;
	}

	void PrintTime()
	{

		int hour, min, sec;
		hour = InSec / 3600;
		min = (InSec - (hour * 3600)) / 60;
		sec = (InSec - (hour * 3600)) - (min * 60);
		cout << "Your time is: " << hour << ":" << min << ":" << sec << endl;
	}

	Time operator + (const Time& sec)
	{
		Time temp;
		temp.InSec = this->InSec + sec.InSec;
		return temp;
	}
	Time operator - (int sec)
	{
		Time temp;
		temp.InSec = InSec - sec;
		return temp;
	}
	Time operator - (const Time& sec)
	{
		Time temp;
		temp.InSec = this->InSec - sec.InSec;
		temp.InSec = abs(temp.InSec);
		return temp;
	}
	int IncSec()
	{
		return InSec++;
	}
};

int main()
{
	Time A;
	A.SetTime(83540);
	A.PrintTime();
	Time B;
	B.SetTime(60);
	Time C = A + B;
	B.PrintTime();
	C.PrintTime();
	Time D = A - 120;
	D.PrintTime();
	Time E = D - A;
	E.PrintTime();
	E.IncSec();
	E.PrintTime();
}