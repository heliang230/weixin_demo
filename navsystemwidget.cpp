#include "navsystemwidget.h"
#include "IconfontHelper.h"

NavSystemWidget::NavSystemWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    ///Í·ÎÄ¼þ
    QFont headerIconfont = IconfontHelper::getInstace()->getFont();
    headerIconfont.setPixelSize(15);
    this->ui.btnFiexd->setFont(headerIconfont);
    this->ui.btnFiexd->setText(QChar(0xe9ba));

    this->ui.btnMinOK->setFont(headerIconfont);
    this->ui.btnMinOK->setText(QChar(0xe624));


    this->ui.btnMax->setFont(headerIconfont);
    this->ui.btnMax->setText(QChar(0xe66b));


    this->ui.btnClose->setFont(headerIconfont);
    this->ui.btnClose->setText(QChar(0xeca0));

    connect(this->ui.btnMax, &QPushButton::clicked, this, [this]() {
        if (!this->window()->isMaximized()) {

            emit this->widgetChange(true);
            this->window()->showMaximized();
            

        }
        else {

            emit this->widgetChange(false);
            this->window()->showNormal();

        }

        });

    connect(this->ui.btnMinOK, &QPushButton::clicked, this, [this]() {
        this->window()->showMinimized();

        });

    connect(this->ui.btnClose, &QPushButton::clicked, this, [this]() {
        this->window()->close();
        //this->window()->hide();
    });
}

NavSystemWidget::~NavSystemWidget()
{
}
