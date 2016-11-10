#include "QDossierSortie.h"

#include <qlabel>
#include <qpushbutton>
#include <qradiobutton.h>
#include <qlayout.h>
#include <QFileDialog>
#include <qdir>

QDossierSortie::QDossierSortie(QWidget *parent)
: QGroupBox(tr("Dossiers de sortie"), parent), mDir("")
{
	QRadioButton *fichierSortie1 = new QRadioButton(tr("Utiliser le dossier source"));
	QRadioButton *fichierSortie2 = new QRadioButton(tr("Spécifier un dossier de sortie"));
	fichierSortie1->setChecked(true);
	QLabel *path = new QLabel(this);
	QPushButton *selectionner = new QPushButton("&Sélectionner", this);
	selectionner->setEnabled(false);

	QVBoxLayout *vbox = new QVBoxLayout;
	QHBoxLayout *hbox = new QHBoxLayout;

	hbox->addWidget(fichierSortie2);
	hbox->addWidget(selectionner);
	vbox->addWidget(fichierSortie1);
	vbox->addLayout(hbox);
	vbox->addWidget(path);
	setLayout(vbox);

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

void QDossierSortie::slectionClicked()
{

	mDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
		QDir::currentPath(),
		QFileDialog::ShowDirsOnly
		| QFileDialog::DontResolveSymlinks);
	emit folderSelected(mDir);
}
