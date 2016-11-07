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

	// Recuperer le nom du fichier
	QString getNomFichier();
	// Retourne le numero qui va débuter la numérotation
	int getDebutNumerotation();

private:
	
	QLineEdit *mPrefixe;
	QSpinBox *mDebNum;
	QRadioButton *mNomFichierSortie1;
	QRadioButton *mNomFichierSortie2;
	QString mNomFichier;

};

#endif // QNOMFICHIERSORTIE_H
