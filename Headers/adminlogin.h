#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include "admin_page.h"

namespace Ui {
class AdminLogin;
}

class AdminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = 0);
    ~AdminLogin();

private slots:
    void on_pushButton_clicked();

    void on_login_btn_clicked();

    void on_cancel_clicked();

    void on_close_clicked();

    void on_clear_clicked();

private:
    Ui::AdminLogin *ui;
    admin_page *ap;
};

#endif // ADMINLOGIN_H
