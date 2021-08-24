#include <iostream>                                                                 // Подключение библиотеки потокового ввода-вывода через директиву
using namespace std;                                                                // Подлючение пространства имён std через ключевые слова

int main()
{
    system("chcp 1251>nul");
    int n, An, An1, An0;
    int progression[30];
    cout << "Введите порядковый номер одного из элементов последовательности n: ";
    cin >> n;
    while (n < 1 || n > 29)
    {
        cout << "Неверно введено число! Введите новый порядковый номер: ";
        cin >> n;
    }
    cout << "Введите элементы последовательности An и An-1: ";
    cin >> An >> An1;
    progression[n - 1] = An;
    progression[n] = An1;
    int size = n + 1;
    while (n > 1)
    {
        An0 = An1 - An;
        An1 = An;
        An = An0;
        n--;
        progression[n - 1] = An;
    }
    cout << "Первые два члена последовательности равны " << An << ", " << An1 << " соответственно.\n";
    cout << "Все элементы последовательности до An+1: ";
    for (int i = 0; i < size; i++)
    {
        cout << progression[i] << "  ";
    }
    cout << endl;
}