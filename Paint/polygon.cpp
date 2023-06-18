#include "polygon.h"

Polygon::Polygon(QPoint startPoint_, QColor color_, bool outlined_) : points(*(new QList<QPoint>()))
{
    startPoint = startPoint_;
    points.push_back(startPoint);
    color = color_;
    outlined = outlined_;
}

Polygon::Polygon(const Polygon &obj) : points(obj.points)
{
    startPoint = obj.startPoint;
    color = obj.color;
    outlined = obj.outlined;

    for(int i = 0; i < points.size(); i++)
    {
        points[i] = obj.points[i];
    }
}

Polygon& Polygon::operator=(const Polygon &obj)
{
    if(this == &obj)
        return *this;

    startPoint = obj.startPoint;
    color = obj.color;
    outlined = obj.outlined;
    for(int i = 0; i < points.size(); i++)
    {
        points[i] = obj.points[i];
    }

    return *this;
}

Polygon::~Polygon()
{

}

bool Polygon::update(QPoint point)
{
    int distanceX = point.x() - startPoint.x();
    int distanceY = point.y() - startPoint.y();

    if(((distanceX < 50 && distanceX > 0) || (distanceX > -50 && distanceX < 0)) &&
        ((distanceY < 50 && distanceY > 0) || (distanceY > -50 && distanceY < 0)))
    {
        points.push_back(points.front());
        return true;
    }

    points.push_back(point);
    return false;
}

void Polygon::paint(QPainter *painter)
{
    if(points.size() == 2)
    {
        painter->setPen(QPen(color, 2));
        painter->setBrush(Qt::NoBrush);
        painter->drawLine(startPoint, points[1]);
        return;
    }

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

        painter->drawPolygon(points);
}

bool Polygon::tooSmall()
{
    int distance = 0;
    for(int i  = 1; i <= points.size(); i++)
    {
        float c2 = pow(points[i].toPointF().x()-points[i-1].toPointF().x(),2) +
                   pow(points[i].toPointF().y()-points[i-1].toPointF().y(),2);

        distance += sqrt(c2);

        if(distance > 2)
            return false;
    }

    return true;
}

bool Polygon::isInside(QPoint point)
{
    int numIntersections = 0;
    int numVertices = points.size();

    for (int i = 0, j = numVertices - 1; i < numVertices; j = i++)
    {
        if (((points[i].y() > point.y()) != (points[j].y() > point.y())) &&
            (point.x() < (points[j].x() - points[i].x()) * (point.y() - points[i].y()) / (points[j].y() - points[i].y()) + points[i].x()))
        {
            numIntersections++;
        }
    }

    return (numIntersections % 2 == 1);
}

void Polygon::reposition(QPoint point)
{
    for(int i  = 0; i < points.size(); i++)
    {
        points[i] += point;
    }
}
