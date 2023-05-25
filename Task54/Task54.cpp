// ������ 3.
// �������� �������, ����������� � �������� ���������� ��� ������ � ������������ 
// ����� ������� ���������, ��� ��������� ������� ��������� � ������� ����� � �()�.
// ��������, ���� ����������� ���� ������ "abaracadabra" � "ab", 
// �� ������� ���� "(ab)aracad(ab)ra"

#include <iostream> 
#include <string>
#include <windows.h>

using namespace std;

// �������� ������� ��� ������� ������ � ������
string insertParentheses(const string& str, const string& pattern);
// �������� ������� ��� �������� ���������� ��������� ��������� � ������
int countPatterns(const string& str, const string& pattern);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str1, str2;
    cout << "������� ������: ";
    getline(cin, str1); // ���� ������
    cout << "������� ������� ���������: ";
    getline(cin, str2); // ���� ������� ��������� 

    // ����� ������� insertParentheses � ���������� ���������� � ���������� result
    string result = insertParentheses(str1, str2);
    cout << "������������ ������: " << result << endl << endl;

    // ����� ������� countOccurrences � ���������� ���������� � ���������� count
    int count = countPatterns(str1, str2);
    cout << "������� " << count << " ���������(-��) ��������� " << "'" << str2 << "' " << "� �������� ������" << endl << endl;

    system("pause");
    return 0;
}

// ������� ��� ������� ������� ������
string insertParentheses(const string& str, const string& pattern)
{
    string result = str; // �������� ����� �������� ������
    size_t pos = 0; // ������������� ���������� pos ��� �������� ������� � ������

    // ���� ��� ������ �������� (���������) � ������
    while ((pos = result.find(pattern, pos)) != string::npos)
    {
        result.insert(pos, "("); // ������� ����������� ������ ����� ���������
        result.insert(pos + pattern.length() + 1, ")"); // ...� ����������� ����� ��������
        pos += 2; // ������� �� ��������� ������� ����� ����������� ������
    }
    return result;
}

// ������� ��� �������� ���������� ��������� ��������� � ������
int countPatterns(const string& str, const string& pattern)
{
    int count = 0;
    size_t pos = 0; // ������������� ���������� pos ��� �������� ������� � ������

    // ���� ��� ������ �������� (���������) � ������
    while ((pos = str.find(pattern, pos)) != string::npos)
    {
        count++; // ���������� ��������
        pos += pattern.length(); // ������� �� ��������� ������� ����� ���������� ���������
    }
    return count;
}