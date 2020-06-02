TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x


SOURCES += main.cpp \
    krolowa.cpp \
    krol.cpp \
    kon.cpp \
    gracz.cpp \
    goniec.cpp \
    plansza.cpp \
    pionki.cpp \
    pion.cpp \
    wieza.cpp

HEADERS += \
    krolowa.h \
    krol.h \
    kon.h \
    gracz.h \
    goniec.h \
    plansza.h \
    pionki.h \
    pion.h \
    wieza.h

