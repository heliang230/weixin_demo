#pragma once

#include <QWidget>
#include "ui_login.h"

class Login : public QWidget
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);
	~Login();
protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);


private:
	Ui::Login ui;
	bool m_bDrag = false;
	QPoint mouseStartPoint;
	QPoint windowTopLeftPoint;
	QPixmap generatePixmap(const QPixmap& src, const int& radius);
	QPixmap scaledPixmap(const QPixmap& src, int width, int height);

};
