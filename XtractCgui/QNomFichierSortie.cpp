#include "QNomFichierSortie.h"
#include <qradiobutton>
#include <qlayout>
#include <qlabel>
#include <qspinbox>
#include <qlineedit>
#include <qstring>

//Groupe pour le nom du fichier
QNomFichierSortie::QNomFichierSortie(QWidget *parent)
: QGroupBox(tr("Nom du fichier de sortie"), parent), mNomFichier("")
{

	//Creation des variables
	mNomFichierSortie1 = new QRadioButton(tr("Utiliser le même nom de fichier"));
	mNomFichierSortie2 = new QRadioButton(tr("Utiliser un nom de fichier avec numérotation automatique"));
	QVBoxLayout *vbox1 = new QVBoxLayout;
	QVBoxLayout *vbox2 = new QVBoxLayout;
	QHBoxLayout *hbox1 = new QHBoxLayout;
	QHBoxLayout *hbox2 = new QHBoxLayout;
	QLabel *texte1 = new QLabel("Préfixe du nom de fichier");
	QLabel *texte2 = new QLabel("Débuter la numérotation à");
	mDebNum = new QSpinBox;
	mPrefixe = new QLineEdit;
	
	//Connection de nos objet
	connect(mNomFichierSortie2, &QRadioButton::toggled,
		texte1, &QLabel::setEnabled);
	connect(mNomFichierSortie2, &QRadioButton::toggled,
		texte2, &QLabel::setEnabled);
	connect(mNomFichierSortie2, &QRadioButton::toggled,
		mPrefixe, &QSpinBox::setEnabled);
	connect(mNomFichierSortie2, &QRadioButton::toggled,
		mDebNum, &QSpinBox::setEnabled);

	//Initialisation du groupe
	mNomFichierSortie1->setChecked(true);
	mDebNum->setValue(1);
	mDebNum->setEnabled(false);
	mPrefixe->setEnabled(false);
	texte1->setEnabled(false);
	texte2->setEnabled(false);

	//Configuration d'affichage
	vbox1->addWidget(mNomFichierSortie1);
	vbox1->addWidget(mNomFichierSortie2);
	hbox1->addWidget(texte1);
	hbox1->addWidget(mPrefixe);
	hbox2->addWidget(texte2);
	hbox2->addWidget(mDebNum);
	vbox1->addLayout(hbox1);
	vbox1->addLayout(hbox2);

	//Affichage du groupe
	setLayout(vbox1);
}

QNomFichierSortie::~QNomFichierSortie()
{

}


//Fonction qui va retourner le prefixe du nom du fichier
QString QNomFichierSortie::getNomFichier()
{
	QString mPref;

	if (mNomFichierSortie2->isChecked() == true){
		mPref = mPrefixe->text();
	}
	else
	{

	}
	return mPref;
}


//Fonction qui retourne la valeur de debut de numerotation
int QNomFichierSortie::getDebutNumerotation()
{
	int mDeb;
	if (mNomFichierSortie2->isChecked() == true){
		mDeb = mDebNum->value();
	}
	else{
		mDeb = 1;
	}
	return mDeb;
}
