// ������ 9.
// ���������� ���������� ���� �� ��������� �����������

#include <iostream>
#include <string> // ���������� ���������� ��� ������������� getline
#include <windows.h> // ���������� ���������� ��� ������������� SetConsole

using namespace std;

int countWords(string& str); // �������� ������� ��� �������� ���� � �����������

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str;
    cout << "������� �����������: " << endl << endl;
    getline(cin, str); // ���������� ������� getline ��� ��������� ������� ������ �� ������������
    cout << endl;
    countWords(str); // ������������ ���������� ���� � �����������
    cout << endl << endl;
    system("pause");
    return 0;
}

int countWords(string& str)
{
    int count = 0;
    for (int i = 1; i < str.length(); i++)
    {
        // ��������� ����������� ��� ����������� ������������� ���� ('\0' - ����� ������)
        if (str[i - 1] != ' ' && (str[i] == ' ' || str[i + 1] == '\0'))
            count++;
    }
    cout << "���������� ���� � �����������: " << count << endl;
    return count;
}
