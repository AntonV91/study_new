// Задача 1.
// Создайте программу, имитирующую многоквартирный дом.
// Необходимо иметь классы «Человек», «Квартира», «Дом»
// Класс «Квартира» содержит динамический массив объектов класса «Человек».
// Класс «Дом» содержит массив объектов класса «Квартира».
// Каждый из классов содержит переменные-члены и функции-члены, необходимые для предметной области.
// Память под строковые значения выделяется динамически. Например, для ФИО в классе «Человек». 
// Обеспечим классы различными конструкторами (конструктор копирования обязателен), деструкторами.
// В main протестировать работу полученного набора классов.

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class Person
{
private:
    string name; // Имя человека
    int age; // Возраст человека
public:
    Person() : name(""), age(0) {} // Конструктор по умолчанию, инициализирующий поля значениями по умолчанию
    Person(const string& n, int a) : name(n), age(a) {} // Конструктор, принимающий имя и возраст человека
    Person(const Person& other) : name(other.name), age(other.age) {} // Конструктор копирования, копирующий имя и возраст человека из другого объекта
    ~Person() {} // деструктор по умолчанию
    string getName() const { return name; } // Метод, возвращающий имя человека
    int getAge() const { return age; } // Метод, возвращающий возраст человека
};

class Apartment
{
private:
    int number; // Номер квартиры
    vector<Person> residents; // Вектор объектов Person, представляющих жителей квартиры
public:
    Apartment() : number(0) {} // Конструктор по умолчанию, который устанавливает номер квартиры равным 0
    Apartment(int num, const vector<Person>& r) : number(num), residents(r) {} // Конструктор, принимающий в качестве аргументов номер квартиры и вектор жильцов
    Apartment(const Apartment& other) : number(other.number), residents(other.residents) {} // Конструктор копирования, который создает новый объект квартиры с тем же номером квартиры и жителями, что и исходный объект
    ~Apartment() {} // деструктор по умолчанию

    int getNumber() const { return number; } // Геттер для получения номера квартиры
    vector<Person> getResidents() const { return residents; } // Геттер для получения копии вектора жильцов

    // Функции addResident и removeResident в спокойном режиме попробую переписать позже 
    // (запутался с добавлением: по вводу квартиры и т.д.), чтобы вводилось с клавиатуры
    // Пока убрал все внутренности, т.к. все попытки их прописать заканчивались ошибками
    void addResident(const Person& resident) // добавляем жильца
    {
        residents.push_back(resident);
    }

    void removeResident(int index) // удаляем жильца
    {
        residents.erase(residents.begin() + index);
    }
};

class House
{
private:
    static const int NUM_APARTMENTS = 4; // константный int, устанавливающий количество квартир в доме
    vector<Apartment> apartments; // Вектор объектов Apartment, представляющих квартиры в доме
public:
    House() {} // Конструктор по умолчанию, не делает ничего, так как вектор уже инициализирован пустым
    House(const vector<Apartment>& apts) : apartments(apts) {} // Конструктор, принимающий вектор квартир и инициализирующий ими вектор apartments
    House(const House& other) : apartments(other.apartments) {} // Конструктор копирования, создающий новый объект House с тем же вектором квартир, что и исходный объект
    ~House() {} // деструктор по умолчанию
    static int getNumApartments() { return NUM_APARTMENTS; } // метод для получения количества квартир в доме
    vector<Apartment> getApartments() const { return apartments; } // Геттер для получения копии вектора квартир  

    // проверка при на то, что кол-во квартир не превышает NUM_APARTMENTS (+ добавление)
    bool addApartment(const Apartment& apt)
    {
        if (apartments.size() < NUM_APARTMENTS)
        {
            apartments.push_back(apt);
            return true;
        }
        else
        {
            return false;
        }
    }

    void showResidents() const // показываем жильцов поквартирно
    {
        for (const auto& apt : apartments)
        {
            cout << "Квартира №" << apt.getNumber() << ":\n";
            for (const auto& resident : apt.getResidents())
            {
                cout << " - " << resident.getName() << ", " << resident.getAge() << " лет\n";
            }
            cout << endl;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Пока сделал такую "затычку" с "готовыми людьми" в main, позже перепишу под ввод с клавиатуры 
    House house;
    house.addApartment(Apartment(1, { Person("Ольга Орлова", 30), Person("Роман Радов", 31) }));
    house.addApartment(Apartment(2, { Person("Артак Гаспарян", 50), Person("Лола Гаспарян", 44) }));
    house.addApartment(Apartment(3, { Person("Капитолина Петровская", 78) }));
    house.addApartment(Apartment(4, { Person("Пак Чхэн До", 19), Person("Ли Вун Ён", 20), Person("Халед Аль-Рахман", 18) }));
    house.showResidents();

    // Вызов функций для добавления и удаления жильца (пока не работает, ибо методы не написаны)
    // Запутался в попытках их верно прописать со связями между классами
    cout << "Обновленный список (ПОКА НЕ ОБНОВЛЯЕТСЯ):" << endl << endl;
    house.getApartments()[1].addResident(Person("Виктория Радова", 1)); // добавляем в кв.
    house.getApartments()[3].removeResident(1); // удаляем из кв. по индексу
    house.showResidents();

    system("pause");
    return 0;
}