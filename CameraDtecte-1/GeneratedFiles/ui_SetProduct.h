/********************************************************************************
** Form generated from reading UI file 'SetProduct.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPRODUCT_H
#define UI_SETPRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetProduct
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QGroupBox *groupBox_2;
    QWidget *widget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QWidget *widget_2;
    QComboBox *comboBox;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *widget_3;
    QComboBox *comboBox_2;
    QLabel *label_5;
    QPushButton *pushButton_8;
    QGroupBox *groupBox_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;

    void setupUi(QDialog *SetProduct)
    {
        if (SetProduct->objectName().isEmpty())
            SetProduct->setObjectName(QStringLiteral("SetProduct"));
        SetProduct->resize(614, 362);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \346\245\267\344\275\223 Std R"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        SetProduct->setFont(font);
        groupBox = new QGroupBox(SetProduct);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 80, 151, 261));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(170, 0, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        groupBox->setPalette(palette);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QLatin1String("QGroupBox{\n"
"border:1px solid#999999;\n"
"border -radius:15px; \n"
"\n"
"}"));
        groupBox->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 121, 61));
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 80, 121, 51));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QStringLiteral(""));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 200, 121, 51));
        pushButton_6->setFont(font);
        pushButton_6->setStyleSheet(QStringLiteral(""));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 140, 121, 51));
        pushButton_7->setFont(font);
        pushButton_7->setStyleSheet(QStringLiteral(""));
        groupBox_2 = new QGroupBox(SetProduct);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(190, 80, 401, 261));
        groupBox_2->setStyleSheet(QLatin1String("QGroupBox{\n"
"border:1px solid#999999;\n"
"border -radius:10px; \n"
"\n"
"}"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 371, 231));
        widget->setFont(font);
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QLatin1String("QWidget{\n"
"border:1px solid#999999;\n"
"border -radius:15px; \n"
"\n"
"}"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 111, 41));
        label->setFont(font);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 30, 171, 41));
        lineEdit->setFont(font);
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 140, 101, 51));
        pushButton_3->setFont(font);
        widget_2 = new QWidget(groupBox_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(10, 10, 371, 231));
        widget_2->setFont(font);
        widget_2->setStyleSheet(QLatin1String("QWidget{\n"
"border:1px solid#999999;\n"
"border -radius:15px; \n"
"\n"
"}"));
        comboBox = new QComboBox(widget_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 30, 181, 41));
        comboBox->setFont(font);
        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(220, 140, 141, 51));
        pushButton_4->setFont(font);
        pushButton_5 = new QPushButton(widget_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(50, 140, 121, 51));
        pushButton_5->setFont(font);
        widget_3 = new QWidget(groupBox_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(10, 10, 371, 231));
        comboBox_2 = new QComboBox(widget_3);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(190, 30, 161, 41));
        comboBox_2->setFont(font);
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 30, 111, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        label_5->setFont(font1);
        pushButton_8 = new QPushButton(widget_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(110, 150, 141, 51));
        pushButton_8->setFont(font);
        groupBox_3 = new QGroupBox(SetProduct);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 10, 561, 61));
        groupBox_3->setFont(font1);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 131, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        label_2->setFont(font2);
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 10, 151, 41));
        label_3->setFont(font2);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(290, 10, 111, 41));
        label_4->setFont(font1);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(400, 10, 151, 41));
        label_6->setFont(font2);
        groupBox_2->raise();
        groupBox->raise();
        groupBox_3->raise();
        QWidget::setTabOrder(pushButton_2, pushButton);
        QWidget::setTabOrder(pushButton, lineEdit);
        QWidget::setTabOrder(lineEdit, pushButton_3);
        QWidget::setTabOrder(pushButton_3, comboBox);
        QWidget::setTabOrder(comboBox, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_5);

        retranslateUi(SetProduct);
        QObject::connect(pushButton_5, SIGNAL(clicked()), SetProduct, SLOT(deleteproduct()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), SetProduct, SLOT(saveselectproduct()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), SetProduct, SLOT(selectproduct()));
        QObject::connect(pushButton, SIGNAL(clicked()), SetProduct, SLOT(newproduct()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), SetProduct, SLOT(savenewproduct()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), SetProduct, SLOT(reject()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), SetProduct, SLOT(selectRole()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), SetProduct, SLOT(saveselectRole()));

        QMetaObject::connectSlotsByName(SetProduct);
    } // setupUi

    void retranslateUi(QDialog *SetProduct)
    {
        SetProduct->setWindowTitle(QApplication::translate("SetProduct", "SetProduct", 0));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("SetProduct", "\346\226\260\344\272\247\345\223\201", 0));
        pushButton_2->setText(QApplication::translate("SetProduct", "\351\200\211\346\213\251\344\272\247\345\223\201", 0));
        pushButton_6->setText(QApplication::translate("SetProduct", "\351\200\200\345\207\272", 0));
        pushButton_7->setText(QApplication::translate("SetProduct", "\351\200\211\346\213\251\347\224\250\346\210\267", 0));
        groupBox_2->setTitle(QString());
        label->setText(QApplication::translate("SetProduct", "\344\272\247\345\223\201\345\220\215\347\247\260:", 0));
        pushButton_3->setText(QApplication::translate("SetProduct", "\344\277\235\345\255\230", 0));
        pushButton_4->setText(QApplication::translate("SetProduct", "\347\241\256\345\256\232", 0));
        pushButton_5->setText(QApplication::translate("SetProduct", "\345\210\240\351\231\244", 0));
        label_5->setText(QApplication::translate("SetProduct", "\351\200\211\346\213\251\347\224\250\346\210\267", 0));
        pushButton_8->setText(QApplication::translate("SetProduct", "\347\241\256\345\256\232", 0));
        groupBox_3->setTitle(QString());
        label_2->setText(QApplication::translate("SetProduct", "\345\275\223\345\211\215\344\272\247\345\223\201", 0));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("SetProduct", "\345\275\223\345\211\215\347\224\250\346\210\267", 0));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SetProduct: public Ui_SetProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPRODUCT_H
