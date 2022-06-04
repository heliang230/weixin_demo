#include "firedlistitem.h"

FiredListItem::FiredListItem(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->ui.lbTuxiang->setPixmap(QPixmap(":/res/img/touxiang.png"));
	
}

FiredListItem::~FiredListItem()
{
}

void FiredListItem::setIndexItem(int index)
{
	this->ui.lbTitle->setText(this->ui.lbTitle->text()+QString("%1").arg(index));
}
