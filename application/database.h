#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>

class database : public QObject
{
    Q_OBJECT
public:
    explicit database(QObject *parent = nullptr);
    QSqlQueryModel *database_model;
    QSqlQueryModel* get_table_model(QString name_table);
    void do_sql_command(QString string_command);
    ~database();

    QStringList get_list_table();
signals:

public slots:
private:
    QSqlDatabase database_site;

};

#endif // DATABASE_H
