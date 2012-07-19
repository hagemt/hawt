#include <QAction>
#include <QApplication>
#include <QIcon>
#include <QMenu>
#include <QMessageBox>
#include <QSystemTrayIcon>

#include "hawt.h"
#include "hawt_settings.h"

int
main(int argc, char *argv[])
{
	// These entities drive the program
	QApplication hawt(argc, argv);
	SettingsInterface window;
	QAction *show_action, *change_action;
	QMenu *context_menu;
	QSystemTrayIcon *tray_icon;
	// Try to use a tray icon
	if (QSystemTrayIcon::isSystemTrayAvailable()) {
		context_menu = new QMenu(&window);
		change_action = new QAction(QObject::tr("Shuffle!"), context_menu);
		show_action = new QAction(QObject::tr("%1 Settings").arg(CLIENT_NAME), context_menu);
		show_action->setCheckable(true);
		show_action->setChecked(false);
		QObject::connect(show_action, SIGNAL(toggled(bool)), &window, SLOT(setVisible(bool)));
		context_menu->addAction(change_action);
		context_menu->addSeparator();
		context_menu->addAction(show_action);
		tray_icon = new QSystemTrayIcon(QIcon(":/images/tray-icon.png"), context_menu);
		tray_icon->setContextMenu(context_menu);
		tray_icon->setToolTip(QObject::tr("%1 >;3").arg(CLIENT_NAME));
		tray_icon->show();
	// Or just show the settings window
	} else if (QMessageBox::question(&window,
					QObject::tr("Oh noes! D="),
					QObject::tr("%1 can't find the system tray; launch anyway?").arg(CLIENT_NAME),
					QMessageBox::Yes | QMessageBox::Close,
					QMessageBox::Close)
				!= QMessageBox::Close) {
		window.show();
	} else {
		window.close();
	}
	// Run the event loop
	return hawt.exec();
}
