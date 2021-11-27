//
// Created by yonggan on 27.11.21.
//

#ifndef FASS_MAIN_H
#define FASS_MAIN_H

int main(int argc, char *argv[]);

class Main {
public:
    enum PMType {
        apt,
        pacman
    };

    int start(int argc, char *argv[]);

    Main::PMType getPMType(QString command);
};

#endif //FASS_MAIN_H
