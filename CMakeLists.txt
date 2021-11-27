cmake_minimum_required(VERSION 3.20)
project(FASS)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(FASS main.cpp main.h utils/config.cpp utils/config.h package_managers/PackageManager.cpp package_managers/PackageManager.h package_managers/Apt.cpp package_managers/Apt.h package_managers/Pacman.cpp package_managers/Pacman.h)
target_link_libraries(FASS
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

