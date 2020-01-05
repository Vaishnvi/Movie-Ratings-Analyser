#include "bollywood.h"
#include "ui_bollywood.h"
#include "QPushButton"
#include "movie_info.h"
#include "qsqldatabase.h"
#include "qmessagebox.h"
#include "qsqlquery.h"
#include "QPixmap"
#include "QDebug"

bollywood::bollywood(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bollywood)
{
    ui->setupUi(this);
    QVector<QPushButton*> btn; // or std::vector

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
int n;
 query.prepare("select count(*) from v1");
  if(query.exec() && query.seek(0))
  {
    n=query.value(0).toString().toInt();
    qDebug() << n;
  }

    //ui-->addWidget();
    for(int j=0; j<n; j++)
    {
    QPushButton *b = new QPushButton;
    b->setObjectName(QString::number(j));
    b->setGeometry(0,0,40,40);
    ui->horizontalLayout->addWidget(b,Qt::AlignVCenter);
    connect(b, SIGNAL(clicked()), this, SLOT(testSlot()));

    btn << b;
    }
    db1.close();

}

int bollywood::btn_no;
void bollywood::testSlot()
{

  QObject *senderObj = sender();
  QString senderObjName = senderObj->objectName();
  int temp=senderObjName.toInt();
  bollywood::btn_no=temp;
  mi = new movie_info();
  mi->showMaximized();

}


bollywood::~bollywood()
{
    delete ui;
}

/*void bollywood::on_search_clicked()
{
    int yr=ui->year->text().toInt();

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
    query.prepare(" select * from v1");

    if(query.exec()){
        while (query.next()) {
            for(int i=0;i<=5;i++)
            {
            QString str = query.value(i).toString();
            ui->textEdit->append(str);
            }
        }
    }
    db.close();


}
*/

void bollywood::on_back_hm_clicked()
{

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
    query.prepare(" drop view v1");
    query.exec();
    this->close();

}
