#include "addwindow.h"
#include "ui_addwindow.h"

#include <QFile>
#include <QTextStream>

QFile ASize("C:/QtRepos/ShitGraph/MatrixSize.txt");
QTextStream AstreamSize(&ASize);
QFile AMatrix("C:/QtRepos/ShitGraph/Matrix.txt");
QTextStream AstreamMatrix(&AMatrix);

int Alen;       // Add len
int** amatrix;  // Add matrix

AddWindow::AddWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);

    ASize.open(QFile::ReadOnly | QFile::Text);
    Alen = AstreamSize.readLine().toInt(0, 10) + 1;
    ASize.flush();
    ASize.close();
    ASize.open(QFile::WriteOnly | QFile::Text);
    AstreamSize << QString::number(Alen);
    ASize.flush();
    ASize.close();
    amatrix = new int* [Alen];
    for (int i = 0; i < Alen; i++)
    {
        amatrix[i] = new int [Alen];
    }

    for (int i = 0; i < Alen; i++)
    {
        for (int j = 0; j < Alen; j++)
        {
            amatrix[i][j] = 0;
        }
    }

    ui->startNode->setText(QString::number(Alen));   // Новая вершина - количество узлов

    /*
    connect(ui->endNode, &QTextEdit::textChanged, this, &AddWindow::setEndNodeText);
    connect(ui->normalLength, &QTextEdit::textChanged, this, &AddWindow::setNormalLengthText);
    connect(ui->reverseLength, &QTextEdit::textChanged, this, &AddWindow::setReverseLengthText);
    */
    connect(ui->btnAddRoad, &QPushButton::clicked, this, &AddWindow::AddRoad);
    connect(ui->btnAdd, &QPushButton::clicked, this, &AddWindow::AddNode);
}

/*
void AddWindow::setStartNodeText()
{
    QString row = ui->startNode->toPlainText();
    bool isDigit;
    if (row.toInt(&isDigit, 10) && (row.toInt(&isDigit, 10) >= Alen ||row.toInt(&isDigit, 10) < 0))
    {
        row.chop(1);
    }
    ui->startNode->setText(row);
}
*/
/*
void AddWindow::setEndNodeText()
{
    QString row = ui->endNode->toPlainText();
    bool isDigit;
    if (row.toInt(&isDigit, 10) && (row.toInt(&isDigit, 10) > Alen - 1 || row.toInt(&isDigit, 10) < 0))
    {
        row.chop(1);
    }
    ui->normalLength->setText(row);
}

void AddWindow::setNormalLengthText()
{
    QString row = ui->normalLength->toPlainText();
    bool isDigit;
    if (row.toInt(&isDigit, 10) && (row.toInt(&isDigit, 10) > 10000 ||row.toInt(&isDigit, 10) < 0))
    {
        row.chop(1);
    }
    ui->normalLength->setText(row);
}

void AddWindow::setReverseLengthText()
{
    QString row = ui->reverseLength->toPlainText();
    bool isDigit;
    if (row.toInt(&isDigit, 10) && (row.toInt(&isDigit, 10) > 10000 ||row.toInt(&isDigit, 10) < 0))
    {
        row.chop(1);
    }
    ui->reverseLength->setText(row);
}
*/
void AddWindow::AddRoad()
{
    bool isWritten;
    if (ui->startNode->toPlainText().toInt(&isWritten, 10) && ui->endNode->toPlainText().toInt(&isWritten, 10) && (ui->normalLength->toPlainText().toInt(&isWritten, 10) ||  ui->normalLength->toPlainText() == "0") && (ui->reverseLength->toPlainText().toInt(&isWritten, 10) ||  ui->reverseLength->toPlainText() == "0"))
    {
        int i = ui->startNode->toPlainText().toInt(0, 10) - 1,
            j = ui->endNode->toPlainText().toInt(0, 10) - 1;

        amatrix [i][j] = ui->normalLength->toPlainText().toInt(0, 10);
        amatrix [j][i] = ui->reverseLength->toPlainText().toInt(0, 10);
        if (ui->normalLength->toPlainText() == 0)
        {
            amatrix [i][j] = 0;
        }
        if (ui->reverseLength->toPlainText() == 0)
        {
            amatrix [j][i] = 0;
        }

        ui->endNode->setText("");
        ui->normalLength->setText("");
        ui->reverseLength->setText("");
    }
}

void AddWindow::AddNode()
{
    AddRoad();
    AMatrix.close();
    AMatrix.open(QFile::ReadOnly | QFile::Text);
    for (int i = 0; i < Alen - 1; i++)
    {
        for (int j = 0; j < Alen - 1; j++)
        {
            amatrix[i][j] = AstreamMatrix.readLine().toInt(0, 10);
        }
    }
    AMatrix.flush();
    AMatrix.close();
    AMatrix.open(QFile::WriteOnly | QFile::Text);
    for (int i = 0; i < Alen; i++)
    {
        for (int j = 0; j < Alen; j++)
        {
            AstreamMatrix << QString::number(amatrix[i][j]) << "\n";
        }
    }
    AMatrix.close();
    close();
}

AddWindow::~AddWindow()
{
    delete ui;
}
