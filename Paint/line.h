#ifndef LINE_H
#define LINE_H
#include "graphobj.h"


class Line : public GraphObj
{
private:
    QPoint endPoint;
public:
    Line(QPoint startPoint_, QColor color_);
    Line(const Line &obj);
    Line& operator=(const Line &obj);
    ~Line();
    bool update(QPoint point) override;
    void paint(QPainter *painter) override;
    bool tooSmall() override;
    bool isInside(QPoint point) override;
    void reposition(QPoint point) override;
};

#endif // LINE_H
