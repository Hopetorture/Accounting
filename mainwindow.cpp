#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QStack>
#include "numbers_to_words.h"



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
        ui->lineEdit_2->setText(QString::number(rr));
        ui->NDS->setText(QString::number(nal));
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
    if(temp.contains("."))
    {
        QStringList magic1 = temp.split(".");
        if(magic1[1]=="0"||magic1[1]=="00")
        {
            QString zzzz=magic1[0];
            int qw=zzzz.toInt();
            double wq=qw+((qw/100)*percent);\

            QString qqq=QString::number(wq-qw);
            QString ress=QString::number(wq);

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
       ui->lineEdit_2->setText(QString::number(for_nds));
       ui->NDS->setText(QString::number(zzresult));
    }

    double drub;
    double dcop;


   percent=percent/100;
   percent+=1;
   drub=rub*percent;
   dcop=cop*percent;

   if(dcop>100)
   {

     QString qw=QString::number(dcop);
     QString hndr=qw.at(0);
     int asdf=hndr.toInt();
     drub+=asdf;
     dcop-=100;

   }//end if



   QStringList bb=QString::number(drub).split(".");
   QString rublezz=bb[0];
   dcop+=bb[1].toInt();
   QString crutches=QString::number(dcop);
   QStringList aa=crutches.split(".");
   QString copres=aa[0]+aa[1];


   result=rublezz+"."+copres;
   ui->lineEdit_2->setText(result);


    double nds_start;

    nds_start=result.toDouble(&ok);

   QString nds_res=QString::number(nds_start-for_nds);

   ui->NDS->setText(nds_res);



   QString cop_part;
   QString rub_part;
   QStringList NDS_words=nds_res.split(".");
   cop_part=NDS_words[1];
   rub_part=NDS_words[0];

  // QStringList rub_words=
   //QString test="5";
   ui->lineEdit_WordsNDS->setText(text.transist(rub_part,cop_part));
   ui->textEdit->setText(text.transist(rub_part,cop_part));
   ui->lineEdit_wordsRes->setText(text.transist(rublezz,copres));
   //1 000 000 000 000
   //13




   return 0;

}
