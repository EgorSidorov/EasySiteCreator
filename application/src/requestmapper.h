/**
  @file
  @author Stefan Frings
*/

#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H

#include "httprequesthandler.h"
#include "javascript_parser_runner.h"

using namespace stefanfrings;

/**
  The request mapper dispatches incoming HTTP requests to controller classes
  depending on the requested path.
*/

class RequestMapper : public HttpRequestHandler {
    Q_OBJECT
    Q_DISABLE_COPY(RequestMapper)
public:


    /**
      Constructor.
      @param parent Parent object
    */
    RequestMapper(QStringList list_way_page,QStringList list_name_page,QObject* parent=0);

    /**
      Destructor.
    */
    ~RequestMapper();

    /**
      Dispatch incoming HTTP requests to different controllers depending on the URL.
      @param request The received HTTP request
      @param response Must be used to return the response
    */
    void service(HttpRequest& request, HttpResponse& response);
private:
    QStringList list_way_page;
    QStringList list_name_page;
    javascript_parser_runner obj_parser;

};

#endif // REQUESTMAPPER_H
