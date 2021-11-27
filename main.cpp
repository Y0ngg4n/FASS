#include <QApplication>
#include <QPushButton>
#include "utils/config.h"
#include "main.h"
#include "package_managers/PackageManager.h"
#include<QDebug>
#include <QSettings>
#include <QGridLayout>

int Main::start(int argc, char *argv[]) {
    qDebug() << "Starting FASS";
    QSettings *settings = makeConfig();
    PMType pmType = getPMType(settings->value("package_manager").toString());
    PackageManager::sync(pmType, false);
    QApplication a(argc, argv);
    QPushButton *search = new QPushButton(QIcon::fromTheme("search"), nullptr);
    QPushButton *installed = new QPushButton(QIcon::fromTheme("installed"), nullptr);
    QPushButton *update = new QPushButton(QIcon::fromTheme("update"), nullptr);
    QPushButton *refreshButton = new QPushButton(QIcon::fromTheme("reload"), nullptr);
    QWidget *window = new QWidget;
    QHBoxLayout *topLayout = new QHBoxLayout(window);
    topLayout->addWidget(search);
    topLayout->addWidget(installed);
    topLayout->addWidget(update);
    topLayout->addWidget(refreshButton);
    window->show();
    return QApplication::exec();
}

Main::PMType Main::getPMType(QString command) {
    if (command == "pacman") {
        return pacman;
    } else if (command == "apt") {
        return apt;
    }
    return apt;
};

int main(int argc, char *argv[]) {
    Main main = *new Main();
    main.start(argc, argv);
}