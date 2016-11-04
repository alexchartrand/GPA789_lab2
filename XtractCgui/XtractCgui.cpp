#include "XtractCgui.h"
#include "AboutTab.h"


#include <qstatusbar.h>


XtractCgui::XtractCgui(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	mDirectorySel = new QDirectorySelector();
	mSplitter = new QSplitter(Qt::Orientation::Horizontal);
	mTab = new QTabWidget();
	mCppCommenteViewer = new QCppCommentViewer();
	mQSelectedFileList = new QSelectedFileList(mDirectorySel);
	mQGenereFile = new QGenereFile();

	mCppCommenteViewer->setFileSuffixFilter(QStringList() << "cpp" << "c" << "hpp" << "h");

	mTab->addTab(mCppCommenteViewer, tr("Consulter le fichier source et ses commentaires"));
	mTab->addTab(mQGenereFile, tr("Générer les fichers de commentaire"));
	mTab->addTab(new AboutTab, tr("About"));
	
	mSplitter->addWidget(mDirectorySel);
	mSplitter->addWidget(mTab);

	setCentralWidget(mSplitter);

	connectWidget();

}

XtractCgui::~XtractCgui()
{

}

void XtractCgui::connectWidget()
{
	connect(mDirectorySel, &QDirectorySelector::fileSelected,
		mCppCommenteViewer, &QCppCommentViewer::setFile);

	connect(mCppCommenteViewer, &QCppCommentViewer::eventSignaled,
		statusBar(), &QStatusBar::showMessage);
}