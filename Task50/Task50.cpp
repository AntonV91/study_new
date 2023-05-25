// ������ 1.
// �������� ���������, ����������� ��������������� ���.
// ���������� ����� ������ ��������, ���������, ����
// ����� ��������� �������� ������������ ������ �������� ������ ��������.
// ����� ���� �������� ������ �������� ������ ���������.
// ������ �� ������� �������� ����������-����� � �������-�����, ����������� ��� ���������� �������.
// ������ ��� ��������� �������� ���������� �����������. ��������, ��� ��� � ������ ��������. 
// ��������� ������ ���������� �������������� (����������� ����������� ����������), �������������.
// � main �������������� ������ ����������� ������ �������.

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class Person
{
private:
    string name; // ��� ��������
    int age; // ������� ��������
public:
    Person() : name(""), age(0) {} // ����������� �� ���������, ���������������� ���� ���������� �� ���������
    Person(const string& n, int a) : name(n), age(a) {} // �����������, ����������� ��� � ������� ��������
    Person(const Person& other) : name(other.name), age(other.age) {} // ����������� �����������, ���������� ��� � ������� �������� �� ������� �������
    ~Person() {} // ���������� �� ���������
    string getName() const { return name; } // �����, ������������ ��� ��������
    int getAge() const { return age; } // �����, ������������ ������� ��������
};

class Apartment
{
private:
    int number; // ����� ��������
    vector<Person> residents; // ������ �������� Person, �������������� ������� ��������
public:
    Apartment() : number(0) {} // ����������� �� ���������, ������� ������������� ����� �������� ������ 0
    Apartment(int num, const vector<Person>& r) : number(num), residents(r) {} // �����������, ����������� � �������� ���������� ����� �������� � ������ �������
    Apartment(const Apartment& other) : number(other.number), residents(other.residents) {} // ����������� �����������, ������� ������� ����� ������ �������� � ��� �� ������� �������� � ��������, ��� � �������� ������
    ~Apartment() {} // ���������� �� ���������

    int getNumber() const { return number; } // ������ ��� ��������� ������ ��������
    vector<Person> getResidents() const { return residents; } // ������ ��� ��������� ����� ������� �������

    // ������� addResident � removeResident � ��������� ������ �������� ���������� ����� 
    // (��������� � �����������: �� ����� �������� � �.�.), ����� ��������� � ����������
    // ���� ����� ��� ������������, �.�. ��� ������� �� ��������� ������������� ��������
    void addResident(const Person& resident) // ��������� ������
    {
        residents.push_back(resident);
    }

    void removeResident(int index) // ������� ������
    {
        residents.erase(residents.begin() + index);
    }
};

class House
{
private:
    static const int NUM_APARTMENTS = 4; // ����������� int, ��������������� ���������� ������� � ����
    vector<Apartment> apartments; // ������ �������� Apartment, �������������� �������� � ����
public:
    House() {} // ����������� �� ���������, �� ������ ������, ��� ��� ������ ��� ��������������� ������
    House(const vector<Apartment>& apts) : apartments(apts) {} // �����������, ����������� ������ ������� � ���������������� ��� ������ apartments
    House(const House& other) : apartments(other.apartments) {} // ����������� �����������, ��������� ����� ������ House � ��� �� �������� �������, ��� � �������� ������
    ~House() {} // ���������� �� ���������
    static int getNumApartments() { return NUM_APARTMENTS; } // ����� ��� ��������� ���������� ������� � ����
    vector<Apartment> getApartments() const { return apartments; } // ������ ��� ��������� ����� ������� �������  

    // �������� ��� �� ��, ��� ���-�� ������� �� ��������� NUM_APARTMENTS (+ ����������)
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

    void showResidents() const // ���������� ������� �����������
    {
        for (const auto& apt : apartments)
        {
            cout << "�������� �" << apt.getNumber() << ":\n";
            for (const auto& resident : apt.getResidents())
            {
                cout << " - " << resident.getName() << ", " << resident.getAge() << " ���\n";
            }
            cout << endl;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ���� ������ ����� "�������" � "�������� ������" � main, ����� �������� ��� ���� � ���������� 
    House house;
    house.addApartment(Apartment(1, { Person("����� ������", 30), Person("����� �����", 31) }));
    house.addApartment(Apartment(2, { Person("����� ��������", 50), Person("���� ��������", 44) }));
    house.addApartment(Apartment(3, { Person("���������� ����������", 78) }));
    house.addApartment(Apartment(4, { Person("��� ���� ��", 19), Person("�� ��� ��", 20), Person("����� ���-������", 18) }));
    house.showResidents();

    // ����� ������� ��� ���������� � �������� ������ (���� �� ��������, ��� ������ �� ��������)
    // ��������� � �������� �� ����� ��������� �� ������� ����� ��������
    cout << "����������� ������ (���� �� �����������):" << endl << endl;
    house.getApartments()[1].addResident(Person("�������� ������", 1)); // ��������� � ��.
    house.getApartments()[3].removeResident(1); // ������� �� ��. �� �������
    house.showResidents();

    system("pause");
    return 0;
}