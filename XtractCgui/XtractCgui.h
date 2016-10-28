#ifndef XTRACTCGUI_H
#define XTRACTCGUI_H

#include <QtWidgets/QMainWindow>
#include <qsplitter.h>
#include <qtabwidget.h>

#include "ui_XtractCgui.h"
#include "QDirectorySelector.h"
#include "QCppCommentViewer.h"

class XtractCgui : public QMainWindow
{
	Q_OBJECT

public:
	XtractCgui(QWidget *parent = 0);
	~XtractCgui();

private:

	void connectWidget();
	Ui::XtractCguiClass ui;
	QSplitter *mSplitter;
	QDirectorySelector *mDirectorySel;
	QTabWidget *mTab;
	QCppCommentViewer *mCppCommenteViewer;
	
};

#endif // XTRACTCGUI_H
