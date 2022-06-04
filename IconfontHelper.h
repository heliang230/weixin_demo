#pragma once
#include <QFont>

class IconfontHelper
{
public:
	static IconfontHelper* getInstace();
	QFont getFont();
private:
	IconfontHelper();
	static IconfontHelper* self;
	void initIconFont();
	QFont iconFont;
};

