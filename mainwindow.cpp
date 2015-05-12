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

   // std::cout<<std::fixed;
    words text;
    bool ok=false;
    double for_nds;
    int rub=0;
    int cop=0;
    double percent=18;
    QString result;
    QString temp;
//    QString rubl;
//    QString cpk;
    temp=ui->lineEdit->displayText();


    percent=ui->Nalog->displayText().toInt();
    temp.replace(",",".");

    if(!temp.contains("."))
    {
        //qDebug()<<"woohooo!11";

        double rr=temp.toDouble();
        double nal=rr*(percent/100);

        rr=rr+(rr*(percent/100));
        int kmp1=rr.lastIndexOf(".");
        int kmp2=nal.lastIndexOf(".");
        //qDebug()<<"KMP ="<<kmp;
        while(rr.size()>kmp1+3)
        {
            rr.chop(1);
        }
        while(nal.size()>kmp2+3)
        {
            nal.chop(1);
        }
        ui->lineEdit_2->setText(QString::number(rr,'f'));
        ui->NDS->setText(QString::number(nal,'f'));
 //      QString q=QString::number(rr);
       // QString w=QString::number(nal);
 //        if(q.contains(","))
 //        {
 //        QStringList qw=w.split(",");
 //        QString w1=qw[0];
 //        QString w2=qw[1];
 //                ui->lineEdit_WordsNDS->setText(text.transist(w1,w2))
 //               ;
 //        }
 //        if(q.contains(","))
 //        {
 //         QStringList wq=q.split(",");
 //         QString wq1=wq[0];
 //          QString wq2=wq[1];
 //          ui->lineEdit_wordsRes->setText(text.transist(wq1,wq2));
 //        }

     //   ui->lineEdit_WordsNDS->setText(text.transist(w,"00"));
     //   ui->lineEdit_wordsRes->setText(text.transist(q,"00"));
                  return true;
    }


    for_nds=temp.toDouble(&ok);


    if(percent==0)
        percent=18;


//    if(temp.contains(","))
//        {
//    QStringList magic = temp.split(",");


//    //wtf control
//    QString bugfix=magic[1];
//        if(bugfix=="0"||bugfix=="00")
//       {

//           QString zzzz=magic[0];
//           int qw=zzzz.toInt();

//           double wq=qw+((qw/100)*percent);\
//           QString qqq=QString::number(wq-qw);
//           QString ress=QString::number(wq);



//           ui->NDS->setText(qqq);
//           ui->lineEdit_2->setText(ress);
//           return 0;

//       }
//    // list2: [ "a", "b", "c" ]
//    //qDebug()<<magic;
//        rub=magic[0].toInt();
//        cop=magic[1].toInt();
//         //qDebug()<<rub;
//    }
    qDebug()<<"1...";
    if(temp.contains("."))
    {
        QStringList magic1 = temp.split(".");
          qDebug()<<"2...";
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

         qDebug()<<"3...";
        rub=magic1[0].toInt();
        cop=magic1[1].toInt();
          qDebug()<<"4...";
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
  qDebug()<<"5...";
     QString qw=QString::number(dcop,'f');
     QString hndr=qw.at(0);
     int asdf=hndr.toInt();
     drub+=asdf;
     dcop-=100;
  qDebug()<<"6...";
   }//end if


  qDebug()<<"7...";
   QStringList bb=QString::number(drub,'f').split(".");
   qDebug()<<"s1";
   QString rublezz=bb[0];
   qDebug()<<"s2"<<bb[0]<<bb[1];
   dcop+=bb[1].toInt();
   qDebug()<<"s3";
   QString crutches=QString::number(dcop,'f');
   qDebug()<<"s4";
   QStringList aa=crutches.split(".");
   qDebug()<<"s5";
   QString copres=aa[0]+aa[1];
     qDebug()<<"8...";


   result=rublezz+"."+copres;
   int kmp1=result.lastIndexOf(".");
   while(result.size()>kmp1+3)
   {
       result.chop(1);
   }
//   while(result.endsWith("0"))
//    {
//         result.chop(1);
//     }
   ui->lineEdit_2->setText(result);


    double nds_start;

    nds_start=result.toDouble(&ok);

   QString nds_res=QString::number(nds_start-for_nds,'f');
   int kmp=nds_res.lastIndexOf(".");
   //qDebug()<<"KMP ="<<kmp;
   while(nds_res.size()>kmp+3)
   {
       nds_res.chop(1);
   }
//   while(nds_res.endsWith("0"))
//   {
//       nds_res.chop(1);
//   }

   ui->NDS->setText(nds_res);



  qDebug()<<"9...";
   QString cop_part;
   QString rub_part;
   QStringList NDS_words=nds_res.split(".");
   cop_part=NDS_words[1];
   rub_part=NDS_words[0];
  qDebug()<<"10...";
   ui->lineEdit_WordsNDS->setText(text.transist(rub_part,cop_part));
   ui->textEdit->setText(text.transist(rub_part,cop_part));

   QStringList res_w=result.split(".");
   QString rr_part=res_w[0];
   QString cr_part=res_w[1];
   QString fml=text.transist(rr_part,cr_part);
   ui->textEdit_RUB->setText(fml);
   ui->lineEdit_wordsRes->setText(fml);

//QString asdf=text.transist("607","247");
//qDebug()<<asdf;
   //13
     qDebug()<<"END...";




   return 0;

}
