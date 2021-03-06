#ifndef QNOMFICHIERSORTIE_H
#define QNOMFICHIERSORTIE_H

#include <QGroupBox>
#include <qlineedit>
#include <qspinbox>
#include <qradiobutton>

class QNomFichierSortie : public QGroupBox
{
	Q_OBJECT

public:
	QNomFichierSortie(QWidget *parent = nullptr);
	~QNomFichierSortie();

	QString getNomFichier();
	int getDebutNumerotation();

private:
	
	QLineEdit *prefixe;
	QSpinBox *deb_num;
	QRadioButton *nom_fichier_sortie1;
	QRadioButton *nom_fichier_sortie2;

	//Variable pour la récupération des information de ce GroupBox
	QString mNomFichier;
	int mDebNum;
};

#endif // QNOMFICHIERSORTIE_H
