//! \file QDossierSortie.h
//!
//! \brief D�finition de la classe QDossierSortie.
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

#ifndef QDOSSIERSORTIE_H
#define QDOSSIERSORTIE_H

#include <QGroupBox>

//! \brief		Classe en charge de la configuration du dossier
//!				o� notre fichier va �tre produit.
//! \details	Cette classe fait partie de la solution XtractCgui 
//! 
//! \author		Alexandre Chartrand
//! \author		J�r�me Combet-Blanc
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

	//! Fonction public qui retourne le chemin selectionn� dans ce GroupBox
	QString getDirectory() { return mDir; }

private:
	void slectionClicked();
	
	QString mDir;

signals:
	// Signal �mis lorsque d'un �v�nement pouvant �tre signal� � l'usager sur la barre de status.
	void folderSelected(QString const & folder);

private slots:
	void clearDir() { mDir = ""; emit folderSelected(mDir); }
};

#endif // QDOSSIERSORTIE_H
