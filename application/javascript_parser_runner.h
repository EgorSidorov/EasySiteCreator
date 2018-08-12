#ifndef JAVASCRIPT_PARSER_RUNNER_H
#define JAVASCRIPT_PARSER_RUNNER_H

#include <QObject>
#include "httprequest.h"
#include <QScriptValue>
#include <QScriptEngine>
#include "request_for_javascript.h"
#include "database_for_javascript.h"
#include "response_for_javascript.h"

class javascript_parser_runner : public QObject
{
    Q_OBJECT
public:
    explicit javascript_parser_runner(QObject *parent = nullptr);
    stefanfrings::HttpRequest* obj_request;
    stefanfrings::HttpResponse* obj_response;
    void set_string(QString start_string);
    QString choose_javascript_result();
    QByteArray choose_javascript_result_file();
    QScriptEngine obj_script_engine;
    request_for_javascript request_javascript;
    response_for_javascript response_javascript;
    database_for_javascript db_javascript;
    QScriptValue obj_script_request;
    QScriptValue obj_script_response;
    QScriptValue obj_script_db;

signals:

public slots:
private:
    QString parser_string;
    QString run_code(QString javascript_code);
};

#endif // JAVASCRIPT_PARSER_RUNNER_H
