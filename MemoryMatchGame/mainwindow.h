#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <myScence.h>
#include <QTime>
#include <QLineEdit>
#include <QTimer>
//这是主窗口头文件
namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int judge();
    void showIt();
    Ui::MainWindow *ui;  //界面
    QTimer *timer = new QTimer();
//    QTime *time;
    int type;
private slots:
    //计时器和ProgressBar的更新信号
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void up();

public:
    myScence *sc; //视图场景
};

#endif // MAINWINDOW_H
