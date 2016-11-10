//! \file AboutTab.h
//!
//! \brief D�finition de la classe AboutTab.
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

#ifndef ABOUT_TAB_H
#define ABOUT_TAB_H

#include <QWidget>

//! \brief		Classe en charge de contenir l'information et de
//!				l'afficher dans l'�vironnement d�velopp�
//! \details	Cette classe fait partie de la solution XtractCgui 
//! 
//! \author		Alexandre Chartrand
//! \author		J�r�me Combet-Blanc
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