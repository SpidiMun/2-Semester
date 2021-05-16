#ifndef TRAVELLERSALESMAN_H
#define TRAVELLERSALESMAN_H

#include <QString>

class TravellerSalesMan
{
public:
    TravellerSalesMan();
    ~TravellerSalesMan();

    QString GetResult(QString root);
    QString WayLength(QString root);

private:
    int getNumber(int I, int J);
    void RemoveNode(int I, int J);
    void GetWay(int Node);
    void SetSize_Matrix();

private:
    int Mainlen;        // Количество узлов
    int di;             // Вспомогательный столбец или строка
    int** MainMatrix;   // Основная матрица (с ней происходит вся работа)
    int** Mtemp;        // Доп матрица (для хранения исходной матрицы с длинами дорог)
    int** roads;        // Хранит варианты дорог (0-й индекс - начальная вершина, 1-й индекс - конечная)
    int Result = 0;
    int start;          // Стартовая вершина
    QString way;        // Маршрут
    int counter;        // Для входа в условие
};

#endif // TRAVELLERSALESMAN_H
