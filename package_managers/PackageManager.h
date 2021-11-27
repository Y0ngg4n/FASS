//
// Created by yonggan on 27.11.21.
//

#ifndef FASS_PACKAGEMANAGER_H
#define FASS_PACKAGEMANAGER_H

#include "../main.h"

class PackageManager {
public:
    static void sync(Main::PMType, bool force);
};

#endif //FASS_PACKAGEMANAGER_H
