// Задание 4.
// Даны два массива: А[M] и B[N](M и N вводятся с клавиатуры).
// Необходимо создать третий массив минимально возможного размера, 
// в котором нужно собрать общие элементы двух массивов без повторений

#include <iostream>
#include <windows.h>

using namespace std;

void title();
void memAlloc(int* ar1, int* ar2, int* ar3, int size1, int size2, int size3);
void initArray(int* ar, int size);
void showArray(int* ar, int size);
int  gener3rd(int* ar1, int* ar2, int* ar3, int size1, int size2, int tempSize, int& size3);  //переименуй
void deleteArrays(int* ar1, int* ar2, int* ar3);
void joinArray(int* ar1, int* ar2, int* ar3, int size1, int size2);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	title();
	cout << endl;

	int size1, size2, size3 = 0;

	int* ar1 = nullptr;
	int* ar2 = nullptr;
	int* ar3 = nullptr;

	cout << "Введите размер первого массива: ";
	cin >> size1;
	cout << "Введите размер второго массива: ";
	cin >> size2;

	ar1 = new int[size1];
	ar2 = new int[size2];
	ar3 = new int[size1 + size2];
	cout << endl;

	memAlloc(ar1, ar2, ar3, size1, size2, size3);

	initArray(ar1, size1);
	initArray(ar2, size2);
	cout << "Размер первого массива = " << size1 << endl;
	cout << "Первый массив: ";
	showArray(ar1, size1);
	cout << endl;
	cout << "Размер второго массива = " << size2 << endl;
	cout << "Второй массив: ";
	showArray(ar2, size2);
	cout << endl;

	// Оставил функцию для соединения двух массивов в третий как в 3ей задаче
	// (для наглядности, и чтобы хоть какая-то задача полностью работала :-)
	joinArray(ar1, ar2, ar3, size1, size2);
	cout << "Размер обединенного массива = " << size1 + size2 << endl;
	cout << "Объединенный массив: ";
	showArray(ar3, size1 + size2);
	cout << endl;

	int tempSize = (size1 > size2) ? size1 : size2;
	gener3rd(ar1, ar2, ar3, size1, size2, tempSize, size3);
	showArray(ar3, size3);

	deleteArrays(ar1, ar2, ar3);

	system("pause");
	return 0;
}

void showArray(int* ar, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << " | ";
	}
	cout << endl;
}

void initArray(int* ar, int size)
{
	for (int i = 0; i < size; i++)
	{
		ar[i] = rand() % 10 + (-5);
	}
}

void deleteArrays(int* ar1, int* ar2, int* ar3)
{
	if (ar1)
	{
		delete[] ar1;
		ar1 = nullptr;
	}
	if (ar2)
	{
		delete[] ar2;
		ar2 = nullptr;
	}
	if (ar3)
	{
		delete[] ar3;
		ar3 = nullptr;
	}
}

void memAlloc(int* ar1, int* ar2, int* ar3, int size1, int size2, int size3)
{
	if (!ar1 || !ar2 || !ar3)
	{
		cout << "ERROR: Ошибка выделения памяти!" << endl;
		exit(0);
	}
}

void title()
{
	cout << "Даны два массива: ar1[size1] и ar2[size2] (size1 и size2 вводятся с клавиатуры)." << endl;
	cout << "Необходимо создать третий массив минимально возможного размера," << endl;
	cout << "в котором нужно собрать общие элементы двух массивов без повторений." << endl;
}

// Объединение двух массивов в третий (простое, без "вычищений", для наглядности)
void joinArray(int* ar1, int* ar2, int* ar3, int size1, int size2)
{
	for (int i = 0; i < size1; i++)
		ar3[i] = ar1[i];

	for (int i = size1, j = 0; j < size2; i++, j++)
		ar3[i] = ar2[j];
}

// Формула работает не во всех случаях, к сожалению (прописана не очень хорошо)
// Обязательно еще поработаю над задачей (в праздники не получилось), постараюсь прийти к приличному коду
// Очень прошу на след. неделе разобрать на паре эти задачи, в знании о динам. массивах у меня пробелы :-)
int gener3rd(int* ar1, int* ar2, int* ar3, int size1, int size2, int tempSize, int& size3)
{
	int temp;   // Переменнная temp, значение за пределами диапазона
	for (int i = 0; i < tempSize; i++)
	{
		for (int j = 0; j < tempSize; j++)
		{
			if ((ar1[j] == ar2[i]) && (ar1[j] != ar3[size3]))  // Проверка на уникальность и совпадение
			{
				temp = ar1[j];
				ar3[size3] = temp; // Записываем элементы после сравнения в 3й массив
				size3++;
			}
		}
	}
	cout << "Размер третьего массива = " << size3 << endl;

	return ar3[size3];
}

