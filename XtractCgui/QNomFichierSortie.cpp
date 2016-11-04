#include "QNomFichierSortie.h"
#include <qradiobutton>
#include <qlayout>
#include <qlabel>
#include <qspinbox>


QNomFichierSortie::QNomFichierSortie(QWidget *parent)
	: QGroupBox(parent)
{
	QRadioButton *nom_fichier_sortie1 = new QRadioButton(tr("Utiliser le même nom de fichier"));
	QRadioButton *nom_fichier_sortie2 = new QRadioButton(tr("Utiliser un nom de fichier avec numérotation automatique"));
	QVBoxLayout *vbox1 = new QVBoxLayout;
	QVBoxLayout *vbox2 = new QVBoxLayout;
	QLabel *texte1 = new QLabel("&Préfixe du nom de fichier");
	QLabel *texte2 = new QLabel("&Préfixe du nom de fichier");
	QSpinBox *deb_num = new QSpinBox;

	connect(nom_fichier_sortie2, &QRadioButton::toggled,
		deb_num, &QSpinBox::setEnabled);


	nom_fichier_sortie1->setChecked(true);
	deb_num->setValue(1);


	vbox1->addWidget(nom_fichier_sortie1);
	vbox1->addWidget(nom_fichier_sortie2);
	vbox2->addWidget(deb_num);
	vbox1->addLayout(vbox2);
	vbox2->setEnabled(false);

	/*connect(nom_fichier_sortie2, &QRadioButton::toggled,
		vbox2, &QLayout::setEnabled);*/



	setLayout(vbox1);
}

QNomFichierSortie::~QNomFichierSortie()
{

}
