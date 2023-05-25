#include <Windows.h>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

int main() 
{
    // ��������� ����� ������
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = 7; // ����� ���� �� ������ ����
    SetConsoleTextAttribute(hConsole, color);

    // ����� ������ �� ������� � ���������
    string text = "Hello, world!";
    while (true) 
    {
        for (int i = 0; i < text.size(); i++) 
        {
            if (i % 2 == 0) {
                SetConsoleTextAttribute(hConsole, 10); // ������� ���� �� ������ ����
            }
            else 
            {
                SetConsoleTextAttribute(hConsole, 7); // ����� ���� �� ������ ����
            }
            cout << text[i];
            this_thread::sleep_for(std::chrono::milliseconds(100)); // �������� � 100 �����������
        }
        cout << "\r"; // ������� ������� � ������ ������
    }
    return 0;
}