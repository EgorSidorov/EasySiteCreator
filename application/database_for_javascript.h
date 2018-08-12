#ifndef DATABASE_FRO_JAVASCRIPT_H
#define DATABASE_FRO_JAVASCRIPT_H

#include <QObject>
#include <QtSql>

class database_for_javascript : public QObject
{
    Q_OBJECT
public:
    explicit database_for_javascript(QObject *parent = nullptr);
    Q_INVOKABLE QString string_answer(QString db_request);
    Q_INVOKABLE QByteArray qbytearray_answer(QString db_request);
    Q_INVOKABLE void no_answer(QString db_request);
    Q_INVOKABLE void set_file(QString db_request, QString bind_name_file, QByteArray file);
    Q_INVOKABLE QStringList stringlist_answer(QString db_request);
signals:

public slots:
private:
    QSqlDatabase database_site;
};

#endif // DATABASE_FRO_JAVASCRIPT_H
