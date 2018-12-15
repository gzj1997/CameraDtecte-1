/********************************************************************************
** Form generated from reading UI file 'GetSF.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETSF_H
#define UI_GETSF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GetSF
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QDialog *GetSF)
    {
        if (GetSF->objectName().isEmpty())
            GetSF->setObjectName(QStringLiteral("GetSF"));
        GetSF->resize(400, 300);
        gridLayoutWidget = new QWidget(GetSF);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 50, 301, 201));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 1, 1, 1);


        retranslateUi(GetSF);
        QObject::connect(pushButton, SIGNAL(clicked()), GetSF, SLOT(getname()));

        QMetaObject::connectSlotsByName(GetSF);
    } // setupUi

    void retranslateUi(QDialog *GetSF)
    {
        GetSF->setWindowTitle(QApplication::translate("GetSF", "GetSF", 0));
        pushButton->setText(QApplication::translate("GetSF", "sf1", 0));
        pushButton_2->setText(QApplication::translate("GetSF", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("GetSF", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("GetSF", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("GetSF", "\347\241\256\345\256\232", 0));
        pushButton_6->setText(QApplication::translate("GetSF", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class GetSF: public Ui_GetSF {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETSF_H
