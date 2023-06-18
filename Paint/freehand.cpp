#include <cmath>
#include "freehand.h"

#include <iostream>

FreeHand::FreeHand(QPoint startPoint_, QColor color_)
{
    points[0] = startPoint_;
    color = color_;
}

FreeHand::FreeHand(const FreeHand &obj)
{
    startPoint = obj.startPoint;
    color = obj.color;
    index = obj.index;

    for(int i = 0; i < LIMIT; i++)
    {
        points[i] = obj.points[i];
    }
}

FreeHand& FreeHand::operator=(const FreeHand &obj)
{
    if(this == &obj)
        return *this;

    startPoint = obj.startPoint;
    color = obj.color;
    index = obj.index;

    for(int i = 0; i < LIMIT; i++)
    {
        points[i] = obj.points[i];
    }

    return *this;
}

FreeHand::~FreeHand()
{

}

bool FreeHand::update(QPoint point)
{
    if(index <= LIMIT)
        points[++index] = point;
    return true;
}

void FreeHand::paint(QPainter *painter)
{
    painter->setPen(QPen(color, 2));
    painter->drawPolyline(points, index);
}

bool FreeHand::tooSmall()
{
    int distance = 0;
    for(int i  = 1; i <= index; i++)
    {
        float c2 = pow(points[i].toPointF().x()-points[i-1].toPointF().x(),2) +
                   pow(points[i].toPointF().y()-points[i-1].toPointF().y(),2);

        distance += sqrt(c2);

        if(distance > 2)
            return false;
    }

    return true;
}

bool FreeHand::isInside(QPoint point)
{
    int distance = 0;
    for(int i  = 1; i <= index; i++)
    {
        int c2 = pow(points[i].x()-point.x(),2) +
                   pow(points[i].y()-point.y(),2);

        distance = sqrt(c2);

        if(distance <= 30)
            return true;
    }

    return false;
}

void FreeHand::reposition(QPoint point)
{
    for(int i  = 0; i < index; i++)
    {
        points[i] += point;
    }
}
