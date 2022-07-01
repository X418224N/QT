#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include<QPushButton>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
     MyPushButton(QString normalImg,QString pressedImg,QWidget *parent = nullptr);
     enum MyPushButtonStat{
         Normal,
         Pressed
     };

    //上下动画
    void moveDonw();
    void moveup();
protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    QString mNormalImg;
    QString mPressedImg;
    MyPushButtonStat mStat;
signals:

};

#endif // MYPUSHBUTTON_H
