#ifndef WORDS_H
#define WORDS_H
#include <QString>
#include <QVector>

class words
{

public:  

    QString transist(QString Rubles, QString Cops);
    QString transist(double Rubles);

    words();
    ~words();

QVector<QString> units;
QVector<QString> tens;
QVector<QString> hundreds;
QVector<QString> uniqs;


    const QString ruble="Рублей";
    const QString onerub="Рубль";
    const QString rublia="Рубля";
    const QString cops="Копеек";
    const QString onecop="Копейка";
   const QString cop2= "Копейки";

   const QString dve="Двe";
   const QString odna="Одна";


    const QString thousand="Тысяча";
    const QString thousands="Тысячи";
    const QString ttt="Тысяч";

    const QString mill="Миллион";
    const QString mills="Миллионов";


    const QString mlrd="Миллиард";
    const QString mlrds="Миллиардов";
    const QString trills="Триллионов";
    const QString trill="Триллион";



private:
    QString getEnding(int rubless);
    QString getEnding(QString kopeck);
    QString getTens(QCharRef tens, QCharRef units);
    QString getHundreds(QCharRef isHundreds, QCharRef isTens, QCharRef isUnits);
    void trim(QString &h1);
    QString getEndingThousand(QCharRef ru);


};

#endif // WORDS_H
