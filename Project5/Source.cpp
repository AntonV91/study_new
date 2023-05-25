#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector> 

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	string path = "myFile.txt";
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app); // ����, �����, ��������

	if (!fs.is_open())
	{
		cout << "������ �������� �����!" << endl;
	}
	else
	{
		string txt;
		int choice;
		cout << "���� ������!" << endl << endl;
		cout << "������� 1 ��� ������ ������ � ����" << endl;
		cout << "������� 2 ��� ������ ������ �� �����" << endl;
		cin >> choice;

		if (choice == 1)
		{
			cin >> txt;
			fs << txt << endl;
		}
		if (choice == 2)
		{
			while (fs.eof())
			{
				txt = "";
				fs >> txt;
				getline(fs, txt);
			}
			cout << endl << endl;
		}
		fs.close();
	}

	system("pause");
	return 0;

}



