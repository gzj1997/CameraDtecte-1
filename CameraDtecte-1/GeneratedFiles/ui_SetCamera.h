/********************************************************************************
** Form generated from reading UI file 'SetCamera.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETCAMERA_H
#define UI_SETCAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetCamera
{
public:
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QGroupBox *groupBox_2;
    QWidget *widget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_gain;
    QLineEdit *lineEdit_pixie;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_name;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_expose;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QComboBox *comboBox;
    QGroupBox *groupBox_3;
    QLabel *label_picture;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *SetCamera)
    {
        if (SetCamera->objectName().isEmpty())
            SetCamera->setObjectName(QStringLiteral("SetCamera"));
        SetCamera->resize(652, 469);
        SetCamera->setStyleSheet(QStringLiteral(""));
        groupBox = new QGroupBox(SetCamera);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 621, 81));
        groupBox->setStyleSheet(QLatin1String("QWidget{\n"
"border:1px solid#999999;\n"
"border -radius:15px; \n"
"\n"
"}"));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 19, 601, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_1 = new QRadioButton(horizontalLayoutWidget);
        radioButton_1->setObjectName(QStringLiteral("radioButton_1"));

        horizontalLayout->addWidget(radioButton_1);

        radioButton_2 = new QRadioButton(horizontalLayoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(horizontalLayoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        horizontalLayout->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(horizontalLayoutWidget);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        horizontalLayout->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(horizontalLayoutWidget);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        horizontalLayout->addWidget(radioButton_5);

        radioButton_6 = new QRadioButton(horizontalLayoutWidget);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));

        horizontalLayout->addWidget(radioButton_6);

        groupBox_2 = new QGroupBox(SetCamera);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 100, 621, 201));
        groupBox_2->setStyleSheet(QLatin1String("QWidget{\n"
"border:1px solid#999999;\n"
"border -radius:15px; \n"
"\n"
"}"));
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 591, 171));
        gridLayoutWidget = new QWidget(widget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 591, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_gain = new QLineEdit(gridLayoutWidget);
        lineEdit_gain->setObjectName(QStringLiteral("lineEdit_gain"));

        gridLayout->addWidget(lineEdit_gain, 1, 1, 1, 1);

        lineEdit_pixie = new QLineEdit(gridLayoutWidget);
        lineEdit_pixie->setObjectName(QStringLiteral("lineEdit_pixie"));

        gridLayout->addWidget(lineEdit_pixie, 2, 1, 1, 1);

        lineEdit_4 = new QLineEdit(gridLayoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 1);

        lineEdit_name = new QLineEdit(gridLayoutWidget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 3, 2, 1, 1);

        lineEdit_expose = new QLineEdit(gridLayoutWidget);
        lineEdit_expose->setObjectName(QStringLiteral("lineEdit_expose"));

        gridLayout->addWidget(lineEdit_expose, 1, 3, 1, 1);

        lineEdit_7 = new QLineEdit(gridLayoutWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 2, 3, 1, 1);

        lineEdit_8 = new QLineEdit(gridLayoutWidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 3, 3, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 3, 1, 1);

        groupBox_3 = new QGroupBox(SetCamera);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 320, 611, 131));
        groupBox_3->setStyleSheet(QLatin1String("QWidget{\n"
"border:1px solid#999999;\n"
"border -radius:15px; \n"
"\n"
"}"));
        label_picture = new QLabel(groupBox_3);
        label_picture->setObjectName(QStringLiteral("label_picture"));
        label_picture->setGeometry(QRect(10, 20, 211, 101));
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(360, 30, 75, 23));
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 80, 75, 23));
        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(460, 30, 75, 23));
        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(460, 80, 75, 23));

        retranslateUi(SetCamera);
        QObject::connect(radioButton_1, SIGNAL(toggled(bool)), SetCamera, SLOT(getCCD(bool)));
        QObject::connect(pushButton, SIGNAL(clicked()), SetCamera, SLOT(onshot()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), SetCamera, SLOT(conshot()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), SetCamera, SLOT(stop()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), SetCamera, SLOT(saveset()));
        QObject::connect(lineEdit_gain, SIGNAL(editingFinished()), SetCamera, SLOT(changegain()));

        QMetaObject::connectSlotsByName(SetCamera);
    } // setupUi

    void retranslateUi(QDialog *SetCamera)
    {
        SetCamera->setWindowTitle(QApplication::translate("SetCamera", "SetCamera", 0));
        groupBox->setTitle(QApplication::translate("SetCamera", "\347\233\270\346\234\272", 0));
        radioButton_1->setText(QApplication::translate("SetCamera", "CCD1", 0));
        radioButton_2->setText(QApplication::translate("SetCamera", "CCD2", 0));
        radioButton_3->setText(QApplication::translate("SetCamera", "CCD3", 0));
        radioButton_4->setText(QApplication::translate("SetCamera", "CCD4", 0));
        radioButton_5->setText(QApplication::translate("SetCamera", "CCD5", 0));
        radioButton_6->setText(QApplication::translate("SetCamera", "CCD6", 0));
        groupBox_2->setTitle(QApplication::translate("SetCamera", "\345\217\202\346\225\260", 0));
        label->setText(QApplication::translate("SetCamera", "\350\256\276\345\244\207\345\220\215\345\255\227", 0));
        label_2->setText(QApplication::translate("SetCamera", "\345\242\236\347\233\212", 0));
        label_3->setText(QApplication::translate("SetCamera", "\345\203\217\347\264\240\346\257\224", 0));
        label_4->setText(QApplication::translate("SetCamera", "TextLabel", 0));
        label_5->setText(QApplication::translate("SetCamera", "\346\250\241\345\274\217", 0));
        label_6->setText(QApplication::translate("SetCamera", "\346\233\235\345\205\211", 0));
        label_7->setText(QApplication::translate("SetCamera", "TextLabel", 0));
        label_8->setText(QApplication::translate("SetCamera", "TextLabel", 0));
        groupBox_3->setTitle(QApplication::translate("SetCamera", "\346\213\215\346\221\204", 0));
        label_picture->setText(QApplication::translate("SetCamera", "TextLabel", 0));
        pushButton->setText(QApplication::translate("SetCamera", "\346\213\215\346\221\204\344\270\200\346\254\241", 0));
        pushButton_2->setText(QApplication::translate("SetCamera", "\350\277\236\347\273\255\346\213\215\346\221\204", 0));
        pushButton_3->setText(QApplication::translate("SetCamera", "\345\201\234\346\255\242", 0));
        pushButton_4->setText(QApplication::translate("SetCamera", "\344\277\235\345\255\230", 0));
    } // retranslateUi

};

namespace Ui {
    class SetCamera: public Ui_SetCamera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETCAMERA_H
