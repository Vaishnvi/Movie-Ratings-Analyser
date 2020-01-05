#ifndef MOVIE_INFO_H
#define MOVIE_INFO_H

#include <QDialog>

namespace Ui {
class movie_info;
}

class movie_info : public QDialog
{
    Q_OBJECT

public:
    explicit movie_info(QWidget *parent = 0);
    ~movie_info();

private slots:
    void on_back_clicked();

    void on_comment_clicked();

    void on_ok_clicked();

    void on_b_5_clicked();

    void on_b_4_clicked();

    void on_b_3_clicked();

    void on_b_2_clicked();

    void on_b_1_clicked();

    void on_com_ok_clicked();

private:
    Ui::movie_info *ui;
};

#endif // MOVIE_INFO_H
