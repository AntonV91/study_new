// ������ 4.
// ���������������� ������� � ��� ��������, ����� ������� ������� ������� ������� 
// ���������� ��������, � ������ � ���������. �������� ������� ���������������� �������.

#include <iostream>
#include <iomanip>

using namespace std;

void title();
void initArray(int** ar, int rows, int cols);
void showArray(int** ar, int rows, int cols);
int** newArray(int rows, int cols);
int** transpArray(int** matrix, int rows, int cols);
void deleteArray(int** ar, int rows);

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    title();
    cout << endl;
    // ������ ������������ ������ ���������� ����� � �������� � �������
    cout << "������� ���������� ����� �������: ";
    int rows;
    cin >> rows;
    cout << "������� ���������� �������� �������: ";
    int cols;
    cin >> cols;
    cout << endl;

    // C����� ������, � ������� ����� ��������
    int** ar = newArray(rows, cols);

    cout << "�������� ��������� ������ (�������): ";
    cout << endl;
    initArray(ar, rows, cols);
    showArray(ar, rows, cols);
    cout << endl;
    // ������������� ������� � ������� � �� �����
    int** tAr = transpArray(ar, rows, cols);
    cout << "����������������� ������ (�������): ";
    cout << endl;
    showArray(tAr, cols, rows);
    cout << endl;

    // ����������� ���������� ������
    deleteArray(ar, rows);
    deleteArray(tAr, cols);

    system("pause");
    return 0;
}

void title()
{
    cout << "���������������� ������� � ��� ��������," << endl;
    cout << "����� ������� ������� ������� ������� ���������� ��������, � ������ � ���������." << endl;
    cout << "������� ������� ���������������� �������." << endl;
}

void initArray(int** ar, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ar[i][j] = rand() % 20 + (-10);
        }
    }
}

void showArray(int** ar, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << ar[i][j] << " | ";
        }
        cout << endl;
    }
}

// ������� ������� ��� �������, � ������� ����� ��������
int** newArray(int rows, int cols)
{
    int** ar = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        ar[i] = new int[cols];
    }
    return ar;
}

// ������������� ������� (���� ������ ����� � ��������)
int** transpArray(int** tAr, int rows, int cols)
{
    int** fin = newArray(cols, rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fin[j][i] = tAr[i][j];
        }
    }
    return fin;
}

// ����������� ������ ����� ����������� ����������� � ���������
void deleteArray(int** ar, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] ar[i];
    }
    delete[] ar;
}