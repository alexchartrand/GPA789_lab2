#include "AboutTab.h"
#include <qmessagebox>
#include <qpushbutton>
#include <QHboxlayout>
#include <QVboxlayout>

//Groupe pour la gestion de l'information concernant ce programme
AboutTab::AboutTab(QWidget *parent)
{
	//Creation des variables
	QPushButton *aboutButton = new QPushButton("À propos...");
	QHBoxLayout *hLayout = new QHBoxLayout;
	QVBoxLayout *vLayout = new QVBoxLayout;

	//Configuration d'affichage
	hLayout->addStretch();
	hLayout->addWidget(aboutButton);
	vLayout->addStretch();
	vLayout->addLayout(hLayout);

	setLayout(vLayout);

	//Connection de nos objet
	connect(aboutButton, &QPushButton::clicked,
		this, &AboutTab::showMessageBox);
}

// Fonction d'affichage des informations du programme
void AboutTab::showMessageBox()
{
	//Creation des variables
	QPixmap image = QPixmap("Resource/icon.png");
	QMessageBox  about;

	//Configuration d'affichage
	about.setIconPixmap(image);
	about.setWindowTitle("À propos de XtractC");
	about.setWindowIcon(image);
	about.setText(R"#(XtractC est un logiciel d'extraction de commentaires du langage C++.

Ce programme a été réalisé par :
- Alexandre Chratrand
- Jérôme Combet-Blanc

Dans le cadre du cours :
- GPA 789 - Analyse et conception orientées objet
- Laboratoire 2

Version 1.0)#");
	
	about.exec();
	
}