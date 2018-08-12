#ifndef REQUEST_FOR_JAVASCRIPT_H
#define REQUEST_FOR_JAVASCRIPT_H

#include <QObject>
#include "httprequest.h"

class request_for_javascript : public QObject
{
    Q_OBJECT
public:
    explicit request_for_javascript(QObject *parent = nullptr);
    stefanfrings::HttpRequest* obj_request;
    Q_INVOKABLE QString get_body();
    Q_INVOKABLE QString get_cookie(QString name);
    Q_INVOKABLE QString get_parameter(QString name);
    Q_INVOKABLE QString get_header(QString name);
    Q_INVOKABLE QString get_path();
    Q_INVOKABLE QByteArray get_parameter_byte_array(QString name);
signals:

public slots:
};

#endif // REQUEST_FOR_JAVASCRIPT_H
