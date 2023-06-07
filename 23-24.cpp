#include <iostream>

using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;

/*
Домашнее задание
Тема. Перегрузка операторов ++, --

Задание 1
Создайте класс Circle (окружность).
Реализуйте через перегруженные операторы:
1. Проверка на равенство радиусов двух окружностей (операция ==);
2. Сравнения длин двух окружностей (операция < );
3. Пропорциональное изменение размеров окружности, путем изменения ее радиуса (операция += и -=);
4. Увеличение и уменьшение радиуса окружности на 1 (операции ++ и --, в префиксной и постфиксной формах);

*/

class Circle
{
private:
	int C;
	int R;
	const double P = 3.14;

public:
	Circle() : C(), R() {}
	Circle(int C) { this->C = C; }
	Circle(int C, int R)
	{
		this->C = C;
		this->R = R;
	}
	void SetC(int C) { this->C = C; }
	void SetR(int R) { this->R = R; }

	int GetC() const { return C; }
	int GetR() const { return R; }

	friend istream& operator >> (istream& is, Circle obj)
	{
		cout << "Input Circumference of Circle: ";
		is >> obj.C;
		cout << "Input Radius of Circle: ";
		is >> obj.R;
		return is;
	}
	friend ostream& operator << (ostream& os, Circle obj)
	{
		os << "Circumference of Circke is: " << obj.C << endl;
		os << "Radius of Circke is: " << obj.R << endl;
		return os;
	}

	bool operator == (Circle circum)
	{
		return this->C == circum.C;
	}

	bool operator < (Circle circum)
	{
		return this->C < circum.C;
	}

	Circle operator += (int R)
	{
		this->R = R;
		return C = (2 * P * R);
	}

	Circle operator ++()
	{
		++R;
		return *this;
	}

	Circle operator ++(int)
	{
		R++;
		return *this;
	}


}; //Circle

	void CheckC(Circle first, Circle second)
	{
		if (first < second)
			cout << "First Circle < than second;" << endl;
		else
			cout << "First Circle > than second;" << endl;

	}



int main()
{
	Circle A;
	Circle B;
	A.SetC(25);
	B.SetC(10);
	CheckC(A,B);
	A += 20;
	cout << A;
	A++;
	cout << A;
	++A;
	cout << A;
}