#ifndef HAWT_H
#define HAWT_H

#define PROGRAM_NAME "HAWT"
#define COMPANY_NAME "onetooneandon.to"

#ifdef Q_WS_WIN
#include <windows.h>
#include <QSettings>
#endif

#include <QDir>
#include <QString>
void set_wallpaper(QString);

#endif /* HAWT_H */
