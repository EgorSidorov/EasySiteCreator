/**
  @file
  @author Stefan Frings
*/

#include <QCoreApplication>
#include "requestmapper.h"
#include "filelogger.h"
#include "staticfilecontroller.h"
#include <QDir>
#include <QDebug>
#include <QTextCodec>
#include <settings_project.h>
#include "ddos_defender.h"

/** Redirects log messages to a file */
//extern FileLogger* logger;

/** Controller for static files */
//extern StaticFileController* staticFileController;

RequestMapper::RequestMapper(QStringList list_way_page, QStringList list_name_page, QObject* parent)
    :HttpRequestHandler(parent)
{
    qDebug("RequestMapper: created");
    this->list_way_page=list_way_page;
    this->list_name_page=list_name_page;
}


RequestMapper::~RequestMapper()
{
    qDebug("RequestMapper: deleted");
}


void RequestMapper::service(HttpRequest& request, HttpResponse& response)
{
    if(ddos_defender::getInstance()->ip_check(request.getPeerAddress()))
    {
    //страница сайта
    QByteArray path=request.getPath();

    int iter=0;
    foreach (QString way_page, list_way_page) {
        if(way_page==QString(path.data())){
            QDir dir;
            dir.cd(settings_project::get_Instance()->get_folder_project_way()+"/html");
            QFile file(dir.filePath(list_name_page.at(iter)));
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QByteArray html_array=file.readAll();
            obj_parser.set_string(QString::fromUtf8(html_array));
            obj_parser.obj_request=&request;
            obj_parser.obj_response=&response;
            QByteArray output_array;
            if(QString::fromUtf8(html_array).indexOf("[RETURN QBYTEARRAY]")==-1)
                response.write(output_array.append(obj_parser.choose_javascript_result().toUtf8()));
            else{
                response.write(obj_parser.choose_javascript_result_file());
            }
            file.close();
            return;
         }
        iter++;
    }
    //публичные ресурсы сайта
    QString folder_path=QString(path.data());
    if(QString(path.data()).indexOf("resource")!=-1){
        QDir dir;
        dir.cd(settings_project::get_Instance()->get_folder_project_way()+"/html");
            folder_path.remove(0,10);
            dir.cd("resource");
         qDebug()<<folder_path;

        QString file_path=dir.filePath(folder_path);
        QFile file(file_path);
        if(file.open(QIODevice::ReadOnly)){
            qDebug("open");
//            //response.setHeader("content-type","image/x-icon");
            response.write(file.readAll());
            file.close();
        }

    }
    }
    else
    {
        response.write("You are blocked");
    }


}
