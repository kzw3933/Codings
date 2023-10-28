#ifndef MINIDRAW_H
#define MINIDRAW_H

#include <QMainWindow>
#include <QToolBar>
#include <QMenu>

#include "./ui_minidraw.h"
#include "viewwidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MiniDraw; }
QT_END_NAMESPACE

class MiniDraw : public QMainWindow
{
    Q_OBJECT

public:
    MiniDraw(QWidget *parent = nullptr);
    ~MiniDraw();

public:
    void Creat_Menu();
    void Creat_ToolBar();
    void Creat_Action();
    void AboutBox();

private:
    Ui::MiniDraw *ui;

private:
    ViewWidget* view_widget_;
    QMenu* pMenu;
    QToolBar* pToolBar;
    QAction* Action_About;
    QAction* Action_Line;
    QAction* Action_Rect;
    QAction* Action_Ellipse;
    QAction* Action_Polygon;
    QAction* Action_FreeHand;
};
#endif // MINIDRAW_H
