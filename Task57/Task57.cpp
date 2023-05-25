// Задача 2.
// Дан текстовый файл. Найти длину самой длинной строки.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Прототипы функций
void showAll(ifstream& file); // Для вывода на экран текста из файла
int findMax(const string& line); // Для подсчета символов в самой динной строке с пробелами
int findMaxWS(const string& line); // Для подсчета символов в самой динной строке без пробелов

int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream file("Текст.txt"); // Открываем файл "Текст.txt" для чтения

    if (file.is_open()) // Проверяем, удалось ли открыть файл
    {
        cout << "Содержимое файла: " << endl << endl;
        showAll(file); // Вызываем функцию showAll для чтения из файла в консоль
        file.close(); // Закрываем файл
    }
    else // Если файл не открылся
    {
        cout << "Ошибка: не удается открыть файл!" << endl; // Выводим сообщение об ошибке
    }

    return 0;
}

void showAll(ifstream& file) // Функция для вывода на экран текста из файла
{
    int max = 0; // Переменная для хранения самой длинной строки
    int maxWS = 0; // Переменная для хранения самой длинной строки (без пробелов)
    string line; // Переменная для хранения текущей строки из файла

    while (getline(file, line)) // Читаем строки из файла, пока они не закончатся
    {
        cout << line << endl; // Выводим текущую строку на экран
        int current = findMax(line); // Находим длину текущей строки
        int currentWS = findMaxWS(line); // Находим длину текущей строки (без пробелов)

        if (current > max) // Если текущая длина больше предыдущей максимальной
        {
            max = current; // Обновляем значение максимальной длины
        }
        // То же самое, но без пробелов
        if (currentWS > maxWS)
        {
            maxWS = currentWS;
        }
    }
    cout << "\nДлина самой длинной строки " << max << " символ(ов), или " << maxWS << " символ(ов) без пробелов" << endl;
}

int findMax(const string& line) // Функция для поиска самой длинной строки (с пробелами)
{
    return line.length();
}

int findMaxWS(const string& line) // Функция для поиска самой длинной строки (без пробелов)
{
    int count = 0; // Переменная-счетчик для символов
    for (char c : line)
    {
        if (c != ' ')
        {
            count++; // Если символ не пробел, то считаем его
        }
    }
    return count;
}