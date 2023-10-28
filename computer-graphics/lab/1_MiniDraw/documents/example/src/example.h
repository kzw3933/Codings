#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <QMainWindow>

#include "ui_example.h"

QT_BEGIN_NAMESPACE
namespace Ui { class example; }
QT_END_NAMESPACE

class example : public QMainWindow
{
	Q_OBJECT
	
public:
	example(QWidget *parent = 0);
	~example();

private:
	Ui::example* ui;

public:
	QMenu *pMenutest;
	QAction *pAction;
	QToolBar *main_toolbar_;

private slots:
	void hello();
};

#endif // EXAMPLE_H
