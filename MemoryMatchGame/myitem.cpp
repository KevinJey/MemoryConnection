#include "myScence.h"
#include <QThread>
#include <QPixmap>
#include <QSize>
#include <QDebug>
#include <QStack>
#include <QWidget>
#include <QObject>
#include <QMessageBox>
#include <synchapi.h>
myitem::myitem()
{
    QPixmap pic;
    pic.load(":/new/prefix1/Block.png");
    QSize picSize(50,50); //修改成50*50的图
    QPixmap tmpPic = pic.scaled(picSize);
    this->setPixmap(tmpPic);
    //为每个方框进行初始化
    flag = false;
    got_a_pair=false;
    count=0;
    len=0;
}


void myitem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug()<<"按下";
    if(this->flag == true||this->the_scence->cooldown==1) return ; //如果没有出现延迟情况 则跳过已经被翻过的被点击的牌 如果出现了 则全部锁定 无法选中

    QSize pic(50,50);
    QString path = ":/new/prefix1/";
    QString fn ;
    int cutline;
    if(this->the_scence->typeButton == 1)
       fn = "ChineseNumber/",cutline=0;
    else if(this->the_scence->typeButton == 2)
        fn = "elements/",cutline=30;
    else
        fn = "pet/",cutline=100;
    qDebug()<<the_scence->typeButton;
    path.append(fn);

    QString filname = QString::number(data,10);//每一个item类对应的data文件名
    QString fileType = data<cutline?".jpg":".png"; //检查后缀名 防止打开失败
    path.append(filname);
    path.append(fileType);

 //   QPixmap beforPic(final);
    QPixmap nPic(path); //变换之后的图
    qDebug()<<path;
    this->setPixmap(nPic.scaled(pic)); //进行图片的缩放和改变


    if(this->the_scence->tempitemA==NULL){ //存第一张
        this->the_scence->tempitemA=this;
        this->the_scence->tempitemA->flag=true;
        return ;
    }else{

        this->the_scence->tempitemB=this;
        //this->the_scence->cooldown = 1;
        got_a_pair = true;
    }
}

void myitem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    qDebug()<<"松开";


    if(this->flag==true  || !got_a_pair || this->the_scence->cooldown==1 ) return ;
    this->the_scence->tempitemA->flag=this->the_scence->tempitemB->flag=true;

    this->the_scence->cooldown=1;   //进入只   看翻的牌啥都不干的挂机模式
    if(this->the_scence->tempitemA->data == this->the_scence->tempitemB->data){
        qDebug()<<"same";
        this->the_scence->tempitemA->flag=true;
        this->the_scence->tempitemB->flag=true;

    }
    else{
        qDebug()<<this->the_scence->delay;
        //QObject::connect(this->the_scence->tme, SIGNAL(timeout()), this->the_scence, SLOT(this->the_scence->update_cooldown()));

        QSize pic(50,50);
        QPixmap beforPic(":/new/prefix1/Block.png");
        this->the_scence->tempitemA->setPixmap(beforPic.scaled(pic));
        this->the_scence->tempitemB->setPixmap(beforPic.scaled(pic));
        this->the_scence->tempitemA->flag = this->the_scence->tempitemB->flag=false;

        //Sleep()
        QThread::sleep(0.5);

   //     this->the_scence->tme->start(1*1000);   //挂机x秒
    }

    this->the_scence->tempitemA = this->the_scence->tempitemB=NULL;
    got_a_pair=false;
    this->the_scence->cooldown=0;
}

