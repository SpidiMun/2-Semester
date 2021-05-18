#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	system("chcp 1251>nul");
	int size;
	cout << "Введите количество элементов в стеке: ";
	cin >> size;
	while (size < 3)											// Проверка числа на натуральность (натуральное ли оно)
	{
		cout << "Число элементов не может быть меньше трёх. Введите новое число элементов: ";
		cin >> size;
	}
	Stack<char> stack;
	stack = FormStack(stack, size);
	stack.Show();
	cout << "После какого элемента вы хотите добавить новый элемент?\n";
	char Key;
	cin >> Key;
	if (stack.isKeyinStack(Key))								// Проверка наличия элемента в стеке
	{
		stack = EditStack(stack, Key);							// Нашёлся, изменяем стек
		stack.Show();
	}
	else
	{	
		cout << "Такого элемента в стеке нет";					// Не нашёлся, сообщаем об этом пользователю
	}
}