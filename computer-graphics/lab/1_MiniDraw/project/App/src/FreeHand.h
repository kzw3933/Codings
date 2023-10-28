#pragma once

#include <QVector>

#include "Shape.h"

class FreeHand: public Shape {
public:
    FreeHand();
    ~FreeHand();

public:
    void Draw(QPainter& painter);
    void AddPoint(QPoint point);

private:
    QVector<QPoint> m_points;
};