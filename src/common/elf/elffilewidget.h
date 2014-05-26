#ifndef ELFFILEWIDGET_H
#define ELFFILEWIDGET_H

#include <QWidget>

namespace Ui {
class elfFileWidget;
}

class elfFileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit elfFileWidget(QWidget *parent = 0);
    ~elfFileWidget();

private:
    Ui::elfFileWidget *ui;
};

#endif // ELFFILEWIDGET_H
