#pragma once

#include <QWidget>
#include "ui_navsystemwidget.h"

class NavSystemWidget : public QWidget
{
	Q_OBJECT

public:
	NavSystemWidget(QWidget *parent = Q_NULLPTR);
	~NavSystemWidget();
signals:
	void widgetChange(bool flag);

private:
	Ui::NavSystemWidget ui;
};
