// Задача 2.
// Создайте класс Complex (комплексное число) или используйте уже созданный вами класс.
// Создайте перегруженные операторы для реализации арифметических операций 
// по работе с комплексными числами (операции + , -, *, / ).

#include <iostream>
#include <windows.h>
using namespace std;

class Complex
{
public:
    // Конструктор класса с параметрами по умолчанию
    // Переменные для действительной и мнимной частей задаем в double, 
    // чтобы корректно отображся результат вычисления (как минимум при делении)
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Перегруженные операторы сложения, вычитания, умножения и деления

    // Сумма двух комплексных чисел вычисляется по формуле:
    // z = (a1 + a2) + (b1 + b2)i
    Complex operator+(const Complex& c) const
    {
        return Complex(real + c.real, imag + c.imag);
    }

    // Разность двух комплексных чисел вычисляется по формуле:
    // z = (a1 - a2) + (b1 - b2)i
    Complex operator-(const Complex& c) const
    {
        return Complex(real - c.real, imag - c.imag);
    }

    // Произведение двух комплексных чисел вычисляется по формуле:
    // z = z1 * z2 = (a1a2 - b1b2) + (a1b2 + b1a2)i
    Complex operator*(const Complex& c) const
    {
        double r = real * c.real - imag * c.imag;
        double i = real * c.imag + imag * c.real;
        return Complex(r, i);
    }

    // Частное двух комплексных чисел вычисляется по формуле:
    // z = z1 / z2 = ((a1a2 + b1b2) / (a2*a2 + b2*b2)) + ((a2b1 -a1b2) / (a2*a2 + b2*b2))i
    Complex operator/(const Complex& c) const
    {
        double r = (real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag);
        double i = (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag);
        return Complex(r, i);
    }

    // Сеттеры и геттеры для значений вещественной и мнимой частей
    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Перегруженный оператор вывода (обращаемся к дружественной функции)
    friend ostream& operator<<(ostream& out, const Complex& c);

private:
    double real, imag; // переменные для действительной и мнимой частей
};

// Перегруженный оператор вывода <<
// Перегрузка оператора вывода позволяет нам определить, как именно будут выведены значения 
// Можно обойтись без перегрузки, но тогда придется вызывать геттеры для вывода вещественной 
// и мнимой частей отдельно (добавляем сразу + и i после значения мнимой части)
// Перегрузка оператора вывода улучшит читаемость кода
ostream& operator<<(ostream& out, const Complex& c)
{
    out << c.real << " + " << c.imag << "i";
    return out;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double real1, real2, imag1, imag2;

    cout << "\t\t\t = Добро пожаловать в программу для арифметических действий с комплексными числами! = " << endl << endl;
    cout << "\t\t\t\t::: Введите действительную и мнимую части двух комплексных чисел ::: " << endl << endl;

    cout << "Введите действительную часть первого числа: ";
    cin >> real1;
    cout << "\nВведите мнимую часть первого числа: ";
    cin >> imag1;
    cout << "\nВведите действительную часть второго числа: ";
    cin >> real2;
    cout << "\nВведите мнимую часть второго числа: ";
    cin >> imag2;

    // Создание двух комплексных чисел
    Complex c1(real1, imag1);
    Complex c2(real2, imag2);

    // Вывод значений комплексных чисел
    cout << endl << "Комплексное число №1: " << c1 << endl;
    cout << "Комплексное число №2: " << c2 << endl;

    // Использование перегруженных операторов
    Complex add = c1 + c2; // сложение
    cout << endl << "Сумма (+) двух комплексных чисел: " << add << endl;

    Complex subtr = c1 - c2; // вычитание
    cout << "Разность (-) двух комплексных чисел: " << subtr << endl;

    Complex multipl = c1 * c2; // умножение
    cout << "Произведение (*) двух комплексных чисел: " << multipl << endl;

    Complex divis = c1 / c2; // деление
    cout << "Частное (/) двух комплексных чисел: " << divis << endl << endl;

    system("pause");
    return 0;
}