#include <iostream>
#include <string>
using namespace std;

string RecordInMassive(string* Arr, int Size)							// Функция записи массива
{
	int i;
	cout << "Запись массива..." << endl << endl;
	cin.ignore();
	for (i = 0; i < Size; i++)
	{
		cout << "Введите " << i + 1 << " строку:" << endl;
		getline(cin, Arr[i]);
		cout << endl;
	}
	return *Arr;
}

void PrintMassive(string* Arr, string* New_Arr, int Size)				// Функция вывода массива на консоль
{
	if (New_Arr[0] == "")
	{
		int i;
		cout << "Вывод массива..." << endl;
		for (i = 0; i < Size; i++)
		{
			cout << Arr[i] << endl;
		}
	}
	else
	{
		int i;
		cout << "Вывод изменённого массива..." << endl;
		for (i = 0; i < Size; i++)
		{
			cout << Arr[i] << endl;
		}
	}
}

string EditMassive(string* Arr, string* New_Arr, int Size, int Key)		// Функция удаления элемента массива
{
	int i, j = 0;
	cout << "Произвожу удаление строки под номером " << Key << "...\n";
	Key--;
	for (i = 0; i < Size; i++)
	{
		if (i != Key)
		{
			New_Arr[i] = Arr[j];
			j++;
		}
		else 
		{
			j++;
			New_Arr[i] = Arr[j];
			j++;
		}
	}
	return *New_Arr;
}

void DeleteMassive(string* Arr_1, string* Arr_2)						// Функция удаления массивов
{
	cout << "Произвожу удаление массивов...\n";
	delete[] Arr_1;
	delete[] Arr_2;
}

int main()
{
	system("chcp 1251>nul");
	cout << "Введите количество строк в массиве: ";
	int N;
	cin >> N;
	while (N <= 1)
	{
		cout << "Число строк в массиве не может быть меньше единицы. Введите новое число строк: ";
		cin >> N;
	}
	string* Rows = new string[N];
	string* Result = new string[N - 1];
	cout << "Запишите строки в массив:" << endl;
	RecordInMassive(Rows, N);
	PrintMassive(Rows, Result, N);
	int delete_number;
	cout << "Теперь введите номер строки, которую хотите удалить: №";
	cin >> delete_number;
	while (delete_number <= 0 || delete_number > N)
	{
		cout << "Номер строки в массиве не может быть меньше или равно нулю. Введите новый номер строки: ";
		cin >> delete_number;
	}
	N--;
	EditMassive(Rows, Result, N, delete_number);
	PrintMassive(Result, Result, N);
	DeleteMassive(Rows, Result);
}