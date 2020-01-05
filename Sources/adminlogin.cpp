#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "admin_page.h"
#include "QMessageBox"
AdminLogin::AdminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);

}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::on_login_btn_clicked()
{
    QString uid,pswd;
    QMessageBox msg;
    uid=ui->userid->text();
    pswd=ui->passwd->text();

    if(uid=="a" && pswd=="a")
    {
        ap = new admin_page(this);
        ap->showMaximized();

    }
    else
    {
        msg.setText("Invalid Username Or Password.");
        msg.exec();
    }
    ui->userid->clear();
    ui->passwd->clear();

}

void AdminLogin::on_close_clicked()
{
    this->close();
}

void AdminLogin::on_clear_clicked()
{
    ui->userid->clear();
    ui->passwd->clear();

}
