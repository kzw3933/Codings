#pragma once

#include <QVector>

#include "Shape.h"

class Polygon: public Shape {
public:
    Polygon();
    ~Polygon();

public:
    void Draw(QPainter& painter);
    void AddPoint(QPoint point);
    bool Over();

private:
    QVector<QPoint> m_points;
};