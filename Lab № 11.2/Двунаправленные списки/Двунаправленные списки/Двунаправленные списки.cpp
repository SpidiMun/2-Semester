#include <iostream>
#include <list>
#include <iterator>
using namespace std;

list<int> FormList(list<int> List, int Size)                 // Функция формирования стека
{
	cout << "Введите элементы списка: ";
	int ch;                                                  // Вводимый элемент
	int i;
	for (i = 0; i < Size; i++)
	{
		cin >> ch;
		List.push_back(ch);                                  // Заполнение списка
	}
	return List;
}

list<int> EditList(list<int> List)                           // Функция удаления элементов из списка
{
	cout << "Произвожу удаление чётных элементов...\n";
	int Size = List.size();                                  // Вычисляем размер списка
	int i, j = 0;
	int* Mas = new int[Size];                                // Массив под хранение элементов списка
	for (i = 0; i < Size; i++)
	{
		if (List.front() % 2 == 0)
		{
			List.pop_front();                                // Нашелся чётный элемент, удаляем его
		}
		else
		{
			Mas[j] = List.front();                           // Нашелся нечётный элемент, сначала запоминаем его
			List.pop_front();                                // Затем удаляем его из списка
			j++; 
		}
	}
	for (i = 0; i < j; i++)
	{
		List.push_back(Mas[i]);                              // Заполнение списка из элементов массива
	}
	return List;
}

int main()
{
	system("chcp 1251>nul");
	cout << "Введите количество элементов в двунаправленном списке: ";
	int N;
	cin >> N;
	while (N < 3)
	{
		cout << "Число элементов не может быть меньше трёх. Введите новое число элементов: ";
		cin >> N;
	}
	list<int> List;
	List = FormList(List, N);                                                 // Формируем список
	copy(List.begin(), List.end(), ostream_iterator<int>(cout, " "));         // Вывод списка на консоль
	cout << endl;
	List = EditList(List);                                                    // Удаление элементов из списка
	if (List.size() == 0)
	{
		cout << "Список пуст\n";
	}
	else
	{
		copy(List.begin(), List.end(), ostream_iterator<int>(cout, " "));         // Вывод изменённого списка на консоль
	}
}


// Сделана блок-схема, перенесён код, нужно сделать результаты работы