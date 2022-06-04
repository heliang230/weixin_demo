#pragma once

#include <QWidget>
#include "ui_chatbuttomwidget.h"


class ChatButtomWidget : public QWidget
{
	Q_OBJECT

public:
	ChatButtomWidget(QWidget *parent = Q_NULLPTR);
	~ChatButtomWidget();
signals:
	void addMsg(QString& msg);
	void addFile(QString& filename);

protected:
	void paintEvent(QPaintEvent* event)override;
private:
	Ui::ChatButtomWidget ui;
};
