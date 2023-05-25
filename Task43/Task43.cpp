// Задача 4.
// Транспонирование матрицы – это операция, после которой столбцы прежней матрицы 
// становятся строками, а строки — столбцами. Напишите функцию транспонирования матрицы.

#include <iostream>
#include <iomanip>

using namespace std;

void title();
void initArray(int** ar, int rows, int cols);
void showArray(int** ar, int rows, int cols);
int** newArray(int rows, int cols);
int** transpArray(int** matrix, int rows, int cols);
void deleteArray(int** ar, int rows);

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    title();
    cout << endl;
    // Просим пользователя ввести количество строк и столбцов в матрице
    cout << "Введите количество строк матрицы: ";
    int rows;
    cin >> rows;
    cout << "Введите количество столбцов матрицы: ";
    int cols;
    cin >> cols;
    cout << endl;

    // Cоздаём массив, с которым будем работать
    int** ar = newArray(rows, cols);

    cout << "Исходный двумерный массив (матрица): ";
    cout << endl;
    initArray(ar, rows, cols);
    showArray(ar, rows, cols);
    cout << endl;
    // Транспонируем матрицу и выводим её на экран
    int** tAr = transpArray(ar, rows, cols);
    cout << "Транспонированный массив (матрица): ";
    cout << endl;
    showArray(tAr, cols, rows);
    cout << endl;

    // Освобождаем выделенную память
    deleteArray(ar, rows);
    deleteArray(tAr, cols);

    system("pause");
    return 0;
}

void title()
{
    cout << "Транспонирование матрицы – это операция," << endl;
    cout << "после которой столбцы прежней матрицы становятся строками, а строки — столбцами." << endl;
    cout << "Напишем функцию транспонирования матрицы." << endl;
}

void initArray(int** ar, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ar[i][j] = rand() % 20 + (-10);
        }
    }
}

void showArray(int** ar, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << ar[i][j] << " | ";
        }
        cout << endl;
    }
}

// Создаем функцию для массива, с которым будем работать
int** newArray(int rows, int cols)
{
    int** ar = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        ar[i] = new int[cols];
    }
    return ar;
}

// Транспонируем матрицу (путём замены строк и столбцов)
int** transpArray(int** tAr, int rows, int cols)
{
    int** fin = newArray(cols, rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fin[j][i] = tAr[i][j];
        }
    }
    return fin;
}

// Освобождаем память после проведенных манипуляций с массивами
void deleteArray(int** ar, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] ar[i];
    }
    delete[] ar;
}