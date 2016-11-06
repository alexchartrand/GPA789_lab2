#include "QGenereFile.h"
#include "QSelectedFileList.h"
#include "QNomFichierSortie.h"

#include <qgridlayout.h>
#include <qlayout.h>
#include <qradiobutton.h>
#include <qcheckbox>
#include <qpushbutton>
#include <qlabel>
#include <qspinbox>
#include <qmessagebox>


QGenereFile::QGenereFile(QWidget *parent)
{

	mDirectorySel = new QDirectorySelector();

	mQSelectedFileList = new QSelectedFileList(mDirectorySel);
	mQSelectedFileList->setFileSuffixFilter(QStringList() << "cpp" << "c" << "hpp" << "h");

	QHBoxLayout *hbox1 = new QHBoxLayout;
	QHBoxLayout *hbox2 = new QHBoxLayout;
	QVBoxLayout *vbox = new QVBoxLayout;

	mDossierSortie = new QDossierSortie;
	mExtensionFichier = new QExtentionFichier;
	mNomFichierSortie = new QNomFichierSortie;

	QCheckBox *checkBox1 = new QCheckBox(tr("Inclure les statistiques"));
	QPushButton *pushButton = new QPushButton("&Générer", this);

	connect(pushButton, &QPushButton::clicked,
		this, &QGenereFile::Appelparametre);

	hbox1->addWidget(mQSelectedFileList);
	hbox1->addLayout(vbox);

	vbox->addWidget(mDossierSortie);
	vbox->addStretch();
	vbox->addWidget(mNomFichierSortie);
	vbox->addStretch();
	vbox->addWidget(mExtensionFichier);
	vbox->addLayout(hbox2);

	hbox2->addWidget(checkBox1);
	hbox2->addWidget(pushButton);

	setLayout(hbox1);

}

void QGenereFile::Appelparametre()
{
	

	QString prefixe = mNomFichierSortie->getNomFichier();
	int deb_num = mNomFichierSortie->getDebutNumerotation();
	QString extension = mExtensionFichier->extentionFiles();



	QMessageBox Reponse;
	Reponse.setText(prefixe);
	Reponse.setText(QString::number(deb_num));
	Reponse.setInformativeText(extension);
	Reponse.exec();

}