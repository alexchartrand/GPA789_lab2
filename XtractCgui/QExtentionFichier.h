#ifndef QEXTENTIONFICHIER_H
#define QEXTENTIONFICHIER_H

#include <QGroupBox>
#include <qlineedit>

class QExtentionFichier : public QGroupBox
{
	Q_OBJECT

public:
	QExtentionFichier(QWidget *parent = nullptr);
	~QExtentionFichier();

private:
	
	QLineEdit *extention;
	QString mExtentionFichier;
};

#endif // QEXTENTIONFICHIER_H
