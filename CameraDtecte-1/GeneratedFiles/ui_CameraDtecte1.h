/********************************************************************************
** Form generated from reading UI file 'CameraDtecte1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERADTECTE1_H
#define UI_CAMERADTECTE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <qchatview.h>

QT_BEGIN_NAMESPACE

class Ui_CameraDtecte1Class
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_6;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QToolButton *toolButton_5;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QCheckBox *checkBox;
    QLabel *label_8;
    QCheckBox *checkBox_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QGroupBox *groupBox_2;
    QTableWidget *tableWidget_2;
    QGroupBox *groupBox_3;
    QListWidget *listWidget_2;
    QGroupBox *groupBox_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QWidget *tab_2;
    QLabel *label_2;
    QChatView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CameraDtecte1Class)
    {
        if (CameraDtecte1Class->objectName().isEmpty())
            CameraDtecte1Class->setObjectName(QStringLiteral("CameraDtecte1Class"));
        CameraDtecte1Class->resize(1225, 601);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/CameraDtecte1/Resources/\345\205\254\345\217\270LOG.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        CameraDtecte1Class->setWindowIcon(icon);
        CameraDtecte1Class->setAutoFillBackground(true);
        CameraDtecte1Class->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(CameraDtecte1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("#centralWidget { \n"
"border-image:url(:/CameraDtecte1/Resources/back1.jpg);\n"
"}  \n"
"# centralWidget * { \n"
"border-image:url(); \n"
"}"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 20, 1171, 91));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_3 = new QToolButton(horizontalLayoutWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/CameraDtecte1/Resources/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon1);
        toolButton_3->setIconSize(QSize(64, 64));
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(horizontalLayoutWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/CameraDtecte1/Resources/stop.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon2);
        toolButton_4->setIconSize(QSize(64, 64));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_4);

        toolButton_6 = new QToolButton(horizontalLayoutWidget);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/CameraDtecte1/Resources/product.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon3);
        toolButton_6->setIconSize(QSize(64, 64));
        toolButton_6->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_6);

        toolButton_2 = new QToolButton(horizontalLayoutWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/CameraDtecte1/Resources/motion.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon4);
        toolButton_2->setIconSize(QSize(64, 64));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_2);

        toolButton = new QToolButton(horizontalLayoutWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/CameraDtecte1/Resources/algorithm.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon5);
        toolButton->setIconSize(QSize(64, 64));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton);

        toolButton_5 = new QToolButton(horizontalLayoutWidget);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/CameraDtecte1/Resources/camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon6);
        toolButton_5->setIconSize(QSize(64, 64));
        toolButton_5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 380, 621, 161));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 30, 621, 131));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_3 = new QCheckBox(gridLayoutWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        gridLayout->addWidget(checkBox_3, 2, 1, 1, 1);

        checkBox_4 = new QCheckBox(gridLayoutWidget);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        gridLayout->addWidget(checkBox_4, 5, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        checkBox = new QCheckBox(gridLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 4, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 1, 1, 1);

        checkBox_2 = new QCheckBox(gridLayoutWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout->addWidget(checkBox_2, 3, 1, 1, 1);

        lineEdit_4 = new QLineEdit(gridLayoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 2, 2, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 2, 3, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 2, 4, 1, 1);

        lineEdit_3 = new QLineEdit(gridLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 3, 2, 1, 1);

        lineEdit_5 = new QLineEdit(gridLayoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 3, 3, 1, 1);

        lineEdit_6 = new QLineEdit(gridLayoutWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 3, 4, 1, 1);

        lineEdit_7 = new QLineEdit(gridLayoutWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 4, 2, 1, 1);

        lineEdit_8 = new QLineEdit(gridLayoutWidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 4, 3, 1, 1);

        lineEdit_9 = new QLineEdit(gridLayoutWidget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout->addWidget(lineEdit_9, 5, 2, 1, 1);

        lineEdit_10 = new QLineEdit(gridLayoutWidget);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        gridLayout->addWidget(lineEdit_10, 5, 3, 1, 1);

        lineEdit_11 = new QLineEdit(gridLayoutWidget);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));

        gridLayout->addWidget(lineEdit_11, 4, 4, 1, 1);

        lineEdit_12 = new QLineEdit(gridLayoutWidget);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));

        gridLayout->addWidget(lineEdit_12, 5, 4, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(640, 10, 561, 261));
        tableWidget_2 = new QTableWidget(groupBox_2);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(10, 30, 541, 221));
        tableWidget_2->raise();
        tableWidget_2->raise();
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(650, 390, 571, 151));
        listWidget_2 = new QListWidget(groupBox_3);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(10, 20, 541, 121));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 120, 621, 261));
        tabWidget = new QTabWidget(groupBox_4);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 611, 251));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 561, 291));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 561, 291));
        label_2->setAutoFillBackground(true);
        tabWidget->addTab(tab_2, QString());
        tabWidget->raise();
        tabWidget->raise();
        graphicsView = new QChatView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(650, 280, 541, 101));
        CameraDtecte1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CameraDtecte1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1225, 23));
        CameraDtecte1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CameraDtecte1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setStyleSheet(QStringLiteral("background-color:transparent"));
        CameraDtecte1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CameraDtecte1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CameraDtecte1Class->setStatusBar(statusBar);

        retranslateUi(CameraDtecte1Class);
        QObject::connect(toolButton_3, SIGNAL(clicked()), CameraDtecte1Class, SLOT(StartBtn()));
        QObject::connect(toolButton_4, SIGNAL(clicked()), CameraDtecte1Class, SLOT(StopBtn()));
        QObject::connect(toolButton_6, SIGNAL(clicked()), CameraDtecte1Class, SLOT(ProductSet()));
        QObject::connect(toolButton_2, SIGNAL(clicked()), CameraDtecte1Class, SLOT(MotionSet()));
        QObject::connect(toolButton, SIGNAL(clicked()), CameraDtecte1Class, SLOT(AlgorithmSet()));
        QObject::connect(toolButton_5, SIGNAL(clicked()), CameraDtecte1Class, SLOT(CameraSet()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CameraDtecte1Class);
    } // setupUi

    void retranslateUi(QMainWindow *CameraDtecte1Class)
    {
        CameraDtecte1Class->setWindowTitle(QApplication::translate("CameraDtecte1Class", "CameraDtecte1", 0));
        toolButton_3->setText(QApplication::translate("CameraDtecte1Class", "\345\274\200\345\247\213", 0));
        toolButton_4->setText(QApplication::translate("CameraDtecte1Class", "\345\201\234\346\255\242", 0));
        toolButton_6->setText(QApplication::translate("CameraDtecte1Class", "\344\272\247\345\223\201\350\256\276\345\256\232", 0));
        toolButton_2->setText(QApplication::translate("CameraDtecte1Class", "\350\277\220\345\212\250\350\256\276\345\256\232", 0));
        toolButton->setText(QApplication::translate("CameraDtecte1Class", "\347\256\227\346\263\225\350\256\276\345\256\232", 0));
        toolButton_5->setText(QApplication::translate("CameraDtecte1Class", "\347\233\270\346\234\272\350\256\276\345\256\232", 0));
        groupBox->setTitle(QApplication::translate("CameraDtecte1Class", "GroupBox", 0));
        checkBox_3->setText(QApplication::translate("CameraDtecte1Class", "CheckBox", 0));
        checkBox_4->setText(QApplication::translate("CameraDtecte1Class", "CheckBox", 0));
        label_3->setText(QApplication::translate("CameraDtecte1Class", "TextLabel", 0));
        label_4->setText(QApplication::translate("CameraDtecte1Class", "TextLabel", 0));
        label_5->setText(QApplication::translate("CameraDtecte1Class", "TextLabel", 0));
        label_6->setText(QApplication::translate("CameraDtecte1Class", "TextLabel", 0));
        checkBox->setText(QApplication::translate("CameraDtecte1Class", "CheckBox", 0));
        label_8->setText(QApplication::translate("CameraDtecte1Class", "TextLabel", 0));
        checkBox_2->setText(QApplication::translate("CameraDtecte1Class", "CheckBox", 0));
        groupBox_2->setTitle(QApplication::translate("CameraDtecte1Class", "GroupBox", 0));
        groupBox_3->setTitle(QApplication::translate("CameraDtecte1Class", "GroupBox", 0));
        groupBox_4->setTitle(QApplication::translate("CameraDtecte1Class", "GroupBox", 0));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CameraDtecte1Class", "Tab 1", 0));
        label_2->setText(QApplication::translate("CameraDtecte1Class", "TextLabel2", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CameraDtecte1Class", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class CameraDtecte1Class: public Ui_CameraDtecte1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERADTECTE1_H
