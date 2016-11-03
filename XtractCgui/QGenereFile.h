#ifndef QGENEREFILE_H
#define QGENEREFILE_H

#include <QWidget>
#include <qgroupbox>

#include "QSelectedFileList.h"
#include "QDirectorySelector.h"
#include <qradiobutton>

class QGenereFile : public QWidget

{
	Q_OBJECT

public :
	QGenereFile(QWidget *parent = nullptr);
	~QGenereFile() = default;

private :

	QSelectedFileList *mQSelectedFileList;
	QDirectorySelector *mDirectorySel;

	QRadioButton *mFichierSortie1;

	QGroupBox *createFirstExclusiveGroup();
	QGroupBox *createSecondExclusiveGroup();
	QGroupBox *createNonExclusiveGroup();

};

#endif // QGENEREFILE_H