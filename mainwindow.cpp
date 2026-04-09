#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QComboBox>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    ui = new Ui::MainWindow;
    ui->setupUi(this);
    // ui->setupUi(this) автоматически подключает сигналы кнопок к on_<object>_clicked().
    connect(ui->cmb_controller, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_cmb_controller_currentIndexChanged);
}

MainWindow::~MainWindow() {
    delete ui;
}

// Методы обновления UI
void MainWindow::SetInputText(const std::string& text) {
    ui->l_result->setStyleSheet(""); // Сброс цвета при обычном выводе
    ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetErrorText(const std::string& text) {
    ui->l_result->setStyleSheet("color: red;");
    ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetFormulaText(const std::string& text) {
    ui->l_formula->setText(QString::fromStdString(text));
}

void MainWindow::SetMemText(const std::string& text) {
    ui->l_memory->setText(QString::fromStdString(text));
}

void MainWindow::SetExtraKey(const std::optional<std::string>& key) {
    if (key.has_value()) {
        ui->tb_extra->setText(QString::fromStdString(*key));
        ui->tb_extra->setVisible(true);
    } else {
        ui->tb_extra->setVisible(false);
    }
}

// Методы установки колбэков
void MainWindow::SetDigitKeyCallback(std::function<void(int key)> cb) {
    digit_cb_ = cb;
}
void MainWindow::SetProcessOperationKeyCallback(std::function<void(Operation key)> cb) {
    operation_cb_ = cb;
}
void MainWindow::SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb) {
    control_cb_ = cb;
}
void MainWindow::SetControllerCallback(std::function<void(ControllerType controller)> cb) {
    controller_cb_ = cb;
}

// ─── Слоты кнопок (только диспетчеризация в контроллер) ──────────────────────────
void MainWindow::on_pb_0_clicked() {
    if (digit_cb_){
        digit_cb_(0);
    }
}
void MainWindow::on_pb_1_clicked() {
    if (digit_cb_){
        digit_cb_(1);
    }
}
void MainWindow::on_pb_2_clicked() {
    if (digit_cb_){
        digit_cb_(2);
    }
}
void MainWindow::on_pb_3_clicked() {
    if (digit_cb_){
        digit_cb_(3);
    }
}
void MainWindow::on_pb_4_clicked() {
    if (digit_cb_){
        digit_cb_(4);
    }
}
void MainWindow::on_pb_5_clicked() {
    if (digit_cb_){
        digit_cb_(5);
    }
}
void MainWindow::on_pb_6_clicked() {
    if (digit_cb_){
        digit_cb_(6);
    }
}
void MainWindow::on_pb_7_clicked() {
    if (digit_cb_){
        digit_cb_(7);
    }
}
void MainWindow::on_pb_8_clicked() {
    if (digit_cb_){
        digit_cb_(8);
    }
}
void MainWindow::on_pb_9_clicked() {
    if (digit_cb_){
        digit_cb_(9);
    }
}

void MainWindow::on_pb_plus_clicked() {
    if (operation_cb_){
        operation_cb_(Operation::ADDITION);
    }
}
void MainWindow::on_pb_minus_clicked() {
    if (operation_cb_){
        operation_cb_(Operation::SUBTRACTION);
    }
}
void MainWindow::on_pb_multiply_clicked() {
    if (operation_cb_){
        operation_cb_(Operation::MULTIPLICATION);
    }
}
void MainWindow::on_pb_division_clicked() {
    if (operation_cb_){
        operation_cb_(Operation::DIVISION);
    }
}
void MainWindow::on_pb_power_clicked() {
    if (operation_cb_){
        operation_cb_(Operation::POWER);
    }
}

void MainWindow::on_pb_result_clicked() {
    if (control_cb_){
        control_cb_(ControlKey::EQUALS);
    }
}
void MainWindow::on_pb_clear_clicked()  {
    if (control_cb_){
        control_cb_(ControlKey::CLEAR);
    }
}
void MainWindow::on_pb_sign_change_clicked() {
    if (control_cb_){
        control_cb_(ControlKey::PLUS_MINUS);
    }
}
void MainWindow::on_pb_back_clicked() {
    if (control_cb_){
        control_cb_(ControlKey::BACKSPACE);
    }
}
void MainWindow::on_pb_open_saved_num_clicked() {
    if (control_cb_){
        control_cb_(ControlKey::MEM_LOAD);
    }
}
void MainWindow::on_pb_save_clicked() {
    if (control_cb_){
        control_cb_(ControlKey::MEM_SAVE);
    }
}
void MainWindow::on_pb_clear_memory_clicked() {
    if (control_cb_){
        control_cb_(ControlKey::MEM_CLEAR);
    }
}
void MainWindow::on_tb_extra_clicked(){
    if (control_cb_){
        control_cb_(ControlKey::EXTRA_KEY);
    }
}

void MainWindow::on_cmb_controller_currentIndexChanged(int index){
    if (!controller_cb_) return;
    ControllerType type;
    switch (index) {
    case 0: type = ControllerType::DOUBLE; break;
    case 1: type = ControllerType::FLOAT; break;
    case 2: type = ControllerType::UINT8_T; break;
    case 3: type = ControllerType::INT; break;
    case 4: type = ControllerType::INT64_T; break;
    case 5: type = ControllerType::SIZE_T; break;
    case 6: type = ControllerType::RATIONAL; break;
    default: return;
    }
    controller_cb_(type);
}
