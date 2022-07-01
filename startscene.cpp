#include "startscene.h"
#include<QPushButton>
#include"mypushbutton.h"
#include<QTimer>
#include<QSound>
StartScene::StartScene(QWidget *parent) : MyMainWindow(parent)
{
    this->setWindowTitle("开始场景");
    MyPushButton *btnstart=new MyPushButton(":/res/MenuSceneStartButton.png",":/res/MenuSceneStartButton.png",this);
    btnstart->resize(114,114);
    btnstart->move((this->width()-btnstart->width())/2,
                   this->height()*3/4-btnstart->height()/2);
    connect(&mselectscene,&selectscene::backbtnclicked,[=](){
        QSound::play(":/res/BackButtonSound.wav");
        this->show();
        this->mselectscene.hide();
        this->move(this->mselectscene.pos());

    });
    connect(btnstart,&MyPushButton::clicked,[=](){
        QSound::play(":/res/TapButtonSound.wav");
        btnstart->moveDonw();
        //将按钮停用
         btnstart->setEnabled(false);
        QTimer::singleShot(150,[=](){
            btnstart->moveup();
        });
        QTimer::singleShot(300,[=](){
            //将按钮可用
            btnstart->setEnabled(true);
        });
        this->hide();
        //显示第二个窗口
        this->mselectscene.show();
        this->mselectscene.move(this->pos());
    });
}


