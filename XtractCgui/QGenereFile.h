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
	QExtentionFichier *mExtensionFichier;
	QNomFichierSortie *mNomFichierSortie;

private slots :

	void Appelparametre();
};

#endif // QGENEREFILE_H