#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QPointF>
#include <QPixmap>
#include <QSize>
#include<math.h>

void MainWindow::paintEvent(QPaintEvent *)
{
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setRenderHint(QPainter::QPainter::SmoothPixmapTransform , true);
        update();
        if(alive==0&&one.health>0&&windows==0)
        {
            ui->progressBar->hide();
            ui->textBrowser->hide();
            ui->textBrowser_2->hide();
            this->beginLabel->setFixedSize(1920,1080);
            this->beginLabel->setAlignment(Qt::AlignCenter);

            QPixmap imageBegin;
            imageBegin.load(":/beginBackground.png");
            QPixmap scaledPixmap0 = imageBegin.scaled(1920,1080);
            this->beginLabel->setPixmap(scaledPixmap0);

            this->beginWidget->show();
            this->beginLabel->show();

        }

        if(alive==0&&one.health>0&&windows==-2)
        {
            ui->progressBar->hide();
            ui->textBrowser->hide();
            ui->textBrowser_2->hide();
            this->ruleLabel->setFixedSize(1920,1080);
            this->ruleLabel->setAlignment(Qt::AlignCenter);

            QPixmap imageBegin;
            imageBegin.load(":/ruleBackground.png");
            QPixmap scaledPixmap0 = imageBegin.scaled(1920,1080);
            this->ruleLabel->setPixmap(scaledPixmap0);

            this->ruleWidget->show();
            this->ruleLabel->show();

        }

        if(windows==1)
        {
            this->chEnWidget->setWindowState(Qt::WindowFullScreen);
            this->chEnWidget->setWindowFlag(Qt::WindowStaysOnTopHint);
            this->chEnWidget->setFixedSize(1920,1080);
            this->chEnLabel->setFixedSize(1920,1080);
            this->chEnLabel->setAlignment(Qt::AlignCenter);

            QPixmap imagechEn;
            imagechEn.load(":/chooseEn.png");
            QPixmap scaledPixmap = imagechEn.scaled(1920,1080);
            this->chEnLabel->setPixmap(scaledPixmap);

            this->chEnWidget->show();
            this->chEnLabel->show();
        }

        if(windows==2)
        {
            this->chMyWidget->setWindowState(Qt::WindowFullScreen);
            this->chMyWidget->setWindowFlag(Qt::WindowStaysOnTopHint);
            this->chMyWidget->setFixedSize(1920,1080);
            this->chMyLabel->setFixedSize(1920,1080);
            this->chMyLabel->setAlignment(Qt::AlignCenter);

            QPixmap imagechMy;
            imagechMy.load(":/chooseMy.png");
            QPixmap scaledPixmap = imagechMy.scaled(1920,1080);
            this->chMyLabel->setPixmap(scaledPixmap);

            this->chMyWidget->show();
            this->chMyLabel->show();
        }

        if(windows==100)
        {
            this->setWidget->setWindowState(Qt::WindowFullScreen);
            this->setWidget->setWindowFlag(Qt::WindowStaysOnTopHint);
            this->setWidget->setFixedSize(1920,1080);
            this->setLabel->setFixedSize(1920,1080);
            this->setLabel->setAlignment(Qt::AlignCenter);

            QPixmap imagechEn;
            imagechEn.load(":/setpageBackground.png");
            QPixmap scaledPixmap = imagechEn.scaled(1920,1080);
            this->setLabel->setPixmap(scaledPixmap);

            this->setWidget->show();
            this->setLabel->show();
        }
/////////////////////////////////////////////////////////////////////////////////////////////
        //11111111111111111111111111111111111111111111111111111111111111111111111111111111111
//*******************************************************************************************
        if(windows==3&&enemPlane==1)
        {
            QPixmap amImage1;
            if(myPlane==1)
            {
                amImage1.load(":/amofMy001.png");
            }
            else if (myPlane==2) {
                amImage1.load(":/amofMy002.png");
            }


            if(one.shoot1==1)
            {
                one.Am->out=1;
                one.Hz1ofAm=0;
                one.Hz1ofAm=0;
                one.Am->x=one.x+65;
                one.Am->y=one.y+25;
                one.Am->out=1;
                one.Am->boom=0;
                one.shoot1=0;
                one.Am=one.Am->next;
            }

            for (int i=0;i<=19;i++)
            {
                if(one.Am->out==0)
                {
                    one.Am->x=one.x+65;
                    one.Am->y=one.y+25;
                }
                one.Am=one.Am->next;
            }

            for (int i=0;i<=19;i++)
           {
               if(one.Am->out==1&&alive)
               {
                   if(myPlane==1)
                   {
                       painter.drawPixmap(one.Am->x,one.Am->y, 30 ,36 ,amImage1);
                   }
                   else if (myPlane==2) {
                       painter.drawPixmap(one.Am->x-65,one.Am->y, 160 ,40 ,amImage1);
                   }

                   one.Am->y-=2;
               }
               one.Am=one.Am->next;
               if(one.Am->y<-40)
               {
                   one.Am->out=0;
               }
           }


            if(alive==1&&one.health>0)
            {
                if(myPlane==1)
                {
                    pix.load(":/my001.png");
                }
                else if(myPlane==2)
                {
                    pix.load(":/my002.png");
                }
                painter.drawPixmap(one.x, one.y,160, 150, pix);
            }



            for (int i=0;i<=9;i++)
            {
                if(enemy1->apear==1)
                {
                    painter.drawPixmap(enemy1->x,enemy1->y, 125 ,190 ,image11);
                    if(alive==1)
                    enemy1->y+=3;
                }


                for (int ii=0;ii<=19;ii++)
                {
                    if(myPlane==1&&one.Am->out==1&&enemy1->apear==1&&one.Am->x+15>=enemy1->x&&one.Am->x+15<=enemy1->x+160&&one.Am->y>=enemy1->y&&one.Am->y<=enemy1->y+100)
                    {
                        enemy1->apear=0;
                        one.Am->out=0;
                        enemy1->boom=1;
                        one.win+=100;
                    }
                    else if (myPlane==2&&one.Am->out==1&&enemy1->apear==1&&one.Am->x+15>=enemy1->x-120&&one.Am->x+15<=enemy1->x+160&&one.Am->y>=enemy1->y&&one.Am->y<=enemy1->y+100) {

                        enemy1->apear=0;
                        one.Am->out=0;
                        enemy1->boom=1;
                        one.win+=50;
                    }
                    one.Am=one.Am->next;
                }
                enemy1=enemy1->next;
            }


            for (int i=0;i<=9;i++)
            {
                if(enemy1->apear==1&&one.x>=enemy1->x-150&&one.x<=enemy1->x+175&&one.y>=enemy1->y-150&&one.y<=enemy1->y+120)
                {
                    enemy1->apear=0;
                    enemy1->boom=1;
                    one.health=one.health-4;
                    if(one.health<0)
                        one.health=0;

                    if(one.health<=0)
                        alive=false;
                }
                enemy1=enemy1->next;
            }

            for (int i=0;i<=9;i++)
            {
                if(enemy1->boom==1&&enemy1->Hz1<25)
                {
                    painter.drawPixmap(enemy1->x,enemy1->y, 120 ,135 ,boomImage1);
                    enemy1->Hz1++;
                }

                if(enemy1->boom==1&&enemy1->Hz1>=25&&enemy1->Hz2<25)
                {
                    painter.drawPixmap(enemy1->x,enemy1->y, 205 ,200 ,boomImage2);
                    enemy1->Hz2++;
                }

                enemy1=enemy1->next;
            }

            if(alive==0&&one.health<=0)
            {
                windows=4;
                if(one.Hz1<25)
                {
                    painter.drawPixmap(one.x, one.y,120 ,135 ,boomImage1);
                    one.Hz1++;
                }

                if(one.Hz1>=25&&one.Hz2<25)
                {
                    painter.drawPixmap(one.x, one.y,205 ,200,boomImage2);
                    one.Hz2++;
                }

                this->endWidget->setWindowState(Qt::WindowFullScreen);
                this->endWidget->setWindowFlag(Qt::WindowStaysOnTopHint);
                this->endWidget->setFixedSize(1920,1080);
                this->endLabel->setFixedSize(1920,1080);
                this->endLabel->setAlignment(Qt::AlignCenter);

                QPixmap imageEnd;
                imageEnd.load(":/endBackground001.png");
                QPixmap scaledPixmap = imageEnd.scaled(1920,1080);
                this->endLabel->setPixmap(scaledPixmap);

                this->endWidget->show();
                this->endLabel->show();
            }
        }
//*******************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////
        //22222222222222222222222222222222222222222222222222222222222222222222222222222222222
        if(windows==3&&enemPlane==2)
        {
            QPixmap amImage1;
            if(myPlane==1)
            {
                amImage1.load(":/amofMy001.png");
            }
            else if (myPlane==2) {
                amImage1.load(":/amofMy002.png");
            }

            if(one.shoot1==1)
            {
                one.Am->out=1;
                one.Hz1ofAm=0;
                one.Hz1ofAm=0;
                one.Am->x=one.x+65;
                one.Am->y=one.y+25;
                one.Am->out=1;
                one.Am->boom=0;
                one.shoot1=0;
                one.Am=one.Am->next;
            }

            for (int i=0;i<=19;i++)
            {
                if(one.Am->out==0)
                {
                    one.Am->x=one.x+65;
                    one.Am->y=one.y+25;
                }
                one.Am=one.Am->next;
            }

            for (int i=0;i<=19;i++)
           {
               if(one.Am->out==1&&alive)
               {
                   if(myPlane==1)
                   {
                       painter.drawPixmap(one.Am->x,one.Am->y, 30 ,36 ,amImage1);
                   }
                   else if (myPlane==2) {
                       painter.drawPixmap(one.Am->x-65,one.Am->y, 160 ,40 ,amImage1);
                   }
                   one.Am->y-=2;
               }
               one.Am=one.Am->next;
               if(one.Am->y<-40)
               {
                   one.Am->out=0;
               }
           }


            if(alive==1&&one.health>0)
            {
                if(myPlane==1)
                {
                    pix.load(":/my001.png");
                }
                else if(myPlane==2)
                {
                    pix.load(":/my002.png");
                }
                painter.drawPixmap(one.x, one.y,160, 150, pix);
            }

            for (int i=0;i<=9;i++)
            {
                for (int i=0;i<=2;i++)
                {
                    if(enemy2->AmofEn1->apear_ofAm)
                    {
                        painter.drawPixmap(enemy2->AmofEn1->xofAm+82,enemy2->AmofEn1->yofAm,30,48,image2);
                        if(alive==1)
                        enemy2->AmofEn1->yofAm+=rand()%3+2;
                    }
                    if(enemy2->AmofEn1->yofAm>2000)
                    {
                        enemy2->AmofEn1->apear_ofAm=0;
                    }
                    enemy2->AmofEn1=enemy2->AmofEn1->next;
                }

                for (int i=0;i<=2;i++)
                {
                    if(enemy2->AmofEn1->apear_ofAm==1&&enemy2->AmofEn1->xofAm+82>=one.x&&enemy2->AmofEn1->xofAm+82<=one.x+160&&enemy2->AmofEn1->yofAm>=one.y+18&&enemy2->AmofEn1->yofAm<=one.y+150)
                    {
                        enemy2->AmofEn1->apear_ofAm=0;
                        enemy2->AmofEn1->boomofAm=1;
                        one.health-=1;
                        if(one.health<0)
                            one.health=0;

                        if(one.health<=0)
                            alive=false;
                    }
                    enemy2->AmofEn1=enemy2->AmofEn1->next;
                }
                enemy2=enemy2->next;
            }

            for (int i=0;i<=9;i++)
            {
                if(enemy2->apear==1)
                {
                    painter.drawPixmap(enemy2->x,enemy2->y, 185 ,120 ,image1);
                    if(alive==1)
                        enemy2->y+=1;
                }


                for (int ii=0;ii<=19;ii++)
                {
                    if(myPlane==1&&one.Am->out==1&&enemy2->apear==1&&one.Am->x+15>=enemy2->x&&one.Am->x+15<=enemy2->x+160&&one.Am->y>=enemy2->y&&one.Am->y<=enemy2->y+100)
                    {
                        enemy2->apear=0;
                        one.Am->out=0;
                        enemy2->boom=1;
                        one.win+=100;
                    }
                    else if (myPlane==2&&one.Am->out==1&&enemy2->apear==1&&one.Am->x+15>=enemy2->x-110&&one.Am->x+15<=enemy2->x+220&&one.Am->y>=enemy2->y&&one.Am->y<=enemy2->y+100) {

                        enemy2->apear=0;
                        one.Am->out=0;
                        enemy2->boom=1;
                        one.win+=50;
                    }
                    one.Am=one.Am->next;
                }
                enemy2=enemy2->next;
            }

            for (int i=0;i<=9;i++)
            {
                if(enemy2->apear==1&&one.x>=enemy2->x-150&&one.x<=enemy2->x+175&&one.y>=enemy2->y-130&&one.y<=enemy2->y+100)
                {
                    enemy2->apear=0;
                    enemy2->boom=1;
                    one.health=one.health-2;
                    if(one.health<0)
                        one.health=0;

                    if(one.health<=0)
                        alive=false;
                }
                enemy2=enemy2->next;
            }

            for (int i=0;i<=9;i++)
            {
                if(enemy2->boom==1&&enemy2->Hz1<25)
                {
                    painter.drawPixmap(enemy2->x,enemy2->y, 120 ,135 ,boomImage1);
                    enemy2->Hz1++;
                }

                if(enemy2->boom==1&&enemy2->Hz1>=25&&enemy2->Hz2<25)
                {
                    painter.drawPixmap(enemy2->x,enemy2->y, 205 ,200 ,boomImage2);
                    enemy2->Hz2++;
                }

                for (int i=0;i<=2;i++)
                {
                    if(enemy2->AmofEn1->boomofAm==1&&enemy2->Hz1ofAm<25)
                    {
                        painter.drawPixmap(enemy2->AmofEn1->xofAm+82,enemy2->AmofEn1->yofAm+20,60,60 ,boomImage1);
                        enemy2->Hz1ofAm++;
                    }
                    if(enemy2->AmofEn1->boomofAm==1&&enemy2->Hz1ofAm>=25&&enemy2->Hz2ofAm<25)
                    {
                        painter.drawPixmap(enemy2->AmofEn1->xofAm+82,enemy2->AmofEn1->yofAm+20,80 ,80,boomImage2);
                        enemy2->Hz2ofAm++;
                    }
                    enemy2->AmofEn1=enemy2->AmofEn1->next;
                }

                enemy2=enemy2->next;
            }

            if(alive==0&&one.health<=0)
            {
                windows=4;
                if(one.Hz1<25)
                {
                    painter.drawPixmap(one.x, one.y,120 ,135 ,boomImage1);
                    one.Hz1++;
                }

                if(one.Hz1>=25&&one.Hz2<25)
                {
                    painter.drawPixmap(one.x, one.y,205 ,200,boomImage2);
                    one.Hz2++;
                }

                this->endWidget->setWindowState(Qt::WindowFullScreen);
                this->endWidget->setWindowFlag(Qt::WindowStaysOnTopHint);
                this->endWidget->setFixedSize(1920,1080);
                this->endLabel->setFixedSize(1920,1080);
                this->endLabel->setAlignment(Qt::AlignCenter);

                QPixmap imageEnd;
                imageEnd.load(":/endBackground001.png");
                QPixmap scaledPixmap = imageEnd.scaled(1920,1080);
                this->endLabel->setPixmap(scaledPixmap);

                this->endWidget->show();
                this->endLabel->show();
            }
        }
/////////////////////////////////////////////////////////////////////////////////////////////////
        //333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
//***********************************************************************************************
        if(windows==3&&enemPlane==3)
        {
            QPixmap amImage1;
            if(myPlane==1)
            {
                amImage1.load(":/amofMy001.png");
            }
            else if (myPlane==2) {
                amImage1.load(":/amofMy002.png");
            }

            if(one.shoot1==1)
            {
                one.Am->out=1;
                one.Hz1ofAm=0;
                one.Hz1ofAm=0;
                one.Am->x=one.x+65;
                one.Am->y=one.y+25;
                one.Am->out=1;
                one.Am->boom=0;
                one.shoot1=0;
                one.Am=one.Am->next;
            }

            for (int i=0;i<=19;i++)
            {
                if(one.Am->out==0)
                {
                    one.Am->x=one.x+65;
                    one.Am->y=one.y+25;
                }
                one.Am=one.Am->next;
            }

            for (int i=0;i<=19;i++)
           {
               if(one.Am->out==1&&alive)
               {
                   if(myPlane==1)
                   {
                       painter.drawPixmap(one.Am->x,one.Am->y, 30 ,36 ,amImage1);
                   }
                   else if (myPlane==2) {
                       painter.drawPixmap(one.Am->x-65,one.Am->y, 160 ,40 ,amImage1);
                   }
                   one.Am->y-=2;
               }
               one.Am=one.Am->next;
               if(one.Am->y<-40)
               {
                   one.Am->out=0;
               }
           }


            if(alive==1&&one.health>0)
            {
                if(myPlane==1)
                {
                    pix.load(":/my001.png");
                }
                else if(myPlane==2)
                {
                    pix.load(":/my002.png");
                }
                painter.drawPixmap(one.x, one.y,160, 150, pix);
            }
//
            for (int i=0;i<=9;i++)
            {
                for (int i=0;i<=2;i++)
                {
                    if(enemy3->AmofEn1->apear_ofAm)
                    {
                        painter.drawPixmap(enemy3->AmofEn1->xofAm,enemy3->AmofEn1->yofAm,180,48,image32);
                        if(alive==1)
                        enemy3->AmofEn1->yofAm+=rand()%3+2;
                    }
                    if(enemy3->AmofEn1->yofAm>2000)
                    {
                        enemy3->AmofEn1->apear_ofAm=0;
                    }
                    enemy3->AmofEn1=enemy3->AmofEn1->next;
                }

                for (int i=0;i<=2;i++)
                {
                    if(enemy3->AmofEn1->apear_ofAm==1&&enemy3->AmofEn1->xofAm+135>=one.x&&enemy3->AmofEn1->xofAm<=one.x+135&&enemy3->AmofEn1->yofAm>=one.y-40&&enemy3->AmofEn1->yofAm<=one.y+150)
                    {
                        enemy3->AmofEn1->apear_ofAm=0;
                        enemy3->AmofEn1->boomofAm=1;
                        one.health-=2;
                        if(one.health<0)
                            one.health=0;

                        if(one.health<=0)
                            alive=false;
                    }
                    enemy3->AmofEn1=enemy3->AmofEn1->next;
                }
                enemy3=enemy3->next;
            }

            for (int i=0;i<=9;i++)
            {
                if(enemy3->apear==1)
                {
                    painter.drawPixmap(enemy3->x,enemy3->y, 185 ,120 ,image31);
                    if(alive==1)
                        enemy3->y+=1;
                }


                for (int ii=0;ii<=19;ii++)
                {
                    if(myPlane==1&&one.Am->out==1&&enemy3->apear==1&&one.Am->x+15>=enemy3->x&&one.Am->x+15<=enemy3->x+160&&one.Am->y>=enemy3->y&&one.Am->y<=enemy3->y+100)
                    {
                        enemy3->apear=0;
                        one.Am->out=0;
                        enemy3->boom=1;
                        one.win+=100;
                    }
                    else if (myPlane==2&&one.Am->out==1&&enemy3->apear==1&&one.Am->x+15>=enemy3->x-150&&one.Am->x+15<=enemy3->x+220&&one.Am->y>=enemy3->y&&one.Am->y<=enemy3->y+100)
                    {

                        enemy3->apear=0;
                        one.Am->out=0;
                        enemy3->boom=1;
                        one.win+=50;
                    }
                    one.Am=one.Am->next;
                }
                enemy3=enemy3->next;
            }



            for (int i=0;i<=9;i++)
            {
                if(enemy3->apear==1&&one.x>=enemy3->x-150&&one.x<=enemy3->x+175&&one.y>=enemy3->y-130&&one.y<=enemy3->y+100)
                {
                    enemy3->apear=0;
                    enemy3->boom=1;
                    one.health=one.health-2;
                    if(one.health<0)
                        one.health=0;

                    if(one.health<=0)
                        alive=false;
                }
                enemy3=enemy3->next;
            }

            for (int i=0;i<=9;i++)
            {
                if(enemy3->boom==1&&enemy3->Hz1<25)
                {
                    painter.drawPixmap(enemy3->x,enemy3->y, 120 ,135 ,boomImage1);
                    enemy3->Hz1++;
                }

                if(enemy3->boom==1&&enemy3->Hz1>=25&&enemy3->Hz2<25)
                {
                    painter.drawPixmap(enemy3->x,enemy3->y, 205 ,200 ,boomImage2);
                    enemy3->Hz2++;
                }

                for (int i=0;i<=2;i++)
                {
                    if(enemy3->AmofEn1->boomofAm==1&&enemy3->Hz1ofAm<25)
                    {
                        painter.drawPixmap(enemy3->AmofEn1->xofAm+82,enemy3->AmofEn1->yofAm+20,60,60 ,boomImage1);
                        enemy3->Hz1ofAm++;
                    }
                    if(enemy3->AmofEn1->boomofAm==1&&enemy3->Hz1ofAm>=25&&enemy3->Hz2ofAm<25)
                    {
                        painter.drawPixmap(enemy3->AmofEn1->xofAm+82,enemy3->AmofEn1->yofAm+20,80 ,80,boomImage2);
                        enemy3->Hz2ofAm++;
                    }
                    enemy3->AmofEn1=enemy3->AmofEn1->next;
                }

                enemy3=enemy3->next;
            }

            if(alive==0&&one.health<=0)
            {
                windows=4;
                if(one.Hz1<25)
                {
                    painter.drawPixmap(one.x, one.y,120 ,135 ,boomImage1);
                    one.Hz1++;
                }

                if(one.Hz1>=25&&one.Hz2<25)
                {
                    painter.drawPixmap(one.x, one.y,205 ,200,boomImage2);
                    one.Hz2++;
                }

                this->endWidget->setWindowState(Qt::WindowFullScreen);
                this->endWidget->setWindowFlag(Qt::WindowStaysOnTopHint);
                this->endWidget->setFixedSize(1920,1080);
                this->endLabel->setFixedSize(1920,1080);
                this->endLabel->setAlignment(Qt::AlignCenter);

                QPixmap imageEnd;
                imageEnd.load(":/endBackground001.png");
                QPixmap scaledPixmap = imageEnd.scaled(1920,1080);
                this->endLabel->setPixmap(scaledPixmap);

                this->endWidget->show();
                this->endLabel->show();
            }
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////
//***************************************************************************************************
        //4444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
        if(windows==3&&enemPlane==4)
        {
            enemy4.AmofEn4->atimer++;
            QPixmap amImage1;
            if(myPlane==1)
            {
                amImage1.load(":/amofMy001.png");
            }
            else if (myPlane==2) {
                amImage1.load(":/amofMy002.png");
            }

            if(one.shoot1==1)
            {
                one.Am->out=1;
                one.Hz1ofAm=0;
                one.Hz1ofAm=0;
                one.Am->x=one.x+65;
                one.Am->y=one.y+25;
                one.Am->out=1;
                one.Am->boom=0;
                one.shoot1=0;
                one.Am=one.Am->next;
            }

            for (int i=0;i<=19;i++)
            {
                if(one.Am->out==0)
                {
                    if(one.Am->boom==0)
                    {
                        one.Am->x=one.x+65;
                        one.Am->y=one.y+25;
                    }
                }
                one.Am=one.Am->next;
            }

            for (int i=0;i<=19;i++)
           {
               if(one.Am->out==1&&alive)
               {
                   if(myPlane==1)
                   {
                       painter.drawPixmap(one.Am->x,one.Am->y, 30 ,36 ,amImage1);
                   }
                   else if (myPlane==2) {
                       painter.drawPixmap(one.Am->x-65,one.Am->y, 160 ,40 ,amImage1);
                   }
                   one.Am->y-=2;
               }
               one.Am=one.Am->next;
               if(one.Am->y<-40)
               {
                   one.Am->out=0;
               }
           }


            if(alive==1&&one.health>0)
            {
                if(myPlane==1)
                {
                    pix.load(":/my001.png");
                }
                else if(myPlane==2)
                {
                    pix.load(":/my002.png");
                }
                painter.drawPixmap(one.x, one.y,160, 150, pix);
            }


            for (int i=0;i<=4;i++) {
                if(enemy4.AmofEn4->apear_ofAm)
                {
                    if(alive==1)
                    {
                        enemy4.AmofEn4->yofAm+=rand()%3+2;
                        if(enemy4.AmofEn4->xofAm-one.x>300&&(enemy4.AmofEn4->yofAm-one.y)>300)
                        enemy4.AmofEn4->xofAm+=3*(enemy4.AmofEn4->xofAm-one.x)/sqrt((enemy4.AmofEn4->xofAm-one.x)*(enemy4.AmofEn4->xofAm-one.x)+(enemy4.AmofEn4->yofAm-one.y)*(enemy4.AmofEn4->yofAm-one.y));
                        painter.drawPixmap(enemy4.AmofEn4->xofAm+17, enemy4.AmofEn4->yofAm+75,35,157,image42/*scaledPixmap.transformed(mat)*/);
                    }
                }
                if(enemy4.AmofEn4->yofAm>2000)
                {
                    enemy4.AmofEn4->apear_ofAm=0;
                }
                enemy4.AmofEn4=enemy4.AmofEn4->next;
            }

            for (int i=0;i<=4;i++) {
                if(enemy4.apear==1&&enemy4.AmofEn4->apear_ofAm==1&&enemy4.AmofEn4->xofAm>=one.x&&enemy4.AmofEn4->xofAm<=one.x+160&&enemy4.AmofEn4->yofAm+150>=one.y+18&&enemy4.AmofEn4->yofAm+150<=one.y+150)
                {
                    enemy4.AmofEn4->apear_ofAm=0;
                    enemy4.AmofEn4->boomofAm=1;
                    one.health-=4;
                    if(one.health<0)
                        one.health=0;

                    if(one.health<=0)
                        alive=false;
                }
                enemy4.AmofEn4=enemy4.AmofEn4->next;
            }

            if(enemy4.apear==1&&enemy4.health>0)
            {
                painter.drawPixmap(enemy4.x,enemy4.y, 560,280 ,image41);
                if(alive==1&&enemy4.apear==1)
                {
                    if(enemy4.towards==0)
                    {
                        enemy4.x-=1;
                        if(enemy4.x<250)
                        {
                            enemy4.towards=1;
                        }
                    }
                    else if (enemy4.towards==1) {
                        enemy4.x+=1;
                        if(enemy4.x>1200)
                        {
                            enemy4.towards=0;
                        }
                    }
                }
            }

            for (int ii=0;ii<=19;ii++)
            {
                if(enemy4.apear==1&&one.Am->out==1&&one.Am->x>=enemy4.x&&one.Am->x<=enemy4.x+560&&one.Am->y>=enemy4.y&&one.Am->y<=enemy4.y+280)
                {
                    one.Am->boom=1;
                    one.Am->out=0;
                    one.win+=100;
                    enemy4.health--;
                    if(enemy4.health<=0)
                    {
                        enemy4.apear=0;
                        enemy4.boom=1;
                    }
                }
                one.Am=one.Am->next;
            }

            if(enemy4.apear==1&&one.x>enemy4.x-145&&one.x<enemy4.x+540&&one.y>0&&one.y<260)
            {
                enemy4.boom=1;
                enemy4.apear=0;
                one.health-=18;
                if(one.health<=0)
                    one.health=0;
            }

            if(enemy4.boom==1)
            {
                if(enemy4.boom==1&&enemy4.Hz1<25)
                {
                    painter.drawPixmap(enemy4.x,enemy4.y-40,350,350 ,boomImage1);
                    enemy4.Hz1++;
                }
                else if(enemy4.boom==1&&enemy4.Hz1>=25&&enemy4.Hz2<25)
                {
                    painter.drawPixmap(enemy4.x,enemy4.y-40,400 ,400,boomImage2);
                    enemy4.Hz2++;
                }
            }



            for (int i=0;i<=9;i++)
            {
                for (int i=0;i<=2;i++)
                {
                    if(enemy2->AmofEn1->apear_ofAm)
                    {
                        painter.drawPixmap(enemy2->AmofEn1->xofAm+82,enemy2->AmofEn1->yofAm,30,48,image2);
                        if(alive==1)
                        enemy2->AmofEn1->yofAm+=rand()%3+2;
                    }
                    if(enemy2->AmofEn1->yofAm>2000)
                    {
                        enemy2->AmofEn1->apear_ofAm=0;
                    }
                    enemy2->AmofEn1=enemy2->AmofEn1->next;
                }

                for (int i=0;i<=2;i++)
                {
                    if(enemy2->AmofEn1->apear_ofAm==1&&enemy2->AmofEn1->xofAm+82>=one.x&&enemy2->AmofEn1->xofAm+82<=one.x+160&&enemy2->AmofEn1->yofAm>=one.y+18&&enemy2->AmofEn1->yofAm<=one.y+150)
                    {
                        enemy2->AmofEn1->apear_ofAm=0;
                        enemy2->AmofEn1->boomofAm=1;
                        one.health-=1;
                        if(one.health<0)
                            one.health=0;

                        if(one.health<=0)
                            alive=false;
                    }
                    enemy2->AmofEn1=enemy2->AmofEn1->next;
                }
                enemy2=enemy2->next;
            }

            for (int i=0;i<=9;i++)
            {
                if(enemy2->apear==1)
                {
                    painter.drawPixmap(enemy2->x,enemy2->y, 185 ,120 ,image1);
                    if(alive==1)
                        enemy2->y+=1;
                }


                for (int ii=0;ii<=19;ii++)
                {
                    if(myPlane==1&&one.Am->out==1&&enemy2->apear==1&&one.Am->x+15>=enemy2->x&&one.Am->x+15<=enemy2->x+160&&one.Am->y>=enemy2->y&&one.Am->y<=enemy2->y+100)
                    {
                        enemy2->apear=0;
                        one.Am->out=0;
                        enemy2->boom=1;
                        one.win+=100;
                    }
                    else if (myPlane==2&&one.Am->out==1&&enemy2->apear==1&&one.Am->x+15>=enemy2->x-110&&one.Am->x+15<=enemy2->x+220&&one.Am->y>=enemy2->y&&one.Am->y<=enemy2->y+100) {

                        enemy2->apear=0;
                        one.Am->out=0;
                        enemy2->boom=1;
                        one.win+=50;
                    }
                    one.Am=one.Am->next;
                }
                enemy2=enemy2->next;
            }

            for (int i=0;i<=9;i++)
            {
                if(enemy2->apear==1&&one.x>=enemy2->x-150&&one.x<=enemy2->x+175&&one.y>=enemy2->y-130&&one.y<=enemy2->y+100)
                {
                    enemy2->apear=0;
                    enemy2->boom=1;
                    one.health=one.health-2;
                    if(one.health<0)
                        one.health=0;

                    if(one.health<=0)
                        alive=false;
                }
                enemy2=enemy2->next;
            }

            for (int i=0;i<=9;i++)
            {
                if(enemy2->boom==1&&enemy2->Hz1<25)
                {
                    painter.drawPixmap(enemy2->x,enemy2->y, 120 ,135 ,boomImage1);
                    enemy2->Hz1++;
                }

                if(enemy2->boom==1&&enemy2->Hz1>=25&&enemy2->Hz2<25)
                {
                    painter.drawPixmap(enemy2->x,enemy2->y, 205 ,200 ,boomImage2);
                    enemy2->Hz2++;
                }

                for (int i=0;i<=2;i++)
                {
                    if(enemy2->AmofEn1->boomofAm==1&&enemy2->Hz1ofAm<25)
                    {
                        painter.drawPixmap(enemy2->AmofEn1->xofAm+82,enemy2->AmofEn1->yofAm+20,60,60 ,boomImage1);
                        enemy2->Hz1ofAm++;
                    }
                    if(enemy2->AmofEn1->boomofAm==1&&enemy2->Hz1ofAm>=25&&enemy2->Hz2ofAm<25)
                    {
                        painter.drawPixmap(enemy2->AmofEn1->xofAm+82,enemy2->AmofEn1->yofAm+20,80 ,80,boomImage2);
                        enemy2->Hz2ofAm++;
                    }
                    enemy2->AmofEn1=enemy2->AmofEn1->next;
                }

                enemy2=enemy2->next;
            }


            for (int ii=0;ii<=19;ii++)
            {
                if(enemy4.apear==1)
                {
                    if(one.Am->boom==1&&one.Hz1ofAm<25)
                    {
                        painter.drawPixmap(one.Am->x,one.Am->y-40,80,80 ,boomImage1);
                        one.Hz1ofAm++;
                    }
                    else if(one.Am->boom==1&&one.Hz1ofAm>=25&&one.Hz2ofAm<25)
                    {
                        painter.drawPixmap(one.Am->x,one.Am->y-40,100 ,100,boomImage2);
                        one.Hz2ofAm++;
                    }
                    else if(one.Am->boom==1&&one.Hz2ofAm>=25)
                    {
                        one.Am->y=one.y+25;
                        one.Am->boom=0;
                    }
                }
                one.Am=one.Am->next;
            }

            if(alive==0&&one.health<=0)
            {
                windows=4;
                if(one.Hz1<25)
                {
                    painter.drawPixmap(one.x, one.y,120 ,135 ,boomImage1);
                    one.Hz1++;
                }

                if(one.Hz1>=25&&one.Hz2<25)
                {
                    painter.drawPixmap(one.x, one.y,205 ,200,boomImage2);
                    one.Hz2++;
                }

                this->endWidget->setWindowState(Qt::WindowFullScreen);
                this->endWidget->setWindowFlag(Qt::WindowStaysOnTopHint);
                this->endWidget->setFixedSize(1920,1080);
                this->endLabel->setFixedSize(1920,1080);
                this->endLabel->setAlignment(Qt::AlignCenter);

                QPixmap imageEnd;
                imageEnd.load(":/endBackground001.png");
                QPixmap scaledPixmap = imageEnd.scaled(1920,1080);
                this->endLabel->setPixmap(scaledPixmap);

                this->endWidget->show();
                this->endLabel->show();
            }
        }

//***************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////********///////////////////////////////////////////////////
//////////////////////////////////////////********///////////////////////////////////////////////////
//////////////////////////////////////////********///////////////////////////////////////////////////
/////////////////////////////////////******************//////////////////////////////////////////////
/////////////////////////////////////******************//////////////////////////////////////////////
/////////////////////////////////////******************//////////////////////////////////////////////
//////////////////////////////////////////********///////////////////////////////////////////////////
//////////////////////////////////////////********///////////////////////////////////////////////////
//////////////////////////////////////////********///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

        for (int i=0;i<=1;i++) {
            if(tool1->out==1)
            {
                tool1->y+=1+rand()%2;
                painter.drawPixmap(tool1->x,tool1->y,125,140 ,imageTool);
                if(tool1->y>2000)
                {
                    tool1->out=0;
                    tool1->y=-200;
                }
                if(tool1->out==1&&one.x>tool1->x-160&&one.x<tool1->x+125&&one.y>tool1->y-140&&one.y<tool1->y+140)
                {
                    tool1->out=0;
                    tool1->y=-200;
                    one.health++;
                }
            }
            tool1=tool1->next;
        }


        for (int i=0;i<=1;i++) {
            if(tool2->out==1)
            {
                tool2->y+=1+rand()%2;
                painter.drawPixmap(tool2->x,tool2->y,100,100 ,imageTool2);
                if(tool2->y>2000)
                {
                    tool2->out=0;
                    tool2->y=-200;
                }
                if(tool2->out==1&&one.x>tool2->x-160&&one.x<tool2->x+100&&one.y>tool2->y-140&&one.y<tool2->y+100)
                {
                    tool2->out=0;
                    tool2->y=-200;
                    one.win=one.win+300;
                }
            }
            tool2=tool2->next;
        }
//***************************************************************************************************
        if(windows==5)
        {
            this->scoresWidget->setWindowState(Qt::WindowFullScreen);
            this->scoresWidget->setWindowFlag(Qt::WindowStaysOnTopHint);
            this->scoresWidget->setFixedSize(1920,1080);
            this->scoresLabel->setFixedSize(1920,1080);
            this->scoresLabel->setAlignment(Qt::AlignCenter);

            QPixmap imageScores;
            imageScores.load(":/scoresBackground.png");
            QPixmap scaledPixmap = imageScores.scaled(1920,1080);
            this->scoresLabel->setPixmap(scaledPixmap);

            this->scoresWidget->show();
            this->scoresLabel->show();
            this->scoresThisLabel->show();
            this->scoresHeightLabel->show();

            QFile  myfile("test.txt");
            myfile.open(QIODevice::ReadOnly | QIODevice::Text);
            QByteArray t = myfile.readAll();
            myfile.close();
            bool ok;
            int theHeight;
            int lastHeight=t.toInt(&ok,10);
            if(lastHeight>=one.win)
            {
                theHeight=lastHeight;
            }
            else {
                theHeight=one.win;
            }

            QString thisWin = QString::number(one.win, 10);
            QString thisHei = QString::number(theHeight, 10);
            this->scoresThisLabel->setStyleSheet("font: 43pt 'STCaiyun';background-color: rgba(255, 255, 255, 0);color:#5AB8FF");
            this->scoresHeightLabel->setStyleSheet("font: 43pt 'STCaiyun';background-color: rgba(255, 255, 255, 0);color:#FF8C43");
            this->scoresThisLabel->setText(thisWin);
            this->scoresHeightLabel->setText(thisHei);

            myfile.open(QIODevice::WriteOnly | QFile::Truncate);
            QTextStream out(&myfile);
            out<<thisHei<<endl;
            myfile.close();
        }
}

//            if (myfile.open(QFile::ReadOnly))
//            {
//                temp=myfile.readAll();
//                myfile.close();
//            }
//            if (myfile.open(QFile::WriteOnly|QFile::Truncate))
//            {
//                QTextStream out(&myfile);
//                out<<one.win<<endl;
//                myfile.close();
//            }
//            qDebug()<<temp;
