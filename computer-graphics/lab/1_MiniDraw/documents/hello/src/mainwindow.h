#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QToolBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void CreateButtons();

private:
    Ui::MainWindow *ui;

private:
    QAction* hello_world_action_;
    QMenu* main_menu_;
    QToolBar* main_toolbar_;
    
private slots:
    void HelloWorld();
};

#endif // MAINWINDOW_H
