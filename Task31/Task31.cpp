//������ 1,3 (������ + �������).
// �������� ������������� ������� (int, double, char) 
// ��� ���������� ��������� ����� :
// - ������������� ���������� �������;
// - ����� ������� �� �����;
// - ����������� ������������� � ������������ �������� �� ������� ��������� �������.
// + ���������� ��� ������ ��������

#include <iostream>
#include <iomanip>
// ���������� ���������� iomanip, ����� ���������������
// �������� setw (���������� ��� ������� ������ ���� 
// ����������� ��� ���������� �������� � ������)

using namespace std;

template <typename T> void showArray(T ar[][4], const int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(4) << ar[i][j] << " \t ";
		}
		cout << endl;
	}
}
// ������� ������ ������� ��� ������ �������� �� �����;

template <typename T> T MinNumMainArray(T ar[][4], const int row, int col)
{
	T min = ar[0][0];
	for (int i = 0; i < row; i++)
		if (min > ar[i][i]) min = ar[i][i];
	cout << "����������� ������� �� ������� ��������� ������� = " << min << endl;
	return min;
}
// ������� ������ ������� ��� ������ � ������ �� ����� 
// ������������ �������� �� ������� ��������� ������� �������

template <typename T> T MaxNumMainArray(T ar[][4], const int row, int col)
{
	T max = ar[0][0];
	for (int i = 0; i < row; i++)
		if (max < ar[i][i]) max = ar[i][i];
	cout << "������������ ������� �� ������� ��������� ������� = " << max << endl;
	return max;
}
// ������� ������ ������� ��� ������ � ������ �� ����� 
// ������������� �������� �� ������� ��������� ������� �������

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	const int row = 4, col = 4;
	int arInt[row][col];
	double arDoub[row][col];
	char arChar[row][col];
	// ����������� ���� ���������� � �������� � ������ �� �����������
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arInt[i][j] = rand() % 50 + (-25);
			arDoub[i][j] = (rand() % 100 + (-50) / 3.01);
			arChar[i][j] = (char)rand() % 255;
		}
	}
	// �������������� �������, ������ ���������� ���������� �������
	// (���������) � �������� ����������

	cout << "������ ��������� int: " << endl << endl;
	showArray(arInt, row, col);
	cout << endl;
	MinNumMainArray(arInt, row, col);
	MaxNumMainArray(arInt, row, col);
	cout << endl;
	// ��������������� ������� �� ����� ������ int, 
	// � ����� max � min �������� �� ������� ���������
	cout << "������ ��������� double: " << endl << endl;
	showArray(arDoub, row, col);
	cout << endl;
	MinNumMainArray(arDoub, row, col);
	MaxNumMainArray(arDoub, row, col);
	cout << endl;
	cout << "������ ��������� char: " << endl << endl;
	showArray(arChar, row, col);
	cout << endl;
	MinNumMainArray(arChar, row, col);
	MaxNumMainArray(arChar, row, col);
	cout << endl;
	// ��������� �������� ��� �������� double � char
	
	system("pause");
	return 0;
}