#include "qtwindow.h"
#include "ui_qtwindow.h"

#include <QPainter>
#include <QGridLayout>
#include <QPushButton>
#include <QProcess>

QtWindow::QtWindow(QWidget *parent)
    :QMainWindow(parent), ui(new Ui::QtWindow)
{
    ui->setupUi(this);

    openGLW = new MyGLWidget(this);
    ui->grid->addWidget(openGLW, 0, 0);
    connect(ui->btnRedraw, &QPushButton::clicked, openGLW, &MyGLWidget::redraw);
    connect(ui->btnCreate, &QPushButton::clicked, this, &QtWindow::CreateGraph);
    connect(ui->btnAdd, &QPushButton::clicked, this, &QtWindow::ButtonAdd);
    connect(ui->btnEdit, &QPushButton::clicked, this, &QtWindow::ButtonEdit);
    connect(ui->btnDelete, &QPushButton::clicked, this, &QtWindow::ButtonDelete);
}

void QtWindow::CreateGraph()
{
    QProcess process(this);
    process.startDetached("C:/QtRepos/ShitGraph/run.bat");
}

void QtWindow::ButtonAdd()
{
    AddWindow window;
    window.setModal(true);
    window.exec();
}

void QtWindow::ButtonEdit()
{
    EditWindow window;
    window.setModal(true);
    window.exec();
}

void QtWindow::ButtonDelete()
{
    DeleteWindow window;
    window.setModal(true);
    window.exec();
}

QtWindow::~QtWindow()
{
    delete ui;
}
