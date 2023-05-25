// ������� 8.
// ��������� ��������� �� ������ ����� �����, ��������� ����� ��������� �������.
// ������������ � ��������� ���������� ���������� ��� ����������� �� �������, 
// � ����� �������� �������������.

#include <iostream>

using namespace std;

// �������� ������� ��� ������������� �������
void initArray(int* ptr, const int size);
// �������� ������� ��� ������ ������� �� �����
void showArray(int* ptr, const int size);
// �������� ������� ��� ������������ ��������� �������
int getSum(int* ptr, const int size);

int main()
{
    setlocale(LC_ALL, "Russian");
    const int size = 15;
    int ar[size];
    int* ptr = &ar[0]; // ���������� ����� �������� �������� ������� � ���������

    initArray(ar, size);
    cout << "��� � �� - ��� ������ �� " << size << " ���������!" << endl << endl;
    showArray(ar, size);
    cout << endl << endl;
    cout << "����� ��������� ������� = " << getSum(ar, size) << endl << endl;
    cout << endl;

    system("pause");
    return 0;
}

void initArray(int* ptr, int size) // �������������� ������
{
    srand(time(NULL));
    for (int i = 0; i < size; i++, ptr++)
    {
        *ptr = rand() % 100 + (-50);
    }
}

void showArray(int* ptr, int size) // ���������� ������ �� ������
{
    for (int i = 0; i < size; i++, ptr++)
    {
        cout << *ptr << " | ";
    }
}

int getSum(int* ptr, int size) // ������� ����� ��������� � �������
{
    int sum = 0;
    for (int i = 0; i < size; i++, ptr++)
    {
        sum += *ptr;
    }
    return sum;
}
