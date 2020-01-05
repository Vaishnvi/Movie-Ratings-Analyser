#include "home.h"
#include "ui_home.h"
#include "bollywood.h"
#include "QPushButton"
#include "movie_info.h"
#include "qsqldatabase.h"
#include "qmessagebox.h"
#include "qsqlquery.h"
#include "QPixmap"
#include "QDebug"



Home::Home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    QPixmap b("/home/pooja/Desktop/qt/MovieRatings/PopWallpaper.jpg");
    b=b.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette p;
    p.setBrush(QPalette::Background,b);
    this->setPalette(p);

}

Home::~Home()
{
    delete ui;
}

void Home::on_admin_login_clicked()
{
    al = new AdminLogin(this);
    al->showMaximized();

}

void Home::on_bollywood_clicked()
{
    int yr=ui->inp_yr->text().toInt();
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
    query.prepare(" create view v1 as select * from Movies_Info where Year=:yr");
    query.bindValue(":yr",yr);
    query.exec();
    /*query.prepare(" select * from v1");

    if(query.exec()){
        while (query.next()) {
            for(int i=0;i<=5;i++)
            {
            QString str = query.value(i).toString();
            ui->textEdit->append(str);
            }
        }
    }
    */
    db.close();

    bp = new bollywood(this);
    bp->showMaximized();

}
