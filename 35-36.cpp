#include <iostream>
#include <queue>
#include <string>
#include <ctime>

#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;
using namespace std;
/*
Домашнее задание
Тема: Очередь

Задание 1.
Разработать приложение, имитирующее очередь печати принтера.
Должны быть клиенты, посылающие запросы на принтер, у каждого из которых есть свой приоритет.
Каждый новый клиент попадает в очередь в зависимости от своего приоритета.
Необходимо сохранять статистику печати (пользователь, время) в отдельной очереди.
Предусмотреть вывод статистики на экран.
*/

template <class T>
class PrinterQueue
{
private:
	T* Data;
	int Size;
	int Count;



public:
	PrinterQueue() : Data(), Size(), Count() {};
	PrinterQueue(int Size_) : Data(new T[Size_]), Size(Size_), Count() {}
	PrinterQueue(const PrinterQueue <T>& q) { *this = q; }
	PrinterQueue <T>& operator = (const PrinterQueue <T>& q)
	{
		if (this == q) { return *this; }
		delete[] Data;
		this->Data = new T[q.GetSize()];
		for (int i = 0; i < q.GetCount(); i++)
		{
			this->Data[i] = q.Data[i];
		}
		this->Size = q.GetSize();
		this->Count = q.GetCount();
		return *this;
	}
	~PrinterQueue() { delete[] Data; }

	int GetSize() { return Size; }
	int GetCount() { return Count; }
	bool IsEmpty() { return Count == 0; }
	bool IsFull() { return Size == Count; }

	void SetSize(int newSize)
	{
		T* temp = new T[newSize];
		int minCount = (newSize < Count) ? newSize : Count;
		for (int i = 0; i < minCount; i++)
		{
			temp[i] = Data[i];
			delete[] Data;
			Data = temp;
			Size = newSize;
			Count = minCount;
		}
	}

	void Clear() { Count = 0; }
	void EnQueue(T val)
	{
		if (IsFull())
			SetSize(Size * 1.5 + 1);
		Data[Count+] = val;
	}

	T DeQueue()
	{
		if (IsEmpty())
			throw "Error!";
		T temp;
		temp = Data[0];
		for (int i = 0; i < Count - 1; i++)
		{
			Data[i] = Data[i] + 1;
		}
		return temp;
	}
	T GetFirst()
	{
		if (IsEmpty())
			throw "Error!";
		return Data[0];
	}
	//T& GetFirst()
	//{
	//	if (IsEmpty())
	//		throw "Error!";
	//	return Data[0];
	//}

	friend ostream& operator<<(ostream& os, PrinterQueue<T>& q)
	{
		os << "Size = " << q.GetSize() << endl;
		os << "Count = " << q.GetCount() << endl;
		for (int i = 0; i < q.GetCount(); i++)
		{
			os << q.Data[i] << endl;
		}
		return os;
	}


};//PrinterQueue

class Time
{
private:
	int hour, minute, second;
public:
	Time() : hour(), minute(), second() {}
	Time(int h, int m, int s) { hour = h, minute = m, second = s; }
	void Sethour(int h)
	{
		if (h <= 12 && h >= 0 || h <= 24 && h >= 0)
			this->hour = h;
	}
	void Setminute(int m)
	{
		if (m <= 60 && m >= 0)
			this->minute = m;
	}
	void Setsecond(int s)
	{
		if (s <= 60 && s >= 0)
			this->second = s;
	}
	int Gethour() { return hour; }
	int Getminute() { return minute; }
	int Getsecond() { return second; }
	void TShow() { cout << "Time: " << hour << ":" << minute << ":" << second << endl; }

	friend ostream& operator << (ostream& os, Time obj)
	{
		os << obj.hour << ":" << obj.minute << ":" << obj.second << endl;
		return os;
	}


};//Time

class Client
{
private:
	string name;
	int priority;
	Time* ClientTime;
public:
	Client() : name("Unkonow"), priority(), ClientTime() {}
	Client(string name, int priority, Time* time) { this->name = name, this->priority = priority, this->ClientTime = time; }
	void Setname(string name) { this->name = name; }
	void Setpriority(int pr) { priority = pr; }
	void SetTime(int h, int m, int s) { this->ClientTime->Sethour(h), this->ClientTime->Setminute(m), this->ClientTime->Setsecond(s);}
	string Getname() { return this->name; }
	int Getpriority() { return this->priority; }
	Time& GetClientTime() { return *ClientTime; }
	void Show()
	{
		cout << "Name: " << this->Getname() << endl;
		cout << "Priority: " << this->Getpriority() << endl;
		cout << "Time: " << GetClientTime() << endl;
	}
};//Client

int main()
{
	Time Time1(11,00,42);
	Client One ("John Doe", 20, &Time1);
	One.Show();
	PrinterQueue <int> printer;
	printer.EnQueue(One.Getpriority());
	cout << printer;
}