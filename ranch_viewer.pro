QT += gui core

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

RC_ICONS = assets/pig.ico

RESOURCES += \
    resources.qrc

FORMS += \
    ui/hallswindow.ui \
    ui/basewindow.ui \
    ui/createwindow.ui \
    ui/hallwindow.ui \
    ui/pigsboxinfodialog.ui

HEADERS += \
    headers/hallswindow.h \
    headers/basewindow.h \
    headers/createwindow.h \
    headers/hallwindow.h \
    headers/pigsbox.h \
    headers/pigsboxinfodialog.h \
    headers/pigshall.h \
    headers/ranch.h

SOURCES += \
    source/hallswindow.cpp \
    source/basewindow.cpp \
    source/createwindow.cpp \
    source/hallwindow.cpp \
    source/main.cpp \
    source/pigsbox.cpp \
    source/pigsboxinfodialog.cpp \
    source/pigshall.cpp \
    source/ranch.cpp
