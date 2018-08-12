#include "javascript_parser_runner.h"
#include <QDebug>
#include <QScriptClass>
javascript_parser_runner::javascript_parser_runner(QObject *parent) : QObject(parent)
{
    obj_script_request = obj_script_engine.newQObject(&request_javascript);
    obj_script_engine.globalObject().setProperty("request",obj_script_request);
    obj_script_response = obj_script_engine.newQObject(&response_javascript);
    obj_script_engine.globalObject().setProperty("response",obj_script_response);
    obj_script_db = obj_script_engine.newQObject(&db_javascript);
    obj_script_engine.globalObject().setProperty("db",obj_script_db);
}

void javascript_parser_runner::set_string(QString start_string)
{
    this->parser_string=start_string;
}

QString javascript_parser_runner::choose_javascript_result()
{
    request_javascript.obj_request = obj_request;
    response_javascript.obj_response = obj_response;
    QString sign_javascript_string="@@js(";
    QString sign_javascript_string_no_answer="@@jsnoanswer(";
    QString true_string_begin="if(true){";
    QString string_end="}endif";
    QString false_string_begin="if(false){";
    //цикл вначале выполняет условия в if(), потом только javascript код на сервере(чтобы javascript код не был выполнен внутри if(false)
    //за один проход выполняется только один скрипт, чтобы потом проверить, не выдает ли он if(true) или if(false)
    while(parser_string.indexOf(sign_javascript_string)!=-1 || parser_string.indexOf(sign_javascript_string_no_answer)!=-1 || parser_string.indexOf(true_string_begin)!=-1 || parser_string.indexOf(false_string_begin)!=-1){
        //вывод только той части страницы, где if(true), удаление той, где if(false)
        while(parser_string.indexOf(true_string_begin)!=-1){
            int input_index=parser_string.indexOf(true_string_begin);
            parser_string.remove(input_index,true_string_begin.length());
            int output_index=parser_string.indexOf(string_end,input_index);
            parser_string.remove(output_index,string_end.length());
        }
        while(parser_string.indexOf(false_string_begin)!=-1){
            int input_index=parser_string.indexOf(false_string_begin);
            int output_index=parser_string.indexOf(string_end,input_index);
            parser_string.remove(output_index,string_end.length());
            parser_string.remove(input_index,output_index-input_index);
        }
        //заменяем код javascript на результат работы этого кода
        if((parser_string.indexOf(sign_javascript_string)!=-1 && parser_string.indexOf(sign_javascript_string_no_answer)==-1) || (parser_string.indexOf(sign_javascript_string)!=-1 && parser_string.indexOf(sign_javascript_string)<parser_string.indexOf(sign_javascript_string_no_answer))){
            int input_index=parser_string.indexOf(sign_javascript_string);
            //удаляем строку, говорящую о том, что это javascript
            parser_string.remove(input_index,sign_javascript_string.length());
            if(parser_string.indexOf(")@@")==-1){
                qDebug()<<"not end symbol )@@";
                return "error_parsing";
            } else {
                //отдаем код на исполнение, а вместо кода вставляем результат работы
                int output_index=parser_string.indexOf(")@@");
                QString javascript_code=parser_string.mid(input_index,output_index-input_index);
                parser_string.remove(input_index,output_index-input_index);
                parser_string.remove(input_index,3);
                parser_string.insert(input_index,run_code(javascript_code));

            }
        }
        //код без ответа
        else if(parser_string.indexOf(sign_javascript_string_no_answer)!=-1){
            int input_index=parser_string.indexOf(sign_javascript_string_no_answer);
            //удаляем строку, говорящую о том, что это javascript
            parser_string.remove(input_index,sign_javascript_string_no_answer.length());
            if(parser_string.indexOf(")@@")==-1){
                qDebug()<<"not end symbol )@@";
                return "error_parsing";
            } else {
                //отдаем код на исполнение, результат не вставляем
                int output_index=parser_string.indexOf(")@@");
                QString javascript_code=parser_string.mid(input_index,output_index-input_index);
                parser_string.remove(input_index,output_index-input_index);
                parser_string.remove(input_index,3);
                run_code(javascript_code);

            }
        }
    }
    return parser_string;
}

QByteArray javascript_parser_runner::choose_javascript_result_file()
{
    request_javascript.obj_request = obj_request;
    response_javascript.obj_response = obj_response;
    QString sign_javascript_string="@@js(";
    QString sign_javascript_string_no_answer="@@jsnoanswer(";
    QString true_string_begin="if(true){";
    QString string_end="}endif";
    QString false_string_begin="if(false){";
    //цикл вначале выполняет условия в if(), потом только javascript код на сервере(чтобы javascript код не был выполнен внутри if(false)
    //за один проход выполняется только один скрипт, чтобы потом проверить, не выдает ли он if(true) или if(false)
    while(parser_string.indexOf(sign_javascript_string)!=-1 || parser_string.indexOf(sign_javascript_string_no_answer)!=-1 || parser_string.indexOf(true_string_begin)!=-1 || parser_string.indexOf(false_string_begin)!=-1){
        //вывод только той части страницы, где if(true), удаление той, где if(false)
        while(parser_string.indexOf(true_string_begin)!=-1){
            int input_index=parser_string.indexOf(true_string_begin);
            parser_string.remove(input_index,true_string_begin.length());
            int output_index=parser_string.indexOf(string_end,input_index);
            parser_string.remove(output_index,string_end.length());
        }
        while(parser_string.indexOf(false_string_begin)!=-1){
            int input_index=parser_string.indexOf(false_string_begin);
            int output_index=parser_string.indexOf(string_end,input_index);
            parser_string.remove(output_index,string_end.length());
            parser_string.remove(input_index,output_index-input_index);
        }
        //заменяем код javascript на результат работы этого кода
        if((parser_string.indexOf(sign_javascript_string)!=-1 && parser_string.indexOf(sign_javascript_string_no_answer)==-1) || (parser_string.indexOf(sign_javascript_string)!=-1 && parser_string.indexOf(sign_javascript_string)<parser_string.indexOf(sign_javascript_string_no_answer))){
            int input_index=parser_string.indexOf(sign_javascript_string);
            //удаляем строку, говорящую о том, что это javascript
            parser_string.remove(input_index,sign_javascript_string.length());
            if(parser_string.indexOf(")@@")==-1){
                qDebug()<<"not end symbol )@@";
                return "error_parsing";
            } else {
                //отдаем код на исполнение, а вместо кода вставляем результат работы
                int output_index=parser_string.indexOf(")@@");
                QString javascript_code=parser_string.mid(input_index,output_index-input_index);
                parser_string.remove(input_index,output_index-input_index);
                parser_string.remove(input_index,3);
                parser_string.insert(input_index,run_code(javascript_code));

            }
        }
        //код без ответа
        else if(parser_string.indexOf(sign_javascript_string_no_answer)!=-1){
            int input_index=parser_string.indexOf(sign_javascript_string_no_answer);
            //удаляем строку, говорящую о том, что это javascript
            parser_string.remove(input_index,sign_javascript_string_no_answer.length());
            if(parser_string.indexOf(")@@")==-1){
                qDebug()<<"not end symbol )@@";
                return "error_parsing";
            } else {
                //отдаем код на исполнение, результат не вставляем
                int output_index=parser_string.indexOf(")@@");
                QString javascript_code=parser_string.mid(input_index,output_index-input_index);
                parser_string.remove(input_index,output_index-input_index);
                parser_string.remove(input_index,3);
                run_code(javascript_code);

            }
        }
    }
    if( parser_string.indexOf("db_request=")!=-1){
        int begin_position=parser_string.indexOf("db_request=");
        QString db_request=parser_string.mid(begin_position+11,parser_string.indexOf("return",begin_position)-begin_position-11);
        qDebug()<<db_request;
        return db_javascript.qbytearray_answer(db_request);
    }
    return QByteArray("NULL");
}

QString javascript_parser_runner::run_code(QString javascript_code){

    return obj_script_engine.evaluate(javascript_code).toString();
}


