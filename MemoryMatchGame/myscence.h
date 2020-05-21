#ifndef MYSCENCE_H
#define MYSCENCE_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <myitem.h>
#include <QPixmap>
#include <mainwindow.h>
class MainWindow;
class myScence : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myScence(QGraphicsScene *parent = 0,int h = 4,int t = 2);

    myitem *items[8][8];
    myitem *tempitemA,*tempitemB;   //存储选取的一对牌
    QTimer *tme = new QTimer();
    int typeButton;
    int delay;
    int time_credit;
    int cooldown;
    MainWindow *mw;
    int len;
public slots:
    void update_cooldown();
};
#endif // MYSCENCE_H
