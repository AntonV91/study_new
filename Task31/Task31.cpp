//Задача 1,3 (первая + шаблоны).
// Написать перегруженные функции (int, double, char) 
// для выполнения следующих задач :
// - Инициализация квадратной матрицы;
// - Вывод матрицы на экран;
// - Определение максимального и минимального элемента на главной диагонали матрицы.
// + Переделать при помощи шаблонов

#include <iostream>
#include <iomanip>
// Подключаем библиотеку iomanip, чтобы воспользоваться
// функцией setw (используем для задания ширины поля 
// отображения для следующего элемента в потоке)

using namespace std;

template <typename T> void showArray(T ar[][4], const int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(4) << ar[i][j] << " \t ";
		}
		cout << endl;
	}
}
// Создаем шаблон функции для вывода массивов на экран;

template <typename T> T MinNumMainArray(T ar[][4], const int row, int col)
{
	T min = ar[0][0];
	for (int i = 0; i < row; i++)
		if (min > ar[i][i]) min = ar[i][i];
	cout << "Минимальный элемент на главной диагонали матрицы = " << min << endl;
	return min;
}
// Создаем шаблон функции для поиска и вывода на экран 
// минимального элемента на главной диагонали каждого массива

template <typename T> T MaxNumMainArray(T ar[][4], const int row, int col)
{
	T max = ar[0][0];
	for (int i = 0; i < row; i++)
		if (max < ar[i][i]) max = ar[i][i];
	cout << "Максимальный элемент на главной диагонали матрицы = " << max << endl;
	return max;
}
// Создаем шаблон функции для поиска и вывода на экран 
// максимального элемента на главной диагонали каждого массива

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	const int row = 4, col = 4;
	int arInt[row][col];
	double arDoub[row][col];
	char arChar[row][col];
	// Прописываем типы переменных в массивах и задаем их размерность
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arInt[i][j] = rand() % 50 + (-25);
			arDoub[i][j] = (rand() % 100 + (-50) / 3.01);
			arChar[i][j] = (char)rand() % 255;
		}
	}
	// Инициализируем массивы, задаем заполнение случайными числами
	// (символами) в заданных диапазонах

	cout << "Массив элементов int: " << endl << endl;
	showArray(arInt, row, col);
	cout << endl;
	MinNumMainArray(arInt, row, col);
	MaxNumMainArray(arInt, row, col);
	cout << endl;
	// Последовательно выводим на экран массив int, 
	// а также max и min элементы на главной диагонали
	cout << "Массив элементов double: " << endl << endl;
	showArray(arDoub, row, col);
	cout << endl;
	MinNumMainArray(arDoub, row, col);
	MaxNumMainArray(arDoub, row, col);
	cout << endl;
	cout << "Массив элементов char: " << endl << endl;
	showArray(arChar, row, col);
	cout << endl;
	MinNumMainArray(arChar, row, col);
	MaxNumMainArray(arChar, row, col);
	cout << endl;
	// Повторяем действия для массивов double и char
	
	system("pause");
	return 0;
}