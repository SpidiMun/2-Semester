#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
	Стек - список, но работающий по принципу LIFO (last in - first out)
	Работать можно только с первым элементом в стеке
*/

stack<char> FormStack(stack<char> Stack, int Size)         // Функция формирования стека
{
	cout << "Введите элементы стека: ";
	int i;
	char* Number = new char[Size];                         // Массив вводимых элементов
	for (i = 0; i < Size; i++)
	{
		cin >> Number[i];                                  // Ввод элемента стека в массив	
	}
	for (i = Size - 1; i >= 0; i--)
	{
		Stack.push(Number[i]);                             // Занесение элемента из массива в очередь
	}
	return Stack;
}

void PrintStack(stack<char> Stack)       // Функция вывода стека в консоль
{
	cout << "Вывожу стек...\n";
	int Size = Stack.size();             // Сохраняем размер стека
	int i;
	for (i = 0; i < Size; i++)           // Непосредственный вывод элементов стека
	{
		cout << Stack.top() << " ";      // Выводим первый элемент стека
		Stack.pop();                     // Удаляем элемент из стека
	}
	cout << endl;
}

bool IsKeyInStack(stack<char> Stack, char Key)				// Функция проверки элемента в стеке
{
	int Size = Stack.size();								// Сохраняем размер стека
	char* Mas = new char[Size];								// Массив для сохранения порядка стека (+ сохранение стека)
	int i = 0;
	while (i < Size)
	{
		if (Stack.top() != Key)								// Если элемент стека не равен ключу, то запоминаем стек
		{
			Mas[i] = Stack.top();
			Stack.pop();
			i++;
		}
		else												// В противном случае, возращаем значение функции true
		{
			return true;
		}
	}
	return false;											// Выход из цикла, следовательно, ключ в стеке не нашёлся. Возрващаем значение функции false
}

stack<char> EditStack(stack<char> Stack, char Key)			// Функция добавления элемента в стек
{
	char Element;											// Элемент, который хотим добавить
	cout << "Введите элемент, который хотите добавить: ";
	cin >> Element;
	cout << "Произвожу добавление элемента в стек...\n";
	int Size = Stack.size();								// Сохраняем размер стека 
	int i, j = 0;
	Size++;
	char* Mas = new char[Size];								// Массив для сохранения порядка стека (+ сохранение стека)
	for (i = 0; i < Size - 1; i++)							// Отбор нечётных элементов для стека
	{
		if (Stack.top() != Key)								// Если элемент стека не является ключом
		{
			Mas[j] = Stack.top();							// Заносим в массив
			Stack.pop();									// Удаляем элемент из стека
			j++;											// Переход на новый элемент (при повторном заполнении стека будет использован в качестве размера стека)
		}
		else
		{
			Mas[j] = Stack.top();							// Заносим в массив
			Stack.pop();									// Удаляем элемент из стека
			j++;
			Mas[j] = Element;
			j++;
		}
	}
	for (i = j - 1; i >= 0; i--)							// Повторное заполнение элементов в стека
	{
		Stack.push(Mas[i]);									// Занесение элемента из массива в стек
	}
	return Stack;
}

int main()
{
	system("chcp 1251>nul");
	int N;
	cout << "Введите количество элементов в стеке: ";
	cin >> N;
	while (N < 3)											// Проверка числа на натуральность (натуральное ли оно)
	{
		cout << "Число элементов не может быть меньше трёх. Введите новое число элементов: ";
		cin >> N;
	}
	stack<char> Stack;
	Stack = FormStack(Stack, N);
	PrintStack(Stack);
	cout << "После какого элемента вы хотите добавить новый элемент?\n";
	char Key;
	cin >> Key;
	if (IsKeyInStack(Stack, Key) == true)					// Проверка наличия элемента в стеке
	{
		Stack = EditStack(Stack, Key);						// Нашёлся, изменяем стек
		PrintStack(Stack);
	}
	else
	{
		cout << "Такого элемента в стеке нет";				// Не нашёлся, сообщаем об этом пользователю
	}
}
