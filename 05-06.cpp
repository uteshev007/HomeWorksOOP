#include <iostream>
#include <string>

using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); }}_;


/*
������� 1

�������� �������, ��� ���������� � ������������ ����������.
�������� ������� ������������, ����� �� ������������� ��������
��������� ������������� ��������� (��������, k ��������� ��������
� ��������� �� 0 �� 100).
� �������� ������� ������ �������� ����� �������� �������� ����,
������� �����������. ������� ����� ������ ��������.
���������� ����������� ������������ ������������� � ������������
��������, ���������� �������� �� 1, ����������� �������� ��������.
*/


class Counter
{
private:
	int temp;
	int hour;
	int MAX = 12;
	int MIN = 1;
	int k;
public:
	Counter();
	int Increment()
	{
		hour = 0;
		for (int  i = 0; i < k; i++)
		{
			hour++;
			if (k > MAX)
			{
				hour++;
				hour = temp % MAX;
			}

		}
		return hour;
	}
	
	void Input()
	{
		cout << "������� ��������: ";
		cin >> temp;
		setHour(temp);
	}
	void Print()
	{
		cout << "������� ��: " << "12" << endl;
		cout << "������� �����: " << Increment() << endl;
	}

	int InputHour()
	{
		return hour;
	}
	
	void setHour(int newhour)
	{
		k = newhour;
		Increment();
	}
	void ChangeMAX(int newMAX)
	{
		MAX = newMAX;
	}
	void ChangeMIN(int newMIN)
	{
		MIN = newMIN;
	}
};
int main()

{
	Counter A;
	A.Input();
	A.Print();

}

Counter::Counter()
{
}
