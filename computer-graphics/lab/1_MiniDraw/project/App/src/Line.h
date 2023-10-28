#pragma once

#include "Shape.h"

class Line: public Shape {
public:
    Line();
    ~Line();

public:
    void Draw(QPainter& painter);
    void set_last(QPoint point);
};