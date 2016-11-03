#ifndef QGENEREFILE_H
#define QGENEREFILE_H

#include <QWidget>
#include <qgroupbox.h>

#include "QSelectedFileList.h"

class QGenereFile : public QWidget

{
	Q_OBJECT

public :
	QGenereFile(QWidget *parent = nullptr);
	~QGenereFile() = default;

private :
	QSelectedFileList *mQSelectedFileList;
	QGroupBox *createFirstExclusiveGroup();
	QGroupBox *createSecondExclusiveGroup();
	QGroupBox *createNonExclusiveGroup();
	QGroupBox *createPushButtonGroup();
};

#endif // QGENEREFILE_H