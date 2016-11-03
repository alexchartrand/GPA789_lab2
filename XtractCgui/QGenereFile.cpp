#include "QGenereFile.h"
#include "qgridlayout.h"
#include "qradiobutton.h"
#include "qcheckbox.h"
#include "qpushbutton.h"
#include "qlabel.h"
#include "QSelectedFileList.h"


QGenereFile::QGenereFile(QWidget *parent)
{

	//mQSelectedFileList = new QSelectedFileList();
	QGridLayout *grid = new QGridLayout;

	//grid->addWidget(mQSelectedFileList, 0, 0);
	grid->addWidget(createFirstExclusiveGroup(), 0, 1);
	grid->addWidget(createSecondExclusiveGroup(), 1, 1);
	grid->addWidget(createNonExclusiveGroup(), 2, 1);


	QCheckBox *checkBox1 = new QCheckBox(tr("Inclure les statistique"));
	grid->addWidget(checkBox1, 3, 1);
	QPushButton *pushButton = new QPushButton("&Générer",this);
	grid->addWidget(pushButton, 3, 2);
	setLayout(grid);

}

QGroupBox *QGenereFile::createFirstExclusiveGroup()
{

	QGroupBox *groupBox = new QGroupBox(tr("Dossiers de sortie"));
	QRadioButton *fichier_sortie1 = new QRadioButton(tr("Utiliser le dossier source"));
	QRadioButton *fichier_sortie2 = new QRadioButton(tr("Spécifier un dossier de sortie"));
	QLabel *path = new QLabel(this);
	path->setText("Chemin");
	QPushButton *selectionner = new QPushButton("&Sélectionner", this);
	QVBoxLayout *vbox = new QVBoxLayout;
	vbox->addWidget(fichier_sortie1);
	vbox->addWidget(fichier_sortie2);
	vbox->addWidget(path);
	vbox->addWidget(selectionner, 0, 1);
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