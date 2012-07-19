#include <QApplication>

#include "hawt.h"
#include "hawt_settings.h"

int
main(int argc, char *argv[])
{
	QApplication hawt(argc, argv);
	SettingsInterface window;
	
	return hawt.exec();
}
