#include "QExtentionFichier.h"
#include <qradiobutton>
#include <qlayout>
#include <qlineedit>

//Groupe pour l'attribution de l'extension du fichier
QExtentionFichier::QExtentionFichier(QWidget *parent)
: QGroupBox(tr("Extension du fichier de sortie"), parent), mExtentionFichier("")
{
	//Creation des variables
	extension_fichier1 = new QRadioButton(tr("Utiliser l'extension XtractC"));
	QRadioButton *extension_fichier2 = new QRadioButton(tr("Spécifier l'extension"));
	QVBoxLayout *vbox = new QVBoxLayout;
	QHBoxLayout *hbox = new QHBoxLayout;
	extention = new QLineEdit;

	//Initialisation du groupe
	extension_fichier1->setChecked(true);
	extention->setEnabled(false);
	extention->setText("xtract");

	//Configuration d'affichage
	vbox->addWidget(extension_fichier1);
	hbox->addWidget(extension_fichier2);
	hbox->addWidget(extention);
	vbox->addLayout(hbox);

	setLayout(vbox);

	//Connection de nos objet
	connect(extension_fichier2, &QRadioButton::toggled,
		extention, &QLineEdit::setEnabled);

}

QExtentionFichier::~QExtentionFichier()
{

}

//Fonction  qui retourne l'extension desirée. La fonction
//r'envoie soit l'extension de Xtract soit une extension
//personalisée si le bouton specifier est coché.
QString QExtentionFichier::extentionFiles() const
{
	QString ext;

	//Considérant le choix de l'utilisateur, on va venir
	//adapter l'extention. Ici le point de l'extention est
	//gerer à l'interne.
	if (extension_fichier1->isChecked() == true)
	{
		ext = ".xtract";
	}
	else
	{
		ext = "."+extention->text();
	}
	return ext;
}