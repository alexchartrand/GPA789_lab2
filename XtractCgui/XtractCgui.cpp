#include "XtractCgui.h"
#include "AboutTab.h"


#include <qstatusbar.h>


XtractCgui::XtractCgui(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Creation des variables
	mDirectorySel = new QDirectorySelector();
	mSplitter = new QSplitter(Qt::Orientation::Horizontal);
	mTab = new QTabWidget();
	mCppCommenteViewer = new QCppCommentViewer();
	mQSelectedFileList = new QSelectedFileList(mDirectorySel);
	mQGenereFile = new QGenereFile(mDirectorySel);

	//Restriction des fichiers acceptés
	mCppCommenteViewer->setFileSuffixFilter(QStringList() << "cpp" << "c" << "hpp" << "h");

	//Configuration d'affichage
	//Création et affichage des trois onglets
	mTab->addTab(mCppCommenteViewer, tr("Consulter le fichier source et ses commentaires"));
	mTab->addTab(mQGenereFile, tr("Générer les fichers de commentaire"));
	mTab->addTab(new AboutTab, tr("About"));
	//Affichage des widgets permanants
	mSplitter->addWidget(mDirectorySel);
	mSplitter->addWidget(mTab);
	setCentralWidget(mSplitter);
	//Integration de l'icône
	QIcon icon = QIcon("Resource/icon.png");
	setWindowIcon(icon);

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

	connect(mQGenereFile, &QGenereFile::eventSignaled,
		statusBar(), &QStatusBar::showMessage);
}