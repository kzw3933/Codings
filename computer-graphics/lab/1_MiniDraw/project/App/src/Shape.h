#pragma once

#include <QtGui>

class Shape {
public:
    Shape();
    virtual ~Shape();

public:
    virtual void Draw(QPainter& paint) = 0;
    void set_start(QPoint s);
    void set_end(QPoint e);

public:
    enum Type {
        kDefault,
        kLine,
        kRect,
        kEllipse,
        kPolygon,
        kFreeHand
    };

protected:
    QPoint start;
    QPoint end;
};