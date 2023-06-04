#include <iostream>
#include <string>

using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;

/*
Домашнее задание
Тема: Перегрузка операторов.

Задание 1.
Создать класс Overcoat (верхняя одежда).
Реализовать перегруженные операторы:
1. Проверка на равенство типов одежды (операция == ).
2. Операцию присваивания одного объекта в другой (операция = ).
3. Сравнение по цене двух пальто одного типа (операции >, >=, <, <= ).

Задание 2.
Создайте класс Circle (окружность).
Реализуйте через перегруженные операторы:
1. Проверка на равенство радиусов двух окружностей (операция ==);
2. Сравнения длин двух окружностей (операция < );
3. Пропорциональное изменение размеров окружности, путем изменения ее радиуса (операция += и -=)
*/

class Overcoat
{
private:
	string type;
	string color;
	unsigned int price;

public:
	Overcoat() : Overcoat ("Unkonow", "Unknown", 0) {}
	Overcoat(string type, string color, unsigned int price) 
	{
		this->type = type;
		this->color = color;
		this->price = price;
	}
	Overcoat(string type) : Overcoat(type, "Unknown", 0) {}
	//Overcoat(string color) : Overcoat("Unknown", color, 0) {}

	string GetType() const { return type; }
	friend ostream& operator << (ostream& os, const Overcoat& obj)
	{
		os << "Type: " << obj.type << endl
			<< "Color: " << obj.color << endl
			<< "Price: " << obj.price << endl;
		return os;
	}

	friend istream& operator >> (istream& is, Overcoat& obj)
	{
		cout << "Enter Type of dress: ";
		is >> obj.type;
		cout << "Enter Color of dress: ";
		is >> obj.color;
		cout << "Enter Price of dress: ";
		is >> obj.price;
		return is;
	}

	bool operator == (const Overcoat&  other) const
	{
		return this->type == other.type;
	}

	Overcoat operator = (const Overcoat& other)
	{
		Overcoat res;
		this->type = other.type;
		this->color = other.color;
		this->price = other.price;
		return res;

	}

	bool operator < (const Overcoat& other) const
	{
		return this->price < other.price;
	}

	bool operator <= (const Overcoat& other) const
	{
		return (this ->price < other.price) || (this->price == other.price);
	}

	bool operator > (const Overcoat& other) const
	{
		return this->price > other.price;
	}

	bool operator >= (const Overcoat& other) const
	{
		return (this ->price > other.price) || (this->price == other.price);
	}
};


int main()
{
	Overcoat A("T-Shirt", "Black", 4000);
	Overcoat B("Sweater", "Brown", 8000);
	Overcoat C("Coat", "Grey", 20000);
	cout << A;
	Overcoat D;
	cin >> D;
	cout << D;
	if (A == B)
		cout << "obj Type == obj Type" << endl;
	else
		cout << "obj Type != obj Type" << endl;
	Overcoat E = A;
	cout << E;
	C < B;
	if (C > B)
		cout << "Price of " << C.GetType() << " > " << B.GetType() << endl;
	else
		cout << "Price of " << C.GetType() << " < " << B.GetType() << endl;

}