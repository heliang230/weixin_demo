#include "charwidget.h"
#include "IconfontHelper.h"
#include <QMouseEvent>
#include <QDebug>
#include <QAction>
#include <QLabel>
#include "firedlistitem.h"


CharWidget::CharWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QFont iconfont=IconfontHelper::getInstace()->getFont();
	iconfont.setPixelSize(15);
	ui.btnSearch->setFont(iconfont);
	ui.btnSearch->setText(QChar(0xe889));


	//½«×ÖÌå×ªÍ¼Æ¬
	QLabel* lbImg = new QLabel();
	lbImg->setAttribute(Qt::WA_TranslucentBackground, true);//ÉèÖÃ±³¾°Í¸Ã÷
	lbImg->setText(QChar(0xe651));
	lbImg->resize(30,30);
	lbImg->setFont(iconfont);
	QPixmap pixmap(lbImg->size());
	pixmap.fill(Qt::transparent);//ÉèÖÃpixmap±³¾°Í¸Ã÷
	lbImg->render(&pixmap);
	

	QAction* pLeadingAction = new QAction(this);
	pLeadingAction->setIcon(QIcon(pixmap));

	ui.lineEdit->addAction(pLeadingAction, QLineEdit::LeadingPosition);
	ui.lineEdit->setPlaceholderText(QString::fromLocal8Bit("ËÑË÷"));
	ui.lineEdit->setFocusPolicy(Qt::ClickFocus);
	ui.lineEdit->setEnabled(true);
	ui.lineEdit->setFocus();
	ui.firedListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
	for (int i = 0; i < 50; i++) 
	{
		FiredListItem* item = new FiredListItem();
		QListWidgetItem* lwi = new QListWidgetItem();
		int width = item->width();
		int height = item->height();
		item->setIndexItem(i);
		lwi->setSizeHint(QSize(width, height));
		ui.firedListWidget->addItem(lwi);
		ui.firedListWidget->setItemWidget(lwi, item);
	}
	
	ui.firedListWidget->setCurrentRow(0);
}




CharWidget::~CharWidget()
{
}



