//! \file QDossierSortie.h
//!
//! \brief Définition de la classe QDossierSortie.
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

#ifndef QDOSSIERSORTIE_H
#define QDOSSIERSORTIE_H

#include <QGroupBox>

//! \brief		Classe en charge de la configuration du dossier
//!				où notre fichier va être produit.
//! \details	Cette classe fait partie de la solution XtractCgui 
//! 
//! \author		Alexandre Chartrand
//! \author		Jérôme Combet-Blanc
//! \version	1.0
//! \date		06/10/2016
//! \copyright	Copyleft 2000-2016

class QDossierSortie : public QGroupBox
{
	Q_OBJECT

public:
	//! Constructeur
	QDossierSortie(QWidget *parent = nullptr);
	//! Destructeur
	~QDossierSortie();

	//! Fonction public qui retourne le chemin selectionné dans ce GroupBox
	QString getDirectory() { return mDir; }

private:
	void slectionClicked();
	
	QString mDir;

signals:
	// Signal émis lorsque d'un évènement pouvant être signalé à l'usager sur la barre de status.
	void folderSelected(QString const & folder);

private slots:
	void clearDir() { mDir = ""; emit folderSelected(mDir); }
};

#endif // QDOSSIERSORTIE_H
