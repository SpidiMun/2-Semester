#ifndef BUTTONS_H
#define BUTTONS_H

#include <QString>

class Buttons
{
public:
    Buttons();
    ~Buttons();

    QString Reset_Loan();
    QString Reset_Percent();
    QString Reset_Time();
    QString Reset_Result();

    QString Add_Loan_0(QString Loan);
    QString Add_Percent_0(QString Percent);
    QString Add_Time_0(QString Time);

    QString Add_Loan_1(QString Loan);
    QString Add_Percent_1(QString Percent);
    QString Add_Time_1(QString Time);

    QString Add_Loan_2(QString Loan);
    QString Add_Percent_2(QString Percent);
    QString Add_Time_2(QString Time);

    QString Add_Loan_3(QString Loan);
    QString Add_Percent_3(QString Percent);
    QString Add_Time_3(QString Time);

    QString Add_Loan_4(QString Loan);
    QString Add_Percent_4(QString Percent);
    QString Add_Time_4(QString Time);

    QString Add_Loan_5(QString Loan);
    QString Add_Percent_5(QString Percent);
    QString Add_Time_5(QString Time);

    QString Add_Loan_6(QString Loan);
    QString Add_Percent_6(QString Percent);
    QString Add_Time_6(QString Time);

    QString Add_Loan_7(QString Loan);
    QString Add_Percent_7(QString Percent);
    QString Add_Time_7(QString Time);

    QString Add_Loan_8(QString Loan);
    QString Add_Percent_8(QString Percent);
    QString Add_Time_8(QString Time);

    QString Add_Loan_9(QString Loan);
    QString Add_Percent_9(QString Percent);
    QString Add_Time_9(QString Time);

    QString Delete_Loan(QString Loan);
    QString Delete_Percent(QString Percent);
    QString Delete_Time(QString Time);

    QString Add_Point_Loan(QString Loan);
    QString Add_Point_Percent(QString Percent);

private:

    // Длина строк полей "Кредит", "Годовой процент" и "Время для выплат" (включая дробную часть числа)

    int LoanRowSize = 0;
    int PercentRowSize = 0;
    int TimeRowSize = 0;

    // Количество цифр после точки

    int LoanPointSize = 0;
    int PercentPointSize = 0;

};

#endif // BUTTONS_H
