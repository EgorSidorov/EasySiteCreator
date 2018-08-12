#include "dialog_sql_command.h"
#include "ui_dialog_sql_command.h"

Dialog_SQL_Command::Dialog_SQL_Command(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_SQL_Command)
{
    ui->setupUi(this);
}

Dialog_SQL_Command::~Dialog_SQL_Command()
{
    delete ui;
}

QString Dialog_SQL_Command::getCommand() const
{
    return command;
}

void Dialog_SQL_Command::setCommand(const QString &value)
{
    ui->sql_command_edit->setText(value);
}

void Dialog_SQL_Command::setCommandfromedit()
{
    command=ui->sql_command_edit->toPlainText();
}

void Dialog_SQL_Command::on_buttonBox_accepted()
{
    setCommandfromedit();
}
