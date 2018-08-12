# This project demonstrates how to use QtWebAppLib by including the
# sources into this project.

TARGET = Demo1
TEMPLATE = app
QT = core network widgets script sql
CONFIG += console

HEADERS += \
           src/requestmapper.h \
    src/mainwindow.h \
    javascript_parser_runner.h \
    database.h \
    dialog_sql_command.h \
    request_for_javascript.h \
    database_for_javascript.h \
    response_for_javascript.h \
    settings_project.h \
    dialog_settings.h \
    ddos_defender.h

SOURCES += src/main.cpp \
           src/requestmapper.cpp \
    src/mainwindow.cpp \
    javascript_parser_runner.cpp \
    database.cpp \
    dialog_sql_command.cpp \
    request_for_javascript.cpp \
    database_for_javascript.cpp \
    response_for_javascript.cpp \
    settings_project.cpp \
    dialog_settings.cpp \
    ddos_defender.cpp

OTHER_FILES += etc/* etc/docroot/* etc/templates/* etc/ssl/* logs/* ../readme.txt

#---------------------------------------------------------------------------------------
# The following lines include the sources of the QtWebAppLib library
#---------------------------------------------------------------------------------------

include(../QtWebApp/logging/logging.pri)
include(../QtWebApp/httpserver/httpserver.pri)
include(../QtWebApp/templateengine/templateengine.pri)
# Not used: include(../QtWebApp/qtservice/qtservice.pri)

FORMS += \
    src/mainwindow.ui \
    dialog_sql_command.ui \
    dialog_settings.ui
