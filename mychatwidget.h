#pragma once

#include <QWidget>
#include "ui_mychatwidget.h"

class MyChatWidget : public QWidget
{
	Q_OBJECT

public:
	MyChatWidget(QWidget *parent = Q_NULLPTR);
	~MyChatWidget();

private:
	Ui::MyChatWidget ui;
};
