/********************************************************************************
** Form generated from reading UI file 'SetAlgorithm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETALGORITHM_H
#define UI_SETALGORITHM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetAlgorithm
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QGroupBox *groupBox_2;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QPushButton *pushButton_2;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QGroupBox *groupBox_4;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QGroupBox *groupBox_5;
    QTableView *tableView;

    void setupUi(QDialog *SetAlgorithm)
    {
        if (SetAlgorithm->objectName().isEmpty())
            SetAlgorithm->setObjectName(QStringLiteral("SetAlgorithm"));
        SetAlgorithm->resize(778, 512);
        groupBox = new QGroupBox(SetAlgorithm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 391, 241));
        groupBox->setStyleSheet(QLatin1String("QWidget{\n"
"border:1px solid#999999;\n"
"border -radius:15px; \n"
"\n"
"}"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 371, 211));
        label->setStyleSheet(QLatin1String("QWidget{\n"
"border:1px solid#999999;\n"
"border -radius:15px; \n"
"\n"
"}"));
        groupBox_2 = new QGroupBox(SetAlgorithm);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(420, 30, 341, 131));
        groupBox_2->setStyleSheet(QLatin1String("QWidget{\n"
"border:1px solid#999999;\n"
"border -radius:15px; \n"
"\n"
"}"));
        tableWidget = new QTableWidget(groupBox_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 321, 101));
        groupBox_3 = new QGroupBox(SetAlgorithm);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(420, 170, 341, 141));
        groupBox_3->setStyleSheet(QLatin1String("QWidget{\n"
"border:1px solid#999999;\n"
"border -radius:15px; \n"
"\n"
"}"));
        gridLayoutWidget = new QWidget(groupBox_3);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 321, 111));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_2 = new QRadioButton(gridLayoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 0, 1, 1, 1);

        radioButton = new QRadioButton(gridLayoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 1, 1, 1);

        horizontalSlider = new QSlider(gridLayoutWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 2, 0, 1, 2);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        groupBox_4 = new QGroupBox(SetAlgorithm);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 290, 391, 201));
        groupBox_4->setStyleSheet(QLatin1String("QWidget{\n"
"border:1px solid#999999;\n"
"border -radius:15px; \n"
"\n"
"}"));
        gridLayoutWidget_2 = new QWidget(groupBox_4);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 20, 391, 181));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(gridLayoutWidget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_2->addWidget(pushButton_4, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_2->addWidget(pushButton_5, 0, 1, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout_2->addWidget(pushButton_6, 2, 0, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_2->addWidget(pushButton_7, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout_2->addWidget(pushButton_8, 2, 2, 1, 1);

        groupBox_5 = new QGroupBox(SetAlgorithm);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(420, 330, 341, 161));
        groupBox_5->setStyleSheet(QLatin1String("QWidget{\n"
"border:1px solid#999999;\n"
"border -radius:15px; \n"
"\n"
"}"));
        tableView = new QTableView(groupBox_5);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 20, 321, 121));

        retranslateUi(SetAlgorithm);
        QObject::connect(pushButton_4, SIGNAL(clicked()), SetAlgorithm, SLOT(sintial()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), SetAlgorithm, SLOT(readhimage()));

        QMetaObject::connectSlotsByName(SetAlgorithm);
    } // setupUi

    void retranslateUi(QDialog *SetAlgorithm)
    {
        SetAlgorithm->setWindowTitle(QApplication::translate("SetAlgorithm", "SetAlgorithm", 0));
        groupBox->setTitle(QApplication::translate("SetAlgorithm", "1\345\233\276\347\211\207", 0));
        label->setText(QString());
        groupBox_2->setTitle(QApplication::translate("SetAlgorithm", "2\345\270\270\350\247\201\345\217\202\346\225\260", 0));
        groupBox_3->setTitle(QApplication::translate("SetAlgorithm", "3\347\211\271\345\256\232\345\217\202\346\225\260", 0));
        radioButton_2->setText(QApplication::translate("SetAlgorithm", "\347\231\275", 0));
        radioButton->setText(QApplication::translate("SetAlgorithm", "\351\273\221", 0));
        pushButton_2->setText(QApplication::translate("SetAlgorithm", "PushButton", 0));
        label_2->setText(QApplication::translate("SetAlgorithm", "\346\225\260\345\200\274\357\274\232", 0));
        groupBox_4->setTitle(QApplication::translate("SetAlgorithm", "4 \351\200\211\346\213\251\347\256\227\346\263\225", 0));
        pushButton_4->setText(QApplication::translate("SetAlgorithm", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_5->setText(QApplication::translate("SetAlgorithm", "\347\256\227\346\263\225\351\200\211\346\213\251", 0));
        pushButton_6->setText(QApplication::translate("SetAlgorithm", "\344\277\235\345\255\230\347\256\227\346\263\225", 0));
        pushButton_7->setText(QApplication::translate("SetAlgorithm", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("SetAlgorithm", "\346\230\276\347\244\272\347\273\223\346\236\234", 0));
        pushButton_8->setText(QApplication::translate("SetAlgorithm", "\350\257\273\345\217\226\345\233\276\347\211\207", 0));
        groupBox_5->setTitle(QApplication::translate("SetAlgorithm", "5 \347\273\223\346\236\234", 0));
    } // retranslateUi

};

namespace Ui {
    class SetAlgorithm: public Ui_SetAlgorithm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETALGORITHM_H
