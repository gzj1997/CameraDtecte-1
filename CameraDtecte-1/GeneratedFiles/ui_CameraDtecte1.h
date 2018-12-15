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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
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
    QToolButton *toolButton_4;
    QToolButton *toolButton_6;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QToolButton *toolButton_5;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QWidget *tab_2;
    QLabel *label_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
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

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 130, 601, 251));
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
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(650, 150, 551, 231));
        tabWidget_2->setStyleSheet(QStringLiteral("background-color:transparent"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tab_3->setStyleSheet(QStringLiteral("background-color:transparent"));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tab_4->setStyleSheet(QStringLiteral("background-color:transparent"));
        tabWidget_2->addTab(tab_4, QString());
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 410, 591, 111));
        listWidget_2 = new QListWidget(centralWidget);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(650, 410, 551, 111));
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
        tabWidget_2->setCurrentIndex(1);


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
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CameraDtecte1Class", "Tab 1", 0));
        label_2->setText(QApplication::translate("CameraDtecte1Class", "TextLabel2", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CameraDtecte1Class", "Tab 2", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("CameraDtecte1Class", "Tab 1", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("CameraDtecte1Class", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class CameraDtecte1Class: public Ui_CameraDtecte1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERADTECTE1_H
