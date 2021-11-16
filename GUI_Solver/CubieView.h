#ifndef CUBIE_H
#define CUBIE_H

#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QColor>

class CubieView : public QGraphicsRectItem
{
public:
    CubieView(int x, int y, QChar color);
    QChar const getColor();
    void setColor(QChar color);
    void update();                          //Updates the cubie after the color is changed

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

private:
    const int SIDE_LENGTH = 45, CUBIE_OUTLINE = 5;
    QPen pen;
    QChar currColor;
    QColor const getColorCode();
    void incrementColor();
};

#endif // CUBIE_H
