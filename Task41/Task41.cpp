// Задача 9.
// Подсчитать количество слов во введенном предложении

#include <iostream>
#include <string> // Подключаем библиотеку для использования getline
#include <windows.h> // Подключаем библиотеку для использования SetConsole

using namespace std;

int countWords(string& str); // Прототип функции для подсчета слов в предложении

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str;
    cout << "Введите предложение: " << endl << endl;
    getline(cin, str); // Используем функцию getline для получения входной строки от пользователя
    cout << endl;
    countWords(str); // Подсчитываем количество слов в предложении
    cout << endl << endl;
    system("pause");
    return 0;
}

int countWords(string& str)
{
    int count = 0;
    for (int i = 1; i < str.length(); i++)
    {
        // Установим ограничения для корректного распознавания слов ('\0' - конец строки)
        if (str[i - 1] != ' ' && (str[i] == ' ' || str[i + 1] == '\0'))
            count++;
    }
    cout << "Количество слов в предложении: " << count << endl;
    return count;
}
