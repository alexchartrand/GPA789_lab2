//! \file QNomFichierSortie.h
//!
//! \brief D�finition de la classe QNomFichierSortie.
//! \details Ce fichier fait partie du laboratoire 2 donn� dans le cadre du cours 
//! <a href="https://cours.etsmtl.ca/gpa789/" target="_blank">GPA789 Analyse et conception orient�es objet</a>.
//!
//! \version 1.0
//!
//! \author Alexandre Chartrand\n
//!		D�partement de g�nie de production automatis�e\n
//!		�cole de technologie sup�rieure\n
//! \author	J�r�me Combet-Blanc
//!
//! \date 2000-2016
//! \copyright Copyleft 2000-2016

#ifndef QNOMFICHIERSORTIE_H
#define QNOMFICHIERSORTIE_H

#include <QGroupBox>
#include <qlineedit>
#include <qspinbox>
#include <qradiobutton>

//! \brief		Classe en charge de la configuration du nom et de la 
//!				num�rotation de notre fichier produit.
//! \details	Cette classe fait partie de la solution XtractCgui 
//! 
//! \author		Alexandre Chartrand
//! \author		J�r�me Combet-Blanc
//! \version	1.0
//! \date		06/10/2016
//! \copyright	Copyleft 2000-2016

class QNomFichierSortie : public QGroupBox
{
	Q_OBJECT

public:
	//! Constructeur
	QNomFichierSortie(QWidget *parent = nullptr);
	//! Destructeur
	~QNomFichierSortie();

	//! Fonction public pour venir chercher les informations d�sir�es
	QString getNomFichier();
	int getDebutNumerotation();

private:
	//! Variable interne du groupe itule au bon fonctionnement de celui-ci
	QLineEdit *prefixe;
	QSpinBox *deb_num;
	QRadioButton *nom_fichier_sortie1;
	QRadioButton *nom_fichier_sortie2;

	//! Variable pour la r�cup�ration des information de ce GroupBox
	QString mNomFichier;
	int mDebNum;
};

#endif // QNOMFICHIERSORTIE_H
