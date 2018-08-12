#ifndef RESPONSE_FOR_JAVASCRIPT_H
#define RESPONSE_FOR_JAVASCRIPT_H

#include <QObject>
#include "httpresponse.h"
class response_for_javascript : public QObject
{
    Q_OBJECT
public:
    explicit response_for_javascript(QObject *parent = nullptr);
    stefanfrings::HttpResponse* obj_response;
    Q_INVOKABLE void set_cookie(QString name, QString value, QString domain, bool httponly=true, QString path="\\", int MaxAge=86000);
    Q_INVOKABLE void set_header(QString name, QString value);
signals:

public slots:
};

#endif // RESPONSE_FOR_JAVASCRIPT_H
