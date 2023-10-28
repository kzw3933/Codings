#include "viewwidget.h"
#include "Line.h"
#include "Rect.h"
#include "Ellipse.h"
#include "Polygon.h"
#include "FreeHand.h"
#include "Shape.h"


ViewWidget::ViewWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ViewWidget)
{
    ui->setupUi(this);
    draw_status_ = false;
    shape_ = nullptr;
    type_ = Shape::kDefault;
}

ViewWidget::~ViewWidget()
{
    delete ui;
}

void ViewWidget::setLine() {
    type_ = Shape::kLine;
}

void ViewWidget::setRect() {
    type_ = Shape::kRect;
}

void ViewWidget::setEllipse() {
    type_ = Shape::kEllipse;
}

void ViewWidget::setPolygon() {
    type_ = Shape::kPolygon;
}

void ViewWidget::setFreeHand() {
    type_ = Shape::kFreeHand;
}

void ViewWidget::mousePressEvent(QMouseEvent *event) {
    if(Qt::LeftButton == event->button()) {
        switch(type_) {
            case Shape::kLine:
                shape_ = new Line();
                break;
            case Shape::kRect:
                shape_ = new Rect();
                break;
            case Shape::kEllipse:
                shape_ = new Ellipse();
                break;
            case Shape::kPolygon: {
                    if(draw_status_) {
                        dynamic_cast<Polygon*>(shape_)->AddPoint(event->pos());
                    } else {
                        auto polygon_shape = new Polygon();
                        polygon_shape->AddPoint(event->pos());
                        shape_ = polygon_shape;
                    }
                }
                break;
            case Shape::kFreeHand: {
                    auto freehand_shape = new FreeHand();
                    freehand_shape->AddPoint(event->pos());
                    shape_ = freehand_shape;
                }
                break;
            default:
                break;
        }
        if(shape_ != nullptr) {
            draw_status_ = true;
            start_point_ = end_point_ = event->pos();
            shape_->set_start(start_point_);
            shape_->set_end(end_point_);
        }
    }
    update();
}

void ViewWidget::mouseMoveEvent(QMouseEvent *event) {
    if(draw_status_ && shape_!= nullptr) {
        if(dynamic_cast<Polygon*>(shape_))
            return;
        end_point_ = event->pos();
        shape_->set_end(end_point_);
        if(dynamic_cast<FreeHand*>(shape_))
            dynamic_cast<FreeHand*>(shape_)->AddPoint(end_point_);
    }
}

void ViewWidget::mouseReleaseEvent(QMouseEvent *event) {
    if(shape_ == nullptr)
        return;
    auto polygon_shape = dynamic_cast<Polygon*>(shape_);
    if(polygon_shape && !polygon_shape->Over()) 
        return;
    draw_status_ = false;
    shape_list_.push_back(shape_);
    shape_ = nullptr;
}

void ViewWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    for(int i = 0; i < shape_list_.size(); i++) {
        shape_list_[i]->Draw(painter);
    }
    if(shape_ != nullptr) {
        shape_->Draw(painter);
    }
    update();
}
 
