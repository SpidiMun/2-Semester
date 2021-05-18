#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Stack
{
	struct Node												// ���� �����
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
		throw length_error("���� ����!\n");
	}
	return top->data;
}

template <class T>
void Stack<T>::Pop()
{
	if (isEmpty())
	{
		throw length_error("���� ����!\n");
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
		cout << "���� ����!\n";
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
		throw length_error("���� ����!\n");
	}
	Node* p = top;											// ��������� �� ������ ������� �����			
	while (p != NULL)
	{
		if (p->data == key)									// ������� ����� ������ � ������
		{
			return true;
		}
		else
		{
			p = p->follow;									// ������� �� ��������� �������
		}
	}
	return false;
}

template <class T>
Stack<T> FormStack(Stack<T> stack, int size)
{
	cout << "������� �������� ����� (��� �������� ���� char)\n";
	int i;
	T elem;													// ������ �������� ���������
	for (i = 0; i < size; i++)
	{
		cout << "������� � " << i + 1 << " : ";
		cin >> elem;										// ���� �������� �����
		stack.Push(elem);									// ��������� �������� � ����
	}
	return stack;
}

template <class T>
Stack<T> EditStack(Stack<T> stack, T key)
{
	T Element;												// �������, ������� ����� ��������
	cout << "������� �������, ������� ������ ��������: ";
	cin >> Element;
	cout << "��������� ���������� �������� � ����...\n";
	int Size = stack.Size();								// ��������� ������ ����� 
	int i, j = 0;
	Size++;
	T* Mas = new T[Size];									// ������ ��� ���������� ������� ����� (+ ���������� �����)
	for (i = 0; i < Size - 1; i++)							// ����� �������� ��������� ��� �����
	{
		if (stack.Top() != key)								// ���� ������� ����� �� �������� ������
		{
			Mas[j] = stack.Top();							// ������� � ������
			stack.Pop();									// ������� ������� �� �����
			j++;											// ������� �� ����� ������� (��� ��������� ���������� ����� ����� ����������� � �������� ������� �����)
		}
		else
		{
			Mas[j] = stack.Top();							// ������� � ������
			stack.Pop();									// ������� ������� �� �����
			j++;
			Mas[j] = Element;
			j++;
		}
	}
	for (i = j - 1; i >= 0; i--)							// ��������� ���������� ��������� � �����
	{
		stack.Push(Mas[i]);									// ��������� �������� �� ������� � ����
	}
	return stack;
}