#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include"mymainwindow.h"
#include<coinbutton.h>
class PlayScene : public MyMainWindow
{
    Q_OBJECT
public:
     PlayScene(int level,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    //翻动row行，col列
    void filp(int row,int col);
    void win();
signals:
    void backbtnclicked();
private:
    //存储数组的指针
    CoinButton *mCoins[4][4];
    //胜率状态
    bool mHASwin;
};

#endif // PLAYSCENE_H
