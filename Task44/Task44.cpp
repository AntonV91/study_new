// ������ 1.
// �������� �������, ����������� ������� ���������� ������� � ��������� �������.

#include <iostream>
#include <iomanip>

void title();
void initArray(int** ar, int rows, int cols);
void showArray(int** ar, int rows, int cols);
int** newArray(int rows, int cols);
void addCol(int** ar, int rows, int cols, int temp);
void inputVerify(int** ar, int rows, int cols, int userchoice);
void deleteArray(int** ar, int rows, int cols);

using namespace std;

int userChoice; // ���������� ���������� ��� ������ ������� �������

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

    int** ar = newArray(rows, cols);
    initArray(ar, rows, cols);
    showArray(ar, rows, cols);
    cout << endl;
    inputVerify(ar, rows, cols, userChoice);

    deleteArray(ar, rows, cols);
    cout << "������ �������! �� ��������!" << endl << endl;

    system("pause");
    return 0;
}

void title()
{
    cout << "�������� �������, ����������� ������� ���������� ������� � ��������� �������" << endl;
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

// ������� ������� ��� ����������������� ����� ������� �������, � ����� ��� ��������
// (������ ���������� ������� addCol � ������� �������� ������ �� �����)
void inputVerify(int** ar, int rows, int cols, int userChoice)
{
    do
    {
        cout << "������� ������� (����� �������), � ������� ���������� �������� ����� �������: (�� 1 �� " << cols + 1 << "): ";
        cin >> userChoice;
        if (userChoice >= 1 && userChoice <= cols + 1)
        {
            cols++;
            addCol(ar, rows, cols, userChoice);
            cout << endl;
            showArray(ar, rows, cols);
            cout << endl;
        }
        else
        {
            cout << "�� ����� ������������ ����� �������! ���������� ��� ���!" << endl;
            cout << endl;
        }

    } while (userChoice < 1 || userChoice > cols + 1);
}

// ��������� ������� � �������� ������
void addCol(int** ar, int rows, int cols, int temp)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // ��������� ����� ������� �� ���� ������� ������ ����� ������������ �������
            if (j == temp - 1)
            {
                for (int k = cols; k > temp - 1; k--)
                {
                    ar[i][k] = ar[i][k - 1];
                }
                // �������������� ����� ������� (��������� ��� ����������� 
                // ������� ������� �������, ����� �� ����� "�������� � �����") 
                ar[i][j] = rand() % 200 + (-100);
            }
        }
    }
}

void deleteArray(int** ar, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        if (ar[i])
        {
            ar[i] = nullptr;
            delete[] ar[i];
        }
        else
            cout << "ERROR: ������ ��� ���� �����������!" << endl;
    }
    if (ar)
    {
        ar = nullptr;
        delete[] ar;
    }
    else
        cout << "ERROR: ������ ��� ���� �����������!" << endl;
}