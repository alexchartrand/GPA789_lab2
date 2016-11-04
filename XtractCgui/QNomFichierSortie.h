#ifndef QNOMFICHIERSORTIE_H
#define QNOMFICHIERSORTIE_H

#include <QGroupBox>

class QNomFichierSortie : public QGroupBox
{
	Q_OBJECT

public:
	QNomFichierSortie(QWidget *parent = nullptr);
	~QNomFichierSortie();

	QString getNomFichier();

private:
	
	QString mNomFichier;
};

#endif // QNOMFICHIERSORTIE_H
