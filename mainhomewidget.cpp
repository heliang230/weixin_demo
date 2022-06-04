#include "mainhomewidget.h"
#include "IconfontHelper.h"
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QButtonGroup>
#include "charwidget.h"
#include <QResizeEvent>
#include <QMenu>
#include <QMessageBox>
#include "firedlistitem.h"

MainHomeWidget::MainHomeWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//在任务栏上不显示图标
	setWindowFlags(Qt::FramelessWindowHint );

	//外层窗口显示为透明
	setAttribute(Qt::WA_TranslucentBackground, true);


	QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect;
	effect->setOffset(0, 0);
	effect->setColor(QColor(68, 68, 68, 100));
	effect->setBlurRadius(10);

	ui.innerWidget->setGraphicsEffect(effect);

    QFont iconfont=IconfontHelper::getInstace()->getFont();
    iconfont.setPixelSize(20);
    ui.btnChat->setFont(iconfont);
    ui.btnChat->setText(QChar(0xe603));
  

    ui.btnContacts->setFont(iconfont);
    ui.btnContacts->setText(QChar(0xe654));

    ui.btnFavorite->setFont(iconfont);
    ui.btnFavorite->setText(QChar(0xe604));

    ui.btnFile->setFont(iconfont);
    ui.btnFile->setText(QChar(0xec17));


    ui.btnFriend->setFont(iconfont);
    ui.btnFriend->setText(QChar(0xe631));

    ui.btnVideo->setFont(iconfont);
    ui.btnVideo->setText(QChar(0xeb81));

    ui.btnSee->setFont(iconfont);
    ui.btnSee->setText(QChar(0xe8bf));

    ui.btnSearch->setFont(iconfont);
    ui.btnSearch->setText(QChar(0xe600));

    ui.btnPrograme->setFont(iconfont);
    ui.btnPrograme->setText(QChar(0xe619));

    ui.btnMobile->setFont(iconfont);
    ui.btnMobile->setText(QChar(0xe692));

    ui.btnMore->setFont(iconfont);
    ui.btnMore->setText(QChar(0xe612));

    ui.lbTuXiang->setPixmap(QPixmap(":/res/img/touxiang.png"));
    ui.lbTuXiang->setScaledContents(true);

    QButtonGroup* btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui.btnChat);
    btnGroup->addButton(ui.btnContacts);
    btnGroup->addButton(ui.btnFavorite);
    btnGroup->addButton(ui.btnFile);
    btnGroup->addButton(ui.btnFriend);
    btnGroup->addButton(ui.btnVideo);
    btnGroup->addButton(ui.btnSee);
    btnGroup->addButton(ui.btnSearch);
    btnGroup->addButton(ui.btnPrograme);
    btnGroup->addButton(ui.btnMobile);
    btnGroup->addButton(ui.btnMore);


    

  

   
    navSystemWidget = new NavSystemWidget();
    navSystemWidget->setParent(this);
    navSystemWidget->setGeometry(this->width()-140, 0, 140, 50);
   

    connect(navSystemWidget, &NavSystemWidget::widgetChange, this, [this](bool flag) {
        if (flag) 
        {
            this->ui.horizontalLayout->setContentsMargins(0, 0, 0, 0);
        }else
        {
            this->ui.horizontalLayout->setSpacing(6);
            this->ui.horizontalLayout->setContentsMargins(11, 11, 11, 11);
        }
     });
 

    //新建QSystemTrayIcon对象
    m_sysTrayIcon = new QSystemTrayIcon(this);

    //设置托盘图标
    QIcon icon = QIcon(":/res/img/weixin.jpg");    //资源文件添加的图标
    m_sysTrayIcon->setIcon(icon);

    this->setWindowIcon(icon);
    //当鼠标移动到托盘上的图标时，会显示此处设置的内容
    m_sysTrayIcon->setToolTip(QString::fromLocal8Bit("自定义微信"));


    //给QSystemTrayIcon添加槽函数
    connect(m_sysTrayIcon, &QSystemTrayIcon::activated,
        [=](QSystemTrayIcon::ActivationReason reason)
        {
            switch (reason)
            {
            case QSystemTrayIcon::Trigger:
                //单击托盘图标
                this->show();
                break;
            case QSystemTrayIcon::DoubleClick:
                    //双击托盘图标
                this->show();
                break;
            default:
                break;
            }
        });


       QMenu* men = new QMenu();
       men->setStyleSheet("background:#fff;color:#666;");
       QAction *acShow=men->addAction(QString::fromLocal8Bit("显示"));
       QAction* acHidden= men->addAction(QString::fromLocal8Bit("隐藏"));
       QAction* acExit= men->addAction(QString::fromLocal8Bit("退出"));

       connect(acShow, &QAction::triggered, this, [this]() {
           this->show();
       });

       connect(acHidden, &QAction::triggered, this, [this]() {
           this->hide();
       });

       connect(acExit, &QAction::triggered, this, [this]() {
           this->close();
       });
       m_sysTrayIcon->setContextMenu(men);
       //在系统托盘显示此对象
       m_sysTrayIcon->show();


       CharWidget* charWidget = new CharWidget();
       this->ui.skWidget->addWidget(charWidget);
       this->ui.skWidget->setCurrentIndex(0);


     
       

}



void MainHomeWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_bDrag = true;
        //获得鼠标的初始位置
        mouseStartPoint = event->globalPos();

        //获得窗口的初始位置
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }

}

void MainHomeWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bDrag)
    {
        //获得鼠标移动的距离
        QPoint distance = event->globalPos() - mouseStartPoint;
        //改变窗口的位置
        this->move(windowTopLeftPoint + distance);
    }

}

void MainHomeWidget::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
}

void MainHomeWidget::resizeEvent(QResizeEvent* event)
{
    navSystemWidget->setGeometry(this->width() - 140, 0, 140, 50);
}


MainHomeWidget::~MainHomeWidget()
{

 
}
