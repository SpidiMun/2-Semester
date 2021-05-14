#include "qtwindow.h"
#include "ui_qtwindow.h"
#include "calculation.h"
#include "buttons.h"

#include <QtCore/qmath.h>       // Для кнопки "Подсчитать!"

QtWindow::QtWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtWindow)
{
    ui->setupUi(this);

    // Кнопка "Сброс"

    connect(ui->ButtonReset, &QPushButton::clicked, this, &QtWindow::Reset_Text);

    // Кнопки калькулятора

    connect(ui->Button0, &QPushButton::clicked, this, &QtWindow::Add_Digit_0);
    connect(ui->Button1, &QPushButton::clicked, this, &QtWindow::Add_Digit_1);
    connect(ui->Button2, &QPushButton::clicked, this, &QtWindow::Add_Digit_2);
    connect(ui->Button3, &QPushButton::clicked, this, &QtWindow::Add_Digit_3);
    connect(ui->Button4, &QPushButton::clicked, this, &QtWindow::Add_Digit_4);
    connect(ui->Button5, &QPushButton::clicked, this, &QtWindow::Add_Digit_5);
    connect(ui->Button6, &QPushButton::clicked, this, &QtWindow::Add_Digit_6);
    connect(ui->Button7, &QPushButton::clicked, this, &QtWindow::Add_Digit_7);
    connect(ui->Button8, &QPushButton::clicked, this, &QtWindow::Add_Digit_8);
    connect(ui->Button9, &QPushButton::clicked, this, &QtWindow::Add_Digit_9);
    connect(ui->ButtonPoint, &QPushButton::clicked, this, &QtWindow::Add_Point);
    connect(ui->ButtonDelete, &QPushButton::clicked, this, &QtWindow::Delete_Digit);

    // Кнопки выбора способа выплат кредита

    connect(ui->Annuitet, &QPushButton::clicked, this, &QtWindow::Set_Annuitet);
    connect(ui->Differentiated, &QPushButton::clicked, this, &QtWindow::Set_Differentiated);

    // Кнопка "Посчитать!"

    connect(ui->GetResult, &QPushButton::clicked, this, &QtWindow::Get_Result);

    connect(ui->LoanText, &QTextEdit::selectionChanged, this, &QtWindow::Set_Loan);
    connect(ui->PercentText, &QTextEdit::selectionChanged, this, &QtWindow::Set_Percent);
    connect(ui->TimeText, &QTextEdit::selectionChanged, this, &QtWindow::Set_Time);
}

void QtWindow::Set_Annuitet()
{
    result.Annuitet();
}

void QtWindow::Set_Differentiated()
{
    result.Differentiated();
}


void QtWindow::Set_Loan()
{
    isLoanSelected = true;
    isPercentSelected = false;
    isTimeSelected = false;
}

void QtWindow::Set_Percent()
{
    isLoanSelected = false;
    isPercentSelected = true;
    isTimeSelected = false;
}


void QtWindow::Set_Time()
{
    isLoanSelected = false;
    isPercentSelected = false;
    isTimeSelected = true;
}

void QtWindow::Reset_Text()
{
    ui->LoanText->setTextColor("#7c7c7c");
    ui->LoanText->setText(button.Reset_Loan());
    ui->PercentText->setTextColor("#7c7c7c");
    ui->PercentText->setText(button.Reset_Percent());
    ui->TimeText->setTextColor("#7c7c7c");
    ui->TimeText->setText(button.Reset_Time());
    ui->PayoutText->setText(button.Reset_Result());
    ui->OverpaymentText->setText("");
}

void QtWindow::Add_Digit_0()
{
    if (isLoanSelected)
    {
        ui->LoanText->setTextColor(QColor(0, 0, 0));
        ui->LoanText->setText(button.Add_Loan_0(ui->LoanText->toPlainText()));
    }
    if (isPercentSelected)
    {
        ui->PercentText->setTextColor(QColor(0, 0, 0));
        ui->PercentText->setText(button.Add_Percent_0(ui->PercentText->toPlainText()));
    }
    if (isTimeSelected)
    {
        ui->TimeText->setTextColor(QColor(0, 0, 0));
        ui->TimeText->setText(button.Add_Time_0(ui->TimeText->toPlainText()));
    }

}

void QtWindow::Add_Digit_1()
{
    if (isLoanSelected)
    {
        ui->LoanText->setTextColor(QColor(0, 0, 0));
        ui->LoanText->setText(button.Add_Loan_1(ui->LoanText->toPlainText()));
    }
    if (isPercentSelected)
    {
        ui->PercentText->setTextColor(QColor(0, 0, 0));
        ui->PercentText->setText(button.Add_Percent_1(ui->PercentText->toPlainText()));
    }
    if (isTimeSelected)
    {
        ui->TimeText->setTextColor(QColor(0, 0, 0));
        ui->TimeText->setText(button.Add_Time_1(ui->TimeText->toPlainText()));
    }
}

void QtWindow::Add_Digit_2()
{
    if (isLoanSelected)
    {
        ui->LoanText->setTextColor(QColor(0, 0, 0));
        ui->LoanText->setText(button.Add_Loan_2(ui->LoanText->toPlainText()));
    }
    if (isPercentSelected)
    {
        ui->PercentText->setTextColor(QColor(0, 0, 0));
        ui->PercentText->setText(button.Add_Percent_2(ui->PercentText->toPlainText()));
    }
    if (isTimeSelected)
    {
        ui->TimeText->setTextColor(QColor(0, 0, 0));
        ui->TimeText->setText(button.Add_Time_2(ui->TimeText->toPlainText()));
    }
}

void QtWindow::Add_Digit_3()
{
    if (isLoanSelected)
    {
        ui->LoanText->setTextColor(QColor(0, 0, 0));
        ui->LoanText->setText(button.Add_Loan_3(ui->LoanText->toPlainText()));
    }
    if (isPercentSelected)
    {
        ui->PercentText->setTextColor(QColor(0, 0, 0));
        ui->PercentText->setText(button.Add_Percent_3(ui->PercentText->toPlainText()));
    }
    if (isTimeSelected)
    {
        ui->TimeText->setTextColor(QColor(0, 0, 0));
        ui->TimeText->setText(button.Add_Time_3(ui->TimeText->toPlainText()));
    }
}

void QtWindow::Add_Digit_4()
{

    if (isLoanSelected)
    {
        ui->LoanText->setTextColor(QColor(0, 0, 0));
        ui->LoanText->setText(button.Add_Loan_4(ui->LoanText->toPlainText()));
    }
    if (isPercentSelected)
    {
        ui->PercentText->setTextColor(QColor(0, 0, 0));
        ui->PercentText->setText(button.Add_Percent_4(ui->PercentText->toPlainText()));
    }
    if (isTimeSelected)
    {
        ui->TimeText->setTextColor(QColor(0, 0, 0));
        ui->TimeText->setText(button.Add_Time_4(ui->TimeText->toPlainText()));
    }
}

void QtWindow::Add_Digit_5()
{

    if (isLoanSelected)
    {
        ui->LoanText->setTextColor(QColor(0, 0, 0));
        ui->LoanText->setText(button.Add_Loan_5(ui->LoanText->toPlainText()));
    }
    if (isPercentSelected)
    {
        ui->PercentText->setTextColor(QColor(0, 0, 0));
        ui->PercentText->setText(button.Add_Percent_5(ui->PercentText->toPlainText()));
    }
    if (isTimeSelected)
    {
        ui->TimeText->setTextColor(QColor(0, 0, 0));
        ui->TimeText->setText(button.Add_Time_5(ui->TimeText->toPlainText()));
    }
}

void QtWindow::Add_Digit_6()
{
    if (isLoanSelected)
    {
        ui->LoanText->setTextColor(QColor(0, 0, 0));
        ui->LoanText->setText(button.Add_Loan_6(ui->LoanText->toPlainText()));
    }
    if (isPercentSelected)
    {
        ui->PercentText->setTextColor(QColor(0, 0, 0));
        ui->PercentText->setText(button.Add_Percent_6(ui->PercentText->toPlainText()));
    }
    if (isTimeSelected)
    {
        ui->TimeText->setTextColor(QColor(0, 0, 0));
        ui->TimeText->setText(button.Add_Time_6(ui->TimeText->toPlainText()));
    }
}

void QtWindow::Add_Digit_7()
{
    if (isLoanSelected)
    {
        ui->LoanText->setTextColor(QColor(0, 0, 0));
        ui->LoanText->setText(button.Add_Loan_7(ui->LoanText->toPlainText()));
    }
    if (isPercentSelected)
    {
        ui->PercentText->setTextColor(QColor(0, 0, 0));
        ui->PercentText->setText(button.Add_Percent_7(ui->PercentText->toPlainText()));
    }
    if (isTimeSelected)
    {
        ui->TimeText->setTextColor(QColor(0, 0, 0));
        ui->TimeText->setText(button.Add_Time_7(ui->TimeText->toPlainText()));
    }
}

void QtWindow::Add_Digit_8()
{
    if (isLoanSelected)
    {
        ui->LoanText->setTextColor(QColor(0, 0, 0));
        ui->LoanText->setText(button.Add_Loan_8(ui->LoanText->toPlainText()));
    }
    if (isPercentSelected)
    {
        ui->PercentText->setTextColor(QColor(0, 0, 0));
        ui->PercentText->setText(button.Add_Percent_8(ui->PercentText->toPlainText()));
    }
    if (isTimeSelected)
    {
        ui->TimeText->setTextColor(QColor(0, 0, 0));
        ui->TimeText->setText(button.Add_Time_8(ui->TimeText->toPlainText()));
    }
}

void QtWindow::Add_Digit_9()
{
    if (isLoanSelected)
    {
        ui->LoanText->setTextColor(QColor(0, 0, 0));
        ui->LoanText->setText(button.Add_Loan_9(ui->LoanText->toPlainText()));
    }
    if (isPercentSelected)
    {
        ui->PercentText->setTextColor(QColor(0, 0, 0));
        ui->PercentText->setText(button.Add_Percent_9(ui->PercentText->toPlainText()));
    }
    if (isTimeSelected)
    {
        ui->TimeText->setTextColor(QColor(0, 0, 0));
        ui->TimeText->setText(button.Add_Time_9(ui->TimeText->toPlainText()));
    }
}

void QtWindow::Add_Point()
{
    if (isLoanSelected)
    {
        ui->LoanText->setText(button.Add_Point_Loan(ui->LoanText->toPlainText()));
    }
    if (isPercentSelected)
    {
        ui->PercentText->setText(button.Add_Point_Percent(ui->PercentText->toPlainText()));
    }
}

void QtWindow::Delete_Digit()
{
    QString row;
    if (isLoanSelected)
    {
        row = button.Delete_Loan(ui->LoanText->toPlainText());
        if (row == "Введите сумму кредита")
        {
            ui->LoanText->setTextColor("#7c7c7c");
            ui->LoanText->setText("Введите сумму кредита");
        }
        else
        {
            ui->LoanText->setText(row);
        }
    }
    if (isPercentSelected)
    {
        row = button.Delete_Percent(ui->PercentText->toPlainText());
        if (row == "Введите годовую ставку (%)")
        {
            ui->PercentText->setTextColor("#7c7c7c");
            ui->PercentText->setText("Введите годовую ставку (%)");
        }
        else
        {
            ui->PercentText->setText(row);
        }
    }
    if (isTimeSelected)
    {
        row = button.Delete_Time(ui->TimeText->toPlainText());
        if (row == "Введите кол-во месяцев для выплаты кредита")
        {
            ui->TimeText->setTextColor("#7c7c7c");
            ui->TimeText->setText("Введите кол-во месяцев для выплаты кредита");
        }
        else
        {
            ui->TimeText->setText(row);
        }
    }
}

void QtWindow::Get_Result()
{
    if (ui->LoanText->toPlainText().toDouble(&isConvert) && ui->PercentText->toPlainText().toFloat(&isConvert) && ui->TimeText->toPlainText().toInt(&isConvert, 10))
    {
        if (result.Get_Payout(ui->LoanText->toPlainText(), ui->PercentText->toPlainText(), ui->TimeText->toPlainText()) != "Выберите способ подсчёта!")
        {
            isLoanSelected = false;
            isPercentSelected = false;
            isTimeSelected = false;
            ui->statusbar->clearMessage();
            ui->PayoutText->setText(result.Get_Payout(ui->LoanText->toPlainText(), ui->PercentText->toPlainText(), ui->TimeText->toPlainText()));
            ui->OverpaymentText->setText(result.Get_Overpayment(ui->LoanText->toPlainText(), ui->PercentText->toPlainText(), ui->TimeText->toPlainText()));
        }
        else
        {
            ui->statusbar->showMessage("Выберите способ подсчёта!");
        }
    }
    else
    {
         ui->statusbar->showMessage("Заполните всё вводимые поля!");
    }
}

QtWindow::~QtWindow()
{
    delete ui;
}
