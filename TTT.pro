QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    board.cpp \
    boardspacelabel.cpp \
    errordialog.cpp \
    gamesetupboards.cpp \
    gamesetupplayers.cpp \
    gamesetupstartgame.cpp \
    imageutils.cpp \
    main.cpp \
    playersymboldialog.cpp \
    playgamewindow.cpp \
    startscreenwindow.cpp \
    gamesetupwindow.cpp \
    symbollabel.cpp \
    utils.cpp

HEADERS += \
    board.h \
    boardsettings.h \
    boardspacelabel.h \
    errordialog.h \
    imageutils.h \
    player.h \
    playersymboldialog.h \
    playgamewindow.h \
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
