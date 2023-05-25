// ������ 5.
// �������� �������, ������� ��������� ������ � ������ ������������ ����� (�� 4000) 
// � ���������� ������, ���������� ������ ����� ����� �������� �������.

#include <iostream>
#include <string>

using namespace std;

string intToRoman(string numStr); // �������� ������� intToRoman

int main()
{
    setlocale(LC_ALL, "Russian");
    string numStr; // ������ ��� ����� ��������� �����
    string again;
    do
    {
        cout << "������� ����� ��� ������ �������� ����: ";
        cin >> numStr; // ������ �������� �����
        string romanNumeral = intToRoman(numStr); // �������� ������� ��� �������������� ����� � ������� ������� ���������
        cout << "����� " << numStr << " � ������� ������� ���������: " << romanNumeral << endl << endl;
        cout << "������ �� �� ��� ��� ��������� �������� ����� � �������? (Y/N): ";
        cin >> again; // ����������� ����� �� ��������� ���������� ���������
        //system("cls"); // ���������������, ���� ������� ������� ����� ����� ������ ��������
        cout << endl;
    } while (again == "Y" || again == "y");

    system("pause");
    return 0;
}

string intToRoman(string numStr)
{
    // ������� ��� ������� ���� � �� ��������
    const int numValues[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    const string romanValues[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    int num = stoi(numStr); // ����������� ������ � �����
    string roman = ""; // �������� ������ � ������� ������

    for (int i = 0; i < sizeof(numValues) / sizeof(numValues[0]); i++)
    {
        while (num >= numValues[i]) // ������ ����� while �����������, ���� num ������ ��� ����� 
                                   // �������� �������� numValues[i]
        {
            roman += romanValues[i]; // ��������� ������� ����� � �������� ������
            num -= numValues[i]; // �������� �������� ������� ����� �� �����
        }
    }
    return roman; // ���������� �������� ������ � ������� ������
}