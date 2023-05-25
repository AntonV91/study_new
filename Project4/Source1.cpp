
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

	//string path = "myFile.txt";
	string path("D:\\Учёба IT\\ДЗ\\TSMGO.txt");
	string path1("D:\\Учёба IT\\ДЗ\\BR.txt");

	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!" << endl << endl;
	}
	else
	{
		cout << "Файл открыт!\n\n";

		// Вывод текста из файла в консоль ПОСИМВОЛЬНО
		/*char ch;
		while (fin.get(ch))
		{
			cout << ch;
		}
		cout << endl << endl;*/

		string str;
		while (!fin.eof())
		{
			//str = "";
			getline(fin, str);
			cout << str << endl;
		}
		cout << endl << endl;
	}
	fin.close();

	//D:\Учёба IT\myFile.txt
	/*cin >> path;*/

	system("pause");
	return 0;
}
