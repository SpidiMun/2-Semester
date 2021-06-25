#include "qtwindow.h"
#include "ui_qtwindow.h"
#include "myglwidget.h"

#include <QPainter>
#include <QProcess>
#include <QGridLayout>
#include <QPushButton>

QtWindow::QtWindow(QWidget *parent)
    :QMainWindow(parent),ui(new Ui::QtWindow)
{
    ui->setupUi(this);
    MyGLWidget *openGLW = new MyGLWidget(this);
    QGridLayout *grid = new QGridLayout();
    grid->addWidget(openGLW, 0, 0);
    ui->centralwidget->setLayout(grid);
    QProcess process(this);
    process.startDetached("C:/QtRepos/GraphWork/run.bat");
}

QtWindow::~QtWindow()
{
    delete ui;
}
