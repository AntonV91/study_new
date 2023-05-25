// Задание 7:
// Напишите рекурсивную функцию, которая принимает одномерный массив из 100 целых чисел, 
// заполненных случайным образом, и находит позицию, с которой начинается последовательность 
// из 10 чисел, сумма которых минимальна.

#include <iostream>
#include <iomanip>

using namespace std;

// Прототип функции для инициализации массива
void initArray(int ar[], const int size);
// Прототип функции для вывода массива на экран
void showArray(int ar[], const int size);
// Прототип функции для поиска минимальной суммы
int findMin(int ar[], const int size, int num, int& min);

int main()
{
    setlocale(LC_ALL, "Russian");
    const int size = 100;
    int ar[size];
    int min;
    int num = 0;

    initArray(ar, size);
    showArray(ar, size);
    cout << endl << endl;
    findMin(ar, size, num, min);
    cout << endl;
    cout << "Минимальная сумма элементов находится в диапазоне с " << min << "ой по " << min + 9 << "ую позицию" << endl << endl;
    cout << endl;

    system("pause");
    return 0;
}

// Функция для вычисления суммы для каждой последовательности из 10 элементов,
// и поиска минимальной суммы
int findMin(int ar[], int size, int num, int& min) // Не успевал грамотно оформить инициализацию
// локальной переменной min (не передавалось в main), подсмотрел на форумах с указателем
{
    int sum = 0;
    for (int i = num; i < num + 10; i++) // Ищем сумму в диапазоне 10 элементов
    {
        sum += ar[i];
    }
    cout << "Сумма элементов с " << num << "го" << " по " << num + 9 << "й" << " = " << sum << endl;

    // Ограничиваем суммирование 90м элементом, т.к., 
    // начиная с 91го, сумма будет считаться не более, чем для девяти
    if (num >= 90)
        /*if (num >= size - 10)*/
    {
        min = num;
        return sum;
    }
    if (num < 90)
        /*if (num < size - 10)*/
    {
        int sumNext = findMin(ar, size, num + 1, min); // Вводим переменную и рекурсивно перебираем массив
        if (sum <= sumNext)
        {
            min = num;
            return sum;
        }
        else
            return sumNext;
    }
}

void showArray(int ar[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(2) << ar[i] << " | ";
    }
}

void initArray(int ar[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        ar[i] = rand() % 100 + (-50);
    }
}
