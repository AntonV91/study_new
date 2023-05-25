// Задача 5.
// Написать функцию, которая принимает строку — запись натурального числа (до 4000) 
// и возвращает строку, содержащую запись этого числа римскими цифрами.

#include <iostream>
#include <string>

using namespace std;

string intToRoman(string numStr); // прототип функции intToRoman

int main()
{
    setlocale(LC_ALL, "Russian");
    string numStr; // Строка для ввода арабского числа
    string again;
    do
    {
        cout << "Введите число при помощи арабских цифр: ";
        cin >> numStr; // Вводим арабское число
        string romanNumeral = intToRoman(numStr); // Вызываем функцию для преобразования числа в римскую систему счисления
        cout << "Число " << numStr << " в римской системе счисления: " << romanNumeral << endl << endl;
        cout << "Хотите ли вы еще раз перевести арабское число в римское? (Y/N): ";
        cin >> again; // Запрашиваем ответ на повторное выполнение программы
        //system("cls"); // Раскомментируем, если захотим очищать экран после каждой операции
        cout << endl;
    } while (again == "Y" || again == "y");

    system("pause");
    return 0;
}

string intToRoman(string numStr)
{
    // Массивы для римских цифр и их значения
    const int numValues[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    const string romanValues[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    int num = stoi(numStr); // Преобразуем строку в число
    string roman = ""; // Итоговая строка с римским числом

    for (int i = 0; i < sizeof(numValues) / sizeof(numValues[0]); i++)
    {
        while (num >= numValues[i]) // Внутри цикла while проверяется, если num больше или равно 
                                   // текущему значению numValues[i]
        {
            roman += romanValues[i]; // Добавляем римскую цифру в итоговую строку
            num -= numValues[i]; // Вычитаем значение римской цифры из числа
        }
    }
    return roman; // Возвращаем итоговую строку с римским числом
}