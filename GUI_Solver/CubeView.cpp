#include "cubeview.h"

CubeView::CubeView(QGraphicsScene *scene)
{
    L = new FaceView(scene, 0, 135, 'Y');
    U = new FaceView(scene, 135, 0, 'O');
    F = new FaceView(scene, 135, 135, 'G');
    D = new FaceView(scene, 135, 270, 'R');
    R = new FaceView(scene, 270, 135, 'W');
    B = new FaceView(scene, 405, 135, 'B');
}

QString const CubeView::getCube()
{
    QString output;

    output = F->getFace() + L->getFace() +
                U->getFace() + R->getFace() +
                B->getFace() + D->getFace();

    return output;
}


void CubeView::setCube(QString input)
{
    //FIXME check for errors in the cube
    F->setFace(input.left(9));
    L->setFace(input.mid(9,17));
    U->setFace(input.mid(18,26));
    R->setFace(input.mid(27,35));
    B->setFace(input.mid(36,44));
    D->setFace(input.right(9));
}

void CubeView::reset()
{
    setCube("GGGGGGGGGYYYYYYYYYOOOOOOOOOWWWWWWWWWBBBBBBBBBRRRRRRRRR");
}

void CubeView::update()
{
    F->update();
    L->update();
    U->update();
    R->update();
    B->update();
    D->update();
}

QString CubeView::scramble()
{
    reset();                //reset the cube so the scramble output is accurate
    QString output = "";
    RandomGenerator rg;
    QVector<int> scrambleList = rg.getRand();

    while(scrambleList.size() > 0) {
        output += turns(scrambleList[0]) + "  ";
        scrambleList.pop_front();
    }

    return output;
}

QString CubeView::turns(int turn)
{
    switch(turn) {
    case(0):
        fTurn();
        return "F";
    case(1):
        fprimeTurn();
        return "F'";
    case(2):
        bTurn();
        return "B";
    case(3):
        bprimeTurn();
        return "B'";
    case(4):
        uTurn();
        return "U";
    case(5):
        uprimeTurn();
        return "U'";
    case(6):
        dTurn();
        return "D";
    case(7):
        dprimeTurn();
        return "D'";
    case(8):
        lTurn();
        return "L";
    case(9):
        lprimeTurn();
        return "L'";
    case(10):
        rTurn();
        return "R";
    case(11):
        rprimeTurn();
        return "R'";
    }
    return "ERROR";
}


/*=================F TURNS ==================*/
void CubeView::fTurn()
{
    F->rotate();
//    QChar temp1, temp2, temp3;

//    temp1 = U->cubies[2][0] ->getColor();
//    temp2 = U->cubies[2][1]->getColor();
//    temp3 = U->cubies[2][2]->getColor();

    D->topTurn(R->leftTurn(U->bottomTurn(L->rightTurn(D->getTop(),-1),1),-1));
}
void CubeView::fprimeTurn()
{
    F->rotateCCW();
    D->topTurn(L->rightTurn(U->bottomTurn(R->leftTurn(D->getTop(),1),1),-1));
}
/*=================B TURNS ==================*/
void CubeView::bTurn()
{
    B->rotate();
    U->topTurn(R->rightTurn(D->bottomTurn(L->leftTurn(U->getTop(),-1),1),1));
}
void CubeView::bprimeTurn()
{
    B->rotateCCW();
    U->topTurn(L->leftTurn(D->bottomTurn(R->rightTurn(U->getTop(),1),1),-1));
}
/*=================U TURNS ==================*/
void CubeView::uTurn()
{
    U->rotate();
    F->topTurn(R->topTurn(B->topTurn(L->topTurn(F->getTop(),1),1),1));
}
void CubeView::uprimeTurn()
{
    U->rotateCCW();
    F->topTurn(L->topTurn(B->topTurn(R->topTurn(F->getTop(),1),1),1));
}
/*=================D TURNS ==================*/
void CubeView::dTurn()
{
    D->rotate();
    F->bottomTurn(L->bottomTurn(B->bottomTurn(R->bottomTurn(F->getBottom(),1),1),1));
}
void CubeView::dprimeTurn()
{
    D->rotateCCW();
    F->bottomTurn(R->bottomTurn(B->bottomTurn(L->bottomTurn(F->getBottom(),1),1),1));
}
/*=================L TURNS ==================*/
void CubeView::lTurn()
{
    L->rotate();
    F->leftTurn(U->leftTurn(B->rightTurn(D->leftTurn(F->getLeft(),1),1),1));
}
void CubeView::lprimeTurn()
{
    L->rotateCCW();
    F->leftTurn(D->leftTurn(B->rightTurn(U->leftTurn(F->getLeft(),1),1),1));
}
/*=================R TURNS ==================*/
void CubeView::rTurn()
{
    R->rotate();
    B->leftTurn(U->rightTurn(F->rightTurn(D->rightTurn(B->getLeft(),1),1),1));
}
void CubeView::rprimeTurn()
{
    R->rotateCCW();
     B->leftTurn(D->rightTurn(F->rightTurn(U->rightTurn(B->getLeft(),1),1),1));
}
