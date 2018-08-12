#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDir>
#include <QCoreApplication>
#include "requestmapper.h"
#include "templatecache.h"
#include "httpsessionstore.h"
#include "staticfilecontroller.h"
#include "filelogger.h"
#include <QSqlQueryModel>
#include <QFileDialog>
#include <settings_project.h>
#include <dialog_settings.h>

MainWindow::MainWindow(QApplication *app, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menubar->addAction("Загрузить проект",this,SLOT(on_action_load_project()));
    ui->menubar->addAction("Настройки сервера",this,SLOT(on_action_server_settings()));
    hasstarting = false;
    on_button_htmlcode_clicked();
    this->app=app;
    QDir dir;
    dir.mkdir(settings_project::get_Instance()->get_folder_project_way()+"/html");
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeWidget,&QTreeWidget::customContextMenuRequested,this,&MainWindow::prepareMenu);
    opensession(settings_project::get_Instance()->get_name_project());
    QFile counter_file(settings_project::get_Instance()->get_folder_project_way()+"/counter.txt");
    counter_file.open(QIODevice::ReadOnly|QIODevice::Text);
    counter=counter_file.readAll().toInt();
    counter_file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::settextitem(QTreeWidgetItem *item,QString first_text,QString second_text){
    item->setText(0,first_text);
    item->setText(1,second_text);
}

void MainWindow::on_pushButton_clicked()
{
    QTreeWidgetItem *item=new QTreeWidgetItem;
    item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsEditable|Qt::ItemIsSelectable);
    settextitem(item,"/new_page"+QString::number(counter),"Page"+QString::number(counter)+".html");
    counter++;
    ui->treeWidget->addTopLevelItem(item);
    full_way(item,"",0,item->text(1));
    QDir dir;
    dir.cd(settings_project::get_Instance()->get_folder_project_way()+"/html");
    QFile counter_file(settings_project::get_Instance()->get_folder_project_way()+"/counter.txt");
    counter_file.remove();
    counter_file.open(QIODevice::WriteOnly|QIODevice::Text);
    QByteArray array_counter_file;
    array_counter_file.append(QString::number(counter));
    counter_file.write(array_counter_file);
    counter_file.close();
    QFile file(dir.filePath(file_name_item));
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    file.write("Hello world");
    file.close();
}

void MainWindow::add_child_page()
{
    QTreeWidgetItem *item=new QTreeWidgetItem;
    item->setText(0,"/new_page"+QString::number(counter));
    item->setText(1,"Page"+QString::number(counter)+".html");
    counter++;
    item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsEditable|Qt::ItemIsSelectable);
    choose_item_menu->addChild(item);
    full_way(item,"",0,item->text(1));
    QDir dir;
    dir.cd(settings_project::get_Instance()->get_folder_project_way()+"/html");
    QFile counter_file(settings_project::get_Instance()->get_folder_project_way()+"/counter.txt");
    counter_file.remove();
    counter_file.open(QIODevice::WriteOnly|QIODevice::Text);
    QByteArray array_counter_file;
    array_counter_file.append(QString::number(counter));
    counter_file.write(array_counter_file);
    counter_file.close();
    QFile file(dir.filePath(file_name_item));
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    file.write("Hello world");
    file.close();
}

//role==0 - внести в файл проекта путь к новому добавленному элементу,
//role==1 - записать в переменную полный путь
void MainWindow::full_way(QTreeWidgetItem* item, QString now_way, int role, QString name_html){
    QString string_insert=item->text(0);
    now_way.insert(0,string_insert);
    if(role==0){
    if(item->parent()!=NULL)
        full_way(item->parent(),now_way,role,name_html);
    else{
        configuration.append(now_way+" "+name_html+"\n");
        QFile file(settings_project::get_Instance()->get_name_project());
        file.remove();
        file.open(QIODevice::WriteOnly|QIODevice::Text);
        QByteArray write_text;
        write_text.append(configuration);
        file.write(write_text);
        file.close();
        //ui->textEdit->setText(configuration);
        full_name_item=now_way;
        file_name_item=name_html;
    }
    } else if(role==1){
        if(item->parent()!=NULL)
            full_way(item->parent(),now_way,role,name_html);
        else{
            full_name_item=now_way;
            file_name_item=name_html;
        }
    }

}

void MainWindow::find_way_in_string_and_choose(QString *input_string, QString last_name, QString now_name, bool file_name)
{
    int index=input_string->indexOf(last_name);
    if(file_name)
        index=input_string->indexOf(" "+last_name);
    input_string->remove(index,last_name.length());
    if(file_name)
    {
        input_string->remove(index,1);
        input_string->insert(index," ");
        index++;
    }
    input_string->insert(index,now_name);

    //input_string->replace(last_name,now_name);
}

void MainWindow::set_table_model(QString name_table)
{
    ui->tableView->setModel(obj_database.get_table_model(name_table));
}

void MainWindow::opensession(QString full_session_way){
    QFile file_session(full_session_way);
    if(file_session.open(QIODevice::ReadOnly | QIODevice::Text)){
        configuration=QString(file_session.readAll());
        setitemfromconfiguration();
    } else
        ui->textEdit->setPlainText("Ошибка чтения сценария");

}

void MainWindow::additemconfigurationintree(QString mid_way,QString mid_page){
    list_way_page.append(mid_way);
    list_name_page.append(mid_page);
    mid_way.remove(0,1);
    if(mid_way.indexOf('/')==-1){
       QTreeWidgetItem *item=new QTreeWidgetItem;
       item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsEditable|Qt::ItemIsSelectable);
       mid_way.insert(0,'/');
       settextitem(item,mid_way,mid_page);
       ui->treeWidget->addTopLevelItem(item);
       list_page.append(item);
    } else {
        QTreeWidgetItem *memory_item;
        QString memory_full_way_item;
        bool first_item=true;
        mid_way.insert(0,'/');
        int iter_cycle=0;
        foreach (QTreeWidgetItem *item, list_page) {
            if(mid_way.indexOf(list_way_page.at(iter_cycle))==0){
                if(first_item){
                    memory_item=item;
                    memory_full_way_item=list_way_page.at(iter_cycle);
                    first_item=false;
                } else {
                    if(memory_full_way_item.length()<list_way_page.at(iter_cycle).length())
                        memory_item=item;
                        memory_full_way_item=list_way_page.at(iter_cycle);
                }

            }
            iter_cycle++;
        }
        QTreeWidgetItem *itemchild=new QTreeWidgetItem;
        itemchild->setFlags(Qt::ItemIsEnabled|Qt::ItemIsEditable|Qt::ItemIsSelectable);
        settextitem(itemchild,mid_way.mid(mid_way.lastIndexOf('/'),mid_way.length()),mid_page);
        memory_item->addChild(itemchild);
        list_page.append(itemchild);
    }


}

void MainWindow::setitemfromconfiguration(){
    int iter=0;
    int last_iter=0;
    QString mid_way;
    QString mid_page;
    while(iter!=configuration.length()){
        if(configuration[iter]==' '){
            mid_way=configuration.mid(last_iter,iter-last_iter);  
            last_iter=iter+1;
        }
        if(configuration[iter]=='\n'){
            mid_page=configuration.mid(last_iter,iter-last_iter);
            additemconfigurationintree(mid_way,mid_page);
            last_iter=iter+1;
        }
        iter++;
    }
}


void MainWindow::prepareMenu( const QPoint & pos )
{
QTreeWidget *tree = ui->treeWidget;

choose_item_menu = tree->itemAt( pos );

QAction *newAct = new QAction(QIcon(":/Resource/warning32.ico"), tr("&New"), this);
newAct->setStatusTip(tr("new sth"));
connect(newAct, SIGNAL(triggered()), this, SLOT(add_child_page()));


QMenu menu(this);
menu.addAction(newAct);

QPoint pt(pos);
menu.exec( tree->mapToGlobal(pos) );
}

void MainWindow::on_treeWidget_itemChanged(QTreeWidgetItem *item, int column)
{
    QString last_full_name_item=full_name_item;
    QString last_file_name_item=file_name_item;
    full_way(item,"",1,item->text(1));
    if(full_name_item != last_full_name_item)
        find_way_in_string_and_choose(&configuration,last_full_name_item,full_name_item,false);
    if(file_name_item != last_file_name_item)
        find_way_in_string_and_choose(&configuration,last_file_name_item,file_name_item,true);

    QFile file_html(settings_project::get_Instance()->get_folder_project_way()+"/html/"+last_file_name_item);
    file_html.rename(settings_project::get_Instance()->get_folder_project_way()+"/html/"+file_name_item);

    //конфигурация проекта
    QFile file(settings_project::get_Instance()->get_name_project());
    file.remove();
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QByteArray write_text;
    write_text.append(configuration);
    file.write(write_text);
    file.close();
    //ui->textEdit->setText(configuration);
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    //запишем полное имя файла в путь, чтобы можно было легко поменять его, если пользователь его переименует
    full_way(item,"",1,item->text(1));
    QDir dir;
    dir.cd(settings_project::get_Instance()->get_folder_project_way()+"/html");
    //QString copy_full_name_item=full_name_item;
    //dir.cd(copy_full_name_item.remove(0,1));
    QFile file(dir.filePath(item->text(1)));
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        ui->textEdit->setPlainText(QString(file.readAll()));
    }
    else
        ui->textEdit->setPlainText("error open html");
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile file(settings_project::get_Instance()->get_folder_project_way()+"/html/"+file_name_item);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QByteArray write_text;
    write_text.append(ui->textEdit->toPlainText());
    file.write(write_text);
    file.close();
}

void MainWindow::on_run_server_clicked()
{
    if(!hasstarting){
        hasstarting = true;
        QSettings* listenerSettings=new QSettings("etc/Demo1.ini",QSettings::IniFormat,app);
        listenerSettings->beginGroup("listener");
        listener = new HttpListener(listenerSettings,new RequestMapper(list_way_page,list_name_page,app),app);
    }
    if(ui->run_server->text() == "Запустить сервер"){
        listener->listen();
        ui->run_server->setText("Остановить сервер");
    }
    else if(ui->run_server->text() == "Остановить сервер"){
        listener->close();
        ui->run_server->setText("Запустить сервер");
    }
}

void MainWindow::on_button_htmlcode_clicked()
{
    ui->comboBox->setVisible(false);
    ui->tableView->setVisible(false);
    ui->Html->setVisible(true);
    ui->Server->setVisible(true);
    ui->create_table->setVisible(false);
    ui->delete_table->setVisible(false);
    ui->insert_row->setVisible(false);
    ui->remove_row->setVisible(false);
    ui->update_row->setVisible(false);
    on_Html_clicked();
    ui->button_htmlcode->setStyleSheet("background-color: orange");
    ui->button_database->setStyleSheet("background-color: grey");
}

void MainWindow::insert_database_button_into_layout(QStringList list_name_button){
    ui->comboBox->clear();
    foreach (QString name_button, list_name_button) {
        ui->comboBox->addItem(name_button);
    }

}

void MainWindow::on_button_database_clicked()
{
    insert_database_button_into_layout(obj_database.get_list_table());
    ui->comboBox->setVisible(true);
    ui->create_table->setVisible(true);
    ui->delete_table->setVisible(true);
    ui->insert_row->setVisible(true);
    ui->remove_row->setVisible(true);
    ui->Html->setVisible(false);
    ui->Server->setVisible(false);
    if(obj_database.get_list_table().length()>0)
        set_table_model(obj_database.get_list_table().at(0));
    ui->tableView->setVisible(true);
    ui->serveredit->setVisible(false);
    ui->textEdit->setVisible(false);
    ui->update_row->setVisible(true);
    ui->button_htmlcode->setStyleSheet("background-color: grey");
    ui->button_database->setStyleSheet("background-color: orange");
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    set_table_model(arg1);
}

void MainWindow::on_insert_row_clicked()
{
    QString string_command="INSERT INTO "+ui->comboBox->currentText()+" VALUES()";
    obj_database.do_sql_command(string_command);
    set_table_model(ui->comboBox->currentText());

}

void MainWindow::on_create_table_clicked()
{
    QString string_command="CREATE TABLE table_name ("
            "column1 datatype,"
            "column2 datatype"
        ");";
    obj_database.do_sql_command(string_command);
    insert_database_button_into_layout(obj_database.get_list_table());
}

void MainWindow::on_delete_table_clicked()
{
    QString string_command="DROP TABLE "+ui->comboBox->currentText();
    obj_database.do_sql_command(string_command);
    insert_database_button_into_layout(obj_database.get_list_table());
}

void MainWindow::on_remove_row_clicked()
{
    QString string_command="DELETE FROM "+ ui->comboBox->currentText() +" WHERE condition;";
    obj_database.do_sql_command(string_command);
    set_table_model(ui->comboBox->currentText());
}

void MainWindow::on_update_row_clicked()
{
    QString string_command="UPDATE "+ ui->comboBox->currentText() +" SET column1 = value1 WHERE condition;";
    obj_database.do_sql_command(string_command);
    set_table_model(ui->comboBox->currentText());
}

void MainWindow::on_action_load_project()
{
    QString way = QFileDialog::getExistingDirectory();
    if(!way.isEmpty())
        settings_project::get_Instance()->set_folder_project_way(way);

}

void MainWindow::on_action_server_settings()
{
    dialog_settings dialog;
    dialog.exec();
}

void MainWindow::on_Html_clicked()
{
    ui->serveredit->setVisible(false);
    ui->textEdit->setVisible(true);
}

void MainWindow::on_Server_clicked()
{
    ui->serveredit->setVisible(true);
    ui->textEdit->setVisible(false);
}
