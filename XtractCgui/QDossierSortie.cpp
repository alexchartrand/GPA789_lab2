#include "QDossierSortie.h"


#include <qpushbutton>
#include <qradiobutton.h>
#include <qlayout.h>
#include <QFileDialog>


QDossierSortie::QDossierSortie(QWidget *parent)
: QGroupBox(tr("Dossiers de sortie"), parent), mDir("")
{
	QRadioButton *fichierSortie1 = new QRadioButton(tr("Utiliser le dossier source"));
	QRadioButton *fichierSortie2 = new QRadioButton(tr("Spécifier un dossier de sortie"));
	fichierSortie1->setChecked(true);
	mPath = new QLabel("C:/", this);
	QPushButton *selectionner = new QPushButton("Sélectionner", this);
	selectionner->setEnabled(false);

	QVBoxLayout *vbox = new QVBoxLayout;
	QHBoxLayout *hbox = new QHBoxLayout;

	hbox->addWidget(fichierSortie2);
	hbox->addWidget(selectionner);
	vbox->addWidget(fichierSortie1);
	vbox->addLayout(hbox);
	vbox->addWidget(mPath);
	setLayout(vbox);

	connect(fichierSortie1, &QRadioButton::toggled,
		this, &QDossierSortie::clearDir);

	connect(fichierSortie2, &QRadioButton::toggled,
		selectionner, &QPushButton::setEnabled);

	connect(fichierSortie2, &QRadioButton::toggled,
		this, &QDossierSortie::reloadPath);

	connect(selectionner, &QPushButton::clicked,
		this, &QDossierSortie::slectionClicked);

}

QDossierSortie::~QDossierSortie()
{

}

void QDossierSortie::slectionClicked()
{

	mDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
		mPath->text(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	mPath->setText(mDir);
	
}
