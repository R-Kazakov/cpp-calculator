#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->l_result->setText("0");
    ui->l_memory->setText("");
    ui->l_formula->setText("");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SetText(const QString& text){
    QString text_removed_trailing_zeros= RemoveTrailingZeroes(text);
    QString normal_number = NormalizeNumber(text_removed_trailing_zeros);
    input_number_=normal_number;
    ui->l_result->setText(input_number_);
    active_number_=input_number_.toDouble();
}

void MainWindow::SetOperation(Operation op){
    if(current_operation_ == Operation::NO_OPERATION){
        calculator_.Set(active_number_);
    }
    current_operation_=op;
    Number num = calculator_.GetNumber();
    QString operation = OpToString(op);
    QString formula_out="%1 %2";
    QString formatted_formula=formula_out.arg(num).arg(operation);
    ui->l_formula->setText(formatted_formula);
    input_number_="";
    //ui->l_result->setText(input_number_);                     //нужная ли эта строка?
}

void MainWindow::AddText(const QString& suffix){
    input_number_+=suffix;
    SetText(input_number_);
}

void MainWindow::on_pb_1_clicked(){
    AddText("1");
}

void MainWindow::on_pb_2_clicked(){
    AddText("2");
}

void MainWindow::on_pb_3_clicked()
{
    AddText("3");
}

void MainWindow::on_pb_4_clicked(){
    AddText("4");
}

void MainWindow::on_pb_5_clicked(){
    AddText("5");
}

void MainWindow::on_pb_6_clicked(){
    AddText("6");
}

void MainWindow::on_pb_7_clicked(){
    AddText("7");
}

void MainWindow::on_pb_8_clicked(){
    AddText("8");
}

void MainWindow::on_pb_9_clicked(){
    AddText("9");
}

void MainWindow::on_pb_0_clicked()
{
    AddText("0");
}

void MainWindow::on_pb_dot_clicked(){
    if (is_with_dot_==true){
        return;
    } else {
        AddText(".");
        is_with_dot_=true;
    }

}

void MainWindow::on_pb_sign_change_clicked(){
    if(input_number_.startsWith("-")){
        SetText(input_number_.mid(1));
    } else{
        input_number_.push_front("-");
        SetText(input_number_);
    }
}

void MainWindow::on_pb_back_clicked(){
    if(!input_number_.isEmpty()){
        input_number_.chop(1);
        SetText(input_number_);
    }
}

QString MainWindow::RemoveTrailingZeroes(const QString &text) {
    for (qsizetype i = 0; i < text.size(); ++i) {
        if (text[i] != '0') {
            return text.mid(i);
        }
    }
    return "";
}

QString MainWindow::NormalizeNumber(const QString &text) {
    if (text.isEmpty()) {
        return "0";
    }
    if (text.startsWith('.')) {
        // Рекурсивный вызов.
        return NormalizeNumber("0" + text);
    }
    if (text.startsWith('-')) {
        // Рекурсивный вызов.
        return "-" + NormalizeNumber(text.mid(1));
    }
    if (text.startsWith('0') && !text.startsWith("0.")) {
        return NormalizeNumber(RemoveTrailingZeroes(text));
    }
    return text;
}

QString MainWindow::OpToString(Operation op) {
    switch(op) {
    case Operation::NO_OPERATION: return "";
    case Operation::ADDITION: return "+";
    case Operation::DIVISION: return "÷";
    case Operation::MULTIPLICATION: return "×";
    case Operation::SUBTRACTION: return "−";
    case Operation::POWER: return "^";
    }
}

void MainWindow::on_pb_plus_clicked(){
    SetOperation(Operation::ADDITION);
}

void MainWindow::on_pb_minus_clicked(){
    SetOperation(Operation::SUBTRACTION);
}

void MainWindow::on_pb_multiply_clicked(){
    SetOperation(Operation::MULTIPLICATION);
}

void MainWindow::on_pb_division_clicked(){
    SetOperation(Operation::DIVISION);
}

void MainWindow::on_pb_power_clicked(){
    SetOperation(Operation::POWER);
}

void MainWindow::on_pb_result_clicked(){
    if(current_operation_ == Operation::NO_OPERATION){
        return;
    } else {
        Number num = calculator_.GetNumber();
        QString operation = OpToString(current_operation_);
        QString formula_out="%1 %2 %3 =";
        QString formatted_formula=formula_out.arg(num).arg(operation).arg(active_number_);
        ui->l_formula->setText(formatted_formula);
        switch(current_operation_) {
        case Operation::ADDITION:
            calculator_.Add(active_number_);
            break;
        case Operation::DIVISION:
            calculator_.Div(active_number_);
            break;
        case Operation::MULTIPLICATION:
            calculator_.Mul(active_number_);
            break;
        case Operation::SUBTRACTION:
            calculator_.Sub(active_number_);
            break;
        case Operation::POWER:
            calculator_.Pow(active_number_);
            break;
        default:break;
        }
        active_number_=calculator_.GetNumber();
        ui->l_result->setText(QString::number(active_number_));
        input_number_="";
        current_operation_=Operation::NO_OPERATION;
    }
}

void MainWindow::on_pb_clear_clicked(){
    current_operation_=Operation::NO_OPERATION;
    ui->l_formula->setText("");
    SetText("0");
}

void MainWindow::on_pb_open_saved_num_clicked(){
    if(number_saved_){
        active_number_=saved_number_;
        ui->l_result->setText(QString::number(saved_number_));
        input_number_="";
    } else{
        return;
    }
}

void MainWindow::on_pb_save_clicked(){
    saved_number_=active_number_;
    ui->l_memory->setText("M");
    number_saved_=true;
}

void MainWindow::on_pb_clear_memory_clicked(){
    saved_number_=0;
    ui->l_memory->setText("");
    number_saved_=false;
}

