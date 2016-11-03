#include "QGenereFile.h"
#include "qgridlayout.h"
#include "qradiobutton.h"
#include "qcheckbox.h"
#include "qpushbutton.h"
#include <qlabel>
#include "QSelectedFileList.h"
#include <qspinbox>


QGenereFile::QGenereFile(QWidget *parent)
{

	mDirectorySel = new QDirectorySelector();

	mQSelectedFileList = new QSelectedFileList(mDirectorySel);
	QHBoxLayout *hbox = new QHBoxLayout;
	QVBoxLayout *vbox = new QVBoxLayout;

	hbox->addWidget(mQSelectedFileList);
	hbox->addLayout(vbox);

	vbox->addWidget(createFirstExclusiveGroup());
	vbox->addWidget(createSecondExclusiveGroup());
	vbox->addWidget(createNonExclusiveGroup());


	QCheckBox *checkBox1 = new QCheckBox(tr("Inclure les statistiques"));
	vbox->addWidget(checkBox1);
	QPushButton *pushButton = new QPushButton("&Générer",this);
	vbox->addWidget(pushButton);
	setLayout(hbox);

}

QGroupBox *QGenereFile::createFirstExclusiveGroup()
{

	QGroupBox *groupBox = new QGroupBox(tr("Dossiers de sortie"));
	mFichierSortie1 = new QRadioButton(tr("Utiliser le dossier source"));
	QRadioButton *fichier_sortie2 = new QRadioButton(tr("Spécifier un dossier de sortie"));
	QLabel *path = new QLabel(this);
	path->setText("Chemin");
	QPushButton *selectionner = new QPushButton("&Sélectionner", this);
	QVBoxLayout *vbox = new QVBoxLayout;
	QHBoxLayout *hbox = new QHBoxLayout;
	hbox->addWidget(fichier_sortie2);
	hbox->addWidget(selectionner);
	vbox->addWidget(mFichierSortie1);
	vbox->addLayout(hbox);
	vbox->addWidget(path);
	groupBox->setLayout(vbox);

	return groupBox;
}

QGroupBox *QGenereFile::createSecondExclusiveGroup()
{

	QGroupBox *groupBox = new QGroupBox(tr("Nom du fichier de sortie"));
	QRadioButton *nom_fichier_sortie1 = new QRadioButton(tr("Utiliser le même nom de fichier"));
	QRadioButton *nom_fichier_sortie2 = new QRadioButton(tr("Utiliser un nom de fichier avec numérotation automatique"));
	QVBoxLayout *vbox = new QVBoxLayout;
	vbox->addWidget(nom_fichier_sortie1);
	vbox->addWidget(nom_fichier_sortie2);
	groupBox->setLayout(vbox);

	return groupBox;

}

QGroupBox *QGenereFile::createNonExclusiveGroup()
{

	QGroupBox *groupBox = new QGroupBox(tr("Extension du fichier de sortie"));
	QRadioButton *extension_fichier1 = new QRadioButton(tr("Utiliser l'extension XtractC"));
	QRadioButton *extension_fichier2 = new QRadioButton(tr("Spécifier l'extension"));
	QVBoxLayout *vbox = new QVBoxLayout;
	vbox->addWidget(extension_fichier1);
	vbox->addWidget(extension_fichier2);
	groupBox->setLayout(vbox);

	return groupBox;

}