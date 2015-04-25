#include "numbers_to_words.h"
#include <QDebug>



QString words::transist(QString Number)
{

int digits=Number.count();
int iNumber=Number.toInt();
if (digits==1)
     {
      return units[iNumber];
     }
 if(digits==2)
    {
     qDebug()<<iNumber;
    return uniqs[iNumber];
    }
else
    {
    qDebug() <<"oopsie daisy";

    return "Failed";
    }
}

words::words()
{
    units={units0,units1,units2,units3,units4,units5,units6,units7,units8,units9};
   tens={tens1,tens2,tens3,tens4,tens5,tens6,tens7,tens8,tens9};
  hundreds={hundreds1,hundreds2,hundreds3,hundreds4,hundreds5,hundreds6,
            hundreds7,hundreds8,hundreds9};
  uniqs={uniqs10,uniqs11,uniqs12,uniqs13,uniqs14,uniqs15,uniqs16,uniqs17,uniqs18,uniqs19};

}

words::~words()
{

}

