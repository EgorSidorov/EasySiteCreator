/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTreeWidget *treeWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *run_server;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_htmlcode;
    QPushButton *button_database;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Html;
    QPushButton *Server;
    QHBoxLayout *db_button_layout;
    QPushButton *create_table;
    QPushButton *delete_table;
    QPushButton *insert_row;
    QPushButton *remove_row;
    QPushButton *update_row;
    QComboBox *comboBox;
    QPlainTextEdit *textEdit;
    QTableView *tableView;
    QTextEdit *serveredit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action->setCheckable(true);
        action->setShortcutVisibleInContextMenu(true);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_2->setCheckable(true);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_3->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        treeWidget = new QTreeWidget(centralwidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
        treeWidget->setColumnCount(2);

        verticalLayout->addWidget(treeWidget);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        run_server = new QPushButton(centralwidget);
        run_server->setObjectName(QStringLiteral("run_server"));

        verticalLayout_2->addWidget(run_server);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        button_htmlcode = new QPushButton(centralwidget);
        button_htmlcode->setObjectName(QStringLiteral("button_htmlcode"));

        horizontalLayout->addWidget(button_htmlcode);

        button_database = new QPushButton(centralwidget);
        button_database->setObjectName(QStringLiteral("button_database"));

        horizontalLayout->addWidget(button_database);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Html = new QPushButton(centralwidget);
        Html->setObjectName(QStringLiteral("Html"));

        horizontalLayout_2->addWidget(Html);

        Server = new QPushButton(centralwidget);
        Server->setObjectName(QStringLiteral("Server"));

        horizontalLayout_2->addWidget(Server);


        verticalLayout_2->addLayout(horizontalLayout_2);

        db_button_layout = new QHBoxLayout();
        db_button_layout->setObjectName(QStringLiteral("db_button_layout"));
        create_table = new QPushButton(centralwidget);
        create_table->setObjectName(QStringLiteral("create_table"));

        db_button_layout->addWidget(create_table);

        delete_table = new QPushButton(centralwidget);
        delete_table->setObjectName(QStringLiteral("delete_table"));

        db_button_layout->addWidget(delete_table);

        insert_row = new QPushButton(centralwidget);
        insert_row->setObjectName(QStringLiteral("insert_row"));

        db_button_layout->addWidget(insert_row);

        remove_row = new QPushButton(centralwidget);
        remove_row->setObjectName(QStringLiteral("remove_row"));

        db_button_layout->addWidget(remove_row);

        update_row = new QPushButton(centralwidget);
        update_row->setObjectName(QStringLiteral("update_row"));

        db_button_layout->addWidget(update_row);


        verticalLayout_2->addLayout(db_button_layout);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        textEdit = new QPlainTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_2->addWidget(textEdit);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_2->addWidget(tableView);

        serveredit = new QTextEdit(centralwidget);
        serveredit->setObjectName(QStringLiteral("serveredit"));

        verticalLayout_2->addWidget(serveredit);


        horizontalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy);
        menubar->setDefaultUp(true);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "EasySiteCreator", nullptr));
        action->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        action_2->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        action_3->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\201\320\265\321\200\320\262\320\265\321\200\320\260", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\321\203", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\202\320\265\320\272\321\203\321\211\321\203\321\216 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\321\203", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\275\320\260 \321\201\320\260\320\271\321\202\320\265", nullptr));
        run_server->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \321\201\320\265\321\200\320\262\320\265\321\200", nullptr));
        button_htmlcode->setText(QApplication::translate("MainWindow", "\320\241\321\202\321\200\320\260\320\275\320\270\321\206\320\260", nullptr));
        button_database->setText(QApplication::translate("MainWindow", "\320\221\320\260\320\267\320\260 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        Html->setText(QApplication::translate("MainWindow", "Html", nullptr));
        Server->setText(QApplication::translate("MainWindow", "Server", nullptr));
        create_table->setText(QApplication::translate("MainWindow", "Create table", nullptr));
        delete_table->setText(QApplication::translate("MainWindow", "Delete table", nullptr));
        insert_row->setText(QApplication::translate("MainWindow", "Insert row", nullptr));
        remove_row->setText(QApplication::translate("MainWindow", "Remowe row", nullptr));
        update_row->setText(QApplication::translate("MainWindow", "Update row", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
