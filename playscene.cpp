#include "playscene.h"
#include"mypushbutton.h"
#include<QPainter>
#include<QMenuBar>
#include<QLabel>
#include"coinbutton.h"
#include"dataconfig.h"
#include<QTimer>
#include<QMessageBox>
#include<QLabel>
#include<QPropertyAnimation>
#include<QSound>
PlayScene::PlayScene(int level,QWidget *parent) : MyMainWindow(parent)
{
    mHASwin=false;
   MyPushButton *btnback=new MyPushButton(":/res/BackButtonSelected.png",":/res/BackButton.png",this);
    btnback->resize(72,32);
     connect(btnback,&QPushButton::clicked,this,&PlayScene::backbtnclicked);
    btnback->move(this->width()-btnback->width(),this->height()-btnback->height());
    QLabel *label=new QLabel(this);
    //
    label->setText(QString("Level:%1").arg(level));
    label->setFont(QFont("华文新魏",20));
    //
    label->move(30,this->height()-label->height());
    //16个硬币按钮
    const int colwidth=50;
    const int rowheight=50;
    const int x0ffset=57;
    const int y0ffset=200;
    dataConfig data;
    QVector<QVector<int>>dataarray=data.mData[level];
    for(int row=0;row<4;++row)
    {
        for(int col=0;col<4;++col)
        {
            CoinButton*btn=new CoinButton(this);
            mCoins[row][col]=btn;
            int x=col*colwidth+x0ffset;
            int y=row*rowheight+y0ffset;
            btn->setGeometry(x,y,50,50);
            //设置row行col列的值，从dataconfig数据中获取
            btn->setStat(dataarray[row][col]);
            //每次点击硬币改变状态
            connect(btn,&CoinButton::clicked,[=](){
//                btn->flip();
                this->filp(row,col);
            });
        }
    }
}
void PlayScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.translate(0,this->menuBar()->height());
    QPixmap pix(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,pix);
    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()/2,pix.height()/2);
    painter.drawPixmap(0,0,pix);
}

void PlayScene::filp(int row, int col)
{
    if(mHASwin)
    {return;}
    this->mCoins[row][col]->flip();
    QSound::play(":/res/ConFlipSound.wav");
    //延时
    QTimer::singleShot(250,[=](){
        //翻动上下左右的硬币
        //下
        if(row+1<4)
        {this->mCoins[row+1][col]->flip();}
        //上
        if(row-1>=0)
        {this->mCoins[row-1][col]->flip();}
        //左
        if(col-1>=0)
        {this->mCoins[row][col-1]->flip();}
        //右
        if(col+1<4)
        {this->mCoins[row][col+1]->flip();}
        //判断胜利
        this->win();

    });

}

void PlayScene::win()
{
    int i=0;
    for(int row=0;row<4;++row)
    {
        for(int col=0;col<4;++col)
        {
            if(this->mCoins[row][col]->stat())
            {
                i++;
            }
            if(i==16)
            {
//                QMessageBox::information(this,"你胜利了","你胜利了");
                mHASwin=true;
            QLabel *labelwin=new QLabel(this);
            QPixmap pix=QPixmap(":/res/LevelCompletedDialogBg.png");
            labelwin->setPixmap(pix);
            labelwin->resize(pix.size());
            labelwin->move((this->width()-labelwin->width())/2,-labelwin->height());
            QPropertyAnimation *animation=new QPropertyAnimation(labelwin,"geometry",this);
            animation->setStartValue(labelwin->geometry());
            animation->setEndValue(QRect(labelwin->x(),labelwin->y()+100,labelwin->width(),labelwin->height()));
            animation->setDuration(1000);
            //动画播放完自动删除对象
            animation->start(QAbstractAnimation::DeleteWhenStopped);
            labelwin->show();
            QSound::play(":/res/LevelWinSound.wav");
                return;
            }
        }
        }
}
