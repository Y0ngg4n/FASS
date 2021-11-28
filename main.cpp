#include <QApplication>
#include <QPushButton>
#include "utils/config.h"
#include "main.h"
#include "package_managers/PackageManager.h"
#include "utils/border_layout.h"
#include<QDebug>
#include <QSettings>
#include <QLineEdit>


const int iconSize = 50;
const int searchBarHeight = 25;

int Main::start(int argc, char *argv[]) {

    qDebug() << "Starting FASS";
    QSettings *settings = makeConfig();
    PMType pmType = getPMType(settings->value("package_manager").toString());
    PackageManager::sync(pmType, false);
    QApplication a(argc, argv);
    QHBoxLayout *topLayout = new QHBoxLayout;
    QVBoxLayout *leftLayout = new QVBoxLayout;
    QLineEdit *searchbar = new QLineEdit();
    searchbar->setClearButtonEnabled(true);
    QFont font = searchbar->font();
    font.setPointSize(searchBarHeight);
    searchbar->setFont(font);
//    QPushButton *search = new QPushButton(QIcon::fromTheme("search"), nullptr);
    searchbar->setAlignment(Qt::AlignCenter);
    searchbar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *installed = new QPushButton(QIcon::fromTheme("download"), nullptr);
    installed->setIconSize(QSize(iconSize, iconSize));
    QPushButton *refreshButton = new QPushButton(QIcon::fromTheme("reload"), nullptr);
    refreshButton->setIconSize(QSize(iconSize, iconSize));
    QWidget *window = new QWidget;
    BorderLayout *borderLayout = new BorderLayout;
    QVBoxLayout *leftBottomLayout = new QVBoxLayout;
    QVBoxLayout *leftTopLayout = new QVBoxLayout;
    borderLayout->add(leftLayout, BorderLayout::West);
    borderLayout->add(topLayout, BorderLayout::North);
    leftLayout->addLayout(leftTopLayout);
    leftLayout->addLayout(leftBottomLayout);
    leftBottomLayout->addWidget(installed);
    leftBottomLayout->addWidget(refreshButton);
    leftBottomLayout->setAlignment(Qt::AlignBottom);
    topLayout->setAlignment(Qt::AlignCenter);
    leftLayout->setContentsMargins(10, 10, 10, 10);
    topLayout->setContentsMargins(iconSize + 30, 10, iconSize + 30, 10);
    topLayout->addWidget(searchbar);
//    topLayout->addWidget(search);

    window->setLayout(borderLayout);
    window->show();
    window->setMinimumSize(400, 400);
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