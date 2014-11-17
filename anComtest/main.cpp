#include <QtGui/QApplication>
#include <QTextCodec>   //加入头文件
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    //使程序可处理中文
    MainWindow w;
    w.show();
    QObject::connect(&w,SIGNAL(myquit()),&a,SLOT(quit()));
    a.quit();
    return a.exec();
}
