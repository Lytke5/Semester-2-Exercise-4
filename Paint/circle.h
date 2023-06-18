#ifndef CIRCLE_H
#define CIRCLE_H
#include "graphobj.h"


class Circle : public GraphObj
{
private:
    bool outlined;
    QPoint endPoint;
public:
    Circle(QPoint startPoint_, QColor color_, bool outlined_);
    Circle(const Circle &obj);
    Circle& operator=(const Circle &obj);
    ~Circle();
    bool update(QPoint point) override;
    void paint(QPainter *painter) override;
    bool tooSmall() override;
    bool isInside(QPoint point) override;
    void reposition(QPoint point) override;
};

#endif // CIRCLE_H
