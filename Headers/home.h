#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include "adminlogin.h"
#include "bollywood.h"

namespace Ui {
class Home;
}

class Home : public QMainWindow
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = 0);
    ~Home();

private slots:
    void on_admin_login_clicked();

    void on_bollywood_clicked();

private:
    Ui::Home *ui;
    AdminLogin *al;
    bollywood *bp;
};

#endif // HOME_H
