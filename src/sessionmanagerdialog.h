#ifndef SESSIONMANAGERDIALOG_H
#define SESSIONMANAGERDIALOG_H

#include <QDialog>

namespace Ui {
class SessionManagerDialog;
}

class SessionManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SessionManagerDialog(QWidget *parent = 0);
    ~SessionManagerDialog();

private:
    Ui::SessionManagerDialog *ui;
};

#endif // SESSIONMANAGERDIALOG_H
