// Задание 8.
// Используя указатель на массив целых чисел, посчитать сумму элементов массива.
// Использовать в программе арифметику указателей для продвижения по массиву, 
// а также оператор разыменования.

#include <iostream>

using namespace std;

// Прототип функции для инициализации массива
void initArray(int* ptr, const int size);
// Прототип функции для вывода массива на экран
void showArray(int* ptr, const int size);
// Прототип функции для суммирования элементов массива
int getSum(int* ptr, const int size);

int main()
{
    setlocale(LC_ALL, "Russian");
    const int size = 15;
    int ar[size];
    int* ptr = &ar[0]; // Записываем адрес нулевого элемента массива в указатель

    initArray(ar, size);
    cout << "Вот и он - наш массив из " << size << " элементов!" << endl << endl;
    showArray(ar, size);
    cout << endl << endl;
    cout << "Сумма элементов массива = " << getSum(ar, size) << endl << endl;
    cout << endl;

    system("pause");
    return 0;
}

void initArray(int* ptr, int size) // Инициализируем массив
{
    srand(time(NULL));
    for (int i = 0; i < size; i++, ptr++)
    {
        *ptr = rand() % 100 + (-50);
    }
}

void showArray(int* ptr, int size) // Показывеам массив на экране
{
    for (int i = 0; i < size; i++, ptr++)
    {
        cout << *ptr << " | ";
    }
}

int getSum(int* ptr, int size) // Считаем сумму элементов в массиве
{
    int sum = 0;
    for (int i = 0; i < size; i++, ptr++)
    {
        sum += *ptr;
    }
    return sum;
}
