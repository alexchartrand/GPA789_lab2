#include "XtractCgui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	XtractCgui w;
	//Test
	w.show();
	return a.exec();
}
