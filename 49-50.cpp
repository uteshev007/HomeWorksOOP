/*
Задание 2
Создать абстрактный базовый класс "Домашнее животное" с виртуальными функциями-методами
 Sound() - издает звук животного (пишем текстом в консоль);
 Show() - отображает имя животного;
 Type() - отображает название его подвида.
Создайте производные классы "Собака", "Кошка", "Попугай", "Хомяк".
С помощью конструктора установить имя каждого животного и его характеристики.
В каждом дочернем классе переопределите виртуальные функции базового класса.
Написать функцию, которая по выбору пользователя создает экземпляр класса Liner или SquareEqu 
(функция "фабрики класса" по аналогии с CreateShape())
и возвращает через указатель на базовый класс "Домашнее животное".
*/


#include <iostream>
#include <string>

using namespace std;

class HomePets {
private:
    string Type;
    string Name;
public:
    HomePets(string type) : Type(type) {}
    virtual void Sound() const = 0;
    virtual string Show() const { return Name; }
    virtual string GetType() const { return Type; }
    virtual ~HomePets() {}
};

class Dog : public HomePets {
public:
    Dog() : HomePets("Dog") {}
    virtual void Sound() const override { cout << "Gav-Gav" << endl; }
};

class Cat : public HomePets {
public:
    Cat() : HomePets("Cat") {}
    virtual void Sound() const override { cout << "Meow-Meow" << endl; }
};

class Bunny : public HomePets {
public:
    Bunny() : HomePets("Bunny") {}
    virtual void Sound() const override { cout << "Squeak-Squeak" << endl; }
};

class Humster : public HomePets {
public:
    Humster() : HomePets("Humster") {}
    virtual void Sound() const override { cout << "Chirp-Chirp" << endl; }
};

HomePets* CreatePet(int type) {
    switch (type) {
    case 1: return new Dog;
    case 2: return new Cat;
    case 3: return new Bunny;
    case 4: return new Humster;
    default: return nullptr;
    }
}

int main() {
    while (true) {
        cout << "Choose your pet:\n"
            << "1 - Dog\n"
            << "2 - Cat\n"
            << "3 - Bunny\n"
            << "4 - Humster\n"
            << "0 - Exit\n";

        int choice;
        cin >> choice;
        if (choice == 0) break;

        HomePets* pPet = CreatePet(choice);
        if (pPet) {
            pPet->Sound();
            cout << "------------\n";
            delete pPet;
        }
        else {
            cout << "Error\n";
        }
    }
    cout << "Good bye...\n";
    return 0;
}
