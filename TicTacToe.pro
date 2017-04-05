#-------------------------------------------------
#
# Project created by QtCreator 2017-04-03T16:32:25
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TicTacToe
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    Board/TicTacToeBoard.cpp \
    Manager/TicTacToeGameManager.cpp \
    GameWindow.cpp \
    Widget/customgamewidget.cpp \
    Widget/camerawidget.cpp

HEADERS  += mainwindow.h \
    Board/IBoard.h \
    Board/TicTacToeBoard.h \
    Manager/IGameManager.h \
    Manager/IManager.h \
    Manager/TicTacToeGameManager.h \
    Misc/Singleton.h \
    Player/IPlayer.h \
    Player/TicTacToePlayer.h \
    Score/IScore.h \
    Score/TicTacToeScore.h \
    GameWindow.h \
    Widget/customgamewidget.h \
    Widget/camerawidget.h

FORMS    += mainwindow.ui \
    GameWindow.ui \
    Widget/customgamewidget.ui \
    Widget/camerawidget.ui

RESOURCES += \
    images.qrc
