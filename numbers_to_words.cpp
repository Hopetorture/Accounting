#include "numbers_to_words.h"
#include <QDebug>


void words::trim(QString &h1)
{
    h1.remove(ruble);
    h1.remove(rublia);
    h1.remove(onerub);

    if(h1.contains("Один"))
      {
        h1.replace("Один","Одна");
    }
    if(h1.contains("Два"))
    {
        h1.replace("Два","Две");
    }
    if(h1.contains("Дведцать"))
    {
        h1.replace("Дведцать","Двадцать");
    }


}
QString words::getEndingThousand(QCharRef ru)
{
    QString f=ru;
            int rubless=f.toInt();
    if(rubless==1)
        return "Тысяча";
    if(rubless>1&&rubless<5)
        return "Тысячи";
    if (rubless>=5)
        return "Тысячь";
    return "Тысяь";
}

QString words::getEnding(int rubless)
{
    if(rubless==1)
        return onerub;
    if(rubless>1&&rubless<5)
        return rublia;
    if (rubless>=5)
        return ruble;
    return "Ошибка";
}

QString words::getHundreds(QCharRef isHundreds,QCharRef isTens,QCharRef isUnits)
{
    QString t=getTens(isTens,isUnits);
    QString h=isHundreds;
    int zxcv=h.toInt();
    QString zzz=hundreds[zxcv-1]+" "+t;
    return zzz;

}

QString words::getTens(QCharRef t0,QCharRef ed1)
{
    QString fq=t0;
    QString fqq=ed1;
    if(fq=="0"&&fqq=="0")
        return" ";    


    QString nmb=t0;
    nmb+=ed1;
   int rnumber=nmb.toInt();

   if(rnumber==1)
   {
   return units[rnumber]+" "+onerub;
   }
   if(rnumber>1&&rnumber<5)
   {
       return units[rnumber]+" "+rublia;
   }
   if(rnumber>=5&&rnumber<10)
   {
         return units[rnumber]+" "+ruble;
   }
    if(rnumber>=10&&rnumber<20)
    {
     return uniqs[rnumber-10]+" "+ ruble;
    }
    if(rnumber>=20)
    {
       QString s1=t0;
       int n1=s1.toInt();
       if(fqq=="0")
       {
           return tens[n1-1]+" "+getEnding(6);
       }
       s1=ed1;
       int n2=s1.toInt();

       return tens[n1-1]+" "+units[n2]+" "+getEnding(n2);

    }
    return"Ошибка";
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
    return cops;
}
QString words::transist(QString Rubles,QString Cops)
{

   while (Cops.size()>2){
        Cops.chop(1);
   }  

  while(Cops.count()<2)
  {
       Cops+="0";   
  }

  QString cOut;
  QString cut=Cops[0];
  cut+=Cops[1];


  int cNumber=cut.toInt();
 if(cNumber>0&&cNumber<=9) 
        cOut=", "+units[cNumber]+" "+getEnding(cut);

    if(cNumber==2)
    {
        cOut.replace("Два","Две");
    }


  if(cNumber>=10&&cNumber<20){
        cOut=", "+uniqs[cNumber-10]+" "+getEnding(cut);

  }

  if(cNumber>=20)
     {
     QString c1=Cops[0];
     int co1=c1.toInt();
     c1=Cops[1];
     int co2=c1.toInt();
     cOut=", "+tens[co1-1]+" "+units[co2]+" "+getEnding(cut);

     if(co2==2)
        {
         cOut.replace("Два","Две");
        }
  }

  if(cOut.contains("Ноль"))
  {
      cOut.remove("Ноль");
  }
    if(cut=="00")
          {
           cOut=" ,Ноль Копеек";
          }


int digits=Rubles.count();
int rNumber=Rubles.toInt();

if (digits==1)
     {
      return units[rNumber]+cOut;
     }

 if(digits==2)
     {
      return getTens(Rubles[0],Rubles[1])+cOut;
     }

 if(digits==3)
 {
   return getHundreds(Rubles[0],Rubles[1],Rubles[2])+cOut;
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
     QString r=getTens(Rubles[0],Rubles[1]);

     trim(r);

     r+=" ";
     r+=Hundred;
     return r;

 }
 if(digits==6)
 {
     QString h1=getHundreds(Rubles[0],Rubles[1],Rubles[2]);
     trim(h1);
     QString fml=getEndingThousand(Rubles[3]);
     h1+=fml;
     QString h2=getHundreds(Rubles[3],Rubles[4],Rubles[5]);
     return h1+" "+h2+cOut;
 }
 if(digits==7)
 {
     QString h1=getHundreds(Rubles[1],Rubles[2],Rubles[3]);
     trim(h1);
     QString fml=getEndingThousand(Rubles[3]);
     h1+=fml;

     QString h2=getHundreds(Rubles[4],Rubles[5],Rubles[6]);
     QString ttmp=Rubles[0];
     int t=ttmp.toInt();
     if(t==1){
       QString zxx=units[1]+" "+mill+" "+h1+" "+h2+cOut;

       return zxx;
     }
     fml=Rubles[0];
     int asdf=fml.toInt();
     return units[asdf]+" "+mills+" "+h1+" "+h2+cOut;
 }
 if(digits==8)
 {

     QString h1=getHundreds(Rubles[2],Rubles[3],Rubles[4]);
     QString h2=getHundreds(Rubles[5],Rubles[6],Rubles[7]);
     QString t1=getTens(Rubles[0],Rubles[1]);

     trim(h1);
     t1.remove(ruble);
     t1.remove(rublia);
     t1.remove(onerub);
     QString zxc=getEndingThousand(Rubles[4]);
     h1+=zxc;
     return t1+" "+mills+" "+h1+" "+h2+cOut;

 }

 return "CЛИШКОМ БОЛЬШОЕ ЧИСЛО";
}

QString words::transist(double Rubles)
{

return QString("Not yet implemented");


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

