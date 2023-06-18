#include <cmath>
#include "circle.h"

Circle::Circle(QPoint startPoint_, QColor color_, bool outlined_)
{
    startPoint = startPoint_;
    endPoint = startPoint_;
    color = color_;
    outlined = outlined_;
}

Circle::Circle(const Circle &obj)
{
    startPoint = obj.startPoint;
    endPoint = obj.endPoint;
    color = obj.color;
    outlined = obj.outlined;
}

Circle& Circle::operator=(const Circle &obj)
{
    if(this == &obj)
        return *this;

    startPoint = obj.startPoint;
    endPoint = obj.endPoint;
    color = obj.color;
    outlined = obj.outlined;

    return *this;
}

Circle::~Circle()
{

}

bool Circle::update(QPoint point)
{
    endPoint = point;
    return true;
}

void Circle::paint(QPainter *painter)
{
    if (!outlined)
    {
        painter->setPen(Qt::NoPen);
        painter->setBrush(color);
    }
    else
    {
        painter->setPen(QPen(color, 2));
        painter->setBrush(Qt::NoBrush);
    }

    int radius = endPoint.x()-startPoint.x();
    painter->drawEllipse(startPoint, radius, radius);
}

bool Circle::tooSmall()
{
    float area = 4/3 * 3.1415 * endPoint.x()-startPoint.x() * endPoint.y()-startPoint.y();
    if(area < 0)
        area *= -1;

    if(area < 2)
        return true;

    return false;
}

bool Circle::isInside(QPoint point)
{
    int radius = endPoint.x()-startPoint.x();

    if(radius < 0)
        radius *= -1;

    int c2 = pow(startPoint.x()-point.x(),2) +
                   pow(startPoint.y()-point.y(),2);

    int distance = sqrt(c2);

    if(distance <= radius)
        return true;

    return false;
}

void Circle::reposition(QPoint point)
{
    startPoint += point;
    endPoint += point;
}
