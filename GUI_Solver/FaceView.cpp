#include "FaceView.h"

FaceView::FaceView(QGraphicsScene *scene, int x, int y, QChar color)
{
    // create cubies and add them to the scene
    for (int i = 0; i < 3; i++) {
        QVector<CubieView*> temp;
        for (int j = 0; j < 3; j++) {
            temp.push_back(new CubieView(x + i*SIDE_LENGTH,y + j*SIDE_LENGTH, color));
            scene->addItem(temp[j]);
        }
        cubies.push_back(temp);
    }
}

QString const FaceView::getFace()
{
    QString output;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            output += cubies[i][j]->getColor();
        }
    }
    return output;
}

void FaceView::setFace(QString input)
{
    int position = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cubies[i][j]->setColor(input.at(position));
            position++;
        }
    }
}

void FaceView::update()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cubies[i][j]->update();
        }
    }
}

void FaceView::rotate()
{
    cyclic_roll(cubies[0][0], cubies[0][2], cubies[2][2], cubies[2][0]); //corner pieces
    cyclic_roll(cubies[0][1], cubies[1][2], cubies[2][1], cubies[1][0]); //inner cross
}

void FaceView::rotateCCW()
{
    cyclic_roll(cubies[0][0], cubies[2][0], cubies[2][2], cubies[0][2]); //corner pieces
    cyclic_roll(cubies[0][1], cubies[1][0], cubies[2][1], cubies[1][2]); //inner cross
}

void FaceView::cyclic_roll(CubieView* &a, CubieView* &b, CubieView* &c, CubieView* &d)
{ //copied from StackOverflow
   QChar temp = a->getColor();
   a->setColor(b->getColor());
   b->setColor(c->getColor());
   c->setColor(d->getColor());
   d->setColor(temp);
}

QVector<QChar> const FaceView::getTop()
{
    QVector<QChar> temp;
    temp.push_back(cubies[0][0]->getColor());
    temp.push_back(cubies[1][0]->getColor());
    temp.push_back(cubies[2][0]->getColor());
    return temp;
}

QVector<QChar> const FaceView::getBottom()
{
    QVector<QChar> temp;
    temp.push_back(cubies[0][2]->getColor());
    temp.push_back(cubies[1][2]->getColor());
    temp.push_back(cubies[2][2]->getColor());
    return temp;
}

QVector<QChar> const FaceView::getLeft()
{
    QVector<QChar> temp;
    temp.push_back(cubies[0][0]->getColor());
    temp.push_back(cubies[0][1]->getColor());
    temp.push_back(cubies[0][2]->getColor());
    return temp;
}

void FaceView::topTurn(QVector<QChar> input)
{
    cubies[0][0]->setColor(input[0]);
    cubies[1][0]->setColor(input[1]);
    cubies[2][0]->setColor(input[2]);
}

void FaceView::bottomTurn(QVector<QChar> input)
{
    cubies[0][2]->setColor(input[0]);
    cubies[1][2]->setColor(input[1]);
    cubies[2][2]->setColor(input[2]);
}

void FaceView::leftTurn(QVector<QChar> input)
{
    cubies[0][0]->setColor(input[0]);
    cubies[0][1]->setColor(input[1]);
    cubies[0][2]->setColor(input[2]);
}

QVector<QChar> FaceView::topTurn(QVector<QChar> input, int in)
{   //create the vector that will be passed to the next face
    QVector<QChar> temp;
    temp.push_back(cubies[0][0]->getColor());
    temp.push_back(cubies[1][0]->getColor());
    temp.push_back(cubies[2][0]->getColor());
    //set the cubies in this face with the input cubies
    cubies[0][0]->setColor(input[0]);
    cubies[1][0]->setColor(input[1]);
    cubies[2][0]->setColor(input[2]);

    return temp;
}

QVector<QChar> FaceView::bottomTurn(QVector<QChar> input, int n)
{
    QVector<QChar> temp;
    temp.push_back(cubies[0][2]->getColor());
    temp.push_back(cubies[1][2]->getColor());
    temp.push_back(cubies[2][2]->getColor());

    cubies[0][2]->setColor(input[0]);
    cubies[1][2]->setColor(input[1]);
    cubies[2][2]->setColor(input[2]);

    return temp;
}

QVector<QChar> FaceView::leftTurn(QVector<QChar> input, int in)
{
    QVector<QChar> temp;
    if(in < 0) {
        temp.push_back(cubies[0][2]->getColor());
        temp.push_back(cubies[0][1]->getColor());
        temp.push_back(cubies[0][0]->getColor());
    }
    else {
        temp.push_back(cubies[0][0]->getColor());
        temp.push_back(cubies[0][1]->getColor());
        temp.push_back(cubies[0][2]->getColor());
    }

    cubies[0][0]->setColor(input[0]);
    cubies[0][1]->setColor(input[1]);
    cubies[0][2]->setColor(input[2]);

    return temp;
}

QVector<QChar> FaceView::rightTurn(QVector<QChar> input, int in)
{
    QVector<QChar> temp;
    if(in < 0) {
        temp.push_back(cubies[2][2]->getColor());
        temp.push_back(cubies[2][1]->getColor());
        temp.push_back(cubies[2][0]->getColor());
        cubies[2][2]->setColor(input[0]);
        cubies[2][1]->setColor(input[1]);
        cubies[2][0]->setColor(input[2]);
   }
    else {
        temp.push_back(cubies[2][0]->getColor());
        temp.push_back(cubies[2][1]->getColor());
        temp.push_back(cubies[2][2]->getColor());
        cubies[2][0]->setColor(input[0]);
        cubies[2][1]->setColor(input[1]);
        cubies[2][2]->setColor(input[2]);
    }

    return temp;
}
