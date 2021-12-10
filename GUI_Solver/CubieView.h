#ifndef CUBIE_H
#define CUBIE_H

#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QColor>

class CubieView : public QGraphicsRectItem
{
public:
    CubieView(int x, int y)
    {
         setRect(x,y,SIDE_LENGTH,SIDE_LENGTH);
         pen.setWidth(CUBIE_OUTLINE);
         setPen(pen);
    }

    void setColor(QChar color)
    {
        setBrush(getColorCode(color));
    }

private:
    const int SIDE_LENGTH = 45, CUBIE_OUTLINE = 5;
    QPen pen;
    QColor const getColorCode(QChar color)
    {
        //Bunch of magic numbers to get the RGB or Qt defined colors
        switch(color.unicode()) {
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
            return Qt::black;               //this means something went wrong
        }
    }
};

#endif // CUBIE_H
