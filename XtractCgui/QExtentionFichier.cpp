#include "QExtentionFichier.h"
#include <qradiobutton>
#include <qlayout>
#include <qlineedit>


QExtentionFichier::QExtentionFichier(QWidget *parent)
: QGroupBox(tr("Extension du fichier de sortie"), parent), mExtentionFichier("")
{
	QRadioButton *extension_fichier1 = new QRadioButton(tr("Utiliser l'extension XtractC"));
	QRadioButton *extension_fichier2 = new QRadioButton(tr("Spécifier l'extension"));
	QVBoxLayout *vbox = new QVBoxLayout;
	QHBoxLayout *hbox = new QHBoxLayout;
	extention = new QLineEdit;

	connect(extension_fichier2, &QRadioButton::toggled,
		extention, &QLineEdit::setEnabled);

	extension_fichier1->setChecked(true);
	extention->setEnabled(false);
	extention->setText("xtract");

	vbox->addWidget(extension_fichier1);
	hbox->addWidget(extension_fichier2);
	hbox->addWidget(extention);
	vbox->addLayout(hbox);

	setLayout(vbox);

}

QExtentionFichier::~QExtentionFichier()
{

}
