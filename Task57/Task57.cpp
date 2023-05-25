// ������ 2.
// ��� ��������� ����. ����� ����� ����� ������� ������.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ��������� �������
void showAll(ifstream& file); // ��� ������ �� ����� ������ �� �����
int findMax(const string& line); // ��� �������� �������� � ����� ������ ������ � ���������
int findMaxWS(const string& line); // ��� �������� �������� � ����� ������ ������ ��� ��������

int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream file("�����.txt"); // ��������� ���� "�����.txt" ��� ������

    if (file.is_open()) // ���������, ������� �� ������� ����
    {
        cout << "���������� �����: " << endl << endl;
        showAll(file); // �������� ������� showAll ��� ������ �� ����� � �������
        file.close(); // ��������� ����
    }
    else // ���� ���� �� ��������
    {
        cout << "������: �� ������� ������� ����!" << endl; // ������� ��������� �� ������
    }

    return 0;
}

void showAll(ifstream& file) // ������� ��� ������ �� ����� ������ �� �����
{
    int max = 0; // ���������� ��� �������� ����� ������� ������
    int maxWS = 0; // ���������� ��� �������� ����� ������� ������ (��� ��������)
    string line; // ���������� ��� �������� ������� ������ �� �����

    while (getline(file, line)) // ������ ������ �� �����, ���� ��� �� ����������
    {
        cout << line << endl; // ������� ������� ������ �� �����
        int current = findMax(line); // ������� ����� ������� ������
        int currentWS = findMaxWS(line); // ������� ����� ������� ������ (��� ��������)

        if (current > max) // ���� ������� ����� ������ ���������� ������������
        {
            max = current; // ��������� �������� ������������ �����
        }
        // �� �� �����, �� ��� ��������
        if (currentWS > maxWS)
        {
            maxWS = currentWS;
        }
    }
    cout << "\n����� ����� ������� ������ " << max << " ������(��), ��� " << maxWS << " ������(��) ��� ��������" << endl;
}

int findMax(const string& line) // ������� ��� ������ ����� ������� ������ (� ���������)
{
    return line.length();
}

int findMaxWS(const string& line) // ������� ��� ������ ����� ������� ������ (��� ��������)
{
    int count = 0; // ����������-������� ��� ��������
    for (char c : line)
    {
        if (c != ' ')
        {
            count++; // ���� ������ �� ������, �� ������� ���
        }
    }
    return count;
}