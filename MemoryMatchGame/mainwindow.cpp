#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QProgressBar>
#include <QString>
#include <QLabel>
#include <QEventLoop>
#include <myScence.h>
#include <QDebug>
#include <QTimer>
#include<QKeyEvent>
#include <QTime>
#include <cstdlib>
#include <QDialog>
#include <iostream>
#include <QDebug>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->myGraphicsView->setScene(sc); //myGraphicsView
    this->ui->radioButton->setChecked(true);

    this->grabKeyboard();
    type = 0;
    timer = new QTimer();
   // connect(timer, SIGNAL(timeout()), this, SLOT(update_time()));
 //   timer->start(1000);
   // this->time = new QTimer();
 //   time = new QTime();
   // time->restart();
}

MainWindow::~MainWindow() //析构函数
{
    delete sc;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    type=1;
    this->sc = new myScence(0,4,6);
    this->sc->typeButton = judge();
    this->sc->mw = this;
    this->ui->myGraphicsView->setScene(sc);
    showIt();
    //在按下push_button 的时候 临时创建一个timer
  //  this->sc->time_credit=0;
  //  time->restart();
}

void MainWindow::on_pushButton_2_clicked()
{
    type=2;
    this->sc = new myScence(0,6,4);
    this->sc->typeButton = judge();
    this->sc->mw = this;
    this->ui->myGraphicsView->setScene(sc);
    showIt();
 //   time->restart();
//    this->sc->time_credit=0;
//    timer->start(1000);

}

void MainWindow::on_pushButton_3_clicked()
{
    type=3;
    this->sc = new myScence(0,8,2);
    this->sc->typeButton = judge();
    this->sc->mw = this;
    this->ui->myGraphicsView->setScene(sc);
    showIt();
  //  time->restart();
 //   this->sc->time_credit=0;
 //   timer->start(1000);

}

int MainWindow::judge(){
    if(this->ui->radioButton->isChecked()) return 1;
    else if(this->ui->radioButton_2->isChecked()) return 2;
    else return 3;
}
/*
void MainWindow::update_time(){
    this->ui->lineEdit->setText(QString::number(this->sc->time_credit));
   // qDebug()<<QString::number(this->time_credit,10);
}
*/

void MainWindow::showIt(){
    this->sc->cooldown = 1;
    int len = 2*type+2;
    for(int i=0;i<len;++i){
        for(int j=0;j<len;++j){
            QSize pic(50,50);
            QString path = ":/new/prefix1/";
            QString fn ;
            int cutline;
            if(this->sc->typeButton == 1)
               fn = "ChineseNumber/",cutline=0;
            else if(this->sc->typeButton == 3)
                fn = "elements/",cutline=30;
            else
                fn = "pet/",cutline=100;
            path.append(fn);

            QString filname = QString::number(this->sc->items[i][j]->data,10);//每一个item类对应的data文件名
            QString fileType = this->sc->items[i][j]->data<cutline?".jpg":".png"; //检查后缀名 防止打开失败
            path.append(filname);
            path.append(fileType);

         //   QPixmap beforPic(final);
            QPixmap nPic(path); //变换之后的图
            qDebug()<<path;
            this->sc->items[i][j]->setPixmap(nPic.scaled(pic)); //进行图片的缩放和改变
        }
    }
   /* connect(timer,SIGNAL(timeout()),this,SLOT(up()));
    timer->start(this->sc->typeButton*1000);
    QThread::sl*/
    QEventLoop eventloop;
    QTimer::singleShot(1000*type*2, &eventloop, SLOT(quit()));
    eventloop.exec();
    for(int i=0;i<len;++i){
        for(int j=0;j<len;++j){
            QSize pic(50,50);
            this->sc->items[i][j]->setPixmap(QPixmap(":/new/prefix1/Block.png").scaled(pic));
        }
    }
    this->sc->cooldown = 0;
}

void MainWindow::up(){
    timer->stop();
}
