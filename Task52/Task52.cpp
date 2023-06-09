// ������ 2.
// �������� ����� Complex (����������� �����) ��� ����������� ��� ��������� ���� �����.
// �������� ������������� ��������� ��� ���������� �������������� �������� 
// �� ������ � ������������ ������� (�������� + , -, *, / ).

// � ��� ������������ ����� ����������� ����� �������� ���������� ��������� () 
// + �� ��������� � ���������� ������� ��������� ���������� ��������� �����

#include <iostream>
#include <windows.h>

using namespace std;

class Complex
{
public:
    // ����������� ������ � ����������� �� ���������
    // ���������� ��� �������������� � ������� ������ ������ � double, 
    // ����� ��������� ��������� ��������� ���������� (��� ������� ��� �������)
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // ������������� ��������� ��������, ���������, ��������� � �������

    // ����� ���� ����������� ����� ����������� �� �������:
    // z = (a1 + a2) + (b1 + b2)i
    Complex operator+(const Complex& c) const
    {
        return Complex(real + c.real, imag + c.imag);
    }

    // �������� ���� ����������� ����� ����������� �� �������:
    // z = (a1 - a2) + (b1 - b2)i
    Complex operator-(const Complex& c) const
    {
        return Complex(real - c.real, imag - c.imag);
    }

    // ������������ ���� ����������� ����� ����������� �� �������:
    // z = z1 * z2 = (a1a2 - b1b2) + (a1b2 + b1a2)i
    Complex operator*(const Complex& c) const
    {
        double r = real * c.real - imag * c.imag;
        double i = real * c.imag + imag * c.real;
        return Complex(r, i);
    }

    // ������� ���� ����������� ����� ����������� �� �������:
    // z = z1 / z2 = ((a1a2 + b1b2) / (a2*a2 + b2*b2)) + ((a2b1 -a1b2) / (a2*a2 + b2*b2))i
    Complex operator/(const Complex& c) const
    {
        double r = (real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag);
        double i = (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag);
        return Complex(r, i);
    }

    // ������� � ������� ��� �������� ������������ � ������ ������
    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // �������� () ��������� ���������� ����� �������� ������� ������ Complex, 
    // ��������� ��� ��������� - ����� �������� ��� real � imag ������������ �����
    Complex operator()(double r, double i) // ���������� ��������� ������ �������
    {
        real = r;
        imag = i;
        return *this; // ���������� ���������� ������ ������ Complex
    }

    // ������������� �������� ������ (���������� � ������������� �������)
    friend ostream& operator<<(ostream& out, const Complex& c);
    // ������������� �������� ����� (���������� � ������������� �������)
    friend istream& operator>>(istream& in, Complex& c);

private:
    double real, imag; // ���������� ��� �������������� � ������ ������
};

// ������������� �������� ������ <<
// ���������� ��������� ������ ��������� ��� ����������, ��� ������ ����� �������� �������� 
// ����� �������� ��� ����������, �� ����� �������� �������� ������� ��� ������ ������������ 
// � ������ ������ �������� (��������� ����� + � i ����� �������� ������ �����)
// ���������� ��������� ������ ������� ���������� ����
ostream& operator<<(ostream& out, const Complex& c)
{
    out << c.real << " + " << c.imag << "i";
    return out;
}

// ������������� �������� ����� >>
// ��������� ��� �� ������� ���������� ��������� ���������� (real1, imag1, real2, imag2)
istream& operator>>(istream& in, Complex& c)
{
    cout << "������� �������������� ����� ������������ �����: ";
    in >> c.real;
    cout << "������� ������ ����� ������������ �����: ";
    in >> c.imag;
    cout << endl;
    return in;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\t\t\t = ����� ���������� � ��������� ��� �������������� �������� � ������������ �������! = " << endl << endl;
    cout << "\t\t\t\t::: ������� �������������� � ������ ����� ���� ����������� ����� ::: " << endl << endl;

    // �1 � �2 ������� �� ���������� ������ (��� ���������� ��������� ()), 
    // ����� �������� ������� ������� (�� � ����������� �����)
    Complex c1, c2;
    cin >> c1 >> c2;
    cout << "����������� ����� �1: " << c1 << endl;
    cout << "����������� ����� �2: " << c2 << endl;
    Complex add = c1 + c2;
    cout << endl << "����� (+) ���� ����������� �����: " << add << endl;
    Complex subtr = c1 - c2;
    cout << "�������� (-) ���� ����������� �����: " << subtr << endl;
    Complex multipl = c1 * c2;
    cout << "������������ (*) ���� ����������� �����: " << multipl << endl;
    Complex divis = c1 / c2;
    cout << "������� (/) ���� ����������� �����: " << divis << endl << endl;

    // ����� ���������� ���������� ���������(), ������� c3 � c4 ����� ���� ������� ��� ������� 
    // � ������� ���������� ��� ��������� ���� double
    Complex c3, c4;

    // ������ Complex c3 ����� ������������ ������ c3, 
    // �.�. c3 ��� ��������� ��� ������ ������ Complex � ���������� ��������� () 
    // ��������� ������������� ��� �������� ��� ������ ������������� ����� ������
    c3(0.12, 4.9);
    c4(-0.001, -2);
    cout << "����������� ����� �3 ����� ������ ���������(): " << c3 << endl;
    cout << "����������� ����� �4 ����� ������ ���������(): " << c4 << endl;

    add = c3 + c4; // �� ���������� ��� ������
    cout << endl << "����� (+) ���� ����������� �����: " << add << endl;
    subtr = c3 - c4;
    cout << "�������� (-) ���� ����������� �����: " << subtr << endl;
    multipl = c3 * c4;
    cout << "������������ (*) ���� ����������� �����: " << multipl << endl;
    divis = c3 / c4;
    cout << "������� (/) ���� ����������� �����: " << divis << endl << endl;

    system("pause");
    return 0;
}