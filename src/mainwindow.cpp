#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QPointF>
#include <QGraphicsItem>
#include <QRectF>
#include<QProgressBar>
#include <QCloseEvent>
#include<QMessageBox>
#include<QMediaPlayer>
#include<QtMultimedia/QMediaPlayer>

myPlane::myPlane()
{
    x=900;
    y=850;
    Am=new Ams();
    Am->out=0;
    Am->next=tail;
    tail=Am;
    last=Am;
    for (int i=0;i<=18;i++)
    {
        Am=new Ams();
        Am->out=0;
        Am->next=tail;
        tail=Am;
    }
    last->next=Am;
}

enemyPlane::enemyPlane()
{

}

enemyPlane1::enemyPlane1()
{
    int t=6;
    x=rand()%1400+200;
    y=-120;
    time=0;
    health=1;
    velocity=rand()%t;
    object1=1;
}

enemyPlane1::~enemyPlane1()
{

}

enemyPlane2::enemyPlane2()
{
    AmofEn1=new AmofEn();
    AmofEn1->next=tail;
    tail=AmofEn1;
    last=AmofEn1;
    for (int i=0;i<=1;i++)
    {
        AmofEn1=new AmofEn();
        AmofEn1->next=tail;
        AmofEn1->xofAm=x;
        AmofEn1->yofAm=y+100;
        tail=AmofEn1;
    }
    last->next=AmofEn1;

    int t=6;
    x=rand()%1400+200;
    y=-120;
    time=0;
    health=1;
    velocity=rand()%t;
    object1=1;
}

enemyPlane2::~enemyPlane2()
{

}

enemyPlane3::enemyPlane3()
{
    AmofEn1=new AmofEn();
    AmofEn1->next=tail;
    tail=AmofEn1;
    last=AmofEn1;
    for (int i=0;i<=1;i++)
    {
        AmofEn1=new AmofEn();
        AmofEn1->next=tail;
        AmofEn1->xofAm=x;
        AmofEn1->yofAm=y+100;
        tail=AmofEn1;
    }
    last->next=AmofEn1;

    int t=6;
    x=rand()%1400+200;
    y=-120;
    time=0;
    health=1;
    velocity=rand()%t;
    object1=1;
}

enemyPlane3::~enemyPlane3()
{

}


enemyPlane4::enemyPlane4()
{

    AmofEn4=new AmofEn();
    AmofEn4->next=tail;
    tail=AmofEn4;
    last=AmofEn4;
    for (int i=0;i<=3;i++)
    {
        AmofEn4=new AmofEn();
        AmofEn4->next=tail;
        AmofEn4->xofAm=x;
        AmofEn4->yofAm=y+100;
        tail=AmofEn4;
    }
    last->next=AmofEn4;

    x=rand()%1400+200;
    y=-10;
    time=0;
    health=40;
    object1=1;
}

enemyPlane4::~enemyPlane4()
{

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->alive=0;
    this->setWindowState(Qt::WindowFullScreen);
    ui->centralWidget->setMouseTracking(true);
//    ui->centralWidget->setAutoFillBackground(true);
    ui->progressBar->setRange(0,one.health);
    ui->progressBar->setValue(one.health);
    this->setMouseTracking(true);
    this->endWidget->hide();
    id1 = startTimer(800);
    id2 = startTimer(500);
    id3 = startTimer(1000);
    id4 = startTimer(37000);
    id5 = startTimer(29000);
    id6 = startTimer(23000);
    this->beginWidget->setWindowState(Qt::WindowFullScreen);
    this->beginWidget->setWindowFlag(Qt::WindowStaysOnTopHint);
    this->beginWidget->setFixedSize(1920,1080);
    this->beginWidget->show();
    this->setWidget->setWindowState(Qt::WindowFullScreen);
    this->setWidget->setWindowFlag(Qt::WindowStaysOnTopHint);
    this->setWidget->setFixedSize(1920,1080);
    this->setWidget->hide();
    this->ruleWidget->setWindowState(Qt::WindowFullScreen);
    this->ruleWidget->setWindowFlag(Qt::WindowStaysOnTopHint);
    this->ruleWidget->setFixedSize(1920,1080);
    this->ruleWidget->hide();
    this->scoresWidget->setWindowState(Qt::WindowFullScreen);
    this->scoresWidget->setWindowFlag(Qt::WindowStaysOnTopHint);
    this->scoresWidget->setFixedSize(1920,1080);
    this->scoresWidget->hide();
    this->scoresThisLabel->setGeometry(rect().x()+1145,rect().y()+335,375,180);
    this->scoresHeightLabel->setGeometry(rect().x()+1145,rect().y()+660,375,180);
    this->chEnWidget->setWindowState(Qt::WindowFullScreen);
    this->chEnWidget->setWindowFlag(Qt::WindowStaysOnTopHint);
    this->chEnWidget->setFixedSize(1920,1080);
    this->chMyWidget->hide();
    this->chMyWidget->setWindowState(Qt::WindowFullScreen);
    this->chMyWidget->setWindowFlag(Qt::WindowStaysOnTopHint);
    this->chMyWidget->setFixedSize(1920,1080);
    this->chMyWidget->hide();

    player=new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile("G:/QtProjects/thePlaneFighting/backgroundMusic002.mp3"));
    player->setVolume(80);
    player->play();

    imageTool.load(":/tool001.png");
    imageTool2.load(":/tool002.png");
    image11.load(":/enemy001.png");
    image1.load( ":/enemy002.png" );
    image2.load(":/amofEn002.png");
    image31.load(":/enemy003.png" );
    image32.load(":/amofEn003.png");
    image41.load(":/enemy004 .png" );
    image42.load(":/amofEn004.png");
    boomImage1.load(":/boom002.png");
    boomImage2.load(":/boom001.png");


    QPixmap pixmap = QPixmap(":/background001.png").scaled(this->size());

    QPalette  palette (this->palette());
    palette .setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );
    pix = QPixmap(960, 1080);

    tool1=new tool();
    tool1->next=tailt;
    tailt=tool1;
    lastt=tool1;
    tool1=new tool();
    tool1->next=tailt;
    tailt=tool1;
    lastt->next=tool1;

    tool2=new tool();
    tool2->next=tailt2;
    tailt2=tool2;
    lastt2=tool2;
    tool2=new tool();
    tool2->next=tailt2;
    tailt2=tool2;
    lastt2->next=tool2;

    enemy1=new enemyPlane1();
    enemy1->next=tail1;
    tail1=enemy1;
    last1=enemy1;
    for (int i=0;i<=8;i++)
    {
        enemy1=new enemyPlane1();
        enemy1->next=tail1;
        tail1=enemy1;
    }
    last1->next=enemy1;

    enemy3=new enemyPlane3();
    enemy3->next=tail3;
    tail3=enemy3;
    last3=enemy3;
    for (int i=0;i<=8;i++)
    {
        enemy3=new enemyPlane3();
        enemy3->next=tail3;
        tail3=enemy3;
    }
    last3->next=enemy3;

    enemy2=new enemyPlane2();
    enemy2->next=tail;
    tail=enemy2;
    last=enemy2;
    for (int i=0;i<=8;i++)
    {
        enemy2=new enemyPlane2();
        enemy2->next=tail;
        tail=enemy2;
    }
    last->next=enemy2;
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::timerEvent(QTimerEvent *event)
{
    if(windows==3)
    {
        if(event->timerId() == id1)
        {
            if((alive==1&&enemPlane==2)||(alive==1&&enemPlane==4))
            {
                enemy2->apear=1;
                enemy2->apTi++;
                enemy2->Hz1=0;
                enemy2->Hz2=0;
                enemy2->boom=0;
                enemy2->y=-240;
                enemy2->x=rand()%1400+200;
                for (int i=0;i<=2;i++) {
                    enemy2->AmofEn1->boomofAm=0;
                    enemy2->AmofEn1=enemy2->AmofEn1->next;
                }
                if(enemy2->apear==1)
                {
                    enemy2->apTi++;
                }
                enemy2=enemy2->next;
            }

            if(alive==1&&enemPlane==3)
            {
                enemy3->apear=1;
                enemy3->apTi++;
                enemy3->Hz1=0;
                enemy3->Hz2=0;
                enemy3->boom=0;
                enemy3->y=-240;
                enemy3->x=rand()%1400+200;
                for (int i=0;i<=2;i++) {
                    enemy3->AmofEn1->boomofAm=0;
                    enemy3->AmofEn1=enemy3->AmofEn1->next;
                }
                if(enemy3->apear==1)
                {
                    enemy3->apTi++;
                }
                enemy3=enemy3->next;
            }


            if(alive==1&&enemPlane==4&&enemy4.boom==0)
            {
                enemy4.apear=1;
                enemy4.apTi++;
            }
        }

        if(event->timerId() == id2)
        {
            if(alive==1)
            {
                allTime2+=1;
            }

            if((alive==1&&enemPlane==1))
            {
                enemy1->apear=1;
                enemy1->apTi++;
                enemy1->Hz1=0;
                enemy1->Hz2=0;
                enemy1->boom=0;
                enemy1->y=-240;
                enemy1->x=rand()%1400+200;

                if(enemy1->apear==1)
                {
                    enemy1->apTi++;
                }
                enemy1=enemy1->next;
            }

            ui->progressBar->setValue(one.health);
            QString theWin = QString::number(one.win, 10);
            ui->textBrowser_2->setText(theWin);
        }

        if(event->timerId() == id3)
        {
            for (int i=0;i<=9;i++)
            {
                if(enemy2->apear==1)
                {
                    enemy2->AmofEn1->apear_ofAm=1;
                    enemy2->AmofEn1->xofAm=enemy2->x;
                    enemy2->AmofEn1->yofAm=enemy2->y+20;
                    enemy2->Hz1ofAm=0;
                    enemy2->Hz2ofAm=0;
                    enemy2->AmofEn1->boomofAm=0;
                    enemy2->AmofEn1=enemy2->AmofEn1->next;
                }
                enemy2=enemy2->next;
            }

            for (int i=0;i<=9;i++)
            {
                if(enemy3->apear==1)
                {
                    enemy3->AmofEn1->apear_ofAm=1;
                    enemy3->AmofEn1->xofAm=enemy3->x;
                    enemy3->AmofEn1->yofAm=enemy3->y+20;
                    enemy3->Hz1ofAm=0;
                    enemy3->Hz2ofAm=0;
                    enemy3->AmofEn1->boomofAm=0;
                    enemy3->AmofEn1=enemy3->AmofEn1->next;
                }
                enemy3=enemy3->next;
            }
            if(enemy4.apear==1)
            {
                enemy4.AmofEn4->xofAm=enemy4.x+270;
                enemy4.AmofEn4->yofAm=enemy4.y+230;
                enemy4.Hz1ofAm=0;
                enemy4.Hz2ofAm=0;
                enemy4.AmofEn4->boomofAm=0;
                enemy4.AmofEn4->apear_ofAm=1;
                enemy4.AmofEn4=enemy4.AmofEn4->next;
            }


            for (int i=0;i<=4;i++)
            {
                if(enemy4.AmofEn4->apear_ofAm==1)
                {
                    enemy4.AmofEn4->apearTime++;
                }
                else {
                    enemy4.AmofEn4->apearTime=0;
                }
            }
        }
    }

    if(event->timerId() == id2)
    {
        ui->progressBar->setValue(one.health);
        QString theWin = QString::number(one.win, 10);
        ui->textBrowser_2->setText(theWin);
    }

    if(event->timerId() == id4||event->timerId() == id5)
    {
        if(alive==1&&one.health>0&&windows==3)
        {
                tool1->out=1;
                tool1->y=-200;
                tool1->x=rand()%1400+200;
                tool1=tool1->next;
        }
    }

    if(event->timerId() == id6)
    {
        if(alive==1&&one.health>0&&windows==3)
        {
                tool2->out=1;
                tool2->y=-200;
                tool2->x=rand()%1400+200;
                tool2=tool2->next;
        }
    }

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(alive==1)
    {
        one.x=event->x()-80;
        one.y=event->y()-75;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->x()>=1537&&event->x()<=1613&&event->y()>=859&&event->y()<=931&&windows==-2)
    {
        windows=100;
        this->ruleWidget->hide();
        this->ruleLabel->hide();
    }

    if(windows==3&&event->button()== Qt::LeftButton)
    {
        if(alive==1)
        {
            one.shoot1=true;
        }
    }

    if(windows==100&&event->button()== Qt::LeftButton)
    {
        if(event->x()>=1415&&event->x()<=1549&&event->y()>=797&&event->y()<=899)
        {
            windows=0;
            this->setWidget->hide();
            this->setLabel->hide();
        }

        if(event->x()>=1425&&event->x()<=1487&&event->y()>=185&&event->y()<=237)
        {
            //********/////
            windows=-2;
            this->setWidget->hide();
            this->setLabel->hide();
        }

        if(event->x()>=595&&event->x()<=885&&event->y()>=299&&event->y()<=641)
        {
            backmusic=1;
            player->setMedia(QUrl::fromLocalFile("G:/QtProjects/thePlaneFighting/backgroundMusic002.mp3"));
            player->setVolume(80);
            player->play();
        }

        if(event->x()>=1055&&event->x()<=1353&&event->y()>=299&&event->y()<=641)
        {
            backmusic=2 ;
            player->setMedia(QUrl::fromLocalFile("G:/QtProjects/thePlaneFighting/backgroundMusic001.mp3"));
            player->setVolume(80);
            player->play();
        }

        if(event->x()>=593&&event->x()<=855&&event->y()>=737&&event->y()<=799)
        {
            background=1;
            QPixmap pixmap = QPixmap(":/background001.png").scaled(this->size());
            QPalette  palette (this->palette());
            palette .setBrush(QPalette::Background, QBrush(pixmap));
            this-> setPalette( palette );
        }

        if(event->x()>=1081&&event->x()<=1337&&event->y()>=737&&event->y()<=799)
        {
            background=2;
            QPixmap pixmap = QPixmap(":/background002 .png").scaled(this->size());
            QPalette  palette (this->palette());
            palette .setBrush(QPalette::Background, QBrush(pixmap));
            this-> setPalette( palette );
        }
    }

    if(windows==2)
    {
        alive=1;
        ui->progressBar->show();
        ui->textBrowser->show();
        ui->textBrowser_2->show();
        this->chMyWidget->hide();
        this->chMyLabel->hide();
        if(event->x()>=131&&event->x()<=781&&event->y()>=291&&event->y()<=781)
        {
            windows=3;
            myPlane=1;
        }
        else if (event->x()>=1115&&event->x()<=1725&&event->y()>=483&&event->y()<=963) {
            windows=3;
            myPlane=2;
        }
    }
    else if (windows==1)
    {
        this->chEnWidget->hide();
        this->chEnLabel->hide();
        if(event->x()>=345&&event->x()<=787&&event->y()>=313&&event->y()<=575)
        {
            windows=2;
            enemPlane=1;
        }
        else if (event->x()>=1135&&event->x()<=1555&&event->y()>=315&&event->y()<=577) {
            windows=2;
            enemPlane=2;
        }
        else if (event->x()>=355&&event->x()<=787&&event->y()>=717&&event->y()<=979) {
            windows=2;
            enemPlane=3;
        }
        else if (event->x()>=1141&&event->x()<=1567&&event->y()>=713&&event->y()<=979) {
            windows=2;
            enemPlane=4;
        }
    }

    if(event->x()>=768&&event->x()<=1138&&event->y()<=498&&event->y()>=378&&windows==0)
    {
        windows=1;
        this->beginWidget->hide();
        this->beginLabel->hide();
    }

    if(event->x()>=768&&event->x()<=1138&&event->y()<=685&&event->y()>=581&&windows==0)
    {
        windows=100;
        this->beginWidget->hide();
        this->beginLabel->hide();
    }

    if(event->x()>=768&&event->x()<=1138&&event->y()<=904&&event->y()>=776&&windows==0)
    {
        windows=-1;
        this->close();
    }

    if(event->x()>=1700&&event->y()>=1000&&windows==5)
    {
//        this->close();
        windows=0;
        this->scoresWidget->hide();
        this->scoresLabel->hide();
        this->endWidget->hide();
        this->endLabel->hide();
        this->beginWidget->show();
        this->beginLabel->show();
        enemy4.health=30;
        enemy4.apear=1;
        enemy4.boom=0;
        one.health=30;
        one.win=0;
    }
    else if(event->x()>=1700&&event->y()>=1000&&windows==4)
    {
        windows=5;
        ui->progressBar->hide();
        ui->textBrowser->hide();
        ui->textBrowser_2->hide();
    }

}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
   if (e->key()==Qt::Key_Escape)
   {
       alive=0;
   }
   if(e->key()==Qt::Key_Return)
   {
       alive=1;
   }
}

