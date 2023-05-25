// ���������� ����� �����. 
// ���������� ������� ��������� � ����������� � �������� ���������� - ������. 
// ���������� ������� - ����� ��� ����� ������ � ���������� - �����,
// ��� ���������� �������������� �������� (��������, ���������, ���������, �������, � �.�.).

#include <iostream>

using namespace std;

class Fraction
{
public:
    Fraction(int n, int d) : numerator(n), denominator(d) {}

    // �������-����� ��� ��������� ��������� � �����������
    void setNumerator(int n) { numerator = n; }
    void setDenominator(int d) { denominator = d; }

    // ����������� ������� ���������� ��� (����������� ������ ��������)
    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }

    // �������-����� ��� �������������� �������� (���������� ���������)
    Fraction operator+(Fraction& f) // ��������
    {
        int n = numerator * f.denominator + f.numerator * denominator;
        int d = denominator * f.denominator;
        int g = gcd(abs(n), d); // �������� ������� ��� (������ � �������������� ������� abs ����� � �����-�� �����������)
        return Fraction(n / g, d / g);
    }

    Fraction operator-(Fraction& f) // ���������
    {
        int n = numerator * f.denominator - f.numerator * denominator;
        int d = denominator * f.denominator;
        int g = gcd(abs(n), d);
        return Fraction(n / g, d / g);
    }

    Fraction operator*(Fraction& f) // ���������
    {
        int n = numerator * f.numerator;
        int d = denominator * f.denominator;
        int g = gcd(abs(n), d);
        return Fraction(n / g, d / g);
    }

    Fraction operator/(Fraction& f) // �������
    {
        int n = numerator * f.denominator;
        int d = denominator * f.numerator;
        int g = gcd(abs(n), d);
        return Fraction(n / g, d / g);
    }

    // �������-���� ��� ������ ����� �� �����
    void show()
    {
        cout << numerator << "/" << denominator << endl;
    }

private:
    // ���������� ��������� (numerator) � ����������� (denominator)
    int numerator;
    int denominator;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int num1, den1, num2, den2;

    cout << "\t\t\t = ����� ���������� � ��������� ��� �������������� �������� � �������! = " << endl << endl;
    cout << "\t\t\t\t::: ������� ��������� � ����������� ����� 1 � ����� 2 ::: " << endl << endl;

    cout << "������� ��������� ������ �����: ";
    cin >> num1;
    do
    {
        cout << "������� ����������� ������ �����: ";
        cin >> den1;
        if (den1 == 0) // ��������� �� ������������ �������� �� "���������" �����������
            // ����� ������� (�����), ������� �����
        {
            cout << "\n����������� �� ����� ���� ����� ����! ���������� ������ �����!" << endl << endl;
        }
    } while (den1 == 0);

    cout << "\n������� ��������� ������ �����: ";
    cin >> num2;
    do
    {
        cout << "������� ����������� ������ �����: ";
        cin >> den2;
        if (den2 == 0)
        {
            cout << "\n����������� �� ����� ���� ����� ����! ���������� ������ �����!" << endl << endl;
        }
    } while (den2 == 0);

    Fraction f1(num1, den1);
    Fraction f2(num2, den2);

    cout << "\n������ �����: ";
    f1.show();
    cout << "������ �����: ";
    f2.show();

    // ���������� ������ ����� ����� ���������������� ���� (switch-case), �� ����� ������ 
    // (������������� ������, ������������ � �.�.). ��� ���������.
    Fraction add = f1 + f2; // ��������
    cout << "\n����� (+) ���� ������: ";
    add.show();

    Fraction subtr = f1 - f2; // ���������
    cout << "�������� (-) ���� ������: ";
    subtr.show();

    Fraction multipl = f1 * f2; // ���������
    cout << "������������ (*) ���� ������: ";
    multipl.show();

    Fraction divis = f1 / f2; // �������
    cout << "������� (/) ���� ������: ";
    divis.show();
    cout << endl;

    // � ������ ����� �������� ��� ������� � ����� � ����� ������ (�� ������ �������)

    system("pause");
    return 0;
}
