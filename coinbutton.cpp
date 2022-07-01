#include "coinbutton.h"
#include<QPainter>
CoinButton::CoinButton(QWidget *parent) : QPushButton(parent)
{
    this->setStat(0);
    //设置按钮不规则样式，去掉边框
    this->setStyleSheet("QPushButton{border:0px;}");
    connect(&this->mTimer,&QTimer::timeout,[=](){
        if(this->mStat)
        {
            this->mFrame--;
        }
        else
        {
            this->mFrame++;
        }
//        this->mFrame++;
        //加载相应帧图片
       QString framename= QString(":/res/Coin000%1.png").arg(this->mFrame);
       this->setIcon(QIcon(framename));
       //停止计时器
       if(this->mFrame==8||this->mFrame==1)
       {
           this->mTimer.stop();
       }
    });
}

int CoinButton::stat() const
{
    return mStat;
}

void CoinButton::setStat(int stat)
{
    mStat = stat;
    if(this->mStat)
    {
        this->setIcon(QIcon(":/res/Coin0001.png"));
    }
    else
    {
    this->setIcon(QIcon(":/res/Coin0008.png"));
    }
    this->setIconSize(this->size());
}

void CoinButton::setStatWithAnimation(int stat)
{
    this->mStat=stat;
    if(this->mStat)
    {
        //mstat==1,表示银币翻金币
        this->mFrame=8;
    }
    else
    {
        //mstat==0,表示金币翻银币
        this->mFrame=1;
    }

    this->mTimer.start(30);
}

void CoinButton::flip()
{
//    this->setStat(!this->stat());
    this->setStatWithAnimation(!this->stat());
}

void CoinButton::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/BoardNode.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //调用父类paintevent
    QPushButton::paintEvent(ev);
}
