#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
������� 1

*�������� ����� ��������� - Worker.
� ������ ���������� ������� ������:
- ���;
- ���������;
- ��� ����������� �� ������;
- ��������.
���������� ��������� (get/set-������) ��� ������� � ��������� ����������-������.
���������� �������-����� ������ ��� ����������� �����-������ ������.
���������� ���������� � ���� � �������� ������ �� �����.
���������� ������������ ��� ��������� ������������� ������� Worker
��������� ������������ ������ � ������� � main().
*/

class Worker
{
	private: 
		string FIO;
		string position;
		size_t entrance;
		size_t salary;
	public:
		Worker()
		{
			FIO = "John Doe";
			position = "NULL";
			entrance = 2023;
			salary = 1000;
		}


		void SetFIO(string newFIO)
		{
			FIO = newFIO;
		}
		void Setposition(string newPosition)
		{
			position = newPosition;
		}
		void Setentrance(size_t newEntrance)
		{
			entrance = newEntrance;
		}
		void Setsalary(size_t newSalary)
		{
			salary = newSalary;
		}
		string GetFIO()
		{
			return FIO;
		}
		string Getposition()
		{
			return position;
		}
		size_t Getentrance()
		{
			return entrance;
		}
		size_t Getsalary()
		{
			return salary;
		}
		void Print()
		{
			cout << "------------------------------------------------------------" << endl;
			cout << "���: " << GetFIO() << endl << "���������: " << Getposition() << endl << "��� ���������������: " << Getentrance() << endl << "��������: " << Getsalary() << endl;
			cout << "------------------------------------------------------------" << endl;
		}
		void Input()
		{
			string temp;
			size_t temp2;
			cout << "������� ���: " << endl;
			getline(cin, temp);
			SetFIO(temp);
			cout << "������� ���������: " << endl;
			getline(cin, temp);
			Setposition(temp);
			cout << "������� ��� ���������������: " << endl;
			cin >> temp2;
			Setentrance(temp2);
			cout << "������� ��������: " << endl;
			cin >> temp2;
			Setsalary(temp2);
			cin.ignore();
		}
		void SafeToFile(string FileName)
		{
			ofstream file; 
			file.open(FileName); 
			if (file.is_open() == true)
				{	
					file << GetFIO() << endl; 
					file << Getposition() << endl;    
					file << Getentrance() << endl;    
					file << Getsalary() << endl;    
				}
			else 
			{
				cout << "������: ���� ��� ������ �� ������!" << endl;
			}
		}
		void LoadFromFile(string FileName)
		{
			ifstream file(FileName); 
			if (file.is_open()) 
			{ 
				string temp;
				size_t temp2;
				getline(file, temp); 
				SetFIO(temp); 
				getline(file, temp); 
				Setposition(temp);
				file >> temp2;
				Setentrance(temp2);
				file >> temp2;
				Setsalary(temp2);
			}
			else
			{ 
				cout << "������: ���� �� ������!" << endl;
			}
		}
		void SafetoFile(string FileName)
		{
			ofstream file;
			file.open(FileName);
			if (file.is_open() == true)
			{ 	file << GetFIO() << endl; 
				file << Getposition() << endl;    
				file << Getentrance() << endl; 
				file << Getsalary() << endl; 
			}
			else {
				cout << "������: ���� ��� ������ �� ������!" << endl;
			}

		}
};
string CorrectFileName(string FileName)
{
	int dot_index = -1;
	for (int i = FileName.size() - 1; i >= 0; i--)
	{
		if (FileName[i] == '.') {
			dot_index = i; 
			break;
		}
	}
	string Result; 
	if (dot_index == -1) 
	{ 
		Result = FileName + ".txt"; 
	}
	else {
		string ext = FileName.substr(dot_index);
		if (ext == ".txt") {
			Result = FileName; 
		}
		else {
			Result = FileName.substr(0, dot_index);
			Result += ".txt";
		}
	} 
	return Result; 
}



using namespace std;


int main()
{
	system("chcp 1251 > null");
	Worker A;
	A.Input();
	A.Print();
	string file_name;
	cout << "������� ��� �����, ���� �������� ������: ";
	getline(cin, file_name);
	file_name = CorrectFileName(file_name);
	cout << "������ ������� �������� � ����: " << file_name << endl;
	A.SafeToFile(file_name);
	Worker B;
	B.LoadFromFile(file_name);
	B.Print();
}
