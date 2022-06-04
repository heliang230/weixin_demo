#include "login.h"
#include "IconfontHelper.h"
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QPixmap>
#include <QPainter>
#include <QRect>
#include "mainhomewidget.h"

Login::Login(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    //在任务栏上不显示图标
    setWindowFlags(Qt::FramelessWindowHint);

    //外层窗口显示为透明
    setAttribute(Qt::WA_TranslucentBackground, true);


    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect;
    effect->setOffset(0, 0);
    effect->setColor(QColor(68, 68, 68,100));
    effect->setBlurRadius(10);
    ui.innerLoginBox->setGraphicsEffect(effect);


    QPixmap pix;
    pix.load(":/res/img/touxiang.png");
    


    QFont iconfont=IconfontHelper::getInstace()->getFont();

    this->ui.btnSetting->setFont(iconfont);
    this->ui.btnSetting->setText(QChar(0xe62a));


    this->ui.btnClose->setFont(iconfont);
    this->ui.btnClose->setText(QChar(0xeca0));

    this->ui.lbTuxiang->setScaledContents(true);
    this->ui.lbTuxiang->setPixmap(this->generatePixmap(pix, 20));

   
    connect(this->ui.btnLogin, &QPushButton::clicked, this, [&]() {
        MainHomeWidget* mhw = new MainHomeWidget();
        mhw->show();
        this->hide();
    });
    
    QIcon icon = QIcon(":/res/img/weixin.jpg");    //资源文件添加的图标
    this->setWindowIcon(icon);
}

Login::~Login()
{
}

void Login::mousePressEvent(QMouseEvent* event)
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

void Login::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bDrag)
    {
        //获得鼠标移动的距离
        QPoint distance = event->globalPos() - mouseStartPoint;
        //改变窗口的位置
        this->move(windowTopLeftPoint + distance);
    }
  
}

void Login::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
}

QPixmap Login::generatePixmap(const QPixmap& src, const int& radius)
{
    // 无效图片不处理
    if (src.isNull()) {
        return src;
    }

    // 压缩图片
    QPixmap pixmap = scaledPixmap(src, src.width(),src.height());

    QPixmap dest(src.width(), src.height());
    dest.fill(Qt::transparent);
    QPainter painter(&dest);
    // 抗锯齿 + 平滑边缘处理
    painter.setRenderHints(QPainter::Antialiasing, true);
    painter.setRenderHints(QPainter::SmoothPixmapTransform, true);
    // 裁剪为圆角
    QPainterPath path;
    path.addRoundedRect(0, 0, src.width(), src.height(), 10, 10);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, src.width(), src.height(), pixmap);

    return dest;
}

QPixmap Login::scaledPixmap(const QPixmap& src, int width, int height)
{
    return src.scaled(width, height,
        Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}
