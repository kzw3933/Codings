#pragma once

#include "Shape.h"

class Rect: public Shape {
public:
    Rect();
    ~Rect();

public:
    void Draw(QPainter& painter);
};