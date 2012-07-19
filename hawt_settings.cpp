#include "hawt_settings.h"
#include "ui_hawt_settings.h"

#include "hawt.h"

SettingsInterface::SettingsInterface(QWidget *parent) :
	QFrame(parent),
	ui(new Ui::SettingsInterface),
	settings(QSettings::IniFormat, QSettings::UserScope, COMPANY_NAME, PROGRAM_NAME)
{
	ui->setupUi(this);
	// attach reset button to default settings
	load_settings();
}

SettingsInterface::~SettingsInterface()
{
	save_settings();
	delete ui;
}

void SettingsInterface::changeEvent(QEvent *e)
{
	QFrame::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void SettingsInterface::save_settings()
{
	emit settings_changed();
}

void SettingsInterface::load_settings()
{
	
}

void SettingsInterface::reset_settings()
{

}
