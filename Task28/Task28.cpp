// ������� 7.
// �������� �������, ������������ ������� �������������� 
// ��������� ������������� �� �������.

#include <iostream>
#include <iomanip>
// ���������� ���������� iomanip, ����� ���������������
// �������� setw (���������� ��� ������� ������ ���� 
// ����������� ��� ���������� �������� � ������)

using namespace std;

void showArray(int ar[][7], const int row, int col)
{
	cout << "����� ���������� � ��������� ��� ���������� �������� ��������������� ��������� �������!\n\n";
	cout << "������� �������� �� ��� ������: \n\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(2) << ar[i][j] << " \t ";
		}
		cout << endl;
	}
}
// ������ �������������� �������, ��������� ������ �� �����;
// ���������� ������� setw (������������� �� ����������� 
// ��������, � ����� ������ ������� ������� ��� min = 2)

void initArray(int ar[][7], const int row, const int col)
{
	srand(time(NULL));
	// ������ ���������� ���������� ������� (������ ������ ��������� - �������)
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			ar[i][j] = rand() % 100;
			// ������ ���������� ������� ���������� ������� �� 0 �� 100
		}
	}
}
// ������ �������������� �������, ���������������� ������: 
// ����������� (�������� ��������� ������� ������ ��������� 
// ���������� �������� [7]) � ��������� ����� � ��������

double averArray(int ar[][7], int row, int col)
{
	double sum = 0;
	double aver = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum += ar[i][j];
			aver = sum / (row * col);
		}

	}
	cout << "\n����� ���� ��������� ������� ���������� = " << sum << endl;
	cout << "\n���������� ��������� � ������� = " << row * col << endl;
	cout << "\n������� �������������� �������� ������� = " << aver << endl << endl;
	return aver;
}
// ������ ������������ �������, ����� ���������� 
// � ������� �� ����� ������� �������������� ��������� �������

int main()
{
	setlocale(LC_ALL, "Russian");
	const int row = 5, col = 7;
	// ������ ����������� ������� �� ������� � ��������
	int ar[row][col];
	// ������ ���������� �������
	initArray(ar, row, col);
	// �������� ������� ������������� �������
	showArray(ar, row, col);
	// �������� ������� ����������� ������� �� ������
	averArray(ar, row, col);
	// �������� ������� �������� ���������������

	system("pause");
	return 0;
}