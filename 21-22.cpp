﻿#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;



/*
Домашнее задание

Тема: Перегрузка операторов

Задание 1
Доделать работу в классе "1-Работа в классе-CatDog.txt".
Реализовать класс DogCat и перегруженный оператор сложения
для объектов Dog и Cat, что бы выпонились операции
из ф-ции main() (закомментированный в конце main код):
DogCat DC = dog + cat;
cout << DC << endl;
*/


/*
  Перегрузка операторов

    CatDog = Cat + Dog
    ? = Dog + Cat

*/

// Прототипы классов

class CatDog;
class Dog;
class Cat;

class Cat {
private:
    string name;
    int age;
    string breed;
    int life;
public:
    Cat() : name("Murka"), age(1), breed("no"), life(13) {}
    Cat(string name, int age) : Cat() {
        this->name = name;
        this->age = age;
    }
    void SetName(string name) { this->name = name; }
    void SetAge(int age) { this->age = age; }
    void SetLife(int life) { this->life = life; }
    void SetBreed(string breed) { this->breed = breed; }

    string GetName() const { return name; }
    int GetAge() const { return age; }
    string GetBreed() const { return breed; }
    int GetLife() const { return life; }

    friend ostream& operator << (ostream& os, const Cat& obj) {
        os << "Name: " << obj.name << endl;
        os << "Age: " << obj.age << endl;
        os << "Breed: " << obj.breed << endl;
        os << "Life: " << obj.life << endl;
        return os;
    }
    friend istream& operator >> (istream& is, Cat& obj) {
        cout << "Input name: ";
        getline(is, obj.name);
        cout << "Input age: ";
        (is >> obj.age).ignore();
        //is.ignore();
        cout << "Input breed: ";
        getline(is, obj.breed);
        cout << "Input life: ";
        (is >> obj.life).ignore();
        //is.ignore();
        return is;
    }
};

class Dog {
private:
    string name;
    int age;
    string breed;
    int command;
public:
    Dog() : name("Bob"), age(1), breed("no"), command(0) {}
    Dog(string name, int age) : Dog() {
        this->name = name;
        this->age = age;
    }
    void SetName(string name) { this->name = name; }
    void SetAge(int age) { this->age = age; }
    void SetCommand(int command) { this->command = command; }
    void SetBreed(string breed) { this->breed = breed; }

    string GetName() const { return name; }
    int GetAge() const { return age; }
    string GetBreed() const { return breed; }
    int GetCommand() const { return command; }

    friend ostream& operator << (ostream& os, const Dog& obj) {
        os << "Name: " << obj.name << endl;
        os << "Age: " << obj.age << endl;
        os << "Breed: " << obj.breed << endl;
        os << "Command: " << obj.command << endl;
        return os;
    }
    friend istream& operator >> (istream& is, Dog& obj) {
        cout << "Input name: ";
        getline(is, obj.name);
        cout << "Input age: ";
        (is >> obj.age).ignore();
        //is.ignore();
        cout << "Input breed: ";
        getline(is, obj.breed);
        cout << "Input command: ";
        (is >> obj.command).ignore();
        //is.ignore();
        return is;
    }
};

class CatDog {
private:
    string name;
    int age;
    string breed;
    int life;
    int command;
public:
    CatDog() : name("Kotopes"), age(1), breed("mixed"), life(), command(1) {}
    CatDog(string name, int age) : CatDog() {
        this->name = name;
        this->age = age;
    }
    void SetName(string name) { this->name = name; }
    void SetAge(int age) { this->age = age; }
    void SetLife(int life) { this->life = life; }
    void SetBreed(string breed) { this->breed = breed; }
    void SetCommand(int command) { this->command = command; }

    string GetName() const { return name; }
    int GetAge() const { return age; }
    string GetBreed() const { return breed; }
    int GetLife() const { return life; }
    int GetCommand() const { return command; }

    friend ostream& operator << (ostream& os, const CatDog& obj) {
        os << "Name: " << obj.name << endl;
        os << "Age: " << obj.age << endl;
        os << "Breed: " << obj.breed << endl;
        os << "Life: " << obj.life << endl;
        os << "Command: " << obj.command << endl;
        return os;
    }
    friend istream& operator >> (istream& is, CatDog& obj) {
        cout << "Input name: ";
        getline(is, obj.name);
        cout << "Input age: ";
        (is >> obj.age).ignore();
        //is.ignore();
        cout << "Input breed: ";
        getline(is, obj.breed);
        cout << "Input life: ";
        (is >> obj.life).ignore();
        cout << "Input command: ";
        (is >> obj.command).ignore();
        //is.ignore();
        return is;
    }
};

class DogCat
{
private:
    string name;
    int age;
    string breed;
    int life;
    int command;
public:
    DogCat() : name("PesoCot"), age(1), breed("mixed"), life(), command(1) {}
    DogCat(string name, int age) : DogCat() 
    {
        this->name = name;
        this->age = age;
    }
    void SetName(string name) { this->name = name; }
    void SetAge(int age) { this->age = age; }
    void SetLife(int life) { this->life = life; }
    void SetBreed(string breed) { this->breed = breed; }
    void SetCommand(int command) { this->command = command; }

    string GetName() const { return name; }
    int GetAge() const { return age; }
    string GetBreed() const { return breed; }
    int GetLife() const { return life; }
    int GetCommand() const { return command; }

    friend ostream& operator << (ostream& os, const DogCat& obj) 
    {
        os << "Name: " << obj.name << endl;
        os << "Age: " << obj.age << endl;
        os << "Breed: " << obj.breed << endl;
        os << "Life: " << obj.life << endl;
        os << "Command: " << obj.command << endl;
        return os;
    }
    friend istream& operator >> (istream& is, DogCat& obj) 
    {
        cout << "Input name: ";
        getline(is, obj.name);
        cout << "Input age: ";
        (is >> obj.age).ignore();
        //is.ignore();
        cout << "Input breed: ";
        getline(is, obj.breed);
        cout << "Input life: ";
        (is >> obj.life).ignore();
        cout << "Input command: ";
        (is >> obj.command).ignore();
        //is.ignore();
        return is;
    }
};

CatDog operator + (const Cat& obj1, const Dog& obj2) {
    CatDog res;
    res.SetName(obj1.GetName() + '-' + obj2.GetName());
    res.SetAge((obj1.GetAge() + obj2.GetAge()) / 2);
    res.SetBreed(obj1.GetBreed() + '-' + obj2.GetBreed());
    res.SetLife(obj1.GetLife());
    res.SetCommand(obj2.GetCommand());
    return res;
}

DogCat operator + (const Dog& obj1, const Cat& obj2) {
    DogCat res;
    res.SetName(obj1.GetName() + '-' + obj2.GetName());
    res.SetAge((obj1.GetAge() + obj2.GetAge()) / 2);
    res.SetBreed(obj1.GetBreed() + '-' + obj2.GetBreed());
    res.SetLife(obj2.GetLife());
    res.SetCommand(obj1.GetCommand());
    return res;
}

int main()
{
    Dog dog;
    Cat cat;

    cin >> cat >> dog;

    CatDog CD = cat + dog;

    cout << cat << endl;
    cout << dog << endl;
    cout << CD << endl;


    // ---------------------------

    cout << "-------Homework---------" << endl;
    DogCat DC = dog + cat;
    cout << DC << endl;
}
