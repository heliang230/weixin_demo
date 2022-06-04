#pragma once

#include <QWidget>
#include "ui_firedlistitem.h"


class FiredListItem : public QWidget
{
	Q_OBJECT

public:
	FiredListItem(QWidget *parent = Q_NULLPTR);
	~FiredListItem();
	void setIndexItem(int index);

private:
	Ui::FiredListItem ui;
};
