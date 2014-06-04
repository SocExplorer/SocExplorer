#ifndef BINARYFILEWIDGET_H
#define BINARYFILEWIDGET_H

#include <QWidget>
#include "binaryfile.h"

namespace Ui {
class binaryFileWidget;
}

class binaryFileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit binaryFileWidget(QWidget *parent = 0);
    ~binaryFileWidget();

public slots:
    void updateBinaryFile(binaryFile* file);
    void updateFragments();

private slots:
    void fragmentCellActivated(int row, int column);
    void fragmentCellChanged(int row, int column);

private:
    Ui::binaryFileWidget *ui;
    binaryFile* p_binfile;
};

#endif // BINARYFILEWIDGET_H
