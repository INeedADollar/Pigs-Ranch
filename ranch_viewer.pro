QT += gui core

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

RESOURCES += \
    resources.qrc

FORMS += \
    ui/ranchwindow.ui \
    ui/basewindow.ui \
    ui/createwindow.ui \
    ui/hallwindow.ui \
    ui/pigsboxinfodialog.ui

HEADERS += \
    headers/basewindow.h \
    headers/createwindow.h \
    headers/hallwindow.h \
    headers/pigsbox.h \
    headers/pigsboxinfodialog.h \
    headers/pigshall.h \
    headers/ranch.h \
    headers/ranchwindow.h

SOURCES += \
    source/ranchwindow.cpp \
    source/basewindow.cpp \
    source/createwindow.cpp \
    source/hallwindow.cpp \
    source/main.cpp \
    source/pigsbox.cpp \
    source/pigsboxinfodialog.cpp \
    source/pigshall.cpp \
    source/ranch.cpp
