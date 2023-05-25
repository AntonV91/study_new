// Задача 4.
// Шифр Цезаря — один из древнейших шифров. При шифровании каждый символ заменяется другим, 
// отстоящим от него в алфавите на фиксированное число позиций.
// Дан текстовый файл. Зашифровать его, используя шифр Цезаря. Результат записать в другой файл.

#include <iostream>
#include <fstream> // Для работы с файлами
#include <Windows.h> // Для работы с кириллицей
#include <string> // Для работы с getline

using namespace std;

void title(); // Прототип функции для вывода заголовка
bool openInputFile(ifstream& input, const string& filename); // Для проверки на открытие файла
int enterKey(); // Для ввода "ключа" (размера смещения)
string encryptText(string inputText, int key); // Для шифрования исходного текста
bool writeToFile(const string& text, const string& filename); // Для проверки на запись в файл

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    title();
    ifstream input; //Создание объекта входного потока для чтения из файла
    if (!openInputFile(input, "Базовый.txt")) // Проверяем открылся ли файл с исходным текстом
    {
        return 1; // Если вернет false, то программа завершается с кодом 1
    }

    string line;
    while (getline(input, line)) // Чтение строк из файла с помощью getline
    {
        cout << "\nИсходный текст: " << line << endl;

        //Для каждой строки вызываются enterKey() и encryptText()
        int key = enterKey(); // Получаем размер смещения

        string encrypted = encryptText(line, key); // Получаем зашифрованный текст

        cout << "\nЗашифрованный текст: ";
        cout << encrypted << endl; // Выводим на экран для наглядности

        //Зашифрованный текст сохраняется в файл (проверяем на "успешную запись")
        if (!writeToFile(encrypted, "Зашифрованный.txt"))
        {
            return 1; // Если вернет false, то программа завершается с кодом 1
        }
    }
    input.close();
    cout << endl;
    system("pause");
    return 0;
}

void title() // Функция-заголовок
{
    cout << "Добро пожаловать в программу для шифрования текста!" << endl;
    cout << "Давайте зашифруем текст при помощи шрифта Цезаря..." << endl;
}

string encryptText(string inputText, int key) // Функция для шифрования текста 
{
    string encrypted = "";

    for (char symbol : inputText) // Бежим по исходному тексту
    {
        // Шифрование символов в нижнем регистре латиницы
        if (symbol >= 'a' && symbol <= 'z')
        {
            // Смещение символа на "ключ" с помощью модуля (по кол-ву символов)
            symbol = 'a' + (symbol - 'a' + key) % 26;
        }
        // Шифрование символов в верхнем регистре латиницы
        else if (symbol >= 'A' && symbol <= 'Z')
        {
            symbol = 'A' + (symbol - 'A' + key) % 26;
        }
        // Шифрование символов в нижнем регистре кириллицы 
        // (проблему с ё/Ё пока не решил, планирую выдумать рабочий способ в будущем)
        else if (symbol >= 'а' && symbol <= 'я')
        {
            symbol = 'а' + (symbol - 'а' + key) % 32;
        }
        // Шифрование символов в верхнем регистре кириллицы
        else if (symbol >= 'А' && symbol <= 'Я')
        {
            symbol = 'А' + (symbol - 'А' + key) % 32;
        }

        encrypted += symbol; // Добавляем зашифрованный символ в строку encrypted
    }
    return encrypted;
}

bool openInputFile(ifstream& input, const string& filename) // Функция для проверки на открытие файла
{
    input.open(filename);
    if (!input.is_open())
    {
        cout << "Ошибка: не удается открыть файл " << filename << " для чтения!" << endl;
        return false;
    }
    return true;
}

int enterKey() // Функция для ввода ключа (размера смещения)
{
    int key;
    cout << "\nВведите размер смещения: ";
    cin >> key;
    return key;
}

bool writeToFile(const string& text, const string& filename) // Функция для проверки на запись в файл
{
    ofstream output(filename);
    if (output.is_open())
    {
        output << text << endl;
        cout << "\nУспешно сохранено в файл " << filename << "!" << endl;
        output.close();
        return true;
    }
    else
    {
        cout << "Ошибка: не удается открыть файл " << filename << " для записи!" << endl;
        return false;
    }
}