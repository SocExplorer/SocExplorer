#ifndef ELFFILEWIDGET_H
#define ELFFILEWIDGET_H

#include <QtWidgets/QWidget>
#include "elffile.h"

namespace Ui {
class elfFileWidget;
}

class elfFileWidget : public QWidget
{
    Q_OBJECT

public:
    elfFileWidget(QWidget *parent = 0);
    ~elfFileWidget();

public slots:
    void updateElfFile(ElfFile* file);

private:
    Ui::elfFileWidget *ui;
    ElfFile* p_elf;
};

#endif // ELFFILEWIDGET_H
