#ifndef QTWINDOW_H
#define QTWINDOW_H

#include <QMainWindow>
#include "myglwidget.h"
#include "addwindow.h"
#include "editwindow.h"
#include "deletewindow.h"

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

private:
    Ui::QtWindow *ui;
    MyGLWidget *openGLW;
};

#endif // QTWINDOW_H
