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
	fs.open(path, fstream::in | fstream::out | fstream::app); // ввод, вывод, дозапись

	if (!fs.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		string txt;
		int choice;
		cout << "Файл открыт!" << endl << endl;
		cout << "Нажмите 1 для записи текста в файл" << endl;
		cout << "Нажмите 2 для чтения текста из файла" << endl;
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



