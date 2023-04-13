#include <iostream>
#include <string>
using namespace std;


/*
������� 1
���������� ����� "�����".
���������� ������� � ����������-������ ������:
- �������� ������,
- ����,
- ��������,
- ����� ������������,
- ���������� ������ �� ������.
���������� �������-����� ������ ��� ����� ������, ������ ������, ���������� ��������� ��� ������� � ��������� ����������-������.

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
		cout << "�������� ������: " << GetName() << endl << "���������: " << GetPrice() << endl << "��������: " << GetDescription() << endl << "�������������: " << GetManufacturer() << endl << "����������: " << GetQuantaty() << endl;
	}

	void Input()
	{
		string temp; 
		size_t temp2;

		cout << "������� �������� ������: " << endl;
		getline(cin, temp);
		SetName(temp);

		cout << "������� ��������� ������: " << endl;
		cin >> (cin, temp2);
		SetPrice(temp2);
		cin.ignore();
		cout << "������� �������� ������: " << endl;
		getline(cin, temp);
		SetDescription(temp);

		cout << "������� ������������� ������: " << endl;
		getline(cin, temp);
		SetManufacturer(temp);

		cout << "������� ���������� ������: " << endl;
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





