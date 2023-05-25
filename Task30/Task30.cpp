//Задача 1.
// Написать перегруженные функции (int, double, char) 
// для выполнения следующих задач :
// - Инициализация квадратной матрицы;
// - вывод матрицы на экран;
// - определение максимального и минимального элемента на главной диагонали матрицы.

#include <iostream>
#include <iomanip>
// Подключаем библиотеку iomanip, чтобы воспользоваться
// функцией setw (используем для задания ширины поля 
// отображения для следующего элемента в потоке)

using namespace std;

void showArray(int ar[][4], const int row, int col)
{
	cout << "Массив элементов типа int: " << endl << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(2) << ar[i][j] << " \t ";
		}
		cout << endl;
	}
}
// Задаем невозвращаемую функцию, выводящую массив на экран;
// используем функцию setw (ориентируемся на минимальное 
// значение, в нашем случае красиво выводит при min = 2)

void initArray(int ar[][4], const int row, const int col)
{
	srand(time(NULL));
	// Задаем заполнение случайными числами (каждый запуск программы - разными)
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			ar[i][j] = rand() % 50 + (-25);
			// Задаем заполнение массива случайными числами от -25 до 25
		}
	}
}

void showArray(double ar[][4], const int row, int col)
{
	cout << "Массив элементов типа double: " << endl << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(2) << ar[i][j] << " \t ";
		}
		cout << endl;
	}
}
// Задаем невозвращаемую функцию, выводящую массив на экран;
// используем функцию setw (ориентируемся на минимальное 
// значение, в нашем случае красиво выводит при min = 2)

void initArray(double ar[][4], const int row, int col)
{
	srand(time(NULL));
	// Задаем заполнение случайными числами (каждый запуск программы - разными)
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			ar[i][j] = rand() % 100 / 3.05;

			// Задаем заполнение массива случайными числами типа double
		}
	}
}

void showArray(char ar[][4], const int row, int col)
{
	cout << "Массив элементов типа char: " << endl << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(4) << ar[i][j] << " \t ";
		}
		cout << endl;
	}
}
// Задаем невозвращаемую функцию, выводящую массив на экран;
// используем функцию setw (ориентируемся на минимальное 
// значение, в нашем случае красиво выводит при min = 4)

void initArray(char ar[][4], int row, int col)
{
	srand(time(NULL));
	// Задаем заполнение случайными числами (каждый запуск программы - разными)
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			ar[i][j] = rand() % 255;
			// Задаем заполнение массива случайными символами ASCII от 0 до 255
		}
	}
}

int MinNumMainArray(int ar[][4], int row, int col) 
{
	int min = ar[0][0];
	for (int i = 0; i < row; i++)
		if (min > ar[i][i]) min = ar[i][i];
	cout << "Минимальный элемент на главной диагонали матрицы = " << min << endl;
	return min;
}
// Задаем функцию для определения минимального элемента 
// на главной диагонали в массиве int

int MaxNumMainArray(int ar[][4], int row, int col)
{
	int max = ar[0][0];
	for (int i = 0; i < row; i++)
		if (max < ar[i][i]) max = ar[i][i];
	cout << "Максимальный элемент на главной диагонали матрицы = " << max << endl;
	return max;
}
// Для максимального на главной диагонали в массиве int

double MinNumMainArray(double ar[][4], int row, int col) 
{
	double min = ar[0][0];
	for (int i = 0; i < row; i++)
		if (min > ar[i][i]) min = ar[i][i];
	cout << "\nМинимальный элемент на главной диагонали матрицы = " << min << endl;
	return min;
}
// Для минимального на главной диагонали в массиве double

double MaxNumMainArray(double ar[][4], int row, int col) 
{
	double max = ar[0][0];
	for (int i = 0; i < row; i++)
		if (max < ar[i][i]) max = ar[i][i];
	cout << "Максимальный элемент на главной диагонали матрицы = " << max << endl;
	return max;
}
// Для максимального на главной диагонали в массиве double

char MinNumMainArray(char ar[][4], int row, int col) 
{
	char min = ar[0][0];
	for (int i = 0; i < row; i++)
		if (min > ar[i][i]) min = ar[i][i];
	cout << "\nМинимальный элемент на главной диагонали матрицы = " << min << endl;
	return min;
}
// Для минимального на главной диагонали в массиве char

char MaxNumMainArray(char ar[][4], int row, int col) 
{
	char max = ar[0][0];
	for (int i = 0; i < row; i++)
		if (max < ar[i][i]) max = ar[i][i];
	cout << "Максимальный элемент на главной диагонали матрицы = " << max << endl;
	return max;
}
// Для максимального на главной диагонали в массиве char

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Добро пожаловать в нашу программу!\n";
	cout << "Давайте найдем минимальный и максимальный элементы на главной диагонали каждого массива!\n\n";
	const int row = 4, col = 4;
	int arInt[row][col];
	double arDoub[row][col];
	char arChar[row][col];
	// Задаем размерность массивов по строкам и столбцам
	initArray(arInt, row, col);
	// Вызываем функцию инициализации массива int
	showArray(arInt, row, col);
	// Вызываем функцию вывода массива на экран int
	cout << endl;
	MinNumMainArray(arInt, row, col);
	// Вызываем функцию поиска и вывода на экран 
	// минимального элемента на главной диагонали
	MaxNumMainArray(arInt, row, col);
	// Вызываем функцию поиска и вывода на экран 
	// максимального элемента на главной диагонали
	cout << endl;
	initArray(arDoub, row, col);
	showArray(arDoub, row, col);
	MinNumMainArray(arDoub, row, col);
	MaxNumMainArray(arDoub, row, col);
	cout << endl;
	initArray(arChar, row, col);
	showArray(arChar, row, col);
	MinNumMainArray(arChar, row, col);
	MaxNumMainArray(arChar, row, col);
	cout << endl;
	// Повторяем те же действия для массивов double и char

	system("pause");
	return 0;
}