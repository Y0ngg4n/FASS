#include <QApplication>
#include <QPushButton>
#include "utils/config.h"
#include<QDebug>
#include <QSettings>

int main(int argc, char *argv[]) {
    qDebug() << "Starting FASS";
    QSettings* settings = makeConfig();
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}