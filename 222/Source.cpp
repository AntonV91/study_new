#include <Windows.h>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

int main() 
{
    // Установка цвета текста
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = 7; // Белый цвет на черном фоне
    SetConsoleTextAttribute(hConsole, color);

    // Вывод текста на консоль с мерцанием
    string text = "Hello, world!";
    while (true) 
    {
        for (int i = 0; i < text.size(); i++) 
        {
            if (i % 2 == 0) {
                SetConsoleTextAttribute(hConsole, 10); // Зеленый цвет на черном фоне
            }
            else 
            {
                SetConsoleTextAttribute(hConsole, 7); // Белый цвет на черном фоне
            }
            cout << text[i];
            this_thread::sleep_for(std::chrono::milliseconds(100)); // Задержка в 100 миллисекунд
        }
        cout << "\r"; // Перенос курсора в начало строки
    }
    return 0;
}