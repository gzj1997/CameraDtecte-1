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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraDtecte1Class
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_3;
    QToolButton *toolButton_6;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QToolButton *toolButton_5;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;
    QToolButton *toolButton_4;
    QGroupBox *groupBox_2;
    QTableView *tableView;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_21;
    QLineEdit *lineEdit_14;
    QLabel *label_25;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_16;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_13;
    QGroupBox *groupBox_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QWidget *tab_2;
    QLabel *label_2;
    QWidget *tab_3;
    QLabel *label_7;
    QWidget *tab_4;
    QLabel *label_9;
    QWidget *tab_5;
    QLabel *label_10;
    QWidget *tab_6;
    QLabel *label_11;
    QWidget *tab_7;
    QLabel *label_12;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_17;
    QToolButton *toolButton_10;
    QToolButton *toolButton_11;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *CameraDtecte1Class)
    {
        if (CameraDtecte1Class->objectName().isEmpty())
            CameraDtecte1Class->setObjectName(QStringLiteral("CameraDtecte1Class"));
        CameraDtecte1Class->resize(1324, 694);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/CameraDtecte1/Resources/\345\205\254\345\217\270LOG.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        CameraDtecte1Class->setWindowIcon(icon);
        CameraDtecte1Class->setAutoFillBackground(true);
        CameraDtecte1Class->setStyleSheet(QLatin1String("#centralWidget { \n"
"border-image:url(:/CameraDtecte1/Resources/back8.jpg);\n"
"}  \n"
"# centralWidget * { \n"
"border-image:url(); \n"
"}"));
        CameraDtecte1Class->setIconSize(QSize(64, 64));
        centralWidget = new QWidget(CameraDtecte1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("#centralWidget { \n"
"border-image:url(:/CameraDtecte1/Resources/back5.jpg);\n"
"}  \n"
"# centralWidget * { \n"
"border-image:url(); \n"
"}"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 641, 91));
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

        toolButton_6 = new QToolButton(horizontalLayoutWidget);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/CameraDtecte1/Resources/setproduct.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon2);
        toolButton_6->setIconSize(QSize(64, 64));
        toolButton_6->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_6);

        toolButton_2 = new QToolButton(horizontalLayoutWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/CameraDtecte1/Resources/motion.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon3);
        toolButton_2->setIconSize(QSize(64, 64));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_2);

        toolButton = new QToolButton(horizontalLayoutWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/CameraDtecte1/Resources/setsf.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon4);
        toolButton->setIconSize(QSize(64, 64));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton);

        toolButton_5 = new QToolButton(horizontalLayoutWidget);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/CameraDtecte1/Resources/camera2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon5);
        toolButton_5->setIconSize(QSize(64, 64));
        toolButton_5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_5);

        toolButton_7 = new QToolButton(horizontalLayoutWidget);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/CameraDtecte1/Resources/count.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon6);
        toolButton_7->setIconSize(QSize(64, 64));
        toolButton_7->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_7);

        toolButton_8 = new QToolButton(horizontalLayoutWidget);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/CameraDtecte1/Resources/form.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_8->setIcon(icon7);
        toolButton_8->setIconSize(QSize(64, 64));
        toolButton_8->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_8);

        toolButton_4 = new QToolButton(horizontalLayoutWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setStyleSheet(QStringLiteral(""));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/CameraDtecte1/Resources/stop.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon8);
        toolButton_4->setIconSize(QSize(64, 64));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton_4);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(670, 110, 631, 331));
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 20, 631, 311));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(670, 450, 631, 151));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        groupBox_3->setFont(font);
        gridLayoutWidget_2 = new QWidget(groupBox_3);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 20, 621, 121));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(gridLayoutWidget_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_22->setFont(font1);

        gridLayout_2->addWidget(label_22, 0, 0, 1, 1);

        label_23 = new QLabel(gridLayoutWidget_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font1);

        gridLayout_2->addWidget(label_23, 1, 0, 1, 1);

        label_24 = new QLabel(gridLayoutWidget_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font1);

        gridLayout_2->addWidget(label_24, 1, 2, 1, 1);

        label_21 = new QLabel(gridLayoutWidget_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font1);

        gridLayout_2->addWidget(label_21, 2, 0, 1, 1);

        lineEdit_14 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setFont(font1);

        gridLayout_2->addWidget(lineEdit_14, 1, 1, 1, 1);

        label_25 = new QLabel(gridLayoutWidget_2);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font1);
        label_25->setStyleSheet(QLatin1String("#centralWidget { \n"
"border-image:url(:/CameraDtecte1/Resources/back2.jpg);\n"
"}  \n"
"# centralWidget * { \n"
"border-image:url(); \n"
"}"));

        gridLayout_2->addWidget(label_25, 2, 2, 1, 1);

        lineEdit_15 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));
        lineEdit_15->setFont(font1);

        gridLayout_2->addWidget(lineEdit_15, 1, 3, 1, 1);

        lineEdit_16 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));
        lineEdit_16->setFont(font1);

        gridLayout_2->addWidget(lineEdit_16, 2, 1, 1, 1);

        lineEdit_17 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_17->setObjectName(QStringLiteral("lineEdit_17"));
        lineEdit_17->setFont(font1);

        gridLayout_2->addWidget(lineEdit_17, 2, 3, 1, 1);

        lineEdit_13 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setFont(font1);

        gridLayout_2->addWidget(lineEdit_13, 0, 1, 1, 3);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 110, 631, 491));
        tabWidget = new QTabWidget(groupBox_4);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 611, 461));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 611, 441));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 611, 441));
        label_2->setAutoFillBackground(true);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 0, 611, 441));
        label_7->setAutoFillBackground(true);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 0, 611, 441));
        label_9->setAutoFillBackground(true);
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_10 = new QLabel(tab_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(0, 0, 611, 441));
        label_10->setAutoFillBackground(true);
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        label_11 = new QLabel(tab_6);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(0, 0, 611, 441));
        label_11->setAutoFillBackground(true);
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        label_12 = new QLabel(tab_7);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(0, 0, 171, 201));
        label_12->setAutoFillBackground(true);
        label_15 = new QLabel(tab_7);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(0, 230, 171, 201));
        label_15->setAutoFillBackground(true);
        label_16 = new QLabel(tab_7);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(200, 230, 171, 201));
        label_16->setAutoFillBackground(true);
        label_13 = new QLabel(tab_7);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(200, 0, 171, 201));
        label_13->setAutoFillBackground(true);
        label_14 = new QLabel(tab_7);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(390, 0, 171, 201));
        label_14->setAutoFillBackground(true);
        label_17 = new QLabel(tab_7);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(400, 230, 171, 201));
        label_17->setAutoFillBackground(true);
        tabWidget->addTab(tab_7, QString());
        toolButton_10 = new QToolButton(centralWidget);
        toolButton_10->setObjectName(QStringLiteral("toolButton_10"));
        toolButton_10->setGeometry(QRect(0, 610, 1321, 61));
        toolButton_10->setContextMenuPolicy(Qt::NoContextMenu);
        toolButton_10->setStyleSheet(QStringLiteral(""));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/CameraDtecte1/Resources/icon6.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_10->setIcon(icon9);
        toolButton_10->setIconSize(QSize(11111, 222));
        toolButton_10->setAutoExclusive(true);
        toolButton_10->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton_10->setAutoRaise(true);
        toolButton_11 = new QToolButton(centralWidget);
        toolButton_11->setObjectName(QStringLiteral("toolButton_11"));
        toolButton_11->setGeometry(QRect(660, 0, 651, 101));
        toolButton_11->setContextMenuPolicy(Qt::NoContextMenu);
        toolButton_11->setStyleSheet(QStringLiteral(""));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/CameraDtecte1/Resources/icon5.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_11->setIcon(icon10);
        toolButton_11->setIconSize(QSize(11111, 222));
        toolButton_11->setAutoExclusive(true);
        toolButton_11->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton_11->setAutoRaise(true);
        CameraDtecte1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CameraDtecte1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1324, 23));
        CameraDtecte1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CameraDtecte1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setStyleSheet(QStringLiteral("background-color:transparent"));
        CameraDtecte1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(CameraDtecte1Class);
        QObject::connect(toolButton_3, SIGNAL(clicked()), CameraDtecte1Class, SLOT(StartBtn()));
        QObject::connect(toolButton_4, SIGNAL(clicked()), CameraDtecte1Class, SLOT(StopBtn()));
        QObject::connect(toolButton_6, SIGNAL(clicked()), CameraDtecte1Class, SLOT(ProductSet()));
        QObject::connect(toolButton_2, SIGNAL(clicked()), CameraDtecte1Class, SLOT(MotionSet()));
        QObject::connect(toolButton, SIGNAL(clicked()), CameraDtecte1Class, SLOT(AlgorithmSet()));
        QObject::connect(toolButton_5, SIGNAL(clicked()), CameraDtecte1Class, SLOT(CameraSet()));
        QObject::connect(tabWidget, SIGNAL(currentChanged(int)), CameraDtecte1Class, SLOT(tabchange(int)));
        QObject::connect(toolButton_8, SIGNAL(clicked()), CameraDtecte1Class, SLOT(ReportForm()));
        QObject::connect(toolButton_7, SIGNAL(clicked()), CameraDtecte1Class, SLOT(NumToZero()));

        tabWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(CameraDtecte1Class);
    } // setupUi

    void retranslateUi(QMainWindow *CameraDtecte1Class)
    {
        CameraDtecte1Class->setWindowTitle(QApplication::translate("CameraDtecte1Class", "CameraDtecte1", 0));
        toolButton_3->setText(QApplication::translate("CameraDtecte1Class", "\345\274\200\345\247\213", 0));
        toolButton_6->setText(QApplication::translate("CameraDtecte1Class", "\344\272\247\345\223\201\350\256\276\345\256\232", 0));
        toolButton_2->setText(QApplication::translate("CameraDtecte1Class", "\350\277\220\345\212\250\350\256\276\345\256\232", 0));
        toolButton->setText(QApplication::translate("CameraDtecte1Class", "\347\256\227\346\263\225\350\256\276\345\256\232", 0));
        toolButton_5->setText(QApplication::translate("CameraDtecte1Class", "\347\233\270\346\234\272\350\256\276\345\256\232", 0));
        toolButton_7->setText(QApplication::translate("CameraDtecte1Class", "\346\270\205\351\233\266", 0));
        toolButton_8->setText(QApplication::translate("CameraDtecte1Class", "\346\212\245\350\241\250", 0));
        toolButton_4->setText(QApplication::translate("CameraDtecte1Class", "\345\201\234\346\255\242", 0));
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        label_22->setText(QApplication::translate("CameraDtecte1Class", "\345\220\215\347\247\260", 0));
        label_23->setText(QApplication::translate("CameraDtecte1Class", "\346\200\273\351\207\217", 0));
        label_24->setText(QApplication::translate("CameraDtecte1Class", "\351\200\237\345\272\246", 0));
        label_21->setText(QApplication::translate("CameraDtecte1Class", "\350\211\257\345\223\201\347\216\207", 0));
        label_25->setText(QApplication::translate("CameraDtecte1Class", "\350\211\257\345\223\201\346\225\260", 0));
        groupBox_4->setTitle(QString());
        label->setText(QApplication::translate("CameraDtecte1Class", "1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CameraDtecte1Class", "CCD1", 0));
        label_2->setText(QApplication::translate("CameraDtecte1Class", "TextLabel2", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CameraDtecte1Class", "CCD2", 0));
        label_7->setText(QApplication::translate("CameraDtecte1Class", "3", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("CameraDtecte1Class", "CCD3", 0));
        label_9->setText(QApplication::translate("CameraDtecte1Class", "4", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("CameraDtecte1Class", "CCD4", 0));
        label_10->setText(QApplication::translate("CameraDtecte1Class", "5", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("CameraDtecte1Class", "CCD5", 0));
        label_11->setText(QApplication::translate("CameraDtecte1Class", "6", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("CameraDtecte1Class", "CCD6", 0));
        label_12->setText(QApplication::translate("CameraDtecte1Class", "1", 0));
        label_15->setText(QApplication::translate("CameraDtecte1Class", "4", 0));
        label_16->setText(QApplication::translate("CameraDtecte1Class", "5", 0));
        label_13->setText(QApplication::translate("CameraDtecte1Class", "2", 0));
        label_14->setText(QApplication::translate("CameraDtecte1Class", "3", 0));
        label_17->setText(QApplication::translate("CameraDtecte1Class", "6", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("CameraDtecte1Class", "\346\211\200\346\234\211", 0));
        toolButton_10->setText(QString());
        toolButton_11->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CameraDtecte1Class: public Ui_CameraDtecte1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERADTECTE1_H
