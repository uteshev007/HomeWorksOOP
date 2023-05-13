#include <iostream>
#include <string>

using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;

/*
Домашнее задание
Тема. Конструктор копирования

Задание 1
Создать класс Строка - String
Поля, переменные класса:
- длина строки без учета нуль-терминатора;
- указатель (char*) на блок памяти, где хранится строка;
  память выделять динамически!

Функции-члены класса:
- конструктор с параметром - строка (char* или const char*);
- конструктор с параметром - длина строки;
- конструктор копирования;
- деструктор;
- вывод строки на экран;
- сеттер, принимающий в качестве параметра - строку (char* или const char*).
  При нехватке уже выделенного блока динамической памяти
  для копирования в  него строки-параметра - произвести корректное перевыделение памяти.

Примечание: перечень полей и функций-членов в заданиях 1-3 является рекомендованным, а не окончательным.
При необходимости возможно добавление требуемых или желаемых полей и функций-членов.

*/



class String {
private:
    char* str;

public:

    String()
    {
        str = nullptr;
    }

    String(const char* str) 
    {
        int length = strlen(str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }
        this->str[length] = '/0';
    }

    // конструктор с параметром - длина строки
    String(size_t length) 
    {
        length = length;
        str = new char[length + 1];
        str[0] = '\0';
    }

    // конструктор копирования
    String & operator = (const String& other) 
    {
        if (this->str != nullptr)
        {
            delete[] str;
        }
        int length = strlen(other.str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[length] = '/0';
        return * this;
    }

    // деструктор
    ~String() {
        delete[] this->str;
    }

    void PrintStr() const
    {
        cout << str << endl;
    }
    void GetStr()
    {

    }
    void SetStr(char * str)
    {
        cout << "Введите строку: ";
        cin >> str;
    }

};

int main() 
{
    String A;
    A.PrintStr('Hello');
}