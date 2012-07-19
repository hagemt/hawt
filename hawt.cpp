#include <QApplication>

#include "hawt_settings.h"

int
main(int argc, char *argv[])
{
	QApplication hawt(argc, argv);
	SettingsInterface window;
	window.show();
	return hawt.exec();
}
