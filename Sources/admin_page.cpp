#include "admin_page.h"
#include "ui_admin_page.h"
#include "qsqldatabase.h"
#include "qmessagebox.h"
#include "qsqlquery.h"
#include "QPixmap"
#include  "QImage"


admin_page::admin_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_page)
{
    ui->setupUi(this);
}

admin_page::~admin_page()
{
    delete ui;
}

void admin_page::on_submit_clicked()
{
    QString name=ui->name->toPlainText();
    int year=ui->year->toPlainText().toInt();
    QString dir=ui->director->toPlainText();
    QString cast=ui->cast->toPlainText();
    int boxofc=ui->boxoffice->toPlainText().toInt();
    QString path=ui->poster->toPlainText();
    // QString=ui->name->toPlainText();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("movies");
    db.setUserName("root");
    db.setPassword("mysql");
    if(!db.open())
        QMessageBox::warning(this,"Error","Unable to connect to the database");

    QSqlQuery query;
    query.prepare("use MovieRating");
    query.exec();

    query.prepare("INSERT INTO Movies_Info(Movies,Year,Director,Cast,BoxOffice,Poster)"
                     "VALUES(:Movies,:Year,:Director,:Cast,:BoxOffice,:Poster)");
         query.bindValue(":Movies",name);
         query.bindValue(":Year",year);
         query.bindValue(":Director",dir);
         query.bindValue(":Cast",cast);
         query.bindValue(":BoxOffice",boxofc);
         query.bindValue(":Poster",path);

        query.exec();


    db.close();
    ui->name->clear();
    ui->cast->clear();
    ui->boxoffice->clear();
    ui->director->clear();
    ui->year->clear();
    ui->poster->clear();


}

void admin_page::on_logout_clicked()
{
    this->close();

}
