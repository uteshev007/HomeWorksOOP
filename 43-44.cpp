/*
Домашнее задание
Тема: Наследование

Задание 2
Создайте класс удостоверение Сertificate, который будет содержать информацию о гражданине Казахстана.
С помощью механизма наследования, реализуйте класс ForeignPassport (загран.паспорт) производный от Сertificate.
Напомним, что заграничный паспорт содержит помимо паспортных данных, также данные о визах, номер заграничного паспорта.
*/

#include <iostream>
#include <string>

#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;
using namespace std;

class Certificate
{
private:
	string FIO;
	int IIN;
	int Bday;
public:
	Certificate() : FIO("Unknown"), IIN(), Bday() {}
	Certificate(string fio) : FIO(fio), IIN(), Bday() {}
	Certificate(string fio, int iin, int bday) : FIO(fio), IIN(iin), Bday(bday) {}

	void SetFIO()
	{
		string fio;
		cout << "Enter FIO: ";
		cin >> fio;
		this->FIO = fio;
	}

	void SetIIN()
	{
		int iin;
		cout << "Enter IIN: ";
		cin >> iin;
		this->IIN = iin;
	}

	void SetBday()
	{
		int bday;
		cout << "Enter Date of Birth: ";
		cin >> bday;
		this->Bday = bday;
	}

	void Input()
	{
		SetFIO();
		SetIIN();
		SetBday();
	}

	string GetFIO() const { return FIO; }
	int GetIIN() const { return IIN; }
	int GetBday() const { return Bday; }

};// class Certificate;

class ForeighnPassport : public Certificate
{
private:
protected:
	int VisaCnt;
	int PassNum;

public:
	ForeighnPassport() : Certificate(), VisaCnt(), PassNum() {}
	ForeighnPassport(string fio) : Certificate(fio), VisaCnt(), PassNum() {}
	ForeighnPassport(string fio, int iin, int bday, int visacnt, int pnum) 
		: Certificate(fio, iin, bday), VisaCnt(visacnt), PassNum(pnum) {}

	void Input()
	{
		int visacnt, pnum;
		Certificate::Input();
		cout << "Enter count of Visas: ";
		cin >> visacnt;
		cout << "Enter number of Passport: ";
		cin >> pnum;

	}

}; //class Foreighn Passport;

int main()
{
	Certificate C;
	C.Input();
	ForeighnPassport F;
	F.Input();
}