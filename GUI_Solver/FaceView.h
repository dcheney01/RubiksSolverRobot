#ifndef FACEVIEW_H
#define FACEVIEW_H

#include <QGraphicsScene>
#include <QVector>

#include "cubieview.h"

class FaceView
{
public:
    FaceView(QGraphicsScene *scene, int x, int y, QChar color);
    QVector<QVector<CubieView*>> cubies;
    QString const getFace();
    void setFace(QString input);
    void update();

    void rotate();
    void rotateCCW();

    QVector<QChar> const getTop();
    QVector<QChar> const getBottom();
    QVector<QChar> const getLeft();

    void topTurn(QVector<QChar> input);
    QVector<QChar> topTurn(QVector<QChar> input, int in);
    void bottomTurn(QVector<QChar> input);
    QVector<QChar> bottomTurn(QVector<QChar> input, int in);
    void leftTurn(QVector<QChar> input);
    QVector<QChar> leftTurn(QVector<QChar> input, int in);
    QVector<QChar> rightTurn(QVector<QChar> input, int in);

private:
    const int SIDE_LENGTH = 45;
    void setCubies(QVector<CubieView*> input);
    void cyclic_roll(CubieView* &a, CubieView* &b, CubieView* &c, CubieView* &d);
};

#endif // FACEVIEW_H
