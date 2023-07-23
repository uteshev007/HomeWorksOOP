/*
Домашнее задание
Тема: Виртуальные функции. Абстрактный класс

Задание 1
Написать программу эмуляции работы с базами данных (СУБД).
Стартовый код в файлах:
"3-Работа в классе-DataBase.H.txt"
"3-Работа в классе-Main.cpp.txt"

Для этого
- реализовать базовый класс DataBase;
- реализовать производные классы MsSQL, ORACLE, PostgeeSQL и пр.;
- реализовать функцию SelectDB() для выбора типа СУБД (пользователем или случайно);
- реализовать функцию CreateReqSQL() генерации SQL-запроса (пользователем или случайно).

Проверить работоспособность объектов и функций - в ф-ции main() есть код для проверки.
*/
#include <iostream>
#include <string>

#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;
using namespace std;

// базовый класс для работы с СУБД
class DataBase {
private:
	string  typeDB; // тип СУБД - имя класса
protected:
	bool    bIsOpen; // =true, если БД открыта
public:
	DataBase();
	virtual void init();
	virtual void open(string& user, string& pass);
	virtual bool IsOpen() const;

	// Обнуление метода - чисто виртуальный метод
	virtual void Execute(string& reqSql) = 0;
	virtual string Result() = 0;
	virtual void close();
	string getTypeBD() const;
	~DataBase() {}
}; // class DataBase


// производные классы
class MsSQL {
public:
	MsSQL();
	virtual void init();
	virtual void open(string& user, string& pass);
	virtual bool IsOpen() const;
	virtual void Execute(string& reqSql);
	virtual string Result();
	virtual void close();
private:
	string resTable; // результат запроса
}; // class MsSQL



class ORACLE
{
public:
	ORACLE();
	virtual string Result();
};
