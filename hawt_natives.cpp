#include "hawt.h"

void set_wallpaper(QString file) {
	QString full_path = QDir::toNativeSeparators(file);
	#ifdef Q_WS_WIN
	// Change the necessary registry entries
	QSettings registry("HKEY_CURRENT_USER\\Control Panel\\Desktop", QSettings::NativeFormat);
	registry.setValue("Wallpaper", full_path);
	registry.setValue("WallpaperStyle", "0");
	registry.setValue("TileWallpaper", "0");
	// Change the system information
	BOOL (*)(UINT, UINT, PVOID, UINT) fp; void *p;
	#ifdef UNICODE
	// Unicode paths require WCHARs
	int path_length = full_path.length();
	WCHAR *unicode_path = new WCHAR[path_length];
	memset(unicode_path, 0, path_length * sizeof(WCHAR));
	path_length length = full_path.toWCharArray(unicode_path);
	fp = &SystemParametersInfoW;
	p = reinterpret_cast<void *>(unicode_path);
	#else /* UNICODE */
	fp = &SystemParametersInfoA;
	p = reinterpret_cast<void *>(full_path.toAscii().data());
	#endif /* UNICODE */
	(*fp)(SPI_SETDESKWALLPAPER, 0, p, SPIF_SENDWININICHANGE);
	#else /* Q_WS_WIN */
	qDebug() << full_path;
	#endif /* Q_WS_WIN */
}
