#include "numbers_to_words.h"
#include <QDebug>


QString words::getEnding(int rubless)
{
    if(rubless==1)
        return onerub;
    if(rubless>1&&rubless<5)
        return rublia;
    if (rubless>=5)
        return ruble;
}

QString words::getHundreds(QCharRef &isHundreds,QCharRef &isTens,QCharRef &isUnits)
{
    QString t=getTens(isTens,isUnits);
    QString h=isHundreds;
    return hundreds[h.toInt()-1]+" "+t;
//    QString tmp=isTens;
//    int dec=tmp.toInt();
//    dec-=1;
//    QString zxc=


}

QString words::getTens(QCharRef &t0,QCharRef &ed1)
{
    QString nmb=t0;
    nmb+=ed1;
   int rnumber=nmb.toInt();
    if(rnumber>=10&&rnumber<20){

    if(rnumber==1)
    return uniqs[rnumber-10]+" "+onerub;
    if(rnumber>1&&rnumber<5)
        return uniqs[rnumber-10]+" "+rublia;
    if(rnumber>=5)
          return uniqs[rnumber-10]+" "+ruble;
    //return "digits is 2";
    }
    if(rnumber>=20)
    {
       QString s1=t0;
       int n1=s1.toInt();
       if(ed1==0)
           return tens[n1-1]+" "+getEnding(6);
       s1=ed1;
       int n2=s1.toInt();
        return tens[n1-1]+" "+units[n2]+" "+getEnding(n2);

    }
}

QString words::getEnding(QString kopeck)
{
    int c=kopeck.toInt();
    if(c==1)
        return onecop;
    if(c>1&&c<5)
        return cop2;
    if(c>=5)
        return cops;
}
QString words::transist(QString Rubles,QString Cops)
{


   if(Cops.count()<2)
       Cops+="0";   
  QString cOut;
  QString cut=Cops[0];
  cut+=Cops[1];

  int cNumber=cut.toInt();
 qDebug()<< cut;
 if(cNumber>=0&&cNumber<=9)
     cOut=", "+units[cNumber]+" "+getEnding(cut);
    if(cNumber==2)
    {    cOut.replace("Два","Две");
         //  qDebug()<<"dvaaa!";
    }
  if(cNumber>=10&&cNumber<20){
      cOut=", "+uniqs[cNumber-10]+" "+getEnding(cut);
  qDebug()<< cOut;}
  if(cNumber>=20)
     { QString c1=Cops[0];
     int co1=c1.toInt();
     c1=Cops[1];
     int co2=c1.toInt();
     cOut=", "+tens[co1-1]+" "+units[co2]+" "+getEnding(cut);
     qDebug()<< cOut;
     if(co2==2)
        { cOut.replace("Два","Две");
       //  qDebug()<<"dvaaa!";
     }
  }


int digits=Rubles.count();
int rNumber=Rubles.toInt();

if (digits==1)
     {
      return units[rNumber]+cOut;
     }
 if(digits==2)
    {
  //QString zxc=getTens(rNumber,Rubles,cOut);
  return getTens(Rubles[0],Rubles[1])+cOut;
//     if(rNumber>=10&&rNumber<20){
//     if(rNumber==1)
//     return uniqs[rNumber-10]+" "+onerub+cOut;
//     if(rNumber>1&&rNumber<5)
//         return uniqs[rNumber-10]+" "+rublia+cOut;
//     if(rNumber>=5)
//           return uniqs[rNumber-10]+" "+ruble+cOut;
//     //return "digits is 2";
//     }
//     if(rNumber>=20)
//     {
//        QString s1=Rubles[0];
//        int n1=s1.toInt();
//        if(Rubles[1]==0)
//            return tens[n1-1]+" "+getEnding(6)+cOut;
//        s1=Rubles[1];
//        int n2=s1.toInt();
//         return tens[n1-1]+" "+units[n2]+" "+getEnding(n2)+cOut;
//     }
    }
 if(digits==3)
 {

   return getHundreds(Rubles[0],Rubles[1],Rubles[2])+cOut;
//     QString t=getTens(Rubles[1],Rubles[2],cOut);
//     QString hndr=Rubles[0];
     //int h=reinterpret_cast<int>(hndr);
     //return hundreds[hndr.toInt()-1]+" "+t;

 }
 if(digits==4)
 {
  QString four=getTens(Rubles[2],Rubles[3]);
  QString Hundred=Rubles[1];
  Hundred=hundreds[Hundred.toInt()-1]+" "+four+cOut;
  QChar n=Rubles[0];
  four=n;

  if(n=="1"){
  return odna+" "+thousand+" "+Hundred;
  }
  if(n=="2")
  {
      return dve+" "+thousands+" "+Hundred;
  }
  return units[(four.toInt())]+" "+thousands+" "+Hundred;
 }
 if(digits==5)
 {
     QString t=getTens(Rubles[3],Rubles[4]);
     QString Hundred=Rubles[2];
     Hundred=hundreds[Hundred.toInt()-1]+" "+t+cOut;

 }
 if(digits==6)
 {
     //123 123
     QString h1=getHundreds(Rubles[0],Rubles[1],Rubles[2]);
     QString h2=getHundreds(Rubles[3],Rubles[4],Rubles[5]);
     return h1+h2+cOut;
 }
else
    {
    qDebug() <<"oopsie daisy";

    return "digits is not 2";
    }
 return "ERROR";
}



words::words()
{
    const QString units0="Ноль";
    const QString units1="Один";
    const QString units2="Два";
    const QString units3="Три";
    const QString units4="Четыре";
    const QString units5="Пять";
    const QString units6="Шесть";
    const QString units7="Семь";
    const QString units8="Восемь";
    const QString units9="Девять";
    const QString uniqs10="Десять";

        const QString uniqs11="Одинадцать";
        const QString uniqs12="Двенадцать";
        const QString uniqs13="Тринадцать";
        const QString uniqs14="Четырнадцать";
        const QString uniqs15="Пятнадцать";
        const QString uniqs16="Шестнадцать";
        const QString uniqs17="Семнадцать";
        const QString uniqs18="Восемнадцать";
        const QString uniqs19="Девятнадцать";

        const QString tens1="Десять";
        const QString tens2="Двадцать";
        const QString tens3="Тридцать";
        const QString tens4="Сорок";
        const QString tens5="Пятьдесят";
        const QString tens6="Шестьдесят";
        const QString tens7="Семьдесят";
        const QString tens8="Восемьдесят";
        const QString tens9="Девяносто";



        const QString hundreds1="Сто";
        const QString hundreds2="Двести";
        const QString hundreds3="Триста";
        const QString hundreds4="Четыреста";
        const QString hundreds5="Пятсот";
        const QString hundreds6="Шестьсот";
        const QString hundreds7="Семьсот";
        const QString hundreds8="Восемьсот";
        const QString hundreds9="Девятьсот";

    units={units0,units1,units2,units3,units4,units5,units6,units7,units8,units9};
   tens={tens1,tens2,tens3,tens4,tens5,tens6,tens7,tens8,tens9};
  hundreds={hundreds1,hundreds2,hundreds3,hundreds4,hundreds5,hundreds6,
            hundreds7,hundreds8,hundreds9};
  uniqs={uniqs10,uniqs11,uniqs12,uniqs13,uniqs14,uniqs15,uniqs16,uniqs17,uniqs18,uniqs19};

}

words::~words()
{

}

