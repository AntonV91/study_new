// ���������� ����� �����. ���������� ������� ���������
// � ����������� � �������� ���������� - ������. ����������
// ������� - ����� ��� ����� ������ � ���������� - �����,
// ��� ���������� �������������� �������� (��������,
// ���������, ���������, �������, � �.�.).

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
        if (den1 == 0)
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
    int userChoice;

    cout << "\n������ �����: " << endl;
    f1.show();
    cout << "������ �����: " << endl;
    f2.show();
    cout << endl;

    Fraction add = f1 + f2; // ��������
    Fraction subtr = f1 - f2; // ���������
    Fraction multipl = f1 * f2; // ���������
    Fraction divis = f1 / f2; // �������

    do
    {
        cout << "�������� ��������: " << endl << endl;
        cout << "1: ������� ��� �����" << endl;
        cout << "2: ������� �� ������ ����� ������" << endl;
        cout << "3: ����������� ��� �����" << endl;
        cout << "4: ��������� ������ ����� �� ������" << endl;
        cout << "0: ����� �� ���������" << endl;
        cout << endl;
        cout << "������� �����, ��������������� ��������: ";
        cin >> userChoice;
        cout << endl;

        switch (userChoice)
        {
        case 1:

            cout << "����� ���� ������: ";
            add.show();
            break;
        case 2:
            cout << "�������� ���� ������: ";
            subtr.show();
            break;
        case 3:
            cout << "������������ ���� ������: ";
            multipl.show();
            break;
        case 4:
            cout << "������� ���� ������: ";
            divis.show();
            break;
        case 0:
            cout << "����� �������!" << endl;
            exit(0);
        default:
            cout << "\n�� ������� ������������ �������! ���������� ���!" << endl << endl;
        }
    } while (userChoice < 0 || userChoice > 4);

    // � ������ ����� �������� ��� ������� � ����� � ����� ������ (�� ������ �������)
    cout << endl;
    system("pause");
    return 0;
}
