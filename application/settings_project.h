#ifndef SETTINGS_PROJECT_H
#define SETTINGS_PROJECT_H

#include <QObject>

class settings_project : public QObject
{
    Q_OBJECT
public:
    QString folder_project_way;
    QString name_project;
    QString database_folder;
    QString database_way;
    static settings_project* get_Instance()
    {
        static settings_project settings_object;
        return &settings_object;
    }
    QString get_folder_project_way() const;
    void set_folder_project_way(const QString &value);

    QString get_database_way() const;
    void set_database_way(const QString &value);

    QString get_database_folder() const;
    void set_database_folder(const QString &value);

    QString get_name_project() const;
    void set_name_project(const QString &value);

    void write_settings_in_file();
signals:

public slots:
private:
    settings_project();
};

#endif // SETTINGS_PROJECT_H
