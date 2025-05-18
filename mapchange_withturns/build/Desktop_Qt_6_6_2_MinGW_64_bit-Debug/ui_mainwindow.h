/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *start;
    QSpacerItem *verticalSpacer_3;
    QPushButton *reset;
    QSpacerItem *verticalSpacer_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *year;
    QComboBox *month;
    QComboBox *date;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_2;
    QComboBox *zmap;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *clabel0;
    QTextEdit *corse0;
    QVBoxLayout *verticalLayout_4;
    QLabel *clabel1;
    QTextEdit *corse1;
    QVBoxLayout *verticalLayout_5;
    QLabel *clabel2;
    QTextEdit *corse2;
    QVBoxLayout *verticalLayout_7;
    QLabel *clabel3;
    QTextEdit *corse3;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_4;
    QTextEdit *corse4;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *outputconsole;
    QGraphicsView *graphicsView_2;
    QGraphicsView *logo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1167, 720);
        MainWindow->setWindowOpacity(1.000000000000000);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        horizontalLayout_5->addWidget(graphicsView);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        start = new QPushButton(centralwidget);
        start->setObjectName("start");
        QFont font;
        font.setPointSize(14);
        start->setFont(font);

        verticalLayout->addWidget(start);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        reset = new QPushButton(centralwidget);
        reset->setObjectName("reset");
        reset->setFont(font);

        verticalLayout->addWidget(reset);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        year = new QComboBox(centralwidget);
        year->addItem(QString());
        year->addItem(QString());
        year->addItem(QString());
        year->addItem(QString());
        year->addItem(QString());
        year->addItem(QString());
        year->addItem(QString());
        year->addItem(QString());
        year->setObjectName("year");
        year->setFont(font);

        horizontalLayout_2->addWidget(year);

        month = new QComboBox(centralwidget);
        month->addItem(QString());
        month->addItem(QString());
        month->addItem(QString());
        month->addItem(QString());
        month->addItem(QString());
        month->addItem(QString());
        month->addItem(QString());
        month->addItem(QString());
        month->addItem(QString());
        month->addItem(QString());
        month->addItem(QString());
        month->addItem(QString());
        month->setObjectName("month");
        month->setFont(font);

        horizontalLayout_2->addWidget(month);

        date = new QComboBox(centralwidget);
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->addItem(QString());
        date->setObjectName("date");
        date->setFont(font);

        horizontalLayout_2->addWidget(date);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_2);

        zmap = new QComboBox(centralwidget);
        zmap->addItem(QString());
        zmap->addItem(QString());
        zmap->addItem(QString());
        zmap->addItem(QString());
        zmap->addItem(QString());
        zmap->setObjectName("zmap");
        zmap->setFont(font);

        verticalLayout->addWidget(zmap);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        clabel0 = new QLabel(centralwidget);
        clabel0->setObjectName("clabel0");
        clabel0->setFont(font);

        verticalLayout_3->addWidget(clabel0);

        corse0 = new QTextEdit(centralwidget);
        corse0->setObjectName("corse0");
        QFont font1;
        font1.setPointSize(16);
        corse0->setFont(font1);

        verticalLayout_3->addWidget(corse0);


        verticalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        clabel1 = new QLabel(centralwidget);
        clabel1->setObjectName("clabel1");
        clabel1->setFont(font);

        verticalLayout_4->addWidget(clabel1);

        corse1 = new QTextEdit(centralwidget);
        corse1->setObjectName("corse1");
        corse1->setFont(font1);

        verticalLayout_4->addWidget(corse1);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        clabel2 = new QLabel(centralwidget);
        clabel2->setObjectName("clabel2");
        clabel2->setFont(font);

        verticalLayout_5->addWidget(clabel2);

        corse2 = new QTextEdit(centralwidget);
        corse2->setObjectName("corse2");
        corse2->setFont(font1);

        verticalLayout_5->addWidget(corse2);


        verticalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        clabel3 = new QLabel(centralwidget);
        clabel3->setObjectName("clabel3");
        clabel3->setFont(font);

        verticalLayout_7->addWidget(clabel3);

        corse3 = new QTextEdit(centralwidget);
        corse3->setObjectName("corse3");
        corse3->setFont(font1);

        verticalLayout_7->addWidget(corse3);


        verticalLayout_6->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        verticalLayout_8->addWidget(label_4);

        corse4 = new QTextEdit(centralwidget);
        corse4->setObjectName("corse4");
        corse4->setFont(font1);

        verticalLayout_8->addWidget(corse4);


        verticalLayout_6->addLayout(verticalLayout_8);


        horizontalLayout->addLayout(verticalLayout_6);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 2);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        outputconsole = new QTextEdit(centralwidget);
        outputconsole->setObjectName("outputconsole");
        QFont font2;
        font2.setPointSize(18);
        outputconsole->setFont(font2);

        horizontalLayout_3->addWidget(outputconsole);

        graphicsView_2 = new QGraphicsView(centralwidget);
        graphicsView_2->setObjectName("graphicsView_2");

        horizontalLayout_3->addWidget(graphicsView_2);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_3);

        logo = new QGraphicsView(centralwidget);
        logo->setObjectName("logo");

        verticalLayout_2->addWidget(logo);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);

        horizontalLayout_5->addLayout(verticalLayout_2);

        horizontalLayout_5->setStretch(0, 4);
        horizontalLayout_5->setStretch(1, 3);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Weighted Path", nullptr));
        start->setText(QCoreApplication::translate("MainWindow", "\352\267\270\353\246\254\352\270\260", nullptr));
        reset->setText(QCoreApplication::translate("MainWindow", "\353\247\265\354\264\210\352\270\260\355\231\224", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\353\202\240\354\247\234", nullptr));
        year->setItemText(0, QCoreApplication::translate("MainWindow", "2016", nullptr));
        year->setItemText(1, QCoreApplication::translate("MainWindow", "2017", nullptr));
        year->setItemText(2, QCoreApplication::translate("MainWindow", "2018", nullptr));
        year->setItemText(3, QCoreApplication::translate("MainWindow", "2019", nullptr));
        year->setItemText(4, QCoreApplication::translate("MainWindow", "2020", nullptr));
        year->setItemText(5, QCoreApplication::translate("MainWindow", "2021", nullptr));
        year->setItemText(6, QCoreApplication::translate("MainWindow", "2022", nullptr));
        year->setItemText(7, QCoreApplication::translate("MainWindow", "2023", nullptr));

        month->setItemText(0, QCoreApplication::translate("MainWindow", "01", nullptr));
        month->setItemText(1, QCoreApplication::translate("MainWindow", "02", nullptr));
        month->setItemText(2, QCoreApplication::translate("MainWindow", "03", nullptr));
        month->setItemText(3, QCoreApplication::translate("MainWindow", "04", nullptr));
        month->setItemText(4, QCoreApplication::translate("MainWindow", "05", nullptr));
        month->setItemText(5, QCoreApplication::translate("MainWindow", "06", nullptr));
        month->setItemText(6, QCoreApplication::translate("MainWindow", "07", nullptr));
        month->setItemText(7, QCoreApplication::translate("MainWindow", "08", nullptr));
        month->setItemText(8, QCoreApplication::translate("MainWindow", "09", nullptr));
        month->setItemText(9, QCoreApplication::translate("MainWindow", "10", nullptr));
        month->setItemText(10, QCoreApplication::translate("MainWindow", "11", nullptr));
        month->setItemText(11, QCoreApplication::translate("MainWindow", "12", nullptr));

        date->setItemText(0, QCoreApplication::translate("MainWindow", "01", nullptr));
        date->setItemText(1, QCoreApplication::translate("MainWindow", "02", nullptr));
        date->setItemText(2, QCoreApplication::translate("MainWindow", "03", nullptr));
        date->setItemText(3, QCoreApplication::translate("MainWindow", "04", nullptr));
        date->setItemText(4, QCoreApplication::translate("MainWindow", "05", nullptr));
        date->setItemText(5, QCoreApplication::translate("MainWindow", "06", nullptr));
        date->setItemText(6, QCoreApplication::translate("MainWindow", "07", nullptr));
        date->setItemText(7, QCoreApplication::translate("MainWindow", "08", nullptr));
        date->setItemText(8, QCoreApplication::translate("MainWindow", "09", nullptr));
        date->setItemText(9, QCoreApplication::translate("MainWindow", "10", nullptr));
        date->setItemText(10, QCoreApplication::translate("MainWindow", "11", nullptr));
        date->setItemText(11, QCoreApplication::translate("MainWindow", "12", nullptr));
        date->setItemText(12, QCoreApplication::translate("MainWindow", "13", nullptr));
        date->setItemText(13, QCoreApplication::translate("MainWindow", "14", nullptr));
        date->setItemText(14, QCoreApplication::translate("MainWindow", "15", nullptr));
        date->setItemText(15, QCoreApplication::translate("MainWindow", "16", nullptr));
        date->setItemText(16, QCoreApplication::translate("MainWindow", "17", nullptr));
        date->setItemText(17, QCoreApplication::translate("MainWindow", "18", nullptr));
        date->setItemText(18, QCoreApplication::translate("MainWindow", "19", nullptr));
        date->setItemText(19, QCoreApplication::translate("MainWindow", "20", nullptr));
        date->setItemText(20, QCoreApplication::translate("MainWindow", "21", nullptr));
        date->setItemText(21, QCoreApplication::translate("MainWindow", "22", nullptr));
        date->setItemText(22, QCoreApplication::translate("MainWindow", "23", nullptr));
        date->setItemText(23, QCoreApplication::translate("MainWindow", "24", nullptr));
        date->setItemText(24, QCoreApplication::translate("MainWindow", "25", nullptr));
        date->setItemText(25, QCoreApplication::translate("MainWindow", "26", nullptr));
        date->setItemText(26, QCoreApplication::translate("MainWindow", "27", nullptr));
        date->setItemText(27, QCoreApplication::translate("MainWindow", "28", nullptr));
        date->setItemText(28, QCoreApplication::translate("MainWindow", "29", nullptr));
        date->setItemText(29, QCoreApplication::translate("MainWindow", "30", nullptr));
        date->setItemText(30, QCoreApplication::translate("MainWindow", "31", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "\355\225\255\353\241\234\354\204\240\355\203\235", nullptr));
        zmap->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        zmap->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        zmap->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        zmap->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        zmap->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));

        clabel0->setText(QCoreApplication::translate("MainWindow", "0\353\262\210\355\225\255\353\241\234(\353\271\250\352\260\225)", nullptr));
        clabel1->setText(QCoreApplication::translate("MainWindow", "1\353\262\210\355\225\255\353\241\234(\354\264\210\353\241\235)", nullptr));
        clabel2->setText(QCoreApplication::translate("MainWindow", "2\353\262\210\355\225\255\353\241\234(\353\205\270\353\236\221)", nullptr));
        clabel3->setText(QCoreApplication::translate("MainWindow", "3\353\262\210\355\225\255\353\241\234(\355\214\214\353\236\221)", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "4\353\262\210\355\225\255\353\241\234(\353\263\264\353\235\274)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
