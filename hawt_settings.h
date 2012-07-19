#ifndef SETTINGSINTERFACE_H
#define SETTINGSINTERFACE_H

#include <QFrame>
#include <QSettings>

#include "hawt.h"

namespace Ui {
	class SettingsInterface;
}

class SettingsInterface : public QFrame {
	Q_OBJECT
public:
	SettingsInterface(QWidget *parent = 0);
	~SettingsInterface();

public slots:
	void save_settings();
	void reset_settings();

signals:
	void settings_changed();

protected:
	void changeEvent(QEvent *e);

private:
	Ui::SettingsInterface *ui;
	QSettings settings;

	void load_settings();
};

#endif // SETTINGSINTERFACE_H
