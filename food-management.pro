QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
    createwindow.cpp \
    main.cpp \
    pigsbox.cpp \
    pigsboxinfodialog.cpp \
    pigshall.cpp \
    ranch.cpp \
    ranchwindow.cpp \
    source/basewindow.cpp \
    source/createmenu.cpp

HEADERS += \
    createwindow.h \
    headers/basewindow.h \
    headers/createmenu.h \
    pigsbox.h \
    pigsboxinfodialog.h \
    pigshall.h \
    ranch.h \
    ranchwindow.h \
    ui_loginmenu.h

FORMS += \
    createwindow.ui \
    pigsboxinfodialog.ui \
    ranchwindow.ui \
    ui/basewindow.ui \
    ui/createmenu.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    assets/hamburger_logo.png \
    assets/pig_bun.ico

RESOURCES += \
    resouces.qrc

