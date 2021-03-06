//! \file QExtentionFichier.h
//!
//! \brief Définition de la classe QExtentionFichier.
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

#ifndef QEXTENTIONFICHIER_H
#define QEXTENTIONFICHIER_H

#include <QGroupBox>
#include <qwidget>

#include <qradiobutton>
#include <qlayout>
#include <qlineedit>

//! \brief		Classe gérant le GroupBox pour l'extension du fichier de sortie
//! \details	Cette classe fait partie de la solution XtractCgui 
//! 
//!				Elle correspond à l'encapsulation de tous les éléments 
//!				nécessaire au programme requis :
//!				 - gestion des arguments passés en ligne de commande
//!				 - gestion des deux automates
//!				 - lecture du fichier source caractère par caractère 
//!					et assignation aux automates
//!				 - gestion des exception des entrées / sorties
//!				 - affichage des statistiques finales
//!
//!				De plus, XtractC possède deux classes internes utilisées 
//!				pour la gestion d'exception (Exception et ParamException).
//! \author		Alexandre Chartrand
//! \author		Jérôme Combet-Blanc
//! \version	1.0
//! \date		06/10/2016
//! \copyright	Copyleft 2000-2016

class QExtentionFichier : public QGroupBox
{
	Q_OBJECT

public:
	//! Constructeur
	QExtentionFichier(QWidget *parent = nullptr);
	//! Destructeur par défaut
	~QExtentionFichier();

	//! Retourne l'extention desiré
	QString extentionFiles() const;

protected:

	//! Variable necessaire pour aller chercher 
	//! l'information dans notre fenetre
	QRadioButton *extension_fichier1;
	QLineEdit *extention;
	QString mExtentionFichier;

private slots:
	
};

#endif // QEXTENTIONFICHIER_H
