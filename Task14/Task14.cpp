// ������� 2. 
// �������� ���������, ������� ����������� ��� ����� ����� x � y, 
// ����� ���� ��������� � ������� �������� x � ������� y.

#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");

	int x, y; // ������ ���������� ��� ������� ����������
	cout << "����� ���������� � ��������� ��� ���������� ����� � �������!\n\n";
	cout << "������� ����� ������� ����� �������� � �������:\nx = ";
	cin >> x;
	cout << "\n������� �������, � ������� ���������� �������� �����:\ny = ";
	cin >> y;
	// ������ ������������ ������ �������� x � y

	cout << "\n�������� " << x << " � ������� " << y << " (x^y) " << " = " << pow(x, y) << endl;
	// ���������� ���������� ��� ������ ������� pow � ������� ��������� ���������� �� �����
	return 0;
}

