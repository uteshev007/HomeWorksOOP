#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <time.h>

#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;
using namespace std;
/*
Домашнее задание
Тема. Списки. Двусвязный список

Обязательное задание одно из двух на выбор

Задание 1 (по теме класс vector<>)

Создайте приложение для работы автосалона.
Необходимо хранить информацию о продаваемых автомобилях (название, год выпуска, объем двигателя, цену).
Реализуйте интерфейс для добавления данных, удаления данных, отображения данных, сортировке данных по различным параметрам, поиску данных по различным параметрам.
При реализации используйте контейнер вектор vector<> из стандартной библиотеки шаблонов.
*/

class cars
{
private:
	string name;
	int year;
	double engine;
	int price;
public:
	cars() : name("Unknown"), year(), engine(), price() {}
	cars(string name) : cars() { this->name = name; }
	cars(string name, int year, double engine, int price) 
	{ 
		this->name = name;
		this->year = year;
		this->engine = engine;
		this->price = price;
	}
	void SetName(string name) { this->name = name; }
	void SetYear(int year) { this->year = year; }
	void SetEngine(double engine) { this->engine = engine; }
	void SetPrice(int price) { this->price = price; }

	string GetName() const { return name; }
	int GetYear() const { return year; }
	double GetEngine() const { return engine; }
	int GetPrice() const { return price; }

	friend ostream& operator << (ostream & os, cars & obj)
	{
		os << "Name: " << obj.GetName();
		os << "Year: " << obj.GetYear();
		os << "Engine: " << obj.GetEngine();
		os << "Price: " << obj.GetPrice();
		return os;
	}

}; // cars;

class Salon
{
private:
public:
	vector<cars> SalonCars;
	void ShowCars(vector<cars>& SalonCars)
	{
		if (SalonCars.empty())
			cout << "Salon is empty" << endl;
		cout << "____________________________________________" << endl;
		cout << "       List of cars in this salon" << endl;
		for (const auto& SalonCars : SalonCars)
		{
			cout << "____________________________________________" << endl;	
			cout << "Name: " << SalonCars.GetName() << endl;
			cout << "Year: " << SalonCars.GetYear() << endl;
			cout << "Engine: " << SalonCars.GetEngine() << endl;
			cout << "Price: " << SalonCars.GetPrice() << endl;
		}
			cout << "____________________________________________" << endl;
	}

	void AddCar(cars& obj)
	{
		string temp;
		int temp2 = 0;
		double temp3 = 0;
		cout << "Enter name of car: ";
		cin >> temp;
		obj.SetName(temp);
		cout << "Enter year of car: ";
		cin >> temp2;
		obj.SetYear(temp2);
		cout << "Enter engine of car: ";
		cin >> temp3;
		obj.SetEngine(temp3);
		cout << "Enter price of car: ";
		cin >> temp2;
		obj.SetPrice(temp2);
		SalonCars.push_back(obj);
	}

	void DelCar(vector<cars>& SalonCars)
	{
		cars temp;
		string name;
		cout << "Enter the name of deleting car: ";
		cin >> name;
		for (const auto& SalonCars : SalonCars)
		{
			SalonCars.GetName();
			if (name == SalonCars.GetName())
				temp = SalonCars.GetName();
			else
				cout << "Car is not found!";
				
		}
	}
}; // Salon


int main()
{
	Salon Aster;
	//vector <cars> SalonCars;
	cars Audi("TT", 2012, 2.0, 4000);
	cars Toyota("Camry", 2018, 3.0, 8000);
	cars Lada("Samara 2114", 2002, 1.6, 1000);
	cars Mazda;
	Aster.SalonCars.push_back(Audi);
	Aster.SalonCars.push_back(Toyota);
	Aster.SalonCars.push_back(Lada);
	//Aster.AddCar(Mazda);
	Aster.ShowCars(Aster.SalonCars);
	Aster.DelCar(Aster.SalonCars);
	Aster.ShowCars(Aster.SalonCars);
}