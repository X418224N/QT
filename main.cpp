#include "mymainwindow.h"
#include"startscene.h"
#include <QApplication>
#include"selectscene.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MyMainWindow w;
//    w.show();
    //开始场景
    StartScene sc;
    sc.show();
    //选择场景
//    selectscene sc;
//    sc.show();
    return a.exec();
}
