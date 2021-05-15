#include "editwindow.h"
#include "ui_editwindow.h"

#include <QFile>
#include <QTextStream>

QFile ESize("C:/QtRepos/ShitGraph/MatrixSize.txt");
QTextStream EstreamSize(&ESize);
QFile EMatrix("C:/QtRepos/ShitGraph/Matrix.txt");
QTextStream EstreamMatrix(&EMatrix);

int Elen;       // Len
int** ematrix;  // Edit matrix

EditWindow::EditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);

    ESize.open(QFile::ReadOnly | QFile::Text);
    Elen = EstreamSize.readLine().toInt(0, 10);
    ESize.flush();
    ESize.close();
    ESize.open(QFile::WriteOnly | QFile::Text);
    EstreamSize << QString::number(Elen);
    ESize.flush();
    ESize.close();
    ematrix = new int* [Elen];
    for (int i = 0; i < Elen; i++)
    {
        ematrix[i] = new int [Elen];
    }

    EMatrix.close();
    EMatrix.open(QFile::ReadOnly | QFile::Text);
    for (int i = 0; i < Elen; i++)
    {
        for (int j = 0; j < Elen; j++)
        {
            ematrix[i][j] = EstreamMatrix.readLine().toInt(0, 10);
        }
    }
    EMatrix.flush();
    EMatrix.close();
    /*
    for (int i = 0; i < Elen; i++)
    {
        for (int j = 0; j < Elen; j++)
        {
            Ematrix[i][j] = 0;
        }
    }
    */
    /*
    connect(ui->startNode, &QTextEdit::textChanged, this, &EditWindow::setStartNodeText);
    connect(ui->endNode, &QTextEdit::textChanged, this, &EditWindow::setEndNodeText);
    connect(ui->normalLength, &QTextEdit::textChanged, this, &EditWindow::setNormalLengthText);
    connect(ui->reverseLength, &QTextEdit::textChanged, this, &EditWindow::setReverseLengthText);
    */
    connect(ui->btnEditRoad, &QPushButton::clicked, this, &EditWindow::EditRoad);
    connect(ui->btnEdit, &QPushButton::clicked, this, &EditWindow::EditNode);
}
/*
void EditWindow::setStartNodeText()
{
    QString row = ui->startNode->toPlainText();
    bool isDigit;
    if (row.toInt(&isDigit, 10) && (row.toInt(&isDigit, 10) > Elen ||row.toInt(&isDigit, 10) < 0))
    {
        row.chop(1);
    }
    ui->startNode->setText(row);
    bool isDigit;
    if (ui->endNode->toPlainText().toInt(&isDigit, 10) && ui->startNode->toPlainText().toInt(&isDigit, 10))
    {
        if (ui->startNode->toPlainText() == ui->endNode->toPlainText())
        {
            ui->normalLength->setText("0");
            ui->reverseLength->setText("0");
        }
        else
        {
            ui->normalLength->setText(QString::number(ematrix[ui->startNode->toPlainText().toInt(0, 10)][ui->endNode->toPlainText().toInt(0, 10)]);
            ui->reverseLength->setText(QString::number(ematrix[ui->endNode->toPlainText().toInt(0, 10)][ui->startNode->toPlainText().toInt(0, 10)]);
        }
    }
}

void EditWindow::setEndNodeText()
{
    QString row = ui->endNode->toPlainText();
    bool isDigit;
    if (row.toInt(&isDigit, 10) && (row.toInt(&isDigit, 10) > Elen || row.toInt(&isDigit, 10) < 0))
    {
        row.chop(1);
    }
    ui->normalLength->setText(row);
    if (ui->endNode->toPlainText().toInt(&isDigit, 10) && ui->startNode->toPlainText().toInt(&isDigit, 10))
    {
        if (ui->startNode->toPlainText() == ui->endNode->toPlainText())
        {
            ui->normalLength->setText("0");
            ui->reverseLength->setText("0");
        }
        else
        {
            ui->normalLength->setText(QString::number(ematrix[ui->startNode->toPlainText().toInt(0, 10)][ui->endNode->toPlainText().toInt(0, 10)]);
            ui->reverseLength->setText(QString::number(ematrix[ui->endNode->toPlainText().toInt(0, 10)][ui->startNode->toPlainText().toInt(0, 10)]);
        }
    }
}

void EditWindow::setNormalLengthText()
{
    QString row = ui->normalLength->toPlainText();
    bool isDigit;
    if (row.toInt(&isDigit, 10) && (row.toInt(&isDigit, 10) > 10000 ||row.toInt(&isDigit, 10) < 0))
    {
        row.chop(1);
    }
    ui->normalLength->setText(row);
}

void EditWindow::setReverseLengthText()
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
void EditWindow::EditRoad()
{
    bool isWritten;
    if (ui->startNode->toPlainText().toInt(&isWritten, 10) && ui->endNode->toPlainText().toInt(&isWritten, 10) && (ui->normalLength->toPlainText().toInt(&isWritten, 10) ||  ui->normalLength->toPlainText() == "0") && (ui->reverseLength->toPlainText().toInt(&isWritten, 10) ||  ui->reverseLength->toPlainText() == "0"))
    {
        int i = ui->startNode->toPlainText().toInt(0, 10) - 1,
            j = ui->endNode->toPlainText().toInt(0, 10) - 1;

        ematrix [i][j] = ui->normalLength->toPlainText().toInt(0, 10);
        ematrix [j][i] = ui->reverseLength->toPlainText().toInt(0, 10);
        if (ui->normalLength->toPlainText() == 0)
        {
            ematrix [i][j] = 0;
        }
        if (ui->reverseLength->toPlainText() == 0)
        {
            ematrix [j][i] = 0;
        }

        ui->endNode->setText("");
        ui->normalLength->setText("");
        ui->reverseLength->setText("");
    }
}

void EditWindow::EditNode()
{
    EditRoad();
    EMatrix.open(QFile::WriteOnly | QFile::Text);
    for (int i = 0; i < Elen; i++)
    {
        for (int j = 0; j < Elen; j++)
        {
            EstreamMatrix << QString::number(ematrix[i][j]) << "\n";
        }
    }
    EMatrix.close();
    close();
}

EditWindow::~EditWindow()
{
    delete ui;
}
