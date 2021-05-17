#include <iostream>
#include <string>
using namespace std;

struct Hash                                                                     // Структура Hash
{
    string FullName;                                                            // Поле данных "ФИО"
    string Birthday;                                                            // Поле данных "Дата рождения"
    string PhoneNumber;                                                         // Поле данных "Номер телефона"
    string Passport;                                                            // Поле данных "Номер паспорта"
};

int Remain_Divide(string Key, int HashTableSize)                                // Хеш-функция, остаток от деления
{
    int Digit_Key = 0;                                                          // Числовое значение ключа
    unsigned int i = 0;                                                         // Индекс символа строки
    while (i < Key.length())                                                    // Пока не пройдена вся длина строки
    {
        Digit_Key += unsigned int(Key[i]);                                      // Увеличиваем ключ на код ASCII символа
        i++;                                                                    // Индекс следующего сивмола строки
    }
    return Digit_Key % HashTableSize;                                           // Возвращение значения ключа
}

Hash* Create_HashTable(Hash* str, Hash* hash, int Size)                         // Функция заполнения хеш-таблицы
{
    string Key;
    int Address;
    for (int i = 0; i < Size; i++)
    {
        Key = str[i].PhoneNumber;
        Address = Remain_Divide(Key, Size);
        while (hash[Address].FullName != "-")
        {
            Address++;
        }
        if (Address >= Size)
        {
            int k = Size * 2;
            Hash* Newhash = new Hash[k];
            for (int j = 0; j < k / 2; i++)
            {
                Newhash[i].FullName = hash[i].FullName;
                Newhash[i].Birthday = hash[i].Birthday;
                Newhash[i].PhoneNumber = hash[i].PhoneNumber;
                Newhash[i].Passport = hash[i].Passport;
            }
            delete hash;
            hash = Newhash;
        }
        hash[Address].FullName = str[i].FullName;
        hash[Address].Birthday = str[i].Birthday;
        hash[Address].PhoneNumber = str[i].PhoneNumber;
        hash[Address].Passport = str[i].Passport;
    }
    return hash;
}

Hash* Create_Table(Hash* str, int Size)
{
    for (int i = 0; i < Size; i++)
    {
        cout << "ФИО: ";
        cin.ignore();
        getline(cin, str[i].FullName);
        cout << "Дата рождения: ";
        cin >> str[i].Birthday;
        cout << "Номер телефона: ";
        cin >> str[i].PhoneNumber;
        cout << "Номер паспорта: ";
        cin >> str[i].Passport;
    }
    return str;
}

void Print_HashTable(Hash* str, int Size)
{
    for (int i = 0; i < Size; i++)
    {
        cout << str[i].FullName << endl;
        cout << str[i].Birthday << endl;
        cout << str[i].PhoneNumber << endl;
        cout << str[i].Passport << endl;
    }
}

int main()
{
    system("chcp 1251>nul");
    int N;
    cout << "Введите количество элементов в таблице: ";
    cin >> N;
    while (N < 3)
    {
        cout << "Число элементов в таблице не может быть меньше трёх. Введите новое число элементов в таблице: ";
        cin >> N;
    }
    Hash* Table = new Hash[N];                                                  // Создание таблицы данных
    Hash* HashTable = new Hash[N];                                              // Создание хеш-таблицы
    for (int i = 0; i < N; i++)                                                 // Заполнение "пустотой" всех элементов хеш-таблицы 
    {
        HashTable[i].FullName = '-';
        HashTable[i].Birthday = '-';
        HashTable[i].PhoneNumber = '-';
        HashTable[i].Passport = '-';
    }
    Table = Create_Table(Table, N);                                             // Заполнение таблицы данных
    HashTable = Create_HashTable(Table, HashTable, N);                          // Заполнение хеш-таблицы данными с ранне заполненной таблицы
    Print_HashTable(HashTable, N);                                              
}
