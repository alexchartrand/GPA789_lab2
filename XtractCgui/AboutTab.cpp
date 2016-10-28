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
	QMessageBox::about(this, "Allo", R"#(...)#");
}