//
// Created by yonggan on 27.11.21.
//

#include <QProcess>
#include "Pacman.h"

void Pacman::sync(bool force) {
    QProcess::execute("pacman -Sy");
}
