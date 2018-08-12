#ifndef DIALOG_SQL_COMMAND_H
#define DIALOG_SQL_COMMAND_H

#include <QDialog>

namespace Ui {
class Dialog_SQL_Command;
}

class Dialog_SQL_Command : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_SQL_Command(QWidget *parent = 0);

    ~Dialog_SQL_Command();

    QString getCommand() const;
    void setCommand(const QString &value);
    void setCommandfromedit();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog_SQL_Command *ui;
    QString command="error_string";
};

#endif // DIALOG_SQL_COMMAND_H
