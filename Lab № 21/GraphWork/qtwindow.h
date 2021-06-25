#ifndef QTWINDOW_H
#define QTWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE

namespace Ui { class QtWindow; }

QT_END_NAMESPACE

class QtWindow : public QMainWindow
{
    Q_OBJECT

public:
    QtWindow(QWidget *parent = nullptr);
    ~QtWindow();

private:
    Ui::QtWindow *ui;
};

#endif // QTWINDOW_H
