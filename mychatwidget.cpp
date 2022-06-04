#include "mychatwidget.h"
#include <QListWidgetItem>
#include "msgitemwidget.h"



MyChatWidget::MyChatWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->ui.listWidget->setFrameShape(QListWidget::NoFrame);

	

	connect(ui.chatButtomWidget, &ChatButtomWidget::addMsg, this, [this](QString &msg) {
		MsgItemWidget* msgItemWidget = new MsgItemWidget(nullptr,0,msg);
		QListWidgetItem* listWidgetItem = new QListWidgetItem(ui.listWidget);
		listWidgetItem->setSizeHint(msgItemWidget->size());
		this->ui.listWidget->addItem(listWidgetItem);
		this->ui.listWidget->setItemWidget(listWidgetItem, msgItemWidget);
	});
	

	connect(ui.chatButtomWidget, &ChatButtomWidget::addFile, this, [this](QString& fileName) {
		MsgItemWidget* msgItemWidget = new MsgItemWidget(nullptr,1, fileName);
		QListWidgetItem* listWidgetItem = new QListWidgetItem(ui.listWidget);
		listWidgetItem->setSizeHint(msgItemWidget->size());
		this->ui.listWidget->addItem(listWidgetItem);
		this->ui.listWidget->setItemWidget(listWidgetItem, msgItemWidget);
		});
	
}

MyChatWidget::~MyChatWidget()
{
}
