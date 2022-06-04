#include "msgitemwidget.h"



MsgItemWidget::MsgItemWidget(QWidget *parent, qint16 type, QString& msg)
	: QWidget(parent)
{

	
	this->type = type;
	this->data = msg;
	if (type == 0) 
	{
		this->initType0();
	}
	else if (type == 1) 
	{
		this->initType1();
	}


	
}

MsgItemWidget::~MsgItemWidget()
{

}

void MsgItemWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);//Ïû¾â³Ý
	painter.setPen(QColor(137,217, 97,220));
	painter.setBrush(QColor(137, 217, 97, 220));

	QRect oldRect;
	QPoint oldPoint;
	if (this->type == 0) 
	{
		 oldRect = this->txtMsg->rect();
		 oldPoint = this->txtMsg->pos();
	}
	else if (this->type == 1) 
	{
		oldRect = this->lbImg->rect();
		oldPoint = this->lbImg->pos();
	}
	

	QRect newRect(oldPoint.x() - 5, oldPoint.y() - 5, oldRect.width() + 10, oldRect.height() + 10);
	
	
	QPainterPath lp;
	lp.moveTo(newRect.topLeft()); //p0
	lp.lineTo(newRect.topRight()); //p1
	lp.lineTo(newRect.bottomRight()); //p2
	lp.lineTo(newRect.bottomLeft()); //p3
	lp.lineTo(newRect.topLeft().x(), newRect.topLeft().y()+15); //p4
	lp.lineTo(newRect.topLeft().x()-7, newRect.topLeft().y() + 8); //p5
	lp.lineTo(newRect.topLeft().x(), newRect.topLeft().y() + 6); //p6
	lp.lineTo(newRect.topLeft()); //p0
	painter.drawPath(lp);
	painter.end();
}

void MsgItemWidget::initType0()
{
	lbTouXiang = new QLabel(this);
	lbTouXiang->setPixmap(QPixmap(":/res/img/touxiang.png"));
	lbTouXiang->setScaledContents(true);
	lbTouXiang->setGeometry(QRect(10, 5, 40, 40));

	txtMsg = new QTextEdit(this);
	txtMsg->setStyleSheet("background-color:rgba(0,0,0,0); border:0px;");
	txtMsg->setGeometry(70, 15, 400, 50);
	txtMsg->setText(this->data);
	txtMsg->setAttribute(Qt::WA_TranslucentBackground);
	txtMsg->setContextMenuPolicy(Qt::NoContextMenu);



	QTextDocument* doc = txtMsg->document();
	doc->setTextWidth(400);
	doc->adjustSize();

	int newHeight = doc->size().height();
	txtMsg->setFixedHeight(newHeight);

	if (newHeight < 70)
	{
		newHeight = 70;
	}
	else {
		newHeight = newHeight + 20;
	}
	this->setFixedHeight(newHeight);
	this->setFixedWidth(560);
}

void MsgItemWidget::initType1()
{
	QPixmap image(this->data);
	
	if (image.size().width() > 200 || image.size().height() > 200)
	{
		image=image.scaled(200, 200);

	}


	lbTouXiang = new QLabel(this);
	lbTouXiang->setPixmap(QPixmap(":/res/img/touxiang.png"));
	lbTouXiang->setScaledContents(true);
	lbTouXiang->setGeometry(QRect(10, 5, 40, 40));

	lbImg = new QLabel(this);
	lbImg->setStyleSheet("background-color:rgba(0,0,0,0); border:0px;");
	lbImg->setGeometry(70, 15, 200, 200);
	lbImg->setText(this->data);
	lbImg->setAttribute(Qt::WA_TranslucentBackground);
	lbImg->setContextMenuPolicy(Qt::NoContextMenu);
	lbImg->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	lbImg->setPixmap(image);

	
	
	int newHeight = lbImg->height() + 20;
	this->setFixedHeight(newHeight);
	this->setFixedWidth(560);


}




