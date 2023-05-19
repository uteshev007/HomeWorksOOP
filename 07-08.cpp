#include <iostream>
#include <string>

using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;

/*
Задание 1a
*Реализуйте класс "Товар" (или используйте ранее созданный класс).
Необходимо хранить в переменных-членах класса:
- название товара,
- цена,
- описание,
- фирма изготовитель,
- количество товара на складе.
Используйте конструкторы, делегирование конструкторов.
Реализуйте аксессоры для доступа к отдельным переменным-членам - get/set-методы.
Реализуйте функции-члены класса для ввода данных с консоли, вывода данных на консоль.
*/

class Product
{
private:
	string name;
	int price;
	string description;
	string manufacturer;
	int quantaty;

public:
	Product() {};
	Product(string name) 
		: name(name), price(), description("null"), manufacturer("null"), quantaty() {}
	Product(string name, string description, string manufacturer) 
		: name(name), price(), description(description), manufacturer(manufacturer), quantaty(){}
	Product(int price, int quantaty)
		: name("null"), price(price), description("null"), manufacturer("null"), quantaty(quantaty) {}




	

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
	int GetPrice()
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
	int GetQuantaty()
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

	cout << "---Делегирующий констурктор с 2 параметрами ЦЕНА и КОЛ----" << endl;
	Product B(200,20);
	B.Print();
	cout << "-----Делегирующий констурктор с 3 параметрами НАЗВАНИЕ ОПИСАНИЕ ПРОИЗВОДСТВО----" << endl;
	Product C("Tea", "Black", "India");
	C.Print();
	cout << "------------------------" << endl;
	Product A;
	A.Input();
	A.Print();
}