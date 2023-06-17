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
Тема. Класс Vector. Стек

Задание 1.

По аналогии с "2-Работа в классе-Book.txt",
используя класс std::vector<> стандартной библиотеки языка C++,
реализуйте объект "Магазин", как вектор (массив) объектов "Товар".

Описание класса "Товар" и его реализацию можно взять из решения домашней работы урока "07-08. Делегирование конструкторов"

Для объекта-вектора "Магазин" реализуйте следущие возможности:
- Ввод данных с консоли для товаров.
- Случайное (рандомное) заполнение товаров.
- Печать всех товаров.
- Печать только тех товаров, цена которых лежит в указанном диапазоне. Диапазон цен вводит пользователь.
- Поиск товара по названию товара.
- Поиск товара по названию фирмы изготовителя.
- Сортировка товаров по названию товара/цене/описанию/фирмы изготовителя/количества.

*/

class Product
{
private:
	string name;
	int price;
	int quantaty;
public:
	Product() : name("Unknown"), price(), quantaty() {}
	Product(string name) : Product() { this->name = name; }
	~Product() {}

	void Setname(string newname) { name = newname; cin >> newname; }
	void Setprice(int newprice) { price = newprice; cin >> newprice; }
	void Setquantaty(int newquantaty) { quantaty = newquantaty; cin >> newquantaty; }

	string Getname() const { return name; }
	int Getprice() const { return price; }
	int Getquantaty() const { return quantaty; }

	friend ostream& operator << (ostream& os, const Product& obj)
	{
		os << left
			<< setw(9) << obj.Getname() << "|"
			<< setw(5) << obj.Getprice() << "|"
			<< setw(8) << obj.Getquantaty() << "|";
		return os;
	}


	void InitRand()
	{
		string temp;
		int size = RAND(4, 8);
		temp = RAND('A', 'Z');
		for (int i = 0; i < size; i++)
		{
			char symbol = RAND('a', 'z');
			temp += symbol;
		}
		Setname(temp);
		int RandPrice = RAND(500, 2000);
		int RandQuantaty = RAND(2, 12);
		Setprice(RandPrice);
		Setquantaty(RandQuantaty);

	}

	void AddProduct()
	{
		string temp;
		cout << "\n Enter the name of product: ";
		(cin >> temp).ignore();
		Setname(temp);
		cout << "\n Enter the price of product: ";
		int tprice;
		(cin >> tprice).ignore();
		Setprice(tprice);
		cout << "\n Enter the quantaty of product: ";
		int tquantaty;
		(cin >> tquantaty).ignore();
		Setquantaty(tquantaty);

	}
}; // Product


ostream& operator << (ostream& os, const vector <Product>& obj)
{
	os << "______________________________" << endl;
	os << "|" << setw(3) << left << "N" << "|" << setw(9) << "Name" << "|" << setw(5) << "Price" << "|" << setw(8) << "Quantaty" << "|" << endl;
	os << "______________________________" << endl;
	for (int i = 0; i < obj.size(); i++)
	{
		os << "|" << setw(3) << left << i + 1 << "|" << obj[i] << endl;
	}
	os << "______________________________" << endl;
	return os;
}

istream& operator >> (istream& is, vector <Product>& obj)
{
	int numproduct;
	cout << "Enter the number of products: ";
	(cin >> numproduct).ignore();
	obj.resize(numproduct);
	for (int i = 0; i < obj.size(); i++)
		obj[i].InitRand();
	return is;
}


		


int main()
{
	vector <Product> products;
	cin >> products;
	cout << products;


}