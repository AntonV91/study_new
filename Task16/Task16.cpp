//������� 4. 
// ����� ������������ ���� ����� ����� �� a �� 20 (�������� a �������� � ���������� :
//1 <= a <= 20).

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	cout << "������ ������������ ���� ����� ����� �� a �� 20\n\n";
	int a;
	long long res = 1;
	// ������ ����������: � (�����, ������� ������ ������������), res (��������� ����������)
	// res � ���� long long, �.�. ��������� ����� "�� ����������" � ��������� ����� int � long

	do // ������ ����, ����� ������������ ���� ���������� �������� (������ ��������� 1-20)
	{
		cout << "������� ����� �� 1 �� 20:\n";
		// ������ ������������ ������ �������� �� 1 �� 20
		cin >> a;
	} while ((a < 1 || a > 20));

	for (int i = a; i <= 20; i++)
		res *= i; // ������ ����, ����� ����� �� � �� 20 �������������
	cout << "������������ ���� ����� ����� �� " << a << " �� 20 = " << res << endl;
	// ������� ��������� ���������� �� ����� (� ���������� ����������)

	system("pause");
	return 0;
}

