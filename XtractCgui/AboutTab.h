#ifndef ABOUT_TAB_H
#define ABOUT_TAB_H

#include <QWidget>

class AboutTab : public QWidget
{
	Q_OBJECT

public:
	AboutTab(QWidget *parent = nullptr);
	~AboutTab() = default;

private slots:
	void showMessageBox();

};

#endif // ABOUT_TAB_H