#ifndef FASS_CONFIG_H
#define FASS_CONFIG_H

#include <QSettings>

QSettings* makeConfig();

std::string getPackageManager();

#endif //FASS_CONFIG_H
