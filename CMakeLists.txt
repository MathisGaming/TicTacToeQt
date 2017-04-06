cmake_minimum_required(VERSION 2.8)
project(TicTacToe)
set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.8.0\\5.8\\msvc2015_64\\")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

#find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)
find_package(Qt5Widgets)

set(SOURCES
main.cpp
mainwindow.cpp
Board/TicTacToeBoard.cpp
Manager/TicTacToeGameManager.cpp
GameWindow.cpp
Widget/customgamewidget.cpp
)

set(HEADERS
mainwindow.h
Board/IBoard.h
Board/TicTacToeBoard.h
Manager/IGameManager.h
Manager/IManager.h
Manager/TicTacToeGameManager.h
Misc/Singleton.h
Player/IPlayer.h
Player/TicTacToePlayer.h
Score/IScore.h
Score/TicTacToeScore.h
GameWindow.h
Widget/customgamewidget.h
)

set(FORMS
mainwindow.ui
GameWindow.ui
Widget/customgamewidget.ui
)

set(RESOURCES
images.qrc
)

INCLUDE_DIRECTORIES("Board" "Manager" "Misc" "Player" "Score" "Widget")
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
add_executable(TicTacToe ${SOURCES} ${HEADERS} ${FORMS} ${RESOURCES})
