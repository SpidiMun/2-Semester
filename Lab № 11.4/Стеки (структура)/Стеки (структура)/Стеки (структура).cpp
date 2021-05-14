#include <iostream>
using namespace std;

/*
	Стек - список, но работающий по принципу LIFO (last in - first out)
	Работать можно только с первым элементом в стеке
*/

struct stack                                    // Структура "Стек"
{
	char data;                                  // Информационное поле (хранит элемент стека)
	stack* next;                                // Адресное поле (хранит указатель на следующий элемент стека)
};

stack* FormStack(int Size)                      // Функция записи стека
{
	cout << "Введите элементы стека: ";
	int i;
	stack* p = new stack;                       // Выделение памяти под элемент
	stack* first;                               // Указатель на первый элемент списка
	first = NULL;                               // Элементов нет, поэтоу указатель равен нулю
	cin >> p->data;                             // Ввод первого элемента стека
	p->next = NULL;                             // Введённый элемент - последний в стеке
	first = p;                                  // Введённый элемент - вершина стека
	for (i = 2; i <= Size; i++)
	{
		stack* q = new stack;                   // Выделение памяти под новый элемент 
		cin >> q->data;                         // Ввод нового элемента
		q->next = first;                        // Указатель нового элемента на следующий(т. е. на ранее введённый элемент)
		first = q;                              // Новый элемент - вершина стека
	}
	return first;
}

void PrintStack(stack* first)                   // Функция вывода стека на консоль
{
	if (first != NULL)
	{
		cout << "Вывод стека...\n";
		stack* p = first;                           // Указатель на первый элемент введённого стека
		while (p != NULL)
		{
			cout << p->data << " ";                 // Вывод значения элемента стека
			p = p->next;                            // Переход указателем на следующий элемент
		}
		cout << endl;
	}
	else
	{
		cout << "Стек пуст";
	}
}

bool IsKeyInStack(stack* first, char Key)       // Функция проверки ключа в стека
{
	stack* p = first;                           // Указатель на первый элемент стека			
	while (p != NULL)
	{
		if (p->data == Key)                     // Элемент стека совпал с ключом
		{
			return true;
		}
		else
		{
			p = p->next;                        // Переход на следующий элемент
		}
	}
	return false;
}

int KeyPosition(stack* first, char Key)			// Функция нахождения позиции ключа
{
	int Size = 0;								// Размер нового стека
	stack* p = first;							// Указатель на первый элемент стека
	bool f = false;								// Проверка, нашелся ли ключ с стеке
	while (f == false)
	{
		if (p->data == Key)
		{
			p = p->next;						// Переход на следующий элемент стека
			Size++;
			f = true;
		}
		else
		{
			p = p->next;						// Переход на следующий элемент стека
			Size++;
		}
	}
	return Size;
}

stack* AddElementInStack(stack* first, char Key, char Element)     // Функция добавления элемента в стека
{
	if (IsKeyInStack(first, Key) == true)                          // Проверка на присутствие ключа в стеке
	{
		stack* p = first;                                          // Указатель на первый элемент введённого стека
		stack* r = new stack;                                      // Указатель на дополнительный стек
		stack* top = NULL;
		int Counter = 0, Size;
		Size = KeyPosition(first, Key);
		stack* p1 = p->next;
		p->next = p1;
		r->data = p->data;
		delete p;
		p = p1;
		r->next = NULL;
		top = r;
		while (Counter < Size - 1)
		{
			Counter++;
			stack* q = new stack;						// Выделение памяти под новый элемент
			stack* padd = p->next;
			p->next = padd;
			q->next = r;								// Указатель нового элемента на следующий(т. е. на ранне введённый элемент)
			r = q;										// Переводим указатель на новый элемент
			r->data = p->data;							// Ввод нового элемента
			delete p;
			p = padd;									// Рассматриваем следующий элемент изначального стека
			top = r;									// Новый элемент - вершина стека
		}
		stack* h = new stack;							// Выделение памяти под новый введённый элемент                                    
		h->data = Element;								// Новый элемент
		h->next = p;									// Указатель нового элемента на следующий(т. е. на ранне введённый элемент)
		p = h;											// Переводим указатель на новый элемент
		top = r;										// Новый элемент - вершина стека
		while (r != NULL)
		{
			stack* q = new stack;                       // Выделение памяти под новый введённый элемент
			stack* padd = r->next;
			r->next = padd;
			q->next = p;                                // Указатель нового элемента на следующий(т. е. на ранне введённый элемент)
			p = q;                                      // Переводим указатель на новый элемент
			p->data = r->data;                          // Новый элемент
			delete r;
			r = padd;                                   // Рассматриваем следующий элемент изначального стека
			first = p;
		}
		return first;
	}
	else
	{
		cout << "Такого элемента не найдено. Список остался тем же\n";
		return 0;
	}
}

int main()
{
	system("chcp 1251>nul");
	cout << "Введите количество элементов в стеке: ";
	int N;
	cin >> N;
	while (N < 3)
	{
		cout << "Число элементов не может быть меньше трёх. Введите новое число элементов: ";
		cin >> N;
	}
	stack* first;                                      // Указатель на первый элемент стека
	first = FormStack(N);                              // Получение указателя на первый элемент
	PrintStack(first);                                 // Вывод стека на консоль
	cout << "Какой элемент вы хотите добавить в список?\n";
	char Element;                                      // Добавленный элемент
	cin >> Element;
	cout << "Введите элемент, после которого хотите вставить новый элемент: ";
	char Key;                                          // Элемент, после которого необходимо добавить новый элемент
	cin >> Key;
	first = AddElementInStack(first, Key, Element);    // Добавление элемента в список
	PrintStack(first);                                 // Вывод стека на консоль
}