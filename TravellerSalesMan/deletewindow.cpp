#include "deletewindow.h"
#include "ui_deletewindow.h"

#include <QFile>
#include <QTextStream>

QFile DSize("C:/QtRepos/ShitGraph/MatrixSize.txt");
QTextStream DstreamSize(&DSize);
QFile DMatrix("C:/QtRepos/ShitGraph/Matrix.txt");
QTextStream DstreamMatrix(&DMatrix);

int Dlen;       // Delete len
int** dmatrix;  // Matrix (уже с удалённым элементом)
int** temp;     // Delete matrix

DeleteWindow::DeleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteWindow)
{
    ui->setupUi(this);

    DSize.open(QFile::ReadOnly | QFile::Text);
    bool ok;
    if (DstreamSize.readLine().toInt(&ok, 10))
    {
        Dlen = DstreamSize.readLine().toInt(0, 10) - 1;
    //}
    //else
    //{
    //    Dlen = DstreamSize.readLine().toInt(0, 10);
    //}
        DSize.flush();
        DSize.close();
        DSize.open(QFile::WriteOnly | QFile::Text);
        DstreamSize << QString::number(Dlen);
        DSize.flush();
        DSize.close();

        temp = new int* [Dlen + 1];
        dmatrix = new int*[Dlen];
        for (int i = 0; i < Dlen; i++)
        {
        temp[i] = new int[Dlen + 1];
            dmatrix[i] = new int [Dlen];
        }
        temp[Dlen + 1] = new int[Dlen + 1];

        DMatrix.close();
        DMatrix.open(QFile::ReadOnly | QFile::Text);
        for (int i = 0; i < Dlen + 1; i++)
        {
            for (int j = 0; j < Dlen + 1; j++)
            {
                temp[i][j] = DstreamMatrix.readLine().toInt(0, 10);
            }
        }
        DMatrix.flush();
        DMatrix.close();

        connect(ui->btnDelete, &QPushButton::clicked, this, &DeleteWindow::DeleteNode);
    }
}

void DeleteWindow::DeleteNode()
{
    bool isWritten;
    if ((ui->deleteNode->toPlainText().toInt(&isWritten, 10)))
    {
        int Idel = ui->deleteNode->toPlainText().toInt(0, 10) - 1, // Для удаления строки
            Jdel = ui->deleteNode->toPlainText().toInt(0, 10) - 1; // Для удаления столбца

        int k = 0, l = 0;
        for (int i = 0; i < Dlen; i++)
        {
            if (i != Idel)
            {
                k++;
                for (int j = 0; j < Dlen; j++)
                {
                    l = 0;
                    if (j != Jdel)
                    {
                        l++;
                        dmatrix[k][l] = temp[i][j];
                    }
                }
            }
        }
        DMatrix.open(QFile::WriteOnly | QFile::Text);
        for (int i = 0; i < Dlen; i++)
        {
            for (int j = 0; j < Dlen; j++)
            {
                DstreamMatrix << QString::number(dmatrix[i][j]) << "\n";
            }
        }
        DMatrix.close();
        close();
    }
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}
