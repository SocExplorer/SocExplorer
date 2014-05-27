#ifndef ELFFILEWIDGET_H
#define ELFFILEWIDGET_H

#include <QWidget>
#include "elffile.h"

namespace Ui {
class elfFileWidget;
}

class elfFileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit elfFileWidget(QWidget *parent = 0);
    ~elfFileWidget();
public slots:
    void updateElfFile(ElfFile* file);

private:
    Ui::elfFileWidget *ui;
    ElfFile* p_elf;
};

#endif // ELFFILEWIDGET_H
