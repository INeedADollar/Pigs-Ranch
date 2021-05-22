QT += gui core

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

RC_ICONS = assets/pig.ico

RESOURCES += \
    resources.qrc

FORMS += \
    ui/pigshallinfodialog.ui \
    ui/questiondialog.ui \
    ui/createhallwindow.ui \
    ui/infodialog.ui \
    ui/hallswindow.ui \
    ui/hallwindow.ui \
    ui/pigsboxinfodialog.ui

HEADERS += \
    headers/pigshallinfodialog.h \
    headers/questiondialog.h \
    headers/createhallwindow.h \
    headers/infodialog.h \
    headers/hallswindow.h \
    headers/hallwindow.h \
    headers/pigsbox.h \
    headers/pigsboxinfodialog.h \
    headers/pigshall.h \
    headers/ranch.h

SOURCES += \
    source/pigshallinfodialog.cpp \
    source/questiondialog.cpp \
    source/createhallwindow.cpp \
    source/infodialog.cpp \
    source/hallswindow.cpp \
    source/hallwindow.cpp \
    source/main.cpp \
    source/pigsbox.cpp \
    source/pigsboxinfodialog.cpp \
    source/pigshall.cpp \
    source/ranch.cpp
