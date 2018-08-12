#include "response_for_javascript.h"

response_for_javascript::response_for_javascript(QObject *parent) : QObject(parent)
{

}

void response_for_javascript::set_header(QString name, QString value)
{
    QByteArray input_name;
    input_name.append(name);
    QByteArray input_value;
    input_value.append(value);
    obj_response->setHeader(input_name, input_value);
}

void response_for_javascript::set_cookie(QString name, QString value, QString domain, bool httponly, QString path, int MaxAge)
{
    QByteArray input_name;
    input_name.append(name);
    QByteArray input_value;
    input_value.append(value);
    QByteArray input_domain;
    input_domain.append(domain);
    QByteArray input_path;
    input_path.append(path);
    stefanfrings::HttpCookie cookie;
    cookie.setDomain(input_domain);
    cookie.setName(input_name);
    cookie.setValue(input_value);
    cookie.setPath(input_path);
    cookie.setHttpOnly(httponly);
    cookie.setMaxAge(MaxAge);
    obj_response->setCookie(cookie);
}
