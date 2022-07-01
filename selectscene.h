#ifndef SELECTSCENE_H
#define SELECTSCENE_H

#include <QMainWindow>
#include <QWidget>

#include"mymainwindow.h"
class selectscene : public MyMainWindow
{
    Q_OBJECT
public:
    explicit selectscene(QWidget *parent = nullptr);

signals:
    void backbtnclicked();
protected:
void paintEvent(QPaintEvent *event);
};

#endif // SELECTSCENE_H
