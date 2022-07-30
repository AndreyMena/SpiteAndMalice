QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    carta.cpp \
    eleccionjugador.cpp \
    ganador1.cpp \
    ganador2.cpp \
    guardarpartida.cpp \
    jugador.cpp \
    main.cpp \
    mainviewcardgames.cpp \
    mazo.cpp \
    menujuego.cpp \
    pantallaempate.cpp \
    pantallajuego.cpp \
    pilaabstracta.cpp \
    pilacentral.cpp \
    piladescarte.cpp \
    reglas.cpp \
    tablero.cpp

HEADERS += \
    carta.h \
    eleccionjugador.h \
    ganador1.h \
    ganador2.h \
    guardarpartida.h \
    jugador.h \
    mainviewcardgames.h \
    mazo.h \
    menujuego.h \
    pantallaempate.h \
    pantallajuego.h \
    pilaabstracta.h \
    pilacentral.h \
    piladescarte.h \
    reglas.h \
    tablero.h

FORMS += \
    eleccionjugador.ui \
    ganador1.ui \
    ganador2.ui \
    guardarpartida.ui \
    mainviewcardgames.ui \
    menujuego.ui \
    pantallaempate.ui \
    pantallajuego.ui \
    reglas.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
