#include "request_for_javascript.h"
#include <QDebug>
#include <QByteArray>

request_for_javascript::request_for_javascript(QObject *parent) : QObject(parent)
{

}

QString request_for_javascript::get_body()
{
    return QString(obj_request->getBody());
}

QString request_for_javascript::get_path()
{
    return QString(obj_request->getPath());
}

QString request_for_javascript::get_header(QString name)
{
    QByteArray input_array;
    input_array.append(name);
    return QString(obj_request->getHeader(input_array));
}

QString request_for_javascript::get_parameter(QString name)
{
    QByteArray input_array;
    input_array.append(name);
    if(QString(obj_request->getParameter(input_array))!=""){
        return QString(obj_request->getParameter(input_array));
    }
    else {
        return "empty_string";
    }
}

QByteArray request_for_javascript::get_parameter_byte_array(QString name)
{
    QByteArray input_array;
    input_array.append(name);
    return obj_request->getUploadedFile(input_array)->readAll();
}

QString request_for_javascript::get_cookie(QString name)
{
    QByteArray input_array;
    input_array.append(name);
    if(QString(obj_request->getCookie(input_array))!=""){
        return QString(obj_request->getCookie(input_array));
    }
    else {
        return "invalid";
    }
}



