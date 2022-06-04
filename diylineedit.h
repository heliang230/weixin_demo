#pragma once

#include <QObject>
#include <QLineEdit>
#include <QWidget>
#include <QMouseEvent>

class DiyLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	DiyLineEdit(QWidget *parent=nullptr);
	~DiyLineEdit();
protected:
	void mouseMoveEvent(QMouseEvent* e) override;

};
