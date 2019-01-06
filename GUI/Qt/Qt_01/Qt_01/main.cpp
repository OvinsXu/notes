#include "mainwindow.h"
#include <QApplication>
#include<QPushButton>
#include<QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*  1 创建一个QLabel

        QLabel * label = new QLabel("hello,world");
        label->show();
    */

    QPushButton *button = new QPushButton("Quit");
    QObject::connect(button, SIGNAL(clicked()), &a, SLOT(quit()));
    button->show();

    return a.exec();
}
