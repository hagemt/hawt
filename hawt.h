#define CLIENT_NAME "HAWT"
#include <QString>
void set_wallpaper(QString);
#ifdef WIN32
#include "hawt_windows.h"
#else
#include "hawt_gnome.h"
#endif
