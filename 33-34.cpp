#include <iostream>
#include <stack>
#include <string>


#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;
using namespace std;

/*
Домашнее задание
Тема. Шаблоны классов. Стек

Задание 1. 
Есть строка символов, признаком конца, которой является символ ';'.
В строке могут быть фигурные, круглые, квадратные скобки.
Скобки могут быть открывающими и закрывающими. 
Необходимо проверить корректность расстановки скобок.
При этом необходимо, чтобы выполнились следующие правила:
1) Каждая открывающая скобка должна иметь справа такую же закрывающую. Обратное также должно быть верно. 
2) Открывающие и закрывающие пары скобок разных типов должны быть правильно расположены по отношению друг к другу.

- Пример правильной строки: ({x-y-z}*[x+2y]-(z+4x)); 
- Пример неправильной строки: ([x-y-z}*[x+2y)-{z+4x)];. 

Если все правила соблюдены выведите информационное сообщение о корректности строки, иначе покажите строку до места возникновения первой ошибки.

*/

bool CheckBrackets(char open, char close)
{
	return  (open == '(' && close == ')') ||
			(open == '{' && close == '}') ||
			(open == '[' && close == ']');
			
}

bool CorrectBrackets(const string& example)
{
	stack <char> Brackets;
	for (char temp : example)
	{
		if (temp == '(' || temp == '{' || temp == '[')
			Brackets.push(temp);
		else if (temp == ')' || temp == '}' || temp == ']')
		{
			if (Brackets.empty() || !CheckBrackets(Brackets.top(), temp))
				return false;
			Brackets.pop();
		}
	}
	return Brackets.empty();
}

int main()
{
	string example;
	example = "({x-y-z}*[x+2y]-(z+4x))";
	//cin >> example;
	if (CorrectBrackets)
		cout << "Example is correct!" << endl;
	else 
		cout << "Example is wrong!" << endl;


}