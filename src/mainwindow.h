#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QDir>
#include <QObject>
#include <QPoint>
#include<QProgressBar>
#include<QDialog>
#include<QLabel>
#include<QWidget>
#include<QMediaPlayer>
#include<QtMultimedia/QMediaPlayer>

namespace Ui {
class MainWindow;
class myPlane;
class GraphicsItem;
}

namespace Qt {
class QDialog;
}

struct tool
{
    int x;
    int y;
    int boom=0;
    bool out=0;
    tool *next;
};

struct Ams
{
    int x;
    int y;
    int boom=0;
    bool out=0;
    Ams *next;
};

class myPlane
{
private:
    int towards;
public:
    int x;
    int y;
    int health=30;
    int object1=0;
    int starttogo1=0;
    int model;
    int win=0;
    int Hz1=0;
    int Hz2=0;
    int Hz1ofAm=0;
    int Hz2ofAm=0;
    bool boom1=0;
    bool boom_ofAm=0;
    bool shoot1=false;
    Ams *Am;
    Ams *tail;
    Ams *last;
    int click_x;
    int click_y;
    myPlane();
    void setTowards(int);
    int getTowards();
    void movePlane(int);
    void fire1();
    void fire2();
    void fire3();
};

struct AmofEn
{
public:
    int atimer=0;
    int xofAm;
    int yofAm;
    int addx4=1;
    int addy4=8;
    int ve_ofAm;
    int apearTime=0;
    bool apear_ofAm=0;
    bool boomofAm=0;
    bool out=0;
    AmofEn *next;
};

struct enemyPlane
{
    int time;
    int x;
    int y;
    int health;
    int velocity;
    int object1=1;
    int boom=0;
    enemyPlane();
};

class enemyPlane1:public enemyPlane
{
public:
    bool apear=0;
    int apTi=0;
    int Hz1=0;
    int Hz2=0;
    int Hz1ofAm=0;
    int Hz2ofAm=0;
    AmofEn *tail;
    AmofEn *last;
    AmofEn *AmofEn1;
    enemyPlane1 *next;
    enemyPlane1();
//        void move1();
    ~enemyPlane1();
};

class enemyPlane2:public enemyPlane
{
public:
    bool apear=0;
    int apTi=0;
    int Hz1=0;
    int Hz2=0;
    int Hz1ofAm=0;
    int Hz2ofAm=0;
    AmofEn *tail;
    AmofEn *last;
    AmofEn *AmofEn1;
    enemyPlane2 *next;
    enemyPlane2();
//        void move1();
    ~enemyPlane2();
};

class enemyPlane3:public enemyPlane
{
public:
    bool apear=0;
    int apTi=0;
    int Hz1=0;
    int Hz2=0;
    int Hz1ofAm=0;
    int Hz2ofAm=0;
    AmofEn *tail;
    AmofEn *last;
    AmofEn *AmofEn1;
    enemyPlane3 *next;
    enemyPlane3();
//        void move1();
    ~enemyPlane3();
};

class enemyPlane4:public enemyPlane
{
public:
    bool apear=0;
    int apTi=0;
    int Hz1=0;
    int Hz2=0;
    int Hz1ofAm=0;
    int Hz2ofAm=0;
    bool towards=0;
    AmofEn *tail;
    AmofEn *last;
    AmofEn *AmofEn4;
    enemyPlane4();
//        void move1();
    ~enemyPlane4();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool alive=0;
    int closeTime=0;
    int windows=0;
    int background=1;
    int backmusic=1;
    myPlane one;
    tool *p;
    tool *tool1;
    tool *tailt;
    tool *lastt;
    tool *tool2;
    tool *tailt2;
    tool *lastt2;
    enemyPlane1 *enemy1;
    enemyPlane1 *tail1;
    enemyPlane1 *last1;
    enemyPlane2 *enemy2;
    enemyPlane2 *tail;
    enemyPlane2 *last;
    enemyPlane3 *enemy3;
    enemyPlane3 *tail3;
    enemyPlane3 *last3;
    enemyPlane4 enemy4;
    int enemPlane=0;
    int myPlane=0;
    int allTime1=0;
    int allTime2=0;
    QPixmap imageTool;
    QPixmap imageTool2;
    QPixmap image1;
    QPixmap image2;
    QPixmap image11;
    QPixmap image12;
    QPixmap image31;
    QPixmap image32;
    QPixmap image41;
    QPixmap image42;
    QPixmap boomImage1;
    QPixmap boomImage2;
    QMediaPlayer *player;
private:
    Ui::MainWindow *ui;
    QPixmap pix;
    QWidget *beginWidget=new QWidget(this,/*Qt::FramelessWindowHint,*/Qt::WindowStaysOnTopHint);
    QLabel *beginLabel=new QLabel(beginWidget,Qt::WindowStaysOnTopHint);
    QWidget *ruleWidget=new QWidget(this,/*Qt::FramelessWindowHint,*/Qt::WindowStaysOnTopHint);
    QLabel *ruleLabel=new QLabel(ruleWidget,Qt::WindowStaysOnTopHint);
    QWidget *setWidget=new QWidget(this,/*Qt::FramelessWindowHint,*/Qt::WindowStaysOnTopHint);
    QLabel *setLabel=new QLabel(setWidget,Qt::WindowStaysOnTopHint);
    QWidget *endWidget=new QWidget(this,/*Qt::FramelessWindowHint,*/Qt::WindowStaysOnTopHint);
    QLabel *endLabel=new QLabel(endWidget,Qt::WindowStaysOnTopHint);
    QWidget *scoresWidget=new QWidget(this,/*Qt::FramelessWindowHint,*/Qt::WindowStaysOnTopHint);
    QLabel *scoresLabel=new QLabel(scoresWidget,Qt::WindowStaysOnTopHint);
    QLabel *scoresThisLabel=new QLabel(scoresWidget,Qt::WindowStaysOnTopHint);
    QLabel *scoresHeightLabel=new QLabel(scoresWidget,Qt::WindowStaysOnTopHint);
    QWidget *chEnWidget=new QWidget(this,/*Qt::FramelessWindowHint,*/Qt::WindowStaysOnTopHint);
    QLabel *chEnLabel=new QLabel(chEnWidget,Qt::WindowStaysOnTopHint);
    QWidget *chMyWidget=new QWidget(this,/*Qt::FramelessWindowHint,*/Qt::WindowStaysOnTopHint);
    QLabel *chMyLabel=new QLabel(chMyWidget,Qt::WindowStaysOnTopHint);

    int id1, id2, id3,id4,id5,id6;
protected:
    void timerEvent(QTimerEvent *);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
public slots:

};

#endif //  b
