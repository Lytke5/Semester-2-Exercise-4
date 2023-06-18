#ifndef GRAPHOBJ_H
#define GRAPHOBJ_H
#include <QPainter>


class GraphObj
{
protected:
    QPoint startPoint;    
    QColor color;
public:
    GraphObj();
    bool virtual update(QPoint point) = 0;
    void virtual paint(QPainter *painter) = 0;
    bool virtual tooSmall() = 0;
    bool virtual isInside(QPoint point) = 0;
    void changeColor(QColor newColor);
    void virtual reposition(QPoint point) = 0;
    virtual ~GraphObj();
};

#endif // GRAPHOBJ_H
