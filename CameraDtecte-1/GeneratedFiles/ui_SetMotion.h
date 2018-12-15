/********************************************************************************
** Form generated from reading UI file 'SetMotion.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETMOTION_H
#define UI_SETMOTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetMotion
{
public:
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButton_in1;
    QToolButton *toolButton_in2;
    QToolButton *toolButton_in3;
    QToolButton *toolButton_in4;
    QToolButton *toolButton_14;
    QToolButton *toolButton_15;
    QToolButton *toolButton_16;
    QToolButton *toolButton_17;
    QGroupBox *groupBox_2;
    QDial *dial;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonplus;
    QRadioButton *radioButtondiv;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QToolButton *toolButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_3;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton_out1;
    QToolButton *toolButton_out2;
    QToolButton *toolButton_out3;
    QToolButton *toolButton_out4;
    QToolButton *toolButton_out5;
    QToolButton *toolButton_9;
    QToolButton *toolButton_7;
    QToolButton *toolButton_5;

    void setupUi(QDialog *SetMotion)
    {
        if (SetMotion->objectName().isEmpty())
            SetMotion->setObjectName(QStringLiteral("SetMotion"));
        SetMotion->resize(675, 416);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \346\245\267\344\275\223 Std R"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        SetMotion->setFont(font);
        SetMotion->setStyleSheet(QStringLiteral("QToolButton{border-style: flat;}"));
        groupBox = new QGroupBox(SetMotion);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 631, 91));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QLatin1String("QGroupBox{\n"
"border:1px solid#999999;\n"
"border -radius:15px; \n"
"\n"
"}"));
        horizontalLayoutWidget_4 = new QWidget(groupBox);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(0, 30, 631, 61));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        toolButton_in1 = new QToolButton(horizontalLayoutWidget_4);
        toolButton_in1->setObjectName(QStringLiteral("toolButton_in1"));
        toolButton_in1->setStyleSheet(QStringLiteral("border-style: flat;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/CameraDtecte1/Resources/red.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_in1->setIcon(icon);
        toolButton_in1->setIconSize(QSize(40, 40));
        toolButton_in1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(toolButton_in1);

        toolButton_in2 = new QToolButton(horizontalLayoutWidget_4);
        toolButton_in2->setObjectName(QStringLiteral("toolButton_in2"));
        toolButton_in2->setStyleSheet(QStringLiteral("border-style: flat;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/CameraDtecte1/Resources/green.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_in2->setIcon(icon1);
        toolButton_in2->setIconSize(QSize(40, 40));
        toolButton_in2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(toolButton_in2);

        toolButton_in3 = new QToolButton(horizontalLayoutWidget_4);
        toolButton_in3->setObjectName(QStringLiteral("toolButton_in3"));
        toolButton_in3->setStyleSheet(QStringLiteral("border-style: flat;"));
        toolButton_in3->setIcon(icon);
        toolButton_in3->setIconSize(QSize(40, 40));
        toolButton_in3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(toolButton_in3);

        toolButton_in4 = new QToolButton(horizontalLayoutWidget_4);
        toolButton_in4->setObjectName(QStringLiteral("toolButton_in4"));
        toolButton_in4->setStyleSheet(QStringLiteral("border-style: flat;"));
        toolButton_in4->setIcon(icon);
        toolButton_in4->setIconSize(QSize(40, 40));
        toolButton_in4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(toolButton_in4);

        toolButton_14 = new QToolButton(horizontalLayoutWidget_4);
        toolButton_14->setObjectName(QStringLiteral("toolButton_14"));
        toolButton_14->setStyleSheet(QStringLiteral("border-style: flat;"));
        toolButton_14->setIcon(icon);
        toolButton_14->setIconSize(QSize(40, 40));
        toolButton_14->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(toolButton_14);

        toolButton_15 = new QToolButton(horizontalLayoutWidget_4);
        toolButton_15->setObjectName(QStringLiteral("toolButton_15"));
        toolButton_15->setStyleSheet(QStringLiteral("border-style: flat;"));
        toolButton_15->setIcon(icon);
        toolButton_15->setIconSize(QSize(40, 40));
        toolButton_15->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(toolButton_15);

        toolButton_16 = new QToolButton(horizontalLayoutWidget_4);
        toolButton_16->setObjectName(QStringLiteral("toolButton_16"));
        toolButton_16->setStyleSheet(QStringLiteral("border-style: flat;"));
        toolButton_16->setIcon(icon);
        toolButton_16->setIconSize(QSize(40, 40));
        toolButton_16->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(toolButton_16);

        toolButton_17 = new QToolButton(horizontalLayoutWidget_4);
        toolButton_17->setObjectName(QStringLiteral("toolButton_17"));
        toolButton_17->setStyleSheet(QStringLiteral("border-style: flat;"));
        toolButton_17->setIcon(icon);
        toolButton_17->setIconSize(QSize(40, 40));
        toolButton_17->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(toolButton_17);

        groupBox_2 = new QGroupBox(SetMotion);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 220, 631, 181));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QLatin1String("QGroupBox{\n"
"border:1px solid#999999;\n"
"border -radius:15px; \n"
"\n"
"}"));
        dial = new QDial(groupBox_2);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(160, 10, 151, 121));
        verticalLayoutWidget = new QWidget(groupBox_2);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 40, 91, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_1 = new QRadioButton(verticalLayoutWidget);
        radioButton_1->setObjectName(QStringLiteral("radioButton_1"));

        verticalLayout->addWidget(radioButton_1);

        radioButton_2 = new QRadioButton(verticalLayoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 140, 41, 31));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(190, 140, 121, 31));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 140, 141, 31));
        horizontalLayoutWidget = new QWidget(groupBox_2);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(350, 20, 131, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButtonplus = new QRadioButton(horizontalLayoutWidget);
        radioButtonplus->setObjectName(QStringLiteral("radioButtonplus"));

        horizontalLayout->addWidget(radioButtonplus);

        radioButtondiv = new QRadioButton(horizontalLayoutWidget);
        radioButtondiv->setObjectName(QStringLiteral("radioButtondiv"));

        horizontalLayout->addWidget(radioButtondiv);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 90, 41, 31));
        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(390, 90, 81, 31));
        toolButton = new QToolButton(groupBox_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(510, 10, 101, 101));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/CameraDtecte1/Resources/\345\205\254\345\217\270LOG.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon2);
        toolButton->setIconSize(QSize(160, 160));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton->setAutoRaise(false);
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 140, 101, 31));
        groupBox_3 = new QGroupBox(SetMotion);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 110, 631, 101));
        groupBox_3->setFont(font);
        groupBox_3->setStyleSheet(QLatin1String("QGroupBox{\n"
"border:1px solid#999999;\n"
"border -radius:15px; \n"
"\n"
"}"));
        horizontalLayoutWidget_3 = new QWidget(groupBox_3);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 30, 631, 71));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        toolButton_out1 = new QToolButton(horizontalLayoutWidget_3);
        toolButton_out1->setObjectName(QStringLiteral("toolButton_out1"));
        toolButton_out1->setStyleSheet(QStringLiteral("border-style: flat;"));
        toolButton_out1->setIcon(icon);
        toolButton_out1->setIconSize(QSize(40, 40));
        toolButton_out1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(toolButton_out1);

        toolButton_out2 = new QToolButton(horizontalLayoutWidget_3);
        toolButton_out2->setObjectName(QStringLiteral("toolButton_out2"));
        toolButton_out2->setStyleSheet(QStringLiteral("border-style: flat;"));
        toolButton_out2->setIcon(icon1);
        toolButton_out2->setIconSize(QSize(40, 40));
        toolButton_out2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(toolButton_out2);

        toolButton_out3 = new QToolButton(horizontalLayoutWidget_3);
        toolButton_out3->setObjectName(QStringLiteral("toolButton_out3"));
        toolButton_out3->setStyleSheet(QStringLiteral("border-style: flat;"));
        toolButton_out3->setIcon(icon);
        toolButton_out3->setIconSize(QSize(40, 40));
        toolButton_out3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(toolButton_out3);

        toolButton_out4 = new QToolButton(horizontalLayoutWidget_3);
        toolButton_out4->setObjectName(QStringLiteral("toolButton_out4"));
        toolButton_out4->setStyleSheet(QStringLiteral("border-style: flat;"));
        toolButton_out4->setIcon(icon);
        toolButton_out4->setIconSize(QSize(40, 40));
        toolButton_out4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(toolButton_out4);

        toolButton_out5 = new QToolButton(horizontalLayoutWidget_3);
        toolButton_out5->setObjectName(QStringLiteral("toolButton_out5"));
        toolButton_out5->setStyleSheet(QStringLiteral("border-style: flat;"));
        toolButton_out5->setIcon(icon);
        toolButton_out5->setIconSize(QSize(40, 40));
        toolButton_out5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(toolButton_out5);

        toolButton_9 = new QToolButton(horizontalLayoutWidget_3);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        toolButton_9->setStyleSheet(QStringLiteral("border-style: flat;"));
        toolButton_9->setIcon(icon);
        toolButton_9->setIconSize(QSize(40, 40));
        toolButton_9->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(toolButton_9);

        toolButton_7 = new QToolButton(horizontalLayoutWidget_3);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setStyleSheet(QStringLiteral("border-style: flat;"));
        toolButton_7->setIcon(icon);
        toolButton_7->setIconSize(QSize(40, 40));
        toolButton_7->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(toolButton_7);

        toolButton_5 = new QToolButton(horizontalLayoutWidget_3);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setStyleSheet(QStringLiteral("border-style: flat;"));
        toolButton_5->setIcon(icon);
        toolButton_5->setIconSize(QSize(40, 40));
        toolButton_5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(toolButton_5);


        retranslateUi(SetMotion);
        QObject::connect(toolButton_out1, SIGNAL(clicked()), SetMotion, SLOT(changestate()));
        QObject::connect(toolButton_out2, SIGNAL(clicked()), SetMotion, SLOT(changestate()));
        QObject::connect(toolButton_out3, SIGNAL(clicked()), SetMotion, SLOT(changestate()));
        QObject::connect(toolButton_out4, SIGNAL(clicked()), SetMotion, SLOT(changestate()));
        QObject::connect(radioButton_1, SIGNAL(toggled(bool)), SetMotion, SLOT(getmachinery(bool)));
        QObject::connect(radioButton_2, SIGNAL(toggled(bool)), SetMotion, SLOT(getmachinery(bool)));
        QObject::connect(dial, SIGNAL(valueChanged(int)), SetMotion, SLOT(getspeed()));
        QObject::connect(pushButton, SIGNAL(clicked()), SetMotion, SLOT(startmotion()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), SetMotion, SLOT(savequit()));

        QMetaObject::connectSlotsByName(SetMotion);
    } // setupUi

    void retranslateUi(QDialog *SetMotion)
    {
        SetMotion->setWindowTitle(QApplication::translate("SetMotion", "SetMotion", 0));
        groupBox->setTitle(QApplication::translate("SetMotion", "IO input", 0));
        toolButton_in1->setText(QApplication::translate("SetMotion", "1", 0));
        toolButton_in2->setText(QApplication::translate("SetMotion", "2", 0));
        toolButton_in3->setText(QApplication::translate("SetMotion", "3", 0));
        toolButton_in4->setText(QApplication::translate("SetMotion", "4", 0));
        toolButton_14->setText(QApplication::translate("SetMotion", "5", 0));
        toolButton_15->setText(QApplication::translate("SetMotion", "6", 0));
        toolButton_16->setText(QApplication::translate("SetMotion", "7", 0));
        toolButton_17->setText(QApplication::translate("SetMotion", "8", 0));
        groupBox_2->setTitle(QApplication::translate("SetMotion", "\344\274\272\346\234\215\347\224\265\346\234\272", 0));
        radioButton_1->setText(QApplication::translate("SetMotion", "\347\224\265\346\234\272\344\270\200", 0));
        radioButton_2->setText(QApplication::translate("SetMotion", "\347\224\265\346\234\272\344\272\214", 0));
        label->setText(QApplication::translate("SetMotion", "\351\200\237\345\272\246\357\274\232", 0));
        pushButton->setText(QApplication::translate("SetMotion", "\345\220\257\345\212\250", 0));
        radioButtonplus->setText(QApplication::translate("SetMotion", "\346\255\243\346\226\271\345\220\221", 0));
        radioButtondiv->setText(QApplication::translate("SetMotion", "\350\264\237\346\226\271\345\220\221", 0));
        label_3->setText(QApplication::translate("SetMotion", "\350\267\235\347\246\273\357\274\232", 0));
        toolButton->setText(QApplication::translate("SetMotion", "log", 0));
        pushButton_2->setText(QApplication::translate("SetMotion", "\344\277\235\345\255\230\351\200\200\345\207\272", 0));
        groupBox_3->setTitle(QApplication::translate("SetMotion", "IO output", 0));
        toolButton_out1->setText(QApplication::translate("SetMotion", "1", 0));
        toolButton_out2->setText(QApplication::translate("SetMotion", "2", 0));
        toolButton_out3->setText(QApplication::translate("SetMotion", "3", 0));
        toolButton_out4->setText(QApplication::translate("SetMotion", "4", 0));
        toolButton_out5->setText(QApplication::translate("SetMotion", "5", 0));
        toolButton_9->setText(QApplication::translate("SetMotion", "6", 0));
        toolButton_7->setText(QApplication::translate("SetMotion", "7", 0));
        toolButton_5->setText(QApplication::translate("SetMotion", "8", 0));
    } // retranslateUi

};

namespace Ui {
    class SetMotion: public Ui_SetMotion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETMOTION_H
