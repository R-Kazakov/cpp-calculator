#pragma once

#include "calculator.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum class Operation {
    NO_OPERATION,    //операция не задана
    ADDITION,        //плюс
    SUBTRACTION,     //минус
    MULTIPLICATION,  //умножить
    DIVISION,        //поделить
    POWER            //возведение в степень
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void SetText(const QString& text);
    void AddText(const QString& suffix);
    QString RemoveTrailingZeroes(const QString &text);
    QString NormalizeNumber(const QString &text);
    QString OpToString(Operation op);
    void SetOperation(Operation op);
private slots:

    void on_pb_1_clicked();
    void on_pb_2_clicked();
    void on_pb_4_clicked();
    void on_pb_5_clicked();
    void on_pb_6_clicked();
    void on_pb_7_clicked();
    void on_pb_8_clicked();
    void on_pb_9_clicked();
    void on_pb_dot_clicked();
    void on_pb_sign_change_clicked();
    void on_pb_back_clicked();
    void on_pb_plus_clicked();
    void on_pb_minus_clicked();
    void on_pb_multiply_clicked();
    void on_pb_division_clicked();
    void on_pb_power_clicked();
    void on_pb_result_clicked();
    void on_pb_clear_clicked();
    void on_pb_open_saved_num_clicked();
    void on_pb_save_clicked();
    void on_pb_clear_memory_clicked();
    void on_pb_3_clicked();
    void on_pb_0_clicked();

private:
    Ui::MainWindow* ui;
    Calculator calculator_;
    QString input_number_;
    bool is_with_dot_=false;
    bool is_positive_=true;
    Number active_number_;
    Operation current_operation_ = Operation::NO_OPERATION;
    Number saved_number_;
    bool number_saved_=false;
};
