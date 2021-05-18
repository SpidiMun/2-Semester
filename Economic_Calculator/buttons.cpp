#include "buttons.h"
#include <QString>

Buttons::Buttons()
{

}

QString Buttons::Reset_Loan()
{
    LoanRowSize = 0;
    LoanPointSize = 0;
    return "Введите сумму кредита";
}

QString Buttons::Reset_Percent()
{
    PercentRowSize = 0;
    PercentPointSize = 0;
    return "Введите годовую ставку (%)";
}

QString Buttons::Reset_Time()
{
    TimeRowSize = 0;
    return "Введите кол-во месяцев для выплаты кредита";
}

QString Buttons::Reset_Result()
{
    return "";
}

QString Buttons::Add_Loan_0(QString Loan)
{
    QString str = Loan;
    bool isConvert;
    if (!(str.toDouble(&isConvert)))
    {
        if (str == "0.")
        {
            str += '0';
            LoanRowSize++;
            LoanPointSize++;
            return str;
        }
        if (str != "0.0")
        {
            str = "";
            str += '0';
            return str;
        }
        return str;
    }
    else
    {
        if ((str + '0').toDouble(&isConvert) < 999999999)
        {
            if (str.count('.') == 0)
            {
                str += '0';
                LoanRowSize++;
                return str;
            }
            else
            {
                if (LoanPointSize < 3)
                {
                    str += '0';
                    LoanRowSize++;
                    LoanPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Percent_0(QString Percent)
{
    QString str = Percent;
    bool isConvert;
    if (!(str.toFloat(&isConvert)))
    {
        if (str == "0.")
        {
            str += '0';
            PercentRowSize++;
            PercentPointSize++;
            return str;
        }
        if (str != "0.0")
        {
            str = "";
            str += '0';
            return str;
        }
        return str;
    }
    else
    {
        if ((str + '0').toFloat(&isConvert) < 100)
        {
            if (str.count('.') == 0)
            {
                str += '0';
                PercentRowSize++;
                return str;
            }
            else
            {
                if (PercentPointSize < 3)
                {
                    str += '0';
                    PercentRowSize++;
                    PercentPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Time_0(QString Time)
{
    QString str = Time;
    bool isConvert;
    if (!(str.toInt(&isConvert, 10)))
    {
        str = "";
        str += '0';
        TimeRowSize++;
        return str;
    }
    else
    {

        if ((str + '0').toInt(&isConvert, 10) < 100)
        {
            str += '0';
            TimeRowSize++;
            return str;
        }
        return str;
    }
}

QString Buttons::Add_Loan_1(QString Loan)
{
    QString str = Loan;
    bool isConvert;
    if (!(str.toDouble(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '1';
            LoanRowSize++;
            LoanPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '1';
            LoanRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '1').toDouble(&isConvert) < 999999999)
        {
            if (str.count('.') == 0)
            {
                str += '1';
                LoanRowSize++;
                return str;
            }
            else
            {
                if (LoanPointSize < 3)
                {
                    str += '1';
                    LoanRowSize++;
                    LoanPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Percent_1(QString Percent)
{
    QString str = Percent;
    bool isConvert;
    if (!(str.toFloat(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '1';
            PercentRowSize++;
            PercentPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '1';
            PercentRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '1').toFloat(&isConvert) < 100)
        {
            if (str.count('.') == 0)
            {
                str += '1';
                PercentRowSize++;
                return str;
            }
            else
            {
                if (PercentPointSize < 3)
                {
                    str += '1';
                    PercentRowSize++;
                    PercentPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Time_1(QString Time)
{
    QString str = Time;
    bool isConvert;
    if (!(str.toInt(&isConvert, 10)))
    {
        str = "";
        str += '1';
        TimeRowSize++;
        return str;
    }
    else
    {
        if ((str + '1').toInt(&isConvert, 10) < 100)
        {
            str += '1';
            TimeRowSize++;
            return str;
        }
        return str;
    }
}

QString Buttons::Add_Loan_2(QString Loan)
{
    QString str = Loan;
    bool isConvert;
    if (!(str.toDouble(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '2';
            LoanRowSize++;
            LoanPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '2';
            LoanRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '2').toDouble(&isConvert) < 999999999)
        {
            if (str.count('.') == 0)
            {
                str += '2';
                LoanRowSize++;
                return str;
            }
            else
            {
                if (LoanPointSize < 3)
                {
                    str += '2';
                    LoanRowSize++;
                    LoanPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Percent_2(QString Percent)
{
    QString str = Percent;
    bool isConvert;
    if (!(str.toFloat(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '2';
            PercentRowSize++;
            PercentPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '2';
            PercentRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '2').toFloat(&isConvert) < 100)
        {
            if (str.count('.') == 0)
            {
                str += '2';
                PercentRowSize++;
                return str;
            }
            else
            {
                if (PercentPointSize < 3)
                {
                    str += '2';
                    PercentRowSize++;
                    PercentPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Time_2(QString Time)
{
    QString str = Time;
    bool isConvert;
    if (!(str.toInt(&isConvert, 10)))
    {
        str = "";
        str += '2';
        TimeRowSize++;
        return str;
    }
    else
    {
        if ((str + '2').toInt(&isConvert, 10) < 100)
        {
            str += '2';
            TimeRowSize++;
            return str;
        }
        return str;
    }
}

QString Buttons::Add_Loan_3(QString Loan)
{
    QString str = Loan;
    bool isConvert;
    if (!(str.toDouble(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '3';
            LoanRowSize++;
            LoanPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '3';
            LoanRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '3').toDouble(&isConvert) < 999999999)
        {
            if (str.count('.') == 0)
            {
                str += '3';
                LoanRowSize++;
                return str;
            }
            else
            {
                if (LoanPointSize < 3)
                {
                    str += '3';
                    LoanRowSize++;
                    LoanPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Percent_3(QString Percent)
{
    QString str = Percent;
    bool isConvert;
    if (!(str.toFloat(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '3';
            PercentRowSize++;
            PercentPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '3';
            PercentRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '3').toFloat(&isConvert) < 100)
        {
            if (str.count('.') == 0)
            {
                str += '3';
                PercentRowSize++;
                return str;
            }
            else
            {
                if (PercentPointSize < 3)
                {
                    str += '3';
                    PercentRowSize++;
                    PercentPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Time_3(QString Time)
{
    QString str = Time;
    bool isConvert;
    if (!(str.toInt(&isConvert, 10)))
    {
        str = "";
        str += '3';
        TimeRowSize++;
        return str;
    }
    else
    {
        if ((str + '3').toInt(&isConvert, 10) < 100)
        {
            str += '3';
            TimeRowSize++;
            return str;
        }
        return str;
    }
}

QString Buttons::Add_Loan_4(QString Loan)
{
    QString str = Loan;
    bool isConvert;
    if (!(str.toDouble(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '4';
            LoanRowSize++;
            LoanPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '4';
            LoanRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '4').toDouble(&isConvert) < 999999999)
        {
            if (str.count('.') == 0)
            {
                str += '4';
                LoanRowSize++;
                return str;
            }
            else
            {
                if (LoanPointSize < 3)
                {
                    str += '4';
                    LoanRowSize++;
                    LoanPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Percent_4(QString Percent)
{
    QString str = Percent;
    bool isConvert;
    if (!(str.toFloat(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '4';
            PercentRowSize++;
            PercentPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '4';
            PercentRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '4').toFloat(&isConvert) < 100)
        {
            if (str.count('.') == 0)
            {
                str += '4';
                PercentRowSize++;
                return str;
            }
            else
            {
                if (PercentPointSize < 3)
                {
                    str += '4';
                    PercentRowSize++;
                    PercentPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Time_4(QString Time)
{
    QString str = Time;
    bool isConvert;
    if (!(str.toInt(&isConvert, 10)))
    {
        str = "";
        str += '4';
        TimeRowSize++;
        return str;
    }
    else
    {
        if ((str + '4').toInt(&isConvert, 10) < 100)
        {
            str += '4';
            TimeRowSize++;
            return str;
        }
        return str;
    }
}

QString Buttons::Add_Loan_5(QString Loan)
{
    QString str = Loan;
    bool isConvert;
    if (!(str.toDouble(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '5';
            LoanRowSize++;
            LoanPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '5';
            LoanRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '5').toDouble(&isConvert) < 999999999)
        {
            if (str.count('.') == 0)
            {
                str += '5';
                LoanRowSize++;
                return str;
            }
            else
            {
                if (LoanPointSize < 3)
                {
                    str += '5';
                    LoanRowSize++;
                    LoanPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Percent_5(QString Percent)
{
    QString str = Percent;
    bool isConvert;
    if (!(str.toFloat(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '5';
            PercentRowSize++;
            PercentPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '5';
            PercentRowSize++;
        }
        return str;
    }
    else
    {
        if ((str + '5').toFloat(&isConvert) < 100)
        {
            if (str.count('.') == 0)
            {
                str += '5';
                PercentRowSize++;
                return str;
            }
            else
            {
                if (PercentPointSize < 3)
                {
                    str += '5';
                    PercentRowSize++;
                    PercentPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Time_5(QString Time)
{
    QString str = Time;
    bool isConvert;
    if (!(str.toInt(&isConvert, 10)))
    {
        str = "";
        str += '5';
        TimeRowSize++;
        return str;
    }
    else
    {
        if ((str + '5').toInt(&isConvert, 10) < 100)
        {
            str += '5';
            TimeRowSize++;
            return str;
        }
        return str;
    }
}

QString Buttons::Add_Loan_6(QString Loan)
{
    QString str = Loan;
    bool isConvert;
    if (!(str.toDouble(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '6';
            LoanRowSize++;
            LoanPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '6';
            LoanRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '6').toDouble(&isConvert) < 999999999)
        {
            if (str.count('.') == 0)
            {
                str += '6';
                LoanRowSize++;
                return str;
            }
            else
            {
                if (LoanPointSize < 3)
                {
                    str += '6';
                    LoanRowSize++;
                    LoanPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Percent_6(QString Percent)
{
    QString str = Percent;
    bool isConvert;
    if (!(str.toFloat(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '6';
            PercentRowSize++;
            PercentPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '6';
            PercentRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '6').toFloat(&isConvert) < 100)
        {
            if (str.count('.') == 0)
            {
                str += '6';
                PercentRowSize++;
                return str;
            }
            else
            {
                if (PercentPointSize < 3)
                {
                    str += '6';
                    PercentRowSize++;
                    PercentPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Time_6(QString Time)
{
    QString str = Time;
    bool isConvert;
    if (!(str.toInt(&isConvert, 10)))
    {
        str = "";
        str += '6';
        TimeRowSize++;
        return str;
    }
    else
    {
        if ((str + '6').toInt(&isConvert, 10) < 100)
        {
            str += '6';
            TimeRowSize++;
            return str;
        }
        return str;
    }
}

QString Buttons::Add_Loan_7(QString Loan)
{
    QString str = Loan;
    bool isConvert;
    if (!(str.toDouble(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '7';
            LoanRowSize++;
            LoanPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '7';
            LoanRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '7').toDouble(&isConvert) < 999999999)
        {
            if (str.count('.') == 0)
            {
                str += '7';
                LoanRowSize++;
                return str;
            }
            else
            {
                if (LoanPointSize < 3)
                {
                    str += '7';
                    LoanRowSize++;
                    LoanPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Percent_7(QString Percent)
{
    QString str = Percent;
    bool isConvert;
    if (!(str.toFloat(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '7';
            PercentRowSize++;
            PercentPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '7';
            PercentRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '7').toFloat(&isConvert) < 100)
        {
            if (str.count('.') == 0)
            {
                str += '7';
                PercentRowSize++;
                return str;
            }
            else
            {
                if (PercentPointSize < 3)
                {
                    str += '7';
                    PercentRowSize++;
                    PercentPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Time_7(QString Time)
{
    QString str = Time;
    bool isConvert;
    if (!(str.toInt(&isConvert, 10)))
    {
        str = "";
        str += '7';
        TimeRowSize++;
        return str;
    }
    else
    {
        if ((str + '7').toInt(&isConvert, 10) < 100)
        {
            str += '7';
            TimeRowSize++;
            return str;
        }
        return str;
    }
}

QString Buttons::Add_Loan_8(QString Loan)
{
    QString str = Loan;
    bool isConvert;
    if (!(str.toDouble(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '8';
            LoanRowSize++;
            LoanPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '8';
            LoanRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '8').toDouble(&isConvert) < 999999999)
        {
            if (str.count('.') == 0)
            {
                str += '8';
                LoanRowSize++;
                return str;
            }
            else
            {
                if (LoanPointSize < 3)
                {
                    str += '8';
                    LoanRowSize++;
                    LoanPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Percent_8(QString Percent)
{
    QString str = Percent;
    bool isConvert;
    if (!(str.toFloat(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '8';
            PercentRowSize++;
            PercentPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '8';
            PercentRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '8').toFloat(&isConvert) < 100)
        {
            if (str.count('.') == 0)
            {
                str += '8';
                PercentRowSize++;
                return str;
            }
            else
            {
                if (PercentPointSize < 3)
                {
                    str += '8';
                    PercentRowSize++;
                    PercentPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Time_8(QString Time)
{
    QString str = Time;
    bool isConvert;
    if (!(str.toInt(&isConvert, 10)))
    {
        str = "";
        str += '8';
        TimeRowSize++;
        return str;
    }
    else
    {
        if ((str + '8').toInt(&isConvert, 10) < 100)
        {
            str += '8';
            TimeRowSize++;
            return str;
        }
        return str;
    }
}

QString Buttons::Add_Loan_9(QString Loan)
{
    QString str = Loan;
    bool isConvert;
    if (!(str.toDouble(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '9';
            LoanRowSize++;
            LoanPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '9';
            LoanRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '9').toDouble(&isConvert) < 999999999)
        {
            if (str.count('.') == 0)
            {
                str += '9';
                LoanRowSize++;
                return str;
            }
            else
            {
                if (LoanPointSize < 3)
                {
                    str += '9';
                    LoanRowSize++;
                    LoanPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Percent_9(QString Percent)
{
    QString str = Percent;
    bool isConvert;
    if (!(str.toFloat(&isConvert)))
    {
        if (str == "0." || str == "0.0")
        {
            str += '9';
            PercentRowSize++;
            PercentPointSize++;
            return str;
        }
        else
        {
            str = "";
            str += '9';
            PercentRowSize++;
            return str;
        }
    }
    else
    {
        if ((str + '9').toFloat(&isConvert) < 100)
        {
            if (str.count('.') == 0)
            {
                str += '9';
                PercentRowSize++;
                return str;
            }
            else
            {
                if (PercentPointSize < 3)
                {
                    str += '9';
                    PercentRowSize++;
                    PercentPointSize++;
                    return str;
                }
            }
        }
        return str;
    }
}

QString Buttons::Add_Time_9(QString Time)
{
    QString str = Time;
    bool isConvert;
    if (!(str.toInt(&isConvert, 10)))
    {
        str = "";
        str += '9';
        TimeRowSize++;
        return str;
    }
    else
    {
        if ((str + '9').toInt(&isConvert, 10) < 100)
        {
            str += '9';
            TimeRowSize++;
            return str;
        }
        return str;
    }
}

QString Buttons::Add_Point_Loan(QString Loan)
{
    QString str = Loan;
    bool isConvert;
    if (str.toDouble(&isConvert) || str == '0')
    {
        if ((LoanRowSize > 0 && str.count('.') != 1) || str == '0')
        {
            if (str == '0')
            {
                LoanRowSize++;
            }
            str += ".";
            LoanRowSize++;
            LoanPointSize++;
            return str;
        }
    }
    return str;
}

QString Buttons::Add_Point_Percent(QString Percent)
{
    QString str = Percent;
    bool isConvert;
    if (str.toFloat(&isConvert) || str == '0')
    {
        if ((PercentRowSize > 0 && str.count('.') != 1) || str == '0')
        {
            if (str == '0')
            {
                PercentRowSize++;
            }
            str += ".";
            PercentRowSize++;
            PercentPointSize++;
            return str;
        }
    }
    return str;
}

QString Buttons::Delete_Loan(QString Loan)
{
    if (LoanRowSize > 1)
    {
        QString str = Loan;
        if (str.count('.') == 0)
        {
            str.chop(1);
            LoanRowSize--;
            return str;
        }
        else
        {
            if (LoanPointSize != 0)
            {
                str.chop(1);
                LoanRowSize--;
                LoanPointSize--;
                return str;
            }
            return str;
        }
    }
    else
    {
         QString str = Reset_Loan();
         LoanRowSize= 0;
         return str;
    }
}

QString Buttons::Delete_Percent(QString Percent)
{
    if (PercentRowSize > 1)
    {
        QString str = Percent;
        if (str.count('.') == 0)
        {
            str.chop(1);
            PercentRowSize--;
            return str;
        }
        else
        {
            if (PercentPointSize != 0)
            {
                str.chop(1);
                PercentRowSize--;
                PercentPointSize--;
                return str;
            }
            return str;
        }
    }
    else
    {
         QString str = Reset_Percent();
         PercentRowSize= 0;
         return str;
    }
}

QString Buttons::Delete_Time(QString Time)
{
    if (TimeRowSize > 1)
    {
        QString str = Time;
        str.chop(1);
        TimeRowSize--;
        return str;
    }
    else
    {
         QString str = Reset_Time();
         TimeRowSize= 0;
         return str;
    }
}


Buttons::~Buttons()
{

}
