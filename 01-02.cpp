#include <iostream>
#include <string>
using namespace std;


/*
Задание 1
Реализуйте класс "Товар".
Необходимо хранить в переменных-членах класса:
- название товара,
- цена,
- описание,
- фирма изготовитель,
- количество товара на складе.
Реализуйте функции-члены класса для ввода данных, вывода данных, реализуйте аксессоры для доступа к отдельным переменным-членам.

*/


class Product
{
private:
	string name;
	size_t price;
	string description;
	string manufacturer;
	size_t quantaty;
public:
	void SetName(string newName)
	{
		name = newName;
	}
	void SetPrice(size_t newPrice)
	{
		price = newPrice;
	}
	void SetDescription(string newDescription)
	{
		description = newDescription;
	}
	void SetManufacturer(string newManufacturer)
	{
		manufacturer = newManufacturer;
	}
	void SetQuantaty(size_t newQuantaty)
	{
		quantaty = newQuantaty;
	}

	string GetName()
	{
		return name;
	}
	size_t GetPrice()
	{
		return price;
	}
	string GetDescription()
	{
		return description;
	}
	string GetManufacturer()
	{
		return manufacturer;
	}
	size_t GetQuantaty()
	{
		return quantaty;
	}

	void Print()
	{
		cout << "Название товара: " << GetName() << endl << "Стоимость: " << GetPrice() << endl << "Описание: " << GetDescription() << endl << "Производитель: " << GetManufacturer() << endl << "Количество: " << GetQuantaty() << endl;
	}

	void Input()
	{
		string temp; 
		size_t temp2;

		cout << "Введите название товара: " << endl;
		getline(cin, temp);
		SetName(temp);

		cout << "Введите стоимость товара: " << endl;
		cin >> (cin, temp2);
		SetPrice(temp2);
		cin.ignore();
		cout << "Введите описание товара: " << endl;
		getline(cin, temp);
		SetDescription(temp);

		cout << "Введите производителя товара: " << endl;
		getline(cin, temp);
		SetManufacturer(temp);

		cout << "Введите количество товара: " << endl;
		cin >> (cin, temp2);
		SetQuantaty(temp2);
		cin.ignore();
	}
};



int main()
	{
		system("chcp 1251 > null");
		Product bread;
		bread.Input();
		bread.Print();

	}





