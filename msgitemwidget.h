#pragma once

#include <QWidget>
#include <QTextDocument>
#include <QTextBlock>
#include <QDebug>
#include <QResizeEvent>
#include <QTextEdit>
#include <QLabel>
#include <QPainter>


class MsgItemWidget : public QWidget
{
	Q_OBJECT

public:
	MsgItemWidget(QWidget *parent,qint16 type,QString &msg);
	~MsgItemWidget();
	

protected:
	void paintEvent(QPaintEvent* event)override;


private:
	QLabel* lbTouXiang;
	QTextEdit* txtMsg;
	qint16 type;
	QString data;
	QLabel* lbImg;
	//��Ϣ
	void initType0();
	//ͼƬ
	void initType1();

};
