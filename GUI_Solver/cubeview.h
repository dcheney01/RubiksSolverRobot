#ifndef CUBEVIEW_H
#define CUBEVIEW_H

#include "FaceView.h"
#include "RandomGenerator.h"

class CubeView
{
public:
    CubeView(QGraphicsScene *scene);
    CubeView(const CubeView &c);
    QString const getCube();
    void setCube(QString input);
    void reset();
    void update();
    QString scramble();

    //Turns
    void fTurn();
    void fprimeTurn();
    void bTurn();
    void bprimeTurn();
    void uTurn();
    void uprimeTurn();
    void dTurn();
    void dprimeTurn();
    void lTurn();
    void lprimeTurn();
    void rTurn();
    void rprimeTurn();

private:
    QString turns(int turn);
    FaceView * F;
    FaceView * B;
    FaceView * L;
    FaceView * R;
    FaceView * U;
    FaceView * D;
};

#endif // CUBEVIEW_H
