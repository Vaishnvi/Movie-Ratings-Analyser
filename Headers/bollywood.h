#ifndef BOLLYWOOD_H
#define BOLLYWOOD_H

#include <QDialog>
#include "movie_info.h"

namespace Ui {
class bollywood;
}

class bollywood : public QDialog
{
    Q_OBJECT

public:
    explicit bollywood(QWidget *parent = 0);
    ~bollywood();
    static int btn_no;
private slots:
    void testSlot();

    void on_pushButton_clicked();

    void on_search_clicked();

    void on_back_hm_clicked();

private:
    Ui::bollywood *ui;
    movie_info *mi;
};

#endif // BOLLYWOOD_H
