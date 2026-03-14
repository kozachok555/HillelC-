QT += widgets

CONFIG += c++17


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    math/math.cpp

HEADERS += \
    mainwindow.h \
    math/math.hpp

FORMS += \
    mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
