#pragma once

#ifndef CALCULATION_H
#define CALCULATION_H

#include <QString>

class Calculation
{
public:
    Calculation();
    ~Calculation();
    QString Get_Payout(QString strLoan, QString strPercent, QString strTime);       // Выплаты (Для кнопки "Посчитать!")
    QString Get_Overpayment(QString strLoan, QString strPercent, QString strTime);  // Переплаты (Для кнопки "Посчитать!")
    void Annuitet();                                                                // Для кнопки "Аннуитетный платёж
    void Differentiated();                                                          // Для кнопки "Дифференциальный платёж

private:
    int KindOfPayment = 0;                                      // Выбор способа вычисления сумм выплат и переплат кредита
};

#endif // CALCULATION_H
