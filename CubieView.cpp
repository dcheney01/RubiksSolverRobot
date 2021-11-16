#include "CubieView.h"

CubieView::CubieView(int x, int y, QChar color)
{
     setRect(x,y,SIDE_LENGTH,SIDE_LENGTH);
     currColor = color;
     setBrush(getColorCode());
     pen.setWidth(CUBIE_OUTLINE);
     setPen(pen);
}

QChar const CubieView::getColor()
{
    return currColor;
}

void CubieView::update()
{
    setBrush(getColorCode());
}


void CubieView::setColor(QChar color)
{
    currColor = color;
}

QColor const CubieView::getColorCode()
{
    //Bunch of magic numbers to get the RGB or Qt defined colors
    switch(currColor.unicode()) {
    case('G') :                         //GREEN
        return QColor(25,192,49);
    case('B') :                         //BLUE
        return QColor(23,84,255);
    case('R') :                         //RED
        return QColor(203,49,49);
    case('O') :                         //ORANGE
        return QColor("orange");
    case('Y') :                         //YELLOW
        return Qt::yellow;
    case('W') :                         //WHITE
        return Qt::white;
    default :
        return Qt::black; //this means something went wrong
    }
}

void CubieView::incrementColor()
{
    switch(currColor.unicode()) {
    case('G') :
        currColor =  'B';
        break;
    case('B') :
        currColor =  'R';
        break;
    case('R') :
        currColor =  'O';
        break;
    case('O') :
        currColor =  'Y';
        break;
    case('Y') :
        currColor =  'W';
        break;
    case('W') :
        currColor =  'G';
        break;
    }
}

void CubieView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    incrementColor();
    setBrush(getColorCode());
}
