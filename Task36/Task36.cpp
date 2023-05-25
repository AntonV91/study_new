// ������� 7:
// �������� ����������� �������, ������� ��������� ���������� ������ �� 100 ����� �����, 
// ����������� ��������� �������, � ������� �������, � ������� ���������� ������������������ 
// �� 10 �����, ����� ������� ����������.

#include <iostream>
#include <iomanip>

using namespace std;

// �������� ������� ��� ������������� �������
void initArray(int ar[], const int size);
// �������� ������� ��� ������ ������� �� �����
void showArray(int ar[], const int size);
// �������� ������� ��� ������ ����������� �����
int findMin(int ar[], const int size, int num, int& min);

int main()
{
    setlocale(LC_ALL, "Russian");
    const int size = 100;
    int ar[size];
    int min;
    int num = 0;

    initArray(ar, size);
    showArray(ar, size);
    cout << endl << endl;
    findMin(ar, size, num, min);
    cout << endl;
    cout << "����������� ����� ��������� ��������� � ��������� � " << min << "�� �� " << min + 9 << "�� �������" << endl << endl;
    cout << endl;

    system("pause");
    return 0;
}

// ������� ��� ���������� ����� ��� ������ ������������������ �� 10 ���������,
// � ������ ����������� �����
int findMin(int ar[], int size, int num, int& min) // �� ������� �������� �������� �������������
// ��������� ���������� min (�� ������������ � main), ���������� �� ������� � ����������
{
    int sum = 0;
    for (int i = num; i < num + 10; i++) // ���� ����� � ��������� 10 ���������
    {
        sum += ar[i];
    }
    cout << "����� ��������� � " << num << "��" << " �� " << num + 9 << "�" << " = " << sum << endl;

    // ������������ ������������ 90� ���������, �.�., 
    // ������� � 91��, ����� ����� ��������� �� �����, ��� ��� ������
    if (num >= 90)
        /*if (num >= size - 10)*/
    {
        min = num;
        return sum;
    }
    if (num < 90)
        /*if (num < size - 10)*/
    {
        int sumNext = findMin(ar, size, num + 1, min); // ������ ���������� � ���������� ���������� ������
        if (sum <= sumNext)
        {
            min = num;
            return sum;
        }
        else
            return sumNext;
    }
}

void showArray(int ar[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(2) << ar[i] << " | ";
    }
}

void initArray(int ar[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        ar[i] = rand() % 100 + (-50);
    }
}
