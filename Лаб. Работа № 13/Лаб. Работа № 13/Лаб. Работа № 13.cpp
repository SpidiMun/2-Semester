#include <iostream>
using namespace std;
int Board[8][8];

void Set_Queen(int I, int J)
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		Board[i][J] += 1;
	}
	for (j = 0; j < 8; j++)
	{
		Board[I][j] += 1;
	}
	if (I >= J)
	{
		i = I - J;
		j = 0;
	}
	else
	{
		i = 0;
		j = J - I;
	}
	while (i < 8 && j < 8)
	{
		Board[i][j] += 1;
		i++;
		j++;
	}
	if (7 - I >= J)
	{
		i = I + J;
		j = 0;
	}
	else
	{
		i = 7;
		j = J - (7 - I);
	}
	while (i > -1 && j < 8)
	{
		Board[i][j] += 1;
		i--;
		j++;
	}
	Board[I][J] = -1;
}

void Reset_Queen(int I, int J)
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		Board[i][J] -= 1;
	}
	for (j = 0; j < 8; j++)
	{
		Board[I][j] -= 1;
	}
	if (I >= J)
	{
		i = I - J;
		j = 0;
	}
	else
	{
		i = 0;
		j = J - I;
	}
	while (i < 8 && j < 8)
	{
		Board[i][j] -= 1;
		i++;
		j++;
	}
	if (7 - I >= J)
	{
		i = I + J;
		j = 0;
	}
	else
	{
		i = 7;
		j = J - (7 - I);
	}
	while (i > -1 && j < 8)
	{
		Board[i][j] -= 1;
		i--;
		j++;
	}
	Board[I][J] = 0;
}

bool Queen_Layout(int i)																					// Получаем номер строки 
{
	bool Find = false;																						// Начальное значение 
	for (int j = 0; j < 8; ++j)																				// Итерирование по клеткам строки
	{
		if (Board[i][j] == 0)																				// Поиск клетки, находящейся не под атакой ферзей
		{
			Set_Queen(i, j);																				// Вызов функции постановки ферзя И обозначения клеток, которые он бьет
			if (i == 7)																						// Достижение последней строки шахматной доски (от 0 до 7)
			{
				Find = true;																				// Изменение значения Find для досрочного выхода из цикла на посл. строке доски после постановки ферзя (63 стр. кода)
			}
			else
			{
				if (!(Find = Queen_Layout(i + 1)))
				{
					Reset_Queen(i, j);																		// Для отката (удаления ферзя на предыд. строке; еще для перехода на строку выше
				}
			}
		}
		if (Find)
		{
			break;																							// Досрочный выход из цикла после постановки ферзя на последней строке доски
		}
	}
	return Find;																							// Возвращение значения функции
}

int main()
{
	for (int i = 0; i < 8; ++i)																				// Сначала обнуляем в 
	{
		for (int j = 0; j < 8; ++j)
		{
			Board[i][j] = 0;
		}
	}
	Queen_Layout(0);																						// Запускаем цикл
	for (int i = 0; i < 8; ++i)																				// Выводим все содержимое
	{
		for (int j = 0; j < 8; ++j)
		{
			if (Board[i][j] == -1)
			{
				cout << " + ";																			// Так выводится ферзь
			}
			else
			{
				cout << " . ";																			// А так пустые клетки 
			}
		}
		cout << endl;
	}
}
