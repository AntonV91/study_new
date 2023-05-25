// ������ 4.
// ���������� ������������� ������ ��� ����� ������� � ������� �����������, 
// ���� ������� �������������� ���� ��������� ������ ����; 
// ����� - ���� ������ �����. ��������� ����� ������� �� �����������, 
// � ����������� � �������� �������.

#include <iostream>
#include <iomanip>

using namespace std;

// ��������� ������� ��� ������������� �������
void initArray(int ar[], const int size);

// �������� ������� ��� ������ ������� �� �����
void showArray(int ar[], const int size);

// ��������� ������� ��� ���������� �������
void selectSort1(int ar[], const int size);
void selectSort2(int ar[], const int size);

// ��������� ������� ��� ������������� �������
void initArray(int ar[], const int size);

// �������� ������� ��� ������ ������� �� �����
void showArray(int ar[], const int size);

// ��������� ������� ��� �������������� ����� �������
void revArray1(int ar[], const int size);
void revArray2(int ar[], const int size);

// �������� ������� ��� ������ �������� ���������������
double averNumArray(int ar[], const int size);

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    const int size = 12;
    int ar[size];

    // ���������� ���������� �������: ������������� �������,
    // ����� "���������" ������� �� �����, ������� ��������������
    // (� "������" � �������� �� ���������� � ������), ����� 
    // "������������������" ������� �� �����
    initArray(ar, size);
    showArray(ar, size);
    cout << endl << endl;
    averNumArray(ar, size);
    showArray(ar, size);
    cout << endl << endl;

    return 0;
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

void selectSort1(int ar[], int size)
{
    int i, j, k;
    int x;
    // ��� �������� ������ ���������� part,
    // ������ 2/3 �������
    int part = (size * 2) / 3;

    // i - ����� �������� ����
    for (i = 0; i < size; i++)
    {
        k = i;
        x = ar[i];
        // ���� ������ ����������� ��������
        for (j = i + 1; j < part; j++)
            if (ar[j] < x)
            {
                k = j;
                x = ar[j];
                // k - ������ ����������� ��������
            }
        if (k != i)
        {
            ar[k] = ar[i];
            // ������ ������� ���������� � a[i]
            ar[i] = x;
        }
    }

}

void revArray1(int ar[], int size)
{
    // ������������ �������� ��������: ���� �� ������� ��������
    // ��������� ����� ������� �� �������� ��������� �����
    // (� ����� ������ ��� 5/6);
    // ��� �������� ������ ���������� point 1-2
    int point1 = (size * 2) / 3;
    int point2 = (size * 5) / 6;
    
    for (int i = point1; i < point2; i++)
    {
        int tmp = ar[i];
        ar[i] = ar[size - (i - point1) - 1];
        ar[size - (i - point1) - 1] = tmp;
    }
}

void selectSort2(int ar[], int size)
{
    int i, j, k;
    int x;
    // ��� �������� ������ ���������� part,
    // ������ 2/3 �������
    int part = size / 3;
    // i - ����� �������� ����
    for (i = 0; i < size; i++)
    {
        k = i;
        x = ar[i];
        // ���� ������ ����������� ��������
        for (j = i + 1; j < part; j++)
            if (ar[j] < x)
            {
                k = j;
                x = ar[j];
                // k - ������ ����������� ��������
            }
        if (k != i)
        {
            ar[k] = ar[i];
            // ������ ������� ���������� � a[i]
            ar[i] = x;

        }
    }
}

void revArray2(int ar[], int size)
{
    // ������������ �������� ��������: ���� �� ������� ��������
    // ��������� ���� ������ ������� �� ������� �������� ��������� �����
    // (� ����� ������ ��� 2/3);
    // ��� �������� ������ ���������� point 1-2
    int point1 = size / 3;
    int point2 = (size * 2) / 3;

    for (int i = point1; i < point2; i++)
    {
        int tmp = ar[i];
        ar[i] = ar[size - (i - point1) - 1];
        ar[size - (i - point1) - 1] = tmp;
    }
}

double averNumArray(int ar[], int size)
{
    double sum = 0;
    double averNum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += ar[i];
        averNum = sum / size;

    }
    // ������ �� �������� �������� ��������������� (������ ��� ������ ����),
    // ������ "�����" ��� ������ ���������� ���������� (2/3 ��� 1/3) 
    // � ������� (1/3 ��� 2/3). ������ ������ �� ������� selectSort 1-2 � revArray 1-2, 
    // ���, �������� �� ����� ��������� (������� � ��������� ������ ��� ������������ ����),
    // ������ ��������� �������� ���������.
    cout << "������� �������������� ���� ��������� ������� = " << averNum << ", �������������� ";
    if (averNum > 0)
    {
        cout << "�� ��������� ������ 2/3 �������!" << endl;
        selectSort1(ar, size);
        revArray1(ar, size);
        cout << endl;
    }
    else
    {
        cout << "�� ��������� ������ 1/3 �������!" << endl;
        selectSort2(ar, size);
        revArray2(ar, size);
        cout << endl;
    }

    return averNum;
}


