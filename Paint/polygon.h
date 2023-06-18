#ifndef POLYGON_H
#define POLYGON_H

#include "graphobj.h"


class Polygon : public GraphObj
{
private:
    QList<QPoint> &points;
    bool outlined;
public:
    Polygon(QPoint startPoint_, QColor color_, bool outlined_);
    Polygon(const Polygon &obj);
    Polygon& operator=(const Polygon &obj);
    ~Polygon();
    bool update(QPoint point) override;
    void paint(QPainter *painter) override;
    bool tooSmall() override;
    bool isInside(QPoint point) override;
    void reposition(QPoint point) override;
};

#endif // POLYGON_H
