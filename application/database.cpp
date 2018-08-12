#include "database.h"
#include <QDir>
#include <QDebug>
#include <QSqlQuery>
#include <dialog_sql_command.h>
#include <settings_project.h>

database::database(QObject *parent) : QObject(parent)
{
//    //если база данных еще не создана, то создаем
      QDir dir(settings_project::get_Instance()->get_database_folder());
      if(!dir.exists()){
          dir.cdUp();
          dir.mkdir(settings_project::get_Instance()->get_database_folder());
      }
//    QFile file(dir.filePath("database_site"));
//    if(!file.exists())
//    database_site=QSqlDatabase::addDatabase("QSQLITE");
//    database_site.setDatabaseName("database/database_site.sqlite");
//    database_site.setConnectOptions("QSQLITE_OPEN_READONLY");
    database_model = new QSqlQueryModel;
}

QSqlQueryModel *database::get_table_model(QString name_table)
{
    database_site=QSqlDatabase::addDatabase("QSQLITE");
    database_site.setDatabaseName(settings_project::get_Instance()->get_folder_project_way()+"/database/database_site.sqlite");
    database_site.setConnectOptions("QSQLITE_OPEN_READONLY");
    database_site.open();
    database_model->setQuery("SELECT * FROM "+name_table, database_site);
    QSqlQuery get_column_from_table(database_site);
    //запрос, чтобы получить поля таблицы
    QString query="pragma table_info("+name_table+")";
    get_column_from_table.exec(query);
    int iter=0;
    while(get_column_from_table.next()){
    database_model->setHeaderData(iter, Qt::Horizontal, get_column_from_table.value(1).toString());
    iter++;
    }
    database_site.close();
    return database_model;
}

QStringList database::get_list_table(){
    database_site=QSqlDatabase::addDatabase("QSQLITE");
    database_site.setDatabaseName(settings_project::get_Instance()->get_folder_project_way()+"/"+settings_project::get_Instance()->get_database_way());
    database_site.setConnectOptions("QSQLITE_OPEN_READONLY");
    database_site.open();
    QStringList databasetable = database_site.tables();
    database_site.close();
    return databasetable;
}

void database::do_sql_command(QString string_command){
    database_site=QSqlDatabase::addDatabase("QSQLITE");
    database_site.setDatabaseName(settings_project::get_Instance()->get_folder_project_way()+"/"+settings_project::get_Instance()->get_database_way());
    database_site.open();
    QSqlQuery command(database_site);
    Dialog_SQL_Command dialog_command;
    dialog_command.setCommand(string_command);
    dialog_command.exec();
    if(dialog_command.getCommand()!="error_string");
    command.exec(dialog_command.getCommand());
    database_site.close();
}

database::~database()
{
    delete database_model;
}
