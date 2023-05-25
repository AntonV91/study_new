// Реализуйте класс Дробь. Необходимо хранить числитель
// и знаменатель в качестве переменных - членов. Реализуйте
// функции - члены для ввода данных в переменные - члены,
// для выполнения арифметических операций (сложение,
// вычитание, умножение, деление, и т.д.).

#include <iostream>

using namespace std;

class Fraction
{
public:
    Fraction(int n, int d) : numerator(n), denominator(d) {}

    // Функции-члены для установки числителя и знаменателя
    void setNumerator(int n) { numerator = n; }
    void setDenominator(int d) { denominator = d; }

    // Рекурсивная функция нахождения НОД (наибольшего общего делителя)
    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }

    // Функции-члены для арифметических операций (перегрузка оператора)
    Fraction operator+(Fraction& f) // Сложение
    {
        int n = numerator * f.denominator + f.numerator * denominator;
        int d = denominator * f.denominator;
        int g = gcd(abs(n), d); // вызываем функцию НОД (запись с использованием функции abs нашел в каком-то самоучителе)
        return Fraction(n / g, d / g);
    }

    Fraction operator-(Fraction& f) // Вычитание
    {
        int n = numerator * f.denominator - f.numerator * denominator;
        int d = denominator * f.denominator;
        int g = gcd(abs(n), d);
        return Fraction(n / g, d / g);
    }

    Fraction operator*(Fraction& f) // Умножение
    {
        int n = numerator * f.numerator;
        int d = denominator * f.denominator;
        int g = gcd(abs(n), d);
        return Fraction(n / g, d / g);
    }

    Fraction operator/(Fraction& f) // Деление
    {
        int n = numerator * f.denominator;
        int d = denominator * f.numerator;
        int g = gcd(abs(n), d);
        return Fraction(n / g, d / g);
    }

    // Функция-член для вывода дроби на экран
    void show()
    {
        cout << numerator << "/" << denominator << endl;
    }

private:
    // Переменные числителя (numerator) и знаменателя (denominator)
    int numerator;
    int denominator;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int num1, den1, num2, den2;
    cout << "\t\t\t = Добро пожаловать в программу для арифметических действий с дробями! = " << endl << endl;

    cout << "\t\t\t\t::: Введите числитель и знаменатель дроби 1 и дроби 2 ::: " << endl << endl;
    cout << "Введите числитель первой дроби: ";
    cin >> num1;
    do
    {
        cout << "Введите знаменатель первой дроби: ";
        cin >> den1;
        if (den1 == 0)
        {
            cout << "\nЗнаменатель не может быть равен нулю! Попробуйте ввести снова!" << endl << endl;
        }
    } while (den1 == 0);

    cout << "\nВведите числитель второй дроби: ";
    cin >> num2;
    do
    {
        cout << "Введите знаменатель второй дроби: ";
        cin >> den2;
        if (den2 == 0)
        {
            cout << "\nЗнаменатель не может быть равен нулю! Попробуйте ввести снова!" << endl << endl;
        }
    } while (den2 == 0);

    Fraction f1(num1, den1);
    Fraction f2(num2, den2);
    int userChoice;

    cout << "\nПервая дробь: " << endl;
    f1.show();
    cout << "Вторая дробь: " << endl;
    f2.show();
    cout << endl;

    Fraction add = f1 + f2; // Сложение
    Fraction subtr = f1 - f2; // Вычитание
    Fraction multipl = f1 * f2; // Умножение
    Fraction divis = f1 / f2; // Деление

    do
    {
        cout << "Выберите действие: " << endl << endl;
        cout << "1: Сложить две дроби" << endl;
        cout << "2: Вычесть из первой дроби вторую" << endl;
        cout << "3: Перемножить две дроби" << endl;
        cout << "4: Разделить первую дробь на вторую" << endl;
        cout << "0: ВЫЙТИ ИЗ ПРОГРАММЫ" << endl;
        cout << endl;
        cout << "Введите цифру, соответствующую варианту: ";
        cin >> userChoice;
        cout << endl;

        switch (userChoice)
        {
        case 1:

            cout << "Сумма двух дробей: ";
            add.show();
            break;
        case 2:
            cout << "Разность двух дробей: ";
            subtr.show();
            break;
        case 3:
            cout << "Произведение двух дробей: ";
            multipl.show();
            break;
        case 4:
            cout << "Частное двух дробей: ";
            divis.show();
            break;
        case 0:
            cout << "Всего доброго!" << endl;
            exit(0);
        default:
            cout << "\nВы выбрали неправильный вариант! Попробуйте еще!" << endl << endl;
        }
    } while (userChoice < 0 || userChoice > 4);

    // В идеале нужно добавить еще перевод в дробь с целой частью (на досуге займусь)
    cout << endl;
    system("pause");
    return 0;
}
