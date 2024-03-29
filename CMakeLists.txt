cmake_minimum_required(VERSION 3.13)
project(Catch_the_pokemon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC on)
set(CMALE_AUTOUIC on)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Multimedia REQUIRED)


set(SOURCE_FILES
        main.cpp
        GameWindow.cpp
        GameWindow.h
        GameArea.cpp
        GameArea.h
        GameWidget.cpp
        GameWidget.h
        gameObjects/GameObject.cpp
        gameObjects/GameObject.h
        gameObjects/Player.cpp
        gameObjects/Player.h
        gameObjects/Obstacle.cpp
        gameObjects/Obstacle.h
        gameObjects/Shot.cpp
        gameObjects/Shot.h
        Thread.cpp
        Thread.h
        CollisionDetection.cpp
        CollisionDetection.h gameObjects/Crosshair.cpp gameObjects/Crosshair.h)

add_executable(Catch_the_pokemon ${SOURCE_FILES})
target_link_libraries(Catch_the_pokemon Qt5::Widgets Qt5::Multimedia)
