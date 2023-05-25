// Создайте приложение "Телефонная книга".
// Необходимо хранить данные (ФИО, домашний, рабочий и моб.телефоны, доп.информацию о контакте) 
// внутри соответствующего класса. Наполните класс переменными-членами, функциями-членами, 
// конструкторами, inline-функциями - членами, используйте инициализаторы, реализуйте деструктор.
// Обязательно необходимо выделять динамически память под ФИО. 
// Предоставьте пользователю возможность добавлять новых абонентов, удалять абонентов, 
// искать абонентов по ФИО, показывать всех абонентов, сохранять в файл и загружать из файла.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

class Contact // Создаем класс Контакт
{
private:
    string fullName; // Указатель на динамически выделенную строку для хранения ФИО контакта
    string homePhone; // Номер домашнего телефона
    string workPhone; // Номер рабочего телефона
    string mobilePhone; // Номер мобильного телефона
    string additionalInfo; // Дополнительная информация о контакте

public:
    // Конструктор, принимающий ФИО, номера телефонов и дополнительную информацию
    Contact(string name, string home, string work, string mobile, string info) :
        fullName(string(name)), homePhone(home), workPhone(work),
        mobilePhone(mobile), additionalInfo(info) {}

    // Конструктор копирования, создающий копию контакта other
    Contact(const Contact& other) :
        fullName(string(other.fullName)), homePhone(other.homePhone),
        workPhone(other.workPhone), mobilePhone(other.mobilePhone),
        additionalInfo(other.additionalInfo) {}

    // оператор присваивания
    Contact& operator=(const Contact& other)
    {
        if (this != &other) // Проверка на присваивание объекта самому себе
        {
            // Копирование значений полей
            fullName = other.fullName;
            homePhone = other.homePhone;
            workPhone = other.workPhone;
            mobilePhone = other.mobilePhone;
            additionalInfo = other.additionalInfo;
        }
        return *this;
    }

    // Деструктор освобождает память, выделенную под ФИО контакта
    ~Contact(){};

    // inline функции-члены для доступа к полям

    // Геттеры:
    const string& getName() const { return fullName; } // получаем значение ФИО контакта
    // получаем значения соответствующих номеров телефонов (дом, раб и моб)
    const string& getHomePhone() const { return homePhone; }
    const string& getWorkPhone() const { return workPhone; }
    const string& getMobilePhone() const { return mobilePhone; }
    // получаем доп. информацию о контакте
    const string& getAdditionalInfo() const { return additionalInfo; }

    // Сеттеры:
    // устанавливаем значения полей объекта (от ФИО до доп. информации)
    void setName(const string& name) { fullName = name; }
    void setHomePhone(const string& phone) { homePhone = phone; }
    void setWorkPhone(const string& phone) { workPhone = phone; }
    void setMobilePhone(const string& phone) { mobilePhone = phone; }
    void setAdditionalInfo(const string& info) { additionalInfo = info; }
};

class PhoneBook // Создаем класс Телефонная книга
{
private:
    vector<Contact*> contacts; // список контактов
    string enterName; // добавляем переменную класса для хранения имени контакта
public:
    // добавление нового абонента в книгу
    void addContact()
    {
        string name, home, work, mobile, info;
        cout << "Введите ФИО абонента: ";
        getline(cin, name);
        cout << "Введите дом.телефон абонента: ";
        getline(cin, home);
        cout << "Введите раб.телефон абонента: ";
        getline(cin, work);
        cout << "Введите моб.телефон абонента: ";
        getline(cin, mobile);
        cout << "Введите доп.информацию об абоненте: ";
        getline(cin, info);
        contacts.push_back(new Contact(name, home, work, mobile, info)); // добавляем в конец списка
    }

    void removeContact()
    {
        int number;
        cout << "Введите порядковый номер контакта, который нужно удалить: ";
        cin >> number;
        cin.ignore(); // игнорируем символ переноса строки

        int index = number - 1; // вычисляем соответствующий индекс в векторе

        if (index < 0 || index >= contacts.size()) // проверяем, что индекс находится в допустимых границах
        {
            cout << "Неверный номер контакта!" << endl;
            return;
        }
        delete contacts[index]; // освобождаем память, выделенную под объект по указанному индексу
        contacts.erase(contacts.begin() + index); // удаляем указатель из вектора по указанному индексу
    }

    // получение количества контактов в книге
    int getCount() const
    {
        return contacts.size(); // возвращаем размер вектора (= кол-ву элементов)
    }

    // получение абонента по индексу
    const Contact& getContact(int index) const
    {
        return *contacts[index]; // возвращаем ссылку на объект по указанному индексу
    }

    void enterContactName() // добавляем метод класса для заполнения переменной enterName
    {
        cout << "Введите ФИО абонента, которого нужно найти: ";
        getline(cin, enterName);
    }

    vector<int> searchContacts() const
    {
        // создаём вектор, в который будут добавляться индексы нужных контактов
        vector<int> result;
        for (int i = 0; i < contacts.size(); i++) // проходим циклом по всем контактам
        {
            const Contact& contact = *contacts[i]; // создаём ссылку на объект по текущему индексу
            if (contact.getName() == enterName) // если ФИО контакта равно переданному из поиска
            {
                result.push_back(i); // добавляем индекс текущего контакта в вектор result
            }
        }

        if (result.empty()) // если ничего не найдено
        {
            cout << "Контакт не найден!" << endl;
        }
        else // иначе выводим информацию о найденных контактах
        {
            cout << "\nНайдены следующие контакты:\n\n";
            for (int i : result)
            {
                const Contact& contact = *contacts[i];
                cout << contact.getName() << endl;
                cout << "Домашний телефон: " << contact.getHomePhone() << endl;
                cout << "Рабочий телефон: " << contact.getWorkPhone() << endl;
                cout << "Мобильный телефон: " << contact.getMobilePhone() << endl;
                cout << "Доп. информация: " << contact.getAdditionalInfo() << endl;
                cout << endl;
            }
        }
        return result;
    }

    // функция для показа всех абонентов
    void showAllContacts() const
    {
        if (contacts.empty()) // если контактов в книге нет
        {
            cout << "В телефонной книге отсутствуют контакты!" << endl;
            return;
        }

        for (int i = 0; i < contacts.size(); i++) // бежим по циклу и построчно выводим на экран
        {
            const Contact& contact = *contacts[i];
            cout << "Абонент №" << i + 1 << endl;
            cout << contact.getName() << endl;
            cout << "Домашний телефон: " << contact.getHomePhone() << endl;
            cout << "Рабочий телефон: " << contact.getWorkPhone() << endl;
            cout << "Мобильный телефон: " << contact.getMobilePhone() << endl;
            cout << "Доп. информация: " << contact.getAdditionalInfo() << endl;
            cout << endl;
        }
    }

    // функция для сохранения контактов в файл
    void saveContacts(const PhoneBook& book, const string& filename)
    {
        ofstream out(filename);//, ios::app);;
        if (!out) // если файл не открылся
        {
            cout << "Не удалось открыть файл " << filename << " для записи!" << endl;
            return;
        }

        //проходим по всем контактам, получаем их данные и записываем в файл (построчно)
        for (int i = 0; i < book.getCount(); i++)
        {
            const Contact& contact = book.getContact(i);
            out << contact.getName() << '\n';
            out << contact.getHomePhone() << '\n';
            out << contact.getWorkPhone() << '\n';
            out << contact.getMobilePhone() << '\n';
            out << contact.getAdditionalInfo() << '\n';
            out << '\n'; // записываем пустую строку между контактами
        }
        out.close();
        cout << "Контакты сохранены в файл Контакты.txt";
    }

    void loadContacts(const string& filename)
    {
        ifstream in(filename);
        if (!in) // если файл не открылся
        {
            cout << "Не удалось открыть файл " << filename << " для чтения!" << endl;
            return;
        }

        // создаем временный вектор для контактов, чтобы не модифицировать
        // основной вектор до тех пор, пока не будут загружены все контакты
        vector<Contact*> tempContacts;

        // считываем данные из файла построчно, создаем объект Контакт
        string name, home, work, mobile, info;

        // После чтения первой строки (имени) проверяется, является ли она пустой
        // Если да, то оператор continue пропускает текущую итерацию цикла, 
        // и чтение продолжается со следующей строки
        while (getline(in, name))
        {
            if (name.empty()) // если строка пустая, пропускаем ее (добавили, чтобы избежать ошибки чтения)
            {
                continue;
            }

            getline(in, home);
            getline(in, work);
            getline(in, mobile);
            getline(in, info);

            // создаем временный объект контакта
            Contact* tempContact = new Contact(name, home, work, mobile, info);
            tempContacts.push_back(tempContact); // добавляем его во временный вектор
        }

        if (tempContacts.empty()) // если файл пустой, то закрываем файл и выходим из функции
        {
            in.close();
            return;
        }

        // освобождаем память, выделенную под старые контакты в основном векторе
        for (auto& contact : contacts)
        {
            delete contact;
        }

        // заменяем старый вектор новым, загруженным из файла
        contacts = tempContacts;
        in.close();
        cout << "Контакты загружены из файла Контакты.txt";
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    PhoneBook book; // создали объект book класса PhoneBook для вызова функций
    int choice;
    cout << "ТЕЛЕФОННЫЙ СПРАВОЧНИК СЕЛА МИНДЮКИНО:" << endl;
    do
    {
        cout << endl << "1 - Добавить абонента" << endl;
        cout << "2 - Удалить абонента" << endl;
        cout << "3 - Найти абонента по ФИО" << endl;
        cout << "4 - Показать всех абонентов" << endl;
        cout << "5 - Сохранить информацию в файл" << endl;
        cout << "6 - Загрузить информацию из файла" << endl;
        cout << "0 - Выход из программы" << endl << endl;
        cout << "Выберите нужный вариант: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            system("cls");
            book.addContact();
            break;
        case 2:
            system("cls");
            book.showAllContacts();
            book.removeContact();
            break;
        case 3:
            system("cls");
            book.enterContactName();
            book.searchContacts();
            break;
        case 4:
            system("cls");
            book.showAllContacts();
            break;
        case 5:
            system("cls");
            book.saveContacts(book, "Контакты.txt");
            break;
        case 6:
            system("cls");
            book.loadContacts("Контакты.txt");
            break;
        case 0:
            cout << "\nДо встречи в справочнике!" << endl;
            exit(0);
            break;
        default:
            cout << "Вы ввели неверное число! Попробуйте еще раз!" << endl;
            break;
        }
        cout << endl;
    } while (choice != 0);

    system("pause");
    return 0;
}