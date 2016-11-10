//! \file QNomFichierSortie.h
//!
//! \brief Définition de la classe QNomFichierSortie.
//! \details Ce fichier fait partie du laboratoire 2 donné dans le cadre du cours 
//! <a href="https://cours.etsmtl.ca/gpa789/" target="_blank">GPA789 Analyse et conception orientées objet</a>.
//!
//! \version 1.0
//!
//! \author Alexandre Chartrand\n
//!		Département de génie de production automatisée\n
//!		École de technologie supérieure\n
//! \author	Jérôme Combet-Blanc
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
//!				numérotation de notre fichier produit.
//! \details	Cette classe fait partie de la solution XtractCgui 
//! 
//! \author		Alexandre Chartrand
//! \author		Jérôme Combet-Blanc
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

	//! Fonction public pour venir chercher les informations désirées
	QString getNomFichier();
	int getDebutNumerotation();

private:
	//! Variable interne du groupe itule au bon fonctionnement de celui-ci
	QLineEdit *prefixe;
	QSpinBox *deb_num;
	QRadioButton *nom_fichier_sortie1;
	QRadioButton *nom_fichier_sortie2;

	//! Variable pour la récupération des information de ce GroupBox
	QString mNomFichier;
	int mDebNum;
};

#endif // QNOMFICHIERSORTIE_H
