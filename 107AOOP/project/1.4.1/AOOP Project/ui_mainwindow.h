/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *function_plot;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *StandardPushButtom;
    QLabel *StandardLaber;
    QTextEdit *StandardTextEdit;
    QLabel *XstartLaber;
    QLineEdit *XstartlineEdit;
    QLabel *XendLaber;
    QLineEdit *XendlineEdit;
    QWidget *tab_2;
    QPushButton *PolarPushButtom;
    QLabel *PolarLaber;
    QLabel *RadiusLaber;
    QLineEdit *PolarlineEdit;
    QLineEdit *maxtheta;
    QLabel *label;
    QLabel *label_2;
    QWidget *tab_3;
    QPushButton *ParameterPushButtom;
    QLabel *PolarLaber_2;
    QLabel *Xlabel;
    QLabel *Ylabel;
    QLineEdit *ParameterXlineEdit;
    QLineEdit *ParameterYlineEdit;
    QLineEdit *ParameterStartlineEdit;
    QLineEdit *ParameterEndlineEdit;
    QLabel *ParameterStartlabel;
    QLabel *ParameterEndlabel;
    QWidget *tab_4;
    QTableWidget *tableWidget;
    QLabel *label_3;
    QPushButton *DrawPoints;
    QLabel *label_4;
    QLineEdit *FittingBasis;
    QPushButton *BasisOk;
    QLabel *label_5;
    QLineEdit *fitting_leftx;
    QLabel *label_6;
    QLineEdit *fitting_rightx;
    QLabel *label_7;
    QLabel *theleastsquared;
    QPushButton *FittingHelpButton;
    QPushButton *saveButtom;
    QPushButton *ShowEquationButton;
    QPushButton *CursorButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1040, 580);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(890, 580));
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setStyleSheet(QStringLiteral("background-image: url(:/pic1.jpg)"));
        function_plot = new QCustomPlot(centralWidget);
        function_plot->setObjectName(QStringLiteral("function_plot"));
        function_plot->setGeometry(QRect(20, 20, 561, 471));
        function_plot->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(585, 30, 401, 411));
        tabWidget->setStyleSheet(QLatin1String("background-color: white;\n"
"background-image: url(:/pic2.png)"));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideLeft);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        StandardPushButtom = new QPushButton(tab);
        StandardPushButtom->setObjectName(QStringLiteral("StandardPushButtom"));
        StandardPushButtom->setGeometry(QRect(80, 240, 75, 23));
        StandardLaber = new QLabel(tab);
        StandardLaber->setObjectName(QStringLiteral("StandardLaber"));
        StandardLaber->setGeometry(QRect(60, 20, 111, 16));
        StandardTextEdit = new QTextEdit(tab);
        StandardTextEdit->setObjectName(QStringLiteral("StandardTextEdit"));
        StandardTextEdit->setGeometry(QRect(30, 40, 331, 121));
        XstartLaber = new QLabel(tab);
        XstartLaber->setObjectName(QStringLiteral("XstartLaber"));
        XstartLaber->setGeometry(QRect(30, 180, 47, 12));
        XstartLaber->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));"));
        XstartlineEdit = new QLineEdit(tab);
        XstartlineEdit->setObjectName(QStringLiteral("XstartlineEdit"));
        XstartlineEdit->setGeometry(QRect(90, 180, 113, 20));
        XstartlineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        XendLaber = new QLabel(tab);
        XendLaber->setObjectName(QStringLiteral("XendLaber"));
        XendLaber->setGeometry(QRect(30, 210, 44, 12));
        XendLaber->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));"));
        XendlineEdit = new QLineEdit(tab);
        XendlineEdit->setObjectName(QStringLiteral("XendlineEdit"));
        XendlineEdit->setGeometry(QRect(90, 210, 113, 20));
        XendlineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        PolarPushButtom = new QPushButton(tab_2);
        PolarPushButtom->setObjectName(QStringLiteral("PolarPushButtom"));
        PolarPushButtom->setGeometry(QRect(80, 240, 75, 23));
        PolarLaber = new QLabel(tab_2);
        PolarLaber->setObjectName(QStringLiteral("PolarLaber"));
        PolarLaber->setGeometry(QRect(70, 20, 111, 16));
        RadiusLaber = new QLabel(tab_2);
        RadiusLaber->setObjectName(QStringLiteral("RadiusLaber"));
        RadiusLaber->setGeometry(QRect(40, 55, 47, 12));
        PolarlineEdit = new QLineEdit(tab_2);
        PolarlineEdit->setObjectName(QStringLiteral("PolarlineEdit"));
        PolarlineEdit->setGeometry(QRect(80, 50, 291, 20));
        maxtheta = new QLineEdit(tab_2);
        maxtheta->setObjectName(QStringLiteral("maxtheta"));
        maxtheta->setGeometry(QRect(80, 90, 291, 20));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(6, 90, 61, 20));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 110, 101, 16));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        ParameterPushButtom = new QPushButton(tab_3);
        ParameterPushButtom->setObjectName(QStringLiteral("ParameterPushButtom"));
        ParameterPushButtom->setGeometry(QRect(80, 240, 75, 23));
        PolarLaber_2 = new QLabel(tab_3);
        PolarLaber_2->setObjectName(QStringLiteral("PolarLaber_2"));
        PolarLaber_2->setGeometry(QRect(50, 20, 131, 16));
        Xlabel = new QLabel(tab_3);
        Xlabel->setObjectName(QStringLiteral("Xlabel"));
        Xlabel->setGeometry(QRect(30, 65, 47, 12));
        Ylabel = new QLabel(tab_3);
        Ylabel->setObjectName(QStringLiteral("Ylabel"));
        Ylabel->setGeometry(QRect(30, 95, 47, 12));
        ParameterXlineEdit = new QLineEdit(tab_3);
        ParameterXlineEdit->setObjectName(QStringLiteral("ParameterXlineEdit"));
        ParameterXlineEdit->setGeometry(QRect(60, 60, 311, 20));
        ParameterYlineEdit = new QLineEdit(tab_3);
        ParameterYlineEdit->setObjectName(QStringLiteral("ParameterYlineEdit"));
        ParameterYlineEdit->setGeometry(QRect(60, 90, 311, 20));
        ParameterStartlineEdit = new QLineEdit(tab_3);
        ParameterStartlineEdit->setObjectName(QStringLiteral("ParameterStartlineEdit"));
        ParameterStartlineEdit->setGeometry(QRect(90, 130, 113, 20));
        ParameterEndlineEdit = new QLineEdit(tab_3);
        ParameterEndlineEdit->setObjectName(QStringLiteral("ParameterEndlineEdit"));
        ParameterEndlineEdit->setGeometry(QRect(90, 160, 113, 20));
        ParameterStartlabel = new QLabel(tab_3);
        ParameterStartlabel->setObjectName(QStringLiteral("ParameterStartlabel"));
        ParameterStartlabel->setGeometry(QRect(30, 130, 47, 12));
        ParameterEndlabel = new QLabel(tab_3);
        ParameterEndlabel->setObjectName(QStringLiteral("ParameterEndlabel"));
        ParameterEndlabel->setGeometry(QRect(30, 160, 47, 12));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tableWidget = new QTableWidget(tab_4);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 50)
            tableWidget->setRowCount(50);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(17, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(18, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(19, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(20, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(21, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(22, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(23, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(24, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(25, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(26, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(27, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(28, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(29, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(30, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(31, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(32, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(33, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(34, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(35, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(36, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(37, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(38, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(39, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(40, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(41, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(42, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(43, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(44, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(45, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(46, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(47, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(48, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(49, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget->setItem(46, 0, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget->setItem(48, 1, __qtablewidgetitem53);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 10, 181, 341));
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 20, 61, 21));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setFrameShadow(QFrame::Sunken);
        DrawPoints = new QPushButton(tab_4);
        DrawPoints->setObjectName(QStringLiteral("DrawPoints"));
        DrawPoints->setGeometry(QRect(20, 360, 181, 23));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        DrawPoints->setFont(font1);
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(210, 60, 61, 16));
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setPointSize(10);
        font2.setItalic(true);
        label_4->setFont(font2);
        FittingBasis = new QLineEdit(tab_4);
        FittingBasis->setObjectName(QStringLiteral("FittingBasis"));
        FittingBasis->setGeometry(QRect(210, 80, 161, 20));
        BasisOk = new QPushButton(tab_4);
        BasisOk->setObjectName(QStringLiteral("BasisOk"));
        BasisOk->setGeometry(QRect(210, 220, 75, 23));
        QFont font3;
        font3.setFamily(QStringLiteral("Times New Roman"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        BasisOk->setFont(font3);
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(210, 100, 101, 16));
        label_5->setFont(font2);
        fitting_leftx = new QLineEdit(tab_4);
        fitting_leftx->setObjectName(QStringLiteral("fitting_leftx"));
        fitting_leftx->setGeometry(QRect(210, 130, 161, 20));
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(210, 160, 121, 16));
        label_6->setFont(font2);
        fitting_rightx = new QLineEdit(tab_4);
        fitting_rightx->setObjectName(QStringLiteral("fitting_rightx"));
        fitting_rightx->setGeometry(QRect(210, 190, 161, 20));
        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(210, 260, 181, 16));
        label_7->setStyleSheet(QStringLiteral("font: 87 8pt \"Arial Black\";"));
        label_7->setTextFormat(Qt::PlainText);
        label_7->setWordWrap(false);
        label_7->setMargin(0);
        label_7->setIndent(-1);
        theleastsquared = new QLabel(tab_4);
        theleastsquared->setObjectName(QStringLiteral("theleastsquared"));
        theleastsquared->setGeometry(QRect(210, 280, 161, 31));
        theleastsquared->setLayoutDirection(Qt::LeftToRight);
        theleastsquared->setStyleSheet(QStringLiteral("font: 16pt \"Agency FB\";"));
        theleastsquared->setAlignment(Qt::AlignCenter);
        FittingHelpButton = new QPushButton(tab_4);
        FittingHelpButton->setObjectName(QStringLiteral("FittingHelpButton"));
        FittingHelpButton->setGeometry(QRect(270, 20, 75, 23));
        FittingHelpButton->setFont(font3);
        tabWidget->addTab(tab_4, QString());
        saveButtom = new QPushButton(centralWidget);
        saveButtom->setObjectName(QStringLiteral("saveButtom"));
        saveButtom->setGeometry(QRect(580, 450, 121, 61));
        QFont font4;
        font4.setFamily(QStringLiteral("Times New Roman"));
        font4.setPointSize(16);
        saveButtom->setFont(font4);
        saveButtom->setStyleSheet(QStringLiteral("background-image: url(:/pic2.png)"));
        ShowEquationButton = new QPushButton(centralWidget);
        ShowEquationButton->setObjectName(QStringLiteral("ShowEquationButton"));
        ShowEquationButton->setGeometry(QRect(720, 450, 141, 61));
        ShowEquationButton->setFont(font4);
        ShowEquationButton->setStyleSheet(QStringLiteral("background-image: url(:/pic2.png)"));
        CursorButton = new QPushButton(centralWidget);
        CursorButton->setObjectName(QStringLiteral("CursorButton"));
        CursorButton->setGeometry(QRect(870, 450, 161, 61));
        QFont font5;
        font5.setFamily(QStringLiteral("Times New Roman"));
        font5.setPointSize(14);
        CursorButton->setFont(font5);
        CursorButton->setStyleSheet(QStringLiteral("background-image: url(:/pic2.png)"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1040, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        StandardPushButtom->setText(QApplication::translate("MainWindow", "Generate", nullptr));
        StandardLaber->setText(QApplication::translate("MainWindow", "Enter a normal function", nullptr));
        XstartLaber->setText(QApplication::translate("MainWindow", "X\350\273\270\350\265\267\345\247\213", nullptr));
        XendLaber->setText(QApplication::translate("MainWindow", "X\350\273\270\347\265\220\346\235\237", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Standard", nullptr));
        PolarPushButtom->setText(QApplication::translate("MainWindow", "Generate", nullptr));
        PolarLaber->setText(QApplication::translate("MainWindow", "Enter a polar function", nullptr));
        RadiusLaber->setText(QApplication::translate("MainWindow", "Radius", nullptr));
        label->setText(QApplication::translate("MainWindow", "upper limit", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "( in the unit of \317\200 )", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Polar", nullptr));
        ParameterPushButtom->setText(QApplication::translate("MainWindow", "Generate", nullptr));
        PolarLaber_2->setText(QApplication::translate("MainWindow", "Enter 2 parameter functions", nullptr));
        Xlabel->setText(QApplication::translate("MainWindow", "X = ", nullptr));
        Ylabel->setText(QApplication::translate("MainWindow", "Y = ", nullptr));
        ParameterStartlabel->setText(QApplication::translate("MainWindow", "\345\217\203\346\225\270\350\265\267\345\247\213", nullptr));
        ParameterEndlabel->setText(QApplication::translate("MainWindow", "\345\217\203\346\225\270\347\265\202\346\255\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Parameter", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "10", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "11", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "12", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "13", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "14", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "15", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "16", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "17", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "18", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "19", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "20", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(20);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "21", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(21);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "22", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->verticalHeaderItem(22);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "23", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(23);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "24", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->verticalHeaderItem(24);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "25", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->verticalHeaderItem(25);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "26", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->verticalHeaderItem(26);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "27", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->verticalHeaderItem(27);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "28", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->verticalHeaderItem(28);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "29", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->verticalHeaderItem(29);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "30", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->verticalHeaderItem(30);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "31", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->verticalHeaderItem(31);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "32", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->verticalHeaderItem(32);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "33", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->verticalHeaderItem(33);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "34", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->verticalHeaderItem(34);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "35", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->verticalHeaderItem(35);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "36", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->verticalHeaderItem(36);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "37", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->verticalHeaderItem(37);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "38", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->verticalHeaderItem(38);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "39", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->verticalHeaderItem(39);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "40", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->verticalHeaderItem(40);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWindow", "41", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->verticalHeaderItem(41);
        ___qtablewidgetitem43->setText(QApplication::translate("MainWindow", "42", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->verticalHeaderItem(42);
        ___qtablewidgetitem44->setText(QApplication::translate("MainWindow", "43", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget->verticalHeaderItem(43);
        ___qtablewidgetitem45->setText(QApplication::translate("MainWindow", "44", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget->verticalHeaderItem(44);
        ___qtablewidgetitem46->setText(QApplication::translate("MainWindow", "45", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget->verticalHeaderItem(45);
        ___qtablewidgetitem47->setText(QApplication::translate("MainWindow", "46", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget->verticalHeaderItem(46);
        ___qtablewidgetitem48->setText(QApplication::translate("MainWindow", "47", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget->verticalHeaderItem(47);
        ___qtablewidgetitem49->setText(QApplication::translate("MainWindow", "48", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget->verticalHeaderItem(48);
        ___qtablewidgetitem50->setText(QApplication::translate("MainWindow", "49", nullptr));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget->verticalHeaderItem(49);
        ___qtablewidgetitem51->setText(QApplication::translate("MainWindow", "50", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_3->setText(QApplication::translate("MainWindow", "fitting", nullptr));
        DrawPoints->setText(QApplication::translate("MainWindow", "Draw points", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "basis", nullptr));
        BasisOk->setText(QApplication::translate("MainWindow", "OK", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Left endpoint", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Right endpoint", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "the least squared residuals", nullptr));
        theleastsquared->setText(QApplication::translate("MainWindow", "0", nullptr));
        FittingHelpButton->setText(QApplication::translate("MainWindow", "help", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "data point", nullptr));
        saveButtom->setText(QApplication::translate("MainWindow", "Save As", nullptr));
        ShowEquationButton->setText(QApplication::translate("MainWindow", "Show Eqaution", nullptr));
        CursorButton->setText(QApplication::translate("MainWindow", "Show/Hide Cursor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
