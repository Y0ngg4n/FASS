//
// Created by yonggan on 27.11.21.
//

#include <QProcess>
#include "PackageManager.h"
#include "Pacman.h"
#include "Apt.h"

void PackageManager::sync(Main::PMType pmType, bool force) {
    switch (pmType) {
        case Main::PMType::pacman:
            Pacman::sync(force);
            break;
        case Main::PMType::apt:
            Apt::sync(force);
            break;
    }
}
