#include "movie_info.h"
#include "ui_movie_info.h"
#include "QPushButton"
#include "movie_info.h"
#include "qsqldatabase.h"
#include "qmessagebox.h"
#include "qsqlquery.h"
#include "QPixmap"
#include "QDebug"
#include "bollywood.h"

int rate=0;
QString str;
QString m_str;
 QString com;
movie_info::movie_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::movie_info)
{
    ui->setupUi(this);
    ui->commentframe->hide();
    ui->unameframe->hide();

    QSqlDatabase db1 = QSqlDatabase::addDatabase("QMYSQL");
    db1.setHostName("localhost");
    db1.setDatabaseName("movies");
    db1.setUserName("root");
    db1.setPassword("mysql");
    if(!db1.open())
        QMessageBox::warning(this,"Error","Unable to connect to the database");

    QSqlQuery query;
    query.prepare("use MovieRating");
    query.exec();

    query.prepare("select * from v1 order by Movies limit 1 offset :id");
    query.bindValue(":id",bollywood::btn_no);
   // query.exec();
    if(query.exec() && query.seek(0))
    {
        QString str=query.value(0).toString();
       // qDebug()<<str;
        ui->m_nm->setText(str);
    }
    if(query.exec() && query.seek(0))
    {
        QString str=query.value(1).toString();
       // qDebug()<<str;
        ui->m_yr->setText(str);
    }
    if(query.exec() && query.seek(0))
    {
        QString str=query.value(2).toString();
        //qDebug()<<str;
        ui->m_dir->setText(str);
    }
    if(query.exec() && query.seek(0))
    {
        QString str=query.value(3).toString();
        //qDebug()<<str;
        ui->m_cst->setText(str);
    }
    if(query.exec() && query.seek(0))
    {
        QString str=query.value(4).toString();
        //qDebug()<<str;
        ui->m_box->setText(str);
    }
  /*  QString avg;
    query.prepare("SELECT Avg(rate) FROM rating where movie=:mv");
    query.bindValue(":mv",str);
    query.exec();
    if(query.exec() && query.seek(0))
    {
        avg = query.value(0).toString();
        qDebug()<<avg;
    }
*/
    QString m1,n;
    m1=ui->m_nm->text();

     query.prepare("SELECT Avg(rate) FROM rating where movie=:mv");
         query.bindValue(":mv",m1);
      if(query.exec() && query.seek(0))
      {
       n=query.value(0).toString();
        qDebug() << n;
      }

    ui->avg_rating->setText(n);

    db1.close();

}


movie_info::~movie_info()
{
    delete ui;
}

void movie_info::on_back_clicked()
{
    this->close();
}

void movie_info::on_comment_clicked()
{
    ui->unameframe->show();
    ui->uname->clear();
}

void movie_info::on_ok_clicked()
{
    str=ui->uname->text();
    m_str=ui->m_nm->text();
    qDebug()<<str<<" "<<m_str;
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

    query.prepare("select * from rating where user=:str AND movie=:m_str");
    query.bindValue(":str",str);
    query.bindValue(":m_str",m_str);

    QMessageBox msg;
    if(query.exec() && query.seek(0))
    {
      QString disp=query.value(0).toString();
       qDebug()<<disp;
      if(str==disp)
      {
          msg.setText("username already exists.");
          msg.exec();
      }
  }
    else
      {
          ui->commentframe->show();
          ui->rateframe->show();
          ui->commentbx->clear();

      }
      //qDebug() << disp;


    db.close();
    ui->unameframe->hide();
 }

void movie_info::on_b_5_clicked()
{
    rate=5;
    ui->rateframe->close();
}

void movie_info::on_b_4_clicked()
{
    rate=4;
    ui->rateframe->close();

}

void movie_info::on_b_3_clicked()
{rate=3;
    ui->rateframe->close();

}

void movie_info::on_b_2_clicked()
{
    rate=2;
    ui->rateframe->close();

}

void movie_info::on_b_1_clicked()
{
    rate=1;
    ui->rateframe->close();

}

void movie_info::on_com_ok_clicked()
{
    com=ui->commentbx->toPlainText();
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

    query.prepare("insert into rating (user,movie,comments,rate)"
                                 "VALUES(:user,:movie,:comments,:rate)");
                     query.bindValue(":user",str);
                     query.bindValue(":movie",m_str);
                     query.bindValue(":comments",com);
                     query.bindValue(":rate",rate);

      qDebug()<<rate<<" "<<com;

     query.exec();


    db.close();
    ui->commentframe->hide();
}
