#include "QNomFichierSortie.h"
#include <qradiobutton>
#include <qlayout>
#include <qlabel>
#include <qspinbox>
#include <qlineedit>
#include <qstring>


QNomFichierSortie::QNomFichierSortie(QWidget *parent)
: QGroupBox(tr("Nom du fichier de sortie"), parent), mNomFichier("")
{

	QRadioButton *nom_fichier_sortie1 = new QRadioButton(tr("Utiliser le même nom de fichier"));
	QRadioButton *nom_fichier_sortie2 = new QRadioButton(tr("Utiliser un nom de fichier avec numérotation automatique"));
	QVBoxLayout *vbox1 = new QVBoxLayout;
	QVBoxLayout *vbox2 = new QVBoxLayout;
	QHBoxLayout *hbox1 = new QHBoxLayout;
	QHBoxLayout *hbox2 = new QHBoxLayout;
	QLabel *texte1 = new QLabel("Préfixe du nom de fichier");
	QLabel *texte2 = new QLabel("Débuter la numérotation à");
	deb_num = new QSpinBox;
	prefixe = new QLineEdit;
	

	connect(nom_fichier_sortie2, &QRadioButton::toggled,
		texte1, &QLabel::setEnabled);
	connect(nom_fichier_sortie2, &QRadioButton::toggled,
		texte2, &QLabel::setEnabled);
	connect(nom_fichier_sortie2, &QRadioButton::toggled,
		prefixe, &QSpinBox::setEnabled);
	connect(nom_fichier_sortie2, &QRadioButton::toggled,
		deb_num, &QSpinBox::setEnabled);


	nom_fichier_sortie1->setChecked(true);
	deb_num->setValue(1);
	deb_num->setEnabled(false);
	prefixe->setEnabled(false);
	texte1->setEnabled(false);
	texte2->setEnabled(false);


	vbox1->addWidget(nom_fichier_sortie1);
	vbox1->addWidget(nom_fichier_sortie2);
	hbox1->addWidget(texte1);
	hbox1->addWidget(prefixe);
	hbox2->addWidget(texte2);
	hbox2->addWidget(deb_num);
	vbox1->addLayout(hbox1);
	vbox1->addLayout(hbox2);


	setLayout(vbox1);
}

QNomFichierSortie::~QNomFichierSortie()
{

}

QString QNomFichierSortie::getNomFichier()
{
	QString mPrefixe = prefixe->text();
	return mPrefixe;
}

int QNomFichierSortie::getDebutNumerotation()
{
	int mDeb_num = deb_num->value();
	return mDeb_num;
}
