//������� 3. 
//����� ������� �������������� ���� ����� ����� �� 1 �� 1000.

#include <iostream>
using namespace std;

int main()
{
setlocale(LC_ALL, "Rus");
double aver = 0; 
// ������ ���������� �������� ��������������� (aver) � ���������� ��������� �������������
		
for (int i = 1; i <= 1000; i++) // ��������� ���� for � ���������������� ���������
{
aver += i;
}
	
cout << "������� �������������� ���� ����� ����� �� 1 �� 1000 = " << aver / 1000 << endl;
// ������� �� ����� ��������� (����� ����� �� 1 �� 1000, ����������� �� ���������� �����, �.�. 1000)

system("pause");
return 0;

}