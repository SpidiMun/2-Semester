#ifndef QTWINDOW_H
#define QTWINDOW_H

#include <QMainWindow>
#include "myglwidget.h"
#include "addwindow.h"
#include "editwindow.h"
#include "deletewindow.h"
#include "travellersalesman.h"

QT_BEGIN_NAMESPACE

namespace Ui { class QtWindow; }

QT_END_NAMESPACE

class QtWindow : public QMainWindow
{
    Q_OBJECT

public:
    QtWindow(QWidget *parent = nullptr);
    ~QtWindow();

private slots:
    void CreateGraph();
    void ButtonAdd();
    void ButtonEdit();
    void ButtonDelete();
    void GetResult();

private:
    Ui::QtWindow *ui;
    MyGLWidget *openGLW;
    TravellerSalesMan man;
};

#endif // QTWINDOW_H
