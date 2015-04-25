#ifndef WORDS_H
#define WORDS_H
#include <QString>
#include <QVector>

class words
{
public:
   // QVector<QVector<QString> > cheats[7][10];
//    QString array[2][10]=
//    {{units0,units1,units2,units3,units4,units5,units6,units7,units8,units9},
//     {tens1,tens2,tens3,tens4,tens5,tens6,tens7,tens8,tens9,NULL}

//    };

//QVector<QString> units=(units0,units1,units2,units3,units4,units5,units6,units7,units8,units9);
//QVector<QString> tens=(tens1,tens2,tens3,tens4,tens5,tens6,tens7,tens8,tens9);
//QVector<QString> hundreds={hundreds1,hundreds2,hundreds3,hundreds4,hundreds5,hundreds6,
//                           hundreds7,hundreds8,hundreds9};
QVector<QString> units;
QVector<QString> tens;
QVector<QString> hundreds;
QVector<QString> uniqs;


    const QString ruble="Рублей";
    const QString rublia="Рубля";
    const QString cops="Копеек";


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

    const QString thousand="Тысяча";
    const QString thousands="Тысячи";

    const QString mill="Миллион";
    const QString mills="Миллионов";


    const QString mlrd="Миллиард";
    const QString mlrds="Миллиардов";
    const QString trills="Триллионов";
    const QString trill="Триллион";
   // сonst QString trills="Триллионов";

    QString transist(QString Number);


    words();
    ~words();
};

#endif // WORDS_H
