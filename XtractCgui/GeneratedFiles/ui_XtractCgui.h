/********************************************************************************
** Form generated from reading UI file 'XtractCgui.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XTRACTCGUI_H
#define UI_XTRACTCGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XtractCguiClass
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *XtractCguiClass)
    {
        if (XtractCguiClass->objectName().isEmpty())
            XtractCguiClass->setObjectName(QStringLiteral("XtractCguiClass"));
        XtractCguiClass->resize(842, 582);
        centralWidget = new QWidget(XtractCguiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        XtractCguiClass->setCentralWidget(centralWidget);

        retranslateUi(XtractCguiClass);

        QMetaObject::connectSlotsByName(XtractCguiClass);
    } // setupUi

    void retranslateUi(QMainWindow *XtractCguiClass)
    {
        XtractCguiClass->setWindowTitle(QApplication::translate("XtractCguiClass", "XtractCgui", 0));
    } // retranslateUi

};

namespace Ui {
    class XtractCguiClass: public Ui_XtractCguiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XTRACTCGUI_H
