/*

Домашнее задание
Тема.Множественное наследование

Задание 1
Используя механизм множественного наследования разработайте класс "Автомобиль".
Должны быть базовые классы "Колеса", "Двигатель", "Двери" и т.д., от которых порождается класс "Автомобиль".

*/

#include <iostream>
#include <string>

#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;
using namespace std;

class Wheels
{
private:
	string Brand;
	string Season;
	string Size;
public:
	Wheels() :Brand("unknown"), Season("winter"), Size("205/65/R16") {}
	Wheels(string brand, string type, string size ) :Brand(brand), Season(type), Size(size) {}

	void SetBrand(string newbrand) { this->Brand = newbrand; }
	void SetSeason(string newseason) { this->Season = newseason; }
	void SetSize(string newsize) { this->Size = newsize; }

	string GetBrand() const { return Brand; }
	string GetSeason() const { return Season; }
	string GetSize() const { return Size; }

	void AddWheel()
	{
		string brand, season, size;
		cout << "Enter Brand name of wheels: ";
		cin >> brand;
		SetBrand(brand);
		cout << "Enter season of wheels: ";
		cin >> season;
		SetSeason(season);
		cout << "Enter size of wheels: ";
		cin >> size;
		SetSize(size);
	}

	void Print()
	{
		cout << "\n ____ I N F O ____ W H E E L S ____\n";
		cout << "| Brand name: " << GetBrand() << endl;
		cout << "| Season: " << GetSeason() << endl;
		cout << "| Size: " << GetSize() << endl;
		cout << "|____________________________________"<< endl;
	}

};//class Wheels

class Engine
{
private:
	double Capacity;
	string Type;
public:
	Engine() : Capacity(1.6), Type("Gasoline") {}
	Engine(double cap, string type) : Capacity(cap), Type(type) {}

	void SetCapacity(double cap) { Capacity = cap; }
	void SetType(string type) { Type = type; }

	double GetCapacity() const { return Capacity; }
	string GetType() const { return Type; }

	void AddEngine()
	{
		double capa;
		string type;

		cout << "Enter Capacity of engine: ";
		cin >> capa;
		SetCapacity(capa);

		cout << "Enter type of engine: ";
		cin >> type;
		SetType(type);
	}

	void Print()
	{
		cout << "\n ____ I N F O ____ E N G I N E ____\n";
		cout << "| Capacity : " << GetCapacity() << endl;
		cout << "| Gas Type : " << GetType() << endl;
		cout << "|____________________________________" << endl;
	}

	
};//class Engine

class Doors
{
private:
	string Color;
	int Count;

public:
	Doors() : Color("white"), Count(4) {}
	Doors(string color, int cnt) :Color(color), Count(cnt) {}

	void SetColor(string color) { Color = color; }
	void SetCount(int cnt) { Count = cnt; }

	string GetColor() const { return Color; }
	int GetCount() const { return Count; }

	void AddDoors()
	{
		string color;
		int cnt;
		cout << "Enter color of door: ";
		cin >> color;
		SetColor(color);
		
		cout << "Enter count of doors: ";
		cin >> cnt;
		SetCount(cnt);
	}

	void Print()
	{
		cout << "\n ____ I N F O ____ D O O R S ____\n";
		cout << "| Color : " << GetColor() << endl;
		cout << "| Count of doors : " << GetCount() << endl;
		cout << "|____________________________________" << endl;
	}

}; //class Doors

class Car : public Wheels, public Doors, public Engine
{
private:
	string Name;
public:
	Car() : Name("Audi") {}
	Car(string name) :Name(name) {}

	void Print()
	{
		Engine::Print();
		Doors::Print();
		Wheels::Print();
	}
};


int main()
{
	Wheels W;
	W.AddWheel();
	Engine E;
	E.AddEngine();
	Doors D;
	D.AddDoors();
	Car C;
	C.Print();

}