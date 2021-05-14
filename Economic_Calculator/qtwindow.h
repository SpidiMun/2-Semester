#ifndef QTWINDOW_H
#define QTWINDOW_H

#include "calculation.h"
#include "buttons.h"

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

private slots:

    void Reset_Text();          // Для кнопки "Сброс"

    void Add_Digit_0();         // Отдельна для реализации
    void Add_Digit_1();
    void Add_Digit_2();
    void Add_Digit_3();
    void Add_Digit_4();
    void Add_Digit_5();
    void Add_Digit_6();
    void Add_Digit_7();
    void Add_Digit_8();
    void Add_Digit_9();
    void Delete_Digit();        // Для кнопки удаления последнего символа
    void Add_Point();           // Для кнопки "."

    void Set_Annuitet();        // Для кнопки "Аннуитетный платёж
    void Set_Differentiated();  // Для кнопки "Дифференциальный платёж
    void Get_Result();          // Для кнопки "Посчитать!"

    void Set_Loan();
    void Set_Percent();
    void Set_Time();

private:
    Ui::QtWindow *ui;
    Calculation result;
    Buttons button;
    bool isConvert;             // Для проверки строк ввода на "пустоту"

    // Флажки для проверки, какое поле ввода было выбрано

    bool isLoanSelected = false;
    bool isPercentSelected = false;
    bool isTimeSelected = false;

};
#endif // QTWINDOW_H
