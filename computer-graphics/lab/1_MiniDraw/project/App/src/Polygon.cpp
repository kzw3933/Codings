#include "Polygon.h"

#include <QDebug>

Polygon::Polygon() {

}

Polygon::~Polygon() {

}

void Polygon::Draw(QPainter& painter) {
   painter.drawPolyline(QPolygon(m_points));
}

void Polygon::AddPoint(QPoint point) {
    m_points.push_back(point);
    qDebug() << m_points;
}

bool Polygon::Over() {
    if(m_points.size() < 2)
        return false;
    auto first = m_points.front();
    auto last = m_points.back();
    auto dx = first.x() - last.x();
    auto dy = first.y() - last.y();
    return dx * dx + dy * dy < 20;
}