#ifndef DIALOG_SETTINGS_H
#define DIALOG_SETTINGS_H

#include <QDialog>

namespace Ui {
class dialog_settings;
}

class dialog_settings : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_settings(QWidget *parent = 0);
    ~dialog_settings();

private slots:
    void on_set_folder_database_clicked();

    void on_set_way_database_clicked();

    void on_set_folder_project_clicked();

    void on_set_way_project_clicked();

    void on_yes_accepted();

private:
    Ui::dialog_settings *ui;
};

#endif // DIALOG_SETTINGS_H
