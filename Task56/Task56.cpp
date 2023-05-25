// ������ 4.
// ���� ������ � ���� �� ���������� ������. ��� ���������� ������ ������ ���������� ������, 
// ��������� �� ���� � �������� �� ������������� ����� �������.
// ��� ��������� ����. ����������� ���, ��������� ���� ������. ��������� �������� � ������ ����.

#include <iostream>
#include <fstream> // ��� ������ � �������
#include <Windows.h> // ��� ������ � ����������
#include <string> // ��� ������ � getline

using namespace std;

void title(); // �������� ������� ��� ������ ���������
bool openInputFile(ifstream& input, const string& filename); // ��� �������� �� �������� �����
int enterKey(); // ��� ����� "�����" (������� ��������)
string encryptText(string inputText, int key); // ��� ���������� ��������� ������
bool writeToFile(const string& text, const string& filename); // ��� �������� �� ������ � ����

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    title();
    ifstream input; //�������� ������� �������� ������ ��� ������ �� �����
    if (!openInputFile(input, "�������.txt")) // ��������� �������� �� ���� � �������� �������
    {
        return 1; // ���� ������ false, �� ��������� ����������� � ����� 1
    }

    string line;
    while (getline(input, line)) // ������ ����� �� ����� � ������� getline
    {
        cout << "\n�������� �����: " << line << endl;

        //��� ������ ������ ���������� enterKey() � encryptText()
        int key = enterKey(); // �������� ������ ��������

        string encrypted = encryptText(line, key); // �������� ������������� �����

        cout << "\n������������� �����: ";
        cout << encrypted << endl; // ������� �� ����� ��� �����������

        //������������� ����� ����������� � ���� (��������� �� "�������� ������")
        if (!writeToFile(encrypted, "�������������.txt"))
        {
            return 1; // ���� ������ false, �� ��������� ����������� � ����� 1
        }
    }
    input.close();
    cout << endl;
    system("pause");
    return 0;
}

void title() // �������-���������
{
    cout << "����� ���������� � ��������� ��� ���������� ������!" << endl;
    cout << "������� ��������� ����� ��� ������ ������ ������..." << endl;
}

string encryptText(string inputText, int key) // ������� ��� ���������� ������ 
{
    string encrypted = "";

    for (char symbol : inputText) // ����� �� ��������� ������
    {
        // ���������� �������� � ������ �������� ��������
        if (symbol >= 'a' && symbol <= 'z')
        {
            // �������� ������� �� "����" � ������� ������ (�� ���-�� ��������)
            symbol = 'a' + (symbol - 'a' + key) % 26;
        }
        // ���������� �������� � ������� �������� ��������
        else if (symbol >= 'A' && symbol <= 'Z')
        {
            symbol = 'A' + (symbol - 'A' + key) % 26;
        }
        // ���������� �������� � ������ �������� ��������� 
        // (�������� � �/� ���� �� �����, �������� �������� ������� ������ � �������)
        else if (symbol >= '�' && symbol <= '�')
        {
            symbol = '�' + (symbol - '�' + key) % 32;
        }
        // ���������� �������� � ������� �������� ���������
        else if (symbol >= '�' && symbol <= '�')
        {
            symbol = '�' + (symbol - '�' + key) % 32;
        }

        encrypted += symbol; // ��������� ������������� ������ � ������ encrypted
    }
    return encrypted;
}

bool openInputFile(ifstream& input, const string& filename) // ������� ��� �������� �� �������� �����
{
    input.open(filename);
    if (!input.is_open())
    {
        cout << "������: �� ������� ������� ���� " << filename << " ��� ������!" << endl;
        return false;
    }
    return true;
}

int enterKey() // ������� ��� ����� ����� (������� ��������)
{
    int key;
    cout << "\n������� ������ ��������: ";
    cin >> key;
    return key;
}

bool writeToFile(const string& text, const string& filename) // ������� ��� �������� �� ������ � ����
{
    ofstream output(filename);
    if (output.is_open())
    {
        output << text << endl;
        cout << "\n������� ��������� � ���� " << filename << "!" << endl;
        output.close();
        return true;
    }
    else
    {
        cout << "������: �� ������� ������� ���� " << filename << " ��� ������!" << endl;
        return false;
    }
}