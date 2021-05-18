#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Stack
{
	struct Node												// Узел стека
	{
		T data;
		Node* follow;
	};
	Node* top;
	int size;
public:
	Stack(); 
	void Push(const T& elem);
	bool isEmpty();
	const T& Top();
	void Pop();
	void Show();
	int Size();
	bool isKeyinStack(T key);
	template <class T> friend Stack<T> FormStack(Stack<T> stack, int size);
	template <class T> friend Stack<T> EditStack(Stack<T> stack, T key);
};


template <class T>
Stack<T>::Stack()
{
	top = nullptr;
	size = 0;
}

template <class T>
void Stack<T>::Push(const T& elem)
{
	Node* newnode = new Node;
	newnode->data = elem;
	newnode->follow = top;
	top = newnode;
	size++;
}

template <class T>
bool Stack<T>::isEmpty()
{
	return (top == nullptr);
}

template <class T>
const T& Stack<T>::Top()
{
	if (isEmpty())
	{
		throw length_error("Стек пуст!\n");
	}
	return top->data;
}

template <class T>
void Stack<T>::Pop()
{
	if (isEmpty())
	{
		throw length_error("Стек пуст!\n");
	}
	Node* delnode = top;
	T elem = delnode->data;
	top = delnode->follow;
	delete delnode;
	size--;
}

template <class T>
void Stack<T>::Show()
{
	if (isEmpty())
	{
		cout << "Стек пуст!\n";
	}
	Node* p = top;
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->follow;
	}
	cout << endl;
}

template <class T>
int Stack<T>::Size()
{
	return size;
}

template <class T>
bool Stack<T>::isKeyinStack(T key)
{
	if (isEmpty())
	{
		throw length_error("Стек пуст!\n");
	}
	Node* p = top;											// Указатель на первый элемент стека			
	while (p != NULL)
	{
		if (p->data == key)									// Элемент стека совпал с ключом
		{
			return true;
		}
		else
		{
			p = p->follow;									// Переход на следующий элемент
		}
	}
	return false;
}

template <class T>
Stack<T> FormStack(Stack<T> stack, int size)
{
	cout << "Введите элементы стека (все элементы типа char)\n";
	int i;
	T elem;													// Массив вводимых элементов
	for (i = 0; i < size; i++)
	{
		cout << "Элемент № " << i + 1 << " : ";
		cin >> elem;										// Ввод элемента стека
		stack.Push(elem);									// Занесение элемента в стек
	}
	return stack;
}

template <class T>
Stack<T> EditStack(Stack<T> stack, T key)
{
	T Element;												// Элемент, который хотим добавить
	cout << "Введите элемент, который хотите добавить: ";
	cin >> Element;
	cout << "Произвожу добавление элемента в стек...\n";
	int Size = stack.Size();								// Сохраняем размер стека 
	int i, j = 0;
	Size++;
	T* Mas = new T[Size];									// Массив для сохранения порядка стека (+ сохранение стека)
	for (i = 0; i < Size - 1; i++)							// Отбор нечётных элементов для стека
	{
		if (stack.Top() != key)								// Если элемент стека не является ключом
		{
			Mas[j] = stack.Top();							// Заносим в массив
			stack.Pop();									// Удаляем элемент из стека
			j++;											// Переход на новый элемент (при повторном заполнении стека будет использован в качестве размера стека)
		}
		else
		{
			Mas[j] = stack.Top();							// Заносим в массив
			stack.Pop();									// Удаляем элемент из стека
			j++;
			Mas[j] = Element;
			j++;
		}
	}
	for (i = j - 1; i >= 0; i--)							// Повторное заполнение элементов в стека
	{
		stack.Push(Mas[i]);									// Занесение элемента из массива в стек
	}
	return stack;
}