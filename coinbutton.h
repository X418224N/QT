#ifndef COINBUTTON_H
#define COINBUTTON_H

#include <QWidget>
#include<QPushButton>
#include<QTimer>
class CoinButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CoinButton(QWidget *parent = nullptr);

    int stat() const;
    void setStat(int stat);
    //setstat带动画函数
    void setStatWithAnimation(int stat);
    //硬币反转 函数
    void flip();
signals:
private:
    int mStat;
    int mFrame;
    QTimer mTimer;
protected:
    void paintEvent(QPaintEvent *ev);
};

#endif // COINBUTTON_H
