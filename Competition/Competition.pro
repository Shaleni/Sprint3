TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../dsstring.cpp \
    ../main.cpp \
    ../quicksorter.cpp

SUBDIRS += \
    ../Sprint3.pro

DISTFILES += \
    ../Sprint3.pro.user \
    ../Bible.txt \
    ../ShakespeareHolmes.txt \
    ../small \
    ../small.txt

HEADERS += \
    ../dsstring.h \
    ../quicksorter.h \
    ../vector.h

