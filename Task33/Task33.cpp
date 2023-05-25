// Задача 4.
// Необходимо отсортировать первые две трети массива в порядке возрастания, 
// если среднее арифметическое всех элементов больше нуля; 
// иначе - лишь первую треть. Остальную часть массива не сортировать, 
// а расположить в обратном порядке.

#include <iostream>
#include <iomanip>

using namespace std;

// Прототипы функций для инициализации массива
void initArray(int ar[], const int size);

// Прототип функций для вывода массива на экран
void showArray(int ar[], const int size);

// Прототипы функций для сортировки выбором
void selectSort1(int ar[], const int size);
void selectSort2(int ar[], const int size);

// Прототипы функций для инициализации массива
void initArray(int ar[], const int size);

// Прототип функций для вывода массива на экран
void showArray(int ar[], const int size);

// Прототипы функций для реверсирования части массива
void revArray1(int ar[], const int size);
void revArray2(int ar[], const int size);

// Прототип функции для поиска среднего арифметического
double averNumArray(int ar[], const int size);

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    const int size = 12;
    int ar[size];

    // Поочередно используем функции: инициализация массива,
    // вывод "исходного" массива на экран, среднее арифметическое
    // (с "вилкой" и ссылками на сортировку и реверс), вывод 
    // "отредактированного" массива на экран
    initArray(ar, size);
    showArray(ar, size);
    cout << endl << endl;
    averNumArray(ar, size);
    showArray(ar, size);
    cout << endl << endl;

    return 0;
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

void selectSort1(int ar[], int size)
{
    int i, j, k;
    int x;
    // Для удобства введем переменную part,
    // равную 2/3 массива
    int part = (size * 2) / 3;

    // i - номер текущего шага
    for (i = 0; i < size; i++)
    {
        k = i;
        x = ar[i];
        // Цикл выбора наименьшего элемента
        for (j = i + 1; j < part; j++)
            if (ar[j] < x)
            {
                k = j;
                x = ar[j];
                // k - индекс наименьшего элемента
            }
        if (k != i)
        {
            ar[k] = ar[i];
            // Меняем местами наименьший с a[i]
            ar[i] = x;
        }
    }

}

void revArray1(int ar[], int size)
{
    // Ограничиваем диапазон перебора: идем от первого элемента
    // последней трети массива до середины последней трети
    // (в нашем случае это 5/6);
    // Для удобства введем переменные point 1-2
    int point1 = (size * 2) / 3;
    int point2 = (size * 5) / 6;
    
    for (int i = point1; i < point2; i++)
    {
        int tmp = ar[i];
        ar[i] = ar[size - (i - point1) - 1];
        ar[size - (i - point1) - 1] = tmp;
    }
}

void selectSort2(int ar[], int size)
{
    int i, j, k;
    int x;
    // Для удобства введем переменную part,
    // равную 2/3 массива
    int part = size / 3;
    // i - номер текущего шага
    for (i = 0; i < size; i++)
    {
        k = i;
        x = ar[i];
        // Цикл выбора наименьшего элемента
        for (j = i + 1; j < part; j++)
            if (ar[j] < x)
            {
                k = j;
                x = ar[j];
                // k - индекс наименьшего элемента
            }
        if (k != i)
        {
            ar[k] = ar[i];
            // Меняем местами наименьший с a[i]
            ar[i] = x;

        }
    }
}

void revArray2(int ar[], int size)
{
    // Ограничиваем диапазон перебора: идем от первого элемента
    // последних двух третей массива до первого элемента последней трети
    // (в нашем случае это 2/3);
    // Для удобства введем переменные point 1-2
    int point1 = size / 3;
    int point2 = (size * 2) / 3;

    for (int i = point1; i < point2; i++)
    {
        int tmp = ar[i];
        ar[i] = ar[size - (i - point1) - 1];
        ar[size - (i - point1) - 1] = tmp;
    }
}

double averNumArray(int ar[], int size)
{
    double sum = 0;
    double averNum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += ar[i];
        averNum = sum / size;

    }
    // Исходя из значения среднего арифметического (больше или меньше нуля),
    // делаем "вилку" для выбора дальнейших сортировки (2/3 или 1/3) 
    // и реверса (1/3 или 2/3). Сделал ссылки на функции selectSort 1-2 и revArray 1-2, 
    // что, наверное не очень правильно (подумаю в спокойном режиме над оптимизацией кода),
    // однако программа работает КОРРЕКТНО.
    cout << "Среднее арифметическое всех элементов массива = " << averNum << ", соответственно ";
    if (averNum > 0)
    {
        cout << "мы сортируем первые 2/3 массива!" << endl;
        selectSort1(ar, size);
        revArray1(ar, size);
        cout << endl;
    }
    else
    {
        cout << "мы сортируем первую 1/3 массива!" << endl;
        selectSort2(ar, size);
        revArray2(ar, size);
        cout << endl;
    }

    return averNum;
}


