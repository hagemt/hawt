#include <QString>
void change_picture(QString);
#ifdef WIN32
#include "hawt_windows.h"
#else
#include "hawt_gnome.h"
#endif
