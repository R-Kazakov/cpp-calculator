/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *l_memory;
    QLabel *l_result;
    QPushButton *pb_9;
    QPushButton *pb_open_saved_num;
    QPushButton *pb_power;
    QPushButton *pb_1;
    QPushButton *pb_3;
    QPushButton *pb_save;
    QPushButton *pb_5;
    QPushButton *pb_4;
    QPushButton *pb_minus;
    QPushButton *pb_result;
    QPushButton *pb_0;
    QPushButton *pb_multiply;
    QPushButton *pb_dot;
    QPushButton *pb_7;
    QLabel *l_formula;
    QPushButton *pb_clear_memory;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_sign_change;
    QPushButton *pb_2;
    QPushButton *pb_8;
    QSpacerItem *verticalSpacer;
    QPushButton *pb_division;
    QPushButton *pb_clear;
    QPushButton *pb_plus;
    QPushButton *pb_6;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pb_back;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(520, 456);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(20);
        horizontalLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        horizontalLayout->setSpacing(-1);
#endif
        horizontalLayout->setObjectName("horizontalLayout");
        l_memory = new QLabel(centralwidget);
        l_memory->setObjectName("l_memory");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(l_memory->sizePolicy().hasHeightForWidth());
        l_memory->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(l_memory);

        l_result = new QLabel(centralwidget);
        l_result->setObjectName("l_result");
        sizePolicy1.setHeightForWidth(l_result->sizePolicy().hasHeightForWidth());
        l_result->setSizePolicy(sizePolicy1);
        l_result->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(l_result);

        horizontalLayout->setStretch(0, 7);
        horizontalLayout->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 5);

        pb_9 = new QPushButton(centralwidget);
        pb_9->setObjectName("pb_9");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pb_9->sizePolicy().hasHeightForWidth());
        pb_9->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_9, 6, 2, 1, 1);

        pb_open_saved_num = new QPushButton(centralwidget);
        pb_open_saved_num->setObjectName("pb_open_saved_num");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pb_open_saved_num->sizePolicy().hasHeightForWidth());
        pb_open_saved_num->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(pb_open_saved_num, 3, 1, 1, 1);

        pb_power = new QPushButton(centralwidget);
        pb_power->setObjectName("pb_power");
        sizePolicy2.setHeightForWidth(pb_power->sizePolicy().hasHeightForWidth());
        pb_power->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_power, 3, 4, 1, 1);

        pb_1 = new QPushButton(centralwidget);
        pb_1->setObjectName("pb_1");
        sizePolicy2.setHeightForWidth(pb_1->sizePolicy().hasHeightForWidth());
        pb_1->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_1, 8, 0, 1, 1);

        pb_3 = new QPushButton(centralwidget);
        pb_3->setObjectName("pb_3");
        sizePolicy2.setHeightForWidth(pb_3->sizePolicy().hasHeightForWidth());
        pb_3->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_3, 8, 2, 1, 1);

        pb_save = new QPushButton(centralwidget);
        pb_save->setObjectName("pb_save");
        sizePolicy.setHeightForWidth(pb_save->sizePolicy().hasHeightForWidth());
        pb_save->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pb_save, 3, 2, 1, 1);

        pb_5 = new QPushButton(centralwidget);
        pb_5->setObjectName("pb_5");
        sizePolicy2.setHeightForWidth(pb_5->sizePolicy().hasHeightForWidth());
        pb_5->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_5, 7, 1, 1, 1);

        pb_4 = new QPushButton(centralwidget);
        pb_4->setObjectName("pb_4");
        sizePolicy2.setHeightForWidth(pb_4->sizePolicy().hasHeightForWidth());
        pb_4->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_4, 7, 0, 1, 1);

        pb_minus = new QPushButton(centralwidget);
        pb_minus->setObjectName("pb_minus");
        sizePolicy2.setHeightForWidth(pb_minus->sizePolicy().hasHeightForWidth());
        pb_minus->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_minus, 7, 4, 1, 1);

        pb_result = new QPushButton(centralwidget);
        pb_result->setObjectName("pb_result");
        sizePolicy2.setHeightForWidth(pb_result->sizePolicy().hasHeightForWidth());
        pb_result->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_result, 9, 4, 1, 1);

        pb_0 = new QPushButton(centralwidget);
        pb_0->setObjectName("pb_0");
        sizePolicy2.setHeightForWidth(pb_0->sizePolicy().hasHeightForWidth());
        pb_0->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_0, 9, 1, 1, 1);

        pb_multiply = new QPushButton(centralwidget);
        pb_multiply->setObjectName("pb_multiply");
        sizePolicy2.setHeightForWidth(pb_multiply->sizePolicy().hasHeightForWidth());
        pb_multiply->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_multiply, 6, 4, 1, 1);

        pb_dot = new QPushButton(centralwidget);
        pb_dot->setObjectName("pb_dot");
        sizePolicy2.setHeightForWidth(pb_dot->sizePolicy().hasHeightForWidth());
        pb_dot->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_dot, 9, 0, 1, 1);

        pb_7 = new QPushButton(centralwidget);
        pb_7->setObjectName("pb_7");
        sizePolicy2.setHeightForWidth(pb_7->sizePolicy().hasHeightForWidth());
        pb_7->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_7, 6, 0, 1, 1);

        l_formula = new QLabel(centralwidget);
        l_formula->setObjectName("l_formula");
        sizePolicy1.setHeightForWidth(l_formula->sizePolicy().hasHeightForWidth());
        l_formula->setSizePolicy(sizePolicy1);
        l_formula->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(l_formula, 0, 4, 1, 1);

        pb_clear_memory = new QPushButton(centralwidget);
        pb_clear_memory->setObjectName("pb_clear_memory");
        sizePolicy3.setHeightForWidth(pb_clear_memory->sizePolicy().hasHeightForWidth());
        pb_clear_memory->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(pb_clear_memory, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 3, 1, 1);

        pb_sign_change = new QPushButton(centralwidget);
        pb_sign_change->setObjectName("pb_sign_change");
        sizePolicy2.setHeightForWidth(pb_sign_change->sizePolicy().hasHeightForWidth());
        pb_sign_change->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_sign_change, 5, 2, 1, 1);

        pb_2 = new QPushButton(centralwidget);
        pb_2->setObjectName("pb_2");
        sizePolicy2.setHeightForWidth(pb_2->sizePolicy().hasHeightForWidth());
        pb_2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_2, 8, 1, 1, 1);

        pb_8 = new QPushButton(centralwidget);
        pb_8->setObjectName("pb_8");
        sizePolicy2.setHeightForWidth(pb_8->sizePolicy().hasHeightForWidth());
        pb_8->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_8, 6, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 3, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        pb_division = new QPushButton(centralwidget);
        pb_division->setObjectName("pb_division");
        sizePolicy2.setHeightForWidth(pb_division->sizePolicy().hasHeightForWidth());
        pb_division->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_division, 5, 4, 1, 1);

        pb_clear = new QPushButton(centralwidget);
        pb_clear->setObjectName("pb_clear");
        sizePolicy2.setHeightForWidth(pb_clear->sizePolicy().hasHeightForWidth());
        pb_clear->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_clear, 5, 0, 1, 2);

        pb_plus = new QPushButton(centralwidget);
        pb_plus->setObjectName("pb_plus");
        sizePolicy2.setHeightForWidth(pb_plus->sizePolicy().hasHeightForWidth());
        pb_plus->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_plus, 8, 4, 1, 1);

        pb_6 = new QPushButton(centralwidget);
        pb_6->setObjectName("pb_6");
        sizePolicy2.setHeightForWidth(pb_6->sizePolicy().hasHeightForWidth());
        pb_6->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_6, 7, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 3, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 1);

        pb_back = new QPushButton(centralwidget);
        pb_back->setObjectName("pb_back");
        sizePolicy2.setHeightForWidth(pb_back->sizePolicy().hasHeightForWidth());
        pb_back->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb_back, 9, 2, 1, 1);

        gridLayout->setRowStretch(0, 3);
        gridLayout->setRowStretch(1, 2);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 2);
        gridLayout->setRowStretch(4, 2);
        gridLayout->setRowStretch(5, 3);
        gridLayout->setRowStretch(6, 3);
        gridLayout->setRowStretch(7, 3);
        gridLayout->setRowStretch(8, 3);
        gridLayout->setRowStretch(9, 3);
        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 2);
        gridLayout->setColumnStretch(4, 3);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        l_memory->setText(QCoreApplication::translate("MainWindow", "l_memory", nullptr));
        l_result->setText(QCoreApplication::translate("MainWindow", "l_result", nullptr));
        pb_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pb_open_saved_num->setText(QCoreApplication::translate("MainWindow", "MR", nullptr));
        pb_power->setText(QCoreApplication::translate("MainWindow", "x\312\270", nullptr));
        pb_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pb_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pb_save->setText(QCoreApplication::translate("MainWindow", "MS", nullptr));
        pb_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pb_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pb_minus->setText(QCoreApplication::translate("MainWindow", "\342\210\222", nullptr));
        pb_result->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pb_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pb_multiply->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        pb_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pb_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        l_formula->setText(QCoreApplication::translate("MainWindow", "l_formula", nullptr));
        pb_clear_memory->setText(QCoreApplication::translate("MainWindow", "MC", nullptr));
        pb_sign_change->setText(QCoreApplication::translate("MainWindow", "\302\261", nullptr));
        pb_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pb_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pb_division->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        pb_clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pb_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pb_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pb_back->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
