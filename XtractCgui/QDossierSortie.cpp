#include "QDossierSortie.h"

#include <qlabel>
#include <qpushbutton>
#include <qradiobutton.h>
#include <qlayout.h>
#include <QFileDialog>
#include <qdir>

//Groupe pour la gestion de la configuration du dossier de sortie de production
//de notre fichier final
QDossierSortie::QDossierSortie(QWidget *parent)
: QGroupBox(tr("Dossiers de sortie"), parent), mDir("")
{

	QRadioButton *fichierSortie1 = new QRadioButton(tr("Utiliser le dossier source"));
	QRadioButton *fichierSortie2 = new QRadioButton(tr("Spécifier un dossier de sortie"));
	QLabel *path = new QLabel(this);
	QPushButton *selectionner = new QPushButton("&Sélectionner", this);
	QVBoxLayout *vbox = new QVBoxLayout;
	QHBoxLayout *hbox = new QHBoxLayout;

	//Initialisation du groupe
	fichierSortie1->setChecked(true);
	selectionner->setEnabled(false);

	//Configuration d'affichage
	hbox->addWidget(fichierSortie2);
	hbox->addWidget(selectionner);
	vbox->addWidget(fichierSortie1);
	vbox->addLayout(hbox);
	vbox->addWidget(path);
	setLayout(vbox);

	//Connection de nos objet
	connect(fichierSortie1, &QRadioButton::toggled,
		this, &QDossierSortie::clearDir);
	connect(fichierSortie2, &QRadioButton::toggled,
		selectionner, &QPushButton::setEnabled);
	connect(selectionner, &QPushButton::clicked,
		this, &QDossierSortie::slectionClicked);
	connect(this, &QDossierSortie::folderSelected,
		path, &QLabel::setText);
}

QDossierSortie::~QDossierSortie()
{

}

// Permet de connaitre le chemin choisi par l'utilisateur
void QDossierSortie::slectionClicked()
{

	mDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
		QDir::currentPath(),
		QFileDialog::ShowDirsOnly
		| QFileDialog::DontResolveSymlinks);
	emit folderSelected(mDir);
}
