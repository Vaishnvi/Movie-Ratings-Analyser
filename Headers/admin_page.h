#ifndef ADMIN_PAGE_H
#define ADMIN_PAGE_H

#include <QDialog>

namespace Ui {
class admin_page;
}

class admin_page : public QDialog
{
    Q_OBJECT

public:
    explicit admin_page(QWidget *parent = 0);
    ~admin_page();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_submit_clicked();

    void on_logout_clicked();

private:
    Ui::admin_page *ui;
};

#endif // ADMIN_PAGE_H
