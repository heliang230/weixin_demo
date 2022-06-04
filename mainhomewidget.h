#pragma once

#include <QWidget>
#include "ui_mainhomewidget.h"
#include "navsystemwidget.h"
#include <QSystemTrayIcon>

class MainHomeWidget : public QWidget
{
	Q_OBJECT

public:
	MainHomeWidget(QWidget *parent = Q_NULLPTR);
	~MainHomeWidget();
protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void resizeEvent(QResizeEvent* event) override;
private:
	Ui::MainHomeWidget ui;
	bool m_bDrag = false;
	QPoint mouseStartPoint;
	QPoint windowTopLeftPoint;
	NavSystemWidget* navSystemWidget;
	QSystemTrayIcon* m_sysTrayIcon; //œµÕ≥Õ–≈Ã

};
