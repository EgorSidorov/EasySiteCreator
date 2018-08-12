/********************************************************************************
** Form generated from reading UI file 'dialog_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SETTINGS_H
#define UI_DIALOG_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialog_settings
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *folder_database;
    QPushButton *set_folder_database;
    QLabel *label_2;
    QLineEdit *way_database;
    QPushButton *set_way_database;
    QLabel *label_3;
    QLineEdit *folder_project;
    QPushButton *set_folder_project;
    QLabel *label_4;
    QLineEdit *way_project;
    QPushButton *set_way_project;
    QDialogButtonBox *yes;

    void setupUi(QDialog *dialog_settings)
    {
        if (dialog_settings->objectName().isEmpty())
            dialog_settings->setObjectName(QStringLiteral("dialog_settings"));
        dialog_settings->resize(400, 300);
        verticalLayout = new QVBoxLayout(dialog_settings);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(dialog_settings);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        folder_database = new QLineEdit(dialog_settings);
        folder_database->setObjectName(QStringLiteral("folder_database"));

        gridLayout->addWidget(folder_database, 0, 1, 1, 1);

        set_folder_database = new QPushButton(dialog_settings);
        set_folder_database->setObjectName(QStringLiteral("set_folder_database"));

        gridLayout->addWidget(set_folder_database, 0, 2, 1, 1);

        label_2 = new QLabel(dialog_settings);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        way_database = new QLineEdit(dialog_settings);
        way_database->setObjectName(QStringLiteral("way_database"));

        gridLayout->addWidget(way_database, 1, 1, 1, 1);

        set_way_database = new QPushButton(dialog_settings);
        set_way_database->setObjectName(QStringLiteral("set_way_database"));

        gridLayout->addWidget(set_way_database, 1, 2, 1, 1);

        label_3 = new QLabel(dialog_settings);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        folder_project = new QLineEdit(dialog_settings);
        folder_project->setObjectName(QStringLiteral("folder_project"));

        gridLayout->addWidget(folder_project, 2, 1, 1, 1);

        set_folder_project = new QPushButton(dialog_settings);
        set_folder_project->setObjectName(QStringLiteral("set_folder_project"));

        gridLayout->addWidget(set_folder_project, 2, 2, 1, 1);

        label_4 = new QLabel(dialog_settings);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        way_project = new QLineEdit(dialog_settings);
        way_project->setObjectName(QStringLiteral("way_project"));

        gridLayout->addWidget(way_project, 3, 1, 1, 1);

        set_way_project = new QPushButton(dialog_settings);
        set_way_project->setObjectName(QStringLiteral("set_way_project"));

        gridLayout->addWidget(set_way_project, 3, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        yes = new QDialogButtonBox(dialog_settings);
        yes->setObjectName(QStringLiteral("yes"));
        yes->setOrientation(Qt::Horizontal);
        yes->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(yes);


        retranslateUi(dialog_settings);
        QObject::connect(yes, SIGNAL(accepted()), dialog_settings, SLOT(accept()));
        QObject::connect(yes, SIGNAL(rejected()), dialog_settings, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialog_settings);
    } // setupUi

    void retranslateUi(QDialog *dialog_settings)
    {
        dialog_settings->setWindowTitle(QApplication::translate("dialog_settings", "Dialog", nullptr));
        label->setText(QApplication::translate("dialog_settings", "\320\237\321\203\321\202\321\214 \320\272 \320\277\320\260\320\277\320\272\320\265 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        set_folder_database->setText(QApplication::translate("dialog_settings", "\320\227\320\260\320\264\320\260\321\202\321\214", nullptr));
        label_2->setText(QApplication::translate("dialog_settings", "\320\237\321\203\321\202\321\214 \320\272 \320\261\320\260\320\267\320\265 \320\264\320\260\320\275\320\275\321\213\321\205 \320\262 \320\277\321\200\320\276\320\265\320\272\321\202\320\265", nullptr));
        set_way_database->setText(QApplication::translate("dialog_settings", "\320\227\320\260\320\264\320\260\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("dialog_settings", "\320\237\321\203\321\202\321\214 \320\272 \320\277\320\260\320\277\320\272\320\265 \320\277\321\200\320\276\320\265\320\272\321\202\320\260", nullptr));
        set_folder_project->setText(QApplication::translate("dialog_settings", "\320\227\320\260\320\264\320\260\321\202\321\214", nullptr));
        label_4->setText(QApplication::translate("dialog_settings", "\320\237\320\276\320\273\320\275\321\213\320\271 \320\277\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203 \320\277\321\200\320\276\320\265\320\272\321\202\320\260", nullptr));
        set_way_project->setText(QApplication::translate("dialog_settings", "\320\227\320\260\320\264\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog_settings: public Ui_dialog_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SETTINGS_H
