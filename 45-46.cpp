/*
Задание 2
Создать базовый класс Employer (служащий) с методами Print(), Input().
Создайте три производных класса: President, Manager, Worker.
Переопределите функции Input() и Print() для ввода и вывода информации, соответствующие каждому типу служащего.*/

#include <iostream>
#include <string>

#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;
using namespace std;

class Employer
{
private:
	string FIO;
	int IIN;
	int Bday;
public:
	Employer() : FIO("Unknown"), IIN(), Bday() {}
	Employer(string fio) : FIO(fio), IIN(), Bday() {}
	Employer(string fio, int iin, int bday) : FIO(fio), IIN(iin), Bday(bday) {}

	void Input()
	{
		cout << "FIO: ";
		getline(cin, FIO);
		cout << "IIN: ";
		cin >> IIN;
		cout << "Date of Birth: ";
		(cin >> Bday).ignore();
	}

	void Print()
	{
		cout << "FIO: " << FIO << endl;
		cout << "IIN: " << IIN << endl;
		cout << "Date of Birth: " << Bday << endl;
	}

};//class Employer

class President :public Employer
{
private:

protected:
	int SubsCnt; // колл-во подчиненных
public:
	President() : Employer(), SubsCnt() {}
	President(string fio) : Employer(fio), SubsCnt() {}
	President(string fio, int iin, int bday, int subscnt) : Employer(fio, iin, bday), SubsCnt(subscnt) {}

	void Input()
	{
		Employer::Input();
		cout << "Enter count of your workerks: ";
		cin >> SubsCnt;
	}

	void Print()
	{
		Employer::Print();
		cout << "Count of your workerks:" << SubsCnt << endl;
	}
};//class President

class Manager : public Employer
{
private:

protected:
	int ProjectCnt; // колл-во проектов
public:
	Manager() : Employer(), ProjectCnt() {}
	Manager(string fio) : Employer(fio), ProjectCnt() {}
	Manager(string fio, int iin, int bday, int Pcnt) : Employer(fio, iin, bday), ProjectCnt(Pcnt) {}

	void Input()
	{
		Employer::Input();
		cout << "Enter count of your Projects: ";
		cin >> ProjectCnt;
	}

	void Print()
	{
		Employer::Print();
		cout << "Count of your Projects:" << ProjectCnt << endl;
	}
};//class Manager

class Worker : public Employer
{
private:

protected:
	int GlovesCnt; // колл-во перчаток
public:
	Worker() : Employer(), GlovesCnt() {}
	Worker(string fio) : Employer(fio), GlovesCnt() {}
	Worker(string fio, int iin, int bday, int Gcnt) : Employer(fio, iin, bday), GlovesCnt(Gcnt) {}

	void Input()
	{
		Employer::Input();
		cout << "Enter count of your Gloves: ";
		cin >> GlovesCnt;
	}

	void Print()
	{
		Employer::Print();
		cout << "Count of your Gloves:" << GlovesCnt << endl;
	}
};//class Worker

int main()
{
	Employer E;
	President P;
	Manager M;
	Worker W;
	P.Input();
	M.Input();
	W.Input();
	P.Print();
	M.Print();
	W.Print();

}