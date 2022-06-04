#include "IconfontHelper.h"
#include <QMutex>
#include <QMutexLocker>
#include <QFontDatabase>
#include <QDebug>

IconfontHelper *IconfontHelper::self=0;



IconfontHelper::IconfontHelper() {
	this->initIconFont();
}

void IconfontHelper::initIconFont()
{
	QFontDatabase fontdb;
    if (!fontdb.families().contains("iconfont")) {
        int fontId = fontdb.addApplicationFont(":/res/iconfont/iconfont.ttf");
        QStringList fontName = fontdb.applicationFontFamilies(fontId);
        if (fontName.count() == 0) {
            qDebug() << "load iconfont.ttf error";
        }
    }
    if (fontdb.families().contains("iconfont")) {
        iconFont = QFont("iconfont");
        iconFont.setHintingPreference(QFont::PreferNoHinting);
    }
 
}

IconfontHelper* IconfontHelper::getInstace()
{
	static QMutex mutex;
	QMutexLocker muxLocke(&mutex);
	if (self == NULL || self == nullptr) {
		IconfontHelper::self=new IconfontHelper();
	}
	return IconfontHelper::self;
}

QFont IconfontHelper::getFont()
{
    return this->iconFont;
}
