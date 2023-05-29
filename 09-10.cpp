#include <iostream>
#include <string>

using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;

/*
Домашнее задание
Тема. Делегирование конструкторов

Задание 1
Создайте приложение "Телефонная книга".
Для этого необходимо хранить данные об абоненте:
- ФИО;
- домашний телефон;
- рабочий телефон;
- мобильный телефон;
- дополнительная информация о контакте;
внутри соответствующего класса, например Abonent.
Наполните класс переменными-членами, функциями-членами, конструкторами.

Потом создайте класс "Телефонная книга" (PhoneBook), который будет хранить массив абонентов.
Наполните необходимыми переменными, конструкторами, методами.
В программе предоставьте пользователю возможность
- показывать всех абонентов,
- добавлять новых абонентов,
- удалять абонентов,
- искать абонентов по ФИО или телефону,
- сортировать абонентов по ФИО или телефону,
- сохранять информацию в файл,
- загружать из файла.
*/


class Abonent
{
private:
	string fio;
	string hometel;
	string jobtel;
	string mobtel;
	string info;



public:
	void SetFio(string newfio) { fio = newfio; }
	void SetHomeTel(string newhometel) { hometel = newhometel; }
	void SetJobTel(string newjobtel) { jobtel = newjobtel; }
	void SetMobTel(string newmobtel) { mobtel = newmobtel; }
	void SetInfo(string newinfo) { info = newinfo; }

	string GetFio() { return fio; }
	string GetHomeTel() { return hometel; }
	string GetJobTel() { return jobtel; }
	string GetMobTel() { return mobtel; }
	string GetInfo() { return info; }

	Abonent() {};
	Abonent(string fio, string mobtel) : fio(fio), hometel("empty"), jobtel("empty"), mobtel(mobtel), info("empty") {}

	void Print()
	{
		cout << "ФИО: " << GetFio() << endl << "Домашний Телефон: " << GetHomeTel() << endl << "Рабочий Телефон: ";
		cout << GetJobTel() << endl << "Мобильный телефон: " << GetMobTel() << endl << "Дополнительная информация: " << GetInfo() << endl;
	}
};
// class Abonent

class PhoneBook
{
private:
	Abonent* Data;
	size_t SizeMas;






public:

	PhoneBook();
	PhoneBook(Abonent* dates, size_t count);
	PhoneBook(Abonent data) : PhoneBook(&data, 1) {}

	void SetSizeMas(size_t newSizeMas) {}
	void SetData(Abonent* newdata, size_t newSize) {}
	size_t GetSize() { return SizeMas; }
	Abonent* GetData() { return Data; }

	void Sort()
	{
		for (int i = 0; i < GetSize(); i++)
		{
			for (int j = GetSize() - 1; j > i; j++)
			{
				if (Data[j].GetFio() < Data[j - 1].GetFio())
					swap(Data[j], Data[j - 1]);
			}
		}
	};
	void ShowAll()
	{
		for (int i = 0; i < SizeMas; i++)
		{
			Data[i].Print();
			cout << "------------------------";
		}
		cout << endl;
	}

	void Add(Abonent data)
	{
		SetSizeMas(SizeMas + 1);
		Data[SizeMas - 1] = data;
	};


	void Delete(size_t Index)
	{
		if (Index >= SizeMas) {
			cout << "ERROR: выход за границы массива!\n";
			return; 
		}
		Abonent* temp = new Abonent[SizeMas - 1];

		for (size_t i = 0; i < Index; i++) {
			temp[i] = Data[i];
		}
		for (size_t i = Index; i < SizeMas - 1; i++) {
			temp[i] = Data[i + 1];
		}
		delete[]Data;
		Data = temp;
		SizeMas--;
	}
	size_t Search(string Name, size_t Start = 0)
	{
		for (size_t i = Start; i < SizeMas; i++) {
			if (Data[i].GetFio() == Name) { return i; }
		}
		return -1;
	}

	~PhoneBook();
};
// class PhoneBook


int main()
{
	Abonent A("Uteshev", "87782683837");
	PhoneBook P;




}