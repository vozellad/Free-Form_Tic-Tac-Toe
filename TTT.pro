QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    errordialog.cpp \
    gamesetupboards.cpp \
    gamesetupplayers.cpp \
    imageutils.cpp \
    main.cpp \
    playersymboldialog.cpp \
    playgamewindow.cpp \
    playsymbollabel.cpp \
    startscreenwindow.cpp \
    gamesetupwindow.cpp \
    symbollabel.cpp \
    utils.cpp

HEADERS += \
    board.h \
    errordialog.h \
    imageutils.h \
    player.h \
    playersymboldialog.h \
    playgamewindow.h \
    playsymbollabel.h \
    startscreenwindow.h \
    gamesetupwindow.h \
    symbollabel.h \
    utils.h

FORMS += \
    errordialog.ui \
    playersymboldialog.ui \
    playgamewindow.ui \
    startscreenwindow.ui \
    gamesetupwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
