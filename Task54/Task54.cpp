// Задача 3.
// Написать функцию, принимающую в качестве параметров две строки и возвращающую 
// копию первого параметра, все вхождения второго параметра в которой взяты в «()».
// Например, если параметрами были строки "abaracadabra" и "ab", 
// то вернуть надо "(ab)aracad(ab)ra"

#include <iostream> 
#include <string>
#include <windows.h>

using namespace std;

// Прототип функции для вставки скобок в строку
string insertParentheses(const string& str, const string& pattern);
// Прототип функции для подсчета количества вхождений подстроки в строку
int countPatterns(const string& str, const string& pattern);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str1, str2;
    cout << "Введите строку: ";
    getline(cin, str1); // Ввод строки
    cout << "Введите искомую подстроку: ";
    getline(cin, str2); // Ввод искомой подстроки 

    // Вызов функции insertParentheses и сохранение результата в переменной result
    string result = insertParentheses(str1, str2);
    cout << "Возвращаемая строка: " << result << endl << endl;

    // Вызов функции countOccurrences и сохранение результата в переменной count
    int count = countPatterns(str1, str2);
    cout << "Найдено " << count << " вхождений(-ия) подстроки " << "'" << str2 << "' " << "в исходную строку" << endl << endl;

    system("pause");
    return 0;
}

// Функция для вставки круглых скобок
string insertParentheses(const string& str, const string& pattern)
{
    string result = str; // Создание копии исходной строки
    size_t pos = 0; // Инициализация переменной pos для хранения позиции в строке

    // Цикл для поиска паттерна (подстроки) в строке
    while ((pos = result.find(pattern, pos)) != string::npos)
    {
        result.insert(pos, "("); // Вставка открывающей скобки перед паттерном
        result.insert(pos + pattern.length() + 1, ")"); // ...и закрывающей после паттерна
        pos += 2; // Переход на следующую позицию после вставленных скобок
    }
    return result;
}

// Функция для подсчета количества вхождений подстроки в строку
int countPatterns(const string& str, const string& pattern)
{
    int count = 0;
    size_t pos = 0; // Инициализация переменной pos для хранения позиции в строке

    // Цикл для поиска паттерна (подстроки) в строке
    while ((pos = str.find(pattern, pos)) != string::npos)
    {
        count++; // Увеличение счетчика
        pos += pattern.length(); // Переход на следующую позицию после найденного вхождения
    }
    return count;
}