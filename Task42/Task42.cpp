// ������� 4.
// ���� ��� �������: �[M] � B[N](M � N �������� � ����������).
// ���������� ������� ������ ������ ���������� ���������� �������, 
// � ������� ����� ������� ����� �������� ���� �������� ��� ����������

#include <iostream>
#include <windows.h>

using namespace std;

void title();
void memAlloc(int* ar1, int* ar2, int* ar3, int size1, int size2, int size3);
void initArray(int* ar, int size);
void showArray(int* ar, int size);
int  gener3rd(int* ar1, int* ar2, int* ar3, int size1, int size2, int tempSize, int& size3);  //����������
void deleteArrays(int* ar1, int* ar2, int* ar3);
void joinArray(int* ar1, int* ar2, int* ar3, int size1, int size2);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	title();
	cout << endl;

	int size1, size2, size3 = 0;

	int* ar1 = nullptr;
	int* ar2 = nullptr;
	int* ar3 = nullptr;

	cout << "������� ������ ������� �������: ";
	cin >> size1;
	cout << "������� ������ ������� �������: ";
	cin >> size2;

	ar1 = new int[size1];
	ar2 = new int[size2];
	ar3 = new int[size1 + size2];
	cout << endl;

	memAlloc(ar1, ar2, ar3, size1, size2, size3);

	initArray(ar1, size1);
	initArray(ar2, size2);
	cout << "������ ������� ������� = " << size1 << endl;
	cout << "������ ������: ";
	showArray(ar1, size1);
	cout << endl;
	cout << "������ ������� ������� = " << size2 << endl;
	cout << "������ ������: ";
	showArray(ar2, size2);
	cout << endl;

	// ������� ������� ��� ���������� ���� �������� � ������ ��� � 3�� ������
	// (��� �����������, � ����� ���� �����-�� ������ ��������� �������� :-)
	joinArray(ar1, ar2, ar3, size1, size2);
	cout << "������ ������������ ������� = " << size1 + size2 << endl;
	cout << "������������ ������: ";
	showArray(ar3, size1 + size2);
	cout << endl;

	int tempSize = (size1 > size2) ? size1 : size2;
	gener3rd(ar1, ar2, ar3, size1, size2, tempSize, size3);
	showArray(ar3, size3);

	deleteArrays(ar1, ar2, ar3);

	system("pause");
	return 0;
}

void showArray(int* ar, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << " | ";
	}
	cout << endl;
}

void initArray(int* ar, int size)
{
	for (int i = 0; i < size; i++)
	{
		ar[i] = rand() % 10 + (-5);
	}
}

void deleteArrays(int* ar1, int* ar2, int* ar3)
{
	if (ar1)
	{
		delete[] ar1;
		ar1 = nullptr;
	}
	if (ar2)
	{
		delete[] ar2;
		ar2 = nullptr;
	}
	if (ar3)
	{
		delete[] ar3;
		ar3 = nullptr;
	}
}

void memAlloc(int* ar1, int* ar2, int* ar3, int size1, int size2, int size3)
{
	if (!ar1 || !ar2 || !ar3)
	{
		cout << "ERROR: ������ ��������� ������!" << endl;
		exit(0);
	}
}

void title()
{
	cout << "���� ��� �������: ar1[size1] � ar2[size2] (size1 � size2 �������� � ����������)." << endl;
	cout << "���������� ������� ������ ������ ���������� ���������� �������," << endl;
	cout << "� ������� ����� ������� ����� �������� ���� �������� ��� ����������." << endl;
}

// ����������� ���� �������� � ������ (�������, ��� "���������", ��� �����������)
void joinArray(int* ar1, int* ar2, int* ar3, int size1, int size2)
{
	for (int i = 0; i < size1; i++)
		ar3[i] = ar1[i];

	for (int i = size1, j = 0; j < size2; i++, j++)
		ar3[i] = ar2[j];
}

// ������� �������� �� �� ���� �������, � ��������� (��������� �� ����� ������)
// ����������� ��� ��������� ��� ������� (� ��������� �� ����������), ���������� ������ � ���������� ����
// ����� ����� �� ����. ������ ��������� �� ���� ��� ������, � ������ � �����. �������� � ���� ������� :-)
int gener3rd(int* ar1, int* ar2, int* ar3, int size1, int size2, int tempSize, int& size3)
{
	int temp;   // ����������� temp, �������� �� ��������� ���������
	for (int i = 0; i < tempSize; i++)
	{
		for (int j = 0; j < tempSize; j++)
		{
			if ((ar1[j] == ar2[i]) && (ar1[j] != ar3[size3]))  // �������� �� ������������ � ����������
			{
				temp = ar1[j];
				ar3[size3] = temp; // ���������� �������� ����� ��������� � 3� ������
				size3++;
			}
		}
	}
	cout << "������ �������� ������� = " << size3 << endl;

	return ar3[size3];
}

