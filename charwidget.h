#pragma once

#include <QWidget>
#include "ui_charwidget.h"
#include <QMouseEvent>

class CharWidget : public QWidget
{
	Q_OBJECT

public:
	CharWidget(QWidget *parent = Q_NULLPTR);
	~CharWidget();



private:
	Ui::CharWidget ui;
};
