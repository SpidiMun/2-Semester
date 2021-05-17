#include <iostream>
#include <string>
using namespace std;

struct VideoCard
{
	string Model;
	int Year;
	int Graph_Memory;
};

VideoCard* Create_Struct(VideoCard* str, int right)															// Функция создания структуры
{
	cout << "Введите элементы множества:\n\n";
	int i;
	for (i = 0; i < right; i++)																				// Каждая итерация отвечает за элемент структуры
	{
		cout << i + 1 << " элемент\n";
		cout << "Модель: ";
		cin.ignore();
		getline(cin, str[i].Model);																			// Заполнения поля "Название модели"
		cout << "Год: ";
		cin >> str[i].Year;																					// Заполнения поля "Год производства"
		cout << "Объем видеопамяти: ";
		cin >> str[i].Graph_Memory;																			// Заполнения поля "Объем видеопамяти"
	}
	cout << endl << endl;
	return str;																								// Возвращение полученной структуры
}

void Print_Struct(VideoCard* str, int right)																// Функция вывода структуры	
{
	cout << "Вывожу множество...\n\n";
	int i;
	for (i = 0; i < right; i++)																				// Вывод полей каждого элемента множества
	{
		cout << i + 1 << " элемент\n";
		cout << "Модель: " << str[i].Model << endl;
		cout << "Год: " << str[i].Year << endl;
		cout << "Объем видеопамяти: " << str[i].Graph_Memory << endl << endl;
	}
}

void Shell_Sort(VideoCard* str, int right)																	// Функция быстрой сортировки Шелла
{
	cout << "========== БЫСТРАЯ СОРТИРОВКА ШЕЛЛА ==========\n\n";
	int i, j;
	VideoCard element;																						// Дополнительный элемент (для первого элемента в неотсортированной части множества)
	int shift = right / 2;																					// Сдвиг на элементы серии
	while (shift > 0)																						// Пока сдвиг существует (!= 0)
	{
		i = 0;																								// Начинаем с первого элемента
		while (i < shift)																					// Проход по всем сериям
		{
			int k = i;																						// Индекс элемента серии
			while (k < right - shift)																		// Проход по элементам серии (сортировка методом вставки)
			{
				j = k;																						// Последний элемент отсортированной части серии множества
				element = str[j + shift];																	// Первый элемент неотсортированной части серии множества
				while (j >= i % shift)																		// Пока не дошли до последнего элемента остортированной части серии множества
				{
					if (str[j + shift].Graph_Memory > str[j].Graph_Memory)									// Если элемент больше предыдущего, производим замену
					{
						str[j + shift] = str[j];															
						str[j] = element;
					}
					j -= shift;																				// Переход на предыдущий элемент серии
				}
				k += shift;																					// Переход на следующий элемент серии
			}
			i += 1;																							// Переход на следующую серию
		}
		shift /= 2;																							// Делим сдвиг на 2 (сортируем больше серий)
	}
	Print_Struct(str, right);																				// Вывод отсортированного множества
	cout << "==============================================\n\n";
}

void Quick_Sort(VideoCard* str, int left, int right)														// Функция быстрой сортировки
{
	int pleft = left, pright = right;																		// Левый индекс элемента множества, правый индекс элемента множества
	int pivot = str[(left + right + 1) / 2].Year;															// Опорный элемент
	do 
	{
		while (str[pleft].Year < pivot)																		// Пока находим левый элемент от опорного
		{
			pleft++;																						// Переходим на следующий
		}
		while (str[pright].Year > pivot)																	// пока находим правый элемент от опорного
		{
			pright--;																						// Переходим на предыдущий
		}
		if (pleft <= pright)																				// Если левый индекс меньше или равен правому (т. е. слева стоит большее число, чем справа)
		{																									// Поизводим замену
			VideoCard mid = str[pleft];																		
			str[pleft] = str[pright];
			str[pright] = mid;
			pleft++;
			pright--;
		}
	} while (pleft <= pright);																				
	if (left < pright)																																						
	{
		Quick_Sort(str, left, pright);																		// Проводим сортировку в левом подмножестве
	}
	if (pleft < right)																						
	{ 
		Quick_Sort(str, pleft, right);																		// Проводим сортировку в правом подмножестве
	}
}

void Hoar_Sort(VideoCard* str, int Size)																	// Функция быстрой сортировки Хоара
{
	cout << "========== БЫСТРАЯ СОРТИРОВКА ХОАРА ==========\n\n";
	Quick_Sort(str, 0, Size - 1);																			// Вызов функции быстрой сортировки
	Print_Struct(str, Size);																				// Вывод отсортированного множества
	cout << "==============================================\n\n";
}

int main()
{
	system("chcp 1251>nul");
	cout << "Введите количество элементов в множестве: ";
	int N;																									// Размерность множества
	cin >> N;
	while (N < 2)
	{
		cout << "Число элементов в множестве не может быть меньше трёх. Введите новое число элементов: ";
		cin >> N;
	}
	VideoCard* Struct1 = new VideoCard[N];																	// Структура № 1
	VideoCard* Struct2 = new VideoCard[N];																	// Структура № 2
	Struct1 = Create_Struct(Struct1, N);																	// Создание структуры № 1
	Struct2 = Struct1;																						// Копирование структуры № 1 в структуру № 2
	Shell_Sort(Struct1, N);																					// Вызов функции быстрой сортировки Шелла
	Hoar_Sort(Struct2, N);																					// Вызов функции быстрой сортировки Хоара
}