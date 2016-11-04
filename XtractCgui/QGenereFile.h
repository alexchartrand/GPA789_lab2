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
	QGenereFile(QWidget *parent = nullptr);
	~QGenereFile() = default;

private :

	QSelectedFileList *mQSelectedFileList;
	QDirectorySelector *mDirectorySel;
	QDossierSortie *mDossierSortie;
	QExtentionFichier *mExtensionFichier;
	QNomFichierSortie *mNomFichierSortie;

	QRadioButton *mFichierSortie1;

	QGroupBox *createFirstExclusiveGroup();
	QGroupBox *createSecondExclusiveGroup();
	QGroupBox *createNonExclusiveGroup();

};

#endif // QGENEREFILE_H