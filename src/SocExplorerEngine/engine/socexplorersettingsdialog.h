#ifndef SOCEXPLORERSETTINGSDIALOG_H
#define SOCEXPLORERSETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SocExplorerSettingsDialog;
}
#include <QListWidgetItem>

class SocExplorerSettingsItem : public QWidget
{
    Q_OBJECT
public:
    SocExplorerSettingsItem(QWidget *parent = 0):QWidget(parent) {}
    ~SocExplorerSettingsItem() {}
public slots:
    virtual void accept()=0;
};

class SocExplorerSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SocExplorerSettingsDialog(QWidget *parent = 0);
    ~SocExplorerSettingsDialog();

public slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
    bool registerConfigEntry(SocExplorerSettingsItem* configEntry, QIcon icon, QString text);
    void popConfigDialog(SocExplorerSettingsItem* selectedConfigEntry=0);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SocExplorerSettingsDialog *ui;
};

#endif // SOCEXPLORERSETTINGSDIALOG_H
