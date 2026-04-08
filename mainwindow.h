#pragma once

#include "calculator.h"
#include "enums.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    //старые функции
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    //пишем заново
    // Методы обновления интерфейса
    void SetInputText(const std::string& text);
    void SetErrorText(const std::string& text);
    void SetFormulaText(const std::string& text);
    void SetMemText(const std::string& text);
    void SetExtraKey(const std::optional<std::string>& key);

    // Методы установки колбэк-функций
    void SetDigitKeyCallback(std::function<void(int key)> cb);
    void SetProcessOperationKeyCallback(std::function<void(Operation key)> cb);
    void SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb);
    void SetControllerCallback(std::function<void(ControllerType controller)> cb);

private slots:

    void on_pb_1_clicked();
    void on_pb_2_clicked();
    void on_pb_4_clicked();
    void on_pb_5_clicked();
    void on_pb_6_clicked();
    void on_pb_7_clicked();
    void on_pb_8_clicked();
    void on_pb_9_clicked();
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
    void on_tb_extra_clicked();
    void on_cmb_controller_currentIndexChanged(int index);


private:
    //пишем заново
    //Хранилища колбэков
    std::function<void(Operation key)> operation_cb_;
    std::function<void(int key)> digit_cb_;
    std::function<void(ControlKey key)> control_cb_;
    std::function<void(ControllerType controller)> controller_cb_;

    Ui::MainWindow* ui;
};
