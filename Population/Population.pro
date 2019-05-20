TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    personne.cpp \
    manipulation.cpp \
    colorrgb.cpp

HEADERS += \
    personne.h \
    manipulation.h \
    colorrgb.h

DISTFILES += \
    Names.txt
