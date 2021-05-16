#include "travellersalesman.h"

#include <QString>
#include <QFile>
#include <QTextStream>

QFile mainSize("C:/QtRepos/TravellerSalesMan/MatrixSize.txt");
QTextStream MainstreamSize(&mainSize);
QFile mainMatrix("C:/QtRepos/TravellerSalesMan/Matrix.txt");
QTextStream MainstreamMatrix(&mainMatrix);

TravellerSalesMan::TravellerSalesMan()
{

}

void TravellerSalesMan::SetSize_Matrix()
{
    way = "";
    counter = 1;
    // Шаг 1. Создание матрицы смежности

    mainSize.open(QFile::ReadOnly | QFile::Text);
    Mainlen = MainstreamSize.readLine().toInt(0, 10);
    mainSize.flush();
    mainSize.close();
    mainSize.open(QFile::WriteOnly | QFile::Text);
    MainstreamSize << QString::number(Mainlen);
    mainSize.flush();
    mainSize.close();

    di = Mainlen;

    MainMatrix = new int* [Mainlen + 1];
    Mtemp = new int* [Mainlen];
    roads = new int* [Mainlen];

    for (int i = 0; i < Mainlen; i++)
    {
        MainMatrix[i] = new int [Mainlen + 1];
        roads[i] = new int[2];
        Mtemp[i] = new int[Mainlen];
    }
    MainMatrix[di] = new int[Mainlen + 1];

    // Заполнение матрицы смежности

    mainMatrix.close();
    mainMatrix.open(QFile::ReadOnly | QFile::Text);
    for (int i = 0; i < Mainlen; i++)
    {
        for (int j = 0; j < Mainlen; j++)
        {
            MainMatrix[i][j] = MainstreamMatrix.readLine().toInt(0, 10);
            Mtemp[i][j] = MainMatrix[i][j];
        }
    }
    mainMatrix.flush();
    mainMatrix.close();
    mainMatrix.open(QFile::WriteOnly | QFile::Text);
    for (int i = 0; i < Mainlen; i++)
    {
        for (int j = 0; j < Mainlen; j++)
        {
            MainstreamMatrix << QString::number(MainMatrix[i][j]) << "\n";
        }
    }
    mainMatrix.close();

    // Заменим размер дороги от одного к тому же городу или отсуствие дорог числом 10000 (будем считать, что это число является бесконечностью)

    for (int i = 0; i < Mainlen; i++)
    {
        for (int j = 0; j < Mainlen; j++)
        {
            if (MainMatrix[i][j] == 0)
            {
                MainMatrix[i][j] = 10000;
            }
        }
    }

    MainMatrix[di][di] = 0;         // Хранит результат вычислений
}

int TravellerSalesMan::getNumber(int I, int J)
{
    int k = 0, resJ, resI;
    while(k == J)
    {
        k++;
    }
    resJ = MainMatrix[I][k];

    k = 0;
    while(k == I)
    {
        k++;
    }
    resI = MainMatrix[k][J];

    for (k = 0; k < Mainlen; k++)   // Проход по строкам и столбцам
    {
        if (MainMatrix[I][k] < resJ && k != J)
        {
            resJ = MainMatrix[I][k];
        }
        if (MainMatrix[k][J] < resI && k != I)
        {
            resI = MainMatrix[k][J];
        }
    }
    return resI + resJ;
}

void TravellerSalesMan::RemoveNode(int I, int J)
{
    for (int k = 0; k < Mainlen; k++)
    {
        MainMatrix[k][J] = 10000;
        MainMatrix[I][k] = 10000;
        MainMatrix[k][k] = 10000;
    }
    if (MainMatrix[J][I] == 0)
    {
        MainMatrix[J][I] = 10000;
    }
}


void TravellerSalesMan::GetWay(int Node)
{
    if (roads[Node][0] != start || counter > 0)
    {
        counter--;
        way += " -> ";
        way += QString::number(roads[Node][1]);
        for (int i = 0; i < Mainlen; i++)
        {
            if (roads[i][0] == roads[Node][1])
            {
                GetWay(i);
                break;
            }
        }
    }
}

QString TravellerSalesMan::GetResult(QString root)
{
    SetSize_Matrix();
    start = root.toInt(0, 10);

    bool ok;
    if (!(root.toInt(&ok, 10)) || (root.toInt(0, 10) < 1 && root.toInt(0, 10) > Mainlen) || Mainlen < 3)
    {
        return "";
    }

    // В цикле



    for (int nodes = 0; nodes < Mainlen; nodes++)
    {
        // Шаг 2. Нахождение минимума по строкам + Шаг 3. Редукция строк
        // Шаг 4. Нахождение минимума по столбцам + Шаг 5. Редукция столбцов

        for (int i = 0; i < Mainlen; i++)
        {
            MainMatrix[i][di] = MainMatrix[i][0];   // Первый элемент в строке минимальный
            MainMatrix[di][i] = MainMatrix[0][i];   // Первый элемент в столбце минимальный
            for (int j = 1; j < Mainlen; j++)
            {
                if (MainMatrix[i][j] < MainMatrix[i][di])   // Строка
                {
                    MainMatrix[i][di] = MainMatrix[i][j];
                }
                if (MainMatrix[j][i] < MainMatrix[di][i])   // Столбец
                {
                    MainMatrix[di][i] = MainMatrix[j][i];
                }
            }
            if (MainMatrix[i][di] == 10000)             // Строка
            {
                MainMatrix[i][di] = 0;
            }
            if (MainMatrix[di][i] == 10000)             // Столбец
            {
                MainMatrix[di][i] = 0;
            }
            for (int j = 0; j < Mainlen; j++)
            {
                if (MainMatrix[i][j] != 10000)          // Строка
                {
                    MainMatrix[i][j] -= MainMatrix[i][di];
                }
                if (MainMatrix[j][i] != 10000)          // Столбец
                {
                    MainMatrix[j][i] -= MainMatrix[di][i];
                }
            }
        }

        // Шаг 6. Вычисление оценок нулевых клеток + Шаг 7. Редукция матрицы

        int max = 0,
            Imax = -1,
            Jmax = -1;

        for (int i = 0; i < Mainlen; i++)
        {
            for (int j = 0; j < Mainlen; j++)
            {
                if (MainMatrix[i][j] == 0)
                {
                    if (getNumber(i, j) >= max)
                    {
                        max = getNumber(i, j);
                        Imax = i;
                        Jmax = j;
                    }
                }
            }
        }

        RemoveNode(Imax, Jmax);

        roads[nodes][0] = Imax + 1;
        roads[nodes][1] = Jmax + 1;

        MainMatrix[di][di] += Mtemp[Imax][Jmax];
    }

    for (int i = 0; i < Mainlen; i++)
    {
        if (roads[i][0] == start)
        {
            way += QString::number(roads[i][0]);
            GetWay(i);
            break;
        }
    }

    return way;
}

QString TravellerSalesMan::WayLength(QString root)
{
    bool ok;
    if (!(root.toInt(&ok, 10)) || (root.toInt(0, 10) < 1 || root.toInt(0, 10) > Mainlen)  || Mainlen < 3)
    {
        return "";
    }
    return QString::number(MainMatrix[di][di]);
}

TravellerSalesMan::~TravellerSalesMan()
{

}
