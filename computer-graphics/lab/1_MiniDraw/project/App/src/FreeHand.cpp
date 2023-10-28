#include "FreeHand.h"

#include <QDebug>

FreeHand::FreeHand() {

}

FreeHand::~FreeHand() {

}

void FreeHand::Draw(QPainter& painter) {
   painter.drawPolyline(QPolygon(m_points));
}

void FreeHand::AddPoint(QPoint point) {
    m_points.push_back(point);
}