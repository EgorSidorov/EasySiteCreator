#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QApplication>
#include "database.h"
#include <QVBoxLayout>
#include <QPushButton>
#include "httplistener.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QApplication *app,QWidget *parent = 0);
    void full_way(QTreeWidgetItem* item, QString now_way, int role, QString name_html=NULL);
    void find_way_in_string_and_choose(QString *input_string,QString last_name,QString now_name,bool file_name);
    int counter=1;
    database obj_database;

    void set_table_model(QString name_table);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void add_child_page();

    void on_treeWidget_itemChanged(QTreeWidgetItem *item, int column);

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_pushButton_2_clicked();

    void on_run_server_clicked();

    void on_button_htmlcode_clicked();

    void on_button_database_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_insert_row_clicked();

    void on_create_table_clicked();

    void on_delete_table_clicked();

    void on_remove_row_clicked();

    void on_update_row_clicked();

    void on_action_load_project();

    void on_action_server_settings();
    void on_Html_clicked();

    void on_Server_clicked();

private:
    QList<QTreeWidgetItem*> list_page;
    stefanfrings::HttpListener *listener;
    QStringList list_way_page;
    QStringList list_name_page;
    QTreeWidgetItem* choose_item_menu;
    QTreeWidgetItem* item_change_name;
    QString full_name_item;
    QString file_name_item;
    Ui::MainWindow *ui;
    QString configuration;
    QApplication *app;
    bool hasstarting;
    void prepareMenu(const QPoint &pos);
    void opensession(QString full_session_way);
    void additemconfigurationintree(QString mid_way, QString mid_page);
    void setitemfromconfiguration();
    void settextitem(QTreeWidgetItem *item, QString first_text, QString second_text);
    void insert_database_button_into_layout(QStringList list_name_button);
};

#endif // MAINWINDOW_H
