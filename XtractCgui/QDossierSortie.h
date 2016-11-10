#ifndef QDOSSIERSORTIE_H
#define QDOSSIERSORTIE_H

#include <QGroupBox>
#include <qlabel>



class QDossierSortie : public QGroupBox
{
	Q_OBJECT

public:
	QDossierSortie(QWidget *parent = nullptr);
	~QDossierSortie();
	QString getDirectory() { return mDir; }

private:
	void slectionClicked();
	QLabel *mPath;
	QString mDir;

signals:
	
	void folderSelected(QString const & folder);

private slots:
	void clearDir() { mDir = ""; }
	void reloadPath() { mDir = mPath->text(); }
};

#endif // QDOSSIERSORTIE_H
