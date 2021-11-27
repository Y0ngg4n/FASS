//
// Created by yonggan on 27.11.21.
//

#include <QProcess>
#include "Apt.h"

void Apt::sync(bool force) {
    QProcess::execute("apt update");
}
