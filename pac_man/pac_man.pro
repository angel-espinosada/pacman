QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bloque.cpp \
    comida.cpp \
    elementos.cpp \
    enemigo.cpp \
    juego.cpp \
    laberinto.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    bloque.h \
    comida.h \
    elementos.h \
    enemigo.h \
    juego.h \
    laberinto.h \
    widget.h

FORMS += \
    juego.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc

    imagenes.qrc \



