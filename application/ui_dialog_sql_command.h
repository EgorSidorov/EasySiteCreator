/********************************************************************************
** Form generated from reading UI file 'dialog_sql_command.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SQL_COMMAND_H
#define UI_DIALOG_SQL_COMMAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_SQL_Command
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *sql_command_edit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_SQL_Command)
    {
        if (Dialog_SQL_Command->objectName().isEmpty())
            Dialog_SQL_Command->setObjectName(QStringLiteral("Dialog_SQL_Command"));
        Dialog_SQL_Command->resize(400, 300);
        verticalLayout = new QVBoxLayout(Dialog_SQL_Command);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        sql_command_edit = new QTextEdit(Dialog_SQL_Command);
        sql_command_edit->setObjectName(QStringLiteral("sql_command_edit"));

        verticalLayout->addWidget(sql_command_edit);

        buttonBox = new QDialogButtonBox(Dialog_SQL_Command);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog_SQL_Command);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_SQL_Command, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_SQL_Command, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_SQL_Command);
    } // setupUi

    void retranslateUi(QDialog *Dialog_SQL_Command)
    {
        Dialog_SQL_Command->setWindowTitle(QApplication::translate("Dialog_SQL_Command", "SQL COMMANDER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_SQL_Command: public Ui_Dialog_SQL_Command {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SQL_COMMAND_H
