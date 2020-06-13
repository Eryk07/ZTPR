QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cinema.cpp \
    factors/airconditioning.cpp \
    factors/factor.cpp \
    factors/fan.cpp \
    factors/people.cpp \
    factors/person.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    screeningroom.cpp \
    settings.cpp \
    simulation.cpp

HEADERS += \
    cinema.h \
    factors/airconditioning.h \
    factors/conditions.h \
    factors/factor.h \
    factors/fan.h \
    factors/people.h \
    factors/person.h \
    mainwindow.h \
    qcustomplot.h \
    screeningroom.h \
    settings.h \
    simulation.h

FORMS += \
    mainwindow.ui \
    settings.ui

win32 {
    INCLUDEPATH += C:/boost/boost_1_73_0
    LIBS += -LC:/boost/boost_1_73_0/stage/lib
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
