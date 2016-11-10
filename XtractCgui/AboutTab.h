//! \file AboutTab.h
//!
//! \brief Définition de la classe AboutTab.
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

#ifndef ABOUT_TAB_H
#define ABOUT_TAB_H

#include <QWidget>

//! \brief		Classe en charge de contenir l'information et de
//!				l'afficher dans l'évironnement développé
//! \details	Cette classe fait partie de la solution XtractCgui 
//! 
//! \author		Alexandre Chartrand
//! \author		Jérôme Combet-Blanc
//! \version	1.0
//! \date		06/10/2016
//! \copyright	Copyleft 2000-2016

class AboutTab : public QWidget
{
	Q_OBJECT

public:
	//! Constructeur
	AboutTab(QWidget *parent = nullptr);
	//! Destructeur
	~AboutTab() = default;

private slots:
	//! fonction qui va afficher la fenetre d'information
	void showMessageBox();

};

#endif // ABOUT_TAB_H