#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>

#include "./ui_viewwidget.h"
#include "Shape.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ViewWidget; }
QT_END_NAMESPACE

class ViewWidget : public QWidget
{
    Q_OBJECT

public:
    ViewWidget(QWidget *parent = nullptr);
    ~ViewWidget();

private:
    Ui::ViewWidget *ui;

public:
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent * event);

private:
    bool draw_status_;
    QPoint start_point_;
    QPoint end_point_;
    Shape::Type type_;
    Shape* shape_;
    std::vector<Shape*> shape_list_;

signals:
public slots:
    void setLine();
    void setRect();
    void setEllipse();
    void setPolygon();
    void setFreeHand();
};
#endif // VIEWWIDGET_H
