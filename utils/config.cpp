#include <QSettings>
#include <filesystem>
#include<QDebug>
#include <QDir>
#include <QFile>

using std::filesystem::exists;
using std::filesystem::path;

std::string getPackageManager(){
    const int pacman = system("/usr/bin/pacman --version");
    const int apt = system("/usr/bin/apt --version");

    if(pacman != -1){
        return "pacman";
    }
    if(apt != -1){
        return "apt";
    }
    return "apt";
}

QSettings* makeConfig() {
    const QString config_dir = QDir::homePath() + "/.config/fass";
    const QString system_config = config_dir + "/system.conf";

    QDir().mkdir(config_dir);
    auto *system_settings = new QSettings(system_config, QSettings::IniFormat);

    if (!QFile(system_config).exists()) {
        qInfo() << "Config file not existing. Creating new one.";
        system_settings->setValue("package_manager", getPackageManager().c_str());
        system_settings->sync();
        qDebug() << ("Saving Settings" + system_config);
    }
    return system_settings;
}
