﻿#include <iostream>                                                                     // Подключение библиотеки потокового ввода-вывода с помощью директивы
#include <time.h>                                                                       // Подключение библиотеки time с помощью директивы (для реализации ГСЧ)
using namespace std;        

int main()
{
    system("chcp 1251>nul");
    int tickets[10];                                                                    // Массив для записи номеров билетов
    srand(time(0));                                                                     // Запись нового сида для генератора псевдо-случайных чисел (для автоматического ввода)
    for (int i = 0; i < 10; i++)                                                        // Цикл для формирования массива номеров каждого билета
    {
        cout << "Введите шестизначный номер " << i + 1 << "-го билета: ";               // Просим ввести пользователя номер билета 
        // cin >> tickets[i];                                                           // Ввод пользователем номера билета (для ручного ввода)
        tickets[i] = (100000 + rand()) % 1000000;                                       // Случайный ввод через ГСЧ (для автоматического ввода)
        cout << tickets[i] << endl;
        while (tickets[i] < 100000 || tickets[i] > 999999)                              // Проверка на число (шестизначное ли оно) (для ручного ввода)
        {
            cout << "Вы ввели неправильный номер билета! Введите новый номер билета: ";
            cin >> tickets[i];                                                          // Ввод нового номера билета
        }
    }
    int ticketCounter = 0;                                                              // Счётчик для подсчёта количетсва счастливых билетов
    for (int i = 0; i < 10; i++)
    {
        // cout << tickets[i] % 10 << " + " << (tickets[i] / 10) % 10 << " + " << (tickets[i] / 100) % 10 << " = " << tickets[i] / 100000 << " + " << (tickets[i] / 10000) % 10 << " + " << (tickets[i] / 1000) % 10 << "?\n";
        if (tickets[i] % 10 + (tickets[i] / 10) % 10 + (tickets[i] / 100) % 10 == tickets[i] / 100000 + (tickets[i] / 10000) % 10 + (tickets[i] / 1000) % 10) // Если сумма первых трёх цифр совпадаеет с суммой последних трёх цифр
        {
            cout << "Ура! Счастливый билет под номером " << i + 1 << "!\n";
            ticketCounter++;                                                            // Считаем счастливый билет
        }
    }
    if (ticketCounter == 0)                                                             // Если счастливые билеты не были найдены, то уведомляем пользователя об этом
    {
        cout << "Увы, среди данных билетов не счастливого!\n";
    }
}