#include "selectscene.h"
#include<QPushButton>
#include<QPainter>
#include<QMenuBar>
#include"mypushbutton.h"
#include"playscene.h"
#include<QSound>
selectscene::selectscene(QWidget *parent) : MyMainWindow(parent)
{
    MyPushButton *btnback=new MyPushButton(":/res/BackButtonSelected.png",":/res/BackButton.png",this);
    btnback->resize(72,32);
    btnback->move(this->width()-btnback->width(),this->height()-btnback->height());
    connect(btnback,&QPushButton::clicked,this,&selectscene::backbtnclicked);
    const int colwidth=70;
    const int rowheight=70;
    //xy偏移
    const int x0ffset=25;
    const int y0ffset=130;
    for(int i=0;i<20;i++)
    {
        MyPushButton *btn=new MyPushButton(":/res/LevelIcon.png",":/res/LevelIcon.png",this);
        btn->setText(QString::number(i+1));
        //排列
        //行i/4
        int row=i/4;
        //列i%4
        int col=i%4;
        //x坐标=列数*列宽+x偏移
        int x=col*colwidth+x0ffset;
        //y坐标=行数*行高+y偏移
        int y=row*rowheight+y0ffset;
        btn->resize(57,57);
        btn->move(x,y);
        connect(btn,&MyPushButton::clicked,[=](){
            QSound::play(":/res/TapButtonSound.wav");
            PlayScene *playscene=new PlayScene(i+1);
            //设置playscene关闭的时候自动释放
            playscene->setAttribute(Qt::WA_DeleteOnClose);
            playscene->show();
            playscene->move(this->pos());
            this->hide();
            connect(playscene,&PlayScene::backbtnclicked,[=](){
                QSound::play(":/res/BackButtonSound.wav");
                this->show();
                this->move(playscene->pos());
                playscene->close();
            });
        });
    }
}

void selectscene::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    //搬动画家到菜单栏下面
    painter.translate(0,this->menuBar()->height());
    //背景
    QPixmap pix(":/res/OtherSceneBg.png");
   painter.drawPixmap(0,0,this->width(),this->height(),pix);
   //logo
   pix.load(":/res/Title.png");
    painter.drawPixmap(0,0,pix);

}
