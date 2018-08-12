#include "settings_project.h"
#include "QFile"
#include "QJsonDocument"
#include "QJsonObject"
#include <QDebug>

QString settings_project::get_database_way() const
{
    return database_way;
}

void settings_project::set_database_way(const QString &value)
{
    database_way = value;
}

QString settings_project::get_database_folder() const
{
    return database_folder;
}

void settings_project::set_database_folder(const QString &value)
{
    database_folder = value;
}

QString settings_project::get_name_project() const
{
    return name_project;
}

void settings_project::set_name_project(const QString &value)
{
    name_project = value;
}

QString settings_project::get_folder_project_way() const
{
    return folder_project_way;
}

void settings_project::set_folder_project_way(const QString &value)
{
    folder_project_way = value;
}

void settings_project::write_settings_in_file()
{
    QFile file("settings.json");
    file.open(QIODevice::WriteOnly);
    QJsonObject object
            {
        {"folder_project_way",folder_project_way},
        {"name_project",name_project},
        {"database_folder",database_folder},
        {"database_way",database_way}
            };
    QJsonDocument document(object);
    file.write(document.toJson());
    qDebug()<<"it work";
    file.close();
}

settings_project::settings_project()
{
    QFile file("settings.json");
    if(file.exists())
    {
        file.open(QIODevice::ReadOnly);
        QJsonDocument document = QJsonDocument::fromJson(file.readAll());
        QJsonObject root = document.object();
        QString value;
        value = root.value("folder_project_way").toString();
        if(!value.isNull())
            folder_project_way = value;
        else
            folder_project_way = "../easysitecreator_project1";
        value = root.value("name_project").toString();
        if(!value.isNull())
            name_project = value;
        else
            name_project = folder_project_way+"/filesession.eproject";
        value = root.value("database_folder").toString();
        if(!value.isNull())
            database_folder = value;
        else
            database_folder = folder_project_way+"/database";
        value = root.value("database_way").toString();
        if(!value.isNull())
            database_way = value;
        else
            database_way = database_folder+"/database_site.sqlite";
        file.close();
    }
    else
    {
        folder_project_way = "../easysitecreator_project1";
        name_project = folder_project_way+"/filesession.eproject";
        database_folder = folder_project_way+"/database";
        database_way = database_folder+"/database_site.sqlite";
        write_settings_in_file();
    }
}
