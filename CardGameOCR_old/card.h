#ifndef CARD_H
#define CARD_H

#include <QObject>

class Card : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString blue MEMBER mBlue NOTIFY blueChanged)
    Q_PROPERTY(QString pink MEMBER mPink NOTIFY pinkChanged)
    Q_PROPERTY(QString yellow MEMBER mYellow NOTIFY yellowChanged)
    Q_PROPERTY(QString purple MEMBER mPurple NOTIFY purpleChanged)
    Q_PROPERTY(QString green MEMBER mGreen NOTIFY greenChanged)
    Q_PROPERTY(QString orange MEMBER mOrange NOTIFY orangeChanged)
    Q_PROPERTY(bool side READ isSideQ WRITE changeSide NOTIFY sideChanged)
    Q_PROPERTY(QString cardNumber READ getCardNumber WRITE setCardNumber
               NOTIFY cardNumberChanged)
    Q_PROPERTY(int cardSet READ getCardSet WRITE setCardSet NOTIFY cardSetChanged)

public:
    Card();
    void insertOCRresult(QList<QString> data);
    bool isSideQ();
    void changeSide(bool val);
    QString getCardNumber();
    void setCardNumber(QString number);
    int getCardSet();
    void setCardSet(int number);

private:
    QString mBlue;
    QString mPink;
    QString mYellow;
    QString mPurple;
    QString mGreen;
    QString mOrange;
    QList<QString> textLines;
    bool isSideA;
    QString cardNumber;
    int cardSet;

signals:
    void blueChanged();
    void pinkChanged();
    void yellowChanged();
    void purpleChanged();
    void greenChanged();
    void orangeChanged();
    void sideChanged();
    void cardNumberChanged();
    void cardSetChanged();
};

#endif // CARD_H
