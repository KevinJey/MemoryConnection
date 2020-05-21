#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QStack>
#include <myScence.h>
class myScence;
class myitem : public QGraphicsPixmapItem // 从QGraphicsPixmapItem类中继承而来的myitem
{
public:
    myitem();
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    int x;
    int y;
    int data;
    bool got_a_pair;
    bool flag;
    myScence *the_scence;
    int count;
    int len;
};
#endif // MYITEM_H
