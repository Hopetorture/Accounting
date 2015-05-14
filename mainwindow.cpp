#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QStack>
#include "numbers_to_words.h"
#include <iostream>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::on_pushButton_clicked()
{


    words text;

    bool ok=false;
    double for_nds;

    int rub=0;
    int cop=0;    
    double percent=18;

    QString result;
    QString temp=ui->lineEdit->displayText();
    percent=ui->Nalog->displayText().toInt();

    temp.replace(",",".");

    if(!temp.contains("."))
    {

        double rr=temp.toDouble();
        double nal=rr*(percent/100);

        rr=rr+(rr*(percent/100));
        QString kmp1=QString::number(rr,'f');
        QString kmp2=QString::number(nal,'f');
        int intkmp=kmp1.lastIndexOf(".");
        int intkmp2=kmp2.lastIndexOf(".");

        while(kmp1.size() > intkmp+3)
        {
            kmp1.chop(1);
        }

        while(kmp2.size() > intkmp2+3)
        {
            kmp2.chop(1);
        }

        QStringList crutchy=kmp1.split(".");
        QString tr=crutchy[0];
        QString ccc=crutchy[1];

        ui->lineEdit_2->setText(kmp1);
        ui->lineEdit_wordsRes->setText(text.transist(tr,ccc));
        ui->NDS->setText(kmp2);

         crutchy=kmp2.split(".");
         tr=crutchy[0];
         ccc=crutchy[1];

       ui->lineEdit_WordsNDS->setText(text.transist(tr,ccc));
       return true;
    }


    for_nds=temp.toDouble(&ok);

    if(percent==0)
        percent=18;


    if(temp.contains("."))
    {
        QStringList magic1 = temp.split(".");

        if(magic1[1]=="0"||magic1[1]=="00")
        {
            QString zzzz=magic1[0];
            int qw=zzzz.toInt();
            double wq=qw+((qw/100)*percent);\

            QString qqq=QString::number(wq-qw,'f');
            QString ress=QString::number(wq,'f');

            ui->NDS->setText(qqq);
            ui->lineEdit_2->setText(ress);
            return 0;
        }

        rub=magic1[0].toInt();
        cop=magic1[1].toInt();
    }
    else
    {
       double zzresult=for_nds;
       for_nds=for_nds*(percent/100);
       zzresult=for_nds-zzresult;

       ui->lineEdit_2->setText(QString::number(for_nds,'f'));
       ui->NDS->setText(QString::number(zzresult,'f'));
    }

    double drub;
    double dcop;

   percent=percent/100;
   percent+=1;
   drub=rub*percent;
   dcop=cop*percent;

   if(dcop>100)
   {
     QString qw=QString::number(dcop,'f');
     QString hndr=qw.at(0);
     int asdf=hndr.toInt();
     drub+=asdf;
     dcop-=100;
   }//end if


   QStringList bb=QString::number(drub,'f').split(".");
   QString rublezz=bb[0];
   dcop+=bb[1].toInt();
   QString crutches=QString::number(dcop,'f');
   QStringList aa=crutches.split(".");
   QString copres=aa[0]+aa[1];


   result=rublezz+"."+copres;
   int kmp1=result.lastIndexOf(".");

   while(result.size()>kmp1+3)
   {
       result.chop(1);
   }

   ui->lineEdit_2->setText(result);

   double nds_start;
   nds_start=result.toDouble(&ok);

   QString nds_res=QString::number(nds_start-for_nds,'f');
   int kmp=nds_res.lastIndexOf(".");   
   while(nds_res.size()>kmp+3)
   {
       nds_res.chop(1);
   }
   ui->NDS->setText(nds_res);


   QString cop_part;
   QString rub_part;
   QStringList NDS_words=nds_res.split(".");
   cop_part=NDS_words[1];
   rub_part=NDS_words[0];
   ui->lineEdit_WordsNDS->setText(text.transist(rub_part,cop_part));

   QStringList res_w=result.split(".");
   QString rr_part=res_w[0];
   QString cr_part=res_w[1];
   QString fml=text.transist(rr_part,cr_part);
   ui->lineEdit_wordsRes->setText(fml);

   return 0;

}
