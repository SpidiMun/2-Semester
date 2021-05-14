#include "calculation.h"

#include <QString>
#include <QtCore/qmath.h>       // Для кнопки "Подсчитать!"

Calculation::Calculation()
{

}

QString Calculation::Get_Payout(QString strLoan, QString strPercent, QString strTime) // Подсчёт
{
    QString PayoutResult;
    double Loan;                // Сумма кредита
    int MonthCount;             // Количество месяцев для выплат (срок)
    float YearPercent;          // Годовая процентная ставка
    double Payout = 0;          // Общая сумма выплат
    Loan = strLoan.toDouble();
    YearPercent = strPercent.toFloat();
    MonthCount = strTime.toInt();
    if (KindOfPayment == 0)
    {
        PayoutResult = "Выберите способ подсчёта!";
        return PayoutResult;
    }
    else
    {
        if (KindOfPayment == 1)
        {
            float MonthPercent;         // Ежемесячная процентная ставка
            double MonthPayout;         // Ежемесячная выплата

            MonthPercent = YearPercent / (100 * 12);
            MonthPayout = Loan * (MonthPercent + MonthPercent / (qPow(1 + MonthPercent, MonthCount) - 1));
            Payout = MonthPayout * MonthCount;

            PayoutResult = QString::number(Payout, 'f', 2);
            return PayoutResult;
        }
        else
        {
            double LoanPayout;          // Ежемесячная выплата тела кредита
            double PercentPayout;       // Ежемесячная выплата процента (переплаты)
            double MonthPayout;         // Ежемесячная выплата
            double Balance;             // Остаток

            Balance = Loan;
            LoanPayout = Loan / MonthCount;

            while (Balance >= 1)
            {
                PercentPayout = Balance * YearPercent / (100 * 12);
                MonthPayout = LoanPayout + PercentPayout;
                Balance -= LoanPayout;
                Payout += MonthPayout;
            }
            PayoutResult = QString::number(Payout, 'f', 2);
            return PayoutResult;
        }
    }
}

QString Calculation::Get_Overpayment(QString strLoan, QString strPercent, QString strTime) // Подсчёт
{
    QString OverpaymentResult;
    double Loan;                // Сумма кредита
    int MonthCount;             // Количество месяцев для выплат (срок)
    float YearPercent;          // Годовая процентная ставка
    double Payout = 0;          // Общая сумма выплат
    double Overpayment;         // Общая сумма переплат
    Loan = strLoan.toDouble();
    YearPercent = strPercent.toFloat();
    MonthCount = strTime.toInt();
    if (KindOfPayment == 0)
    {
        OverpaymentResult = "Выберите способ подсчёта!";
        return OverpaymentResult;
    }
    else
    {
        if (KindOfPayment == 1)
        {
            float MonthPercent;         // Ежемесячная процентная ставка
            double MonthPayout;         // Ежемесячная выплата

            MonthPercent = YearPercent / (100 * 12);
            MonthPayout = Loan * (MonthPercent + MonthPercent / (qPow(1 + MonthPercent, MonthCount) - 1));
            Payout = MonthPayout * MonthCount;
            Overpayment = Payout - Loan;

            OverpaymentResult = QString::number(Overpayment, 'f', 2);
            return OverpaymentResult;
        }
        else
        {
            double LoanPayout;          // Ежемесячная выплата тела кредита
            double PercentPayout;       // Ежемесячная выплата процента (переплаты)
            double MonthPayout;         // Ежемесячная выплата
            double Balance;             // Остаток

            Balance = Loan;
            LoanPayout = Loan / MonthCount;

            while (Balance >= 1)
            {
                PercentPayout = Balance * YearPercent / (100 * 12);
                MonthPayout = LoanPayout + PercentPayout;
                Balance -= LoanPayout;
                Payout += MonthPayout;
            }
            Overpayment = Payout - Loan;

            OverpaymentResult = QString::number(Overpayment, 'f', 2);

            return OverpaymentResult;
        }
    }
}

void Calculation::Annuitet()
{
    KindOfPayment = 1;
}

void Calculation::Differentiated()
{
    KindOfPayment = 2;
}

Calculation::~Calculation()
{

}
