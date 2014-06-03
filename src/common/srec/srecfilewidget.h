#ifndef SRECFILEWIDGET_H
#define SRECFILEWIDGET_H

#include <QWidget>
#include "srecfile.h"

namespace Ui {
class srecFileWidget;
}

class srecFileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit srecFileWidget(QWidget *parent = 0);
    ~srecFileWidget();

public slots:
    void updatSrecFile(srecFile* file);
    void updateRecords();

private slots:
    void recordCellActivated(int row, int column);

private:
    Ui::srecFileWidget *ui;
    srecFile* p_srec;
};

#endif // SRECFILEWIDGET_H
