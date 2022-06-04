#include "chatbuttomwidget.h"
#include <QPainter>
#include <QFileDialog>
#include "IconfontHelper.h"


ChatButtomWidget::ChatButtomWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QFont iconfont=IconfontHelper::getInstace()->getFont();
	iconfont.setPixelSize(18);
	ui.btnBiaoqing->setFont(iconfont);
	ui.btnBiaoqing->setText(QChar(0xec80));

	ui.btnFile->setFont(iconfont);
	ui.btnFile->setText(QChar(0xec17));


	ui.btnCut->setFont(iconfont);
	ui.btnCut->setText(QChar(0xede2));

	ui.btnChat->setFont(iconfont);
	ui.btnChat->setText(QChar(0xec80));

	ui.btnBiaoqing->setFont(iconfont);
	ui.btnBiaoqing->setText(QChar(0xe665));


	ui.btnAudio->setFont(iconfont);
	ui.btnAudio->setText(QChar(0xe61b));


	ui.btnVideo->setFont(iconfont);
	ui.btnVideo->setText(QChar(0xe63b));

	connect(ui.btnSend, &QPushButton::clicked, this, [&]() {
		QString msg=ui.txtContent->toPlainText();
		if (msg.isEmpty() || msg.isNull()) {
			return;
		}
		emit this->addMsg(msg);
	});

	connect(ui.btnFile, &QPushButton::clicked, this, [&]() {
		 QString fileName=QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("ͼƬѡȡ"), QDir::currentPath(), QString::fromLocal8Bit("ͼƬ(*jpg)"));
		 if (fileName.isNull() && fileName.isEmpty()) {
			 return;
		 }

		 emit this->addFile(fileName);

	});
}

ChatButtomWidget::~ChatButtomWidget()
{
}

void ChatButtomWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QPen m_pen;
	m_pen.setColor(QColor("#ECECEC"));
	painter.setPen(m_pen);
	painter.drawLine(QLine(0, 0, this->width(),0));
	
}
