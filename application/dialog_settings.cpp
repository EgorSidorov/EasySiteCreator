#include "dialog_settings.h"
#include "ui_dialog_settings.h"
#include "settings_project.h"
#include "QFileDialog"

dialog_settings::dialog_settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_settings)
{
    ui->setupUi(this);
    ui->folder_database->setText(settings_project::get_Instance()->get_database_folder());
    ui->folder_project->setText(settings_project::get_Instance()->get_folder_project_way());
    ui->way_database->setText(settings_project::get_Instance()->get_database_way());
    ui->way_project->setText(settings_project::get_Instance()->get_name_project());
}

dialog_settings::~dialog_settings()
{
    delete ui;
}

void dialog_settings::on_set_folder_database_clicked()
{
    settings_project::get_Instance()->set_database_folder(QFileDialog::getExistingDirectory());
    ui->folder_database->setText(settings_project::get_Instance()->get_database_folder());
}

void dialog_settings::on_set_way_database_clicked()
{
    settings_project::get_Instance()->set_database_way(QFileDialog::getOpenFileName());
    ui->way_database->setText(settings_project::get_Instance()->get_database_way());
}

void dialog_settings::on_set_folder_project_clicked()
{
    settings_project::get_Instance()->set_folder_project_way(QFileDialog::getExistingDirectory());
    ui->folder_project->setText(settings_project::get_Instance()->get_folder_project_way());
}

void dialog_settings::on_set_way_project_clicked()
{
    settings_project::get_Instance()->set_name_project(QFileDialog::getExistingDirectory());
    ui->way_project->setText(settings_project::get_Instance()->get_name_project());
}

void dialog_settings::on_yes_accepted()
{
    settings_project::get_Instance()->set_database_folder(ui->folder_database->text());
    settings_project::get_Instance()->set_database_way(ui->way_database->text());
    settings_project::get_Instance()->set_folder_project_way(ui->folder_project->text());
    settings_project::get_Instance()->set_name_project(ui->way_project->text());
    settings_project::get_Instance()->write_settings_in_file();
}
