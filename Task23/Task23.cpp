// ������ 4.
// �������� ���������, ���������� ��������������� ��������
// ������ ������� �������� 10 ��������� � ��� ������� 
// �������� 5 ��������� ������.

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	// ������ ���������� ���������� ������� (������ ������ ��������� - �������)
	int ar1[10]{}, ar2[5]{}, ar3[5]{};
	// ��������� � �������������� �������: ������ �� 10 ���������,
	// � ����� ������ � ������ - �� ����

	cout << "C����� �� ��������������� �� 2023 ���: \n\n";
	bool alrThere;

	for (int i = 0; i < 10; i++)
		// ������ ���� ��� ���������� ������� (���������) �������:
		// �� 0�� �� 9�� ������� (�������� 1-10), ��� +1
	{
		ar1[i] = rand() % 40 + (1953);
		// ������ ���������� ���������� ������� 
		// � ������������� ����������� (��������������� ����� ������
		// �������� �� 1953 �� 1992 �.�.)
		// (� ��������� ������� �������� �.�. ����� �����������,
		// �.�. �� �� ������ ���������� "�����������" ����������. 
		// ��� ��� �������� � ����� (����� ���� ���������� bool 
		// ��� �������������� �����, ��������� ����� ��� �������� � �.�.),
		// �� ����������� ���� �� �������. �������� ��������� ����� � �� ���� ������ :)
		cout << "���. ������������������ �-�� " << "" << ar1[i] << " �.�.\n";
	}

	cout << endl;
	cout << "������� � 1� ���������: \n\n";
	for (int i = 0; i < 5; i++)
		// ������ ���� ��� ���������� ������� �������,
		// ������������ ����� ����������, ��� +1
	{
		ar2[i] = ar1[i];
		// �������� �������� �� ������� #1:
		// �� 0�� �� 4�� ������� (�������� 1-5)
		cout << "���. ������������������ �-�� " << "" << ar2[i] << " �.�.\n";
	}

	cout << endl;
	cout << "������� �� 2� ���������: \n\n";
	for (int i = 0; i < 5; i++)
		// ������ ���� ��� ���������� �������� �������,
		// ������������ ����� ����������, ��� +1
	{
		ar3[i] = ar1[i + 5];
		// �������� �������� �� ������� #1:
		// �� 5�� �� 9 ������� (�������� 6-10)
		// ��� ����� ��������� � �������� +5
		cout << "���. ������������������ �-�� " << "" << ar3[i] << " �.�.\n";
	}
	return 0;
}