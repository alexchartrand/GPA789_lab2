#include "AboutTab.h"
#include <qmessagebox>
#include <qpushbutton>
#include <QHboxlayout>
#include <QVboxlayout>


AboutTab::AboutTab(QWidget *parent)
{
	QPushButton *aboutButton = new QPushButton("À propos...");
	QHBoxLayout *hLayout = new QHBoxLayout;
	QVBoxLayout *vLayout = new QVBoxLayout;

	hLayout->addStretch();
	hLayout->addWidget(aboutButton);
	vLayout->addStretch();
	vLayout->addLayout(hLayout);

	setLayout(vLayout);

	connect(aboutButton, &QPushButton::clicked,
		this, &AboutTab::showMessageBox);
}


void AboutTab::showMessageBox()
{
	QPixmap image = QPixmap("Resource/icon.png");
	

	QMessageBox  about;
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