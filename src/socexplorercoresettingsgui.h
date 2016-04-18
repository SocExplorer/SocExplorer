#ifndef SOCEXPLORERCORESETTINGSGUI_H
#define SOCEXPLORERCORESETTINGSGUI_H

#include <QWidget>
#include <socexplorersettingsdialog.h>

namespace Ui {
class SocExplorerCoreSettingsGUI;
}

class SocExplorerCoreSettingsGUI : public SocExplorerSettingsItem
{
    Q_OBJECT

public:
    explicit SocExplorerCoreSettingsGUI(QWidget *parent = 0);
    ~SocExplorerCoreSettingsGUI();

protected:
    void changeEvent(QEvent *e);
public slots:
    void accept();
private:
    Ui::SocExplorerCoreSettingsGUI *ui;
};

#endif // SOCEXPLORERCORESETTINGSGUI_H
