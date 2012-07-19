#include "hawt_settings.h"
#include "ui_hawt_settings.h"

SettingsInterface::SettingsInterface(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingsInterface)
{
    ui->setupUi(this);
}

SettingsInterface::~SettingsInterface()
{
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
