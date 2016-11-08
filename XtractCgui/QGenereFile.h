#ifndef QGENEREFILE_H
#define QGENEREFILE_H

#include <QWidget>
#include <qgroupbox>
#include <qradiobutton>


#include "QSelectedFileList.h"
#include "QDirectorySelector.h"
#include "QDossierSortie.h"
#include "QExtentionFichier.h"
#include "QNomFichierSortie.h"
#include "XtractC.h"

class QGenereFile : public QWidget
{
	Q_OBJECT

public :
	QGenereFile(QDirectorySelector *DirectorySel, QWidget *parent = nullptr);
	~QGenereFile() = default;

private :

	QSelectedFileList *mQSelectedFileList;
	QDirectorySelector *mDirectorySel;
	QDossierSortie *mDossierSortie;
	XtractC mXtractC;
	QExtentionFichier *mExtensionFichier;
	QNomFichierSortie *mNomFichierSortie;
	QCheckBox *mDisplayStatistics;

signals :

	void eventSignaled(QString const & message, int timeOut = 3500);

private slots :

	void Appelparametre();
};

#endif // QGENEREFILE_H