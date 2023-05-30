#include <iostream>
#include <string>

using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))


/*
Тема: статические члены класса
Задание
Реализуйте класс "Член Семьи".
В классе заведите переменные: "Название члена семьи", "Текущий расход", "Суммарный расход" и пр.
Реализуйте конструкторы, деструкторы, методы класса для доступа к переменным класса.
В классе описать статическую переменную - "Бюджет семьи".
Реализуйте статическую функцию установки исходного значения бюджета.
Реализуйте метод класса - "расход из бюджета". Расход можно представить, как уменьшение бюджета на случайную ограниченную величину.

В программе объявить членов семьи, например: Мама, Папа, Дочь, Сын.
Задать исходное значение бюджета.
Каждый член такой семьи будет случайным образом расходовать бюджет до его обнуления.
В итоге вывести общий расход каждого члена семьи.
*/

/*
class Family {
    budg; -"Бюджет семьи"
        static int getBuget() { return budg; }
};

int main() {
    cout << Family::getBuget() << endl;
    Family mama, papa, son, doth;
    Family fma[4] = { "mama", "papa", };

    for (int i = 0; i < 7; i++) {
        mama.shoping(10'000, 20'000);
        papa.spen(3000, 5000);
        son.spen(1000, 3000);
        doth.spen(1000, 3000);
        cout << Family::getBuget() << endl;
        if (Family::getBuget() == 0) {
            break;
        }
    }
    mama.Show();
    papa.Show();
    son.Show();
}
*/


class Family
{
private:
    string Name;
    int CurSpend;
    int SumSpend;
    static int Budg;

public:

    static int GetBudg() { return Budg; }
    static void SetBudg(int number) { Budg = number; }

    Family() {};
    Family(string Name) { this->Name = Name; this->CurSpend = 0; this->SumSpend = 0; Budg; }
    Family(string Name, int CurSpend) : Family(Name) { this->CurSpend = CurSpend; }
    Family(string Name, int CurSpend, int SumSpend) : Family(Name, CurSpend) { this->SumSpend = SumSpend; }
    ~Family(){}

    void SetName(string Name) { this->Name = Name; }
    int SetCurSpend() 
    {
        cout << "Enter summ of spend: ";
        cin >> CurSpend;
        return CurSpend;
    }
    void SetSumSpend(int summ) { this->SumSpend = summ; }

    string GetName() { return Name; }
    int GetCurSpend() { return CurSpend; }
    int GetSumSpend() 
    { 
        SumSpend += CurSpend;
        return SumSpend; 
    }



    void RandSpend() 
    {
        if (Budg != 0)
        {
            int temp = RAND(100, 500);
            CurSpend = Budg - temp;
        }
        else
            cout << "Error! Budget is emty!" << endl;
    }
    void Spend(int number)
    {
        SumSpend += number;
    }
    void Print()
    {
        cout << "Name: " << GetName() << endl;
        cout << "Total Spend: " << SumSpend << endl;
        cout << "Budget: " << (Budg -= SumSpend) << endl;
    }


};
    int Family::Budg;


int main()
{
    Family::SetBudg(5000);
    cout << Family::GetBudg() << endl;
    Family Mama{ "Mom" }, Papa{ "Dad" }, Son{"Son"};
    Mama.Spend(500);
    Papa.Spend(400);
    Mama.Print();
    Papa.Print();
    cout << Family::GetBudg() << endl;


}