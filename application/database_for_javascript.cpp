#include "database_for_javascript.h"
#include <settings_project.h>

database_for_javascript::database_for_javascript(QObject *parent) : QObject(parent)
{
//    database_site=QSqlDatabase::addDatabase("QSQLITE");
//    database_site.setDatabaseName("database/database_site.sqlite");
    //database_site.setConnectOptions("SQLITE_OPEN_NOMUTEX");
}

QString database_for_javascript::string_answer(QString db_request)
{
    qDebug()<<db_request;
    database_site=QSqlDatabase::addDatabase("QSQLITE");
    database_site.setDatabaseName(settings_project::get_Instance()->get_folder_project_way()+"/"+settings_project::get_Instance()->get_database_way());
    if(database_site.open()){
        QSqlQuery query(database_site);
        query.exec(db_request);
        QString answer = "invalid";
        if(query.next())
            answer = query.value(0).toString();
        database_site.close();
        qDebug()<<answer;
        return answer;
    }
}

QStringList database_for_javascript::stringlist_answer(QString db_request)
{
    database_site=QSqlDatabase::addDatabase("QSQLITE");
    database_site.setDatabaseName(settings_project::get_Instance()->get_folder_project_way()+"/"+settings_project::get_Instance()->get_database_way());
    if(database_site.open()){
        QSqlQuery query(database_site);
        query.exec(db_request);
        QStringList answer;
        while(query.next())
            answer.append(query.value(0).toString());
        if(answer.isEmpty() == true)
            answer.append("invalid");
        database_site.close();
        return answer;
    }
}


QByteArray database_for_javascript::qbytearray_answer(QString db_request)
{
    database_site=QSqlDatabase::addDatabase("QSQLITE");
    database_site.setDatabaseName(settings_project::get_Instance()->get_folder_project_way()+"/"+settings_project::get_Instance()->get_database_way());
    if(database_site.open()){
        QSqlQuery query(database_site);
        query.exec(db_request);
        query.next();
        QByteArray answer = query.value(0).toByteArray();
        database_site.close();
        return answer;
    }
}

void database_for_javascript::no_answer(QString db_request)
{
     qDebug()<<db_request;
    database_site=QSqlDatabase::addDatabase("QSQLITE");
    database_site.setDatabaseName(settings_project::get_Instance()->get_folder_project_way()+"/"+settings_project::get_Instance()->get_database_way());
    if(database_site.open()){
        QSqlQuery query(database_site);
        query.exec(db_request);
        database_site.close();
    }
}

void database_for_javascript::set_file(QString db_request,QString bind_name_file, QByteArray file)
{
    qDebug()<<"size of file:"<<file.size();
    database_site=QSqlDatabase::addDatabase("QSQLITE");
    database_site.setDatabaseName(settings_project::get_Instance()->get_folder_project_way()+"/"+settings_project::get_Instance()->get_database_way());
    if(database_site.open()){
        QSqlQuery query(database_site);
        query.prepare(db_request);
        query.bindValue(bind_name_file,file);
        query.exec();
        database_site.close();
    }
}
