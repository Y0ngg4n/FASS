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

add_executable(FASS main.cpp main.h utils/config.cpp utils/config.h)
target_link_libraries(FASS
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

