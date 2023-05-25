#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class Person
{
private:
    string* name; // Указатель на имя (должен быть динамическим)
    int age; // Возраст
public:
    // Конструктор по умолчанию
    Person() : name(new string()), age(0) {}

    // Конструктор с параметрами
    Person(const string& n, int a) : name(new string(n)), age(a) {}

    // Конструктор копирования
    Person(const Person& other) : name(new string(*(other.name))), age(other.age) {}

    // Деструктор
    ~Person() {
        delete name; // Освобождаем память, выделенную под name
    }

    // Геттер для имени (inline-функции использовать смысла нет)
    string getName() const
    {
        return *name;
    }

    // Геттер для возраста
    int getAge() const
    {
        return age;

    }
};

class Apartment
{
private:
    int number; // Номер квартиры
    Person* residents; // Указатель на массив жителей квартиры
    int numResidents; // Количество жителей квартиры
public:
    // Конструктор по умолчанию
    Apartment() : number(0), residents(nullptr), numResidents(0) {}

    // Конструктор с параметрами
    Apartment(int num, Person* r, int n) : number(num), residents(new Person[n]), numResidents(n)
    {
        for (int i = 0; i < n; i++)
        {
            residents[i] = r[i];
        }
    }

    // Конструктор копирования
    Apartment(const Apartment& other) : number(other.number), residents(new Person[other.numResidents]), numResidents(other.numResidents)
    {
        for (int i = 0; i < numResidents; i++)
        {
            residents[i] = other.residents[i];
        }
    }

    // Деструктор
    ~Apartment()
    {
        delete[] residents; // Освобождаем память, выделенную под residents
    }

    // Геттер для номера квартиры
    int getNumber() const
    {
        return number;
    }

    // Геттер для массива жителей
    Person* getResidents() const
    {
        return residents;
    }

    // Геттер для количества жителей
    int getNumResidents() const
    {
        return numResidents;
    }
};

class House
{
private:
    Apartment* apartments; // Указатель на массив квартир в доме
    int numApartments; // Количество квартир в доме
public:
    // Конструктор по умолчанию
    House() : apartments(nullptr), numApartments(0) {}

    // Конструктор с параметрами
    House(int n, Apartment* a) : numApartments(n), apartments(new Apartment[n])
    {
        for (int i = 0; i < n; i++)
        {
            apartments[i] = a[i];
        }
    }

    // Конструктор копирования
    House(const House& other) : numApartments(other.numApartments), apartments(new Apartment[other.numApartments])
    {
        for (int i = 0; i < numApartments; i++)
        {
            apartments[i] = other.apartments[i];
        }
    }

    // Деструктор
    ~House()
    {
        delete[] apartments; // Освобождаем память, выделенную под apartments
    }

    // Геттер для массива квартир
    Apartment* getApartments() const
    {
        return apartments;
    }

    // Геттер для количества квартир
    int getNumApartments() const
    {
        return numApartments;
    }

    // показ информации о квартирах и жителях
    void showHouseInfo(const House& house)
    {
        cout << "Информация о жителях дома:" << endl;
        cout << "Количество квартир: " << house.getNumApartments() << endl;

        Apartment* apartments = house.getApartments();
        for (int i = 0; i < house.getNumApartments(); i++)
        {
            cout << "Номер квартиры: " << apartments[i].getNumber() << endl;

            Person* residents = apartments[i].getResidents();
            int numResidents = apartments[i].getNumResidents();
            for (int j = 0; j < numResidents; j++)
            {
                cout << "Житель " << j + 1 << " Имя: " << residents[j].getName() << endl;
                cout << "Житель " << j + 1 << " Возраст: " << residents[j].getAge() << endl;
            }
        }
    }
};

int main()
{
    // Создаем квартиры и жителей
    Person p1("John", 30);
    Person p2("Jane", 25);
    Person p3("Bob", 40);
    Person p4("Alice", 35);

    Person apartment1Residents[] = { p1, p2 };
    Apartment apartment1(101, apartment1Residents, 2);

    Person apartment2Residents[] = { p3, p4 };
    Apartment apartment2(102, apartment2Residents, 2);

    Apartment apartments[] = { apartment1, apartment2 };
    House house(2, apartments);

    // Показываем информацию о доме
    showHouseInfo(house);

    return 0;
}