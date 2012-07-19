#ifndef SETTINGSINTERFACE_H
#define SETTINGSINTERFACE_H

#include <QFrame>

namespace Ui {
    class SettingsInterface;
}

class SettingsInterface : public QFrame {
    Q_OBJECT
public:
    SettingsInterface(QWidget *parent = 0);
    ~SettingsInterface();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SettingsInterface *ui;
};

#endif // SETTINGSINTERFACE_H
