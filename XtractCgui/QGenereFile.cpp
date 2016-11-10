#include "QGenereFile.h"
#include "QSelectedFileList.h"
#include "QNomFichierSortie.h"
#include "XtractC.h"
#include "QCppCommentViewer.h"

#include <qgridlayout.h>
#include <qlayout.h>
#include <qradiobutton.h>
#include <qcheckbox>
#include <qpushbutton>
#include <qlabel>
#include <qspinbox>
#include <qmessagebox>

#include <sstream>


QGenereFile::QGenereFile(QDirectorySelector *DirectorySel,QWidget *parent)
{

	mDirectorySel = DirectorySel;

	mQSelectedFileList = new QSelectedFileList(mDirectorySel);
	mQSelectedFileList->setFileSuffixFilter(QStringList() << "cpp" << "c" << "hpp" << "h");

	QHBoxLayout *hbox1 = new QHBoxLayout;
	QHBoxLayout *hbox2 = new QHBoxLayout;
	QVBoxLayout *vbox = new QVBoxLayout;

	mDossierSortie = new QDossierSortie;
	mExtensionFichier = new QExtentionFichier;
	mNomFichierSortie = new QNomFichierSortie;

	mDisplayStatistics = new QCheckBox(tr("Inclure les statistiques"));
	QPushButton *pushButton = new QPushButton("Générer", this);

	connect(pushButton, &QPushButton::clicked,
		this, &QGenereFile::Appelparametre);

	hbox1->addWidget(mQSelectedFileList);
	hbox1->addLayout(vbox);
	vbox->addWidget(mDossierSortie);
	vbox->addWidget(mNomFichierSortie);
	vbox->addWidget(mExtensionFichier);
	vbox->addStretch();


	vbox->addLayout(hbox2);
	

	hbox2->addWidget(mDisplayStatistics);
	hbox2->addWidget(pushButton);

	setLayout(hbox1);

}

void QGenereFile::Appelparametre()
{
	// On va aller chercher les configuration dans chacun des QGroupBox
	std::string prefixe = mNomFichierSortie->getNomFichier().toStdString();
	int numberOfFile = mQSelectedFileList->selectedFilesCount();
	int deb_num = mNomFichierSortie->getDebutNumerotation();
	bool addNumbering = false;
	std::string extension = mExtensionFichier->extentionFiles().toStdString();
	std::string path = mDossierSortie->getDirectory().toStdString();
	QStringList fichierSource = mQSelectedFileList->selectedFiles();
	

	// Permet la sortie du document en fonction des configurations precedentes
	for (int i = 0; i < fichierSource.size(); i++){
		// On viens ajouter à notre fichier de sortie l'extention désiré
		std::string outputName;
		std::string fileName(fichierSource.value(i).toStdString());
		std::size_t indexOfDot = fileName.rfind(".");
		//Vérification que le "." ai été trouvé
		indexOfDot = indexOfDot == string::npos ? fileName.size() : indexOfDot;

		std::size_t indexOfDash = fileName.rfind("/");
		//Vérification que le "/" ai été trouvé
		indexOfDash = indexOfDash == string::npos ? 0 : indexOfDash;

		if (path.empty()){
			path = fileName.substr(0, indexOfDash);
		}

		if (!prefixe.empty()){
			indexOfDot = indexOfDash+1;
			addNumbering = true;
		}

		outputName += path + fileName.substr(indexOfDash, indexOfDot - indexOfDash) + prefixe + (addNumbering ? std::to_string(deb_num + i) : "") + extension;

		try {
			mXtractC.setup(fichierSource.at(i).toStdString(), outputName);
			mXtractC.process(mDisplayStatistics->isChecked());
		}
		catch (XtractC::ParamException const & exception)
	{
			emit eventSignaled("XtractC exception caught : " + QString::fromStdString(exception.what()));
		}
		catch (XtractC::Exception const & exception) {
			emit eventSignaled("XtractC exception caught : " + QString::fromStdString(exception.what()));
		}
		catch (exception const & exception) {
			emit eventSignaled("XtractC exception caught : " + QString::fromStdString(exception.what()));
		}
	}

	emit eventSignaled("File Created");

}