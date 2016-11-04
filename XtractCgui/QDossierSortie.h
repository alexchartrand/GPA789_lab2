#ifndef QDOSSIERSORTIE_H
#define QDOSSIERSORTIE_H

#include <QGroupBox>


class QDossierSortie : public QGroupBox
{
	Q_OBJECT

public:
	QDossierSortie(QWidget *parent = nullptr);
	~QDossierSortie();

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
